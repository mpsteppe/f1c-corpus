## PitCrewAnimationOffsetUpdate_0054bf60 — Update pit crew animation vertex offsets

**Summary:** Walks UI/animation element linked list (head at this+0x204, next at node+0x10) and updates vertex position offsets for entries matching a given type ID (a2). For each matching entry, iterates vertices with stride 48 bytes and adds offset (a4, a5) to X/Y position components. Attribute offset base depends on a3: 0 updates offsets at data_ptr+32/36, 1 updates at data_ptr+40/44. Sets dirty flag bit 0x800 at entry+0x30. Part of pit crew animation system called during camera/viewport render setup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraViewportRenderSetup (004fbd70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x204 | R | — | Head of animation element linked list |
| this | 0x224 | R | — | Accessed during element iteration |
| this | 0x32C | R | — | Entry count guard; must be > 0 for processing |
| this | 0x330 | R | — | Entry type ID; compared against a2 for match |
| this | 0x338 | R | — | Vertex count per entry; iteration bound |
| this | 0x33C | R | — | Vertex data pointer for offset updates |
| this | 0x368 | RW | — | Dirty flag; bit 0x800 set after offset update |

**Written-by note (persistence):**
- this 0x368: written once per matching entry; flag bit 0x800 set after offset modification

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x32C | > | 0 | Entry count; must be positive for traversal |
| this | 0x338 | > | 0 | Vertex count per entry; must be positive for offset updates |

**Guard interpretation:** List walk BLOCKED if `this[0x204]` (head) is null. Per-element: BLOCKED if entry count ≤ 0. Per-entry: only processed if entry type ID matches a2. Vertex offset loop BLOCKED if vertex count ≤ 0 (inner guard). a3 value selects attribute offset: 0 → base at data+36, 1 → base at data+44; any other a3 value skips the offset update completely (only dirty flag set).
