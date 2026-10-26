## ConstructorWithStringCopy_0048b420 — Edit box constructor with string copy

**Summary:** Initializes text edit box widget: sets vtable (off_5ABED0), allocates/finds string buffer (a2 or this+0xE6), copies initial text (a3) into dual buffers, sets byte flags (0xE2, 0xE5) and max length (a6).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConstructorWithBulkInitAndVTable (00470230), InitWithVTableSet (004702a0), sub_48C070 (0048c070), sub_493FC0 (00493fc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5ABED0 (VTable_EditBox) |
| this | 0xE2 | RW | — | byte flag (a5) — widget option/behavior flag |
| this | 0xE5 | RW | — | byte flag (a7) — widget option/behavior flag |
| this | 0x2E8 | RW | — | this+744 — max length / bound value (a6) |
| this | 0x2F0 | RW | — | this+752 — string buffer pointer (a2 or fallback this+0xE6) |
| this | 0x2FC | RW | 0 | this+764 — zeroed on construction |

**Written-by note (persistence):**
- this 0x0: written once during construction (vtable assignment)
- this 0xE2: written once during construction
- this 0xE5: written once during construction
- this 0x2E8: written once during construction
- this 0x2F0: written once during construction (buffer pointer)
- this 0x2FC: written once during construction (set to 0)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005abed0 | off_5ABED0 | R | VTable_EditBox [DERIVED] — edit box vtable assigned to this object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00485e30 | ShortComputation_5e30 | initializes base widget state before setup |
| 0048b4f0 | sub_48B4F0 | performs further initialization of edit box internals |
| 0048b8f0 | BoundedFieldSetter | sets max length / bound on text field |

**Guard conditions:** a3 (initial text) string copy only happens if a3 is non-null AND strlen(a3) < a4 (max length). If a2 (buffer pointer) is null, uses this+0xE6 (internal buffer offset 230).
