# Algebraic Expression Solver

A C++ program to evaluate algebraic expressions with `+`, `-`, `*`, and parentheses, returning the result modulo `10^9 + 7`.

## Problem Statement

Given an input string `s` representing a valid algebraic expression, evaluate the expression and print the result modulo `10^9 + 7`. The string contains digits (`0-9`), operators (`+`, `-`, `*`), and parentheses (`(`, `)`).

### Constraints:
- \(1 \leq |s| \leq 2,000,000\)
- Each number in the expression is a positive integer less than \(10^9\) without leading zeros.

## Usage

- Compile: `g++ -o evaluator main.cpp`
- Run: `./evaluator`
- Input: Algebraic expression (e.g., `(2+3*4-5)`)

## Output

The result of the expression modulo `10^9 + 7`.

## Example

- Input: `(2+3*4-5)`
- Output: `9`

