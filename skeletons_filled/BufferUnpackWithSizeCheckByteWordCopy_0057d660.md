## BufferUnpackWithSizeCheckByteWordCopy_0057d660 — UnpackAndVerifyStructuredPacket

**Summary:** Unpacks structured packet from input buffer a1: verifies payload size against expected size from a2, conditionally copies payload to *(a2+20), then copies remaining data via MemcpyLikeWithRealloc.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57CB50 (0057cb50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | input header WORD: declared payload size (compared against expected) |
| this | 0x2 | R | — | input header WORD: secondary size used for trailing data copy |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587510 | MemcpyLikeWithRealloc | copy remaining data after payload (size = a1[1]) with possible reallocation |

**Guard conditions:** if *a1 (declared payload size) does not match computed byte count from a2 bitfield → skip payload qmemcpy (blocked). MemcpyLikeWithRealloc always executes regardless.
