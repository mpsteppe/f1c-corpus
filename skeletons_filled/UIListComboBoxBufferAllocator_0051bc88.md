## UIListComboBoxBufferAllocator_0051bc88 — UIListComboBoxBufferAllocator

**Summary:** Allocates per-object 256-byte buffers initialized to zero, stores them at object+80, and initializes a dispatch state with FAILOverviewSaysFIRCrossfeedButDispatchesToIMDCT vtable.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_516C7B (00516c7b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | sub-allocator vtable entry 0 (allocation function) |
| *(this+0xC4) | 0x50 | RW | — | per-object field at +80, written with allocated 256-byte zeroed buffer |
| this | 0x4 | R | — | sub-allocator vtable pointer |
| this | 0x20 | R | — | number of objects to allocate buffers for |
| this | 0xC4 | R | — | pointer to array of object descriptors |
| this | 0x198 | RW | — | written with pointer to allocated 84-byte dispatch state |

**Written-by note (persistence):**
- *(this+0xC4) 0x50: once, per object; set to allocated buffer; survives external poke
- this 0x198: once, unconditional; set to dispatch state; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051bad1 | FAILOverviewSaysFIRCrossfeedButDispatchesToIMDCT | R | vtable entry 0 for dispatch state (audio processing dispatch) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | > | 0 | object count |

**Guard interpretation:** this->0x20 > 0 PASSES (allocates per-object 256-byte buffers). When <= 0, BLOCKED (skip per-object buffer allocation).
