## CameraViewSystem_00408e20 — Camera View System Initialization

**Summary:** Initializes the camera view system: opens an audio stream, iterates camera definitions, creates 3D sound emitters for each named camera view (swingman, cockpit, TV cockpit, nosecam, localcam), allocates dynamic view arrays, and applies session-manager camera positions.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x10)+0x0) | 0x0 | R | — | CameraView0 base pointer deref (swingman emitter data) |
| *(*(this+0x14)+0x0) | 0x0 | R | — | CameraView1 base pointer deref (cockpit emitter data) |
| *(*(this+0x18)+0x0) | 0x0 | R | — | CameraView2 base pointer deref (TV cockpit emitter data) |
| *(*(this+0x1C)+0x0) | 0x0 | R | — | CameraView3 base pointer deref (nosecam emitter data) |
| *(*(this+0x20)+0x0) | 0x0 | R | — | CameraView4 base pointer deref (additional view) |
| *(this+0x10) | 0x0 | R | — | CameraView0 struct start (swingman) |
| *(this+0x10) | 0x40 | RW | — | CameraView0 PositionX (world-space camera position) |
| *(this+0x10) | 0x44 | RW | — | CameraView0 PositionY (or FOV value) |
| *(this+0x14) | 0x0 | R | — | CameraView1 struct start (cockpit) |
| *(this+0x14) | 0x40 | RW | — | CameraView1 PositionX |
| *(this+0x14) | 0x44 | RW | — | CameraView1 PositionY |
| *(this+0x18) | 0x0 | R | — | CameraView2 struct start (TV cockpit) |
| *(this+0x18) | 0x40 | RW | — | CameraView2 PositionX |
| *(this+0x18) | 0x44 | RW | — | CameraView2 PositionY |
| *(this+0x1C) | 0x0 | R | — | CameraView3 struct start (nosecam) |
| *(this+0x1C) | 0x40 | RW | — | CameraView3 PositionX |
| *(this+0x1C) | 0x44 | RW | — | CameraView3 PositionY |
| *(this+0x20) | 0x0 | R | — | CameraView4 struct start (additional view) |
| *(this+0x24) | 0x40 | RW | — | CameraView5 PositionX (dynamic views array entry 0) |
| *(this+0x24) | 0x44 | RW | — | CameraView5 PositionY |
| *(this+0x28) | 0x40 | RW | — | CameraView6 PositionX |
| *(this+0x28) | 0x44 | RW | — | CameraView6 PositionY |
| *(this+0x2C) | 0x40 | RW | — | CameraView7 PositionX |
| *(this+0x2C) | 0x44 | RW | — | CameraView7 PositionY |
| *(this+0x30) | 0x40 | RW | — | CameraView8 PositionX |
| *(this+0x30) | 0x44 | RW | — | CameraView8 PositionY |
| this | 0x10 | RW | — | CameraView0Ptr (pointer to swingman 3D sound emitter, allocated via OperatorNew) |
| this | 0x14 | RW | — | CameraView1Ptr (cockpit emitter) |
| this | 0x18 | RW | — | CameraView2Ptr (TV cockpit emitter) |
| this | 0x1C | RW | — | CameraView3Ptr (nosecam emitter) |
| this | 0x20 | RW | — | CameraView4Ptr (additional view emitter) |
| this | 0x24 | R | — | CameraView5Ptr (read for position setup via ShortComputation_6080) |
| this | 0x28 | R | — | CameraView6Ptr |
| this | 0x2C | R | — | CameraView7Ptr |
| this | 0x30 | R | — | CameraView8Ptr |
| this | 0x38 | RW | 0 | DynamicViewCount (number of active swingman/localcam views) |
| this | 0x3C | RW | 0 | CurrentViewIndex (active view index, zeroed) |

**Written-by note (persistence):**
- *(this+0x10) 0x40: one-shot init — external poke does NOT persist
- *(this+0x10) 0x44: one-shot init — external poke does NOT persist
- *(this+0x14) 0x40: one-shot init — external poke does NOT persist
- *(this+0x14) 0x44: one-shot init — external poke does NOT persist
- *(this+0x18) 0x40: one-shot init — external poke does NOT persist
- *(this+0x18) 0x44: one-shot init — external poke does NOT persist
- *(this+0x1C) 0x40: one-shot init — external poke does NOT persist
- *(this+0x1C) 0x44: one-shot init — external poke does NOT persist
- *(this+0x24) 0x40: one-shot init — external poke does NOT persist
- *(this+0x24) 0x44: one-shot init — external poke does NOT persist
- *(this+0x28) 0x40: one-shot init — external poke does NOT persist
- *(this+0x28) 0x44: one-shot init — external poke does NOT persist
- *(this+0x2C) 0x40: one-shot init — external poke does NOT persist
- *(this+0x2C) 0x44: one-shot init — external poke does NOT persist
- *(this+0x30) 0x40: one-shot init — external poke does NOT persist
- *(this+0x30) 0x44: one-shot init — external poke does NOT persist
- this 0x10: one-shot init — external poke does NOT persist
- this 0x14: one-shot init — external poke does NOT persist
- this 0x18: one-shot init — external poke does NOT persist
- this 0x1C: one-shot init — external poke does NOT persist
- this 0x20: one-shot init — external poke does NOT persist
- this 0x38: one-shot init — external poke does NOT persist
- this 0x3C: one-shot init — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be888 | aSwingman | R | Camera name string "swingman" — matched for emitter assignment to v60 |
| 005be894 | aCockpit_0 | R | Camera name string "cockpit" — matched for emitter assignment to v61 |
| 005be89c | aTvcockpit | R | Camera name string "tvcockpit" — matched for emitter assignment to v59 |
| 005be8a8 | aNosecam | R | Camera name string "nosecam" — matched for emitter assignment to v62 |
| 005be910 | aLocalcam | R | Camera name string "localcam" — matched for dynamic emitter array in v70 |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00408870 | CameraPositionDefinitions | Initialize per-camera position definitions from loaded data |
| 00456080 | ShortComputation_6080 | Extract position value from camera struct into float pointer |
| 00456170 | F_3DSoundEmitter | Construct a 3D sound emitter struct (200-byte object, used for camera audio positioning) |
| 004562a0 | ShortComputation_62a0 | Cleanup/release audio emitter struct |
| 004562f0 | sub_4562F0 | Initialize emitter with audio stream and camera name |
| 00457000 | sub_457000 | Copy emitter data from source struct (position/parameters) |
| 00542520 | DoubleFieldGetter | Read double/float field from session manager at given offset |
| 005651b0 | sub_5651B0 | Check audio stream state (conditional gate) |
| 00565520 | sub_565520 | Search/match camera name string in stream data |
| 005668b0 | ZeroInitSmallStruct | Zero-initialize small audio stream handle struct (v57) |
| 005668d0 | SubCallWithConditionalFieldFree | Cleanup audio stream handle struct |
| 00566b20 | AudioStreamOpen | Open audio stream from resource file handle |
| 00566b90 | ConditionalFileHandleCloseWithFlagDispatch | Close file handle with conditional flag dispatch |
| 00566cc0 | ConditionalDispatchBasedOnFlag | Iterate entries in audio stream (conditional dispatch loop) |
| 00587c03 | OperatorNewNhMallocWrapper | Heap memory allocation (operator new wrapper) |
| 005881c0 | __alloca_probe | Stack probe for large alloca |
| 00588410 | sub_588410 | String comparison (returns true if not match) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x38 | > | 0 | DynamicViewCount — PASSES if dynamic (localcam) views > 0, enables allocation and position setup |

**Guard interpretation:** Primary guard is `a2 == 0` (input parameter) — if null resource handle, return 1 immediately. AudioStreamOpen failure triggers cleanup and return 1. The `this+0x38 > 0` guard controls whether dynamic view array is allocated and its camera positions are initialized from session manager data.
