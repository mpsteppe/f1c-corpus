## F_3DPositionDeltaComputation_004faec0 — Compute3DPositionDelta

**Summary:** Computes 3D position delta between current-position pointer and stored reference, or between stored position and reference pointer. Falls back to (0, 0, -1.0f) when neither pointer is available.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_402690 (00402690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x10C) | 0x0 | R | — | current position X |
| *(this+0x10C) | 0x4 | R | — | current position Y |
| *(this+0x10C) | 0x8 | R | — | current position Z |
| *(this+0x110) | 0x0 | R | — | reference position X |
| *(this+0x110) | 0x4 | R | — | reference position Y |
| *(this+0x110) | 0x8 | R | — | reference position Z |
| this | 0x0 | R | — | stored reference/position X |
| this | 0xC | RW | 0 | output delta X |
| this | 0x10 | RW | 0 | output delta Y |
| this | 0x14 | RW | 18446744072627421184 → -1.0f | output delta Z |
| this | 0x10C | R | — | pointer to float[3] current position |
| this | 0x110 | R | — | pointer to float[3] reference position |

**Written-by note (persistence):**
- this 0xC: conditional — written both branches (delta X); external poke survives until next call
- this 0x10: conditional — written both branches (delta Y); external poke survives until next call
- this 0x14: conditional — written both branches (delta Z) or default -1.0f; external poke survives until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** *(this+0x10C) != NULL → compute delta = currentPosPtr - inlineRef (stored at +0x0/+0x4/+0x8). *(this+0x10C)==NULL AND *(this+0x110)!=NULL → compute delta = inlinePos (at +0x0/+0x4/+0x8) - refPosPtr. Both pointers NULL → set delta=(0.0, 0.0, -1.0f), skip arithmetic.
