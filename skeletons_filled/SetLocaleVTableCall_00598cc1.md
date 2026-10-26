## SetLocaleVTableCall_00598cc1 — StreambufVtableResetAndDispatch

**Summary:** Resets the object's vtable to std::streambuf::vftable (destructor-time vtable fixup) and dispatches a call through the locale sub-object at offset +52 (this+13). Part of C++ streambuf destructor chain.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestructorWithFlagCleanup_92b7 (005992b7)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to streambuf vtable) |

**Written-by note (persistence):**
- this 0x0: once — set to std::streambuf::vftable during destruction; persists as part of destructor vtable fixup

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9c04 | ??_7?$basic_streambuf@DU?$char_traits@D@std@@@std@@6B@ | R | VTable_basic_streambuf [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None unconditional.
