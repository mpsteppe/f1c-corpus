## PlaybackBufferAlloc_0051bf23 — Audio playback buffer allocation

**Summary:** Allocates and initializes the ring buffer sub-struct for audio playback. Creates a 28-byte control block, sets SoundEffectStateCallback as the state handler, and conditionally allocates the audio data buffer (read or write variant based on flag a2).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_516C7B (00516c7b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | Vtable method at [0]: memory allocator (size=28, type=1) |
| *(this+0x4) | 0x8 | R | — | Vtable method at [2]: alternate buffer allocator (used when a2==0) |
| *(this+0x4) | 0x10 | R | — | Vtable method at [4]: primary buffer allocator (used when a2!=0) |
| this | 0x4 | R | — | Vtable pointer — dispatch table for allocation methods |
| this | 0x4A | R | — | Flag byte — if non-zero, perform buffer allocation setup |
| this | 0x5C | R | — | Buffer dimension (width/channels), multiplied with offset 0x64 for total size |
| this | 0x60 | R | — | Value passed to AlignUp for buffer alignment calculation |
| this | 0x64 | R | — | Buffer dimension (height/sample count), multiplied with offset 0x5C |
| this | 0x110 | R | — | Alignment requirement — stored in sub-struct[4] and passed to allocator |
| this | 0x188 | RW | — | Sub-struct pointer (v3/ring buffer control block) — written once |

**Written-by note (persistence):**
- this 0x188: Written once with allocation result. Fixed pointer for lifetime. Survives external pokes.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051be7d | SoundEffectStateCallback | R | State callback function pointer — stored as sub-struct[0] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00515927 | AlignUp | Aligns buffer size to required alignment boundary |

**Guard conditions:** Guard at byte flag `*(this+0x4A)` (line 16): if non-zero, proceed with full buffer allocation (read v4 from offset 0x110, set sub-struct[4], allocate data buffer). If zero, skip entire allocation block — sub-struct entries 2, 3, 4 remain null/zero.
