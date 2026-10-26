## sub_5FCE80_005fce80 — Per-frame fill of dynamic vertex buffer for queued elements

**Summary:** Runs when the list count is nonzero: extracts render-context values from a6 (sub_5E4D90), optionally computes view-relative angles (sub_5E4DA0) for flagged billboard/rotation modes, optionally computes per-element squared distances to v41 and sorts the list, locks the vertex buffer (sub_5FCA00), then for every queued element applies rotation to its matrix, transforms and exports its vertices into the locked buffer with blended per-vertex colors (alpha fade scaled by sub_600770(2)/sub_5FC610), unlocks the buffer when flagged, and finishes with a manager call (vtable+424).

**Called by:** sub_5FDB90 (005fdb90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x6C) | 0x4C | R | — | Write pointer (offset 76) inside the locked buffer object; base of the destination vertex area (advances by (v32<<6)) |
| this | 0x0 | RW | — | Flag word: 0x20 (billboard: computed angles zeroed), 0x10 (apply computed angles), 0x40 (compute distances + sort list), 0x30 (rotate elements), 0x100000 (buffer locked, cleared at the end) |
| this | 0x30 | R | — | List count (a1[12]) — main loop bound and the early-out value |
| this | 0x38 | R | — | List array of element pointers (a1[14]) — iteration source and sort target |
| this | 0x40 | R | — | Holder pointer (a1[16]) whose +44 slot is the buffer object |
| this | 0x44 | RW | 0 | Cached locked data pointer (a1[17]); checked as the fill-loop gate and zeroed on unlock |
| this | 0x4C | R | — | Vertex count per element (a1[19]); also the destination advance per element (v32 += a1[19]) |
| this | 0x50 | R | — | Source vertex template base (a1[20]); inner loop advances it by 64 bytes |
| this | 0x5C | R | — | Source template +12 (read and copied to destination +12) — per-vertex attribute |
| this | 0x60 | R | — | Source template +16 (copied to destination +16) |
| this | 0x64 | R | — | Source template +20 (copied to destination +20) |
| this | 0x68 | R | — | Source template +24 (read as v19, one input of the per-vertex color blend) |
| this | 0x6C | R | — | The locked buffer object (a1[16]+44) whose +76 write pointer receives the transformed vertices |
| this | 0x70 | R | — | Source template +32 (copied to destination +32) |
| this | 0x74 | R | — | Source template +36 (copied to destination +36) |

**Written-by note (persistence):**
- this 0x0: 0x100000 is conditionally AND-cleared only when it was set (after the unlock call); all other flag bits are read-only here. An external poke setting 0x100000 forces an unlock on the next nonempty-list call; pokes to the other bits survive.
- this 0x44: recalculated every call — sub_5FCA00 fills it with the locked pointer or 0, and it is zeroed again on unlock; external pokes do not survive a call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005fc620 | sub_5FC620 | R | Address-taken comparison routine (the float-key three-way comparator) associated with the element-list sort path; the distance stored at element+16 matches its compared field |
| 00fb27a4 | dword_FB27A4 | R | Global buffer/device manager: vtable+416 unlocks the buffer (with 4096, a3, a4) and vtable+424 is called at the end with (v8, a1) |
| 00fb27a8 | dword_FB27A8 | R | Manager-related global consumed within this routine's helper path; no direct load appears in the decompiled body |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d73c0 | sub_5D73C0 | Writes the negated orientation (-v31, -v34, -v30) into the element matrix at element+20 |
| 005d7810 | sub_5D7810 | Transforms one vertex from the source template (v16) into the destination (v17) using the element matrix region (v14+4) |
| 005d7980 | F_3DSquaredDistance [exact] | Computes the squared distance from element+92 to v41; result stored at element+16 as the sort key |
| 005d8400 | sub_5D8400 | Finalizes the element's matrix at +20 after the rotation update |
| 005e4d90 | sub_5E4D90 | Extracts render-context values from a6 into v42, v43 and v44 |
| 005e4da0 | sub_5E4DA0 | Computes orientation angles from a6 into v31/v34/v30 (then zeroed for flag 0x20) |
| 005fc610 | sub_5FC610 | Truncates the alpha fade value (HIBYTE(color1) * v39) to a 16-bit factor for the color blend |
| 005fca00 | sub_5FCA00 | Locks/fills the first buffer and caches its write pointer into a1[17] |
| 00600770 | sub_600770 | Query returning a float (argument 2) used as the fade scale v39 for the vertex-color blend |
| 00632c60 | sub_632C60 | Processes the element list (array this[0x38], count a1[12]) after distances are computed — the sort step using the +16 distance keys |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x30 | <= | 0 | List count (a1[12]); zero means nothing to render — function returns the count immediately |

**Guard interpretation:** The whole body is BLOCKED when the count at this+0x30 is 0 (returns the 0 immediately). Within the body: flag 0x20 selects billboard mode (angles v30/v31 zeroed after sub_5E4DA0), else flag 0x10 selects applying the computed angles; flag 0x40 enables the per-element distance computation and the list sort; the fill stage runs only if sub_5FCA00 left a non-null locked pointer at this+0x44 (a1[17]); flag 0x30 gates the per-element rotation call; each element's 0x40000 bit gates propagation of flag 2 into its matrix block (element+20); loops are bounded by the list count and by the per-element vertex count (a1[19]); flag 0x100000 gates the unlock call and is cleared only if it was set; the function's final return value is the manager vtable+424 call (dword_FB27A4, v8, a1).
