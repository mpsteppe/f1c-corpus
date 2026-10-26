## CDestructorWithVTableChain_00599e71 — Streambuf destructor with vtable chain teardown

**Summary:** Tears down streambuf/locale object under SEH protection: sets vtable to off_5B9C68, conditionally runs cleanup callback based on flag at offset 0x48, frees allocated buffer at offset 0x44 after ref-count decrement, virtual-dispatches cleanup on locale facets at offsets 0x4C and 0x34, resets vtable to basic_streambuf.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_59A38D (0059a38d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d44f | loc_59D44F | R | address of exception handler code registered by SEHHandlerInit |
| 005b9c68 | off_5B9C68 | R | PTR_VTABLE_5B9C68 [DERIVED] |
| 005b9ca0 | ??_7?$basic_streambuf@GU?$char_traits@G@std@@@std@@6B@ | R | VTable_5B9CA0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | frees allocated memory |
| 0058a5d8 | SEHHandlerInit | registers SEH exception handler for frame |
| 00598c70 | NullCheckWithVirtualDispatch | checks for null then dispatches virtual call |
| 005993af | ReferenceCountDecrementWithConditionalFree | decrements reference count and conditionally frees |
| 0059a44c | ConditionalCallbackWithNullCheck | conditionally runs cleanup callback |

**Guard conditions:** Checks byte at v1+72 (offset 0x48). If non-zero, calls ConditionalCallbackWithNullCheck. If zero, skips that callback. Also checks v2[17] (pointer at offset 0x44) — if non-null, decrements ref count and frees it; if null, skips buffer deallocation.
