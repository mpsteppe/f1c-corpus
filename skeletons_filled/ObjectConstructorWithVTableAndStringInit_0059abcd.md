## ObjectConstructorWithVTableAndStringInit_0059abcd — Locale facet object constructor with vtable and string init

**Summary:** Constructs a locale facet object. Sets ref count to 1, initial vtable to std::locale::facet, copies flag bytes from parameters to offsets 0x14 and 0x18, zeroes offsets 0x8-0x10, initializes a null-terminated string buffer at offset 0x18 from global word_5C406C, then overrides vtable with off_5B9D4C.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_59AAB9 (0059aab9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | Previously zeroed field (v3[2] cleared to 0) |
| this | 0xB | R | — | Flag byte read from parameter at a1+11 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d510 | loc_59D510 | R | SEH continuation/landing pad address |
| 005b9d4c | off_5B9D4C | R | VTable_5B9D4C [DERIVED] |
| 005b9d54 | ??_7facet@locale@std@@6B@ | R | VTable_StdfacetLocale [DERIVED] |
| 005c406c | word_5C406C | R | InitStringConstant [DERIVED] (also: global string constant used for initialization) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | Initialize SEH handler frame on stack |
| 0058e1b0 | Strlen | Compute length of init string constant |
| 005993af | ReferenceCountDecrementWithConditionalFree | Release ref on buffer at this+6 before reinit |
| 00599615 | BufferWriteWithNullTerminate | Copy init string into buffer with null terminator |

**Guard conditions:** No explicit guard conditions — full sequence always executes.
