## sub_4BB8E0_004bb8e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4C6B60 (004c6b60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x18 | RW | 18446744072627421184 → -1.0f | [LLM] |
| this | 0x1C | RW | 18446744072627421184 → -1.0f | [LLM] |
| this | 0x20 | RW | 18446744072627421184 → -1.0f | [LLM] |
| this | 0x60 | RW | 1 | [LLM] |
| this | 0xA8 | RW | 0 | [LLM] |
| this | 0xAC | RW | 0 | [LLM] |
| this | 0xB0 | RW | 0 | [LLM] |
| this | 0xB4 | RW | 0 | [LLM] |
| this | 0xD0 | RW | 0 | [LLM] |
| this | 0xD4 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x18: recalc every frame — external poke does NOT persist
- this 0x1C: recalc every frame — external poke does NOT persist
- this 0x20: recalc every frame — external poke does NOT persist
- this 0x60: recalc every frame — external poke does NOT persist
- this 0xA8: recalc every frame — external poke does NOT persist
- this 0xAC: recalc every frame — external poke does NOT persist
- this 0xB0: recalc every frame — external poke does NOT persist
- this 0xB4: recalc every frame — external poke does NOT persist
- this 0xD0: recalc every frame — external poke does NOT persist
- this 0xD4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e9ca0 | AIRacingLinePathFollowing | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x60 | == | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
