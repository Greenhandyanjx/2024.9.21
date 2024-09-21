#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
};
class Solution {
public:
    vector<vector<int>>res;
    vector<int>path;
    vector<vector<int>> dfs(vector<vector<int>>& graph, int x) {
        if (x == graph.size() - 1)
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < graph[x].size(); i++) {
            path.push_back(graph[x][i]);
            dfs(graph, x + 1);
            path.pop_back();
        }
        return res;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph, 0);
        return res;
    }
};
void RemoveDuplicates(ListNode* head) {
    if (!head) return;
    ListNode* current = head;
    unordered_map<int, int>mp{ 0,0 };
    while (current != nullptr) {
        ListNode* runner = current;
        if(mp.find(current->val)==mp.end())
        mp[current->val]++;
        if (!current->next&&mp[current->next->val] == 1)
        {
            if (!current->next) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
        }
        current = current->next;
    }
}