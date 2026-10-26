## VehicleDataFieldCopy_004b0e30 — VehicleState_SnapshotFields

**Summary:** Copies 15 vehicle state fields (12 ints, 1 byte, 1 float, plus one float read separately) from scattered source offsets into a contiguous destination block at this+0x496C (offset 18796). Used for network sync or save-state snapshot of vehicle data.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_5StepInit (004b0720), SettingsFileInit (004b0930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x654 | R | — | source vehicle data field 0 (int) |
| this | 0x888 | R | — | source vehicle data field 1 (int) |
| this | 0x984 | R | — | source vehicle data field 2 (int) |
| this | 0xA80 | R | — | source vehicle data field 3 (int) |
| this | 0xB7C | R | — | source vehicle data field 4 (int) |
| this | 0xC78 | R | — | source vehicle data field 5 (int) |
| this | 0xD44 | R | — | source vehicle data field 6 (byte) |
| this | 0x209C | R | — | source vehicle data field 7 (int) |
| this | 0x2198 | R | — | source vehicle data field 8 (int) |
| this | 0x2294 | R | — | source vehicle data field 9 (int) |
| this | 0x2390 | R | — | source vehicle data field 10 (float, read separately via v1) |
| this | 0x248C | R | — | source vehicle data field 11 (int) |
| this | 0x2588 | R | — | source vehicle data field 12 (int) |
| this | 0x275C | R | — | source vehicle data field 13 (int) |
| this | 0x2858 | R | — | source vehicle data field 14 (int) |
| this | 0x496C | RW | — | dest snapshot field 0 (int from 0x654) |
| this | 0x4970 | RW | — | dest snapshot field 1 (int from 0x888) |
| this | 0x4974 | RW | — | dest snapshot field 2 (int from 0x984) |
| this | 0x4978 | RW | — | dest snapshot field 3 (int from 0xA80) |
| this | 0x497C | RW | — | dest snapshot field 4 (int from 0xB7C) |
| this | 0x4980 | RW | — | dest snapshot field 5 (int from 0xC78) |
| this | 0x4984 | RW | — | dest snapshot field 6 (byte from 0xD44) |
| this | 0x4988 | RW | — | dest snapshot field 7 (int from 0x209C) |
| this | 0x498C | RW | — | dest snapshot field 8 (int from 0x2198) |
| this | 0x4990 | RW | — | dest snapshot field 9 (int from 0x2294) |
| this | 0x4994 | RW | — | dest snapshot field 10 (float from 0x2390) |
| this | 0x4998 | RW | — | dest snapshot field 11 (int from 0x248C) |
| this | 0x499C | RW | — | dest snapshot field 12 (int from 0x2588) |
| this | 0x49A0 | RW | — | dest snapshot field 13 (int from 0x275C) |
| this | 0x49A4 | RW | — | dest snapshot field 14 (int from 0x2858) |

**Written-by note (persistence):**
- this 0x496C: written every call — external poke overwritten on next call
- this 0x4970: written every call — external poke overwritten on next call
- this 0x4974: written every call — external poke overwritten on next call
- this 0x4978: written every call — external poke overwritten on next call
- this 0x497C: written every call — external poke overwritten on next call
- this 0x4980: written every call — external poke overwritten on next call
- this 0x4984: written every call — external poke overwritten on next call
- this 0x4988: written every call — external poke overwritten on next call
- this 0x498C: written every call — external poke overwritten on next call
- this 0x4990: written every call — external poke overwritten on next call
- this 0x4994: written every call — external poke overwritten on next call
- this 0x4998: written every call — external poke overwritten on next call
- this 0x499C: written every call — external poke overwritten on next call
- this 0x49A0: written every call — external poke overwritten on next call
- this 0x49A4: written every call — external poke overwritten on next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** no guard — function always executes the full 15-field copy and returns 1 unconditionally.</content>
