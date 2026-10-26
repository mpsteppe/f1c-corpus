## DataFileCheckSizeQuery_0045c650 — DataFileCheckSizeQuery

**Summary:** Strips extension from file path, looks up matching scene in scene array by name, and accumulates scene file size into output. Part of data file validation for scene loading.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_45C0C0 (0045c0c0), ParticleSoundEffectSpawner (004607a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1 | R | — | Selector byte for UtilityFunction_8a60 parameter extraction |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ac488 | dword_8AC488 | R | SceneFileCount [DERIVED] — number of entries in scene array |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] — base of scene data array |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00568a60 | UtilityFunction_8a60 | Extracts parameter value using selector byte |
| 00587dd0 | sub_587DD0 | Copies string with length limit (max 511) |
| 00588410 | sub_588410 | String comparison against scene name at offset 4 in each entry |

**Guard conditions:** Scene count must be > 0 to enter search loop. Loop continues while sub_588410 returns non-zero (name mismatch). Match found when sub_588410 returns 0 — adds size at offset 0x188 (392) to output. If no match in any entry, returns without adding size.
