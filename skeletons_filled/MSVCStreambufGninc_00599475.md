## MSVCStreambufGninc_00599475 — StreambufGetPtrIncrement

**Summary:** MSVC streambuf get-pointer increment (gninc). Pre-decrements remaining count at this+0x2C, then returns current byte from read pointer at this+0x1C and increments it. Advances buffer read position by one byte.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StdBasicStreambufUflow (00598cdc), sub_5990AE (005990ae)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C) | 0x0 | R | — | current byte value at read pointer before increment |
| *(this+0x2C) | 0x0 | R | — | remaining byte count value before decrement |
| this | 0x1C | R | — | pointer to current read position (pointer-to-pointer to buffer) |
| this | 0x2C | R | — | pointer to remaining byte count |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional read position advance.
