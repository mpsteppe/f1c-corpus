## VelocityDampingFromSpeedError_00441ad0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsIntegrationStep (00441d60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x15F0) | 0x2C | R | — | [LLM] |
| *(this+0x15F0) | 0x44 | R | — | [LLM] |
| *(this+0x15F0) | 0x5C | R | — | [LLM] |
| *(this+0x15F0) | 0x64 | R | — | [LLM] |
| *(this+0x15F0) | 0x6C | R | — | [LLM] |
| *(this+0x15F0) | 0x74 | R | — | [LLM] |
| *(this+0x15F0) | 0x134 | RW | — | [LLM] |
| *(this+0x15F0) | 0x13C | RW | — | [LLM] |
| *(this+0x15F0) | 0x144 | RW | — | [LLM] |
| *(this+0x1F00) | 0x344C | R | — | [LLM] |
| *(this+0x1F00) | 0x3450 | R | — | [LLM] |
| this | 0x48 | R | — | [LLM] |
| this | 0x15F0 | R | — | [LLM] |
| this | 0x1EF0 | R | — | [LLM] |
| this | 0x1F00 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x15F0) 0x134: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x13C: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x144: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059ed40 | dbl_59ED40 | R | SpeedErrorGain [DERIVED] |
| 0059ed48 | dbl_59ED48 | R | RefSpeed_Aero [DERIVED] (also: ` — reference speed (double) |
| 007ce838 | byte_7CE838 | R | DampingEnableFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x1F00) | 0x3450 | != | 3 | [LLM] |
| this | 0x1EF0 | != | 18446744073709551615 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
