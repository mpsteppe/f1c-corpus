## SceneFilenameMatchAgainstBasePath_0047f300 — FindMatchingSceneForTrackPath

**Summary:** Iterates scene file entries to find one whose filename matches the current track path; returns 0 on match or calls AIW fallback if none found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_485B90 (00485b90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ce5d0 | dword_7CE5D0 | R | CurrentTrackPath [DERIVED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ac488 | dword_8AC488 | R | SceneFileCount [DERIVED] |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c54f0 | AIW | default scene initialization or fallback when no matching scene found |
| 00596c80 | sub_596C80 | compares a scene filename against a base directory path |

**Guard conditions:** If SceneFileCount (dword_8AC488) <= 0, immediately return AIW(0) — no scene files to check. Each scene filename strlen must be > 0 to be tested; otherwise skipped.
