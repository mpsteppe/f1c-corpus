## sub_4E2FE0_004e2fe0 — draw scaled textured quad via renderer device

**Summary:** Renders a textured quad: it queries the current draw position and texture metrics through two sub_5EDB40 calls, computes horizontal/vertical extents from the globals at 00903EB8/00903EBC scaled by the passed parameters (a2, a3), and emits four corner vertices via sub_5EDF20 with the matching texture coordinates. All rendering goes through the device pointer stored at this+0x0; called from sub_4A0940.

**Called by:** sub_4A0940 (004a0940)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Renderer/device pointer (tested for null); passed as the first argument to every sub_5EDB40/sub_5EDF20 call |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f4dc8 | flt_6F4DC8 | R | Float global referenced by this function; exact consumption not visible in the decompiled body — unknown |
| 006f9500 | flt_6F9500 | R | Float global referenced by this function; exact consumption not visible in the decompiled body — unknown |
| 00903eb8 | dword_903EB8 | R | Integer base dimension: multiplied by 0.00125 (≈ ÷800) and by a2 to produce the quad's horizontal extent v12 |
| 00903ebc | dword_903EBC | R | Integer base dimension: multiplied by 0.0016666667 (≈ ÷600) and by a3 to produce the quad's vertical extent v10 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005edb40 | sub_5EDB40 | Query helper: call (device, 0, &v14, &v15, &v16, &v13, &v13, &a2) fetches the base position (v14,v15,v16); call (device, 2, &v17, &v18, &v19, &v11, &a3, &a2) fetches a float metric (v11) used as texture coordinate |
| 005edf20 | sub_5EDF20 | Vertex emit helper: called with (device, index 0..3, x, y, z, u, v, a2) to define the four textured-quad corners |

**Guard conditions:** Reads `v4 = *this` (device pointer at this+0x0): if NON-ZERO → PASSES into the full draw path (scaled extents computed, two queries, four vertex submissions). If ZERO → BLOCKED, no rendering happens and the function returns an uninitialized result value.
