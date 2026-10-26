## VertexBufferResourceAllocation_00543fa0 — VertexBufferSetupAndAllocate

**Summary:** Allocates and configures D3D vertex buffers for scene graph rendering — frees old buffers, allocates new draw-element arrays, categorizes elements by render-state flags into four buckets, and sets up per-element vertex format descriptors (type, stride, texture flags) for each draw batch.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitCrewAnimationLoader (004a2a90), sub_4D0110 (004d0110), VehicleGraphicsSceneLoader (004dfce0), AudioEngineInitialization (00546010), sub_559200 (00559200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x154) | 0x4C | R | — | Bucket size copied from sub-struct (this[68]->field at +0x14 / element 5) |
| *(this+0x204) | 0xEC | R | — | Master flags field (this[59]) — bit 2 (0x4) gates linked-list cleanup and UI iteration |
| *(this+0x204) | 0x104 | R | — | Additional count field from sub-struct (this[68]->field at +0x20 / element 8) |
| this | 0x44 | RW | — | Copied bucket 0 count (from sub-struct field 5) |
| this | 0x48 | RW | — | Copied bucket 1 count (from sub-struct field 6) |
| this | 0x4C | RW | — | Copied bucket 2 count (from sub-struct field 7) |
| this | 0x50 | RW | — | Copied bucket 3 count (from sub-struct field 8) |
| this | 0x64 | R | — | Number of vertex buffer elements to allocate (this[25]) |
| this | 0xEC | R | — | Flags field — checked for bit flags 0x20, 0x100, 0x800, 0x40 to determine bucket and vertex format |
| this | 0x100 | R | — | Pointer to scene graph element linked list head (this[64]) |
| this | 0x108 | R | — | Audio/graph draw element list head pointer (this[66]) |
| this | 0x110 | R | — | Pointer to the sub-struct containing draw element arrays (this[68]) |
| this | 0x124 | R | — | Index used by sub_548850 to iterate elements |
| this | 0x128 | R | — | Unknown index/counter field |
| this | 0x12C | R | — | Unknown index/counter field |
| this | 0x130 | R | — | Unknown index/counter field |
| this | 0x14C | RW | 0 | Bucket 0 draw-element array pointer (allocated 528 bytes per element) |
| this | 0x150 | RW | 0 | Current vertex buffer element array (freed and reallocated, 24 bytes per element) |
| this | 0x1B4 | RW | 0 | Bucket 0 draw-element array pointer (duplicate/alternate) |
| this | 0x1B8 | RW | 0 | Bucket 0 element count |
| this | 0x1BC | RW | 0 | Bucket 1 draw-element array pointer |
| this | 0x1C0 | RW | 0 | Bucket 1 element count |
| this | 0x1C4 | RW | 0 | Bucket 2 draw-element array pointer |
| this | 0x1C8 | RW | 0 | Bucket 2 element count |
| this | 0x1CC | RW | 0 | Bucket 3 draw-element array pointer |
| this | 0x1D0 | RW | 0 | Bucket 3 element count |

**Written-by note (persistence):**
- this 0x44: Once per allocation cycle — copied from sub-struct; survives across frames until next alloc
- this 0x48: Once per allocation cycle — copied from sub-struct; survives across frames
- this 0x4C: Once per allocation cycle — copied from sub-struct; survives across frames
- this 0x50: Once per allocation cycle — copied from sub-struct; survives across frames
- this 0x14C: Once per allocation cycle — allocated fresh; external poke would be overwritten next alloc
- this 0x150: Once per allocation cycle — freed then reallocated; external poke overwritten
- this 0x1B4: Once per allocation cycle — set during bucket distribution; external poke overwritten
- this 0x1B8: Once per allocation cycle — computed from distribution; external poke overwritten
- this 0x1BC: Once per allocation cycle — set during bucket distribution; external poke overwritten
- this 0x1C0: Once per allocation cycle — computed from distribution; external poke overwritten
- this 0x1C4: Once per allocation cycle — set during bucket distribution; external poke overwritten
- this 0x1C8: Once per allocation cycle — computed from distribution; external poke overwritten
- this 0x1CC: Once per allocation cycle — set during bucket distribution; external poke overwritten
- this 0x1D0: Once per allocation cycle — computed from distribution; external poke overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00544720 | jpt_5445A4 | R | Jump table for switch dispatch on vertex format type (cases 1-7) |
| 0059e234 | InterlockedDecrement | R | Thread-safe atomic decrement for audio half-buffer synchronization |
| 00800000 | unk_800000 | R | MMXFlag [DERIVED] |
| 00804000 | unk_804000 | R | D3D_VertexBuffer_State [DERIVED] |
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |
| 008b8eec | Addend | R | AudioHalfBufferSize [DERIVED] (also: ` — half buffer size) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486720 | ShortComputation_6720 | Compute per-element sub-count (number of draw primitives/vertices) from element data |
| 004b0170 | EmptyStub_0170 | No-op cleanup stub called per old vertex buffer element before freeing |
| 0053c9c0 | BitFlagArrayUpdate | Update global bit flag array after all vertex buffers are configured |
| 0053ced0 | DoublyLinkedListNodeRemovalByFlag | Remove nodes from a doubly-linked list matching a flag condition |
| 005414e0 | Field0x13B0Accessor | Access field at sound manager offset 0x13B0 (audio channel count or mode) |
| 00544740 | sub_544740 | Additional render state setup — returns error code if fails |
| 00544d30 | AudioNetworkTreeWalker | Walk audio network tree for a draw element (returns status) |
| 00545a10 | UILinkedListCleanupIterator | Iterate and clean up UI-linked list entries |
| 00545a40 | sub_545A40 | Additional scene/render state processing |
| 00545bb0 | SceneInstanceCollection | Collect and process scene instances |
| 00545f50 | AudioVolumeLoadComputation | Compute audio volume load (called every other iteration) |
| 005487a0 | LinkedListWalkInterlockedDec | Walk linked list with interlocked decrement — returns error on failure |
| 00548810 | LinkedListAccumulation | Accumulate values from linked list nodes |
| 00548850 | sub_548850 | Get next draw element to process from the global element pool |
| 00548e00 | ShortComputation_8e00 | Initialize a vertex buffer element structure (6 DWORDs, 24 bytes) |
| 0054bd30 | SceneGraphRenderWalk | Walk scene graph for rendering — called for each element with non-zero field at +0xEC (236) |
| 00557240 | sub_557240 | Initialize a draw element array entry (528 bytes, 132 DWORDs) |
| 00557280 | CleanupFunction | Clean up an individual draw element entry before freeing its array |
| 00587bcf | FreeWrapper_7bcf | Free allocated memory (old vertex buffer arrays, draw element arrays) |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate memory for vertex buffer elements (24 bytes each) and draw element arrays (528 bytes each) |

**Guard conditions:**
- `this[84] != 0` (offset 0x150): Free old vertex buffer data. PASSES when previous allocation exists — iterates all elements calling `EmptyStub_0170`, then frees entire block. BLOCKED when no old data — skips.
- `(this[59] & 4) == 0` (offset 0xEC bit 2 clear): Run linked list cleanup and UI processing. PASSES when the skip flag is not set — calls `LinkedListWalkInterlockedDec`, `LinkedListAccumulation`, `sub_544740`, `UILinkedListCleanupIterator`, `sub_545A40`, `SceneInstanceCollection`. BLOCKED when bit 2 is set — skips all cleanup.
- `this[66] != 0` (offset 0x108): Audio network processing. PASSES — walks audio tree, interleaves `InterlockedDecrement` and `AudioVolumeLoadComputation` every other iteration. Returns -1 on `AudioNetworkTreeWalker` failure.
- Bucket distribution (per-element loop): Each element from `sub_548850` is categorized by flags at `v46[39]`:
  - `(flags & 0x20) && (flags & 0x100)` → bucket 2 (alpha + texture)
  - `(flags & 0x20) && !(flags & 0x100)` → bucket 3 (alpha only)
  - `!(flags & 0x20) && (flags & 0x100)` → bucket 0 (texture only)
  - `!(flags & 0x20) && !(flags & 0x100)` → bucket 1 (neither)
  Each element assigned to a bucket, increments bucket counter.
- `v49 > 0` (sub-count from ShortComputation_6720): PASSES — allocates 16-byte sub-array, enters per-sub-element vertex format setup loop. BLOCKED (v49 == 0) — skips to next element.
- D3D buffer address checks during vertex format setup:
  - `v54 <= &unk_800000`: PASSES — buffer below MMX region, falls through to `v54 == &unk_800000` check (LABEL_101: sets type=8, stride=1).
  - `v54 == &unk_804000`: PASSES — D3D vertex buffer state marker (LABEL_101: same type=8, stride=1).
  - `v54 == 0x100000`: Sound/audio buffer — checks `Field0x13B0Accessor(dword_8B78A0)` modulo, then switch on `*(v52+36)` (cases 1-7) to set vertex format type (1-11) and stride (2 or 4). Special case: if `v55 > 0 && v55 % field == 0`, uses type=1, stride=2 unconditionally.
  - `v54 == 0x400000`: Sets `*v48 |= 0x800`, type=2, stride=2.
- After address dispatch, post-checks (LABEL_102):
  - `(flags & 0x800)`: Sets `*v48 |= 4` (vertex buffer flag).
  - `(flags & 0x40)`: Sets `*v48 |= 0x400`.
  - `(*(byte*)v52 & 0xC) != 0`: Sets `v53[3] = 1`.
  - `(flags & 0x20)`: Sets `*v48 |= 0x800`, `*v53 = 2`.
  - `*(char*)v52 < 0`: Sets `*v48 |= 1`, `*v53 = 3`.
  - `(*(dword*)v52 & 0x200)`: Sets `*(v53-1) = 6`.
  - `(*(dword*)v52 & 0x400)`: `v53[4] = 1`. Else `(*(dword*)v52 & 0x1000)`: `v53[4] = 2`. Else 0.
  - `(*(dword*)v52 & 0x800)`: `v53[5] = 1`. Else `(*(dword*)v52 & 0x2000)`: `v53[5] = 2`. Else 0.
- Loop bound: `v56 < v66` (total draw elements across all buckets). PASSES while elements remain; exits when all processed.