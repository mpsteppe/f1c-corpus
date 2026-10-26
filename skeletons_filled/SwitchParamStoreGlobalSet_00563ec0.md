## SwitchParamStoreGlobalSet_00563ec0 — SetParamStoreAndDispatchCallback

**Summary:** Selects a function pointer based on type parameter (a4): 0→sub_563F20, 1→PhysicsSignDirectionFunction, 2→PhysicsObjectNameCompare, default→sub_564090. Stores parameters a2/a3 in the struct, updates global context pointer (dword_8D46B4), and dispatches via sub_564A00 with the selected callback.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkFilterSort (00462160)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00563f10 | jpt_563EC9 | R | jump table for switch dispatch |
| 00563f20 | sub_563F20 | R | callback for type 0 |
| 00563f70 | PhysicsSignDirectionFunction | R | callback for type 1 (physics sign/direction) |
| 00564000 | PhysicsObjectNameCompare | R | callback for type 2 (physics object name comparison) |
| 00564090 | sub_564090 | R | default callback (type >= 3) |
| 008d46b4 | dword_8D46B4 | W | NetworkContextPtr [DERIVED] (also: undocumented global pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00564a00 | sub_564A00 | dispatches to selected callback with struct context |

**Guard conditions:** switch on a4: 0, 1, 2 each select specific callback; default handles all other values.

