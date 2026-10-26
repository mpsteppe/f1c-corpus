## sub_5FDB90_005fdb90 — Render dispatch: upload, then flush or fill

**Summary:** Per-frame dispatcher for the element geometry: first runs the buffer upload (sub_5FC840); if that succeeds it branches on the 0x200 flag — set: bulk-copy the dirty data block via sub_5FD150; clear: run the full per-element fill via sub_5FCE80. Upload failure (-1) is returned directly.

**Called by:** sub_611020 (00611020)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Flag word; bit 0x200 selects the flush path (sub_5FD150) versus the full fill path (sub_5FCE80) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005fc840 | sub_5FC840 | One-shot upload of the element vertex/index buffers through the manager; returns -1 on buffer-operation failure |
| 005fce80 | sub_5FCE80 | Full per-frame element fill into the locked buffer (distance sort, transforms, blended vertex colors) |
| 005fd150 | sub_5FD150 | Bulk-copy flush of the dirty data block (this+0x60 → locked pointer) plus unlock |

**Guard conditions:** First gate: sub_5FC840's return value — if nonzero (-1, upload failure) the function returns it immediately and neither branch runs. Otherwise the flag `(*this & 0x200)`: set → sub_5FD150(a1, a5, a6) is returned (flush path); clear → sub_5FCE80(a1, a2, a4, a1, a5, a6) is returned (fill path). The chosen callee's own guards then apply.
