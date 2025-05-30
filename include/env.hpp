#pragma once
#include "driver.hpp"
#include "monitor.hpp"
#include "scoreboard.hpp"
#include "alu.hpp"
#include "transaction.hpp"
#include <memory>
#include <vector>
#include <iostream>

/*
 * Env 負責初始化並連接：
 *  - DUT（此處為 ALU）
 *  - Driver（輸入驅動）
 *  - Monitor（輸出監控）
 * 
 * Env 控制模擬流程(run)，在每個模擬週期推動 Driver 輸入資料，
 * 觸發 DUT 模擬，並由 Monitor 監察輸出，方便驗證 DUT 功能正確性。
 *
 * 此設計模仿 UVM 驗證環境架構，將模組化驗證元件整合，方便擴充與重複使用。
 */

class Env {
    private:
        std::unique_ptr<Driver<int>> lhsDriver;       // 驅動 ALU 左操作數
        std::unique_ptr<Driver<int>> rhsDriver;       // 驅動 ALU 右操作數
        std::unique_ptr<Monitor<int>> aluMonitor;     // 監視 ALU 輸出
        std::unique_ptr<Scoreboard<int>> aluScoreboard; // 驗證 ALU 輸出
        std::shared_ptr<Wire<int>> lhsWire;           // ALU 左操作數 Wire
        std::shared_ptr<Wire<int>> rhsWire;           // ALU 右操作數 Wire
        std::shared_ptr<Wire<int>> outputWire;        // ALU 輸出 Wire
        std::unique_ptr<Alu<int>> alu;                // ALU 元件
        std::vector<ALUTransaction> transactions;     // 測試資料
    public:
        Env(const std::vector<ALUTransaction>& transactions) : transactions(transactions){

            // Initial wire
            lhsWire = std::make_shared<Wire<int>>();
            rhsWire = std::make_shared<Wire<int>>();
            outputWire = std::make_shared<Wire<int>>();
            
            // ALU , 初始op可以是任意值
            alu = std::make_unique<Alu<int>>(lhsWire, rhsWire, outputWire, ALUOp::ADD);
            
            // Driver
            std::vector<int> lhsInputs, rhsInputs, expectedOutputs; 
            for(const auto transaction : transactions){
                lhsInputs.push_back(transaction.operand1);
                rhsInputs.push_back(transaction.operand2);
                expectedOutputs.push_back(transaction.expected);
            }
            lhsDriver = std::make_unique<Driver<int>>(lhsWire, lhsInputs);
            rhsDriver = std::make_unique<Driver<int>>(rhsWire, rhsInputs);

            // monitor
            aluMonitor = std::make_unique<Monitor<int>>(outputWire);

            // scoreboard
            aluScoreboard = std::make_unique<Scoreboard<int>>(expectedOutputs);
            
        }
        void run(int cycles){
            for(int time = 0; time < cycles; time++){
                std::cout << "=================== Time: " << time << " ===================" << std::endl;
                
                // Driver
                lhsDriver->drive();
                rhsDriver->drive();

                // ALU
                alu->setOp(transactions[time].op);
                alu->simulate();

                // 紀錄 觀察輸出
                aluMonitor->observe();
                aluScoreboard->record(outputWire->get());
            }

            // Scoreboard比對結果
            aluScoreboard->compare();
        }
    };