## TracksideCameraTargetLookup_0040c890 — TracksideCameraTargetLookup

**Summary:** Resolves a camera target name/ID by querying three registered loader objects in sequence (config, scene, module) via virtual method at vtable+28. Returns first non-zero result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraTargetNameResolver (0040db00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x18) | 0x1C | R | — | virtual method (vtable+28) on config loader object, called to resolve target name |
| *(this+0x1C) | 0x1C | R | — | virtual method (vtable+28) on scene loader object, fallback if first fails |
| *(this+0x20) | 0x1C | R | — | virtual method (vtable+28) on module loader object, fallback if first two fail |
| this | 0x18 | R | — | pointer to first (config) loader object |
| this | 0x1C | R | — | pointer to second (scene) loader object |
| this | 0x20 | R | — | pointer to third (module) loader object |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** if a2 (target name/ID) is null, returns 0 immediately. Otherwise queries each loader in sequence; returns first non-null result.
