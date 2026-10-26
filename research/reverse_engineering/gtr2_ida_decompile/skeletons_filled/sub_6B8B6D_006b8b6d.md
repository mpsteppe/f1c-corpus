## sub_6B8B6D_006b8b6d — deflateEnd (free zlib deflate state)

**Summary:** zlib `deflateEnd()` equivalent: validates the stream state, releases the four internal state buffers and then the state structure itself through the stream's zfree callback, clears strm->state, and returns Z_OK unless the stream was still busy. Cleanup counterpart of the deflate driver.

**Called by:** sub_67A404 (0067a404), sub_6B96C8 (006b96c8)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C) | 0x4 | R | — | Deflate status: must be 42/113/666; 113 (busy) forces the Z_DATA_ERROR return |
| *(this+0x1C) | 0x8 | R | — | Internal buffer pointer freed via zfree (pending data buffer) |
| *(this+0x1C) | 0x30 | R | — | Internal buffer pointer freed via zfree (window buffer) |
| *(this+0x1C) | 0x38 | R | — | Internal buffer pointer freed via zfree (hash prev-chain table) |
| *(this+0x1C) | 0x3C | R | — | Internal buffer pointer freed via zfree (hash head table) |
| this | 0x1C | RW | 0 | strm->state; set to NULL after the state is released |
| this | 0x24 | R | — | strm->zfree — deallocation callback invoked for each buffer and for the state |
| this | 0x28 | R | — | strm->opaque — pass-through argument for the zfree callback |

**Written-by note (persistence):**
- this 0x1C: written once at the end of this call (set to NULL); it is the terminal teardown, so no further poke can survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** BLOCKING entry checks: NULL stream or NULL state returns -2 (Z_STREAM_ERROR); a status other than 42, 113 or 666 also returns -2. Each buffer free (0x8, 0x30, 0x38, 0x3C) is conditional on its pointer being nonzero — NULL pointers are skipped. Final return: 0 (Z_OK) unless the saved status was 113 (busy), in which case -3 (Z_DATA_ERROR).
