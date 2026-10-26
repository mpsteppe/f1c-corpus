## WheelDataCopy_004414d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsIntegrationStep (00441650)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x340 | RW | — | [LLM] |
| this | 0x344 | RW | — | [LLM] |
| this | 0x348 | R | — | [LLM] |
| this | 0x34C | R | — | [LLM] |
| this | 0x350 | RW | — | [LLM] |
| this | 0x354 | RW | — | [LLM] |
| this | 0x15AC | R | — | [LLM] |
| this | 0x15B0 | R | — | [LLM] |
| this | 0x162C | R | — | [LLM] |
| this | 0x1C5C | R | — | [LLM] |
| this | 0x1C60 | R | — | [LLM] |
| this | 0x1C64 | RW | — | [LLM] |
| this | 0x1C68 | RW | — | [LLM] |
| this | 0x1E38 | R | — | [LLM] |
| this | 0x1E3C | R | — | [LLM] |
| this | 0x1E40 | RW | — | [LLM] |
| this | 0x1E44 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x340: recalc every frame — external poke does NOT persist
- this 0x344: recalc every frame — external poke does NOT persist
- this 0x350: recalc every frame — external poke does NOT persist
- this 0x354: recalc every frame — external poke does NOT persist
- this 0x1C64: recalc every frame — external poke does NOT persist
- this 0x1C68: recalc every frame — external poke does NOT persist
- this 0x1E40: recalc every frame — external poke does NOT persist
- this 0x1E44: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0043f7f0 | SuspensionWheelDynamicsSolver | [LLM] |
| 00441450 | PhysicsSubObjectFree | [LLM] |
| 0056ecf0 | sub_56ECF0 | [LLM] |
| 0056ee40 | sub_56EE40 | [LLM] |
| 0056f020 | IteratePhysicsBodiesCallUpdateFunction | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x15AC | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
