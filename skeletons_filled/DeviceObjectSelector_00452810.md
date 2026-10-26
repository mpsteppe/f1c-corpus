## DeviceObjectSelector_00452810 — Device/Object Config Selector & Registration

**Summary:** Matches an input integer ID against a large set of pre-registered global config objects (collision, audio, rendering constants). Stores the matched global's address in this+0x20 (output), sets this+0x0=2 for success or 0 for no match, then reinitializes a sub-structure via SwapAndReinit. Part of the device initialization / config-binding system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_30a0 (004530a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | match-result status (2=matched, 0=no match) |
| this | 0x1C | RW | 0 | sub-structure zero-init sentinel field |
| this | 0x20 | RW | 0 | pointer to matched global config object (selected device/config) |

**Written-by note (persistence):**
- this 0x0: written once per call — external poke does NOT persist (overwritten each call)
- this 0x1C: written once per call (via SwapAndReinit) — external poke does NOT persist
- this 0x20: written once per call — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ca3a8 | dword_7CA3A8 | R | AudioBuffer_08 [DERIVED] (also: ` — collision state (type=0x26, alpha=1.0) |
| 007ca3b8 | dword_7CA3B8 | R | config object — audio/rendering buffer source ID |
| 007ca3c8 | dword_7CA3C8 | R | CollisionRegionType [DERIVED] (also: ` — region type (6) |
| 007ca3d8 | dword_7CA3D8 | R | AudioBuffer_11 [DERIVED] (also: ` — audio buffer/source objects identified by address) |
| 007ca3e8 | dword_7CA3E8 | R | AudioEngineDefaultType [DERIVED] |
| 007ca410 | dword_7CA410 | R | CollisionSolverIter [DERIVED] (also: ` — collision iteration count (0x3e = 62) |
| 007ca438 | dword_7CA438 | R | AudioBuffer_05 [DERIVED] (also: ` — node element count (35) |
| 007ca448 | dword_7CA448 | R | AudioBuffer_06 [DERIVED] |
| 007ca470 | dword_7CA470 | R | CollisionGridSize (4) [DERIVED] |
| 007ca480 | dword_7CA480 | R | AudioBuffer_09 [DERIVED] (also: ` through `_DAT_007ca48c` — config block (type=0x27, float extent=-1.0f, zeroed fields) |
| 007ca490 | dword_7CA490 | R | CollisionCellInitCount [DERIVED] (also: ` — collision cell initial count (1) |
| 007ca4d0 | dword_7CA4D0 | R | CollisionWorldObjType [DERIVED] (also: ` — collision object index/type) |
| 007ca4f8 | dword_7CA4F8 | R | SteeringRackTravel [DERIVED] |
| 007ca50c | dword_7CA50C | R | AudioBuffer_03 [DERIVED] (also: ` — collision contact limit / iteration count) |
| 007ca57c | dword_7CA57C | R | ForceFeedbackGain [DERIVED] |
| 007cc9bc | dword_7CC9BC | R | AudioBufferSource [DERIVED] |
| 007cc9ec | dword_7CC9EC | R | AudioSourceObject [DERIVED] |
| 007cca44 | dword_7CCA44 | R | NodeElementCount [DERIVED] (also: ` — node element count (2) |
| 007cca6c | dword_7CCA6C | R | RenderStateInt_9 [DERIVED] |
| 007cca7c | dword_7CCA7C | R | UIElementTypeID [DERIVED] |
| 007ccbb0 | dword_7CCBB0 | R | CollisionMaterialDefault [DERIVED] |
| 007ccbf4 | dword_7CCBF4 | R | AudioBuffer_07 [DERIVED] (also: ` — grid size (37) |
| 007cccb0 | dword_7CCCB0 | R | CollisionConfigType [DERIVED] |
| 007ccf60 | dword_7CCF60 | R | CollisionGlobalCount107 [DERIVED] (also: ` — collision global, int = 0x6b) |
| 007ccf70 | dword_7CCF70 | R | CollisionConfigBlock [DERIVED] (also: ` through `_DAT_007ccf7c` — collision configuration variables) |
| 007ccf80 | dword_7CCF80 | R | MaxContactCount [DERIVED] (also: ` — collision global, int = 10) |
| 007ccf90 | dword_7CCF90 | R | VehicleSetup_Target_7CCF90 [DERIVED] |
| 007ccfa0 | dword_7CCFA0 | R | RenderStateID_CFA0 [DERIVED] |
| 007ccfb0 | dword_7CCFB0 | R | RenderStateID_S [DERIVED] |
| 007ccfdc | dword_7CCFDC | R | SoundBank_CCFDC [DERIVED] |
| 007cd0f8 | dword_7CD0F8 | R | AudioBuffer_04 [DERIVED] (also: ` — collision cell count (34) |
| 007cd108 | dword_7CD108 | R | AudioSystemSingleton [DERIVED] |
| 007cd148 | dword_7CD148 | R | CollisionBucketParam_7CD148 [DERIVED] |
| 007cd158 | dword_7CD158 | R | AudioBuffer_02 [DERIVED] (also: ` — material stride (0x20 = 32 bytes per material entry) |
| 007cd188 | dword_7CD188 | R | CollisionShape_105 [DERIVED] |
| 007cd198 | dword_7CD198 | R | DefaultCollisionState [DERIVED] (also: ` — collision state (type=5, alpha=1.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00452740 | SwapAndReinit | reinitialize sub-structure at this+4 (89 bytes, zero-filled) |

**Guard conditions:** No branch-based guards — the function is a linear chain of if/else-if comparisons. The only conditional outcome is: if a2 matches one of 34 known globals, set status=2 and store the global's address; if no match, set status=0 and return -1. The SwapAndReinit call executes unconditionally after the matching chain.