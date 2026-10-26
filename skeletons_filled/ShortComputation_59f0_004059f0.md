## ShortComputation_59f0_004059f0 — AudioSampleEndAndReinit

**Summary:** Ends current Miles audio sample playback and reinitializes the sample handle, then clears the sample handle pointer and its reference back-pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x68) | 0x10 | R | — | Sample handle (passed to AIL_end_sample/AIL_init_sample) |
| this | 0x58 | RW | 0 | Pointer to sample handle struct (cleared to 0 after cleanup) |
| this | 0x68 | R | — | Indirection to sample handle (this[0x68]→0x10 = sample handle) |

**Written-by note (persistence):**
- this 0x58: set to 0 after cleanup (overwrites previous handle pointer)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e3d8 | _AIL_end_sample@4 | R | Stop/end sample playback via Miles API |
| 0059e3dc | _AIL_init_sample@4 | R | Reinitialize sample after ending |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Two-level null check: first checks if `this[22]` (offset 0x58, sample handle struct pointer) is non-null. If null → blocked (returns 0). Then checks if `*(this[22]+16)` (sample handle itself) is non-null. If null → skips AIL_end_sample/AIL_init_sample but still clears the back-pointer. Both must be non-null to PASS and execute sample cleanup.
