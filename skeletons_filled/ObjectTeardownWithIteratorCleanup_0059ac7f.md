## ObjectTeardownWithIteratorCleanup_0059ac7f — Locale facet array-based object teardown

**Summary:** Destroys a locale facet object containing an array of facet pointers. Iterates the facet array (count at this+0xC, array at this+0x8), decrements each facet's reference count via RefcountDecrementWithLock and conditionally destroys it. Frees the array allocation, releases the string buffer at this+6, and resets vtable to std::locale::facet.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ExceptionDestructorWithConditionalFree (0059ac63)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d537 | loc_59D537 | R | SEH continuation/landing pad address |
| 005b9d4c | off_5B9D4C | R | VTable_5B9D4C [DERIVED] |
| 005b9d54 | ??_7facet@locale@std@@6B@ | R | VTable_StdfacetLocale [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | Initialize SEH handler frame on stack |
| 0058aa6f | sub_58AA6F | Free heap-allocated facet pointer array |
| 00598c88 | RefcountDecrementWithLock | Thread-safe reference decrement on facet object |
| 005993af | ReferenceCountDecrementWithConditionalFree | Release reference on string buffer at this+6 |
| 0059a54d | sub_59A54D | CRT init prologue |
| 0059a5e9 | sub_59A5E9 | CRT cleanup epilogue |

**Guard conditions:** `while (v3)` — loops while facet count > 0, processing each array entry. `if (v4)` — skip null facet slots.
