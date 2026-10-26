## StateTransition_004a56b0 — GenericModeSwitchWithReturnCode

**Summary:** Sets operation mode and flags. When a2=0, mode=1 with flags cleared. When a2≠0 and mode is not already 2, transitions to mode 2 with flags set. Returns 0 (reset), 1 (activated), or 2 (already active). Unlike ArithmeticComparison_5660, does not dispatch further.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStopDecisionTireCompound (0042a3d0), PitPartStateCopy (004a5330), CollisionSparkParticleEffects (004ec1a0), ActorMotionPostProcessingUpdate (004ed030), RepairServiceStateDispatcher (004ed250)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x128 | RW | 1 | Operation mode: 1 = inactive/reset, 2 = active |
| this | 0x12C | RW | 0 | Status flag (set to 1 when activating) |
| this | 0x130 | RW | 0 | Additional status flag (set to 1 when activating) |

**Written-by note (persistence):**
- this 0x128: recalc every frame — external poke does NOT persist
- this 0x12C: recalc every frame — external poke does NOT persist
- this 0x130: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x128 | != | 2 | Guard against redundant activation |

**Guard interpretation:** When a2 is non-zero and mode is already 2, skips the state-change block (no write to mode/flags) and returns 2. When mode is not 2, writes mode=2, flags=1 and returns 1. When a2=0, always resets mode=1, flags=0 and returns 0.