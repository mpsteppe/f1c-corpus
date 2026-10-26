## VTableConstructor_0059af50 — std::length_error exception vtable constructor

**Summary:** Constructs `std::length_error` exception object. Calls CObjectConstructorWithVtable (logic_error base), then overrides vtable pointer with std::length_error vtable.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CExceptionThrowWrapper_af17 (0059af17)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | VTable pointer, overwritten with length_error vtable |

**Written-by note (persistence):**
- this 0x0: Once — vtable pointer set at construction. No external poke survives; only called once per object.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9d5c | ??_7length_error@std@@6B@ | R | VTable_StdLengthError [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059ae7d | CObjectConstructorWithVtable | Construct logic_error base exception (string copy + flag transfer) |

**Guard conditions:** No explicit guard conditions — full sequence always executes.
