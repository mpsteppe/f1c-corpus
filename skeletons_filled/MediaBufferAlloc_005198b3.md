## MediaBufferAlloc_005198b3 — MediaBufferAllocAndSetup

**Summary:** Allocates a media playback buffer (80 bytes), sets its vtable to PlaybackStateController, conditionally patches vtable entries, then fills frame buffer slots from sub-struct dimension data via VertexBufferOffsetSetup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_516C7B (00516c7b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x19C) | 0x8 | R | — | byte flag indicating audio buffer readiness |
| *(this+0x4) | 0x0 | R | — | sub-allocator vtable entry 0 (allocation function) |
| *(this+0x4) | 0x8 | R | — | sub-allocator vtable entry 2 (allocation function) |
| *(this+0xC4) | 0x24 | R | — | sub-struct width/stride field used in buffer size calc |
| obj | 0x0 | R | — | vtable/type tag of allocated buffer (set to PlaybackStateController) |
| obj | 0x14 | RW | 46 | vtable entry index 5, patched with 4 or 46 conditionally |
| this | 0x0 | R | — | main vtable pointer for dispatch |
| this | 0x4 | R | — | sub-allocator vtable pointer |
| this | 0x20 | R | — | count of sub-struct elements to process (loop bound) |
| this | 0xC4 | R | — | pointer to array of sub-structs (84 bytes each) |
| this | 0x114 | R | — | current count/state value, checked < 2 for dispatch condition |
| this | 0x180 | RW | — | written with allocated buffer pointer |
| this | 0x19C | R | — | pointer to audio buffer status struct |

**Written-by note (persistence):**
- obj 0x14: once, conditional (a2 || byte+8); set to 4 or 46 before dispatch; survives external poke
- this 0x180: once, unconditional (allocation result); survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051984b | PlaybackStateController | R | vtable/function pointer written as first field of allocated buffer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00519375 | VertexBufferOffsetSetup | sets up vertex buffer offsets after buffer allocation |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | > | 0 | count of sub-structs to process |
| this | 0x114 | < | 2 | current state count threshold for dispatch |

**Guard interpretation:** a2 == 0 and *(this->0x19C + 8) == 0 BLOCKS vtable patching (no dispatch). When byte at *(this->0x19C+8) is nonzero, this->0x114 < 2 must PASS to write 46 and dispatch through vtable. Loop body PASSES only when this->0x20 > 0 (element count positive).
