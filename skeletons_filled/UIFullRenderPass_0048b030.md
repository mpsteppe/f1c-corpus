## UIFullRenderPass_0048b030 — Full text render pass with word-wrap

**Summary:** Full UI render pass: parses input text, word-wraps at spaces/newlines, measures line widths, builds linked list of rendered segments. Clears then repopulates pool (this[0xEC-0xF8]), computes line height at end.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xF0) | 0x4 | R | — | next node pointer in linked render pool |
| this | 0xC8 | R | — | this[50] — pointer to prefix string source |
| this | 0xEC | RW | 0 | this[59] — pool head pointer (zeroed, then repopulated) |
| this | 0xF0 | RW | 0 | this[60] — pool current/tail pointer (zeroed, then repopulated) |
| this | 0xF4 | RW | 0 | this[61] — pool head copy (zeroed, then repopulated) |
| this | 0xF8 | RW | 0 | this[62] — pool node count (zeroed, then incremented) |
| this | 0x108 | RW | — | this[66] — computed line height (v22 / v27, written conditionally) |

**Written-by note (persistence):**
- this 0xEC: zeroed then repopulated with new pool head each render pass
- this 0xF0: zeroed then updated as nodes added
- this 0xF4: zeroed then set to first node
- this 0xF8: zeroed then incremented per node
- this 0x108: written once conditionally when v27 (text height) is non-zero

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404f70 | ConditionalFreeWithBit0Flag | frees existing pool nodes with conditional bit0 check |
| 00487060 | sub_487060 | gets horizontal boundary positions |
| 004870e0 | sub_4870E0 | gets vertical boundary positions |
| 004983b0 | TextRenderToSurface | measures rendered text width for line-break decisions |
| 00498560 | sub_498560 | processes prefix string from this[0xC8] |
| 005665b0 | sub_5665B0 | processes single character into line buffer |
| 00566650 | StringCopyWithBufferRealloc | copies string into render buffer |
| 00587bcf | FreeWrapper_7bcf | frees heap memory for pool nodes |
| 00587c03 | OperatorNewNhMallocWrapper | allocates heap memory for helper structs and pool nodes |

**Guard conditions:** a2 (input text pointer) must be non-null; if null, function returns immediately without rendering.
