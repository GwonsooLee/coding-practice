n = int(input())
values = list(map(int, input().split()))
edges = [tuple(map(int, input().split())) for _ in range(n - 1)]

# Please write your code here.
graph = dict()
for (u, v) in edges:
    if u not in graph:
        graph[u] = []
    graph[u].append(v)
    if v not in graph:
        graph[v] = []
    graph[v].append(u)

def dfs(node, parent):

    best_selected_value, best_selected_nodes = 0, []
    all_not_selected, all_not_selected_nodes = 0, []

    for child in graph[node]:
        if child == parent:
            continue

        child_sv, child_sn, child_nsv, child_nsn = dfs(child, node)

        all_not_selected += child_nsv
        all_not_selected_nodes.extend(child_nsn)

        best_selected_value += child_sv if child_sv >= child_nsv else child_nsv
        best_selected_nodes.extend(child_sn if child_sv >= child_nsv else child_nsn)

    all_not_selected += values[node-1]
    all_not_selected_nodes.append(node)
    return all_not_selected, all_not_selected_nodes, best_selected_value, best_selected_nodes

sv, sn, nsv, nsn =dfs(1, 0)

def print_array(arr):
    arr.sort()
    for i in arr:
        print(i, end=" ")

if sv >= nsv:
    print(sv)
    print_array(sn)
else:
    print(nsv)
    print_array(nsn)