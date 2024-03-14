
# Fractol
Generation of fractals from the complex numbers of an iterative mathematical construct. A fractal is a fragmented geometrical figure that infinitely repeats itself at smaller scales. Introduciont to graphical projects, using uses the school's graphical library, MiniLibX.

## Usage
- Execution: The type of the fractal has to be specified (whereas _options_ don't).

```shell
./fractol <type> <options>
```

Types: ``mandesbrot`` or ``1``   |   ``julia`` or ``2``

If the Julia set is chosen, you can specify two other parameters (complex numbers that will change the generation of the julia fractal).

- Events
  
 KEY           | Action        |
| -------------        |:-------------:|
| `A`                   | move left     |
| `D`                  | move right    |
| `W`                  | move forward  |
| `S`                  | move backward |
| `→`                  |        |
| `←`                  |        |
| `MOUSE RIGHT CLICK`  | Color Palette change    |
| `MOUSE LEFT CLICK` *  | Julia Fractal re-generation |
| `MOUSE SCROLL`       |  Zoom In |

Notes: Tested on Linux. Mouse left click action available for Julia set only.

Bonus: included (color change and arrow movement).

## Screenshots
Mandelbrot Set
```shell
./fractol Mandelbrot
```
Julia Set
```shell
./fractol Julia 1 1
```
