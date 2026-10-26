## ConstructorWithVTableAndParamStore_0046f610 — Constructor with vtable and parameter store

**Summary:** Calls ConstructorWithByteParams to zero-initialize object, stores parameter a2 at offset 0xE4 (this[57]), sets vtable to off_59FF80, then returns constructed object pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_59FF80 | vtable pointer — set to off_59FF80 after base initialization |
| this | 0xE4 | RW | a2 (parameter) | field at offset 228 (this[57]) — stores constructor parameter a2 |

**Written-by note (persistence):**
- this 0x0: once — written by this function, persists until object destroyed or vtable swapped
- this 0xE4: once — set from constructor parameter a2; persists until explicitly modified

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059ff80 | off_59FF80 | R | vtable reference assigned to object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487220 | ConstructorWithByteParams | base initializer: zeroes object fields with two byte parameters |

**Guard conditions:** No guards. Always runs ConstructorWithByteParams, stores a2, sets vtable, returns this.
