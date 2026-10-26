## LocaleObjectAllocAndVtableSetup_00599bf0 — Locale/istream object alloc and vtable setup

**Summary:** Registers SEH handler, allocates locale/istream object with conditional vtable chain (locale vtable + basic_ios), then calls StreamCreationWithFlagInit to complete stream construction.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_579FF0 (00579ff0), EntityConstructorWrapper (0057a980), SingleFunctionCallWrapper_adf0 (0057adf0), SingleFunctionCallWrapper_ae70 (0057ae70), sub_585E50 (00585e50), SingleFunctionCallWrapper_6f10 (00586f10), SingleFunctionCallWrapper_7430 (00587430), SingleFunctionCallWrapper_76c0 (005876c0), SingleFunctionCallWrapper_7a90 (00587a90), ThunkToFUN00599958 (005997cb)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | parameter: handle/name passed to StreamCreationWithFlagInit |
| this | 0xC | R | — | parameter: mode/flags passed to StreamCreationWithFlagInit |
| this | 0x10 | R | — | boolean guard flag: 0 = skip locale vtable init, non-zero = apply locale vtable chain |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d3e6 | loc_59D3E6 | R | address of exception handler code registered by SEHHandlerInit |
| 005b9c40 | ??_7?$basic_istream@GU?$char_traits@G@std@@@std@@6B@ | R | IStreamWVTable [DERIVED] |
| 005b9c50 | ??_7?$basic_ios@GU?$char_traits@G@std@@@std@@6B@ | R | VTable_basic_ios [DERIVED] |
| 005b9c5c | unk_5B9C5C | R | LocaleVTablePtr [DERIVED] (also: ` — locale vtable pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | registers SEH exception handler for frame |
| 0059a3a9 | StreamCreationWithFlagInit | creates/opens stream with parameters |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | == | 0 | boolean guard flag for locale vtable chain init |

**Guard interpretation:** If offset 0x10 is non-zero, locale vtable (unk_5B9C5C → basic_ios) and frame flags are applied. If zero, vtable init block is skipped. StreamCreationWithFlagInit is always called regardless of guard.
