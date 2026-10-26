## sub_5BC5A0_005bc5a0 — Expand bounding sphere to include point

**Summary:** Grows a bounding sphere (center at this[0..2], radius at this[3], squared radius cached at this[4]) so it encloses the point a2. If the point lies outside (squared distance > cached squared radius), the center moves half the remaining gap toward the point and the radius grows by the length of that half-step.

**Called by:** sub_5BC7F0 (005bc7f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | sphere center X (read, then shifted by half residual) |
| this | 0x4 | RW | — | sphere center Y (read, then shifted by half residual) |
| this | 0x8 | RW | — | sphere center Z (read, then shifted by half residual) |
| this | 0xC | RW | — | sphere radius (read; increased by residual half-length) |
| this | 0x10 | RW | — | cached squared radius (comparison key, then rewritten as new radius²) |

**Written-by note (persistence):**
- this 0x0: written only when a tested point is outside the sphere (v5 > this[4]); incremental shift, otherwise untouched — a poke survives until an outside point triggers a grow.
- this 0x4: written only when a tested point is outside the sphere; incremental shift — poke survives unless grow triggers.
- this 0x8: written only when a tested point is outside the sphere; incremental shift — poke survives unless grow triggers.
- this 0x10 (0xC): written only when a tested point is outside the sphere; radius is incremented (grow-only), never reset — poke survives unless grow triggers.
- this 0x10: written only when a tested point is outside the sphere; recomputed as new radius² — poke survives unless grow triggers.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16a0 | dbl_6F16A0 | R | double rodata constant used in the reciprocal-distance normalization (decompile renders it as the 1.0 numerator) |
| 006f2378 | dbl_6F2378 | R | double rodata constant used as the half-step scale on the center/radius residuals (rendered as 0.5) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** single gate `if (v5 > this[4])` where v5 = squared distance center→a2 and this[4] = cached squared radius. If the point is inside or on the sphere → nothing written (early skip). If outside → all five fields updated. No other branches.
