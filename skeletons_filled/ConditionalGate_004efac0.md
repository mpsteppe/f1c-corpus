## ConditionalGate_004efac0 — ConditionalGate

**Summary:** Conditional gate that resets a per-instance field or a global flag based on rigid body constraint. Part of vehicle state management system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIMainUpdate (00424e70), AIAbility (00429470), PitStopDecisionTireCompound (0042a3d0), AIStateReset (0042af40), AISteeringRacingLineCorrection (0042b0e0), sub_4A0250 (004a0250)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | R | — | Rigid body constraint pointer (branch selector) |
| this | 0x3994 | RW | 0 | Field reset to 0 when rigid body is valid |

**Written-by note (persistence):**
- this 0x3994: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks rigid body ptr (this+0x32BC). If nonzero (PASSES with rigid body): sets this+0x3994 = 0. If zero (no rigid body): sets global byte_7C9081 = 0. Returns ptr value as result.
