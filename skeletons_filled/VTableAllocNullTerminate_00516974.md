## VTableAllocNullTerminate_00516974 — AllocAndNullTerminateBuffer

**Summary:** Allocates a 130-byte buffer via vtable function at *(this+4) (first entry, called as allocator), writes a zero byte at offset 128 (null terminator), and returns the buffer pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MP3HuffmanDecoder (00510d60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | first vtable entry of allocator object at this+0x4, called with (this, 0, 130) to allocate buffer |
| this | 0x4 | R | — | pointer to allocator object used for buffer allocation |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No conditional branches — always allocates 130 bytes and null-terminates at offset 128.
