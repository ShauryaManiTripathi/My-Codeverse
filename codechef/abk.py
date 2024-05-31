import heapq

def dijkstra(graph, start, end):
    n = len(graph)
    dist = [float('inf')] * n
    dist[start] = 0
    pq = [(0, start)]

    while pq:
        current_dist, u = heapq.heappop(pq)
        if current_dist > dist[u]:
            continue

        if u == end:
            return dist[u]

        for v, weight in graph[u]:
            new_dist = dist[u] + weight
            if new_dist < dist[v]:
                dist[v] = new_dist
                heapq.heappush(pq, (new_dist, v))

    return -1

def solve():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))

        graph = [[] for _ in range(N)]
        for i in range(N):
            for j in range(N):
                if i != j:
                    weight = abs(j - i) * max(A[i], A[j])
                    graph[i].append((j, weight))

        distance = dijkstra(graph, 0, N - 1)
        print(distance)

solve()