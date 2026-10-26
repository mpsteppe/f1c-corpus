## WheelControllerInputDecoder_00410bc0 — WheelInputDataUnpackDispatcher

**Summary:** Decodes packed wheel input data from a 36-byte input buffer into 13 scaled float values, then dispatches to the appropriate wheel group (6 groups total based on a 6-bit type field). Within each group, validates wheel index bounds, checks sentinel (-1) to optionally initialize via ShortComputation_e770, calls RepairServiceStateDispatcher with subgroup ID, and converts physics state vector via PhysicsStateVectorConversion. References VEH global arrays for repair state lookups.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B3400 (004b3400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | batch 1 count (max wheel index for group 0) |
| this | 0x28 | R | — | batch 1 base pointer (group 0 wheel array base) |
| this | 0x30 | R | — | batch 2 count (group 1 max index) |
| this | 0x34 | R | — | batch 2 base pointer (group 1 wheel array base) |
| this | 0x3C | R | — | batch 3 count (group 2 max index) |
| this | 0x40 | R | — | batch 3 base pointer (group 2 wheel array base) |
| this | 0x48 | R | — | batch 4 count (group 3 max index, min start 416) |
| this | 0x4C | R | — | batch 4 base pointer (group 3 wheel array base) |
| this | 0x54 | R | — | batch 5 count (group 4 max index, min start 208) |
| this | 0x58 | R | — | batch 5 base pointer (group 4 wheel array base) |
| this | 0x60 | R | — | batch 6 count (group 5 max index, min start 832) |
| this | 0x64 | R | — | batch 6 base pointer (group 5 wheel array base) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00410f44 | jpt_410D15 | R | jump table for switch on 6-bit type field (0-5) |
| 0059e774 | flt_59E774 | R | ShortToFloatScale [DERIVED] — position/short-to-float scale factor (0.000030517578) |
| 0059e778 | flt_59E778 | R | AngleToRadians [DERIVED] — spread/angle scale factor 2 (0.00048828125) |
| 0059e77c | flt_59E77C | R | ShortVertexScale [DERIVED] — third scale group factor (0.015625) |
| 0059e780 | flt_59E780 | R | VertexScaleFactor [DERIVED] — fourth scale group factor (0.0078125) |
| 005ec6e4 | unk_5EC6E4 | R | VEH[0].0xC — unknown VEH field accessed in wheel group processing |
| 005ecf0c | dword_5ECF0C | R | VEH[0].0x834 — repair state lookup for wheel group 3 (indexed by 4656*dword stride) |
| 005ed3ac | dword_5ED3AC | R | VEH[0].0xCD4 — repair state lookup for wheel group 4 even sub-index |
| 005ed3f0 | dword_5ED3F0 | R | VEH[0].0xD18 — repair state lookup for wheel group 4 odd sub-index |
| 005ed434 | dword_5ED434 | R | VEH[0].0xD5C — repair state lookup for wheel group 5 (indexed by 17*subgroup stride) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040e770 | ShortComputation_e770 | initializes wheel object when sentinel (-1) detected |
| 0040ef70 | PhysicsStateVectorConversion | converts decoded float array v37 into physics state for the wheel |
| 004ed250 | RepairServiceStateDispatcher | dispatches repair service state for the wheel's subgroup |

**Guard conditions:** wheel index v15 bounds-checked against per-group count; sentinel check *wheelObj == -1 triggers ShortComputation_e770 init. If sentinel and no repair state (result == 0) → early return without processing. Positive index range validated before any access.
