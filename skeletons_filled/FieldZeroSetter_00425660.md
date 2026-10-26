## FieldZeroSetter_00425660 — DriverStatusClear

**Summary:** Resets driver status field (this[4420] / offset 0x4510) to 0. Called from AIMainUpdate to clear AI driver state at the start of each frame tick.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIMainUpdate (00424e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4510 | RW | 0 | driverStatus [CONFIRMED] — cleared to 0 (idle/ready state) |

**Written-by note (persistence):**
- this 0x4510: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — always executes.
