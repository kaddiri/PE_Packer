#include <iostream>
#include <fstream>
#include <vector>
#include <zlib.h>

void compressFile(const std::string& inputPath, const std::string& outputPath) {
    std::ifstream inputFile(inputPath, std::ios::binary | std::ios::ate);
    std::ofstream outputFile(outputPath, std::ios::binary);

    if (!inputFile || !outputFile) {
        std::cerr << "Error opening files." << std::endl;
        return;
    }

    std::streamsize inputSize = inputFile.tellg();
    inputFile.seekg(0, std::ios::beg);

    std::vector<char> buffer(inputSize);
    inputFile.read(buffer.data(), inputSize);

    uLongf compressedSize = compressBound(inputSize);
    std::vector<Bytef> compressedData(compressedSize);

    if (compress(compressedData.data(), &compressedSize, reinterpret_cast<Bytef*>(buffer.data()), inputSize) != Z_OK) {
        std::cerr << "Compression failed." << std::endl;
        return;
    }

    outputFile.write(reinterpret_cast<char*>(compressedData.data()), compressedSize);
    std::cout << "File compressed successfully!" << std::endl;
}

int main() {
    std::string inputPath = "dummy/dummy.exe";  // Dummy executable path
    std::string outputPath = "stub/compressed.bin";  // Output path for compressed file

    compressFile(inputPath, outputPath);
    return 0;
}
