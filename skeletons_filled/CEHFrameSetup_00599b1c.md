## CEHFrameSetup_00599b1c — CEH frame setup with conditional stream init

**Summary:** Registers SEH handler for C++ exception handling, conditionally initializes a stream object's vtable chain (basic_ostream/basic_ios) and optionally calls StreamCreationWithFlagInit to open a stream if the flag at offset 0x10 is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_579FF0 (00579ff0), EntityConstructorWrapper (0057a980), SingleFunctionCallWrapper_adf0 (0057adf0), SingleFunctionCallWrapper_ae70 (0057ae70), sub_585E50 (00585e50), SingleFunctionCallWrapper_6f10 (00586f10), SingleFunctionCallWrapper_7430 (00587430), SingleFunctionCallWrapper_76c0 (005876c0), SingleFunctionCallWrapper_7a90 (00587a90), ThunkToFUN00599958 (005997cb)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | parameter: handle/name passed to stream creation |
| this | 0xC | R | — | parameter: mode/flags passed to stream creation |
| this | 0x10 | R | — | boolean guard flag: 0 = skip stream creation, non-zero = call StreamCreationWithFlagInit |
| this | 0x14 | R | — | boolean guard flag: 0 = skip object vtable init, non-zero = apply vtable chain |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d39e | loc_59D39E | R | address of exception handler code registered by SEHHandlerInit |
| 005b9c48 | ??_7?$basic_ostream@GU?$char_traits@G@std@@@std@@6B@ | R | VTable_basic_ostream_wchar [DERIVED] |
| 005b9c50 | ??_7?$basic_ios@GU?$char_traits@G@std@@@std@@6B@ | R | VTable_basic_ios [DERIVED] |
| 005b9c54 | unk_5B9C54 | R | CppStreamObject_5B9C54 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | registers SEH exception handler for frame |
| 0059a3a9 | StreamCreationWithFlagInit | creates/opens stream with flag parameter |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | == | 0 | boolean flag to trigger stream creation |
| this | 0x14 | == | 0 | boolean flag to trigger vtable init block |

**Guard interpretation:** Both guards suppress their respective init blocks when zero. If offset 0x14 is non-zero, object receives vtables (basic_ostream_wchar, basic_ios) and flag at frame-0x10 is set to 1. If offset 0x10 is non-zero, StreamCreationWithFlagInit is called with params from offsets 0x8 and 0xC. If either is zero, the corresponding block is skipped.
