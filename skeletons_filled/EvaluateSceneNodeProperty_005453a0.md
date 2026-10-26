## EvaluateSceneNodeProperty_005453a0 — Evaluate scene node property via recursive string search

**Summary:** Searches for a property value (`a2`) across scene node trees. If `a3` is non-zero, searches the provided tree directly. Otherwise iterates through audio network nodes (first list at 0x100) probing sub-lists, then falls back to second list (head at 0x108). Returns found value or 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleSceneLoadAndPositionTires (004681b0), StewardLightGlowNodeFinder (004d0e20), sub_4D15F0 (004d15f0), Steward_Init (004d38f0), VehicleGraphicsSceneLoader (004dfce0), sub_4FBA10 (004fba10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x204) | 0x104 | R | — | Forward link between audio network nodes |
| this | 0x100 | R | — | Head of first list (audio network node chain) |
| this | 0x108 | R | — | Head of second list (fallback search list) |
| this | 0x1EC | R | — | Unknown — artifact from decompiler path |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054bc60 | RecursiveTreeStringSearch | Recursive string comparison to find matching scene node property |

**Guard conditions:** `a3` (direct flag): PASSES (search directly via RecursiveTreeStringSearch) when non-zero; BLOCKED (iterate manager lists) when zero. `this[64]` (first list head): PASSES (iterate audio network nodes) when non-null; BLOCKED (try second list) when null. Sub-list head at offset 0xEC: PASSES (RecursiveTreeStringSearch on sub-node) when non-null; BLOCKED (skip to next audio network node) when null.
