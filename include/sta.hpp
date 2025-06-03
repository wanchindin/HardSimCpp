#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
#include <fstream>

/*
Arrival Time：信號到達節點的最早時間。
Slack Time：節點的時間裕度，表示容許延遲的空間。
Critical Path：延遲最大的路徑，決定電路的最大延遲。
*/

class STA {
    private:
        std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> adjList; // 鄰接表
        std::unordered_map<std::string, int> arrivalTime;   // 最早到達時間
        std::unordered_map<std::string, int> requiredTime;  // 最晚可接受時間
        std::unordered_map<std::string, int> inDegree;      // 入度
        std::unordered_map<std::string, int> slackTime;     // 節點 slack
        std::vector<std::tuple<std::string, std::string, int>> criticalEdges; // slack 為 0 的邊
        std::vector<std::string> topoOrder;


    public:
        // 讀取表並建立圖
        void loadNetlist(const std::string& filename){
            std::ifstream file(filename);
            if(!file.is_open()){
                throw std::runtime_error("Failed to open file: " + filename);
            }
            std::string gate, input1, input2, output;
            int delay;
            while (file >> gate >> input1 >> input2 >> output >> delay) {
                adjList[input1].emplace_back(output, delay);
                adjList[input2].emplace_back(output, delay);
                adjList[output]; // 確保輸出節點也在圖中
            }
        }

        void topologicalSort(){
            // 計算每一個node的indegree
            for(const auto& [node, edges] : adjList){
                // 確保每個節點都在 包含沒被指向的節點(indegree = 0)
                if(!inDegree.count(node)) inDegree[node] = 0;
                for(const auto& [dst, _] : edges){
                    ++inDegree[dst];
                }
            }

            std::queue<std::string> q;
            for(const auto& [node, degree] : inDegree){
                if(degree == 0) q.push(node);
            }
            
            while(!q.empty()){
                std::string node = q.front();
                q.pop();
                //加入結果序列
                topoOrder.push_back(node);

                for(const auto& [dst, _] : adjList[node]){
                    --inDegree[dst];
                    if(inDegree[dst] == 0) q.push(dst);
                }
            }
            if(topoOrder.size() < inDegree.size()){
                throw std::runtime_error("Cycle detected in the graph!");
            }
        }

        void calculateArrivalTime(){
            for(const auto& [node, degree] : inDegree){
                if(degree == 0) arrivalTime[node] = 0;
            }
            for(std::string node : topoOrder){
                for(const auto& [dst, delay] : adjList[node]){
                    arrivalTime[dst] = std::max(arrivalTime[dst], arrivalTime[node]+delay);
                }
            }
        }

        void calculateSlackTime(){
            
        }

        void findCriticalPath(){

        }

        void printResults(){

        }
};