## FloatComparisonWithConstantsTable_004ce380 — ParticleTypeFloatCheck

**Summary:** Check if a non-zero float value exists for a given particle type entry in a constant table. Iterates entries; type 1 reads field at offset 0x28 (a2[10]), type 5 reads field at offset 0x30 (a2[12]), default reads offset 0x2C (a2[11]). Returns 1 if the field is non-zero.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4EE2D0 (004ee2d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x40) | 0x4 | R | — | particle type ID in each entry |
| this | 0x3C | R | — | entry count |
| this | 0x40 | R | — | pointer to constant entry array |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Entry count > 0 (this[15]). Iterates entries, breaking on entry type 0. Returns 0 (not found) if loop exhausts all entries.
