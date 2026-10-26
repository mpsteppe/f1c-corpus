## DestroyLocaleObjectFreeResourcesCallDtor_00598e39 — LocaleObjectDtorWithFileAndBufferFree

**Summary:** Destructor for locale/file stream object. Closes file handle if byte at this+0x48 is set, decrements refcount and frees buffer at this+0x44, dispatches virtual cleanup on sub-object slots, transitions vtable to base `std::streambuf` vtable.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestructorPattern (005992d3)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d2ef | loc_59D2EF | R | SEH handler landing pad or exception filter for destructor |
| 005b9bcc | off_5B9BCC | R | VTable_5B9BCC [DERIVED] |
| 005b9c04 | ??_7?$basic_streambuf@DU?$char_traits@D@std@@@std@@6B@ | R | VTable_basic_streambuf [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | free heap-allocated buffer memory |
| 0058a5d8 | SEHHandlerInit | initialize SEH handler for exception-safe destructor |
| 00598c70 | NullCheckWithVirtualDispatch | null-check pointer then dispatch virtual call on sub-object |
| 005993af | ReferenceCountDecrementWithConditionalFree | decrement reference count, free if reaches zero |
| 00599495 | FileCloseWrapperWithStatus | close file handle |

**Guard conditions:** checks byte at this+0x48 — if non-zero, calls FileCloseWrapperWithStatus (file is open). Checks pointer at this+0x44 — if non-null, decrements refcount and frees buffer.
