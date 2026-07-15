# HexView

A clone of hexdump written from scratch in C that displays file contents in hexadecimal and ASCII format. The output is displayed in 16-byte rows using big-endian byte ordering.

## Build

We will be building this project using CMake:

```bash
cmake -S . -B build
cmake --build build
```

> The executable will be generated inside the build directory.

## Usage

Pass the path to a file as a command-line argument:

```bash
build/hexview assets/file.txt # To view the sample txt file
build/hexview assets/file.bin # To view the sample bin file
```

## License

This project is licensed under MIT license. See [LICENSE](./LICENSE) file, for more details.

