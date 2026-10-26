## WheelCollisionContactFlagSetter_0043e770 — WheelContactCollisionFlagUpdater

**Summary:** Sets collision contact flags on collision data entries based on wheel contact state. When a wheel has contact (v2 != 0), marks the matching body-pair contact as collided; otherwise marks wheel-body contacts with contact flags. Part of vehicle collision system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** RepairServiceStateDispatcher (004ed250)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x141C | R | — | wheel index array base (281 * wheel_index + 251) |
| this | 0x15B4 | R | — | wheel contact state (non-zero = wheel in contact) |
| this | 0x15B8 | R | — | wheel contact body ID (first, used in both paths) |
| this | 0x15BC | R | — | contact count for body-pair array |
| this | 0x15C0 | R | — | pointer to body-pair contact data array (72-byte stride) |
| this | 0x15C4 | R | — | contact count for wheel-body array |
| this | 0x15C8 | R | — | pointer to wheel-body contact data array (48-byte stride) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x15B4 | > | 0 | wheel contact state — non-zero means wheel has ground contact |

**Guard interpretation:** If wheel contact state (this+0x15B4) > 0 (wheel has contact), set contact flags on body-pair entries + mark wheel contact flag. If == 0 (no wheel contact), scan wheel-body contact entries matching body IDs and set wheel contact flag (bit 0 at +0x2C) on matching entries.
