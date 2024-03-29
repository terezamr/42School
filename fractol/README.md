
# Fractol
Generation of fractals from the complex numbers of an iterative mathematical construct. A fractal is a fragmented geometrical figure that infinitely repeats itself at smaller scales. Introduciont to graphical projects, using uses the school's graphical library, MiniLibX.

## Usage
- Execution: The type of the fractal has to be specified (whereas _options_ don't).

```shell
./fractol <type> <options>
```

Types: ``mandesbrot`` or ``1``   |   ``julia`` or ``2``

If the Julia set is chosen, you can specify two other parameters (complex numbers that will change the generation of the julia fractal). If no parameters are specified, the program assumes the set [0.6, 0.015].

For the Julia set, the mouse left click action results in the re-generation of the fractal, according to the position of the mouse.

- Events
  
 KEY           | Action        |
| :-------------:        |:-------------:|
| `↑`                  | move up  |
| `↓`                  | move down |
| `→`                  |move right  |
| `←`                  | move left |
| `MOUSE RIGHT CLICK`  | Color Palette change    |
| `MOUSE SCROLL`       |  Zoom in / out |
| `MOUSE LEFT CLICK`[^1]  | Julia Fractal re-generation |

Notes: Tested on Linux. Zoom movement according to the mouse position was not implemented.
[^1]: Mouse left click action available for Julia set only.

Bonus: included (color change and arrow movement).

## Screenshots
#### Mandelbrot Set
```shell
./fractol Mandelbrot
```

<img src="https://github.com/terezamr/42School/assets/80223858/46c4b84c-991b-4b65-9edd-6f7d3a516ff8" width=400>
<img src="https://github.com/terezamr/42School/assets/80223858/87e92122-026a-4f58-af8c-7d1aa2623a18" width=400>


#### Julia Set
```shell
./fractol 2
```

<img src="https://github.com/terezamr/42School/assets/80223858/25a2996d-12c8-4334-b48d-16476d0642aa" width=400>

```shell
./fractol Julia -0.79 0.15
```

<img src="https://github.com/terezamr/42School/assets/80223858/862430c1-8a46-41fa-afc1-e59d277ac6fd" width=400>
<img src="https://github.com/terezamr/42School/assets/80223858/eeb17b14-69a5-4fcc-be35-e69f960b60a6" width=400>
