## UIListComboBoxConstructor_0051a4f2 — UIListComboBoxConstructor

**Summary:** Allocates and initializes a rendering state buffer (116 bytes) with function pointers and per-object or flat buffer allocations, selecting between copy mode and compositing mode based on a2 parameter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_516C7B (00516c7b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | sub-allocator vtable entry 0 (116-byte state buffer alloc) |
| *(this+0x4) | 0x4 | R | — | sub-allocator vtable entry 1 (1280-byte flat buffer alloc for compositing mode) |
| *(this+0x4) | 0x14 | R | — | sub-allocator vtable entry 5 (per-object buffer alloc for copy mode) |
| *(this+0xC4) | 0xC | R | — | sprite object width used for alignment calculation |
| *(this+0xC4) | 0x1C | R | — | sprite object stride/row width (used with AlignUp) |
| *(this+0xC4) | 0x20 | R | — | sprite object field used for second AlignUp dimension |
| this | 0x4 | R | — | sub-allocator vtable pointer |
| this | 0x20 | R | — | number of sprite objects to process |
| this | 0xC4 | R | — | pointer to array of sprite object descriptors |
| this | 0xC8 | R | — | flag; if set, object width multiplied by 3 in copy mode |
| this | 0x184 | RW | — | written with pointer to allocated 116-byte state buffer |

**Written-by note (persistence):**
- this 0x184: once, unconditional (result of primary allocation); survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005199c5 | InitAndChain | R | vtable entry 0 (init and frame chain) |
| 005199d5 | CompositingPass | R | vtable entry 3 for compositing mode |
| 00519baf | sub_519BAF | R | vtable entry 1 for compositing mode |
| 00519bb2 | CompositingCopy | R | vtable entry 1 for copy mode |
| 00519d51 | DrawableObjectBatchProcessor | R | vtable entry 3 for copy mode |
| 0051a4b7 | ProtocolStateHandler | R | vtable entry 2 (state handler) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00515927 | AlignUp | rounds up dimensions to alignment boundaries before buffer allocation |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | > | 0 | sprite object count |

**Guard interpretation:** a2 != 0 enters copy mode (per-object buffer allocation loop when this->0x20 > 0). a2 == 0 enters compositing mode (flat 1280-byte buffer with 10 slots). Copy mode loop PASSES for each object when this->0x20 > 0; BLOCKED (skips allocation) if object count is zero.
