# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Derived architecture proposal for 19 validated functions in scope generic_runtime_objects. Two packet-DERIVED owners anchor classes: 0x0048D2B0 (LinkedListNodeAppend) joins 0x0048D230 (LinkedListDestructionWithVTableCall) on the shared this+0x31C..0x340 list state block as the LinkedList class, and 0x0048D9D0 forms MediaBufferPlaybackManager. All remaining functions carry packet-UNKNOWN owners and are grouped into GUESS classes keyed on shared field regions: ScrollableUIList (0x0048CCB0, shares the 0x31C/0x324/0x328 list region), TextInputWidget (0x0048B9C0), ConditionalRenderWidget (0x0048D6F0), ResourceWidget (0x0048E250/0x0048E3A0/0x0048E4B0, sharing the this+0xE4..0xF8 resource/metric region and vtable slots 44/160), MutexResourceCleanup (0x0048E890, kept apart from ResourceWidget because this+0xE8/0xEC carry incompatible roles), ViewportClipForwarder (0x0048F0B0), DoublyLinkedList (0x0048F5D0), BitmapSurface (0x0048FC80/0x0048FCA0), DelegationDispatchWidget (0x0048FDF0), CustomMemoryPoolAllocator (0x004906E0/0x00490940 over globals 0x7CD9C8/0x7CD9CC/0x7CD9D0), and AudioStreamFile (0x00491EE0/0x00491F60). A shared 10-arg clip-and-emit pattern (GlobalAccessor_5150 + F_10ParamForwarder) is factored into the SurfaceBlitForwarder interface.

## Function roles

- `0x0048B9C0` **TextInputWidget** — Text-input widget render: resolve font (this+0xC8, path at +0x40, default byte_5EA438), prime measurement context, resolve layout child, mask edit buffer at this+0x2F0 with '*' when password flag 0xE2, append cursor glyph (0xE0 & 0xE1), measure/left-scroll against view width, BitmapDraw, write geometry to out params, call vtable+44 post-render; returns 0
- `0x0048CCB0` **ScrollableUIList** — Sprite/tile batch render for a scrollable UI list: clip-rect (0x14..0x20) and tile-count (0x328) guards, camera-derived column sweep over the linked list at 0x31C/0x324, clamped sprite sub-rect emission via F_10ParamForwarder, second hover/overlay pass via sub_486830 and ConditionalDelegation_6460, visible-region publish via vtable+16; returns 0 or -1
- `0x0048D230` **LinkedList** — Destroy the object's singly linked list at 0x31C: per-node guard on active flag byte node+0xC and first dword, indirect vtable destructor call, FreeWrapper_7bcf on each node, then zero the state block 0x31C..0x340 except direction byte 0x33C set to 1
- `0x0048D2B0` **LinkedList** — Append a value to the doubly linked list: allocate 8-byte data node and 16-byte list node, link at tail 0x320, bump count 0x328, recompute size statistics, notify change via vtable slot 44; returns 1 on success, 0 on allocation failure
- `0x0048D6F0` **ConditionalRenderWidget** — Conditional UI render dispatch: early return 0 when flag at 0xEC is clear; else fetch UI string, copy it into buffer 0x40 via sub_498560 when non-null, and delegate rendering to UILargeRenderDispatcher 0x00488BE0
- `0x0048D9D0` **MediaBufferPlaybackManager** — Render media-buffer playback list: cache item layout (X 0x108..0x114, Y 0x118..0x124), position list iterator, string-table lookup into byte_5EC4CC, UIMessageDispatch for item 3, clip-bounds multi-item pass gated on playback states 3/4/5/8/9, delegate surface fill and invoke vtable #4/#11; returns 0
- `0x0048E250` **ResourceWidget** — Bink video render-or-reload: compare expected path 0xB0 vs loaded path 0xE8; on match with unloaded state 0xE4 null and handle 0xE0 non-null render one frame at (0xC,0x4) via BinkVideoFrameRender and notify vtable+44; on mismatch invoke vtable+160 reload; returns 0
- `0x0048E3A0` **ResourceWidget** — Font resource load: free existing resource 0xE4, build path from dir 0xB0, base dir dword_5EC3F0 and name 0xB8 (defaulting to byte_5EA438), create resource, clear metrics 0xE8/0xEC, on failure branch clear active byte 0xF8 and copy glyph width/height from resource +0xC/+0x10 into 0xF0/0xF4 and configure DSP parameter; returns 1/0
- `0x0048E4B0` **ResourceWidget** — Per-object Bink frame render/reload driver: compare loaded path 0xFC vs reference 0xB0; on difference invoke vtable+160 reload; else when resource 0xE4 present and flag 0xF8 set render a frame, clear flag, blit rendered surface, notify vtable+44 and repaint vtable+16; returns 0
- `0x0048E890` **MutexResourceCleanup** — Clean up a mutex/semaphore resource: release handle at 0xE8 via MutexSemaphoreCleanup when non-null, clear it, unconditionally zero field 0xEC; returns 1
- `0x0048F0B0` **ViewportClipForwarder** — Guarded render-bounds forwarder: requires a2, flag 0x17C and source pointer 0xE4; clip a3/a4 against bounds 0x120/0x140, clamp source width/height (*(this+0xE4)+0x1C/+0x20) against 0x124/0x144, fetch render context via GlobalAccessor_5150 and forward 10 args to F_10ParamForwarder; returns forwarded result
- `0x0048F5D0` **DoublyLinkedList** — Append a 16-byte node (data pointer + byte flag) to a doubly linked list at 0xF0/0xF4/0xF8/0xFC: skip entirely on null data, allocate via OperatorNewNhMallocWrapper(16), link head/cursor/tail, increment element count
- `0x0048FC80` **BitmapSurface** — Copy nested external bounds: store source pointer into 0x38, read width from *(a2+12)+28 into 0xC and height from *(a2+12)+32 into 0x10; returns the nested source struct pointer
- `0x0048FCA0` **BitmapSurface** — Guarded bitmap blit with source/destination clipping: requires 0x38 and descriptor base 0x44; clip a2/a3 against bounds 0x24/0x1C, clamp source width/height (descriptor +0x1C/+0x20) against 0x28/0x20, fetch render context and forward 10 args to F_10ParamForwarder; returns forwarded result
- `0x0048FDF0` **DelegationDispatchWidget** — Conditional delegation dispatch: when sub-object 0x30 is non-null, run ConditionalDelegation_6460 with the sub-object's slot 33, accumulate incoming offsets via OffsetAccumulator, invoke the sub-object's vtable slot 0x2C with literal 1 and return its result; null-guard path returns an uninitialized result
- `0x004906E0` **CustomMemoryPoolAllocator** — One-time custom memory-pool allocator init: guard byte_7CD9C8 bit 0, allocate pool struct/descriptor/32-entry array, link free-list nodes, store pool in dword_7CD9CC and allocator handle in dword_7CD9D0, register ResourceLinkedListTeardown; returns pointer to dword_7CD9CC
- `0x00490940` **CustomMemoryPoolAllocator** — Pool node pop-or-alloc over the global container: pop free-list head or allocate node + 68-byte block, init four dwords, append to pool list; dealloc-walk unlinks/destroys a matched node; ends with ShortComputation_16e0; returns the resulting node pointer
- `0x00491EE0` **AudioStreamFile** — Audio stream open wrapper: open read stream "rb" into this[0], optionally open write stream "wt" into this[1] when flag 0x19A is set, read/init audio stream buffer from the read stream, configure the write stream; returns 0
- `0x00491F60` **AudioStreamFile** — Three-handle resource cleanup: dispatch/close this[0] via StreamFileTypeCheckWithDispatch and this[1]/this[2] via FileCloseWithLock when non-null, zero all three slots; returns 0

## Proposed classes

### LinkedList

Doubly linked-list container holding value nodes. Appends a value node and notifies via vtable slot 44 (0x0048D2B0) and destroys the list, freeing every node through FreeWrapper_7bcf and resetting the state block 0x31C..0x340 with direction byte 0x33C left at 1 (0x0048D230).

Methods: `0x0048D230`, `0x0048D2B0`

- `this+0x00000000` `pointer vtable` (read, DERIVED)
- `this+0x0000031C` `pointer listHeadPtr` (read_write, DERIVED)
- `this+0x00000320` `pointer listTailPtr` (read_write, DERIVED)
- `this+0x00000324` `pointer firstElementPtr` (read_write, DERIVED)
- `this+0x00000328` `int elementCount` (read_write, DERIVED)
- `this+0x0000032C` `int stateField_32C` (write, DERIVED)
- `this+0x00000330` `int stateField_330` (write, DERIVED)
- `this+0x00000334` `int stateField_334` (write, DERIVED)
- `this+0x00000338` `int stateField_338` (write, DERIVED)
- `this+0x0000033C` `byte directionByte` (write, DERIVED)
- `this+0x00000340` `int stateField_340` (write, DERIVED)
- `*(this+0x31C)+0x00000000` `pointer nodeValuePtr` (read, DERIVED)
- `*(this+0x31C)+0x0000000C` `byte nodeActiveFlag` (read, DERIVED)
- `*(*(this+0x31C)+0x0)+0x00000000` `pointer dataNodeVTable` (read, DERIVED)
- `*(*(*(this+0x31C)+0x0)+0x0)+0x00000000` `pointer vtableDestructorSlot` (read, GUESS)
- `obj+0x0000002C` `pointer notifyChangeCallback` (read, DERIVED)

### ScrollableUIList

Sprite/tile batch renderer for a scrollable UI list (0x0048CCB0). Sweeps the linked list held at this+0x31C/0x324 under camera-derived column math, emits clamped sprite sub-rects through F_10ParamForwarder, and publishes the visible region back to the caller. Shares the 0x31C..0x340 list state block with LinkedList on a GUESS basis.

Methods: `0x0048CCB0`

- `this+0x00000000` `pointer vtable` (read, GUESS)
- `this+0x00000004` `int widgetPosX` (read, GUESS)
- `this+0x0000000C` `int widgetPosY` (read, GUESS)
- `this+0x00000014` `int clipLeft` (read, GUESS)
- `this+0x00000018` `int clipTop` (read, GUESS)
- `this+0x0000001C` `int clipRight` (read, GUESS)
- `this+0x00000020` `int clipBottom` (read, GUESS)
- `this+0x00000084` `int delegationSelector` (read, GUESS)
- `this+0x00000088` `int skipNodeSlot` (read, GUESS)
- `this+0x0000031C` `pointer listHeadPtr` (read, GUESS)
- `this+0x00000324` `pointer listCursorPtr` (read_write, GUESS)
- `this+0x00000328` `int tileCount` (read, GUESS)
- `this+0x0000032C` `int columnWidth` (read, GUESS)
- `this+0x00000334` `int columnField_334` (read, GUESS)
- `*(this+0x324)+0x00000004` `pointer spriteNodeNext` (read, GUESS)
- `*(*(this+0x324)+0x4)+0x0000000C` `pointer spriteChildPtr` (read, GUESS)
- `*(*(*(this+0x324)+0x4)+0xC)+0x0000001C` `int textureSizeW` (read, GUESS)

### TextInputWidget

Text-input widget renderer (0x0048B9C0): resolves the font sub-object, masks the edit buffer when the password flag is set, appends the cursor glyph, left-scrolls overflow, draws via BitmapDraw and invokes the post-render vtable callback.

Methods: `0x0048B9C0`

- `this+0x00000000` `pointer vtable` (read, GUESS)
- `this+0x00000004` `int widgetPosX` (read, GUESS)
- `this+0x0000000C` `int widgetPosY` (read, GUESS)
- `this+0x000000C8` `pointer fontSubObjectPtr` (read, GUESS)
- `*(this+0xC8)+0x00000040` `pointer fontPathPtr` (read, GUESS)
- `this+0x000000E0` `byte visibleFlag` (read, GUESS)
- `this+0x000000E1` `byte cursorFlag` (read, GUESS)
- `this+0x000000E2` `byte passwordFlag` (read, GUESS)
- `this+0x000002F0` `pointer editBufferPtr` (read, GUESS)

### ConditionalRenderWidget

Conditional UI render dispatcher (0x0048D6F0): skips rendering while the flag at 0xEC is clear, copies a fetched UI string into the buffer at 0x40, and delegates the actual draw to UILargeRenderDispatcher.

Methods: `0x0048D6F0`

- `this+0x00000040` `pointer stringBufferPtr` (write, GUESS)
- `this+0x000000EC` `byte renderFlag` (read, GUESS)

### MediaBufferPlaybackManager

Renders the media-buffer playback list (0x0048D9D0): caches per-item layout coordinates, walks the item list to the clamped current index, looks display strings up in the string table, dispatches UI messages, and for playback states 3/4/5/8/9 runs a clip-tested extra-item pass; ends by delegating a surface fill and invoking vtable #4/#11.

Methods: `0x0048D9D0`

- `this+0x00000000` `pointer vtable` (read, DERIVED)
- `this+0x00000004` `int baseX` (read, DERIVED)
- `this+0x0000000C` `int baseY` (read, DERIVED)
- `this+0x00000084` `int delegationSelector` (read, DERIVED)
- `this+0x000000C8` `pointer fontSubObjectPtr` (read, DERIVED)
- `this+0x000000E8` `pointer listHeadPtr` (read, DERIVED)
- `this+0x000000EC` `pointer listNodePtr` (read, DERIVED)
- `this+0x000000F0` `pointer currentNodePtr` (read_write, DERIVED)
- `this+0x000000F4` `int pageCount` (read, DERIVED)
- `this+0x000000F8` `int maxPageIndex` (read, DERIVED)
- `this+0x000000FC` `int currentIndex` (read_write, DERIVED)
- `this+0x00000100` `int targetIndex` (read, DERIVED)
- `this+0x00000104` `int selectedIndex` (write, DERIVED)
- `this+0x00000108` `int layoutX_0` (write, DERIVED)
- `this+0x0000010C` `int layoutX_1` (write, DERIVED)
- `this+0x00000110` `int layoutX_2` (write, DERIVED)
- `this+0x00000114` `int layoutX_3` (write, DERIVED)
- `this+0x00000118` `int layoutY_0` (write, DERIVED)
- `this+0x0000011C` `int layoutY_1` (write, DERIVED)
- `this+0x00000120` `int layoutY_2` (write, DERIVED)
- `this+0x00000124` `int layoutY_3` (write, DERIVED)
- `*(this+0xE8)+0x00000000` `pointer headNodeDataPtr` (read, DERIVED)
- `*(this+0xEC)+0x00000004` `pointer nodeNextPtr` (read, DERIVED)
- `*(this+0xF0)+0x00000000` `pointer currentNodeDataPtr` (read, DERIVED)
- `obj+0x00000010` `pointer renderCallback` (read, DERIVED)
- `obj+0x0000002C` `pointer cleanupCallback` (read, DERIVED)

### ResourceWidget

Resource widget holding a single loadable resource at this+0xE4 with path/metric state around it. Loads font resources (0x0048E3A0), renders Bink video frames or reloads when the path changes (0x0048E250, 0x0048E4B0). Shares vtable slots 44 (content changed) and 160 (reload).

Methods: `0x0048E250`, `0x0048E3A0`, `0x0048E4B0`

- `this+0x00000000` `pointer vtable` (read, GUESS)
- `this+0x00000004` `int posX` (read, GUESS)
- `this+0x0000000C` `int posY` (read, GUESS)
- `this+0x000000B0` `pointer pathStringPtr` (read, GUESS)
- `this+0x000000B8` `pointer fontNamePtr` (read, GUESS)
- `this+0x000000E0` `pointer videoResourceHandle` (read, GUESS)
- `this+0x000000E4` `pointer resourcePtr` (read_write, GUESS)
- `this+0x000000E8` `pointer loadedPathPtr` (read, GUESS)
- `this+0x000000EC` `int metricField` (write, GUESS)
- `this+0x000000F0` `int metricWidth` (read_write, GUESS)
- `this+0x000000F4` `int metricHeight` (read_write, GUESS)
- `this+0x000000F8` `byte activeFlag` (write, GUESS)
- `this+0x000000FC` `pointer loadedPathPtr_FC` (read, GUESS)
- `*(this+0xE4)+0x0000000C` `int resourceGlyphW` (read, GUESS)
- `*(this+0xE4)+0x00000010` `int resourceGlyphH` (read, GUESS)
- `obj+0x00000010` `pointer repaintCallback` (read, GUESS)
- `obj+0x0000002C` `pointer contentChangedCallback` (read, GUESS)
- `obj+0x000000A0` `pointer reloadCallback` (read, GUESS)

### MutexResourceCleanup

Cleanup helper for a mutex/semaphore-style handle (0x0048E890): releases the handle at 0xE8 via MutexSemaphoreCleanup and zeroes the secondary field at 0xEC. Kept separate from ResourceWidget because 0xE8/0xEC carry incompatible roles there.

Methods: `0x0048E890`

- `this+0x000000E8` `pointer mutexHandle` (read_write, GUESS)
- `this+0x000000EC` `int secondaryField` (write, GUESS)

### ViewportClipForwarder

Guarded render-bounds forwarder (0x0048F0B0): clips requested source offsets against stored viewport bounds, clamps the source rectangle from the pointed object at 0xE4, and forwards the computed parameters to F_10ParamForwarder.

Methods: `0x0048F0B0`

- `this+0x000000E4` `pointer sourceObjectPtr` (read, GUESS)
- `this+0x00000120` `int clipBoundX` (read, GUESS)
- `this+0x00000124` `int clampBoundW` (read, GUESS)
- `this+0x00000140` `int clipBoundY` (read, GUESS)
- `this+0x00000144` `int clampBoundH` (read, GUESS)
- `this+0x0000017C` `byte enabledFlag` (read, GUESS)
- `*(this+0xE4)+0x0000001C` `int sourceRectW` (read, GUESS)
- `*(this+0xE4)+0x00000020` `int sourceRectH` (read, GUESS)

### DoublyLinkedList

Doubly linked list container at 0xF0..0xFC (0x0048F5D0): appends 16-byte nodes holding a data pointer and a byte flag, linking head/cursor/tail and bumping the element count. Node member semantics are DERIVED from the raw body, not from the packet's typed field list.

Methods: `0x0048F5D0`

- `this+0x000000F0` `pointer headPtr` (read_write, GUESS)
- `this+0x000000F4` `pointer tailPtr` (read_write, GUESS)
- `this+0x000000F8` `pointer cursorPtr` (write, GUESS)
- `this+0x000000FC` `int elementCount` (read_write, GUESS)

### BitmapSurface

Bitmap render-surface object: copies nested source bounds (0x0048FC80) and performs guarded, clipped bitmap blits (0x0048FCA0) that clamp a source rectangle from the descriptor base at 0x44 and forward to F_10ParamForwarder. Both methods are called by GameFilterSetup (0x00477830) and ProfileBitmapBrowser (0x00477CB0).

Methods: `0x0048FC80`, `0x0048FCA0`

- `this+0x00000038` `pointer sourcePtr` (read, GUESS)
- `this+0x00000044` `pointer descriptorBasePtr` (read, GUESS)
- `this+0x0000000C` `int destWidth` (write, GUESS)
- `this+0x00000010` `int destHeight` (write, GUESS)
- `this+0x0000001C` `int clipBoundY` (read, GUESS)
- `this+0x00000020` `int clipBoundH` (read, GUESS)
- `this+0x00000024` `int clipBoundX` (read, GUESS)
- `this+0x00000028` `int clipBoundW` (read, GUESS)
- `*(this+0x44)+0x0000001C` `int sourceW` (read, GUESS)
- `*(this+0x44)+0x00000020` `int sourceH` (read, GUESS)

### DelegationDispatchWidget

Conditional delegation dispatcher (0x0048FDF0): when the sub-object at 0x30 is present, runs ConditionalDelegation_6460 with the sub-object's slot 33, accumulates incoming offsets, and invokes the sub-object's vtable slot 0x2C with literal 1.

Methods: `0x0048FDF0`

- `this+0x00000030` `pointer subObjectPtr` (read, GUESS)
- `*(this+0x30)+0x0000002C` `pointer subObjectVTableSlot` (read, GUESS)

### CustomMemoryPoolAllocator

Global custom memory-pool allocator: one-time construction of the pool and free list with an allocator handle (0x004906E0) and node pop-or-alloc over the global container (0x00490940). Backed by global byte_7CD9C8 / dword_7CD9CC / dword_7CD9D0 (see MemoryPoolAllocatorGlobalState contract) and consumed by Accessor/GlobalDataRead.

Methods: `0x004906E0`, `0x00490940`


### AudioStreamFile

Audio stream file object: opens read and optional write streams with mode strings (0x00491EE0) and closes/zeroes the three handle slots (0x00491F60). The read/write stream handles and the write-mode flag at 0x19A suggest an audio stream file, but the concrete owner type is unproven.

Methods: `0x00491EE0`, `0x00491F60`

- `this+0x00000000` `pointer readStreamPtr` (read_write, GUESS)
- `this+0x00000004` `pointer writeStreamPtr` (read_write, GUESS)
- `this+0x00000008` `pointer thirdHandlePtr` (read_write, GUESS)
- `this+0x0000019A` `byte writeModeFlag` (read_write, GUESS)

## Compatibility contracts

- **TextInputEditBufferContract** — TextInputRender (0x0048B9C0) requires an edit-buffer pointer at this+0x2F0 with 256-byte scratch semantics: when the password flag byte at this+0xE2 is set the buffer is masked with '*' (0x2A), and when the visibility flag 0xE0 AND the cursor flag 0xE1 are set the cursor glyph word_5CC214 is appended. The font sub-object path at this+0xC8/+0x40 falls back to the shared default string byte_5EA438.
- **ScrollableTileListStateBlock** — The scrollable UI list and its linked-list container share the state block this+0x31C..0x340: head 0x31C, tail 0x320, first-element/cursor 0x324, count 0x328; destruction (0x0048D230) zeroes the block except the direction byte at 0x33C which is set to 1. List nodes are 4-byte linked via +0x4 next with an active byte at +0xC.
- **DoublyLinkedListNodeLayout** — DoublyLinkedListAppend (0x0048F5D0) appends 16-byte nodes holding a data pointer at +0, next at +4, prev at +8 and a byte flag at +12, with container head 0xF0, tail 0xF4, cursor 0xF8 and element count 0xFC incremented on append. Nothing is appended when the data pointer is null.
- **BinkVideoFrameRenderSignature** — BinkVideoFrameRender(context, x, y, 32) draws one video frame where context comes from GlobalAccessor_5150(&unk_7CDE00) and (x,y) is the stored render position. After a render, vtable slot 44 (byte offset 0x2C) is called with literal 1 to signal content changed; vtable slot 160 (byte offset 0xA0) triggers a reload when the path differs.
- **AudioStreamOpenModeStrings** — FileOpenWrapperWithModeCheck (0x00491EE0) opens the read stream with mode string "rb" (global 0x005BE828) into this[0] and, when the write-mode flag byte at this+0x19A is set, an optional write stream with "wt" (global 0x005C302C) into this[1]; the flag is cleared when the write stream cannot be created.
- **MemoryPoolAllocatorGlobalState** — CustomMemoryPoolAllocatorInit (0x004906E0) is one-time: guarded by byte_7CD9C8 bit 0, it builds the pool, stores the pool pointer in dword_7CD9CC and the allocator handle in dword_7CD9D0, and registers ResourceLinkedListTeardown (0x00490850) as teardown callback. Accessor/GlobalDataRead depend on this global state.

## Unresolved

- The three functions sharing the this+0x31C..0x340 list region carry conflicting packet owner names: 0x0048D2B0 is LinkedList/DERIVED, 0x0048CCB0 is Scrollable_UI_List_Rendering/UNKNOWN, 0x0048D230 is UnknownObject. They are placed in LinkedList (0x0048D230/0x0048D2B0) and ScrollableUIList (0x0048CCB0) and linked by a GUESS 'shares_linked_list_state_block' dependency; common ownership is not proven by the packet.
- Eight read-only obj fields (obj+0x8..+0x24) flagged by 0x0048CCB0 packet facts do not appear in the raw decompiled body; they are probably the child-object layout consumed by F_10ParamForwarder and are left unresolved.
- The vtable slot identities of ScrollableUIList (camera getters 24/28/32/36, callbacks 8/12/16/20) are not named by the packet.
- MediaBufferPlaybackManager parameters a2-a5 are never referenced in the body; the playback-state enum values 3/4/5/8/9 returned by ShortComputation_6720 are unnamed; the DualFieldRead clip-bounds source is unknown; and the function has no static callers so its invocation context is unknown.
- The nested delegation-object fields (obj+0x18/0x1C/0x24/0x2C in TextInputRender and the obj+8..0x24 region) and the rectangle-delta layout semantics of the delegation child cannot be recovered from this packet.
- ResourceWidget and MutexResourceCleanup both touch this+0xE8/0xEC but with incompatible roles (path/metrics vs mutex handle/secondary); per rule 8 they are kept as separate classes rather than merged.
- global byte_5EA438 is the shared default string substituted whenever a path/name pointer is null across nearly every UI renderer in this packet; its content is unknown.
- GlobalAccessor_5150(&unk_7CDE00) returns the render surface/context used by SurfaceBlitForwarder; the identity and structure of the global behind 0x007CDE00 are not determinable from this packet.
- field:this:0x000000B4 (0x0048FDF0) is recorded as read by deterministic facts but the raw source passes the sub-object's dword 33 (offset 0x84) as the delegation parameter; the two cannot be reconciled from this packet alone.
- The 0x0048F5D0 packet field entry lists this+0xFC as read-only (R) yet the decompiled body increments it (++this[63]); the R/W classification is inconsistent with the observed write.
- BinkVideoFrameRender's literal argument 32 (bit depth or flags) is unresolved, and which path string is requested vs loaded is inferred rather than confirmed.
- ObjectCreationWithRollbackOnFailure in 0x0048E3A0 reads glyph metrics from the resource object on the failure branch, suggesting partial creation on failure; the exact contract is unclear.
- The pool struct and free-list node layouts in 0x004906E0 are DERIVED from dword/byte indices; when the descriptor allocation fails the decompiled body still dereferences the descriptor inside the walk loop, so the original guard may be unrecoverable.
- global dword_8AFE64 (0x008AFE64) is packet-listed as read by 0x0048E3A0 and 0x0048E890 but does not appear in the raw source text of either.
- The indirect vtable destructor target in 0x0048D230 is node-type dependent; the state-block fields 0x320..0x340 (tail/counts/scroll state) and the 0x33C direction-byte semantics are not individually established.
- The constant 10 (margin) in 0x0048F0B0's y-clip and height clamp and the 0x120/0x140 (scroll offset vs viewport maximum) interpretation are not proven by the packet.
- DoublyLinkedList node member semantics (data +0, next +4, prev +8, byte flag +12) are DERIVED from the raw source, not part of the packet's typed field list; the owning class of the four list fields at 0xF0..0xFC is unknown.
- 0x0048E250/0x0048E4B0/0x0048F0B0/0x0048FCA0 have no static callers in the packet, so the external trigger conditions for their render/reload/repaint paths are unknown.
- sub_587DD0's copy semantics (plain vs bounded string copy) in 0x0048B9C0 are inferred only from its 255-length argument.
