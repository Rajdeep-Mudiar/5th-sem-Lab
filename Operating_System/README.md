# Operating Systems Lab Practical Record (LaTeX)

This directory contains the LaTeX source for the Operating Systems laboratory
manual / practical journal. The compiled record covers every program currently
kept in [`Programs/`](Programs), including the four required shell scripts for
even/odd, leap year, factorial, and swapping two integers.

## Directory structure

```text
Operating_System/
├── main.tex                 # Master document: cover page, styling, includes
├── index.tex                # Laboratory record index page
├── appendix.tex             # Viva-voce questions and execution quick reference
├── Makefile                 # Build helpers
├── .gitignore               # LaTeX build artefacts
├── images/
│   └── gu-logo-black.png    # Gauhati University emblem
├── screenshots/             # Optional terminal screenshots (currently empty)
├── practicals/
│   ├── practical_01.tex     # Experiment 1: Introduction to UNIX/Linux
│   ├── practical_02.tex     # Experiment 2: UNIX system calls
│   ├── practical_03.tex     # Experiment 3: Simulating ls and grep
│   ├── practical_04.tex     # Experiment 4: Shell programming
│   ├── practical_05.tex     # Experiment 5: CPU scheduling algorithms
│   ├── practical_06.tex     # Experiment 6: Producer-consumer problem
│   └── practical_07.tex     # Experiment 8: Banker's algorithm
└── Programs/                # C and shell programs included in the manual
```

## Experiments covered

The index page preserves the experiment numbers of the departmental OS lab
manual. Experiment 7 and Experiments 9--15 are listed as pending; their sections
can be added later without renumbering the completed experiments.

| Record Exp. | Official Exp. | Topic | Source |
|---|---|---|---|
| 1 | 1 | Introduction to UNIX/Linux and basic commands | `practicals/practical_01.tex` |
| 2 | 2 | UNIX system calls (`opendir`, `readdir`, `fork`, ...) | `practicals/practical_02.tex` |
| 3 | 3 | Simulation of `ls` and `grep` | `practicals/practical_03.tex` |
| 4 | 4 | Shell programming (11 scripts) | `practicals/practical_04.tex` |
| 5 | 5 | Priority, Round Robin, FCFS and SJF scheduling | `practicals/practical_05.tex` |
| 6 | 6 | Producer-consumer using semaphores | `practicals/practical_06.tex` |
| -- | 7 | IPC using shared memory (pending) | -- |
| 8 | 8 | Banker's algorithm for deadlock avoidance | `practicals/practical_07.tex` |
| -- | 9--15 | Deadlock detection, threads, memory, paging, files (pending) | -- |

## Programs covered

### Shell scripts (Experiment 4)

| Program | File |
|---|---|
| Even or odd | `Programs/08_even_or_odd.sh` |
| Leap year | `Programs/09_leap_year.sh` |
| Factorial | `Programs/10_factorial.sh` |
| Swap two integers | `Programs/11_swap_two_integers.sh` |
| Fibonacci series | `Programs/01_fibonacci.sh` |
| Palindrome | `Programs/02_palindrome.sh` |
| Power of a number | `Programs/03_power.sh` |
| Second-largest element | `Programs/04_second_largest.sh` |
| Prime check | `Programs/05_prime.sh` |
| Sum of digits | `Programs/06_sum_of_digits.sh` |
| Multiplication table | `Programs/07_multiplication_table.sh` |

### C programs

| Experiment | Program | File |
|---|---|---|
| 2 | Directory listing | `Programs/expt_2_1.c` |
| 2 | Process creation with `fork` / `getpid` | `Programs/expt_2_2.c` |
| 3 | `ls` simulation | `Programs/expt_3_1.c` |
| 3 | `grep` simulation | `Programs/expt_3_2.c` |
| 3 | `grep` with occurrence count | `Programs/expt_3_3.c` |
| 5 | Priority scheduling | `Programs/expt_5_a.c` |
| 5 | Round Robin scheduling | `Programs/expt_5_b.c` |
| 5 | FCFS scheduling | `Programs/expt_5_c.c` |
| 5 | SJF scheduling | `Programs/expt_5_d.c` |
| 6 | Bounded-buffer simulation | `Programs/expt_6.c` |
| 8 | Banker's safety algorithm | `Programs/expt_8.c` |

## Building the PDF

Using `latexmk` (recommended):

```bash
latexmk -pdf main.tex
```

Using `pdflatex` directly (run twice so that the index page references resolve):

```bash
pdflatex -interaction=nonstopmode main.tex
pdflatex -interaction=nonstopmode main.tex
```

With `make`:

```bash
make          # build main.pdf
make clean    # remove auxiliary files
make cleanall # remove auxiliary files and main.pdf
make watch    # continuous preview
```

The output is `main.pdf`.

## Running the programs

Shell scripts:

```bash
cd Programs
chmod +x 08_even_or_odd.sh
./08_even_or_odd.sh
# or
bash 08_even_or_odd.sh
```

C programs:

```bash
cd Programs
gcc -std=c11 -Wall -Wextra expt_5_c.c -o expt_5_c
./expt_5_c
```

The system-call programs (`expt_2_1.c`, `expt_3_1.c`) and the `fork` path of
`expt_2_2.c` assume a POSIX environment such as Linux, WSL, or a UNIX system.
The palindrome script uses the GNU `rev` utility.

## Notes

- Code is included directly from `Programs/` with `\lstinputlisting`, so the
  listings in the PDF always match the source files.
- The dates, marks, and faculty-signature columns in `index.tex` are left blank
  for handwriting.
- Sample outputs are representative; process IDs, directory contents, and
  timing values naturally vary between runs.
- To add a screenshot, place it in `screenshots/` and use it in a practical:
  ```latex
  \begin{figure}[H]
      \centering
      \includegraphics[width=0.85\textwidth]{your_screenshot.png}
      \caption{Output of the program}
  \end{figure}
  ```
- To add a new experiment, create the next `practicals/practical_XX.tex`, input
  it from `main.tex`, and add a row to `index.tex`.
