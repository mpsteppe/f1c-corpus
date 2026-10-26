## ArrayInitWithSentinelInLoop_00460c60 — ArraySentinelInitLoop

**Summary:** Initializes 104 entries of a DWORD array at this+0x3E18 with -1 sentinel value. Also reinitializes associated struct arrays via helper calls.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SynchronizeWithServer (00464290)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3E18 | RW | 18446744073709551615 | DWORD array (104 elements), each initialized to -1 sentinel |

**Written-by note (persistence):**
- this 0x3E18: once per call — all 104 entries set to -1; persists until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461480 | StructFieldZeroInitWithDefaults | Zero-init struct fields with default values (140-byte struct at this+0x394) |
| 004fffa0 | ThunkWithStructInitSubCalls | Init sub-struct via thunk (872-byte struct at this+0x4180) |

**Guard conditions:** unconditional — always runs 104 iterations, no early exit.
