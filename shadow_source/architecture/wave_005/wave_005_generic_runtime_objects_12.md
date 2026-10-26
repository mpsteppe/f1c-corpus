# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Proposal for the generic_runtime_objects scope: 23 functions clustered by shared this-field usage, shared callees, and shared callers into an event-message list queue (MessageEventQueue, three methods all reached from sub_4B9000), a sorted overlay display list (SpriteOverlayDisplayList, five methods sharing head/tail/cursor/count/dirty fields at 0x6C0-0x6D0 and the float key at 0xF38), a pit-stall ring buffer (PitStallRingBuffer), a dual linked object list with generated value sub-lists (DualLinkedObjectList, stride variants 432/1016/12), and several small stateful helpers. Class boundaries are GUESS synthesis over evidence; every named field is a DERIVED interpretation of an evidenced offset. The packet marks only two owners as DERIVED (SpriteOverlayDisplayList for 0x004B81A0, SessionStateObject for 0x004BB8E0); all other owners are UnknownObject in the IR.

## Function roles

- `0x004B54A0` **MessageEventQueue** — Validates a singly-linked list by walking it from head (this+0x20) through the cursor (this+0x28), accepting each node's first dword via FloatComparisonCheck (0x005001F0); returns 1 on empty/zero/end/invalid-node paths, 0 when the check rejects a node value.
- `0x004B54E0` **MessageEventQueue** — Dispatches a network message (a2) into the message list object: extracts a 6-bit type (bits 18..23) and a flag byte (a2+8), walks the active list (head 0x20, cursor 0x28) for an existing node matching type (+0x368) and flag (+0x36C), otherwise reuses a free-list node (0x10, removed via DoublyLinkedListNodeRemoval 0x004BA7A0) or allocates+constructs a fresh one (OperatorNewNhMallocWrapper + sub_4BA980 + CollisionNodeListInsertion 0x004BAD70), resets identity fields (type/flag/value), appends a 12-byte entry to the active list, increments the count (0x2C), then calls ZoneThresholdComparisonWithConditionalAction (0x004FFFB0).
- `0x004B5760` **MessageEventQueue** — Iterates the list (head 0x20, cursor 0x28); for each node whose first dword passes FieldCompareConstant (0x005001D0), FloatComparisonCheck (0x005001F0) and the audio-sample playback query (0x00500210, fed the float at this+0x30), writes the audio-state buffer's +4 float into the item at +0x370 and passes the buffer to SceneNodeDecoder (0x00410F60) with global dword_5EA560; advances via node+4.
- `0x004B66E0` **LapSpeedToleranceCheck** — Compares two floats (a2, a3) against difficulty-scaled tolerances selected by a switch on (selector this+0x9AC - 1): first jump table jpt_4B67AC picks a base tolerance (0.045/0.022/0.01/0.007/default 0.066), early-accepts when |a2| <= base; clamps |a3| into [2.0, 7.5] (below 2.0 returns 0), then the second jump table jpt_4B67BC picks a scaled tolerance (0.03/0.015/0.008/0.005/default 0.045) and returns |a2| <= scaled * clamped |a3|.
- `0x004B68C0` **PitStallRingBuffer** — Computes the active-entry count of a circular buffer (data 0x9B0, modulus 0x9B4, write 0x9B8, read 0x9BC): returns 0 when write >= read and CoordinateBoundCheck (0x004B69F0) holds, or when the single active entry at buffer + 176*read is empty; otherwise returns write-read+1 (non-wrapped) or modulus-read+write+1 (wrapped).
- `0x004B69D0` **PitStallRingBuffer** — Advances the circular-buffer read index (0x9BC) by one with modulo wrap against the modulus (0x9B4); when read equals write (0x9B8) the buffer is treated as empty and the read index is returned unchanged, otherwise the wrapped successor is stored and the wrap quotient (read+1)/size returned. Used by sub_4B7860.
- `0x004B81A0` **SpriteOverlayDisplayList** — Inserts a display element with a float key (this+0xF38) into the sorted overlay list, re-sorting by split-and-merge (MergeSort 0x004BB2E0): builds a node label via StringFormatWithBufferOverflowCheck (0x0058815F, format global 0x005C3280, count this+0x6CC+1) and StringCopyWithBufferRealloc (0x00566650), allocates a 12-byte key node and a 16-byte frame, appends at the tail (head 0x6C0 / tail 0x6C4 / count 0x6CC), counts nodes, splits at midpoint, merges the two runs by float key, re-links prev pointers, updates head/tail/end (0x6C0/0x6C4/0x6C8), sets the sorted/dirty flag (0x6D0), and returns 1.
- `0x004B8360` **SpriteOverlayDisplayList** — Removes the first display-list node whose inner-data float key (data +0) matches the reference key this+0xF38 within epsilon 2.0; traversal stops early once sorted keys exceed the reference. Unlinks the node (head 0x6C0 / tail 0x6C4 / cursor 0x6C8 / count 0x6CC), frees the inner data (string pointer +4 then struct +0) when the node flag byte (+0xC) is set, frees the 16-byte frame via FreeWrapper_7bcf (0x00587BCF), sets the dirty flag 0x6D0, and returns 1.
- `0x004B8480` **SpriteOverlayDisplayList** — Full teardown of the display list: sets the dirty flag (0x6D0), walks nodes via the next pointer (node+4), frees each node's inner data (string +4 then struct +0) when the node flag byte (+0xC) is set, frees each node frame and the inner struct via FreeWrapper_7bcf (0x00587BCF), then zeroes head/tail/cursor/count (0x6C0-0x6CC). Returns 0.
- `0x004B84F0` **SpriteOverlayDisplayList** — Forward seek over the sorted display list (head 0x6C0, count 0x6CC): advances the cursor (0x6C8) past every node whose float value (data +0) is <= the threshold key this+0xF38, clamps the cursor back to the head when the visited count equals the element count (or nulls it out of range), and writes the selected node's float value back into this+0xF38. Always returns 0.
- `0x004B85D0` **SpriteOverlayDisplayList** — Searches the sorted display list for the seek position whose float value falls in a window relative to the threshold (this+0xF38 - 2.0): seeds the cursor (0x6C8) from the tail (0x6C4) and walks backward via prev (+8) while the window lower bound is <= the node's float value, counting steps, then re-seeks forward from the head (0x6C0) by that many next (+4) steps when the step count is within [0, count); otherwise nulls the cursor. Writes the selected float value back into this+0xF38. Returns 0.
- `0x004B9C80` **QueueRangeProbe** — Queue range-width getter: dereferences the queue pointer at this+0x0, calls QueuePeek (0x004B87A0) for the two end values, and returns their difference (second minus first).
- `0x004B9D00` **FloatAccumulator** — Float accumulator: reads the value through the pointer at this+0x0 via FloatGetter (0x004B8790), adds the incoming float parameter, and forwards the sum to SingleCallWrapper_9cd0 (0x004B9CD0). Used per-step by PitServiceSteeringAnimationStep (0x004B9E40) as a steering animation accumulator.
- `0x004BA150` **SessionFlagGateUpdate** — Session-flag-gated update: when the session active flag at this+0x0 equals 1 and the packed trigger flag at this+2 (PackedFlagRead_9a00, 0x004B9A00) is not set, loads the session time from dbl_8AFEA0 and passes it with the session message count dword_7D2E50 to CallWrapper_9870 (0x004B9870).
- `0x004BA740` **ConditionalRenderCleanup** — Conditional cleanup dispatch gated by the global flag dword_7D005C and the state/type id at this+0x0 (runs sub_4B9880 on the object at this+2 only when both are non-zero/equal to 1); always refreshes the render state via RenderToggleRefresh (0x004B97E0) on this+2 and clears the byte flag at this+4. Returns the RenderToggleRefresh result.
- `0x004BA950` **SizedAllocationSlot** — Sized allocation helper (__thiscall): allocates 432*32 bytes when a2 is non-zero else 432*8 bytes via OperatorNewNhMallocWrapper (0x00587C03), stores the pointer into this+0x0, and returns this. Used by CollisionObjectInsertion (0x004B48E0).
- `0x004BAC40` **DualLinkedObjectList** — Dual-list node insertion (collision sub-list builder): when a2 is non-null, appends a tagged 12-byte node (payload=a2, tag=1) to list 1 (head 0x0, tail 0x4, anchor 0x8, count 0xC), then builds list 2 (head 0x10, anchors 0x14/0x18, count 0x1C) of 8 or 32 nodes whose values are base *a2 plus a running 432-byte stride, skipping zero values; tag 0 nodes are linked at the front. Returns the exhausted loop counter. Called by CollisionObjectInsertion (0x004B48E0).
- `0x004BAF10` **DualLinkedObjectList** — Structural twin of LinkedListNodeInsertion with different secondary geometry: list 1 append (tag 1 node) identical, but list 2 (head 0x10, anchors 0x14/0x18, count 0x1C) is built only when a3 is zero, producing at most two nodes at base *a2 plus a 1016-byte stride, skipping zero values. Used for vehicle instance list nodes by VehicleInstanceListBuilder (0x004B5C50).
- `0x004BB150` **DualLinkedObjectList** — Appends a caller-supplied payload (a2) as a 12-byte node to list 1 (head 0x0, tail 0x4, anchor 0x8, count 0xC), then generates a parallel sub-list (tail 0x10, head 0x14, cursor 0x18, count 0x1C) of 32 or 64 nodes whose data values are the first dword of a2 plus a 12-byte stride; nodes with zero value are skipped. Returns the exhausted loop counter. Called by CarPhysicsStateInitializer (0x004B57F0) and sub_4B7860.
- `0x004BB5A0` **DualLinkedObjectList** — Teardown of the dual-list container (singly-linked variant): walks nodes from the head (this+0x0); when the node flag byte (+8) is set and the payload pointer (+0) is non-null, releases the payload's inner allocation element-by-element with a 1016-byte backward stride (one EmptyStub_0170 call, 0x004B0170, per element, count read from the dword preceding the payload), frees the allocation header, the payload, and the node via FreeWrapper_7bcf (0x00587BCF), then zeroes this[0..3] and returns 0.
- `0x004BB8E0` **SessionStateObject** — Per-frame session/vehicle state reset: when the global session type dword_7C56A4 is <= 6 (non-qualifying) and the condition flag at obj+0x32C8 (obj = the pointer at this+0x0) is <= 1, re-initializes the AI racing line via AIRacingLinePathFollowing (0x004E9CA0), downgrades the mode flag this+0x60 from 2 to 1, and resets the floats this+0x18/0x1C/0x20 to -1.0f; unconditionally clears status flags this+0xA8/0xAC/0xB0/0xB4/0xD0/0xD4, then returns the value read at entry.
- `0x004BC2D0` **PitTrackerState** — Pit-timer state init: zeroes the counter field this+0xC, stores the passed index a2 into this+0x64, sets the state/mode field this+0x60 to literal 2, and returns a2 unchanged. Called by PitTimerStateInit (0x004D23D0).
- `0x004BD800` **OwnerStructCleanup** — Struct teardown: frees up to three owned heap pointers (this[2], this[5], this[8]) through FreeWrapper_7bcf (0x00587BCF), each guarded by a non-null check with the pointer captured before its slot is cleared, zeroes all nine pointer fields this[0..8], and returns the last free result (or null). Called from the cleanup paths of 0x004BD7D0 and 0x004BDDE0.

## Proposed classes

### MessageEventQueue

Event/message list queue: an active message list (head/cursor at 0x20/0x28) whose nodes carry a type key (+0x368), flag key (+0x36C) and float value (+0x370) and are validated/updated per frame (validation walk, dispatch with free-list reuse, audio-state-driven iteration), plus a threshold float at 0x30.

Methods: `0x004B54A0`, `0x004B54E0`, `0x004B5760`

- `this+0x00000010` `void* freeListHead` (read_write, DERIVED)
- `this+0x00000018` `void* freeListTempHead` (write, GUESS)
- `this+0x00000020` `void* activeListHead` (read_write, DERIVED)
- `this+0x00000024` `void* activeListTail` (read_write, DERIVED)
- `this+0x00000028` `void* activeListCursor` (read_write, DERIVED)
- `this+0x0000002C` `int entryCount` (read_write, DERIVED)
- `this+0x00000030` `float thresholdValue` (read, DERIVED)

### LapSpeedToleranceCheck

Stateless-ish float-tolerance comparator driven by a difficulty/assist selector at this+0x9AC: two switch-selected threshold families (base and scaled) and a clamped [2.0, 7.5] scale factor decide whether a candidate speed difference is accepted.

Methods: `0x004B66E0`

- `this+0x000009AC` `int toleranceSelector` (read, DERIVED)

### PitStallRingBuffer

Circular buffer holding per-entry pit-stall data: data pointer, modulus, write index and read index at 0x9B0/0x9B4/0x9B8/0x9BC; computes the active-entry count and advances the read index with modulo wrap.

Methods: `0x004B68C0`, `0x004B69D0`

- `this+0x000009B0` `void* bufferData` (read, DERIVED)
- `this+0x000009B4` `int capacity` (read, DERIVED)
- `this+0x000009B8` `int writeIndex` (read_write, DERIVED)
- `this+0x000009BC` `int readIndex` (read_write, DERIVED)

### SpriteOverlayDisplayList

Sorted doubly-linked display list holding inner data objects with a float key: container head/tail/cursor/count at 0x6C0/0x6C4/0x6C8/0x6CC, sorted/dirty flag at 0x6D0, float key at 0xF38; nodes are 16-byte frames {data +0, next +4, prev +8, flag byte +0xC} wrapping the inner object {float key +0, string +4}. Supports insert-with-merge-sort, remove-by-key with early stop, full teardown, forward seek and priority (windowed) seek.

Methods: `0x004B81A0`, `0x004B8360`, `0x004B8480`, `0x004B84F0`, `0x004B85D0`

- `this+0x000006C0` `void* head` (read_write, DERIVED)
- `this+0x000006C4` `void* tail` (read_write, DERIVED)
- `this+0x000006C8` `void* cursor` (read_write, DERIVED)
- `this+0x000006CC` `int count` (read_write, DERIVED)
- `this+0x000006D0` `byte sortedDirtyFlag` (read_write, DERIVED)
- `this+0x00000F38` `float thresholdKey` (read_write, DERIVED)

### QueueRangeProbe

Peeks the two end values of a queue (pointer at this+0x0) via QueuePeek and returns their difference as a scalar range width.

Methods: `0x004B9C80`

- `this+0x00000000` `void* queuePtr` (read, DERIVED)

### FloatAccumulator

Accumulates an incoming float onto the value referenced through the pointer at this+0x0 (via FloatGetter) and forwards the sum; per-step steering animation accumulation.

Methods: `0x004B9D00`

- `this+0x00000000` `float* targetValuePtr` (read, DERIVED)

### SessionFlagGateUpdate

Gated session update: when the active flag at this+0x0 is 1 and the packed trigger flag at this+2 is clear, pushes the session time (dbl_8AFEA0) and message count (dword_7D2E50) through a call wrapper.

Methods: `0x004BA150`

- `this+0x00000000` `int sessionActiveFlag` (read, DERIVED)

### ConditionalRenderCleanup

Conditional render/cleanup dispatcher: gated by a global flag and a state/type id at this+0x0, runs a cleanup handler on the object at this+2, always refreshes render state (RenderToggleRefresh) and clears the byte flag at this+4.

Methods: `0x004BA740`

- `this+0x00000000` `int stateTypeFlag` (read, DERIVED)
- `this+0x00000004` `byte renderByteFlag` (read_write, DERIVED)

### SizedAllocationSlot

Allocates a sized heap block (432*32 or 432*8 bytes) selected by a flag, stores the pointer at this+0x0 and returns this for chaining.

Methods: `0x004BA950`

- `this+0x00000000` `void* allocationPtr` (read_write, DERIVED)

### DualLinkedObjectList

Container with two parallel 12-byte-node lists: list 1 (head 0x0, tail 0x4, anchor 0x8, count 0xC) holds tagged (tag=1) owner nodes; list 2 (0x10/0x14/0x18/0x1C) holds generated value nodes (tag=0) built from a base value plus a running stride (432 with 8/32 entries, 1016 with up to 2 entries, or 12 with 32/64 entries) skipping zero values. Teardown frees flagged payload allocations element-by-element. Nodes: {value +0, next +4, tag/flag byte +8}.

Methods: `0x004BAC40`, `0x004BAF10`, `0x004BB150`, `0x004BB5A0`

- `this+0x00000000` `void* list1Head` (read_write, DERIVED)
- `this+0x00000004` `void* list1Tail` (read_write, DERIVED)
- `this+0x00000008` `void* list1Anchor` (read_write, GUESS)
- `this+0x0000000C` `int list1Count` (read_write, DERIVED)
- `this+0x00000010` `void* list2HeadOrTail` (read_write, GUESS)
- `this+0x00000014` `void* list2LinkA` (read_write, GUESS)
- `this+0x00000018` `void* list2LinkB` (read_write, GUESS)
- `this+0x0000001C` `int list2Count` (read_write, DERIVED)
- `obj+0x00000000` `void* nodeValue` (read_write, DERIVED)
- `obj+0x00000008` `byte nodeFlag` (read, GUESS)

### SessionStateObject

Per-frame session/vehicle state reset controller: holds a target vehicle/object pointer (this+0x0), mode flag (0x60), three reset floats (0x18/0x1C/0x20) and a set of status flags (0xA8/0xAC/0xB0/0xB4/0xD0/0xD4); reset is gated on the session type global (dword_7C56A4 <= 6) and the target's condition flag (+0x32C8 <= 1).

Methods: `0x004BB8E0`

- `this+0x00000000` `void* targetObject` (read, DERIVED)
- `this+0x00000018` `float resetValueA` (read_write, GUESS)
- `this+0x0000001C` `float resetValueB` (read_write, GUESS)
- `this+0x00000020` `float resetValueC` (read_write, GUESS)
- `this+0x00000060` `int sessionModeFlag` (read_write, DERIVED)
- `this+0x000000A8` `int statusFlagA` (read_write, GUESS)
- `this+0x000000AC` `int statusFlagB` (read_write, GUESS)
- `this+0x000000B0` `int statusFlagC` (read_write, GUESS)
- `this+0x000000B4` `int statusFlagD` (read_write, GUESS)
- `this+0x000000D0` `int statusFlagE` (read_write, GUESS)
- `this+0x000000D4` `int statusFlagF` (read_write, GUESS)
- `obj+0x000032C8` `int objectCondition` (read, DERIVED)

### PitTrackerState

Pit-timer state slot: counter field at 0xC, state/mode field at 0x60 (initialized to literal 2) and an index at 0x64.

Methods: `0x004BC2D0`

- `this+0x0000000C` `int counter` (read_write, GUESS)
- `this+0x00000060` `int stateMode` (read_write, GUESS)
- `this+0x00000064` `int indexValue` (read_write, GUESS)

### OwnerStructCleanup

Small owner struct with nine pointer fields (this[0..8]), three of which (this[2], this[5], this[8]) are owned heap allocations released with a captured-before-clear free pattern.

Methods: `0x004BD800`

- `this+0x00000000` `void* field0` (read_write, GUESS)
- `this+0x00000004` `void* field1` (read_write, GUESS)
- `this+0x00000008` `void* ownedA` (read_write, DERIVED)
- `this+0x0000000C` `void* field3` (read_write, GUESS)
- `this+0x00000010` `void* field4` (read_write, GUESS)
- `this+0x00000014` `void* ownedB` (read_write, DERIVED)
- `this+0x00000018` `void* field6` (read_write, GUESS)
- `this+0x0000001C` `void* field7` (read_write, GUESS)
- `this+0x00000020` `void* ownedC` (read_write, DERIVED)

## Compatibility contracts

- **MessageNodeKeyLayout** — Each message node in the active list must expose a type key at +0x368, a flag key at +0x36C and a float value at +0x370; the type is a 6-bit field packed at bits 18..23 of the incoming message dword and the flag is the byte at message+8. A replacement must preserve the reuse-on-match and free-list-reuse paths.
- **MessageEventQueueListLayout** — The queue container keeps the free-list head at this+0x10, the active list head at this+0x20, tail at this+0x24, cursor at this+0x28 and entry count at this+0x2C; active-list entries are 12 bytes {node, next, flags} with the tail's next slot at +4, and the threshold float at this+0x30 is passed to the post-append conditional action.
- **DisplayListFrameLayout** — Display-list nodes are 16-byte frames {inner data pointer +0, next +4, prev +8, flag byte +0xC}; the inner data object holds a float key at +0 and an optional string pointer at +4 freed only when the flag byte is set. The container tracks head/tail/cursor/count at this+0x6C0/0x6C4/0x6C8/0x6CC, a sorted/dirty flag at 0x6D0 and the search key at 0xF38.
- **DisplayListSortedOrder** — The display list is maintained in float-key order over the inner data value (+0); removal stops early once a node key exceeds the reference key (ascending reading), while the insert path merges with >= comparisons (descending candidate). The two directions conflict across evidence, so a replacement must match the actual consumer reads; ordering direction is not settled.
- **PitStallRingBufferLayout** — The circular buffer stores its data pointer at this+0x9B0, modulus at 0x9B4, write index at 0x9B8 and read index at 0x9BC; the active count is write-read+1 when write >= read, else modulus-read+write+1, and write == read is treated as empty. Entries are 176 bytes (pit-stall records, from existing analysis).
- **SessionResetGate** — The per-frame session/vehicle reset runs only when the global session type dword_7C56A4 is <= 6 (non-qualifying) and the target's condition at +0x32C8 is <= 1; it must re-initialize the AI racing line, downgrade the mode at this+0x60 from 2 to 1, set this+0x18/0x1C/0x20 to -1.0f, and clear the status flags at 0xA8/0xAC/0xB0/0xB4/0xD0/0xD4 on every call.
- **DualListValueSubList** — The dual-list container appends a tag-1 owner node to list 1 (head 0x0/tail 0x4/count 0xC) and generates a tag-0 value sub-list in list 2 (0x10/0x14/0x18/0x1C) whose values are base plus a running stride (432 bytes for 8/32 entries, 1016 bytes for up to 2 entries, or 12 bytes for 32/64 entries depending on variant); nodes with zero computed value are skipped. Nodes are 12 bytes {value +0, next +4, tag/flag byte +8}.

## Unresolved

- All function owners except 0x004B81A0 (SpriteOverlayDisplayList) and 0x004BB8E0 (SessionStateObject) are UnknownObject in the validated IR; the class boundaries and names in this proposal are GUESS synthesis over shared this-field usage, shared callees and shared callers.
- Four SpriteOverlayDisplayList members (0x004B8360, 0x004B8480, 0x004B84F0, 0x004B85D0) have UNKNOWN owners in the packet; their inclusion is inferred GUESS from the shared this+0x6C0..0x6D0 / this+0xF38 cluster and the shared MenuActionDispatch caller.
- The SessionStateObject owner label for 0x004BB8E0 is DERIVED from a legacy ABI name (State_Reset_on_Session_Condition) plus reset semantics, not from independent class evidence; whether this is the vehicle array slot itself or a controller holding a vehicle pointer at this+0x0 is unconfirmed.
- Display-list sort order is contradictory across evidence: the insert merge uses >= (descending) while the removal early-stop assumes keys exceed the reference in ascending order; the actual direction is not settled.
- The this+2 packed byte (accessed by 0x004BA150's PackedFlagRead_9a00 and passed to handlers by 0x004BA740) has no allowed field: evidence ref in this packet; its bit layout and setter are unknown.
- The 11 float globals recorded for 0x004B66E0 (0x0059E444, 0x0059E44C, 0x0059E800, 0x0059E8F4, 0x005ACD3C..0x005ACD54) do not appear in the decompiled body; they likely back the threshold literals but the linkage is unestablished.
- Global 0x005ACD20 (flt_5ACD20) is listed for 0x004B8360 and 0x004B85D0 but absent from their raw bodies (the sources use the literal 2.0); global 0x005ACD24 is referenced in the packet for 0x004B54E0 but absent from its body.
- The message node's layout beyond +0x368/+0x36C/+0x370 and the message type/flag enum are unknown; whether the type/flag lookup is a coalescing cache rather than a plain duplicate check is GUESS.
- Message argument v2 to SingleCallWrapper_9cd0 (0x004B9CD0) and v1 to CallWrapper_9870 (0x004B9870) are uninitialized locals in the decompiled output; the real signatures are unknown.
- Sub-list stride semantics (432/1016/12) and the tag meaning (tag 1 vs tag 0) are inferred from structure only; the two anchors this+0x14 and this+0x18 are not disambiguated.
- The 1016-byte element stride and the allocation-header count read at payload-4 in 0x004BB5A0 are unverified; EmptyStub_0170 (0x004B0170) is a stub whose per-element destructor behavior is unknown.
- The 176-byte ring-buffer entry size and the pit-stall semantics of PitStallRingBuffer come from existing analysis, not from this packet's raw source.
- QueuePeek (0x004B87A0) output ordering (which end each peeked float represents) is not evidenced, so the signed meaning of the range width is DERIVED.
- The MEMORY[0] writes into this+0xF38 on null-cursor paths in 0x004B84F0/0x004B85D0 are decompiler artifacts of a null dereference; real runtime behavior is unknown.
- The identity of the nine-field struct cleaned by 0x004BD800 and the state value 2 written to this+0x60 by 0x004BC2D0 are unknown (no enum mapping).
- dbl_8AFEA0 (session time) and dword_7D2E50 (session message count) semantics are inherited from corpus names, not confirmed in this packet.
- Element size 432 and the 32 vs 8 count selection in 0x004BA950 are unexplained.
