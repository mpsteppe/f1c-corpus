## ModuleAssetPathResolver_0040c3b0 — CameraModuleAssetPathLoader

**Summary:** Loads a second camera module asset file by constructing path from current SceneArray entry (replacing extension with "cam" suffix). Identical pattern to CameraSceneFileLoader but stores result in this+0x20 slot instead of this+0x1C.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CamMan_Init (0040c920)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x20) | 0x4 | R | — | virtual method (vtable+4) called with constructed asset file path |
| this | 0x20 | RW | — | pointer to allocated module asset loader object (24 bytes) |

**Written-by note (persistence):**
- this 0x20: set once on first call (lazy allocation); persists for lifetime

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be880 | aCam | R | VehicleDataString [DERIVED] (also: "cam" string constant) |
| 008ac48c | dword_8AC48C | R | CurrentSceneIndex [DERIVED] — index into SceneArray |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] — array of scene entries |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040b560 | StructInitWithVtable | initializes the 24-byte asset loader object with vtable |
| 00587c03 | OperatorNewNhMallocWrapper | allocates 24 bytes for asset loader object |

**Guard conditions:** if this+0x20 (this[8]) is non-null, allocation/initialization skipped. Asset loading skipped if SceneArray entry at current index is null.
