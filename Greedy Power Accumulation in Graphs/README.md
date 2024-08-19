# Secret Hitler Conquest Simulation

This C++ program evaluates the minimum additional power required for each country in a network to conquer all others, assuming that country starts as Nazi Germany.

## Problem Overview

Given a set of `n` countries connected by `m` bidirectional relationships (neighbors), each country has an initial power level. Starting from any country as Nazi Germany, the goal is to determine if it can conquer all other countries by sequentially conquering its neighbors. To conquer a neighbor, Nazi Germany's power must strictly exceed the neighbor's power. The program calculates the minimum power boost needed for each country to ensure it can conquer all others.

### Input

1. **First Line**: Two integers, `n` and `m`, representing the number of countries and the number of connections (neighbor relationships).
2. **Second Line**: A list of `n` integers where each integer represents the power of a country.
3. **Next `m` Lines**: Each line contains two integers `u` and `v`, indicating a connection (neighbor relationship) between country `u` and country `v`.

### Output

The program outputs `n` integers, where the `i-th` integer represents the minimum power that must be added to the `i-th` country to allow it to conquer all other countries if it starts as Nazi Germany. The output may be `0` if the country can already conquer all others without additional power.

## Example

### Input

```
3 2
1 2 3
1 2
2 3
```

### Output

```
2 1 0
```

### Explanation

- **Country 1**: Needs an additional power of 2 to start conquering all countries.
- **Country 2**: Needs an additional power of 1.
- **Country 3**: Needs no additional power (0).

## How It Works

1. **Initialization**: The program reads the number of countries and connections, then initializes power values and neighbor relationships.
2. **Simulation**: For each country:
   - It simulates starting from that country as Nazi Germany.
   - It checks each neighbor to determine if the country can conquer it, updating the total power and required power boost as needed.
3. **Result**: The program outputs the minimum power boost required for each country.
