
.PHONY : all
all : charamza-1972.pdf

charamza-1972.pdf : charamza-1972.tex *.tex Makefile
	pdflatex $<
	pdflatex $<

clean:
	rm -f charamza-1972.pdf *.aux *.log *.toc *~ *.bcf *blg
