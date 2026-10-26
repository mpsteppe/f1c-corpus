## BitfieldExtractionWithScale_004b2b40 — Bitfield 2-bit extract (bits 22-23)

**Summary:** Extracts 2-bit field from bits 22-23 of dword at offset 0x30 and multiplies by 0.333333 (1/3). Decodes small-range state/flag value.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsTimeStep (004c73f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x30 | R | — | Bitfield dword at offset 0x30 (bits 22-23 = 2-bit encoded value) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e98c | flt_59E98C | R | AccelerationTuningFactor [DERIVED] (also: ` â€” acceleration tuning) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — reads directly.
