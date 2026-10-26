## PhysicsIntegrationStep_00441d60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsIntegrationStep (00441650)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x15F0) | 0x134 | RW | — | [LLM] |
| *(this+0x15F0) | 0x13C | RW | — | [LLM] |
| *(this+0x15F0) | 0x144 | RW | — | [LLM] |
| *(this+0x15F0) | 0x14C | RW | — | [LLM] |
| *(this+0x15F0) | 0x154 | RW | — | [LLM] |
| *(this+0x15F0) | 0x15C | RW | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0xEC | R | — | [LLM] |
| this | 0xF4 | R | — | [LLM] |
| this | 0xFC | R | — | [LLM] |
| this | 0x104 | R | — | [LLM] |
| this | 0x10C | R | — | [LLM] |
| this | 0x114 | R | — | [LLM] |
| this | 0x19C | R | — | [LLM] |
| this | 0x15AC | R | — | [LLM] |
| this | 0x15B0 | R | — | [LLM] |
| this | 0x15F0 | R | — | [LLM] |
| this | 0x1F04 | R | — | [LLM] |
| this | 0x1F0C | R | — | [LLM] |
| this | 0x1F14 | R | — | [LLM] |
| this | 0x1F1C | R | — | [LLM] |
| this | 0x1F24 | R | — | [LLM] |
| this | 0x1F2C | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x15F0) 0x134: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x13C: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x144: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x14C: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x154: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x15C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059ed50 | dbl_59ED50 | R | VelocityDampingFactor [DERIVED] (also: ` — anti-roll rate scale) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004359a0 | RigidBodyConstraintJointSolver | [LLM] |
| 00441ad0 | VelocityDampingFromSpeedError | [LLM] |
| 00441bb0 | RigidBodyTorqueAccumulation | [LLM] |
| 004423b0 | sub_4423B0 | [LLM] |
| 00442c90 | sub_442C90 | [LLM] |
| 004432f0 | DamperSpringForceComputationWithAntiRoll | [LLM] |
| 0056eb90 | sub_56EB90 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x15AC | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
