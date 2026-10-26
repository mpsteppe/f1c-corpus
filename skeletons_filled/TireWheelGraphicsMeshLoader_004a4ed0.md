## TireWheelGraphicsMeshLoader_004a4ed0 — TireWheelGraphicsMeshLoader

**Summary:** Loads tire/wheel graphics mesh reference (.MTS file) for a specific wheel position (LF/RF/LR/RR). Parses instance name, meshfile path, and LOD distance bounds from a data stream, allocates a 72-byte mesh info struct, and links it into the per-tire linked list. Recursively handles nested instance loading.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A51C0 (004a51c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c596c | aTrue | R | sTrue [DERIVED] |
| 005c6754 | aLftire | R | NodeNameLFTire [DERIVED] |
| 005c675c | aRftire | R | aRftire [DERIVED] |
| 005c6764 | aLrtire | R | LRTire [DERIVED] |
| 005c676c | aRrtire | R | TireName_RR [DERIVED] |
| 005cc4f4 | asc_5CC4F4 | R | Str_UI_CompareToken_CC4F4 [DERIVED] |
| 005cd5ec | aMts | R | aMts [DERIVED] |
| 005cd5f0 | byte_5CD5F0 | R | Unknown_VehicleSetup_Value [DERIVED] |
| 005cd5f4 | aShadowobject | R | ShadowObjectKey [DERIVED] |
| 005cd604 | aLodout | R | StringLODOut [DERIVED] |
| 005cd60c | aLodin | R | StringLODIn [DERIVED] |
| 005cd614 | aMeshfile | R | Key_MeshFile [DERIVED] |
| 005cd620 | aInstance | R | StringInstance [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007cf884 | dword_7CF884 | R | DetailLevel [DERIVED] (also: ` â€” detail level (â‰¤1 = load pitcrew meshes) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a4ed0 | TireWheelGraphicsMeshLoader | recursive call for nested instance mesh loading |
| 005651b0 | sub_5651B0 | advances to next token/entry in data stream |
| 00565520 | sub_565520 | matches a key string against the current data stream token |
| 00565870 | sub_565870 | reads a float value associated with a key (LOD bounds) |
| 00566810 | sub_566810 | checks if string ends with ".MTS" extension |
| 00566cc0 | ConditionalDispatchBasedOnFlag | conditional dispatch/init for the 384-byte local parse context |
| 00587c03 | OperatorNewNhMallocWrapper | allocates 72-byte mesh info struct |
| 00588410 | sub_588410 | compares input string against tire position name (aLftire, aRftire, etc.) or "True" |

**Guard conditions:** No struct field guards. Outer loop: if ConditionalDispatchBasedOnFlag returns 0, skip entirely. Within loop: if data stream has no more entries (sub_5651B0 returns non-zero), break. If current token equals asc_5CC4F4, return success. If instance key not match, or meshfile key not match, skip element. LOD check: skip if a6 < aLodin or a6 >= aLodout (distance outside LOD range). Shadow check: skip if shadowobject key matches "True" and detail level >= 2.
