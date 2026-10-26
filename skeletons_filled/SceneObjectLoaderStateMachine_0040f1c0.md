## SceneObjectLoaderStateMachine_0040f1c0 — SceneObjectLoaderStateMachine

**Summary:** 7-mode state machine dispatching loading/unloading of scene objects: checks sub-object status, updates position from sub-object data, processes camera shake and vehicle physics. Part of scene/vehicle loading system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** LoopWithConditionalSkipFunction (00410980)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x20)+0x0) | 0x48BC | R | — | Vtable entry at offset 0x48BC; bit 8 checked for VehiclePhysicsModeDispatcher gate |
| *(this+0x20) | 0x0 | R | — | Virtual method table pointer on sub-object |
| *(this+0x20) | 0x34D4 | R | — | Sub-object field at offset 13524 → copied to this[3] (X position, case 6) |
| *(this+0x20) | 0x34D8 | R | — | Sub-object field at offset 13528 → copied to this[4] (Y position, case 6) |
| *(this+0x20) | 0x34DC | R | — | Sub-object field at offset 13532 → copied to this[5] (Z position, case 6) |
| this | 0xC | RW | — | Position X component (this[3]) |
| this | 0x10 | RW | — | Position Y component (this[4]) |
| this | 0x14 | RW | — | Position Z component (this[5]) |
| this | 0x1C | R | — | Mode selector (this[7], values 0-6) |
| this | 0x20 | R | — | Pointer to sub-object with scene data (this[8]) |

**Written-by note (persistence):**
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040f2d8 | jpt_40F1D0 | R | Jump table for 7-case mode switch (0-6) |
| 008ab710 | dword_8AB710 | R | UIWidgetList [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040f600 | CameraShakeRingBufferWrite | Writes camera shake data to ring buffer |
| 0045a8e0 | sub_45A8E0 | Checks loading/unloading state for this+12 position |
| 004bde20 | sub_4BDE20 | Cleanup subroutine after state processing |
| 004e4930 | VehiclePhysicsModeDispatcher | Dispatches vehicle physics mode (guarded by vtable bit 8) |
| 004e9600 | SuspensionStateUpdate | Updates suspension state from sub-object |

**Guard conditions:** Mode 0/3: sub_45A8E0 returns non-zero → cleanup + return 0. Mode 1/4: sub_45A8E0 returns zero → camera shake + cleanup + return 0. Mode 2/5: sub_45A8E0 returns non-zero → camera shake + cleanup + return 0; zero → continue to cleanup path. Mode 6: vtable bit 8 at offset 0x48BC must be set → dispatch VehiclePhysicsModeDispatcher. Always runs SuspensionStateUpdate + position copy + cleanup on case 6, returns 1.
