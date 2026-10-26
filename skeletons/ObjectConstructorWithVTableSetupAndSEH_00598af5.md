## ObjectConstructorWithVTableSetupAndSEH_00598af5 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_579FB0 (00579fb0), ThunkToFUN00598815 (0057a940), sub_57ADB0 (0057adb0), sub_57AE30 (0057ae30), SingleFunctionCallWrapper_5e10 (00585e10), ThunkToFUN00598815_6ed0 (00586ed0), CallWrapper_73f0 (005873f0), sub_587680 (00587680), ThunkToFUN00598815_7a50 (00587a50), SingleFunctionCallWrapper_97a1 (005997a1)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d286 | loc_59D286 | R | [LLM] |
| 005b9ba4 | ??_7?$basic_istream@DU?$char_traits@D@std@@@std@@6B@ | R | IStreamVtablePtr [DERIVED] |
| 005b9bb4 | ??_7?$basic_ios@DU?$char_traits@D@std@@@std@@6B@ | R | IosVtable [DERIVED] |
| 005b9bc0 | unk_5B9BC0 | R | PrimaryVTablePtr [DERIVED] (also: primary vtable pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | [LLM] |
| 005993eb | ObjectInitWithVTableFlagSet | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
