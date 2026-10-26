## WheelDynamicsInit_0043e230 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** DynMan_Post (0042c9f0), DynamicsObjectInitialization (00438c10), PhysicsInitSequence (00438ca0), sub_4E4790 (004e4790)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5D8 | RW | 18446744071819766006 | [LLM] |
| this | 0x5DC | RW | 1081507266 → 3.8514f | [LLM] |
| this | 0x5E0 | RW | — | [LLM] |
| this | 0x5E4 | RW | — | [LLM] |
| this | 0x5E8 | RW | — | [LLM] |
| this | 0x5EC | RW | — | [LLM] |
| this | 0x6B8 | R | — | [LLM] |
| this | 0x162C | R | — | [LLM] |
| this | 0x1CFC | R | — | [LLM] |
| this | 0x1D4C | R | — | [LLM] |
| this | 0x1F00 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x5D8: recalc every frame — external poke does NOT persist
- this 0x5DC: recalc every frame — external poke does NOT persist
- this 0x5E0: recalc every frame — external poke does NOT persist
- this 0x5E4: recalc every frame — external poke does NOT persist
- this 0x5E8: recalc every frame — external poke does NOT persist
- this 0x5EC: recalc every frame — external poke does NOT persist
- this 0x1F00: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56c0 | byte_7C56C0 | R | SessionNameBuffer [DERIVED] (also: file loader flag (save/restore around file operations, docs/08) |
| 008ad238 | dword_8AD238 | R | ScoringGateOpen [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00431930 | SetContactConstraint | [LLM] |
| 004319c0 | ParameterArraySetterWithDirtyFlag | [LLM] |
| 00431a50 | SimpleSetterWithFlag | [LLM] |
| 00431a70 | PhysicsGridValueSet | [LLM] |
| 004358f0 | PhysicsBufferClear | [LLM] |
| 004d5840 | ResourceDestroy | [LLM] |
| 0056e970 | sub_56E970 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
