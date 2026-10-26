## LocaleObjectConstructorWithVTableSetup_00599cb7 — Locale streambuf constructor with refcount and buffer init

**Summary:** Registers SEH handler, acquires reference counts on two locale facets (at offsets 0x34 and 0x4C), initializes self-referential pointer ring, sets up vtable chain (basic_streambuf → custom vtable off_5B9C68), and assigns buffer data pointer via ObjectInitWithBufferDataPointerAssignment.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_579FF0 (00579ff0), EntityConstructorWrapper (0057a980), SingleFunctionCallWrapper_adf0 (0057adf0), SingleFunctionCallWrapper_ae70 (0057ae70), sub_585E50 (00585e50), SingleFunctionCallWrapper_6f10 (00586f10), SingleFunctionCallWrapper_7430 (00587430), SingleFunctionCallWrapper_76c0 (005876c0), SingleFunctionCallWrapper_7a90 (00587a90), ThunkToFUN00599958 (005997cb)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | parameter: buffer handle/pointer passed to ObjectInitWithBufferDataPointerAssignment |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d432 | loc_59D432 | R | address of exception handler code registered by SEHHandlerInit |
| 005b9c68 | off_5B9C68 | R | PTR_VTABLE_5B9C68 [DERIVED] |
| 005b9ca0 | ??_7?$basic_streambuf@GU?$char_traits@G@std@@@std@@6B@ | R | VTable_5B9CA0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | registers SEH exception handler for frame |
| 00598c1c | LocaleRefcountAcquireUnderLock | acquires reference count on locale facet under lock |
| 0059a473 | ObjectInitWithBufferDataPointerAssignment | initializes object with buffer data pointer |
| 0059a4c9 | SelfReferentialPointerRingInit | initializes self-referential pointer ring within object |

**Guard conditions:** None — all operations unconditional (under SEH protection).
