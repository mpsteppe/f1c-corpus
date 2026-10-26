## TokenMatchingLoop_00492030 — Match brace/bracket pairs and count nesting

**Summary:** Parses tokenized input tracking brace/bracket nesting depth using a counter. Skips past delimiters, then matches open/close tokens to find matching pairs. Decrements this[101] (nesting counter).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_492A40 (00492a40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x194 | R | — | Nesting depth counter (this[101]), decremented after match |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005cc4f4 | asc_5CC4F4 | R | Str_UI_CompareToken_CC4F4 [DERIVED] |
| 005cc4f8 | asc_5CC4F8 | R | StringDelimiter_Brace [DERIVED] |
| 007cdb70 | unk_7CDB70 | R | StringCompareBuffer_007CDB70 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00491fb0 | sub_491FB0 | Reads next line and updates token counters |
| 00587c20 | sub_587C20 | Compares current token against a delimiter string |

**Guard conditions:** Returns immediately if sub_491FB0 fails (no input). Skips tokens matching delimiter (asc_5CC4F8). Loops while nesting depth >= 1, incrementing on open token match and decrementing on close token match.
