## BufferTruncationShrink_00599348 — BufferTruncateRemoveRange

**Summary:** Removes `a3` bytes from buffer starting at offset `a2`. Shifts remaining data, updates size at this+0x8, and null-terminates. Validates bounds before operation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_598E9E (00598e9e), CharValidationAgainstEncodingTableWithLocaleFall (00598fd4), sub_5990AE (005990ae), sub_599ED6 (00599ed6), FileOffsetPositionValidation (0059a01e), sub_59A103 (0059a103), sub_59A221 (0059a221), sub_59A9CA (0059a9ca)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | buffer data pointer (start of allocated buffer) |
| this | 0x8 | RW | — | current buffer size, updated after truncation |

**Written-by note (persistence):**
- this 0x8: written when truncation succeeds; external poke would corrupt buffer size tracking

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058b130 | sub_58B130 | memmove/shift memory within buffer after removed range |
| 00599560 | sub_599560 | validate new buffer position before updating size |
| 005995e5 | ConditionalStringFreeWithLengthCheck | free previous string data if buffer was holding allocated string |
| 0059af68 | sub_59AF68 | handle buffer underflow or invalid truncation offset |

**Guard conditions:** if this+0x8 (size) < a2 (remove offset), call sub_59AF68 (invalid). Cap remove count to available data. Only proceed if remove count > 0.
