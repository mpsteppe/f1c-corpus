## NameStringCopy_0042ed50 — BoundedStringCopy

**Summary:** Copies up to 63 characters from source string a2 into struct buffer at this+0x70. Ensures null termination at this+0xAF.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TheSvmHdvVehicleFileParser (004f4270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xAF | RW | 0 | stringNullTerminator |

**Written-by note (persistence):**
- this 0xAF: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587dd0 | sub_587DD0 | Bounded string copy (strncpy-style) with max length parameter |

**Guard conditions:** None — always copies string and null-terminates.
