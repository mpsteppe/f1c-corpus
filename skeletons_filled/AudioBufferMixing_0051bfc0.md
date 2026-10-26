## AudioBufferMixing_0051bfc0 — Audio channel mixing flush and copy

**Summary:** Mixes audio by flushing accumulated channel data when buffer is full, then copying the next block of samples to output. Iterates over active channels via virtual dispatch, clamps copy size by remaining data and output space, and updates consumed/remaining counters.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | R | — | Active channel count — loop bound for flushing each channel |
| this | 0xC4 | R | — | Base offet/address for channel data, incremented by 0x54 (84) per channel |
| this | 0x110 | R | — | Total buffer size — compared against consumed count for flush trigger |
| this | 0x19C | R | — | Pointer to mixing state sub-struct (v8) |
| this | 0x1A0 | R | — | Pointer to function table for channel mixing dispatch |
| this | 0x1A4 | R | — | Not directly accessed in this function; part of shared struct layout |
| this | 0x1D0 | R | — | Not directly accessed in this function; part of shared struct layout |
| this | 0x1F8 | RW | 0 | Consumed sample count — accumulates across calls, reset to 0 after flush |
| this | 0x1FC | RW | — | Remaining sample count — decremented as samples are copied out |
| this | 0x200 | R | — | Sub-struct field used in address computation for copy source |

**Written-by note (persistence):**
- this 0x1F8: Accumulated consumed count. Reset to 0 when >= total size (flush trigger). Survives external pokes between calls.
- this 0x1FC: Remaining count, decremented each call. External pokes survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | > | 0 | a1[8] — channel count. Must be >0 to enter the per-channel flush loop. |

**Guard interpretation:** Guard at `*(v8+92) >= a1[68]` (line 12): if consumed count >= total buffer size, flush all channels by iterating loop (bound by a1[8]>0), then reset consumed=0. If consumed < total, skip flush. Clamping guards: limit copy to min(available samples `a1[68]-consumed`, remaining `v8[96]`, output space `a7-*a6`). Final guard (line 50): after copy, if consumed >= total, increment the buffer pointer `*a3`.
