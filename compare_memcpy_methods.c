#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

#define SIZE 1024 * 1024 // 1MB size for testing

// Bitwise optimized memcpy
void memcpy_optimized_bitwise(char *dest, const char *src, size_t n) {
    size_t i;

    for (i = 0; i < n / 8; i++) {
        uint64_t value = 0;

        // Copy each byte from src to value
        for (int j = 0; j < 8; j++) {
            value |= (uint64_t)(unsigned char)src[i * 8 + j] << (j * 8);
        }

        // Copy value to destination
        for (int j = 0; j < 8; j++) {
            dest[i * 8 + j] = (char)(value & 0xFF);
            value >>= 8;
        }
    }

    // Copy remaining bytes if any
    for (i = n - (n % 8); i < n; i++) {
        dest[i] = src[i];
    }
}

// Casting optimized memcpy
void memcpy_optimized_casting(char *dest, const char *src, size_t n) {
    size_t i;

    for (i = 0; i < n / 8; i++) {
        *((uint64_t *)(dest + i * 8)) = *((uint64_t *)(src + i * 8));
    }

    // Copy remaining bytes if any
    for (i = n - (n % 8); i < n; i++) {
        dest[i] = src[i];
    }
}

// Direct byte-by-byte copy
void memcpy_byte_by_byte(char *dest, const char *src, size_t n) {
    size_t i;

    for (i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

// Standard memcpy
void memcpy_standard(char *dest, const char *src, size_t n) {
    memcpy(dest, src, n);
}

int main() {
    // Allocate memory for source and destination arrays
    char *src = (char *)malloc(SIZE);
    char *dest1 = (char *)malloc(SIZE);
    char *dest2 = (char *)malloc(SIZE);
    char *dest3 = (char *)malloc(SIZE);
    char *dest4 = (char *)malloc(SIZE); // For standard memcpy

    // Fill source array with some data (e.g., a simple pattern)
    for (size_t i = 0; i < SIZE; i++) {
        src[i] = (char)(i % 256);
    }

    // Measure time for bitwise memcpy
    clock_t start = clock();
    memcpy_optimized_bitwise(dest1, src, SIZE);
    clock_t end = clock();
    double bitwise_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bitwise memcpy time: %f seconds\n", bitwise_time);

    // Measure time for casting memcpy
    start = clock();
    memcpy_optimized_casting(dest2, src, SIZE);
    end = clock();
    double casting_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Casting memcpy time: %f seconds\n", casting_time);

    // Measure time for direct byte-by-byte memcpy
    start = clock();
    memcpy_byte_by_byte(dest3, src, SIZE);
    end = clock();
    double byte_by_byte_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Byte-by-byte memcpy time: %f seconds\n", byte_by_byte_time);

    // Measure time for standard memcpy
    start = clock();
    memcpy_standard(dest4, src, SIZE);
    end = clock();
    double standard_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Standard memcpy time: %f seconds\n", standard_time);

    // Free allocated memory
    free(src);
    free(dest1);
    free(dest2);
    free(dest3);
    free(dest4);

    return 0;
}
