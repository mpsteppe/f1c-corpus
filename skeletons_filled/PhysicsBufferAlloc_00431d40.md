## PhysicsBufferAlloc_00431d40 — PhysicsBufferAllocator

**Summary:** Allocates three physics system buffers (two of 80 bytes, one of 128 bytes) via OperatorNewNhMallocWrapper, stores pointers and sizes in the struct, and zeroes remaining fields.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Thunk_1bc0 (00431bc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Pointer to first 80-byte buffer |
| this | 0x4 | RW | 80 | Size of first buffer |
| this | 0x8 | RW | — | Pointer to second 80-byte buffer |
| this | 0xC | RW | 80 | Size of second buffer |
| this | 0x10 | RW | — | Pointer to third 128-byte buffer |
| this | 0x14 | RW | 128 | Size of third buffer |
| this | 0x18 | RW | 0 | Flags/counter field (zeroed) |
| this | 0x1C | RW | 0 | Flags/counter field (zeroed) |
| this | 0x20 | RW | 0 | Flags/counter field (zeroed) |
| this | 0x24 | RW | 0 | Flags/counter field (zeroed) |
| this | 0x28 | RW | 0 | Flags/counter field (zeroed) |
| this | 0x2C | RW | 0 | Flags/counter field (zeroed) |
| this | 0x30 | RW | 0 | Flags/counter field (zeroed) |
| this | 0x34 | RW | 0 | Flags/counter field (zeroed) |
| this | 0x38 | RW | 0 | Flags/counter field (zeroed) |
| this | 0x3C | RW | 0 | Flags/counter field (zeroed) |

**Written-by note (persistence):**
- this 0x0: set once per call to freshly allocated pointer. External poke survives until next allocation.
- this 0x4: set once per call to 80. Always re-initialized.
- this 0x8: set once per call to freshly allocated pointer. External poke survives until next allocation.
- this 0xC: set once per call to 80. Always re-initialized.
- this 0x10: set once per call to freshly allocated pointer. External poke survives until next allocation.
- this 0x14: set once per call to 128. Always re-initialized.
- this 0x18-0x3C: set to 0 each call. Always re-initialized.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c03 | OperatorNewNhMallocWrapper | Allocates heap memory of specified byte size |

**Guard conditions:** None — unconditional allocation of all three buffers and zeroing of all fields.
