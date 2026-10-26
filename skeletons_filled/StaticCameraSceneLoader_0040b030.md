## StaticCameraSceneLoader_0040b030 — Static Camera Scene Loader

**Summary:** Loads static camera scene data from file: initializes 128 temp camera entries on stack, searches for "MainView" string, opens audio stream, reads static camera entries (up to 128) matching "StaticCam", allocates persistent storage, and stores the allocated array + count in this fields.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | MainView string search result (stored if found) |
| this | 0xC | RW | — | Allocated camera entry array (stride 160, allocated by OperatorNewNhMallocWrapper) |
| this | 0x10 | RW | — | Camera entry count (number of entries loaded) |
| this | 0x14 | RW | 0 | Camera current index initializer (always set to 0) |

**Written-by note (persistence):**
- this 0x4: Written conditionally when TwoLevelWideStringSearch finds "MainView". External poke survives when search fails.
- this 0xC: Written unconditionally if entries found (v6 > 0), allocated heap pointer. External poke does NOT survive (overwritten each load).
- this 0x10: Written unconditionally if entries found, set to loaded count. External poke does NOT survive.
- this 0x14: Written unconditionally if entries found, set to 0. External poke does NOT survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be8e0 | aMainview | R | "MainView" string searched at start of load |
| 005be928 | aStaticcam | R | "StaticCam" string for static camera entry matching |
| 008afe88 | dword_8AFE88 | R | Collision geometry handle (used by callees) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004562a0 | ShortComputation_62a0 | Initializes a 40-byte transform struct on stack |
| 004571e0 | F_3DTransformObjectInit | Initializes a 160-byte 3D transform object |
| 004572b0 | sub_4572B0 | Processes static camera entry into temp struct |
| 00457b60 | F_2DTransformStructCopy | Copies 160-byte entry from stack array to heap allocation |
| 00544f50 | TwoLevelWideStringSearch | Searches for "MainView" string |
| 005651b0 | sub_5651B0 | Checks file read state |
| 00565520 | sub_565520 | Reads "StaticCam" matching entry from file |
| 005668b0 | ZeroInitSmallStruct | Zero-initializes file handle struct |
| 005668d0 | SubCallWithConditionalFieldFree | Frees file handle struct fields |
| 00566b20 | AudioStreamOpen | Opens audio stream for the scene |
| 00566b90 | ConditionalFileHandleCloseWithFlagDispatch | Closes file handle |
| 00566cc0 | ConditionalDispatchBasedOnFlag | Loop condition check for file reading |
| 00587c03 | OperatorNewNhMallocWrapper | Allocates heap memory for camera entries |
| 005881c0 | __alloca_probe | Stack probing for large local arrays |

**Guard conditions:** AudioStreamOpen must succeed (non-zero). ConditionalDispatchBasedOnFlag must return non-zero to enter read loop. sub_5651B0 must return non-zero (no error) and sub_565520 must match "StaticCam" for each entry. Entry count v6 must be > 0 to allocate and store results; otherwise sets error flag (v3=1).
