## __vsnprintf_00632098 — CRT _vsnprintf

**Summary:** MSVC CRT `_vsnprintf`: formats a va_list into a fixed-size buffer through the `_output` engine, NUL-terminating when room remains. Returns the number of characters that would have been written (classic _vsnprintf truncation semantics), not the stored count.

**Called by:** sub_41D810 (0041d810), MMX3DNowVectorTransform [structural] (00649374), sub_65A0B7 (0065a0b7), sub_65DD1F (0065dd1f), sub_65DDE6 (0065dde6), sub_65EC68 (0065ec68), sub_663C07 (00663c07), sub_663C69 (00663c69), sub_686791 (00686791), sub_686816 (00686816), sub_694A67 (00694a67), sub_694B97 (00694b97) … +2 more

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | First byte of the output buffer; set to 0 as the terminating NUL character when the buffer count has not been exhausted |

**Written-by note (persistence):**
- this 0x0: written once at the end of a call that still had remaining buffer space; the buffer is caller-owned and rewritten by the next formatted write, so an external poke would not survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00637022 | sub_637022 | Overflow handler called with `(0, &v6)` when the BufferCount budget is exhausted (underflowed) |
| 006371c9 | __output | Core printf formatting engine that consumes the va_list and returns the full untruncated character count |

**Guard conditions:** `if (Buffer)`: a null destination skips the terminator write entirely (count-only callers). Inside, `if ((--v7 & 0x80000000) != 0)` — decrementing the remaining BufferCount underflows (more characters were emitted than the buffer can hold) → overflow handler `sub_637022(0, &v6)` runs and the buffer may be left without a terminator; otherwise `*v6 = 0` writes the NUL terminator. The return value is always `_output`'s character count.
