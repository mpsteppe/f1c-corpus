## DriverNameTeamCopy_004b51e0 — DriverNameTeamPathCopy

**Summary:** Copies driver/team name string (63 bytes) and two file path strings (31 bytes each) from source struct a2 into this, extracting filename portions after last backslash. Copies a flag byte from a2+18580 to this[0]. Called from VehicleInstanceListBuilder during vehicle instance setup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleInstanceListBuilder (004b5c50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Flag byte copied from a2+18580 (driver/team flag) |
| this | 0x40 | RW | 0 | Null terminator after 63-byte name string (this[0x40]=0) |
| this | 0x60 | RW | 0 | Null terminator after first 31-byte path string (this[0x60]=0) |
| this | 0x80 | RW | 0 | Null terminator after second 31-byte path string (this[0x80]=0) |

**Written-by note (persistence):**
- this 0x0: written once — flag byte from source
- this 0x40, 0x60, 0x80: written once — null terminators

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Default application directory path (fallback for null path pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b4f70 | StructInitWithGlobalData | Initialize struct with zeroed fields and sentinel values |
| 00587dd0 | sub_587DD0 | Copy string with length-limited buffer (strncpy equivalent) |

**Guard conditions:**
1. For first path extraction: if string at a2+18196 is empty (start > end), skip backslash search; v3 stays at start.
2. For second path extraction: if string pointer at a2+1920 is null, use byte_5EA438 (default directory). If string is empty (v5 <= v4), skip backslash search.
