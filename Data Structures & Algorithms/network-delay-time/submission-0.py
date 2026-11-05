"""
Input: int n: # of nodes in network, int k: starting node, times: list of lists where every list contains: start node, target node, time it takes to get from start to target
Output: int: minimum time it takes k to reach every node
Method: bfs, from start until we reach the end
Plan:
-map to hold all visited nodes and minimum time it takes to get there
-initalize queue with starting node, value of 0
-while queue
    -popleft, take node and current value (time)
    -check if nodes pointed at is in visited and compare time, take path with less time
    -append every node + updated time (how long it takes to get there)
-if size(map) != n: forest => return -1
-return highest value in map
"""

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        edges = defaultdict(list)
        for u, v, w in times:
            edges[u].append((v, w))

        minHeap = [(0, k)]
        visited = set()
        time = 0
        while minHeap:
            weight, node = heapq.heappop(minHeap)
            if node in visited:
                continue
            visited.add(node)
            time = max(time, weight)

            for neighborn, neighborw in edges[node]:
                if neighborn not in visited:
                    heapq.heappush(minHeap, (weight + neighborw, neighborn))

        if len(visited) == n:
            return time
        return -1

        