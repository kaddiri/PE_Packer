#include <iostream>
#include <fstream>
#include <vector>
#include <zlib.h>

void decompressFile(const std::string& inputPath) {
    std::ifstream inputFile(inputPath, std::ios::binary | std::ios::ate);
    if (!inputFile) {
        std::cerr << "Error opening input file." << std::endl;
        return;
    }

    std::streamsize compressedSize = inputFile.tellg();
    inputFile.seekg(0, std::ios::beg);

    std::vector<Bytef> compressedData(compressedSize);
    inputFile.read(reinterpret_cast<char*>(compressedData.data()), compressedSize);

    uLongf decompressedSize = 10 * compressedSize; // Estimate decompressed size
    std::vector<Bytef> decompressedData(decompressedSize);

    if (uncompress(decompressedData.data(), &decompressedSize, compressedData.data(), compressedSize) != Z_OK) {
        std::cerr << "Decompression failed." << std::endl;
        return;
    }

    // Assuming the decompressed data is the executable in memory, simulate its execution
    std::cout << "Decompressed and loaded executable in memory!" << std::endl;
    // Here you would execute the decompressed code, but this is just a simple example.
}

int main() {
    std::string inputPath = "compressed.bin";  // Path to the compressed file

    decompressFile(inputPath);
    return 0;
}
