## TwoFieldSetterCall_005423c0 — Set two fields and trigger update call

**Summary:** Stores a2 at offset 0x4 and a3 at offset 0x8, then calls sub_542050 with float parameters from offsets 0x6C and 0x70 and flag 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraModeViewportUpdate (00409a00), CameraShake (0040adb0), CameraTransformComputation (0040b710), CarSelectionStateMachine (00434460), sub_548AD0 (00548ad0), sub_5550E0 (005550e0), sub_55A060 (0055a060), sub_560C10 (00560c10), sub_560FE0 (00560fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | first field — written with a2 |
| this | 0x8 | RW | — | second field — written with a3 |
| this | 0x6C | R | — | first float parameter passed to sub_542050 |
| this | 0x70 | R | — | second float parameter passed to sub_542050 |

**Written-by note (persistence):**
- this 0x4: overwritten with a2 each call.
- this 0x8: overwritten with a3 each call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00542050 | sub_542050 | trigger update/apply with float params from 0x6C, 0x70 and flag 1 |

**Guard conditions:** None — always executes.
