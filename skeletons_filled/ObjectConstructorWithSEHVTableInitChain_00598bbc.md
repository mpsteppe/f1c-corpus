## ObjectConstructorWithSEHVTableInitChain_00598bbc — StreambufObjectConstructChain

**Summary:** Constructs a streambuf-derived object with multi-phase vtable initialization. Acquires locale references for two sub-objects, sets up self-referential buffer pointers, and transitions vtable through multiple states (streambuf → off_5B9BCC). Part of C++ standard library streambuf construction with locale management.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_579FB0 (00579fb0), ThunkToFUN00598815 (0057a940), sub_57ADB0 (0057adb0), sub_57AE30 (0057ae30), SingleFunctionCallWrapper_5e10 (00585e10), ThunkToFUN00598815_6ed0 (00586ed0), CallWrapper_73f0 (005873f0), sub_587680 (00587680), ThunkToFUN00598815_7a50 (00587a50), SingleFunctionCallWrapper_97a1 (005997a1)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | argument passed to ObjectInitializationWithBufferBoundsSetup |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d2d2 | loc_59D2D2 | R | exception handling type descriptor |
| 005b9bcc | off_5B9BCC | R | VTable_5B9BCC [DERIVED] |
| 005b9c04 | ??_7?$basic_streambuf@DU?$char_traits@D@std@@@std@@6B@ | R | VTable_basic_streambuf [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | initialize SEH handler registration for this constructor |
| 00598c1c | LocaleRefcountAcquireUnderLock | acquire reference on locale-related object with lock |
| 005994bc | ObjectInitializationWithBufferBoundsSetup | set up buffer bounds and pointers after vtable init |
| 0059a4c9 | SelfReferentialPointerRingInit | initialize self-referential buffer pointer ring |

**Guard conditions:** None unconditional — all initialization steps execute in order.
