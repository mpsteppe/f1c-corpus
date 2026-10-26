## UtilityFunction_7810_00477810 — ConditionalSceneDispatchSelector

**Summary:** Dispatches different scene commands via `dword_7CD8C0` based on whether the object identifier at offset 0x180 equals 24.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_75f0 (004775f0), SeasonSceneInitialization (00477720)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x180 | R | — | mode/type discriminator compared against 24 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] (also: ` — game command dispatch interface pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x180 | == | 24 | mode/type identifier |

**Guard interpretation:** `this[96]` (offset 0x180) == 24 → dispatch command ID 23; != 24 → dispatch command ID 21
