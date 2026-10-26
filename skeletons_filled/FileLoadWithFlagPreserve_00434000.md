## FileLoadWithFlagPreserve_00434000 — FileLoadWithFlagPreserve

**Summary:** Saves the SessionNameBuffer flag, loads a vehicle setup file via VehicleSetupFileWriter, then restores the flag. Preserves global state around the file load.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A00A0 (004a00a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | path string pointer for the vehicle setup file to load |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | default application directory path (fallback if this[0] is null) |
| 007c56c0 | byte_7C56C0 | RW | SessionNameBuffer — flag preserved across VehicleSetupFileWriter call |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042fd00 | VehicleSetupFileWriter | write/load vehicle setup file with flag parameter |

**Guard conditions:** If `*this` (path string) is null, falls back to `&byte_5EA438` (default directory). Always preserves byte_7C56C0 by saving before and restoring after VehicleSetupFileWriter.
