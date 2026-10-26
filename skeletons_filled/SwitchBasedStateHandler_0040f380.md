## SwitchBasedStateHandler_0040f380 — SwitchBasedStateHandler

**Summary:** 8-mode state handler dispatching collision detection, wheel contact distance computation, UI focus changes, and scene node visibility toggles based on mode and vtable flags. Part of vehicle/collision/physics system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ProximityCheckWithTagUpdate (004bda20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x20) | 0x48BC | R | — | Sub-object vtable entry at offset 0x48BC; bit 0 checked for case 6 gate |
| this | 0x1C | R | — | Mode selector (this[7], values 0-7) |
| this | 0x20 | R | — | Sub-object pointer (this[8]) with data and vtable |
| this | 0xF0 | R | — | Sub-object field at offset (this[8]+0x6E8) used as UIFocus target in case 6 |
| this | 0x158 | R | — | Sub-object double field at offset 0x138 (vector X, case 2) |
| this | 0x160 | R | — | Sub-object double field at offset 0x140 (vector Y, case 2) |
| this | 0x168 | R | — | Sub-object double field at offset 0x148 (vector Z, case 2) |
| this | 0x708 | R | — | Sub-object field at offset 0x34EC (wheel contact data pointer, case 6) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040f484 | jpt_40F393 | R | Jump table for 8-case mode switch |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e9a40 | VehicleBodyToWheelContactDistanceComputation | Computes distance from vehicle body to wheel contact point |
| 004ea040 | F_3DCollisionDetectionWithAABBTestAndContactResp | Performs AABB collision test and contact response |
| 0054f7a0 | UIFocusChange | Changes UI focus element |
| 0054fb40 | SceneNodeVisibilityToggle | Toggles scene node visibility (on/off) |

**Guard conditions:** Cases 0/1/3/4/5 → AABB collision + contact response. Case 2 → visibility toggle + wheel contact distance. Case 6 → must have vtable bit 0 at offset 0x48BC set → wheel contact + UI focus + visibility toggle. Case 7 → wheel contact + UI focus + visibility toggle (always). default → skip.
