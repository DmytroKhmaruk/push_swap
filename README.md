*This project has been created as part of the 42 curriculum by zorwa, dkhmaruk.*

# push_swap

## Description

`push_swap` sorts a list of integers using two stacks and a limited set of
allowed operations.

The program receives stack `a` as arguments. The first argument is the top of
the stack. Stack `b` starts empty.

The goal is to print a valid list of push_swap operations that sorts stack `a`
in ascending order, with the smallest number at the top.

At the end:

```text
stack a -> sorted
stack b -> empty
```

---

## Contributors

| Contributor    | Login      |
|----------------|------------|
| Zain Orwa      | `zorwa`    |
| Dmytro Khmaruk | `dkhmaruk` |

### Contributions

**Zain Orwa (`zorwa`)**

- Input validation
- Parsing
- Operations integration
- Strategy integration
- Testing and debugging
- Sort medium implementation
- Sort complex implementation
- Documentation

**Dmytro Khmaruk (`dkhmaruk`)**

- Stack building
- Small sort implementation
- Simple sort strategy
- Benchmark output
- Sorting logic review
- Project integration
- Testing and debugging
- Peer review

Both contributors worked together on integration, testing, debugging, and
reviewing the final behavior of the project.

Both contributors understand the complete codebase and can explain any part of
the project during defense.

---

## Instructions

Build the project:

```bash
make
```

Clean object files:

```bash
make clean
```

Remove objects and executable:

```bash
make fclean
```

Rebuild:

```bash
make re
```

Run the program:

```bash
./push_swap 3 2 1
```

Run with checker:

```bash
ARG="3 2 1"
./push_swap $ARG | ./checker_linux $ARG
```

Expected checker output:

```text
OK
```

No arguments must print nothing:

```bash
./push_swap
```

---

## Strategy Selectors

The program supports four strategy selectors:

| Selector     | Meaning                                  |
|--------------|------------------------------------------|
| `--simple`   | Forces the O(n²) algorithm               |
| `--medium`   | Forces the O(n√n) algorithm              |
| `--complex`  | Forces the O(n log n) algorithm          |
| `--adaptive` | Chooses a strategy based on disorder     |

If no selector is given, the default behavior is:

```text
--adaptive
```

Examples:

```bash
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

Only one strategy selector is accepted.

---

## Benchmark Mode

Benchmark mode is enabled with:

```text
--bench
```

Example:

```bash
ARG="9 1 8 2 7 3 6 4 5"
./push_swap --bench --adaptive $ARG
```

Example output:

```text
[bench] disorder: 55.55%
[bench] strategy: Adaptive / O(n log n)
[bench] total_ops: 59
[bench] sa: 0 sb: 0 ss: 0 pa: 23 pb: 23
[bench] ra: 13 rb: 0 rr: 0 rra: 0 rrb: 0 rrr: 0
```

When `--bench` is active, normal operations are hidden from stdout. Benchmark
information is printed to stderr.

---

## Input Validation

Invalid input prints:

```text
Error
```

to stderr.

Rejected cases include:

| Case                       | Example                   |
|----------------------------|---------------------------|
| Empty string               | `./push_swap ""`         |
| Only spaces                | `./push_swap "   "`      |
| Non-numeric token          | `./push_swap 12a`         |
| Invalid sign               | `./push_swap ++1`         |
| Duplicate numbers          | `./push_swap 1 2 1`       |
| Integer overflow           | `./push_swap 2147483648`  |
| Integer underflow          | `./push_swap -2147483649` |
| Equivalent duplicates      | `./push_swap 01 1`        |
| Equivalent zero duplicates | `./push_swap 0 -0`        |

---

## Stack Representation

The project uses a doubly linked list.

```c
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;
```

| Field   | Meaning                  |
|---------|--------------------------|
| `value` | Original integer value   |
| `index` | Sorted rank of the value |
| `prev`  | Previous node            |
| `next`  | Next node                |

The sorting algorithms work with indexes instead of raw values.

Example:

```text
Values:  50  -3  100  7
Indexes: 2    0   3   1
```

This makes sorting safe for negative numbers, zero, and large gaps between
values.

---

## Disorder Metric

Disorder measures how far the initial stack is from being sorted.

It is calculated before any move is performed.

The metric counts inverted pairs:

```text
If a bigger value appears before a smaller value,
that pair is counted as a mistake.
```

Formula:

```text
disorder = mistakes / total_pairs
```

| Input Type         | Disorder Value          |
|--------------------|-------------------------|
| Already sorted     | `0.0`                   |
| Fully reversed     | `1.0`                   |
| Partly mixed input | Between `0.0` and `1.0` |

---

## Algorithms and Complexity

The project implements four required strategies.

### Simple Strategy — O(n²)

Function:

```c
insertion_sort()
```
Internal technique:

```text
Find the smallest index.
Move it to the top of stack A.
Push it to stack B.
Repeat until three elements remain.
Sort the last three elements.
Push everything back to stack A.
```

This is a simple baseline strategy. In the push_swap operation model, searching
and moving the next minimum repeatedly gives an O(n²) upper bound.

---

### Medium Strategy — O(n√n)

Function:

```c
medium_sort()
```

Internal technique:

```text
Split indexes into chunks of about √n.
Push chunk ranges from A to B.
Rotate B to keep smaller values deeper.
Move the biggest indexes back from B to A.
```

For 100 numbers, the chunk size is about 10:

```text
0-9
10-19
20-29
...
```

This is a chunk-based strategy. The number of chunks and the movement inside
each chunk give an O(n√n) upper-bound argument in the push_swap operation model.

---

### Complex Strategy — O(n log n)

Function:

```c
radix_sort()
```

Internal technique:

```text
Use binary radix sort on indexes.

For each bit:
  if current bit is 0 -> pb
  if current bit is 1 -> ra

Then push everything from B back to A.
Repeat for all required bits.
```

The algorithm checks all `n` elements for each binary bit. Since the number of
bits needed for indexes `0` to `n - 1` is about `log n`, this gives an
O(n log n) upper bound in the push_swap operation model.

---

### Adaptive Strategy

Function:

```c
run_sort()
```

Adaptive mode chooses the internal strategy based on the measured disorder.

| Disorder Range       | Strategy    | Complexity |
|----------------------|-------------|------------|
| `< 0.2`              | Simple sort | O(n²)      |
| `>= 0.2` and `< 0.5` | Chunk sort  | O(n√n)     |
| `>= 0.5`             | Radix sort  | O(n log n) |

Threshold rationale:

```text
Low disorder:
The list is close to sorted, so the simple strategy is acceptable.

Medium disorder:
The list is mixed but not fully chaotic, so chunk sorting is used.

High disorder:
The list is heavily mixed or reversed, so radix gives predictable performance.
```

---

## Resources

Resources used during the project:

- 42 push_swap subject
- 42 Norm
- Libft
- Peer review and discussion
- `checker_linux`
- Valgrind
- Norminette
- Manual tests with valid and invalid inputs
- Algorithm notes about insertion sort, chunk sort, and radix sort

---

## AI Usage

AI was used as a learning and review assistant for:

- Reviewing the project structure
- Explaining algorithms
- Reviewing edge cases
- Preparing test commands
- Improving README wording

All AI-assisted output was manually reviewed, tested, and discussed.

The project was checked with:

```text
make re
norminette
checker_linux
valgrind
manual edge-case tests
```

The contributors remain responsible for understanding and defending the complete
project.

---

## Testing

### Basic Tests

```bash
make re
norminette *.c *.h
```

```bash
ARG="3 2 1"
./push_swap --adaptive $ARG | ./checker_linux $ARG
```

Expected:

```text
OK
```

### Adaptive Strategy Tests

Low disorder:

```bash
ARG="1 2 3 4 5 6 7 8 10 9"
./push_swap --bench --adaptive $ARG >/dev/null
```

Expected strategy:

```text
Adaptive / O(n^2)
```

Medium disorder:

```bash
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
./push_swap --bench --adaptive $=ARG >/dev/null
```

Expected strategy is usually:

```text
Adaptive / O(n√n)
```

High disorder:

```bash
ARG=$(seq 100 -1 1 | tr '\n' ' ')
./push_swap --bench --adaptive $=ARG >/dev/null
```

Expected strategy:

```text
Adaptive / O(n log n)
```

### Larger Tests

100 random numbers:

```bash
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
./push_swap --adaptive $=ARG | ./checker_linux $=ARG
./push_swap --adaptive $=ARG | wc -l
```

500 mixed numbers:

```bash
ARG=$(seq -250 249 | shuf | tr '\n' ' ')
./push_swap --adaptive $=ARG | ./checker_linux $=ARG
./push_swap --adaptive $=ARG | wc -l
```

Valgrind:

```bash
ARG=$(seq -250 249 | shuf | tr '\n' ' ')
valgrind --leak-check=full ./push_swap --adaptive $=ARG >/dev/null
```

Expected:

```text
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors
```

---

## zsh Testing Note

On zsh, use:

```bash
$=ARG
```

Example:

```bash
ARG=$(seq 100 -1 1 | tr '\n' ' ')
./push_swap --adaptive $=ARG | ./checker_linux $=ARG
```

This forces word splitting so arguments are passed correctly.
