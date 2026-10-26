## AudioEngineInitialization_00546010 — AudioEngineInitialization

**Summary:** Initializes the audio engine: allocates audio buffers via system callback, creates an audio mixer channel, allocates vertex buffer resources, and walks the audio node linked list to initialize each node's processing pipeline.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CUBESceneLoaderEntry (0048e8d0), VidMan_Init (004fa320)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x100)+0x104) | 0x104 | R | — | audio node linked list next pointer (traversed in init loop) |
| *(obj+0x110) | 0x14 | R | — | audio sample data size field 1 (for total size accumulation) |
| *(obj+0x110) | 0x18 | R | — | audio sample data size field 2 |
| *(obj+0x110) | 0x1C | R | — | audio sample data size field 3 |
| *(obj+0x110) | 0x20 | R | — | audio sample data size field 4 |
| obj | 0xEC | RW | — | audio channel flags (OR'd with a3 parameter) |
| obj | 0x100 | R | — | audio node linked list head pointer |
| obj | 0x110 | R | — | pointer to audio sample data block |
| this | 0x0 | RW | 0 | output: pointer to created audio mixer channel object |

**Written-by note (persistence):**
- obj 0xEC: written once on init (flags OR'd); external poke persists until next init call
- this 0x0: written once with allocated object pointer; external poke persists until next init call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e238 | InterlockedIncrement | R | atomic increment function pointer for thread-safe counter |
| 008b8ee8 | dword_8B8EE8 | RW | AudioBufferSize [DERIVED] |
| 008b8eec | Addend | RW | AudioHalfBufferSize [DERIVED] (also: ` — half buffer size) |
| 008b8ef0 | dword_8B8EF0 | W | AudioBufferDataPtr [DERIVED] (also: ` — buffer pointer/reference) |
| 008b8ef4 | dword_8B8EF4 | W | TotalAudioSampleDataSize [DERIVED] (also: ` — total sample data size) |
| 008b8ef8 | dword_8B8EF8 | RW | AudioBufferReadyCounter [DERIVED] (also: ` — buffer ready counter) |
| 008b8f00 | dword_8B8F00 | R | AudioSystemCallback [DERIVED] |
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053ac70 | EmptyStubWithFlagCheck | set audio engine state flag (enable/disable) |
| 0053c5d0 | LinkedListAppend_c5d0 | append audio channel to global linked list |
| 0053c630 | DoublyLinkedListUnlink | remove audio channel from linked list (on error) |
| 005435d0 | AudioMixerChannelInitializer | construct and initialize audio mixer channel object |
| 00543a80 | MemoryAllocationWithFallback | allocate memory for audio sample buffers |
| 00543fa0 | VertexBufferResourceAllocation | allocate vertex buffer resources for audio visualization |
| 00545f50 | AudioVolumeLoadComputation | compute audio volume from buffer load level |
| 00549170 | ArithmeticComparison_9170 | arithmetic comparison/processing on audio node |
| 005492b0 | LinkedListWalkWithDispatch | walk linked list with dispatch callback |
| 00549380 | LinkedListUpdate | update linked list state |
| 00549440 | AudioNodeUpdateWalk | traverse and update audio node processing |
| 00549470 | sub_549470 | additional audio node update step |
| 0055b8c0 | sub_55B8C0 | query audio system for buffer size via callback |
| 00587c03 | OperatorNewNhMallocWrapper | allocate 496 bytes for audio mixer channel |

**Guard conditions:** 
- If dword_8B8F00 (audio system callback) is non-null and sub_55B8C0 returns 0, the callback is invoked with (16, 0) to signal an error/init state to the audio system.
- If MemoryAllocationWithFallback fails (non-zero return), the audio channel is unlinked and function returns -1 (BLOCKED — initialization aborted).
- If VertexBufferResourceAllocation fails (non-zero return), the audio channel is unlinked, pointer zeroed, returns -1 (BLOCKED).
- Audio node linked list traversal continues while the `next` pointer is non-null; when null, loop ends.
