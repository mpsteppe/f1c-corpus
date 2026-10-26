## StewardLightGlowNodeFinder_004d0e20 — Find scene glow and line nodes

**Summary:** Evaluates scene node properties for two node identifiers (a2, a3), storing resulting handles at this+0x4 (line node) and this+0x8 (glow node). Logs "could not find" errors if either property evaluates to zero.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Steward_Init (004d38f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | Handle/pointer to the "line" scene node |
| this | 0x8 | RW | — | Handle/pointer to the "glow" scene node |

**Written-by note (persistence):**
- this 0x4: Written once from EvaluateSceneNodeProperty(a2, 0). External poke would survive — it's a stored handle.
- this 0x8: Written once from EvaluateSceneNodeProperty(a3, 0). Conditional on first write not being needed for write to execute. External poke would survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d3b6c | aDDevF119992002_3 | R | Format string for scene path, passed to StringSplitLoop |
| 005d3b94 | aCouldNotFindGl | R | "Could not find glow" error string |
| 005d3bb0 | aCouldNotFindLi | R | "Could not find line" error string |
| 008ad25c | dword_8AD25C | R | Debug message buffer passed to DebugLogWrite |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | Parses scene path string for node lookup iteration |
| 004d7aa0 | DebugLogWrite | Writes error message to debug log when node not found |
| 005453a0 | EvaluateSceneNodeProperty | Evaluates a scene node property (sub-property index 0) to get a node handle |

**Guard conditions:** None — both nodes are always looked up unconditionally. If a node is not found (EvaluateSceneNodeProperty returns 0), an error is logged but execution continues.
