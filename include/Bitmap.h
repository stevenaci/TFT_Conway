#pragma once
#include <vector>
#include <cstdint>

class Bitmap{
    public:
    /* Update the bitmap from 2d array pixels, applying scaling; */
    void updateBitmap(const std::vector<std::vector<uint8_t>>& pixels) {
            for (int cellX = 0; cellX < width/scale; cellX++) {
                for (int cellY = 0; cellY < height/scale; cellY++) {
                    // Determine the block of pixels for this cell
                    for (int dx = 0; dx < scale; dx++) {
                        for (int dy = 0; dy < scale; dy++) {
                            int x = cellX * scale + dx;
                            int y = cellY * scale + dy;
                            // Calculate the byte index and bit index
                            int pixelIndex = y * width + x  ;
                            int byteIndex = pixelIndex / 8;    // Which byte in the array
                            int bitIndex = pixelIndex % 8;     // Which bit in the byte
                            if (pixels[cellX][cellY] == 1) {
                                bitmap[byteIndex] |= (1 << (7 - bitIndex)); // Set bit to 1 (white)
                            } else {
                                bitmap[byteIndex] &= ~(1 << (7 - bitIndex)); // Set bit to 0 (black)
                            }
                        }
                    }
                }
            }
        }
        int width, height, scale;
        std::vector<uint8_t> bitmap;
        Bitmap(int w, int h, int s): width(w), height(h), scale(s) {
            bitmap.reserve(width * height / 8  );
        }
};