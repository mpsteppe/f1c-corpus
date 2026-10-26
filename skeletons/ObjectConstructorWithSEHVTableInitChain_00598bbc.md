## ObjectConstructorWithSEHVTableInitChain_00598bbc — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_579FB0 (00579fb0), ThunkToFUN00598815 (0057a940), sub_57ADB0 (0057adb0), sub_57AE30 (0057ae30), SingleFunctionCallWrapper_5e10 (00585e10), ThunkToFUN00598815_6ed0 (00586ed0), CallWrapper_73f0 (005873f0), sub_587680 (00587680), ThunkToFUN00598815_7a50 (00587a50), SingleFunctionCallWrapper_97a1 (005997a1)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d2d2 | loc_59D2D2 | R | [LLM] |
| 005b9bcc | off_5B9BCC | R | VTable_5B9BCC [DERIVED] |
| 005b9c04 | ??_7?$basic_streambuf@DU?$char_traits@D@std@@@std@@6B@ | R | VTable_basic_streambuf [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | [LLM] |
| 00598c1c | LocaleRefcountAcquireUnderLock | [LLM] |
| 005994bc | ObjectInitializationWithBufferBoundsSetup | [LLM] |
| 0059a4c9 | SelfReferentialPointerRingInit | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
