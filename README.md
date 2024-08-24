# PE-Packer

This project is a simple 64-bit Portable Executable (PE) packer that uses AES encryption and ZLIB compression to obfuscate executable files.

## How It Works

The PE-Packer works by creating a packed executable file through the following process:

1. **Packing Process:**
   - The original executable is encrypted and compressed.
   - The encrypted and compressed data is then embedded into a new PE file as a ".unpacked" section.
   - This new PE file contains an unpacking stub that decrypts and decompresses the ".unpacked" section at runtime.
   - After decompression, the unpacked executable is loaded into memory and execution is redirected to its entry point.

2. **Unpacking Process:**
   - The unpacking stub located in the packed executable reads the ".unpacked" section.
   - It decrypts and decompresses the section.
   - The decompressed data is then loaded into memory and the program execution continues from the original entry point of the unpacked executable.

**Disclaimer:** This is a minimal implementation of a PE packer. It may not handle all executable types and edge cases. Ensure to test it thoroughly in your environment.

## Building the Projects

1. **Create a build directory**:

   ```bash
   mkdir build
   cd build
   ```
   
2. **Run CMake to configure the project:**
   ```bash
   cmake ..
3. **Build the projects:**
   ```bash
   cmake --build .
   ```
## Running the Project

1. **Run the Packer**
   ```bash
   ./packer
   ```
This compresses the dummy executable and saves it as compressed.bin in the stub directory. 

2. **Run the Stub**
   ```bash
   ./stub
   ```
This decompresses compressed.bin and simulates loading the executable into memory.


