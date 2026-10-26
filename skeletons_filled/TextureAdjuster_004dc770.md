## TextureAdjuster_004dc770 — Adjust texture material assignment by matching alternatives

**Summary:** Resolves a material name to a texture ID via sub_548890, then tries to match up to three alternative texture paths (a3-a5) against it using StringCompareCopy; returns 0, 1, or 2 indicating which alternative matched, or -1 on failure. Logs a debug message when no match found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D0110 (004d0110), sub_4D1450 (004d1450), PitCrewInstanceSetup (004ddad0), sub_4FC400 (004fc400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d4b98 | aUnableToAdjust | R | String_UnableToAdjust [DERIVED] |
| 005d4be0 | aDDevF119992002_5 | R | DDevString [DERIVED] |
| 005ea438 | byte_5EA438 | R | Global path buffer for file path operations |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | Format debug message string with variable arguments |
| 004d7aa0 | DebugLogWrite | Write debug log message |
| 004dc430 | ConditionalDispatchWithGlobalCheck | Check global condition before processing (guards execution) |
| 004dc450 | StringCompareCopy | Compare and conditionally copy texture path against reference |
| 00548890 | sub_548890 | Resolve material name to internal texture ID/pointer |
| 00587dd0 | sub_587DD0 | Copy string with length limit (strncpy-like) |

**Guard conditions:** Three early-exit guards: (1) `a1` (material name) must be non-null; (2) `ConditionalDispatchWithGlobalCheck(a7)` must return non-zero; (3) `sub_548890(a1)` must return a valid pointer. All return -1 on failure. Then cascading match: if `a3` is non-null and `StringCompareCopy` returns 0 → match found (return 0); else try `a4` → return 1; else try `a5` → return 2; else log error and return -1.
