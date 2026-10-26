## InitWithVTableSet_004702a0 — InitWithVTableAndParamStore

**Summary:** Constructor: calls ConstructorWithStringCopy base initializer, stores integer parameter a2 at offset 0x304, sets vtable to off_5A0308, and returns the object.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5A0308 |
| this | 0x304 | RW | — | stores parameter a2 (index 0/flag/data) |

**Written-by note (persistence):**
- this 0x0: set once to vtable off_5A0308; overwritten if external code changes vtable
- this 0x304: set once from parameter a2; survives unless external code modifies it

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a0308 | off_5A0308 | R | VTablePtr_5A0308 [DERIVED] — vtable pointer assigned to this object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048b420 | ConstructorWithStringCopy | base object constructor with string copy capability (called with zeros and trailing 1) |

**Guard conditions:** No guards — unconditional initialization.
