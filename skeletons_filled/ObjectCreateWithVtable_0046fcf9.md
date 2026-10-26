## ObjectCreateWithVtable_0046fcf9 — ObjectCreateWithCallbackAndVTableInit

**Summary:** Creates/initializes an object: calls a function pointer at offset 0x6A from an interface parameter, applies byte adjustments, constructs with byte params, stores a byte at offset 0xE4, and sets vtable to off_5A00F0. Returns the new object pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x6A | R | — | function pointer called during init (offset 106 from interface a1) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a00f0 | off_5A00F0 | R | vtable pointer assigned to new object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487220 | ConstructorWithByteParams | base object constructor, called with byte params |

**Guard conditions:** No guards — function unconditionally executes all steps and returns.
