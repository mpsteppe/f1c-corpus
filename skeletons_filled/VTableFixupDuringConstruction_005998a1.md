## VTableFixupDuringConstruction_005998a1 — VTableConstructorFixup

**Summary:** C++ constructor vtable fixup: reads vcall offset from vtable slot at index 1 (offset 0x4), then writes `std::basic_istream<unsigned short>::vftable` to `this + offset`. Tail-calls to 0x599BE5.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestructorConditionalFree (0059a352)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | vtable slot index 1 — vcall offset for base class vtable adjustment |
| this | 0x0 | R | — | vtable pointer — read to get vcall offset |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9c40 | ??_7?$basic_istream@GU?$char_traits@G@std@@@std@@6B@ | R | IStreamWVTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional vtable fixup as part of constructor chain.
