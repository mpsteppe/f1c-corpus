## UIScreenSelectionHandler_0048d6b0 — UIScreenSelectionHandler

**Summary:** Handles UI screen selection by retrieving a screen object from this+0x40, getting its path string (via FieldGetterAt0x1570, field at +0xC0 from the screen object), and comparing it to a stored path via UIStringComparison. If a valid screen object exists, triggers a content-changed signal.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | Vtable offset 44 — signal content changed |
| this | 0x0 | R | — | Vtable pointer of the UI list |
| this | 0x40 | R | — | Pointer to the selected screen object (this[16]) |
| this | 0xEC | RW | — | Stored screen identifier/pointer (this[59]) |

**Written-by note (persistence):**
- this 0xEC: set to the retrieved screen object pointer; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00488b40 | UIStringComparison | Compare screen's path string with stored reference |
| 00495790 | FieldGetterAt0x1570 | Get a string/name field from the screen object |

**Guard conditions:** PASS: retrieved screen object is non-null. BLOCKED: null screen object → skip (return 0 without signal).
