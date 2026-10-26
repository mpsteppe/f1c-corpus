## CameraModeSetter_004f1b50 — camera view mode / render offset reset

**Summary:** Sets camera view mode global and resets render offset fields based on input flag and internal state. Called during pit stop camera transitions.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStopReadyCheck (004a6200), PitStopProgress (004a68b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | R | — | internal state flag determining camera behavior branch |
| this | 0x34EC | RW | 0 | render offset cleared when 0x32BC is set |
| this | 0x34F0 | RW | 0 | RenderX [FACT] |
| this | 0x34F4 | RW | 0 | RenderY [FACT] |

**Written-by note (persistence):**
- this 0x34EC: recalc every frame — external poke does NOT persist
- this 0x34F0: recalc every frame — external poke does NOT persist
- this 0x34F4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c74f8 | dword_7C74F8 | W | CameraViewMode [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Input a2=0 AND field 0x32BC != 0 → no action (blocked). a2=0 AND 0x32BC=0 → sets CameraViewMode=0. a2 != 0 AND 0x32BC=0 → sets CameraViewMode=2. a2 != 0 AND 0x32BC != 0 → clears render offsets (0x34EC/0x34F0/0x34F4) to 0.
