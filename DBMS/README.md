# DBMS Practical Laboratory Record (LaTeX Setup)

This repository contains the complete LaTeX setup for generating the Database Management Systems (DBMS) practical laboratory manual / journal PDF.

---

## 📁 Repository Structure

```text
DBMS/
├── main.tex                    # Master LaTeX document (title page, index, styling)
├── Makefile                    # Build scripts for easy compilation
├── .gitignore                  # Ignores LaTeX build artifacts
├── README.md                   # Setup and usage guide
├── screenshots/                # Store terminal screenshots and query outputs here
│   ├── .gitkeep
│   └── sample_output.png       # Sample terminal screenshot
├── images/                     # Store ER diagrams, relational schema diagrams, etc.
│   └── .gitkeep
└── practicals/                 # Individual modular practical files
    ├── practical_01.tex        # Experiment 1: Introduction to MySQL
    ├── practical_02.tex        # Experiment 2: Data Definition Language (DDL) Commands
    └── practical_03.tex        # Experiment 3: Data Manipulation Language (DML) Commands
```

---

## 🛠️ Prerequisites & Available Tools

The following LaTeX tools are installed and verified on your system:
- **`pdflatex`** (TeX Live)
- **`latexmk`** (automated multi-pass build tool)
- **`xelatex`** / **`lualatex`**

---

## 🚀 How to Build the PDF

You can build the PDF using any of the following methods:

### Option 1: Using `make` (Recommended)
```bash
# Build the PDF (automatically runs required passes)
make

# Clean auxiliary files (*.aux, *.log, *.toc, etc.)
make clean

# Clean everything including main.pdf
make cleanall

# Continuous preview mode (auto-recompiles on file save)
make watch
```

### Option 2: Using `latexmk` directly
```bash
latexmk -pdf main.tex
```

### Option 3: Using `pdflatex` directly
```bash
pdflatex -interaction=nonstopmode main.tex
pdflatex -interaction=nonstopmode main.tex
```

The compiled output will be generated as **`main.pdf`**.

---

## 📸 How to Add Screenshots & Logos

### 1. Institutional Logo / Emblem (Cover Page)
- Place your college/university logo in `images/` as **`logo.png`**, **`logo.pdf`**, or **`logo.svg`**.
- If you use a vector **`.svg`** file (e.g., `images/logo.svg`), running `make` will automatically convert it to a crisp vector `logo.pdf` using `rsvg-convert` and embed it on the cover page.
- Until a logo file is added, an elegant visual placeholder box is rendered automatically.

### 2. Screenshots & Experiment Diagrams
1. Save your terminal screenshot or query execution image in the `screenshots/` directory (e.g., `screenshots/exp03_keys.png`) or `images/`.
2. Both `screenshots/` and `images/` are registered in `\graphicspath`, so in your `.tex` files you only need to specify the filename:
   ```latex
   \begin{figure}[h!]
       \centering
       \includegraphics[width=0.85\textwidth]{exp03_keys.png}
       \caption{Output of query execution}
       \label{fig:exp03_keys}
   \end{figure}
   ```

---

## ➕ How to Add a New Practical

1. Create a new file in `practicals/`, e.g., `practicals/practical_03.tex`.
2. Add your content following the boilerplate template:
   ```latex
   \section{Practical 3: Integrity Constraints}
   \label{exp:constraints}

   \subsection*{Aim}
   ...

   \subsection*{Theory}
   ...

   \subsection*{SQL Code \& Execution}
   \begin{lstlisting}[caption={Primary and Foreign Key definition}]
   CREATE TABLE Department (
       dept_id INT PRIMARY KEY,
       dept_name VARCHAR(50) NOT NULL
   );
   \end{lstlisting}

   \subsection*{Output / Screenshots}
   \begin{figure}[h!]
       \centering
       \includegraphics[width=0.85\textwidth]{your_screenshot.png}
       \caption{Console output}
   \end{figure}

   \subsection*{Result \& Conclusion}
   ...
   ```
3. Include it in [main.tex](file:///home/jyoti/Documents/dev/DBMS/main.tex):
   ```latex
   \newpage
   \input{practicals/practical_03.tex}
   ```
4. Update the Index table on page ii in [main.tex](file:///home/jyoti/Documents/dev/DBMS/main.tex).
