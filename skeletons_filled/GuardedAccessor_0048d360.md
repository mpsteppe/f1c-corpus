## GuardedAccessor_0048d360 — GuardedSelectedIndexGetter

**Summary:** Returns the currently selected index (stored at this+0x338) if the list count (this+0x328) is greater than 0, otherwise returns -1. A guarded accessor for a UI list/collection.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ProfileIconBmpLoader (004692b0), SetupFileLoadAndFinalize (00469630), ThreeCallChain (00469857), SceneLoadAndNameMatch (00475920), PollingStateChangeDetection (00477fa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x328 | R | — | Item count of the list |
| this | 0x338 | R | — | Currently selected index |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x328 | > | 0 | Item count |

**Guard interpretation:** PASS: count > 0 → returns selected index. BLOCKED: count <= 0 → returns -1.
