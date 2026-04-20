/*
def have to redo this

1. set up adj map
key value
node : list of (neighbor, time)

2. dijkstra's
*/

struct Edge {
    int node, time;
};

struct compareEdges {
    bool operator()(const Edge& a, const Edge& b) {
        return a.time > b.time;
    }
};

class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for(auto& t : times) graph[t[0]].push_back({t[1], t[2]});

        priority_queue<Edge, vector<Edge>, compareEdges> min_pq;
        vector<int> dist(n + 1, INT_MAX);

        min_pq.push({k, 0});
        dist[k] = 0;

        unordered_set<int> visited; // node

        while(!min_pq.empty()) {
            Edge cur = min_pq.top();
            min_pq.pop();

            if(visited.count(cur.node)) continue;
            visited.insert(cur.node);

            for(auto& [neighbor, w] : graph[cur.node]) {
                int newDist = dist[cur.node] + w;
                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    min_pq.push({neighbor, newDist});
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};