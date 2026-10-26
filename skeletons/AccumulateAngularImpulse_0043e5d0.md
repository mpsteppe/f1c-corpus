## AccumulateAngularImpulse_0043e5d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleContactForceAccumulation (004ebc60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x15F0) | 0x4 | R | — | [LLM] |
| *(this+0x15F0) | 0xC | R | — | [LLM] |
| *(this+0x15F0) | 0x14 | R | — | [LLM] |
| this | 0x15F0 | R | — | [LLM] |
| this | 0x1F04 | RW | — | [LLM] |
| this | 0x1F0C | RW | — | [LLM] |
| this | 0x1F14 | RW | — | [LLM] |
| this | 0x1F1C | RW | — | [LLM] |
| this | 0x1F24 | RW | — | [LLM] |
| this | 0x1F2C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x1F04: recalc every frame — external poke does NOT persist
- this 0x1F0C: recalc every frame — external poke does NOT persist
- this 0x1F14: recalc every frame — external poke does NOT persist
- this 0x1F1C: recalc every frame — external poke does NOT persist
- this 0x1F24: recalc every frame — external poke does NOT persist
- this 0x1F2C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cbb10 | unk_7CBB10 | R | Collision_ContactBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044fee0 | CollisionImpulseAccumulator | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
