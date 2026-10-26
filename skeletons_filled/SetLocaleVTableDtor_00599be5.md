## SetLocaleVTableDtor_00599be5 — Set locale vtable and destruct

**Summary:** Sets vtable pointer to basic_ios vtable for locale object, then calls ObjectDestructorWithRefCountDecrement on the same object.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalFreeWithFlagCheck_a336 (0059a336)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to basic_ios vtable before destructor |

**Written-by note (persistence):**
- this 0x0: written once to basic_ios vtable address, then destructor runs; value survives until destructor call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9c50 | ??_7?$basic_ios@GU?$char_traits@G@std@@@std@@6B@ | R | VTable_basic_ios [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00599a47 | ObjectDestructorWithRefCountDecrement | destroys object and decrements reference counter |

**Guard conditions:** None — unconditional execution.
