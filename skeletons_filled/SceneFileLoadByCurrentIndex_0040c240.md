## SceneFileLoadByCurrentIndex_0040c240 — CameraSceneFileLoader

**Summary:** Loads a camera scene file based on current scene index. Allocates a scene loader object on first call, constructs path from SceneArray entry by replacing extension with "cam" suffix, then loads it via virtual dispatch.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CamMan_Init (0040c920)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C) | 0x4 | R | — | virtual method (vtable+4) called with constructed scene file path |
| this | 0x1C | RW | — | pointer to allocated scene loader object (24 bytes) |

**Written-by note (persistence):**
- this 0x1C: set once on first call (lazy allocation); persists for lifetime

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be880 | aCam | R | VehicleDataString [DERIVED] (also: "cam" string constant appended to scene filename) |
| 008ac48c | dword_8AC48C | R | CurrentSceneIndex [DERIVED] — index into SceneArray |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] — array of scene entries |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040ac00 | StructInitWithVTable | initializes the 24-byte scene loader object with vtable |
| 00587c03 | OperatorNewNhMallocWrapper | allocates 24 bytes for scene loader object |

**Guard conditions:** if this+0x1C (this[7]) is non-null, allocation/initialization skipped. Scene file loading skipped if SceneArray entry at current index is null.
