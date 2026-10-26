# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Wave-06 packet covering 29 generic runtime-object functions. Four structural conventions recur: (1) vtable pointer installed/reset at this+0x0, either at construction (0x0048FEB0) or restored during teardown (0x0048D3E0, 0x0048FD80, 0x0048E0D0, 0x0048E360, 0x00495300, 0x0048C0D0); (2) the MSVC scalar-deleting-destructor shape (run teardown body, then free the object iff (a2 & 1) != 0, return this) seen in 0x0048CA30, 0x0048E0B0, 0x0048FE90, 0x004952E0, 0x004902A0 and the in-body variant 0x0048FD80; (3) vtable-slot-driven UI widget behavior (change signal at obj+0x2C, dispatch slot at obj+0x40, child dispatch list at this+0xE0/0xE8/0xEC, scroll/counter value via obj+0xB4) shared by 0x0048D4B0, 0x0048D590, 0x0048F300, 0x00490640, 0x00490660, 0x0048EA60; and (4) container teardown walking arrays/linked lists and releasing nodes via FreeWrapper_7bcf (0x00490B90, 0x00491740, 0x00491770, 0x00495300). Most concrete class identities remain UNKNOWN; the classes proposed here are DERIVED groupings of functions that demonstrably share field offsets and vtable slots, and equal offsets on different objects (e.g. this+0xE0 as scroll value vs child-list head vs stored path) are NOT merged.

## Function roles

- `0x0048C0D0` **UnknownObject** — vtable_reinstall_helper: restores object vtable at this+0x0 to off_5ABF88 then delegates to an unresolved sub-call; runs inside a destruction/reset sequence.
- `0x0048CA30` **UnknownObject** — scalar_deleting_destructor_wrapper: runs LinkedListDestructor teardown then frees object iff (a2 & 1) != 0; returns this.
- `0x0048D3E0` **UIWidgetBase** — vtable_reset_and_base_teardown: resets vtable at this+0x0 to off_5AC1D0 then runs base teardown sub_485EB0 (unresolved); used in destructor sequences.
- `0x0048D4B0` **ScrollListControl** — scroll_progress_handler: normalizes scroll value to 0..1 and maps it to a thumb pixel position through vtable slots +24/+32/+44/+56/+176/+180; refreshes when the position changes.
- `0x0048D590` **ScrollListControl** — input_dispatch_navigation: scans short input codes, treats 203 as previous and 205 as next, increments/decrements the selection (integer field this+0xE0 or vtable+0xB4 counter) and signals the change via vtable slot +0x2C.
- `0x0048E0B0` **BinkVideoPlayer** — scalar_deleting_destructor_wrapper: runs media-player teardown body 0x0048E0D0 then frees object iff (a2 & 1) != 0; returns this.
- `0x0048E0D0` **BinkVideoPlayer** — media_player_destructor: resets vtable to off_5AC3E0, closes/frees the Bink handle at this+0xE0 via ConditionalFreeWithBinkClose when non-null, frees the secondary allocation at this+0xE8, then delegates to base teardown sub_485EB0.
- `0x0048E360` **FontResourceObject** — font_resource_destructor: resets vtable to off_5AC490, closes/frees the Bink handle at this+0xE4 via ConditionalFreeWithBinkClose when non-null, frees the secondary allocation at this+0xFC, then delegates to base teardown (ObjectInitWithVTableCleanup).
- `0x0048E6B0` **DirectoryChangeHandler** — directory_change_handler: appends self to a doubly linked list, compares current path (this+0xB8) with stored path (this+0xE0) defaulting to byte_5EA438, copies the new path on mismatch and fires the vtable+0xAC notification, then always refreshes via vtable+0x2C.
- `0x0048EA60` **UIWidgetBase** — point_in_rect_hit_test: returns 1 when point (a2,a3) is strictly inside the axis-aligned rect with origin this+0x14/this+0x18 and extent this+0xC/this+0x10; used by mouse/position hit testing.
- `0x0048F300` **UIWidgetBase** — state_reset_with_conditional_virtual_dispatch: zeroes byte flags this+0x17D/0x17E; when state this+0x104 != 4 resets it to 0 and dispatches vtable+0x40 with argument 0.
- `0x0048FD80` **ControlBase** — ui_control_destructor: restores vtable to off_5A443C, conditionally frees the child resource pointer at this+0x4, then frees the object itself when (a2 & 1) is set; returns this.
- `0x0048FE90` **UIWidgetBase** — scalar_deleting_destructor_wrapper: runs vtable/teardown init 0x0048FEB0 then frees object iff (a2 & 1) != 0; returns this.
- `0x0048FEB0` **UIWidgetBase** — vtable_init_constructor_helper: installs vtable off_5AC6B0 at this+0x0 then delegates remaining init to sub-initializer sub_485EB0.
- `0x004902A0` **UnknownObject** — conditional_teardown_with_vtable_notification: runs LinkedListDestructorWithVTableNotification teardown then frees object iff (a2 & 1) != 0; returns this.
- `0x00490640` **UIWidgetBase** — vtable_dispatch_init: dispatches the vtable+0x40 method with argument 0, then iterates the child dispatch list and returns its result.
- `0x00490660` **UIWidgetBase** — child_dispatch_list_iteration: walks the child linked list (head this+0xE0, count this+0xEC) and dispatches each child's vtable method at offset 16 with a bool derived from ShortComputation_6720; returns the child count.
- `0x00490B90` **MultiListContainer** — multi_list_destructor: destroys the 16-byte element array (count this+0x0, pointer this+0x8) and three embedded singly-linked lists (this+0xC, this+0x1C, this+0x2C), freeing array block and nodes; returns 0.
- `0x00491280` **BroadphaseList** — broadphase_filter_scan: iterates a singly-linked list (head this+0x0, cursor this+0x8) applying the sub_491680 filter to each node AABB quad; returns 1 on first match else 0.
- `0x00491740` **MultiListContainer** — conditional_multi_list_destructor: when the object pointer at this+0x0 is non-null, destroys it via MultiListDestruction and frees it via FreeWrapper_7bcf.
- `0x00491770` **IteratorArrayContainer** — destroy_all_iterators: destroys every list iterator in the container reached through *this (count obj+0x0, array obj+0x8) plus two embedded iterators; returns the final destruction result.
- `0x00491E10` **UnknownObject** — conditional_resource_cleanup: when the flag byte this+0x8 is non-zero and the pointer this+0x0 is non-null frees the embedded pointer; then frees self iff (a2 & 1) != 0; returns this.
- `0x00494C80` **UnknownObject** — line_segment_rect_clip: clips a 2D line segment against an axis-aligned rect whose width/height come from a1+28/+32, clamping and interpolating per axis; returns whether the clipped line retains non-zero extent.
- `0x004952E0` **TrackDatabase** — scalar_deleting_destructor_wrapper: runs track-database teardown body 0x00495300 then frees object iff (a2 & 1) != 0; returns this.
- `0x00495300` **TrackDatabase** — track_database_destructor: restores vtable to off_5AC998, destroys interior list containers and the segment list (this+0x18AC) and curve/section list (this+0xF0), frees several heap regions (this+0x1558, this+0x3C, four-slot run), walks the child-object list at this+0x4 invoking per-node vtable destructors, and zeroes the list heads.
- `0x00495790` **UnknownObject** — field_getter: reads the DWORD at this+0x1570 and returns it unchanged; used by UIScreenSelectionHandler.
- `0x004958D0` **UnknownObject** — sum_tree_values_with_recursion: sums ShortComputation_5920 over the linked list seeded by FieldGetter_8e30, then adds ShortComputation_8f60(a1) and a recursive TreeWalkerVirtualCallRecurse result; returns -1 when a1 is null.
- `0x00495A20` **RenderQueueList** — doubly_linked_list_node_unlink: splices node a2 out of a doubly linked list with head this+0x14 and tail this+0x18, fixing node next (+0x64) and previous (+0x68) links.
- `0x00495AE0` **RenderQueueList** — list_tail_pop_and_render_dispatch: pops the tail node of the render list (head this+0x14, tail this+0x18), unlinks it, dispatches its rectangle fields via GuardedSubRectangleRenderDispatch, and clears the node links.

## Proposed classes

### UIWidgetBase

DERIVED grouping of vtable-managed UI widget lifecycle/dispatch functions that share a vtable pointer at this+0x0, a state byte/flag region at this+0x104/0x17D/0x17E, a child dispatch list at this+0xE0/0xE8/0xEC, a rectangle region at this+0xC/0x10/0x14/0x18, and vtable dispatch slots +0x2C (refresh/change) and +0x40 (state dispatch). Construction/deconstruction both funnel through the shared base teardown sub_485EB0 (address not in packet).

Methods: `0x0048D3E0`, `0x0048FEB0`, `0x0048FE90`, `0x0048F300`, `0x00490640`, `0x00490660`, `0x0048EA60`

- `this+0x00000000` `void** vtable_ptr` (read_write, DERIVED)
- `this+0x0000000C` `float rect_width` (read, GUESS)
- `this+0x00000010` `float rect_height` (read, GUESS)
- `this+0x00000014` `float rect_left` (read, GUESS)
- `this+0x00000018` `float rect_top` (read, GUESS)
- `this+0x000000E0` `node* child_list_head` (read, DERIVED)
- `this+0x000000E8` `node* child_list_tail` (read, GUESS)
- `this+0x000000EC` `int child_count` (read, DERIVED)
- `this+0x00000104` `int state` (read_write, DERIVED)
- `this+0x0000017D` `unsigned __int8 flag_a` (write, DERIVED)
- `this+0x0000017E` `unsigned __int8 flag_b` (write, DERIVED)
- `obj+0x0000002C` `vtable slot (offset 44) refresh_or_change_vtable_slot` (read, DERIVED)
- `obj+0x00000040` `vtable slot (offset 64) state_dispatch_vtable_slot` (read, DERIVED)
- `*(this+0xE0)+0x00000000` `void* child_list_node_child_ptr` (read, DERIVED)
- `*(*(this+0xE0)+0x0)+0x00000010` `vtable slot (offset 16) of child object child_vtable_method_slot` (read, DERIVED)

### ScrollListControl

DERIVED grouping of scroll-bar / list-navigation UI control functions that share the selection/scroll value at this+0xE0, a storage-mode byte at this+0xF0, range bounds at this+0xF4/0xF8, and vtable slots +0x18/+0x20 (area extents), +0x2C (change signal), +0xA4 (post-update callback), +0xB0 (refresh), +0xB4 (mutable value pointer getter).

Methods: `0x0048D4B0`, `0x0048D590`

- `this+0x00000000` `void** vtable_ptr` (read, DERIVED)
- `this+0x000000E0` `int or float depending on mode flag selection_or_scroll_value` (read_write, DERIVED)
- `this+0x000000F0` `unsigned __int8 storage_mode_byte` (read, DERIVED)
- `this+0x000000F4` `float range_lower` (read, DERIVED)
- `this+0x000000F8` `float range_upper` (read, DERIVED)
- `obj+0x00000018` `vtable slot (offset 24) area_start_vtable_slot` (read, DERIVED)
- `obj+0x00000020` `vtable slot (offset 32) area_end_vtable_slot` (read, DERIVED)
- `obj+0x0000002C` `vtable slot (offset 44) change_signal_vtable_slot` (read, DERIVED)
- `obj+0x000000A4` `vtable slot (offset 164) post_update_callback_vtable_slot` (read, DERIVED)
- `obj+0x000000B0` `vtable slot (offset 176) refresh_vtable_slot` (read, DERIVED)
- `obj+0x000000B4` `vtable slot (offset 180) mutable_value_getter_vtable_slot` (read, DERIVED)

### DirectoryChangeHandler

Object that registers itself into a doubly linked list and refreshes its directory-path buffer (this+0xB8) when the stored path (this+0xE0) changes, firing a vtable+0xAC notification and always refreshing via vtable+0x2C.

Methods: `0x0048E6B0`

- `this+0x00000000` `void** vtable_ptr` (read, DERIVED)
- `this+0x000000B8` `char* current_path` (read_write, DERIVED)
- `this+0x000000E0` `char* stored_path` (read, DERIVED)
- `obj+0x0000002C` `vtable slot (offset 44) refresh_vtable_slot` (read, DERIVED)
- `obj+0x000000AC` `vtable slot (offset 172) change_notification_vtable_slot` (read, DERIVED)

### ControlBase

UI control object whose destructor restores its vtable (off_5A443C) and conditionally releases a child resource pointer at this+0x4 before self-free.

Methods: `0x0048FD80`

- `this+0x00000000` `void** vtable_ptr` (read_write, DERIVED)
- `this+0x00000004` `void* child_resource_ptr` (read_write, DERIVED)

### BinkVideoPlayer

Media player object holding a Bink video resource handle at this+0xE0 and a secondary heap allocation at this+0xE8; its destructor resets the vtable (off_5AC3E0), closes the Bink handle, frees the secondary allocation, and delegates to base teardown sub_485EB0.

Methods: `0x0048E0D0`, `0x0048E0B0`

- `this+0x00000000` `void** vtable_ptr` (read_write, DERIVED)
- `this+0x000000E0` `void* bink_handle` (read, DERIVED)
- `this+0x000000E8` `void* secondary_alloc` (read, DERIVED)

### FontResourceObject

Font resource object holding a Bink video resource handle at this+0xE4 and a secondary heap allocation at this+0xFC; its destructor resets the vtable (off_5AC490), closes the Bink handle, frees the secondary allocation, and delegates to base teardown ObjectInitWithVTableCleanup.

Methods: `0x0048E360`

- `this+0x00000000` `void** vtable_ptr` (read_write, DERIVED)
- `this+0x000000E4` `void* bink_handle` (read, DERIVED)
- `this+0x000000FC` `void* secondary_alloc` (read, DERIVED)

### MultiListContainer

Container object holding an array of 16-byte list elements (count this+0x0, array this+0x8) plus three embedded singly-linked lists (heads this+0xC, this+0x1C, this+0x2C) and a trailing region at this+0x3C; fully destroyed by MultiListDestruction (0x00490B90), conditionally via 0x00491740.

Methods: `0x00490B90`, `0x00491740`

- `this+0x00000000` `int element_count` (read, DERIVED)
- `this+0x00000008` `element16* array_ptr` (read, DERIVED)
- `this+0x0000000C` `list header (4 DWORDs) first_sub_list_head` (read_write, DERIVED)
- `this+0x0000001C` `list header (4 DWORDs) second_sub_list_head` (read_write, DERIVED)
- `this+0x0000002C` `list header (4 DWORDs) third_sub_list_head` (read_write, DERIVED)
- `this+0x0000003C` `4-DWORD region passed to EmptyStub_0170 trailing_region` (read, GUESS)
- `*(this+0xC)+0x00000000` `void* first_list_node_value` (read, DERIVED)
- `*(*(this+0xC)+0x4)+0x00000004` `node* first_list_node_next` (read, DERIVED)
- `*(this+0xC)+0x00000008` `unsigned __int8 first_list_node_flags` (read, DERIVED)
- `*(this+0x1C)+0x00000000` `void* second_list_node_value` (read, DERIVED)
- `*(*(this+0x1C)+0x4)+0x00000004` `node* second_list_node_next` (read, DERIVED)
- `*(this+0x1C)+0x00000008` `unsigned __int8 second_list_node_flags` (read, DERIVED)
- `*(this+0x2C)+0x00000000` `void* third_list_node_value` (read, DERIVED)
- `*(*(this+0x2C)+0x4)+0x00000004` `node* third_list_node_next` (read, DERIVED)
- `*(this+0x2C)+0x00000008` `unsigned __int8 third_list_node_flags` (read, DERIVED)

### IteratorArrayContainer

Container reached through a pointer-to-pointer that owns an array of 16-byte list iterators (count obj+0x0, array obj+0x8) plus two embedded iterators, all destroyed by DestroyAllIterators.

Methods: `0x00491770`

- `this+0x00000000` `void* container_ptr` (read, DERIVED)
- `obj+0x00000000` `int element_count` (read, DERIVED)
- `obj+0x00000008` `iterator16* iterator_array` (read, DERIVED)

### BroadphaseList

Singly-linked list object used for collision/broadphase filtering: head at this+0x0, iteration cursor at this+0x8, nodes carrying an AABB coordinate quad tested by the sub_491680 filter.

Methods: `0x00491280`

- `this+0x00000000` `node* list_head` (read, DERIVED)
- `this+0x00000008` `node* iteration_cursor` (read_write, DERIVED)
- `obj+0x00000000` `void* head_node_value` (read, DERIVED)
- `*(this+0x8)+0x00000004` `node* list_node_next` (read, DERIVED)
- `*(*(this+0x8)+0x4)+0x00000000` `void* list_node_value_ptr` (read, DERIVED)
- `*(*(*(this+0x8)+0x4)+0x0)+0x00000000` `short aabb_coord_0` (read, DERIVED)
- `*(*(*(this+0x8)+0x4)+0x0)+0x00000002` `short aabb_coord_1` (read, DERIVED)
- `*(*(*(this+0x8)+0x4)+0x0)+0x00000004` `short aabb_coord_2` (read, DERIVED)
- `*(*(*(this+0x8)+0x4)+0x0)+0x00000006` `short aabb_coord_3` (read, DERIVED)

### TrackDatabase

GUESS-named object whose destructor (0x00495300) is the only packet member; it is a large container holding child objects (list at this+0x4), a curve/section list (this+0xF0), a segment list (this+0x18AC), interior list containers and several heap regions. The 'track database' semantics come from the packet's ABI lead name and are not independently proven.

Methods: `0x00495300`, `0x004952E0`

- `this+0x00000000` `void** vtable_ptr` (read_write, DERIVED)
- `this+0x00000004` `list header (4 DWORDs) child_list_head` (read_write, DERIVED)
- `*(this+0x4)+0x00000000` `void* child_node_data` (read, DERIVED)
- `*(this+0x4)+0x0000000C` `unsigned __int8 child_node_flag_byte` (read, DERIVED)
- `*(*(this+0x4)+0x4)+0x00000004` `node* child_node_next` (read, DERIVED)
- `*(*(*(this+0x4)+0x0)+0x0)+0x00000000` `vtable slot 0 of child object child_vtable_destructor_slot` (read, DERIVED)
- `this+0x000000F0` `list header (4 DWORDs) curve_section_list_head` (read_write, DERIVED)
- `*(*(this+0xF0)+0x4)+0x00000004` `node* curve_list_node_next` (read, DERIVED)
- `this+0x00001558` `void* secondary_alloc` (read, DERIVED)
- `this+0x0000003C` `void* heap_block` (read, DERIVED)
- `this+0x000018AC` `list header (4 DWORDs) segment_list_head` (read_write, DERIVED)
- `*(*(this+0x18AC)+0x4)+0x00000004` `node* segment_list_node_next` (read, DERIVED)

### RenderQueueList

Doubly linked render list with head at this+0x14 and tail at this+0x18, whose nodes carry next/previous links at +0x64/+0x68; supports node unlink (0x00495A20) and tail-pop with rectangle render dispatch (0x00495AE0).

Methods: `0x00495A20`, `0x00495AE0`

- `this+0x00000014` `node* list_head` (read_write, DERIVED)
- `this+0x00000018` `node* list_tail` (read_write, DERIVED)
- `*(this+0x78)+0x00000064` `node* node_next_link` (read, DERIVED)

## Compatibility contracts

- **VtablePointerAtOffsetZero** — Every object in this subsystem stores its active vtable pointer at this+0x0. Construction installs the class vtable there (0x0048FEB0, off_5AC6B0); destruction restores the class vtable before running teardown (off_5AC1D0, off_5AC3E0, off_5AC490, off_5A443C, off_5AC998, off_5ABF88). A replacement must keep the vtable slot at offset 0 and reinstall the original vtable at the start of each destructor.
- **ScalarDeletingDestructorFlagBit0** — All scalar-deleting-destructor wrappers free the object memory if and only if the low bit (a2 & 1) of the deletion-flag argument is set; the teardown body runs unconditionally first and the original this pointer is returned. A replacement must preserve this convention for callers that invoke deleting-destructors.
- **UIWidgetVtableSlotIndices** — UI widget objects dispatch behavior through fixed vtable slots: +0x2C change/refresh signal, +0x40 state dispatch, +0xAC directory-change notification, +0xB0 refresh, +0xB4 mutable value getter, +0xA4 post-update callback, +0x18/+0x20 area-extent getters, and child dispatch method at offset +0x10 on child vtable. A replacement UI system must keep these slot indices stable.
- **UIChildDispatchListLayout** — UI widget children are stored in a linked list with head at this+0xE0 and count at this+0xEC; each node holds the child object at node+0x0 and the child's dispatch method is at child-vtable+0x10. A replacement must reproduce this walk for child dispatch.
- **BinkResourceReleaseOnDestruct** — Objects that own a Bink video resource handle must close and free it (via ConditionalFreeWithBinkClose) during destruction, and also free the secondary heap allocation, before the base teardown runs.
- **MultiListContainerLayout** — The multi-list container holds an array of 16-byte elements (count this+0x0, pointer this+0x8, with a 4-byte count header preceding the block) and three embedded singly-linked lists at this+0xC, this+0x1C, this+0x2C whose nodes carry a value at +0x0, next at +0x4 and a flags byte at +0x8. Destruction must drain the array (in reverse) and every list, freeing each node.
- **RenderListHeadTailOffsets** — The doubly linked render list keeps head at this+0x14 and tail at this+0x18; node links live at node+0x64 (next) and node+0x68 (previous). Unlink and tail-pop must maintain head/tail and splice links so the tail marker stays consistent.

## Unresolved

- Concrete class identity is UNKNOWN for most objects: off_5ABF88 (HUD timer vtable), off_5AC1D0/off_5AC6B0 (widget vtable), off_5AC3E0 (media player), off_5AC490 (font resource), off_5A443C (control base) and off_5AC998 (track-database) are not resolved to named types by this packet.
- The shared base teardown sub_485EB0 (called by 0x0048D3E0, 0x0048FEB0, 0x0048E0D0, 0x0048E360) has no address in this packet; its contract is unverified and it cannot be cited as a callee evidence ref.
- 0x0048C0D0 delegates to VTableSetterSubCall_b4e0 whose address is absent from the packet; the call target cannot be cited.
- Global dword_8AFE64 appears in static analysis of 0x0048E0D0 and 0x0048E360 but not in their raw bodies; role unconfirmed.
- flt_59E440 and flt_59E450 (listed as accessed by 0x0048D4B0) are not directly referenced in the raw source; the mapping to the 0.0 / 0.5 constants (ZeroThreshold / DegreesToRadians per existing analysis) is not adopted here. flt_59E440 is used as the zero threshold by 0x00494C80.
- Offset this+0xE0 carries three different meanings across different object bases: selection/scroll value (ScrollListControl), child-list head (UIWidgetBase) and stored path (DirectoryChangeHandler). They are kept as separate fields in separate classes per the equal-offset rule; the packet does not prove common ownership.
- The storage-mode byte at this+0xF0 and the pointer-mode counter via vtable+0xB4 in 0x0048D590 are inferred from two parallel mutation paths, not fully classified.
- Semantics of input codes 203/205 as previous/next navigation come from existing analysis, not independently proven.
- The vtable+0x40 dynamic target, the meaning of state constant 4 (0x0048F300) and the meaning of the ShortComputation_6720 range 3..5 flag (0x00490660) are not resolvable from this packet.
- The purpose of the unused parameter a2 in 0x00491280 is unknown; sub_491680's filter semantics are caller/callee-defined.
- The null branch of 0x00491740 returns an uninitialized result variable, a decompiler artifact of a compiler-proven-unreachable path.
- In 0x00495AE0 the node offset +100 (0x64) serves as both the next link and a tail-marker flag; its exact meaning is not confirmed, and roles of this+0x1C/0x20/0x24/0x28/0x78/0x7C/0x80/0xE4 are unresolved (0x1C..0x28 are sub-list heads in MultiListContainer).
- 0x00495300 interior offsets 0x18DC/0x18CC/0x18BC (list containers), 0x18A4 (ListCleanup target), 0x16F4 (EmptyStub target), 0x168C (MultiList target) and the four-slot run ending at this+0x162C are not declared packet fields; their contents are unevidenced beyond the calls.
- The child-list node layout of 0x00495300 (flag byte +0xC, vtable/data at +0) is inferred from the dereference pattern; no node struct is evidenced.
- ShortComputation_1e60 and EmptyStub_0170 semantics (beyond conditional invocation) are unknown; the meaning of their constant argument 1 is unknown.
- FreeWrapper_7bcf identity as the global operator delete is DERIVED from its name only and is not independently proven.
- The meaning of the field at this+0x1570 (0x00495790) and of the -1 sentinel / per-node semantics in 0x004958D0 are unidentified.
- IteratorArrayContainer's sole caller sub_485B90 (0x00485B90) is outside the allowed evidence set and is not cited.
- The node layout at node+72 for the 0x004958D0 linked list and node+0x64/+0x68 for the render list are only evidenced by the pointer math of the accessing functions.
- The a2 bit-0 self-free flag convention (0x00491E10) is read from the raw source only; the packet provides no dedicated guard evidence for it.
