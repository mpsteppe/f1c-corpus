## ShortComputation_f890_0046f890 — ConstructorWithByteParamAndVTableInit

**Summary:** Constructor: calls base ConstructorWithByteParams (0,0), stores a byte parameter at offset 0xE4, and sets vtable pointer to off_5A0040. Returns initialized object pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5A0040 |
| this | 0xE4 | RW | — | byte storage for parameter a2 |

**Written-by note (persistence):**
- this 0x0: set once to vtable address off_5A0040; overwritten if external code writes new vtable
- this 0xE4: set once from parameter a2; survives unless external code modifies it

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a0040 | off_5A0040 | R | vtable pointer assigned to this object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487220 | ConstructorWithByteParams | base object constructor, called with (this, 0, 0) |

**Guard conditions:** No guards — function unconditionally initializes object and returns.
