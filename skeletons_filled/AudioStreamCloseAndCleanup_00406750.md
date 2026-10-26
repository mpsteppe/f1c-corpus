## AudioStreamCloseAndCleanup_00406750 — AudioStreamCloseAndCleanup

**Summary:** Closes a Miles audio stream if handle is non-null, performs additional cleanup via sub_406A70 when a slot index is not -1, and initializes a structure from sub_4080B0 result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SortedStringListInsert (004062b0), ViewCameraReset (004064c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | 0 | Miles audio stream handle (closed and set to 0) |
| this | 0x1C | R | — | parameter passed to sub_4080B0 for struct init |
| this | 0x5C | R | — | slot index (checked against -1 to decide sub_406A70 call) |

**Written-by note (persistence):**
- this 0xC: written conditionally — set to 0 after stream close

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e37c | _AIL_close_stream@4 | R | Miles Sound System API to close an audio stream |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00406a70 | sub_406A70 | performs additional cleanup when slot index (offset 0x5C) is not -1 |
| 004080b0 | sub_4080B0 | retrieves or initializes a sub-struct from slot at offset 0x1C |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x5C | != | 18446744073709551615 | slot index at offset 0x5C compared to -1 |

**Guard interpretation:** When this[23] (offset 0x5C) != -1, calls sub_406A70(this) for additional slot cleanup. When -1, skips that call entirely.
