## ConditionalDraw_00475c80 — DrawRedLineIfEnabled

**Summary:** Checks a render debug flag; if set, draws a red line (color 0xFF0000) between two 2D points provided as parameters.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_475A90 (00475a90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | First point X coordinate |
| this | 0x4 | R | — | First point Y coordinate |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] — debug render enable flag |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00494c20 | FloatVectorWithConditionalTransform | Draws a colored line between two 2D points |
| 00495150 | GlobalAccessor_5150 | Checks if debug rendering is enabled |

**Guard conditions:** Drawing PASSES only when GlobalAccessor_5150(&unk_7CDE00) returns non-zero. If zero (disabled), drawing BLOCKED — returns immediately.
