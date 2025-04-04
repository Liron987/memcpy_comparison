# memcpy_comparison
compare memcpy methods

## Results (no optimization)

### Performance Comparison of memcpy Implementations (without Prefetching)

| Method                        | Time (seconds)   |
| ----------------------------- | ---------------- |
| **Bitwise memcpy**             | 0.003849         |
| **Casting memcpy**             | 0.000572         |
| **Byte-by-byte memcpy**       | 0.002365         |
| **Standard memcpy**           | 0.000388         |

### Performance Comparison of memcpy Implementations (with Prefetching)

| Method                        | Time (seconds)   |
| ----------------------------- | ---------------- |
| **Bitwise memcpy**             | 0.004173         |
| **Casting memcpy**             | 0.000680         |
| **Byte-by-byte memcpy**       | 0.003397         |
| **Standard memcpy**           | 0.000462         |
