## NetworkReplayBufferInit_0045d260 — NetworkReplayBufferInit

**Summary:** Initializes replay/network buffer structure: stores session port, clears flag byte, XOR-decodes obfuscation key data into global buffers, then allocates a memory object for network encoding.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_463E20 (00463e20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | Active/initialized flag byte, cleared to 0 |
| this | 0x4 | RW | — | Session port low 16 bits (copied from word_7D0FE8) |
| this | 0x8 | RW | — | Session port low 16 bits (copied from word_7D0FE8 again) |
| this | 0xC | RW | — | Handle to allocated memory object from MemoryObjectAllocator |

**Written-by note (persistence):**
- this 0x0: once/init — set to 0 on call, survives until overwritten externally
- this 0x4: once/init — set from word_7D0FE8 on call, persists until changed
- this 0x8: once/init — set from word_7D0FE8 on call, persists until changed
- this 0xC: once/init — set from MemoryObjectAllocator result, persists until changed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0045d2d0 | sub_45D2D0 | R | Callback function for MemoryObjectAllocator (network encode/decode routine) |
| 0059f0c4 | byte_59F0C4 | R | ObfuscationSourceData [DERIVED] — source bytes for XOR key generation |
| 005c5b68 | off_5C5B68 | R | unknown |
| 007d0fe8 | word_7D0FE8 | R | SessionPortBase [DERIVED] (also: Global state (used via uint cast) |
| 008d4680 | dword_8D4680 | RW | NetworkEncodeBuffer [DERIVED] (also: 8c` — Global state buffer) |
| 008d4684 | dword_8D4684 | W | XORPadData [DERIVED] |
| 008d4688 | dword_8D4688 | W | NetworkSaltBuffer [DERIVED] |
| 008d468c | dword_8D468C | W | XORKey_NetworkAuth [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00562b50 | MemoryObjectAllocator | Allocates a memory object for the network encode buffer with callback sub_45D2D0 |

**Guard conditions:** none — no conditional branches; all fields written unconditionally.
