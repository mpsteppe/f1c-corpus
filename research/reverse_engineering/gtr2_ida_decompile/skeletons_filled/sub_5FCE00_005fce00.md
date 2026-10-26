## sub_5FCE00_005fce00 — Mark queued record element dirty (write xyz + value fields)

**Summary:** Wider dirty-updater sibling of sub_5FCDB0: with flag 0x200 set and a valid record index, it locates the stride-132 queued record and, when flag 0x400 is set, writes three floats (a4, a5, a6) at element offsets +0/+4/+8 and the dword a7 at +24 of the record's data area, then sets the object's 0x80000 "needs re-upload" flag.

**Called by:** ParticleEffectBillboardQuadSetup [structural] (00542590), F_3DBoundingBoxRender [structural] (00542790), sub_544CF0 (00544cf0), sub_544F00 (00544f00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Flag word: 0x200 enables the update, 0x400 enables the data writes, 0x80000 is OR-set to signal pending re-upload |
| this | 0x2C | R | — | Capacity (this[11]); a2 must be below it |
| this | 0x34 | R | — | Base of the 132-byte record array (this[13]); record = base + 132*a2 |

**Written-by note (persistence):**
- this 0x0: 0x80000 is conditionally OR-set each qualifying call and never cleared here — it persists until an upload path clears it; remaining bits are read-only here, so external pokes to them survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Stacked gates, all required: `(*this & 0x200) != 0` and `a2 < this[11]`; then the record's `0x100` queued bit; then `(*this & 0x400) != 0` gates the four data writes (`v7[32] + (a3<<6)` receives a4/a5/a6 at +0/+4/+8 and a7 at +24). Flag 0x80000 is set whenever the 0x200/0x100 gates pass, regardless of 0x400. Failing any gate blocks the rest.
