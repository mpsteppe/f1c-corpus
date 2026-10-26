## RigidBodyTorqueAccumulation_00441bb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsIntegrationStep (00441d60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x15F0) | 0x4 | R | — | [LLM] |
| *(this+0x15F0) | 0xC | R | — | [LLM] |
| *(this+0x15F0) | 0x14 | R | — | [LLM] |
| *(this+0x15F0) | 0x64 | R | — | [LLM] |
| *(this+0x15F0) | 0x6C | R | — | [LLM] |
| *(this+0x15F0) | 0x74 | R | — | [LLM] |
| *(this+0x15F0) | 0x7C | R | — | [LLM] |
| *(this+0x15F0) | 0x84 | R | — | [LLM] |
| *(this+0x15F0) | 0x8C | R | — | [LLM] |
| *(this+0x1D4) | 0x4 | R | — | [LLM] |
| *(this+0x1D4) | 0xC | R | — | [LLM] |
| *(this+0x1D4) | 0x14 | R | — | [LLM] |
| *(this+0x1D4) | 0x64 | R | — | [LLM] |
| *(this+0x1D4) | 0x6C | R | — | [LLM] |
| *(this+0x1D4) | 0x74 | R | — | [LLM] |
| *(this+0x1D4) | 0xAC | R | — | [LLM] |
| *(this+0x1D4) | 0x134 | RW | — | [LLM] |
| *(this+0x1D4) | 0x13C | RW | — | [LLM] |
| *(this+0x1D4) | 0x144 | RW | — | [LLM] |
| this | 0x1D4 | R | — | [LLM] |
| this | 0x1D8 | R | — | [LLM] |
| this | 0x1E0 | R | — | [LLM] |
| this | 0x15F0 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x1D4) 0x134: recalc every frame — external poke does NOT persist
- *(this+0x1D4) 0x13C: recalc every frame — external poke does NOT persist
- *(this+0x1D4) 0x144: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00435e00 | Matrix3x3VectorMultiply | [LLM] |
| 00569b70 | F_3DVectorSubtractWithCrossProduct | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
