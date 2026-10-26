## ThreeFieldSetterWithSubCall_0054b3b0 — Three-field setter with bitmask clear

**Summary:** Assigns three parameters to fields at offsets 0x20, 0x24, 0x28, then clears a bitmask at offset 0x40 via BitmaskClear.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AudioPhysicsMixWithLerp (0040e2b0), VehiclePhysicsInitializer (00439210), PhysicsStateIntegration (00459a40), sub_45A8E0 (0045a8e0), sub_4A3320 (004a3320), PhysicsAudioVectorUpdate (004e2ad0), CameraViewportRenderSetup (004fbd70), OffsetDispatch (0054b3f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | RW | — | First value parameter |
| this | 0x24 | RW | — | Second value parameter |
| this | 0x28 | RW | — | Third value parameter |

**Written-by note (persistence):**
- this 0x20: recalc every frame — external poke does NOT persist
- this 0x24: recalc every frame — external poke does NOT persist
- this 0x28: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always writes all three fields and calls BitmaskClear.
