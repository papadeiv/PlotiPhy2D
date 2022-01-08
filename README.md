# PlotiPhy2D - Plotter and Intepreter for 2-dimensional Physics

This light and fast C++-based software allows users to plot and interpret physical 2D vector fields in real-time. Vector fields are _vector-valued_ functions that maps any point of a subset of a _d-dimensional_ Euclidean space to a unique _D-dimensional_ vector. In physics, vector fields of interest s.a. the velocity field of a fluid, or the electric field of a certain charge distribution, are defined over the _d=3_ Euclidean space with dimensions (x,y,z). PlotiPhy2D restricts to _d=2_ the plotting of those physical vector fields defined over a discretised grid of a infinite continuous plane of Cartesian coordinates (x,y). Here's an example produced by this library of a 2D electric field E(x,y) generated by a discrete distribution of point-like charges.

![](example.png)

The graphics and rendering has been implemented using [SFML](https://github.com/SFML/SFML) while the rest of the code is original.

## Dependencies
Aside from the aforementioned __SFML__, to use this program without any alteration to its source code the user must download and compile the following third-party software:
- [x]  [GCC - GNU Compiler Collection](https://gcc.gnu.org/) (at least version `9.4`);
- [x]  [GNU Make](https://www.gnu.org/software/make/) (at least version `4.2.*`).
To install the above dependencies in a __Debian__-based Linux distro the user can simply run
```
$ sudo apt update
$ sudo apt install build-essential
```
which automatically installs both dependencies.

## Build and execution
The easiest and most straightforward option for building __PlotiPhy2D__ from source is to use __Make__ with __GCC__. Invoking `make` from the top-level directory of this repository will compile __PlotiPhy2D__ source files and link with __SFML__'s necessary modules. In such rule it is included the automatic execution of the resulting executable file `PlotiPhy` however the user can easily disable that by commenting out line 3 of the `makefile`. Also the rule `make clean` will remove all the `.o` object files generated by the compiler alongside the executable file itself.