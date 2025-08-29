# fract-ol

Fractol is a graphical fractal renderer written in C using the MinilibX graphics library.  
This project is part of the 42/1337 curriculum and demonstrates mathematical visualization, graphics programming, and user interaction.

## Features

- **Mandelbrot Set Rendering:** Visualize the classic Mandelbrot fractal.
- **Julia Set Rendering:** Explore Julia sets with customizable parameters.
- **Interactive Zoom:** Use your mouse wheel to zoom in and out of fractals.
- **Parameter Adjustment:** Pass custom parameters for Julia sets via command line.
- **Clean Exit:** Close the window or press Escape to exit the program.

## Requirements

- Linux (Debian/Ubuntu recommended)
- gcc, make
- X11 development libraries: `xorg`, `libxext-dev`
- BSD utility functions: `libbsd-dev`
- MinilibX (included in `minilibx-linux` folder)

## Installation

1. **Install dependencies:**
   ```sh
   sudo apt-get install gcc make xorg libxext-dev libbsd-dev
   ```
2. **Clone the repository:**
   ```sh
   git clone https://github.com/yourusername/fract-ol.git
   cd fract-ol
   ```
3. **Build MinilibX:**
   ```sh
   cd minilibx-linux
   ./configure
   cd ..
   ```
4. **Build fractol:**
   ```sh
   make
   ```

## Usage

Run the program with one of the following commands:

```sh
./fractol Mandelbrot
./fractol Julia <x> <y>
```

- `Mandelbrot`: Renders the Mandelbrot set.
- `Julia <x> <y>`: Renders a Julia set with parameters `<x>` and `<y>` (both between -2 and 2).

## Controls

- **Zoom:** Mouse wheel up/down
- **Exit:** Escape key or close window

## File Structure

- `SRC/` — Source code for fractol
- `minilibx-linux/` — MinilibX graphics library
- `Makefile` — Build instructions

## Example

```sh
./fractol Mandelbrot
./fractol Julia 0.355 0.355
```

## License

MinilibX is BSD 2-Clause licensed (see `minilibx-linux/LICENSE`).

---

Feel free to open issues
