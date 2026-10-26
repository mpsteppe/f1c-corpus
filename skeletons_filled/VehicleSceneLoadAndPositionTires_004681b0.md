## VehicleSceneLoadAndPositionTires_004681b0 — VehicleSceneLoadAndPositionTires

**Summary:** Loads a temporary vehicle visual scene file, locates the four tire nodes (LF, RF, LR, RR) in the scene graph, and repositions them relative to their computed center. Also handles cockpit and mirror node flag manipulation. Cleanup deletes the temporary scene file.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x134)+0x4C) | 0x4C | R | — | next sibling pointer (offset 0x4C = 76) in scene graph child node traversal |
| this | 0xE8 | R | — | vehicle model/object pointer (this[58]) |
| this | 0xEC | R | — | second vehicle data pointer (this[59]) |
| this | 0xF0 | RW | — | scene graph root node pointer (this[60], assigned from LinkedListNodeFinder) |
| this | 0x128 | R | — | guard index/status (this[74]); must be >= 0 to proceed |
| this | 0x134 | R | — | scene graph node chain base (used for child traversal at +0x4C) |

**Written-by note (persistence):**
- this 0xF0: once per call (assigned from LinkedListNodeFinder when this+0xE8 is non-null); external poke overwrites if scene is reloaded

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005c6754 | aLftire | R | NodeNameLFTire [DERIVED] |
| 005c675c | aRftire | R | aRftire [DERIVED] |
| 005c6764 | aLrtire | R | LRTire [DERIVED] |
| 005c676c | aRrtire | R | TireName_RR [DERIVED] |
| 005c6774 | aMirror | R | String_Mirror [DERIVED] |
| 005c677c | aCockpit | R | Cockpit [DERIVED] |
| 005c6784 | aSSS_0 | R | sFormatPath [DERIVED] |
| 005c678c | aVviewScn | R | VviewScnString [DERIVED] |
| 005c6798 | aTmpvehicleScn | R | TmpvehicleScnString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 005ec428 | dword_5EC428 | R | SeasonName [DERIVED] |
| 005ec440 | dword_5EC440 | R | SettingsDirectory [DERIVED] |
| 007cfe0c | dword_7CFE0C | R | VehicleSkinOverridePath [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040e1f0 | GlobalVectorOffsetUpdate | apply computed center offset to scene graph root node |
| 00466300 | StateInitializerWithFlagCheck | initialize vehicle state with conditional flag check |
| 004ddf70 | ZeroInitWrapper | zero-initialize the vehicle object at this+0xE8 |
| 004ddf90 | SceneFileTEAMDIRVEHDIRNOTSPINWriter | write/generate the vehicle view scene file with team/dir/vehicle paths |
| 00545340 | LinkedListNodeFinder | find or create a linked list node (scene graph root) |
| 005453a0 | EvaluateSceneNodeProperty | search scene graph for a named node (e.g., tire, cockpit) |
| 0054b3f0 | OffsetDispatch | apply translation offset to a scene graph node |
| 0054b420 | TripleFieldQuery | query 3 float fields (position X,Y,Z) from current node |
| 0054b450 | sub_54B450 | set tire position/orientation in scene graph |
| 0054c030 | FlagFieldBitManipulation | set/clear flags on scene nodes (cockpit, mirror) |
| 005506a0 | sub_5506A0 | initialize or reset tire node transform |
| 00566650 | StringCopyWithBufferRealloc | copy temp vehicle scene file path with buffer management |
| 0058815f | StringFormatWithBufferOverflowCheck | format file path strings with overflow protection |
| 0058986e | FileDeleteWithErrorHandling | delete the temporary vehicle scene file |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x128 | >= | 0 | vehicle status/index guard |

**Guard interpretation:** this+0x128 >= 0 → proceed with scene load, tire positioning, and file cleanup; < 0 → skip entire function, return 0 immediately (vehicle not in valid state for scene processing).
