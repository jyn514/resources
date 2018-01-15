#TEXC=/usr/bin/pdflatex
TEXC=pdflatex
TEXOPTS=--shell-escape
#BIBC=/usr/bin/bibtex
BIBC=bibtex
BIBOPTS=
#MAKEINDEXC=/usr/bin/makeindex
MAKEINDEXC=makeindex
MAKEINDEXOPTS=

# extracted from process_data logs to get around rounding issues
u_trial1=0.0008571428571428572
u_trial2=0.0003184713375796178

clean:
  -rm -rf out
  -rm -rf build

prep: clean 
  -mkdir build
  -mkdir out
  cp -r src/* build
  cp -r etc/data/* build


data: prep
# redirect stdout to out-trial.csv, stderr to out-trial.log
  cd build && ./process_data.py < data-trial1.csv > out-trial1.csv 2>out-trial1.log
  cd build && ./process_data.py < data-trial2.csv > out-trial2.csv 2>out-trial2.log
  -cp etc/*.eps build
  
plots: prep data
  cd build && gnuplot -e "filename='out-trial1.csv'" plot-png.gp 2> trial1-plot_png.log
  cd build && gnuplot -e "filename='out-trial2.csv'" plot-png.gp 2> trial2-plot_png.log
  cd build && gnuplot -e "filename='out-trial1.csv'; u=$(u_trial1)" plot-LaTeX.gp 2> trial1-plot_LaTeX.log
  cd build && gnuplot -e "filename='out-trial2.csv'; u=$(u_trial2)" plot-LaTeX.gp 2> trial2-plot_LaTeX.log

  mv build/out-trial1.csv.tex build/out-trial1-plot.tex
  mv build/out-trial2.csv.tex build/out-trial2-plot.tex



master: clean prep plots data
  cd build && $(TEXC) $(TEXOPTS) master
  cd build && $(BIBC) master

  cd build && $(TEXC) $(TEXOPTS) master
  cd build && $(TEXC) $(TEXOPTS) master

  cp build/*.pdf out/

