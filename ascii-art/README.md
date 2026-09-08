# ASCII Mandelbrot (terminal)

This program renders a Mandelbrot set as ASCII art in the terminal.

Build:
  make -C ..

Or from repo root:
  make

Compile manually:
  g++ -O2 -std=c++17 ascii-art/mandelbrot.cpp -o ascii-art/mandelbrot

Run (defaults: 80x25, 1000 iterations):
  ./ascii-art/mandelbrot

Examples:
  ./ascii-art/mandelbrot --width 120 --height 40 --iter 2000
  ./ascii-art/mandelbrot --nocolor --gradient "@#%*+=-:. "
  ./ascii-art/mandelbrot --xmin -0.75 --xmax -0.6 --ymin 0.0 --ymax 0.15

Notes:
- ANSI 256-color is used by default; use --nocolor to disable.
- You can set width/height/iterations and the rendered complex-plane region via flags.
