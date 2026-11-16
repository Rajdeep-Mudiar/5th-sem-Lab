.PHONY: all clean cleanall watch

MAIN = main
COMPILER = pdflatex
LATEXMK = latexmk

# Default target: compile using latexmk if available, otherwise pdflatex twice
all:
	@if command -v $(LATEXMK) >/dev/null 2>&1; then \
		echo "Building with latexmk..."; \
		$(LATEXMK) -pdf -interaction=nonstopmode $(MAIN).tex; \
	else \
		echo "Building with pdflatex..."; \
		$(COMPILER) -interaction=nonstopmode $(MAIN).tex && \
		$(COMPILER) -interaction=nonstopmode $(MAIN).tex; \
	fi

# Clean auxiliary files
clean:
	@if command -v $(LATEXMK) >/dev/null 2>&1; then \
		$(LATEXMK) -c; \
		rm -f *.synctex.gz; \
	else \
		rm -f *.aux *.log *.out *.toc *.synctex.gz *.fls *.fdb_latexmk; \
	fi

# Clean everything including the PDF
cleanall: clean
	rm -f $(MAIN).pdf

# Continuous preview: recompiles whenever a source file changes
watch:
	$(LATEXMK) -pdf -pvc -interaction=nonstopmode $(MAIN).tex
