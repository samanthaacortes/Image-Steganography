/**
  *@file image_steganography.cpp
  *
  *Prints a decoded message to standard output.
  *
  *The program shall expect one command-line argument denoting the number of channels/components in the image (e.g. 1 for grayscale, 3 for RGB, and 4 for RGBA).
  *
  *shall read any number of bytes from standard input, assumed to be pixel values with one byte per pixel component (e.g. 3 bytes/24 bits per RGB pixel).
  *
  *The least-significant bit of one byte in each pixel shall be considered one bit in a hidden/encoded message. The byte containing the special bit will cycle through the color components, e.g. in an RGB image: The red component of the first pixel, the green component of the second pixel, the blue component of the third pixel, the red component of the fourth pixel, etc.
  *
  *shall assume the message is terminated with a null character (0b00000000).
  *
  *shall print the entire decoded message (without the null character) to standard output.
  *
  *@author Samantha Cortes
  */

#include <iostream>
#include <string>
#include <vector>

char isBitSet(char ch) {
  char num1 = 1;
  char num0 = 0;

  if (ch & 0x01) {
    return num1;
  } else {
    return num0;
  }
}

int main(int argc, char **argv) {
  int arg;
  char bit_code = 0;
  char bit_count = 0;
  bool done = false;
  int pixel_count = 0;

  arg = std::stoi(argv[1]);

  std::vector<char> reading_bits(arg);

  while (done != true) {
    std::cin.read(reading_bits.data(), arg);


    bit_code <<= 1;
    bit_code += isBitSet(reading_bits[pixel_count % arg]);

    bit_count++;

    if (bit_count == 8) {
        if (bit_code == '\0') {
            done = true;
            (void) done;
            break;
        }
        bit_count = 0;
        std::cout << bit_code;
        bit_code = 0;
    }
    pixel_count++;
  }
}

