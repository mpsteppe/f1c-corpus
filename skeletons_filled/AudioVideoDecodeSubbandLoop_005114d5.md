## AudioVideoDecodeSubbandLoop_005114d5 — JPEG restart marker scanner

**Summary:** Scans JPEG markers to find the expected restart (RST) marker relative to a reference counter. Classifies markers into three categories: v5=1 (expected RST found, break), v5=2 (unexpected or <192, skip and read next), v5=3 (acceptable non-RST marker, return). Dispatches states 117 and 96 per iteration.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | second vtable entry for parameterized dispatch (states 117, 96) |
| obj | 0x14 | RW | 96 | state code — 117 (initial), 96 (per-iteration classification) |
| obj | 0x18 | RW | — | current marker byte value |
| obj | 0x1C | RW | — | marker category (1=expected RST, 2=skip, 3=acceptable stop) |
| this | 0x0 | R | — | pointer to state dispatcher object |
| this | 0x178 | RW | 0 | current marker byte — read initially, updated via BitstreamTokenReader |

**Written-by note (persistence):**
- obj 0x14: written to 117 then repeatedly to 96 in loop
- obj 0x18: written with current marker each iteration
- obj 0x1C: written with category classification
- this 0x178: reset to 0 when category 1 marker found; left with value for category 3

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005110fc | BitstreamTokenReader | reads next marker from byte-stuffed stream when marker needs skipping |

**Guard conditions:** Marker classification tree: marker < 192 → category 2 (skip). Marker in 208-215 range: checked against expected RST offsets from a2. Matches within +1 or +2 → category 3 (acceptable). Matches within -1 or -2 → category 2 (skip). All others in 208-215 → category 1 (expected). Non-RST markers 192-207, 216+ → category 3 (acceptable stop, don't consume).
