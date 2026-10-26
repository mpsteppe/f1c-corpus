## ObjectInitWithVTable_b038_0059b038 — std::out_of_range exception vtable constructor

**Summary:** Constructs `std::out_of_range` exception object. Calls CObjectConstructorWithVtable (logic_error base), then overrides vtable pointer with std::out_of_range vtable.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ExceptionThrowWrapper (0059afff)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | VTable pointer, overwritten with out_of_range vtable |

**Written-by note (persistence):**
- this 0x0: Once — vtable pointer set at construction. No external poke survives; only called once per object.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9d8c | ??_7out_of_range@std@@6B@ | R | StdOutOfRangeVtable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059ae7d | CObjectConstructorWithVtable | Construct logic_error base exception (string copy + flag transfer) |

**Guard conditions:** No explicit guard conditions — full sequence always executes.
