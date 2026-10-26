## CameraViewportFrustumInitialization_00424b20 — AI Camera Frustum and Viewport Reset

**Summary:** Initializes AI driver camera viewport, frustum planes, and projection parameters each frame. Resets distance tracking, near/far clip planes, viewport dimensions, and driver status flags to default sentinel values before recomputation.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4C6B60 (004c6b60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | vehicle index or track position seed (negated and multiplied by 7.0 for distance init) |
| this | 0x413C | RW | 2139095039 | projection matrix element or frustum parameter initialized to sentinel max |
| this | 0x41B4 | RW | 18446744073709551615 | per-segment frustum/layer state (loop base, set to -1 for 5 iterations) |
| this | 0x42CC | RW | 0 | per-segment distance accumulator (zeroed in 5-iteration loop via v3) |
| this | 0x43F8 | RW | 0 | frustum near-plane or state flag cleared |
| this | 0x4404 | RW | 18446744072627421184 → -1.0f | projection parameter (e.g., aspect ratio sentinel) |
| this | 0x442C | RW | 0 | driver state field zeroed |
| this | 0x4430 | RW | 0 | driver state field zeroed |
| this | 0x443C | RW | 0 | viewport or frustum parameter zeroed |
| this | 0x444C | RW | 0 | viewport dimension/offset zeroed |
| this | 0x4454 | RW | — | computed distance value = -(vehicle_idx) * 7.0 |
| this | 0x4458 | RW | 18446744073709551615 | viewport parameter sentinel (-1) |
| this | 0x4460 | RW | 18446744072627421184 → -1.0f | far-plane or depth parameter sentinel |
| this | 0x4464 | RW | 1065353216 → 1.0f | aspect ratio or scale factor |
| this | 0x446C | RW | 0 | projection matrix element zeroed |
| this | 0x4470 | RW | 0 | projection parameter zeroed |
| this | 0x4474 | RW | 1148829696 → 999.0f | near-plane distance or clip threshold |
| this | 0x4478 | RW | 0 | projection parameter zeroed |
| this | 0x4484 | RW | 1232348144 → 999999.0f | far-plane distance or max range sentinel |
| this | 0x44B0 | RW | 18446744073709551615 | frustum plane parameter sentinel (-1) |
| this | 0x4510 | RW | 0 | driverStatus [CONFIRMED] |
| this | 0x4524 | RW | 0 | viewport width or screen dimension zeroed |
| this | 0x4538 | RW | 1232348144 → 999999.0f | maxSpeed [CONFIRMED] |
| this | 0x4540 | RW | 1086324736 → 6.0f | gear ratio or speed multiplier |
| this | 0x4544 | RW | 1 | gear index or mode flag enabled |
| this | 0x4548 | RW | 0 | byte flag zeroed (shift indicator) |
| this | 0x454C | RW | 0 | callToBox [CONFIRMED] |
| this | 0x4550 | RW | 0 | state field zeroed |
| this | 0x4554 | RW | 1065353216 → 1.0f | scale factor or weight |
| this | 0x4558 | RW | 50 | speed limit or threshold constant |
| this | 0x4560 | RW | 0 | field zeroed before AI init |
| this | 0x4564 | RW | 0 | field zeroed before AI init |
| this | 0x4584 | RW | 0 | byte flag zeroed after sub_426430 |
| this | 0x45F4 | RW | 0 | ActiveFlag [FACT] |
| this | 0x461C | RW | 1232348144 → 999999.0f | max range/distance sentinel |

**Written-by note (persistence):**
- this 0x413C: recalc every frame — external poke does NOT persist
- this 0x41B4: recalc every frame — external poke does NOT persist
- this 0x42CC: recalc every frame — external poke does NOT persist
- this 0x43F8: recalc every frame — external poke does NOT persist
- this 0x4404: recalc every frame — external poke does NOT persist
- this 0x442C: recalc every frame — external poke does NOT persist
- this 0x4430: recalc every frame — external poke does NOT persist
- this 0x443C: recalc every frame — external poke does NOT persist
- this 0x444C: recalc every frame — external poke does NOT persist
- this 0x4454: recalc every frame — external poke does NOT persist
- this 0x4458: recalc every frame — external poke does NOT persist
- this 0x4460: recalc every frame — external poke does NOT persist
- this 0x4464: recalc every frame — external poke does NOT persist
- this 0x446C: recalc every frame — external poke does NOT persist
- this 0x4470: recalc every frame — external poke does NOT persist
- this 0x4474: recalc every frame — external poke does NOT persist
- this 0x4478: recalc every frame — external poke does NOT persist
- this 0x4484: recalc every frame — external poke does NOT persist
- this 0x44B0: recalc every frame — external poke does NOT persist
- this 0x4510: recalc every frame — external poke does NOT persist
- this 0x4524: recalc every frame — external poke does NOT persist
- this 0x4538: recalc every frame — external poke does NOT persist
- this 0x4540: recalc every frame — external poke does NOT persist
- this 0x4544: recalc every frame — external poke does NOT persist
- this 0x4548: recalc every frame — external poke does NOT persist
- this 0x454C: recalc every frame — external poke does NOT persist
- this 0x4550: recalc every frame — external poke does NOT persist
- this 0x4554: recalc every frame — external poke does NOT persist
- this 0x4558: recalc every frame — external poke does NOT persist
- this 0x4560: recalc every frame — external poke does NOT persist
- this 0x4564: recalc every frame — external poke does NOT persist
- this 0x4584: recalc every frame — external poke does NOT persist
- this 0x45F4: recalc every frame — external poke does NOT persist
- this 0x461C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e864 | flt_59E864 | R | ColorQuantScale [DERIVED] (also: ` — Quantization scale for color channels) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00424c80 | AIRingBufferFieldInit | initializes AI ring buffer data structure fields for inter-frame communication |
| 00424cd0 | AICommandMessageQueueDispatcher | dispatches queued AI command messages for processing |
| 00426430 | sub_426430 | post-init AI state processor (likely validates/synchronizes AI state after reset) |
| 0042ae00 | AIClearStateFlags | clears AI driving state flags to reset behavior for new frame |

**Guard conditions:** none — unconditional initialization. All fields are written every call without branching on existing values.
