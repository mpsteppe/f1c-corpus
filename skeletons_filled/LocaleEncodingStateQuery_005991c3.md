## LocaleEncodingStateQuery_005991c3 — EncodingStateQueryWithLocaleFallback

**Summary:** Queries encoding state structure from locale object. Returns 24-byte state blob copied to output buffer. Falls back to default state if encoding doesn't match or stream read fails.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40 | R | — | encoding state value (starting byte/mbstate) included in result |
| this | 0x50 | R | — | pointer to encoding state object used for query |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587f64 | sub_587F64 | check if encoding/locale matches a3/a4 parameters |
| 0058801d | StringStreamReadWithMaskCheck | read encoding state from string stream with mask validation |
| 0059942b | sub_59942B | create default encoding state object (-1 = default) |

**Guard conditions:** if this+0x50 is NULL (no encoding state) OR sub_587F64 returns non-zero (encoding mismatch) OR StringStreamReadWithMaskCheck fails → fall back to default state from sub_59942B(-1). Else build state from stream read result and this+0x40.
