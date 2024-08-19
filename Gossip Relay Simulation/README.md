# Gossip Relay Simulation

This C++ program simulates the spread of a secret in a social network. Given an initial person who knows a secret and the network of gossip relationships, the program calculates the minimum number of days it takes for the secret to return to the original person.

## Problem Description

In a group of `n` friends, each pair of friends might have a one-way gossip relationship, meaning if person `u` knows a secret, they can tell it to person `v` during a meeting. Given a scenario where person `s` shares a secret with person `t` (who doesn't gossip back to `s`), the program determines the minimum number of days required for the secret to spread through the network and eventually return to person `s`.

### Input

For each test case:

1. **First Line**: Four integers `n`, `m`, `s`, and `t`:
   - `n`: Number of friends.
   - `m`: Number of gossip relationships.
   - `s`: The person who starts with the secret.
   - `t`: The person who receives the secret initially.
  
2. **Next `m` Lines**: Each line contains two integers `u` and `v`, indicating a one-way gossip relationship from `u` to `v`.

### Output

For each test case, output the minimum number of days it takes for the secret to return to person `s`. If it is impossible, output `-1`.

## Example

### Input

```
2
3 3 1 2
1 2
2 3
3 1
4 3 2 3
1 3
3 4
4 1
```

### Output

```
2
-1
```

### Explanation

- **Test Case 1**: The secret takes 2 days to return to person `1`.
- **Test Case 2**: It is impossible for the secret to return to person `2`.

## How It Works

1. **BFS Algorithm**: The program uses Breadth-First Search (BFS) to determine the shortest path from person `t` back to person `s` through the network.
2. **Simulation**: For each test case, it builds the network, runs BFS, and checks if the secret can return to the original person. If not, it outputs `-1`.
