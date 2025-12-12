# Push_Swap

Sorting algorithm that sorts a list of integers using two stacks and a limited set of operations.

## Description

The goal is to sort a stack of random numbers (Stack A) in ascending order using a second auxiliary stack (Stack B) and a specific set of allowed operations. The program seeks to use the minimum number of moves possible.

## Available Operations

### Basic Operations

| Operation | Description |
|---|---|
| `sa` | Swap the first two elements of A |
| `sb` | Swap the first two elements of B |
| `ss` | Swap the first two elements of A and B simultaneously |

### Transfer Operations

| Operation | Description |
|---|---|
| `pa` | Move the first element from B to A |
| `pb` | Move the first element from A to B |

### Upward Rotation Operations

| Operation | Description |
|---|---|
| `ra` | Rotate A upward (first goes to end) |
| `rb` | Rotate B upward |
| `rr` | Rotate A and B upward simultaneously |

### Downward Rotation Operations

| Operation | Description |
|---|---|
| `rra` | Rotate A downward (last goes to first) |
| `rrb` | Rotate B downward |
| `rrr` | Rotate A and B downward simultaneously |

## Included Files

- `push_swap.c` - Main program
- `checker.c` - Verification program (bonus)
- Operation and utility files

## Compilation

```bash
make              # Compile push_swap
make bonus        # Compile checker (bonus)
make clean        # Clean object files
make fclean       # Clean everything
```

## Usage

```bash
# Sort a list of numbers
./push_swap 3 2 5 1 6

# Verify a solution
./checker 3 2 5 1 6
```

## Execution Example

```bash
$ ./push_swap 3 2 5 1 6
pb
pb
pb
pa
pa
pa
```

The program prints the operations needed to sort the list.

## Requirements

- C compiler (gcc, clang, etc.)
- Make
- Linux or macOS

## Features

- Argument parsing and validation
- Error detection (duplicate numbers, non-numeric, etc.)
- Optimized algorithm for small lists
- Bonus version with solution verification
- Efficient memory management

## Limitations

- Maximum recommended numbers: 500
- Only accepts integers
- No duplicate values allowed

## Algorithm

The program uses different strategies based on list size:
- Lists of 3 elements: direct algorithm
- Lists of 5 elements: specific algorithm
- Larger lists: LIS method

### Brief explanation of the LIS method

The LIS (Longest Increasing Subsequence) method finds a longest subsequence of numbers that are already in increasing order. The algorithm keeps the elements belonging to that subsequence in `stack A` and pushes the other elements to `stack B`. Then it inserts the elements from `stack B` back into `stack A` in the correct positions using the fewest rotations and pushes possible. This reduces the total number of operations because elements that are already in correct relative order are not moved unnecessarily.

---

Last updated: December 2025
