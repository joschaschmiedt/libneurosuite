# Building libneurosuite on Ubuntu 24.04

This guide provides step-by-step instructions for building libneurosuite on Ubuntu 24.04 using CMake.

## Prerequisites

### System Requirements

- Ubuntu 24.04 LTS
- CMake 3.16 or higher
- C++17 compatible compiler (GCC 11+ or Clang 14+)
- Qt6 development libraries

### Installing Dependencies

Install all required dependencies using apt:

```bash
sudo apt update
sudo apt install -y \
    build-essential \
    cmake \
    git \
    qt6-base-dev \
    qt6-webengine-dev \
    qt6-webview-dev \
    libxkbcommon-dev \
    libqt6webenginewidgets6 \
```

### Verifying Installation

Verify that CMake and Qt6 are properly installed:

```bash
cmake --version
qmake6 --version
```

CMake should be version 3.16 or higher, and Qt should be version 6.x.

## Building the Library

### 1. Clone the Repository (if not already done)

```bash
git clone https://github.com/joschaschmiedt/libneurosuite.git
cd libneurosuite
```

### 2. Configure the Build

Create a build directory and configure the project with CMake:

```bash
cmake -B build -S .
```

**Optional Build Options:**

- To build the test binary:

    ```bash
    cmake -B build -S . -DWITH_TEST=ON
    ```

- To specify a custom installation prefix:

    ```bash
    cmake -B build -S . -DCMAKE_INSTALL_PREFIX=/usr/local
    ```

- To build in Release mode (optimized):

    ```bash
    cmake -B build -S . -DCMAKE_BUILD_TYPE=Release
    ```

- To build in Debug mode (with debug symbols):
    ```bash
    cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug
    ```

### 3. Build the Library

Build the project using CMake:

```bash
cmake --build build
```

For faster builds on multi-core systems, use parallel compilation:

```bash
cmake --build build -j$(nproc)
```

### 4. Install the Library (Optional)

To install the library system-wide:

```bash
sudo cmake --install build
```

Or install to a custom location:

```bash
cmake --install build --prefix /path/to/install
```

## Build Artifacts

After a successful build, you'll find:

- **Library:** `build/src/libneurosuite.so` (shared library)
- **Headers:** In `src/` subdirectories
- **CMake package files:** In `build/cmake/`

## Troubleshooting

### Qt6 Not Found

If CMake cannot find Qt6, you may need to set the Qt6 path explicitly:

```bash
cmake -B build -S . -DCMAKE_PREFIX_PATH=/usr/lib/x86_64-linux-gnu/cmake/Qt6
```

### WebEngine Dependencies Missing

If you encounter errors related to Qt6WebEngine, ensure all WebEngine packages are installed:

```bash
sudo apt install -y qt6-webengine-dev qt6-webengine-dev-tools
```

### Permission Denied During Installation

If installation fails due to permissions, use `sudo`:

```bash
sudo cmake --install build
```

## Using libneurosuite in Your Project

After installation, you can use libneurosuite in your CMake projects:

```cmake
find_package(neurosuite REQUIRED)
target_link_libraries(your_target PRIVATE neurosuite)
```

## Additional Information

- **Project Version:** 3.0.0
- **Qt Version:** Qt6 (Qt5 is no longer supported)
- **C++ Standard:** C++17
- **License:** GNU Public License v2

For more information, see the [README.md](README.md) file.
