## BufferWriteWithNullTerminate_00599615 — BufferWriteWithNullTerminate

**Summary:** Writes `a3` bytes from source `a2` to buffer at this+0x4. Validates/resizes buffer via sub_599560 first, then copies data, updates size at this+0x8 to `a3`, and null-terminates. Returns this.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalStringFreeWithLengthCheck (005995e5), sub_59A5FE (0059a5fe), sub_59AAB9 (0059aab9), ObjectConstructorWithVTableAndStringInit (0059abcd), sub_59AD49 (0059ad49), sub_59AF68 (0059af68)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | buffer data pointer — destination for memory copy |
| this | 0x8 | RW | — | buffer size — updated to a3 after successful write |

**Written-by note (persistence):**
- this 0x8: written to a3 on successful write; external poke would corrupt buffer size tracking

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058cc00 | MemoryCopy_cc00 | copy a3 bytes from source a2 to buffer at this+0x4 |
| 00599560 | sub_599560 | validate/resize buffer to accommodate a3 bytes before write |

**Guard conditions:** if sub_599560 returns 0 (buffer validation/resize failed), skip write entirely.
