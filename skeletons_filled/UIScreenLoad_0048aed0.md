## UIScreenLoad_0048aed0 — Screen resource file loader

**Summary:** Loads UI screen resource data from file. Builds path from override prefix (dword_5EC408) + screen name (this[0xB0]), opens via AudioStreamOpen, reads resource chunks into allocated buffer, replaces output pointer with new data.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB0 | R | — | this[44] — screen path/name string used to build resource filename |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` — format string for path construction) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec408 | dword_5EC408 | R | OverridePathPtr [DERIVED] (also: ` — override path pointer (docs/19) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005665b0 | sub_5665B0 | reads data chunk from resource into buffer |
| 005668b0 | ZeroInitSmallStruct | zeros small struct before use |
| 005668d0 | SubCallWithConditionalFieldFree | cleanup/free helper for resource struct |
| 00566b20 | AudioStreamOpen | opens resource file for reading |
| 00566cc0 | ConditionalDispatchBasedOnFlag | reads/iterates resource data chunks |
| 00566db0 | sub_566DB0 | seeks within opened resource to a position |
| 00566e20 | ResourceLookupDispatcher | gets resource section size |
| 00587bcf | FreeWrapper_7bcf | frees heap memory (old buffer) |
| 00587c03 | OperatorNewNhMallocWrapper | allocates heap memory for data buffer |
| 0058815f | StringFormatWithBufferOverflowCheck | formats path string safely ("%s%s") |

**Guard conditions:** AudioStreamOpen must return non-zero (success). If file open fails, no resource loading occurs — output pointer remains unchanged.
