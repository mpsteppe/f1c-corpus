## SessionReset_0042d350 — SessionReset

**Summary:** Destroys texture surfaces for state flag pair and frees/reinitializes season parent path resources. Called during game exit to reset session state.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameExit (0042db20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ec3d0 | dword_5EC3D0 | R | SeasonParentPath [DERIVED] |
| 008ad254 | dword_8AD254 | R | StateFlagPair [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00422be0 | sub_422BE0 | Free/reinitialize path-based resources (season parent path) |
| 004d7800 | TextureSurfaceDestroyer | Destroy/unload texture surfaces for state flag pair |

**Guard conditions:** No guard — always executes both calls unconditionally.
