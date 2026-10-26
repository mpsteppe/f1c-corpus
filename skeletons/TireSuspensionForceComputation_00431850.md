## TireSuspensionForceComputation_00431850 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_475A90 (00475a90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xBC4 | R | — | [LLM] |
| this | 0x1570 | R | — | [LLM] |
| this | 0x1578 | R | — | [LLM] |
| this | 0x1584 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059ea70 | dbl_59EA70 | R | SuspForceConst [DERIVED] |
| 008ad254 | dword_8AD254 | R | StateFlagPair [DERIVED] |
| 008adb88 | unk_8ADB88 | R | TireDatasetHandle [DERIVED] |
| 008aeec0 | dword_8AEEC0 | R | AeroSuspensionModeSelector [DERIVED] (also: ` — aero/suspension mode selector (0=fixed, 1=blended, 2=fixed-alt) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ed00 | SessionStateIndexedLookup | [LLM] |
| 004d7570 | CompoundIndexLookup | [LLM] |
| 004d7880 | TireBrandLookup | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
