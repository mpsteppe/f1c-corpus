## UIRenderDispatchWrapper_00488f40 — UIRenderDispatchWrapper

**Summary:** If a linked child at offset 0xC8 exists, copies its string at +64 to the widget's own string buffer via sub_498560, then delegates to UILargeRenderDispatcher for actual rendering.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xC8) | 0x40 | R | — | Child object's string pointer (at +64) |
| this | 0x40 | R | — | Widget's own string buffer pointer |
| this | 0xC8 | R | — | Child object reference to copy text from |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00488be0 | UILargeRenderDispatcher | Perform actual text rendering |
| 00498560 | sub_498560 | Copy string between buffers |

**Guard conditions:** If *(this+0xC8) is null, skips string copy and goes directly to UILargeRenderDispatcher.
