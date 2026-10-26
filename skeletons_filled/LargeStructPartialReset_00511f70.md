## LargeStructPartialReset_00511f70 — Partial structure reset preserving vtable header and three fields

**Summary:** Releases multiple sub-resources via conditional callbacks, then zeroes most of the struct (0x19C bytes) while preserving the first 0x40 bytes (vtable header) and DWORDs at offsets 0x40, 0x44, 0x48.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ThreeObjectCleanupChain (00512093)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40 | RW | — | DWORD at offset 64 (preserved across reset) |
| this | 0x44 | RW | — | DWORD at offset 68 (preserved across reset) |
| this | 0x48 | RW | — | DWORD at offset 72 (preserved across reset) |
| this | 0x5D | R | — | byte at offset 93: flag bits controlling sub-resource release |
| this | 0x9C | R | — | pointer to sub-resource (released unconditionally) |
| this | 0xD8 | R | — | pointer to sub-resource (released unconditionally) |
| this | 0xDC | R | — | pointer to sub-resource (released unconditionally) |
| this | 0x104 | R | — | pointer to sub-resource (released conditionally on bit 0x10) |
| this | 0x12C | R | — | exponent byte for computing array-element count: 1 << (8 - value) |
| this | 0x138 | R | — | pointer to sub-resource (released unconditionally) |
| this | 0x144 | R | — | pointer to array of sub-resource pointers (released with counted loop) |
| this | 0x15C | R | — | pointer to sub-resource (released conditionally on bit 0x20) |
| this | 0x174 | R | — | pointer to sub-resource (released unconditionally) |
| this | 0x178 | R | — | pointer to sub-resource (released unconditionally) |

**Written-by note (persistence):**
- this 0x40: preserved from old to new struct after memset
- this 0x44: preserved from old to new struct after memset
- this 0x48: preserved from old to new struct after memset

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00513cd3 | SafeDeleteGuardForThunkFUN00517ec8 | release sub-resource at offset 0x104 with safe-delete guard |
| 00513d2f | ShortComputation_3d2f | perform computation on a2/a3 parameters before reset |
| 005179a2 | sub_5179A2 | cleanup/release resource at offset 0x64 |
| 00517ec8 | ConditionalCall_7ec8 | conditionally release a sub-resource pointer |

**Guard conditions:** Two flag checks on byte at this+0x5D: bit 0x10 enables SafeDeleteGuard on offset 0x104; bit 0x20 enables ConditionalCall_7ec8 on offset 0x15C. Additionally, DWORD at offset 0x144 (non-null) gates a counted-pointer-array release loop whose count = 1 << (8 - *(byte)(this+0x12C)).
