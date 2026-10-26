## AudioVoiceChannelAllocation_00515bb0 — Audio Voice Channel Allocator

**Summary:** Allocates voice channels for PCM audio streams: computes per-stream voice counts, buffer alignments, and sample counts using ceiling division for format negotiation. Handles single-stream (direct copy) and multi-stream (iterative allocation) cases with a hard cap of 10 total voice slots. Part of the audio/voice management system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VtableDelegateDispatch (00515db8)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x124) | 0x8 | R | — | block alignment / bytes per sample frame (read from stream descriptor) |
| *(this+0x124) | 0xC | R | — | channel count per stream (descriptor field, used for voice allocation) |
| *(this+0x124) | 0x1C | R | — | buffer size in bytes (descriptor field v2[7]) |
| *(this+0x124) | 0x20 | R | — | sample count / buffer length (descriptor field v2[8]) |
| *(this+0x124) | 0x24 | R | — | buffer multiplier factor (descriptor field v2[9], scaled with block align) |
| *(this+0x124) | 0x34 | RW | — | allocated block alignment (set to stream's bytes-per-frame value) |
| *(this+0x124) | 0x38 | RW | — | allocated channel count (set to stream's channel count) |
| *(this+0x124) | 0x3C | RW | — | allocated voice count (block_align × channels = voices needed for this stream) |
| *(this+0x124) | 0x40 | RW | — | allocated buffer size value (set to v2[9] or scaled block_align × v2[9]) |
| *(this+0x124) | 0x44 | RW | — | modulo alignment value (sample_count % block_align, floored to block_align if zero) |
| *(this+0x124) | 0x48 | RW | — | modulo alignment value (buffer_size % block_align, floored to block_align if zero) |
| obj | 0x0 | R | — | vtable/error-handler function pointer (called on allocation failure) |
| obj | 0x14 | RW | 11 | error code slot (set to 24 for invalid stream count, 11 for voice overflow) |
| obj | 0x18 | RW | — | error parameter slot (stores the invalid stream count on error) |
| obj | 0x1C | RW | 4 | error severity/type slot (set to 4 on invalid count error) |
| this | 0x0 | R | — | pointer to vtable/error dispatch object (dereferenced for error callback) |
| this | 0x18 | R | — | format parameter numerator (used in CeilingDivision for voice channel count) |
| this | 0x1C | R | — | format parameter numerator (used in CeilingDivision for sample count) |
| this | 0x10C | R | — | format parameter denominator multiplier (used in CeilingDivision: 8 × this value) |
| this | 0x110 | R | — | format parameter denominator multiplier (used in CeilingDivision: 8 × this value) |
| this | 0x120 | R | — | audio stream count (number of PCM streams to allocate; valid range 1-4) |
| this | 0x124 | R | — | pointer to array of stream descriptor structs (one per stream) |
| this | 0x130 | R | — | unknown (not directly accessed in visible decompiled code) |
| this | 0x134 | RW | — | computed total voice channel count (from CeilingDivision or stream descriptor) |
| this | 0x138 | RW | — | computed sample count per voice (from CeilingDivision or stream descriptor) |
| this | 0x13C | RW | 0 | total allocated voice slot count accumulator (starts at 1 for single-stream, 0 for multi) |
| this | 0x140 | RW | 0 | voice allocation index array base (filled with stream indices per voice slot) |
| this | 0x144 | R | — | voice slot array entry (index 1 region of the allocation array) |
| this | 0x148 | R | — | voice slot array entry (index 2 region) |
| this | 0x158 | RW | 1 | voice slot entry with default value 1 (pre-initialized or fallback slot) |
| this | 0x15C | RW | 1 | voice slot entry with default value 1 |
| this | 0x160 | RW | 1 | voice slot entry with default value 1 |
| this | 0x164 | RW | — | voice slot entry (variable init, part of allocation array tail) |
| this | 0x168 | RW | 1 | voice slot entry with default value 1 |
| this | 0x16C | RW | — | voice slot entry (variable init, last slot in allocation array) |

**Written-by note (persistence):**
- *(this+0x124) 0x34: written once per allocation call — external poke does NOT survive next allocation
- *(this+0x124) 0x38: written once per allocation call — external poke does NOT survive next allocation
- *(this+0x124) 0x3C: written once per allocation call — external poke does NOT survive next allocation
- *(this+0x124) 0x40: written once per allocation call — external poke does NOT survive next allocation
- *(this+0x124) 0x44: written once per allocation call — external poke does NOT survive next allocation
- *(this+0x124) 0x48: written once per allocation call — external poke does NOT survive next allocation
- obj 0x14: written only on error path — external poke persists until next error
- obj 0x18: written only on error path — external poke persists until next error
- obj 0x1C: written only on error path — external poke persists until next error
- this 0x134: written once per allocation call — external poke does NOT survive next allocation
- this 0x138: written once per allocation call — external poke does NOT survive next allocation
- this 0x13C: written once per allocation call — external poke does NOT survive next allocation
- this 0x140: written once per allocation call (array fill) — external poke does NOT survive next allocation
- this 0x158: written once per allocation call (part of index array) — external poke does NOT survive next allocation
- this 0x15C: written once per allocation call — external poke does NOT survive next allocation
- this 0x160: written once per allocation call — external poke does NOT survive next allocation
- this 0x164: written once per allocation call — external poke does NOT survive next allocation
- this 0x168: written once per allocation call — external poke does NOT survive next allocation
- this 0x16C: written once per allocation call — external poke does NOT survive next allocation

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00515917 | CeilingDivision | computes ceiling integer division: (numerator + denominator - 1) / denominator, used for voice/sample count calculation |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x120 | <= | 0 | audio stream count valid-range lower bound check (combined with > 4 for upper bound) |

**Guard interpretation:** Stream count (this+0x120) must be 1 through 4 inclusive. Count == 1 triggers single-stream allocation: directly copies buffer/channel values from the stream descriptor at *(this+0x124), sets voice slot count to 1, initializes alignment values in descriptor fields. Count 2-4 triggers multi-stream allocation: iterates each stream descriptor, computes per-stream voice allocations via CeilingDivision and alignment math (modulo floored to block align), fills voice index array (this+0x140 onwards) with stream index per slot, and enforces hard cap of 10 total voice slots — exceeding 10 triggers error handler with code 11 on the vtable dispatch at *this. Count <= 0 or > 4 triggers error handler with code 24, passing the invalid count and severity 4. The vtable dispatch `(*(void (**)(int*))*a1)(a1)` is called on both error paths.
