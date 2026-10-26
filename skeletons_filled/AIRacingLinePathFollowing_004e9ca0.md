## AIRacingLinePathFollowing_004e9ca0 — AI Racing Line Path Node Traversal

**Summary:** Traverses the racing line's doubly-linked path nodes for an AI vehicle: looks up the current and target nodes via position queries, iterates node-by-node applying position/orientation to vehicle state, updates suspension and wheel contact distances, and toggles scene-node visibility for track-follow display. Part of the AI path-following and racing-line visualization system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4BB8E0 (004bb8e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4040 | R | — | target path node ID (compared against node's +17 field for matching) |
| obj | 0x4094 | RW | 1 | per-iteration step flag (set to 1 each time through the node traversal loop) |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x3440 | R | — | path traversal mode byte flag (nonzero = forward-follow mode: walks +68 next-pointer chain to reach target node) |
| this | 0x34D4 | RW | — | current path node X coordinate (copied from node data via *v7) |
| this | 0x34D8 | RW | — | current path node Y coordinate |
| this | 0x34DC | RW | — | current path node Z coordinate |
| this | 0x34E0 | RW | — | Euler angle X component (from 3D transform result v31) |
| this | 0x34E4 | RW | — | Euler angle Y component (from transform result v31[1]) |
| this | 0x34E8 | RW | — | Euler angle Z component (from transform result v31[2]) |
| this | 0x3A9C | RW | — | cached pointer to current racing line node (from sub_403640 position lookup, stored at DWORD index 3751) |

**Written-by note (persistence):**
- obj 0x4094: recalc every frame — external poke does NOT persist
- this 0x34D4: recalc every frame — external poke does NOT persist
- this 0x34D8: recalc every frame — external poke does NOT persist
- this 0x34DC: recalc every frame — external poke does NOT persist
- this 0x34E0: recalc every frame — external poke does NOT persist
- this 0x34E4: recalc every frame — external poke does NOT persist
- this 0x34E8: recalc every frame — external poke does NOT persist
- this 0x3A9C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005ea3f0 | dword_5EA3F0 | R | RaycastMaxIterMult [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008ad07c | dword_8AD07C | R | TrackFollowStatePtr [DERIVED] |
| 008ad080 | dword_8AD080 | R | Unknown_Game_Setup_AD080 [DERIVED] |
| 008ad084 | dword_8AD084 | R | PathNodeCount [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403640 | sub_403640 | looks up a racing line node by position (returns pointer to node data struct from setup scene) |
| 004bc340 | sub_4BC340 | checks whether path-following mode is active (returns bool from postProcessInput+0x4034) |
| 004d1140 | RenderCallWithGuard | executes render operation with guard condition, populates transform output buffers v31/v32 |
| 004e9600 | SuspensionStateUpdate | updates vehicle suspension physics state for the current path position |
| 004e9a40 | VehicleBodyToWheelContactDistanceComputation | computes vehicle body to wheel contact distances (collision detection for wheels) |
| 004e9bd0 | F_3x3MatrixTransformWithTranslation | applies 3x3 matrix transform with translation to vehicle body |
| 004ef6c0 | CoordinateTransformWithOffset | transforms coordinates with offset (used to compute target node position) |
| 004efb20 | F_3DTransformWithMatrixMultiplication | applies 3D transformation using matrix multiply (world-to-local or local-to-world) |
| 0054f7a0 | UIFocusChange | changes UI focus/highlight to specified scene node |
| 0054fae0 | BufferEntryClear | clears a buffer entry by flag mask (0x8000000 = specific render buffer) |
| 0054fb40 | SceneNodeVisibilityToggle | toggles scene node visibility on/off (0 = hide, 1 = show) |
| 00566e40 | EulerToRotationMatrix | converts Euler angles (XYZ triplet) to 3x3 rotation matrix for vehicle orientation |

**Guard conditions:** Outer guard: sub_4BC340 on postProcessInput+0x4034 must return true (path-following active). First RenderCallWithGuard at line 35 must succeed (v3|v4 flags both zero). Node matching loop (lines 45-55): iterates backward through node +67 prev pointers until node's +17 field matches target node ID (obj+0x4040), bounded by 2*dword_5EA3F0 iterations; returns early if limit exceeded. Second path traversal (lines 62-70): if v14|v15 render flags nonzero, walks prev-pointers again up to v5 limit. Forward-follow block (lines 73-87): only executes if byte at this+0x3440 is set; walks +68 next pointers (requires each node's +75 field nonzero = valid forward link) until reaching target node v11; returns early if link broken or limit exceeded. Main traversal loop (lines 94-143): follows node chain via +69 next pointer (when node's linked target at offset 300 == 1) or +68 prev pointer (otherwise); terminates when state v26 != 1 (switches from 1 to 2 when v7 reaches target v11) OR when node's +17 field is zero (end of chain). At each node: copies XYZ to this+0x34D4-DC, updates suspension, sets per-step flag (obj+0x4094=1), computes wheel contacts, applies matrix transform, clears buffer, and toggles scene node visibility for up to three global track-follow pointers (dword_8AD07C, dword_8AD080, dword_8AD084). Loop bound by v25 = 2*dword_5EA3F0; exceeds limit triggers early buffer clear and return.
