## _vsprintf_00631cae — CRT vsprintf

**Summary:** ANSI CRT `vsprintf`: formats a va_list through the shared `_output` engine into a caller-supplied buffer and NUL-terminates it unless the buffer pointer is null. Returns the number of characters written.

**Called by:** sub_5D8C80 (005d8c80), sub_613D30 (00613d30), sub_617350 (00617350)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | First byte of the output buffer; set to 0 as the terminating NUL character after formatting (only when Buffer is non-null) |

**Written-by note (persistence):**
- this 0x0: written once at the end of each call (string terminator) into the caller-owned buffer; subsequent vsprintf/sprintf calls into the same buffer overwrite it, so an external poke would not survive the next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00637022 | sub_637022 | Overflow/error handling for the output stream (invoked with stream id 0 and the output-state struct when the character budget goes negative) |
| 006371c9 | __output | Core printf formatting engine that consumes the va_list and emits characters through the output-state struct; returns the count written |

**Guard conditions:** `if (Buffer)`: if the destination pointer is null, formatting runs but no terminator is written (size-counting callers use 0x7FFFFFFF budget). Inside, `if (--v6 < 0)` — the 0x7FFFFFFF (INT_MAX) character budget exhausted — calls sub_637022 (overflow handler); otherwise `*v5 = 0` writes the NUL terminator at the current position. Returns the character count from `_output` in every case.
