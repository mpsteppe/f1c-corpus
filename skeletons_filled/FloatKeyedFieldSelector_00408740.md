## FloatKeyedFieldSelector_00408740 — FloatKeyedFieldSelector

**Summary:** Switch-based field selector using float-as-integer key (LODWORD); selects from 9 struct fields, applies degrees-to-radians conversion and trig computation. Part of camera/view vector processing system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ViewCameraModeDispatch (00409440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Enable flag (this[1]), must be non-zero for processing |
| this | 0x10 | R | — | Field selected by case 0 |
| this | 0x14 | R | — | Field selected by case 1 |
| this | 0x18 | R | — | Field selected by case 2 |
| this | 0x1C | R | — | Field selected by case 3 |
| this | 0x20 | R | — | Field selected by case 4 (base value) |
| this | 0x24 | R | — | Field selected by case 5 |
| this | 0x28 | R | — | Field selected by case 6 |
| this | 0x2C | R | — | Field selected by case 7 |
| this | 0x30 | R | — | Field selected by case 8 |
| this | 0x34 | RW | — | Stores input key (a2) after successful processing |
| this | 0x3C | R | — | Multiplier for case 4 (added as 200 * this[15]) |

**Written-by note (persistence):**
- this 0x34: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004087dc | jpt_408752 | R | Jump table for the 9-case switch dispatch |
| 0059e65c | flt_59E65C | R | CameraShakeMultiplier [DERIVED] (also: ` — camera shake multiplier / conversion factor (docs/09, 19) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00456060 | DualFieldGetter | Extracts two float fields from input (vector components for processing) |
| 00542050 | sub_542050 | Trigonometry/computation function using degrees-to-radians converted values |

**Guard conditions:** Selected field (v4) must be non-zero AND this[1] must be non-zero → processing proceeds. Otherwise → skip/return.
