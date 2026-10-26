## VTableSetSubCall_005998e5 — VTableConstructorFixupOStream

**Summary:** C++ constructor vtable fixup for ostream base: reads vcall offset from vtable slot at index 1 (offset 0x4), writes `std::basic_ostream<unsigned short>::vftable` at `this + offset`. Tail-calls to 0x599BE5.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PhysicsObjectDestructorWrapper (0059a317)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | vtable slot index 1 — vcall offset for base class vtable adjustment |
| this | 0x0 | R | — | vtable pointer — read to get vcall offset |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9c48 | ??_7?$basic_ostream@GU?$char_traits@G@std@@@std@@6B@ | R | VTable_basic_ostream_wchar [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional vtable fixup as part of constructor chain.
