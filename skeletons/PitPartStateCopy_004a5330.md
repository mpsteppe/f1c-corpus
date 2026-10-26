## PitPartStateCopy_004a5330 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SuspensionAndWheelPhysics (004e5f60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x6C | RW | — | [LLM] |
| this | 0x75 | RW | 0 | [LLM] |
| this | 0xA8 | R | — | [LLM] |
| this | 0xAC | RW | 1 | [LLM] |
| this | 0xEC | R | — | [LLM] |
| this | 0xF0 | RW | — | [LLM] |
| this | 0xF5 | RW | 0 | [LLM] |
| this | 0x158 | RW | — | [LLM] |
| this | 0x15C | RW | — | [LLM] |
| this | 0x160 | RW | — | [LLM] |
| this | 0x164 | RW | 1024 | [LLM] |
| this | 0x168 | RW | — | [LLM] |
| this | 0x16C | RW | 2048 | [LLM] |
| this | 0x170 | RW | — | [LLM] |
| this | 0x174 | RW | 3072 | [LLM] |
| this | 0x178 | RW | — | [LLM] |
| this | 0x17C | RW | — | [LLM] |
| this | 0x184 | RW | 0 | [LLM] |
| this | 0x188 | RW | 0 | [LLM] |
| this | 0x18C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x6C: recalc every frame — external poke does NOT persist
- this 0x75: recalc every frame — external poke does NOT persist
- this 0xAC: recalc every frame — external poke does NOT persist
- this 0xF0: recalc every frame — external poke does NOT persist
- this 0xF5: recalc every frame — external poke does NOT persist
- this 0x158: recalc every frame — external poke does NOT persist
- this 0x15C: recalc every frame — external poke does NOT persist
- this 0x160: recalc every frame — external poke does NOT persist
- this 0x164: recalc every frame — external poke does NOT persist
- this 0x168: recalc every frame — external poke does NOT persist
- this 0x16C: recalc every frame — external poke does NOT persist
- this 0x170: recalc every frame — external poke does NOT persist
- this 0x174: recalc every frame — external poke does NOT persist
- this 0x178: recalc every frame — external poke does NOT persist
- this 0x17C: recalc every frame — external poke does NOT persist
- this 0x184: recalc every frame — external poke does NOT persist
- this 0x188: recalc every frame — external poke does NOT persist
- this 0x18C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007d0374 | dword_7D0374 | R | ScoringSessionValue [DERIVED] |
| 008ad254 | dword_8AD254 | R | StateFlagPair [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a3440 | FlagBasedLoopConditionalCall | [LLM] |
| 004a5600 | PitstopStateTransition | [LLM] |
| 004a5660 | ArithmeticComparison_5660 | [LLM] |
| 004a56b0 | StateTransition | [LLM] |
| 004a57f0 | FindZeroResultIndex | [LLM] |
| 004a5820 | NthValidPartLookup | [LLM] |
| 004d7570 | CompoundIndexLookup | [LLM] |
| 004d7880 | TireBrandLookup | [LLM] |
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
