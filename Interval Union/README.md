# Interval Union

## Overview

Given `n` intervals on the number line in one of 8 forms, compute their union and output it in a non-overlapping, standard format.

### Interval Types

1. `(a, ∞)` - Numbers greater than `a`
2. `(−∞, a)` - Numbers less than `a`
3. `[a, ∞)` - Numbers ≥ `a`
4. `(−∞, a]` - Numbers ≤ `a`
5. `(a, b)` - Numbers `a < x < b`
6. `(a, b]` - Numbers `a < x ≤ b`
7. `[a, b)` - Numbers `a ≤ x < b`
8. `[a, b]` - Numbers `a ≤ x ≤ b`

### Input

- An integer `n` (1 ≤ `n` ≤ 100000)
- `n` lines, each defining an interval in one of the 8 types.

### Output

- The union of all intervals as a series of non-overlapping intervals separated by `U`.

### Example

**Input:**
```
3
(1, 5)
[3, 7)
[6, inf)
```

**Output:**
```
(1, 7) U [6, inf)
```

### Constraints

- All intervals are valid and non-empty.
- Values range from [−10^9, 10^9].
