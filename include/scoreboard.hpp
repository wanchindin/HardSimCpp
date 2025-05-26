#pragma once
#include <vector>
#include <iostream>

template <typename T>
class Scoreboard {
private:
    std::vector<T> expectedValues; // 儲存期望值
    std::vector<T> actualValues;   // 儲存實際值
    bool testPassed;               // 測試是否成功

public:
    Scoreboard(const std::vector<T>& expected) 
        : expectedValues(expected), testPassed(true) {}

    // 記錄實際值
    void record(const T& value) {
        actualValues.push_back(value);
    }

    // 比對實際值與期望值
    void compare() {
        std::cout << "=================== Scoreboard Results ===================" << std::endl;
        for (size_t i = 0; i < expectedValues.size(); ++i) {
            if (i >= actualValues.size()) {
                std::cout << "Error: Missing actual value for cycle " << i << std::endl;
                testPassed = false;
                continue;
            }

            if (actualValues[i] != expectedValues[i]) {
                std::cout << "Mismatch at cycle " << i 
                          << ": Expected " << expectedValues[i] 
                          << ", but got " << actualValues[i] << std::endl;
                testPassed = false;
            } else {
                std::cout << "Cycle " << i << ": Passed (Value = " << actualValues[i] << ")" << std::endl;
            }
        }

        if (testPassed) {
            std::cout << "All tests passed!" << std::endl;
        } else {
            std::cout << "Some tests failed." << std::endl;
        }
    }
};