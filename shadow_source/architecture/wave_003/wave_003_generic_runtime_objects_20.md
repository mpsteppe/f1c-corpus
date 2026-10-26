# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Proposal for the generic-runtime-objects slice of the engine. The dominant cluster is replay/game-state IO: ReplayDataFileWriter (0x004B7500) records a full 104-slot replay to a file or performs a one-shot buffer-chain dump, QueuePop (0x004B7A00) drains the same node list into window accumulators, SaveHotlapData (0x004B7DE0) writes .HOT lap files, and ReplayFileLoadStateMachine (0x004BA1F0) drives the VCR playback loader. These share a file/stream backend (0x00566xxx) and a string-table message interface (0x00423A00 + byte_5EC4C0/byte_5EC4CC). A second cluster is generic intrusive linked-list removal (0x004BA830, 0x004BACF0, 0x004BB0C0) operating on 12-byte nodes, plus the dual-list allocator AllocDualListBlockAndInsertNodes (0x004BAFC0). Support pieces include AngleClampWrap (0x004B86E0), serialization magic detection (0x004B8090), a loading state-transition gate (0x004B8AE0) that ticks many global subsystems, a key-priority multi-path dispatcher (0x004BA180), and a replay-status UI renderer (0x004B9FD0). Ownership is established for only ReplayPlaybackLoaderStateMachine and DualListContainer (DERIVED, from packet owners); most owners stay UnknownObject, and equal byte offsets on different bases (0xF30/0xF34/0xF38/0xF3C/0xF80 appear on several independent objects) are deliberately not merged.

## Function roles

- `0x004B7500` **ReplaySaveStateMachine** — Save step for replay/game state: rebuilds the output node list, then records a full 104-slot replay to file or performs a one-shot buffer-chain dump, closing handles and resetting the save-state flag.
- `0x004B7A00` **UnknownObject** — Queue-pop processor: drains a circular buffer into a result list, then returns the head/tail node values into the window accumulators (or zeroes them when the result list is empty).
- `0x004B7DE0` **UnknownObject** — Saves a hotlap (qualifying/record lap) data file: builds a .HOT path from base name, lap time and message-buffer content, opens it, serializes vehicle physics state and a network buffer, closes and cleans up; returns 1 only on full success.
- `0x004B8010` **UnknownObject** — Settings-file existence check and cleanup: resolves the target path, opens it, and when present closes it, clears the read-only attribute and deletes it; returns the inverted delete result (true = no file existed or deletion failed).
- `0x004B8090` **UnknownObject** — Serialization magic self-check: writes sentinel 'xxxx' and float -1.0 through the serialization backend and returns whether they equal the global magic string and float.
- `0x004B86E0` **SteeringAngleController** — Constrains the angle float at +0xF38 to the range [+0xF30, +0xF34], wrapping (mode byte +0xF81 zero) or hard-clamping (non-zero), preserving the previous value at +0xF3C.
- `0x004B8AE0` **UnknownObject** — Loading/state-transition trigger check: refuses to advance while the target progress (+0xF34) is not above current progress (+0xF30), ticks a broad set of global subsystems, and returns 0 when a completion guard trips.
- `0x004B9510` **UnknownObject** — Plays timed audio events whose timestamps fall inside window [a2, a3]: positions the playback cursor on the node list, walks next/prev pointers, and allocates ring-buffer slots for each played event.
- `0x004B9CE0` **UnknownObject** — Delegation: reads the float* stored at this+0x0 and forwards it to FloatGetter (0x004B8790), discarding the return value.
- `0x004B9FD0` **UnknownObject** — One-shot replay-recording status UI renderer: draws a ReplayRecording line and a longer activation message via TextLineWrappingAndRendering, then sets the displayed flag at this+0x4.
- `0x004BA180` **UnknownObject** — Key-priority multi-path dispatcher: routes between the pit-service steering-animation path and an alternative handler based on a key-priority chain, then processes driver entries when a sub-struct float/flag changed.
- `0x004BA1E0` **UnknownObject** — Zero-init stub: writes DWORD 0 at offset 0x0 of this.
- `0x004BA1F0` **ReplayPlaybackLoaderStateMachine** — Replay/VCR playback loader state-machine step: in state 2 opens, reads in 1024-byte chunks, processes the replay data and assigns the player vehicle; in any other state recomputes the state from a session-flag gate.
- `0x004BA830` **LinkedList** — Removes the first linked-list node whose first dword matches the key, unlinking it and freeing its owned data and the node itself; returns 1 on removal.
- `0x004BACF0` **LinkedList** — Pops the head node of a linked list and returns its data pointer, fixing head/tail/current pointers and freeing the node (and its data when flagged).
- `0x004BAFC0` **DualListContainer** — Allocates a 2036-byte block holding two 1016-byte sub-chunks and inserts block nodes into a dual list container, appending per-sub-chunk nodes to the second list; returns the last allocated node.
- `0x004BB0C0` **LinkedList** — Removes the linked-list node whose value equals the head node's value, freeing the node and its owned payload when flagged; returns the removed value.

## Proposed classes

### ReplaySaveStateMachine

Owns the replay/game-state save flow: full replay recording to a file and a one-shot buffer-chain dump, plus the file handle, output paths, node-list pointers and recorded-time window those operations use.

Methods: `0x004B7500`

- `this+0x000006D0` `uint8_t dumpTriggerByte` (read_write, DERIVED)
- `this+0x000006E4` `uint32_t streamHandle` (read_write, DERIVED)
- `this+0x000006E8` `char* dumpPath` (read, DERIVED)
- `this+0x00000700` `uint32_t replaySaveState` (read_write, DERIVED)
- `this+0x00000704` `char* audioOutputPath` (read, DERIVED)
- `this+0x0000070C` `char* outputFilePath` (read, DERIVED)
- `this+0x00000714` `void* bufferChainHead` (read_write, DERIVED)
- `this+0x00000718` `void* bufferChainTail` (read, GUESS)
- `this+0x0000071C` `void* bufferChainCurrent` (read_write, GUESS)
- `this+0x00000720` `uint32_t resultListCount` (read, GUESS)
- `this+0x000009A4` `uint32_t replayTypeDword` (read, DERIVED)
- `this+0x00000F30` `float recordedWindowStart` (read, DERIVED)
- `this+0x00000F34` `float recordedWindowEnd` (read, DERIVED)
- `this+0x00000F94` `char* dumpTargetPath` (read, DERIVED)

### ReplayPlaybackLoaderStateMachine

State machine step for the replay/VCR playback loader, polled by Game_Init: opens and processes the replay file in state 2, otherwise recomputes its state from session flags.

Methods: `0x004BA1F0`

- `this+0x00000000` `uint32_t stateDword` (read_write, DERIVED)
- `this+0x00000008` `void* loaderObjectPtr` (read, DERIVED)

### SteeringAngleController

Stores a current/previous angle pair and clamps or wraps the current value into a configured range, used by steering-animation and loading paths.

Methods: `0x004B86E0`

- `this+0x00000F30` `float rangeLower` (read, DERIVED)
- `this+0x00000F34` `float rangeUpper` (read, DERIVED)
- `this+0x00000F38` `float currentAngle` (read_write, DERIVED)
- `this+0x00000F3C` `float previousAngle` (read_write, DERIVED)
- `this+0x00000F81` `uint8_t wrapOrClampMode` (read, GUESS)

### LinkedList

Generic intrusive singly-linked list over 12-byte nodes, keyed by the value stored at node+0, with node removal by key, by value, and head-pop.

Methods: `0x004BA830`, `0x004BACF0`, `0x004BB0C0`

- `this+0x00000000` `LinkedListNode* head` (read_write, DERIVED)
- `this+0x00000004` `LinkedListNode* secondPointer` (read_write, GUESS)
- `this+0x00000008` `LinkedListNode* tailOrCurrent` (read_write, GUESS)
- `this+0x0000000C` `uint32_t count` (read_write, DERIVED)

### LinkedListNode

12-byte intrusive list node: value/data pointer at +0, next pointer at +4, ownership flag byte at +8; a fourth dword at +0xC is packet-flagged but never used in the observed logic.

Methods: 

- `obj+0x00000000` `void* dataOrKey` (read_write, DERIVED)
- `obj+0x00000004` `LinkedListNode* next` (read_write, DERIVED)
- `obj+0x00000008` `uint8_t flagByte` (read_write, DERIVED)
- `obj+0x0000000C` `uint32_t unresolvedDword` (unknown, UNKNOWN)

### DualListContainer

Container holding two intrusive linked lists (head/tail/current/count each) that AllocDualListBlockAndInsertNodes populates with block nodes and per-sub-chunk nodes.

Methods: `0x004BAFC0`

- `this+0x00000000` `void* firstListHead` (read_write, DERIVED)
- `this+0x00000004` `void* firstListTail` (read_write, DERIVED)
- `this+0x00000008` `void* firstListCurrent` (read_write, DERIVED)
- `this+0x0000000C` `uint32_t firstListCount` (read_write, DERIVED)
- `this+0x00000010` `void* secondListHead` (read_write, DERIVED)
- `this+0x00000014` `void* secondListAnchor` (read_write, GUESS)
- `this+0x00000018` `void* secondListSecondary` (read_write, GUESS)
- `this+0x0000001C` `uint32_t secondListCount` (read_write, DERIVED)

## Compatibility contracts

- **ReplayFileRoundTrip** — Replay files written by the save path (1024-byte chunked writes through the FileWriteBackend dispatch) must be readable back by the replay loader using the same 1024-byte chunked read path; recording is gated by session type dword_7C569C != 4 and a positive recorded-time window (this+0xF34 minus this+0xF30 above the flt_59E440 threshold).
- **HotlapFileWrite** — .HOT lap files are built from the base name at this+0x70C (extension stripped, '.HOT' word appended), the player lap-time float at dword_7C54E8+16540 (skip when -1.0 or not greater than 0.0), and message-buffer content; the file-type enum at this+0x9A4 maps 0..3 through and everything else to mode 4 before opening via sub_566940.
- **ReplaySaveStateInterface** — The replay save-state dword at +0x700 must be 1 to enter the full recording path and is reset to 0 by the save step; the dump trigger byte at +0x6D0 is a one-shot (cleared to 0 so the dump runs once). A replacement must preserve this external state interface.
- **LoaderStateGateInterface** — The replay loader state dword at +0x0 must be 2 to run the load branch; in any other state the value is recomputed from the flag gate dword_5EA43C and session flags dword_7D0038/dword_7D005C.
- **NodeLinkedListLayout** — List nodes are 12 bytes: value/data at +0, next pointer at +4, ownership flag byte at +8; the list head is at this+0, a second pointer (tail/current, roles ambiguous across functions) at this+4, a tail/current pointer at this+8, and the element count at this+0xC. Three independent functions agree on this layout.
- **AudioEventRingBuffer** — Timed-audio-event playback allocates ring-buffer slots with a 432-byte stride from base dword_8AAE64, advancing a slot counter dword_83EE60 and capping at 1023 slots, when the event header (v24[0] & 0xE0000000) is not the 0x20000000 skip pattern.
- **SerializationMagicCheck** — The serialization format self-check writes a 4-byte 'xxxx' sentinel and the float -1.0 through the backend and reports success only when the buffer equals the global string at 0x005D2434 and the float equals the global float at 0x005D2438.

## Unresolved

- 0x004B7A00 (QueuePop) shares field offsets 0x714/0x718/0x71C/0x720/0xF30/0xF34 with ReplaySaveStateMachine's `this` and is called by 0x004B7500, but the packet leaves its owner UnknownObject; common ownership is not proven, so the fields were not merged into ReplaySaveStateMachine.
- 0x004B86E0 (SteeringAngleController) and 0x004B9510 use the same numeric offsets 0xF30/0xF34 (and 0xF38/0xF3C for the controller) as ReplaySaveStateMachine's recorded-window and QueuePop's accumulators, but on different bases; equal offsets were not merged.
- The dispatcher 0x004BA180 reads a sub-struct behind this+0x8 with fields at 0xF80 (byte flag) and 0xF3C (float), which numerically overlap the SteeringAngleController layout; whether the sub-struct is a steering controller is unproven and left unresolved.
- field:this:0x00000F9C (referenced by 0x004BA1F0 from the deterministic fact table) conflicts with the 0xF94 path-pointer read visible in the raw decompile; not reconciled.
- Null-pointer branches in 0x004B7A00 dereference address zero in the raw source (MEMORY[0]) - a decompiler artifact; actual behavior on null head/tail is unproven.
- The 104-iteration loop at sub_4B6190 in 0x004B7500 is assumed to serialize per-slot replay physics, but what list it iterates is not established.
- The writer that sets this+0x700 (replay save state) to 1 and the writer that sets this+0x6D0 (dump trigger) are not visible in this packet; only the resets performed here are observed.
- 0x004B7DE0 passes an uninitialized v10 to SessionTypeGuard and references globals flt_59E440, flt_59E670 and byte_5BE718 that do not appear in the raw body.
- 0x004B8090 references globals dword_5D246C and byte_5D2470 that do not appear in the raw body, and whether FileWriteWithBackendDispatch round-trips or only writes is uncertain.
- 0x004B8AE0 references globals flt_59E440 and unk_7CE2A4 that do not appear in the raw body; the semantics of the subsystem tick calls (sub_4B8C40, sub_4D4580, sub_4FA7E0, sub_4A1830) are unknown beyond their legacy names.
- 0x004B9510 references global flt_5ACD68 that does not appear in the raw body; the owner and format of the 432-byte-stride ring buffer are not established.
- 0x004BA180 references global byte_8AC494 that does not appear in the raw body; FloatGetter, ProcessDriverEntries, Delegation, sub_4B9000 and sub_4B9B80 are called without evidence refs in the packet, so their addresses are unknown.
- 0x004B9FD0 passes literal 16909060 and line parameters 2/3 to TextLineWrappingAndRendering, and appends word_5C32D8 immediately after the string terminator; both meanings are unconfirmed.
- 0x004B9CE0 (Delegation) has 19 callers across telemetry, wheel, particle, scoring and vehicle paths, but the per-caller intent of the delegation is not established.
- LinkedListNode field at +0xC is packet-flagged as read but never appears in any decompiled logic; possibly padding or a decompiler artifact.
- The role of this+0x4 vs this+0x8 in LinkedList (tail/current/second-pointer ambiguity) differs slightly between 0x004BA830, 0x004BACF0 and 0x004BB0C0.
- In 0x004BAFC0 the semantics of DualCallWrapper_4f50's per-sub-chunk initialization, the header value 2 at block start, and the flag difference (1 vs 0) between the two lists' nodes are unknown.
- EmptyStub_0170 (0x004B0170) is called before owned-data frees with no observable effect; likely a no-op or bookkeeping stub.
- FreeWrapper_7bcf (0x00587BCF) is listed as a callee of 0x004B7500 but never appears in its decompiled body; likely reached through an inlined or tail path.
- Local v19 in 0x004BA1F0 doubles as the 128-byte path object and as the QueuePeek output buffer; the lifetime overlap is not resolved.
