
# Fractol

## Usage
Summary: Generation of fractals from the complex numbers of an iterative mathematical construct. A fractal is a fragmented geometrical figure that infinitely repeats itself at smaller scales. Introduciont to graphical projects, using uses the school's graphical library, MiniLibX.

Execution: The type of the fractal has to be specified (whereas _options_ don't).

```shell
./fractol <type> <options>
```

Types: mandesbrot/1 | julia/2.

If the Julia set is chosen, you can specify two other parameters (complex numbers taht will change the generation os the julia fractal).

Notes: Tested on Linux.

## Screenshots
Mandelbrot Set
```shell
./fractol Mandelbrot
```
Julia Set
```shell
./fractol Julia 1 1
```
