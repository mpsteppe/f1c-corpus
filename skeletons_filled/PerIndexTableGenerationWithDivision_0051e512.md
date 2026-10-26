## PerIndexTableGenerationWithDivision_0051e512 — PerEntryDivisionTableBuild

**Summary:** Builds per-entry division lookup tables for gradient computation. For each unique entry descriptor, allocates 1024-byte table and fills with division results (65025 - 510*value) / scaled_param using global double and integer source tables.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CodecModeSelect (0051ea90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1A4) | 0x20 | R | — | entry descriptor array (used for uniqueness check) |
| *(this+0x4) | 0x0 | R | — | allocator vtable function (allocate memory) |
| this | 0x4 | R | — | allocator pointer |
| this | 0x64 | R | — | channel count |
| this | 0x1A4 | R | — | context pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b05c8 | dbl_5B05C8 | R | DriverTableSource [DERIVED] (also: Source data table) |
| 005b06c8 | dword_5B06C8 | R | CombinatoricsLookupTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x64 | > | 0 | channel count > 0 (proceed with per-entry table builds) |

**Guard interpretation:** When this+0x64 > 0, iterate over each entry descriptor and build division table if not already allocated. PASSES: entries processed. BLOCKED: no channels, skip entirely.
