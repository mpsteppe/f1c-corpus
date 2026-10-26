## VtableSetSubCall_8aea_00598aea — IosVtableSetAndTailCall

**Summary:** Sets the object's vtable pointer to std::ios::vftable, then tail-calls to another initialization routine at 0x59A86C. Part of C++ stream object construction chain.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_59927C (0059927c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to std::ios::vftable) |

**Written-by note (persistence):**
- this 0x0: once — vtable pointer written to point to ios vtable; persists as object's type identity

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9bb4 | ??_7?$basic_ios@DU?$char_traits@D@std@@@std@@6B@ | R | IosVtable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None unconditional.
