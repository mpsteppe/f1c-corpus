## MultiPhaseProcessingStateMachine_00404460 — VehicleWheelPhaseProcessor

**Summary:** Three-phase state machine for processing vehicle wheel updates across multiple frames (time-sliced). Phase 0 runs friction callbacks (sub_4FB260), phase 1 runs suspension callbacks (sub_4FAF60), phase 2 runs proximity queries (VehicleProximity). Each phase processes a batch of up to 20 wheels per call, advancing the phase index (this+0x170) and transitioning phases when all wheels are done.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GamePostMainLoop (0042d8a0), StateTriggerCheck (004b8ae0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x130 | R | — | wheel count |
| this | 0x134 | R | — | wheel array pointer |
| this | 0x16C | RW | 1 | processing step size (batch size) |
| this | 0x170 | RW | — | current wheel index within phase (advances per call) |
| this | 0x174 | RW | 0 | phase selector: 0=friction, 1=suspension, 2=proximity |

**Written-by note (persistence):**
- this 0x16C: set once to 1 — persists across frames
- this 0x170: updated each frame (time-sliced index) — persists across frames
- this 0x174: updated on phase transitions — persists across frames

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e480 | dbl_59E480 | R | PhysicsTolerance [DERIVED] (also: ` — multiplier/tolerance) |
| 008afee8 | flt_8AFEE8 | R | TrackGripBase [DERIVED] |
| 008afeec | flt_8AFEEC | R | TrackGripComparison [DERIVED] (also: ` — additive globals) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004faf60 | sub_4FAF60 | per-wheel suspension callback (phase 1) |
| 004fb260 | sub_4FB260 | per-wheel friction callback (phase 0) |
| 004fb2e0 | VehicleProximity | wheel-to-wheel proximity detection (phase 2) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x174 | != | 18446744073709551615 | phase state != -1 (inactive) — processing active |
| this | 0x174 | == | 18446744073709551615 | phase state == -1 (inactive/idle) — skip all processing |

**Guard interpretation:** If grip scale factor changed by more than 0.05 tolerance OR phase is not -1 (processing active), enters state machine. Phase transitions: 0→1→2→reset to -1 (done). Each call processes min(phase_index+20, max_count) wheels. PASSES: batch of wheels processed, phase advanced. BLOCKED: if fabs(grip_change) <= 0.05 AND phase == -1, does nothing (no update needed).
