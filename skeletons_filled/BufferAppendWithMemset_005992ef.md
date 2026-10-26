## BufferAppendWithMemset_005992ef — BufferAppendWithMemsetFill

**Summary:** Appends `a2` bytes of value `a3` to a growable buffer. Checks for overflow, validates new position, fills via sub_58BB10 (memset-like), updates size at this+0x8, and null-terminates. Returns this.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_598E9E (00598e9e), sub_5990AE (005990ae), sub_599ED6 (00599ed6), sub_59A103 (0059a103)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | buffer data pointer (start of allocated buffer) |
| this | 0x8 | RW | — | current buffer size/length, updated after append |

**Written-by note (persistence):**
- this 0x8: written when append succeeds; external poke would corrupt buffer size tracking

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9c38 | dword_5B9C38 | R | SetupConstantValue [DERIVED] (also: setup constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058bb10 | sub_58BB10 | fill memory with byte value (memset-like) at current buffer end |
| 00599560 | sub_599560 | validate/check memory region at new buffer position |
| 0059ad49 | sub_59AD49 | handle buffer overflow error or trigger reallocation |

**Guard conditions:** integer overflow check — if current size + append size would overflow, call sub_59AD49. If append size is zero, skip. If sub_599560 validates new position, proceed with fill and size update.
