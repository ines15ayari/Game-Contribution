# Build Instructions

Instructions for building this repository on your machines.

## Dependencies

- [Git][]
- C Compiler (gcc, ...)
- [CMake][]
- [SDL2][sdl] library
- [SDL2_image][] library
- [SDL2_gfx][] library

**On Debian/Ubuntu based distributions, use the following command:**

```sh
sudo apt install git build-essential pkg-config cmake cmake-data libsdl2-dev libsdl2-image-dev libsdl2-gfx-dev
```

This project also use this libraries:

- [SDL2_ttf][] library
- [SDL2_net][] library
- [SDL2_mixer][] library

```sh
sudo apt install libsdl2-ttf-dev libsdl2-net-dev libsdl2-mixer-dev
```

## Build instructions

```sh
# Clone this repo
git clone https://gitlab.com/aminosbh/flying-plane-sdl-animation.git
cd flying-plane-sdl-animation

# Create a build folder
mkdir build
cd build

# Build
cmake ..
make

# Run
./flying-plane-sdl-animation
```

**_Note:_** To use SDL2_ttf, SDL2_net or SDL2_mixer, you should uncomment some
instructions in the CMakeLists.txt file and re-execute the `make` command.

### Open the project with an IDE under Linux

See [IDE_USAGE.md](IDE_USAGE.md) for details.
