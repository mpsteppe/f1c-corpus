## sub_5BC7F0_005bc7f0 — Compute aggregate AABB + bounding sphere

**Summary:** Recomputes this object's aggregate bounds over its children: resets the AABB (0x1E0..0x1F4) to +FLT_MAX/-FLT_MAX, fills it either by recursively merging child bounds (a4/recurse flag, list at 0x1B8) or by merging each positioned child's point (list at 0x1C4), or by delegating to a virtual collector (vtable slots +0x1C/+0x20 selected by a3), then derives the sphere center (AABB midpoint) and grows the bounding sphere to enclose both AABB corners.

**Called by:** sub_5BC7F0 (005bc7f0), sub_5BF410 (005bf410)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1C | R | — | vtable slot +0x1C (28); virtual collector variant invoked (this+480, a2) when a3==1 |
| obj | 0x20 | R | — | vtable slot +0x20 (32); virtual collector variant invoked when a3 is not 0 and not 1 |
| this | 0x0 | R | — | own vtable pointer, read to reach slots +0x1C/+0x20 |
| this | 0x1B0 | R | — | count of child list at 0x1B8 (recursion list) |
| this | 0x1B8 | R | — | pointer to child array (entries have own AABB at +480, own count at +544) |
| this | 0x1BC | R | — | count of positioned-child list at 0x1C4 |
| this | 0x1C4 | R | — | pointer to child array; each child's point stored at child+0x74..0x7C |
| this | 0x1E0 | RW | 2139095039 | AABB min X; init 0x7F7FFFFF (+FLT_MAX), then min-merged |
| this | 0x1E4 | RW | 2139095039 | AABB min Y; init +FLT_MAX, then min-merged |
| this | 0x1E8 | RW | 2139095039 | AABB min Z; init +FLT_MAX, then min-merged |
| this | 0x1EC | RW | 18446744073701163007 | AABB max X; init 0xFF7FFFFF (-FLT_MAX), then max-merged |
| this | 0x1F0 | RW | 18446744073701163007 | AABB max Y; init -FLT_MAX, then max-merged |
| this | 0x1F4 | RW | 18446744073701163007 | AABB max Z; init -FLT_MAX, then max-merged |
| this | 0x1F8 | RW | — | bounding-sphere center X = (minX+maxX)*0.5 |
| this | 0x1FC | RW | — | bounding-sphere center Y = (minY+maxY)*0.5 |
| this | 0x200 | RW | — | bounding-sphere center Z = (minZ+maxZ)*0.5 |
| this | 0x204 | RW | 0 | bounding-sphere radius; zeroed, then grown to cover both AABB corners |
| this | 0x208 | RW | 0 | cached squared radius; zeroed, then grown with radius |

**Written-by note (persistence):**
- this 0x1E0: reset to +FLT_MAX then rebuilt every call — external poke overwritten on next call.
- this 0x1E4: reset to +FLT_MAX then rebuilt every call — poke overwritten.
- this 0x1E8: reset to +FLT_MAX then rebuilt every call — poke overwritten.
- this 0x1EC: reset to -FLT_MAX then rebuilt every call — poke overwritten.
- this 0x1F0: reset to -FLT_MAX then rebuilt every call — poke overwritten.
- this 0x1F4: reset to -FLT_MAX then rebuilt every call — poke overwritten.
- this 0x1F8: recomputed every call from AABB center — poke overwritten.
- this 0x1FC: recomputed every call from AABB center — poke overwritten.
- this 0x200: recomputed every call from AABB center — poke overwritten.
- this 0x204: zeroed then grown every call — poke overwritten.
- this 0x208: zeroed then grown every call — poke overwritten.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f2378 | dbl_6F2378 | R | double constant 0.5 used to halve (min+max) into the sphere center |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005bc480 | sub_5BC480 | expand the AABB to include a point (per positioned child; both corners of list-B child AABBs) |
| 005bc5a0 | sub_5BC5A0 | grow the sphere to include a point (called with AABB min corner and max corner) |
| 005bc7f0 | sub_5BC7F0 | recursion over each list-0x1B8 child, with a2 clamped to that child's own index range |

**Guard conditions:** a3 selects the AABB source: `a3 != 0` → virtual call (this+480, a2): `a3 == 1` uses vtable+0x1C, any other nonzero uses vtable+0x20; `a3 == 0` → loop over this[111] (0x1BC) children, merging each child point at +0x74. `(_BYTE)a4 != 0` → loop over this[108] (0x1B0) children: a2 is clamped to [0, childCount(0x220)-1] (negative → 0, too large → childCount-1), then recurse and merge the child's AABB corners (+480 and +492). Only the low byte of a4 is tested.
