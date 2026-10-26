## VehicleActive_00447160 — VehicleActiveStateCheck

**Summary:** Returns boolean indicating whether the vehicle is in an active state. Checks multiple conditions: threshold values > 0, active flag set, optional override flag, and secondary state byte. Part of vehicle state management.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_42C440 (0042c440), Gearbox (00443b70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1F00) | 0x344C | R | — | secondary state enable byte |
| this | 0x19C | R | — | threshold value (must be > 0.0) |
| this | 0x1C59 | R | — | active flag byte (must be non-zero) |
| this | 0x1D0C | R | — | override flag byte (if set, returns true immediately) |
| this | 0x1DB4 | R | — | threshold value (must be > 0.0) |
| this | 0x1F00 | R | — | pointer to secondary state struct |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** three sequential checks — if any of (this+0x1DB4 <= 0.0) OR (this+0x19C <= 0.0) OR (this+0x1C59 byte == 0), return false (vehicle inactive). Then if override flag (this+0x1D0C) is non-zero, return true immediately. Otherwise return depends on secondary state byte at *(this+0x1F00)+0x344C.
