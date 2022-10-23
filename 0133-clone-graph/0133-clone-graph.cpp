/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<int, Node*> graph;
        unordered_map<int, bool> isVisited;
        stack<Node*> toVisit;
        toVisit.push(node);
        while (!toVisit.empty()){
            Node* curNode = toVisit.top();
            toVisit.pop();
            int curInd = curNode->val;
            if (isVisited[curInd]){
                continue;
            }
            if (graph.find(curInd) == graph.end()){
                graph[curInd] = new Node(curInd);
            }
            for (int i = 0; i < curNode->neighbors.size(); i++){
                int nodeInd = curNode->neighbors[i]->val;
                if (graph.find(nodeInd) == graph.end()){
                    graph[nodeInd] = new Node(nodeInd);   
                }
                graph[curInd]->neighbors.push_back(graph[nodeInd]);
                toVisit.push(curNode->neighbors[i]);
            }
            isVisited[curInd] = true;
        }
        return graph[1];
    }
};