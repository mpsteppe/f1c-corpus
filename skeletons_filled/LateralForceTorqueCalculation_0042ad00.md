## LateralForceTorqueCalculation_0042ad00 — LateralTorqueFromForce

**Summary:** Computes lateral torque from input force value: multiplies input by lateral force coefficient and 0.01 scaling factor. Part of vehicle physics torque model.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_424080 (00424080), AIDriverRandomSelector (0042ae20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x44F4 | R | — | lateralForceCoefficient |
| this | 0x453C | RW | — | lateralTorqueOutput |

**Written-by note (persistence):**
- this 0x453C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always computes product unconditionally.
