## sub_6CD4DC_006cd4dc — Refine object ordering window (local search)

**Summary:** Windowed local-search pass over the object order list (+0x3C, size +0x38): starting at index a2 it scans neighbouring entries (grow right if the running balance sum is positive, left if negative), copies the related-index lists of candidate objects into the temp buffer (+0x18) and marks visited objects with the current round counter (+0x48), accepts a candidate window only while chain membership through world array +0x14 stays consistent and the recomputed metrics improved, and on convergence restores the list from backup (+0x40) and recomputes offsets via sub_6CD3BF. Returns 1 on success, 0 when a candidate is rejected by the metric comparison.

**Called by:** sub_6CD96E (006cd96e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x0 | R | — | first element of the working object-id buffer (walked while scanning set members) |
| *(this+0x18) | 0x0 | R | — | first element of the temp object-id buffer (walked while adjusting flags) |
| *(this+0x4) | 0x14 | R | — | world array of chain/list records; each record has +0x14 next index and +0x18 value, walked to test chain membership |
| *(this+0x4) | 0x18 | R | — | world array of object records, indexed by object id (object fields +0x24/+0x30 timestamps, +0x54 flag, +0x74 id) |
| this | 0x4 | R | — | pointer to shared world/context struct |
| this | 0x8 | R | — | per-object count for the object's index list |
| this | 0xC | R | — | per-object start index into the index array at +0x10 |
| this | 0x10 | R | — | index array holding per-object related object indices (copied into buffers) |
| this | 0x14 | R/W | — | working buffer of object ids for the current set |
| this | 0x18 | R/W | — | temporary buffer of collected object ids |
| this | 0x28 | R | — | per-object balance counter, summed over ranges into v87/v81 |
| this | 0x34 | R | — | per-object processed flag; non-zero for a2 makes the function return 1 immediately |
| this | 0x38 | R | — | size of the object order list |
| this | 0x3C | R/W | — | object order list (patched from backup on convergence) |
| this | 0x40 | R | — | backup copy of the object order list, restored on LABEL_84 |
| this | 0x48 | R/W | — | round/visit counter incremented per pass and stamped into object fields |
| this | 0x4C | R | — | best (largest) per-object max metric kept from previous accepted state |
| this | 0x50 | R | — | best total metric kept from previous accepted state |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006cd2ce | sub_6CD2CE | range operation on the ordering state over [start,end) — tried before the metric comparison (details not visible here) |
| 006cd379 | sub_6CD379 | sorts/compacts an object-id buffer given pointer + count by reference (used on +0x14 and +0x18 buffers) |
| 006cd3bf | sub_6CD3BF | recomputes per-object offsets (+0x2C) and balance counters (+0x28) and returns totals (v73 total, v68 max) |

**Guard conditions:** if the per-object flag `*(this+0x34)[v3]` is already non-zero at entry, the whole body is skipped and 1 is returned. Inside the scan: probing stops when index `v39 >= *(this+0x38)` (list size). A candidate object whose chain head is not found in the walked +0x14 chain (`v79 != -1` after the walk) or whose chain value differs (`v75 != v30`) jumps to LABEL_84 → restore backup and return 1. The scan loop also stops when the candidate's chain pair is unchanged. `v87 == 0` (perfect balance), or `v86 >= v89` (empty captured window) → LABEL_84 → return 1. When `v82 == 0` the metric check runs: new total v73 < stored +0x50 with new max v68 <= stored +0x4C, or v73 <= +0x50 with v68 < +0x4C (equal total, smaller max) → return 0; otherwise the window is shifted (`m/v85 += |v89-v86|`) and the pass restarts at LABEL_3.
