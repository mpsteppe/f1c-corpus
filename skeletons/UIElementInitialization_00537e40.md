## UIElementInitialization_00537e40 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ConditionalMultiFieldReset (00535e10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB0E | RW | — | [LLM] |
| this | 0xB16 | RW | — | [LLM] |
| this | 0xB1A | RW | — | [LLM] |
| this | 0xB22 | RW | — | [LLM] |
| this | 0xB26 | RW | — | [LLM] |
| this | 0xB2E | RW | — | [LLM] |
| this | 0x16A7 | RW | 8 | [LLM] |
| this | 0x16AB | RW | 0 | [LLM] |
| this | 0x16AD | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0xB0E: recalc every frame — external poke does NOT persist
- this 0xB16: recalc every frame — external poke does NOT persist
- this 0xB1A: recalc every frame — external poke does NOT persist
- this 0xB22: recalc every frame — external poke does NOT persist
- this 0xB26: recalc every frame — external poke does NOT persist
- this 0xB2E: recalc every frame — external poke does NOT persist
- this 0x16A7: recalc every frame — external poke does NOT persist
- this 0x16AB: recalc every frame — external poke does NOT persist
- this 0x16AD: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005da928 | off_5DA928 | R | VTable_AudioClass [DERIVED] |
| 005da93c | off_5DA93C | R | PtrTable_5DA93C [DERIVED] |
| 005da950 | unk_5DA950 | R | D3D_Shader_StatePtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00537eb0 | EmptyStub_7eb0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
