.PHONY: all clean cleanall watch convert-svg

MAIN = main
COMPILER = pdflatex
LATEXMK = latexmk

# Find any SVG files in images/ or screenshots/
SVG_FILES := $(wildcard images/*.svg screenshots/*.svg)
SVG_PDFS  := $(patsubst %.svg,%.pdf,$(SVG_FILES))

# Auto convert SVG to vector PDF if rsvg-convert or inkscape is present
convert-svg: $(SVG_PDFS)

%.pdf: %.svg
	@if command -v rsvg-convert >/dev/null 2>&1; then \
		echo "Converting $< to $@ using rsvg-convert..."; \
		rsvg-convert -f pdf -o "$@" "$<"; \
	elif command -v inkscape >/dev/null 2>&1; then \
		echo "Converting $< to $@ using inkscape..."; \
		inkscape "$<" --export-filename="$@"; \
	fi

# Default target: compile using latexmk if available, fallback to pdflatex
all: convert-svg
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

# Clean everything including PDF
cleanall: clean
	rm -f $(MAIN).pdf

# Continuous preview watch mode (updates PDF automatically when files change)
watch:
	$(LATEXMK) -pdf -pvc -interaction=nonstopmode $(MAIN).tex
