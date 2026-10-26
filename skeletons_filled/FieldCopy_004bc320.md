## FieldCopy_004bc320 — FieldCopyStateToPrev

**Summary:** Copies AI driver state (offset 0x2C) to previous-state field (offset 0x24), copies float from offset 0x68 to offset 0x28, preserving current state snapshot before update.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiplayerVehiclePlacement (0042cf10), NetCommPlayerSlotSync (0045fc50), sub_462E20 (00462e20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | RW | — | previous AI driver state (receives copy of current state) |
| this | 0x28 | RW | — | previous float value (receives copy from offset 0x68) |
| this | 0x2C | R | — | current AI driver state (copied to offset 0x24) |
| this | 0x68 | R | — | current float value (copied to offset 0x28) |

**Written-by note (persistence):**
- this 0x24: overwritten each call with snapshot of offset 0x2C; external poke survives until next snapshot
- this 0x28: overwritten each call with snapshot of offset 0x68; external poke survives until next snapshot

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditionally copies both fields
