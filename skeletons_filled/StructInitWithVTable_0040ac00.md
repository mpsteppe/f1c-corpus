## StructInitWithVTable_0040ac00 — UI Object Constructor

**Summary:** Initializes a struct with VTable_UIObject_59E678 and zeros 5 fields. Acts as a constructor for a UI object.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneFileLoadByCurrentIndex (0040c240)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | VTable pointer (set to VTable_UIObject_59E678) |
| this | 0x4 | RW | 0 | UI object field 1 (zeroed) |
| this | 0x8 | RW | 0 | UI object field 2 (zeroed) |
| this | 0xC | RW | 0 | UI object field 3 (zeroed) |
| this | 0x10 | RW | 0 | UI object field 4 (zeroed) |
| this | 0x14 | RW | 0 | UI object field 5 (zeroed) |

**Written-by note (persistence):**
- this 0x0: Written unconditionally every call (to off_59E678). External poke does NOT survive.
- this 0x4: Written unconditionally every call (to 0). External poke does NOT survive.
- this 0x8: Written unconditionally every call (to 0). External poke does NOT survive.
- this 0xC: Written unconditionally every call (to 0). External poke does NOT survive.
- this 0x10: Written unconditionally every call (to 0). External poke does NOT survive.
- this 0x14: Written unconditionally every call (to 0). External poke does NOT survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e678 | off_59E678 | R | VTable_UIObject_59E678 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — all writes execute unconditionally.
