## AudioSystemShutdown_00406e50 — Miles Audio System Shutdown / Cleanup

**Summary:** Tear-down function for the Miles Sound System (AIL) audio manager: iterates four internal linked lists of audio resources/components, calls virtual cleanup/release methods on each, frees all nodes, closes the wave output device, and calls AIL_shutdown to terminate the audio library. Guarded by an active-flag; does nothing if already shut down.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ComplexDestructorWith4LinkedLists (00406ba0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x18)+0x0) | 0x0 | R | — | audio-component object vtable pointer inside list-1 node (for virtual method dispatch) |
| *(*(this+0x8)+0x0) | 0x18 | R | — | vtable entry at offset 0x18 (virtual release/destroy) on each audio component |
| *(this+0x18) | 0x0 | R | — | audio-component object pointer (non-null guard) in linked-list-1 head node |
| *(this+0x1C) | 0x4 | R | — | unknown (read not visible in decompiled C — possibly assembly-level next-pointer field) |
| *(this+0x28) | 0x0 | R | — | nested audio-resource pointer (non-null guard) in linked-list-2 head node |
| *(this+0x2C) | 0x4 | R | — | unknown (read not visible in decompiled C) |
| *(this+0x3C) | 0x4 | R | — | unknown (read not visible in decompiled C) |
| *(this+0x8) | 0x0 | R | — | head pointer of primary audio-component linked list (vtable-iteration list) |
| obj | 0x34 | R | — | unknown (no explicit obj access in decompiled C — possibly imported library handle) |
| this | 0x0 | R | — | vtable pointer of audio-manager object (virtual method call at offset 52) |
| this | 0x8 | R | — | primary audio-component list head (copied to iterator) |
| this | 0x10 | RW | — | primary audio-component list iterator (list walk cursor) |
| this | 0x18 | RW | 0 | audio-resource linked-list 1 head (zeroed after free) |
| this | 0x1C | RW | 0 | audio-resource linked-list 1 tail (zeroed after free) |
| this | 0x20 | RW | 0 | audio-resource linked-list 2b head (zeroed during list-2 cleanup) |
| this | 0x24 | RW | 0 | audio-resource linked-list 2b tail (zeroed during list-2 cleanup) |
| this | 0x28 | RW | 0 | audio-resource linked-list 2 head (zeroed after free) |
| this | 0x2C | RW | 0 | audio-resource linked-list 2 tail (zeroed after free) |
| this | 0x30 | RW | 0 | audio-resource linked-list 3b head (zeroed during list-3 cleanup) |
| this | 0x34 | RW | 0 | audio-resource linked-list 3b tail (zeroed during list-3 cleanup) |
| this | 0x38 | RW | 0 | audio-resource linked-list 3 head (zeroed after multi-stage cleanup) |
| this | 0x3C | RW | 0 | audio-resource linked-list 3 tail (zeroed after multi-stage cleanup) |
| this | 0x40 | RW | 0 | audio-resource linked-list 3c head (zeroed during list-3 cleanup) |
| this | 0x44 | RW | 0 | audio-resource linked-list 3c tail (zeroed during list-3 cleanup) |
| this | 0x88 | RW | 0 | audio system active/running flag (read as gate; set to 0 after shutdown) |
| this | 0x90 | RW | 0 | AIL digital audio output device handle (HWAVE, closed via AIL_waveOutClose) |

**Written-by note (persistence):**
- this 0x10: written each iteration as list cursor — temporary, overwritten per-node
- this 0x18: written once on shutdown — external poke does NOT persist (final cleanup)
- this 0x1C: written once on shutdown — external poke does NOT persist (final cleanup)
- this 0x20: written once on shutdown — external poke does NOT persist (final cleanup)
- this 0x24: written once on shutdown — external poke does NOT persist (final cleanup)
- this 0x28: written once on shutdown — external poke does NOT persist (final cleanup)
- this 0x2C: written once on shutdown — external poke does NOT persist (final cleanup)
- this 0x30: written once on shutdown — external poke does NOT persist (final cleanup)
- this 0x34: written once on shutdown — external poke does NOT persist (final cleanup)
- this 0x38: written once on shutdown — external poke does NOT persist (final cleanup)
- this 0x3C: written once on shutdown — external poke does NOT persist (final cleanup)
- this 0x40: written once on shutdown — external poke does NOT persist (final cleanup)
- this 0x44: written once on shutdown — external poke does NOT persist (final cleanup)
- this 0x88: written once on shutdown — external poke does NOT persist (final cleanup)
- this 0x90: written once on shutdown — external poke does NOT persist (final cleanup)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e394 | __imp__AIL_shutdown@0 | R | imported AIL_shutdown — terminates the Miles Sound System library |
| 0059e3a4 | _AIL_waveOutClose@4 | R | imported AIL_waveOutClose — closes the digital audio output device handle |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00405410 | MultiStageCleanupWithFree | multi-stage cleanup + deallocation of nested audio resource object (list 3) |
| 00587bcf | FreeWrapper_7bcf | wrapper around memory deallocation (free-equivalent) for list nodes |

**Guard conditions:** Field `this[34]` (offset 0x88, audio-system active flag) controls execution:
- `this[34] == 0`: BLOCKED — entire function body skipped (system already shut down or never initialised).
- `this[34] != 0`: PASSES — four linked-list cleanup passes execute, then virtual vtable call at `(*this+52)(this, 0)`, then `AIL_waveOutClose`, then `AIL_shutdown()`, then flag zeroed.
- Within list-1 iteration: per-node flag `*(node+8)` must be non-zero AND `*node != 0` (component object pointer non-null) to call the virtual cleanup method.
- Within list-2 iteration: per-node flag `*(node+8)` must be non-zero AND `**node != 0` (nested pointer non-null) to free nested resources.
- Within list-3 iteration: per-node flag `*(node+8)` must be non-zero AND `*node != 0` to invoke `MultiStageCleanupWithFree`.

(End of file - total 72 lines)
