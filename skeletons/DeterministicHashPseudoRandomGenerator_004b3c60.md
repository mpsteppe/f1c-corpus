## DeterministicHashPseudoRandomGenerator_004b3c60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** RandomNoiseValueGenerator (004b3ce0), AIDriverCountSetup (004bfd90), sub_4CB120 (004cb120), TelemetryDataDump (004d4a80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x804 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x804: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0d4 | __imp_GetTickCount | R | [LLM] |
| 005accf4 | flt_5ACCF4 | R | RandomSeedMult [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0055687b | RDTSCTimestampRead | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 005884ed | RandLCGRandomNumberGenerator | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
