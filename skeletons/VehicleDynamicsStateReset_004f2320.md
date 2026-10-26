## VehicleDynamicsStateReset_004f2320 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AISteeringRacingLineCorrection (0042b0e0), VehicleYawRotationRecoveryController (004f1c40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | R | — | [LLM] |
| this | 0x34EC | RW | 0 | [LLM] |
| this | 0x34F0 | RW | 0 | RenderX [FACT] |
| this | 0x34F4 | RW | 0 | RenderY [FACT] |
| this | 0x34F8 | RW | 0 | RenderZ [FACT] |
| this | 0x34FC | RW | 0 | [LLM] |
| this | 0x3500 | RW | 0 | [LLM] |
| this | 0x3504 | RW | 0 | [LLM] |
| this | 0x3508 | RW | 0 | [LLM] |
| this | 0x350C | RW | 0 | [LLM] |
| this | 0x35B0 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x34EC: recalc every frame — external poke does NOT persist
- this 0x34F0: recalc every frame — external poke does NOT persist
- this 0x34F4: recalc every frame — external poke does NOT persist
- this 0x34F8: recalc every frame — external poke does NOT persist
- this 0x34FC: recalc every frame — external poke does NOT persist
- this 0x3500: recalc every frame — external poke does NOT persist
- this 0x3504: recalc every frame — external poke does NOT persist
- this 0x3508: recalc every frame — external poke does NOT persist
- this 0x350C: recalc every frame — external poke does NOT persist
- this 0x35B0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
