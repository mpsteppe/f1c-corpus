# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

DERIVED architecture for the wave_004_generic_runtime_objects_23 packet: 31 functions grouped into five proposed classes by shared field-access evidence (ViewportBoundsObject, DrawableNodeListManager, AudioUiStateObject, SurfaceCompositorObject, StreamConfigObject). The remaining functions are left ownerless; their fields, globals and callees are recorded in function-role and dependency evidence. All class identities, field names and semantics are DERIVED/GUESS proposals pending independent verification.

## Function roles

- `0x005424E0` **ViewportBoundsObject** — Reads four dword fields of the object into four null-guarded caller output pointers and returns the last output pointer.
- `0x00542520` **UnknownObject** — Getter that reads this+0x4 and this+0x8 into two null-guarded output pointers and returns the a3 pointer.
- `0x005425A0` **ViewportBoundsObject** — Projects a 3D point to screen space via the indirect transform call behind global 0x008B8F24, truncates to integers, and clamps both axes to the object's viewport bounds.
- `0x00542680` **UnknownObject** — Setter writing the float parameter into this+0x88 only when the parameter is strictly positive; non-positive values are rejected.
- `0x005426E0` **StreamConfigObject** — Maps a stream-mode value (1-13) to a bitmask, stores mode and mask into the object, reports undefined video stream modes, and returns -1/0.
- `0x00542950` **StreamConfigObject** — Stores stream parameters (a5 into this+0x18, a2 into this+0x1C, a3 into this+0x20) after mode validation, and registers the object with the sound/stream manager singleton when the low nibble of a5 is set.
- `0x00542EC0` **StreamConfigObject** — Locates a bitmap filename across the registered data directories and the object list; derives a 4-bit format mode from this+0x18 and logs failure when the walk count matches the expected count.
- `0x00543210` **UnknownObject** — Argument-reordering dispatch shim: forwards the global dispatch context dword_8B78A0, this, and the two swapped arguments to VTableDispatchByFlags and returns its result unchanged.
- `0x005432F0` **SurfaceCompositorObject** — Renders a clipped 2D rectangle onto the global surface target: derives or takes the rectangle, normalizes corners via the clip helper, and composites when both clipped dimensions are positive.
- `0x00543440` **SurfaceCompositorObject** — Clipped 2D surface draw: clips draw parameters in place, blits/fills the global surface when both clipped dimensions are positive, and clears status bit 0x400 of this+0x18 on success.
- `0x005434A0` **SurfaceCompositorObject** — Fills a rectangle on the global surface from object dimensions scaled by factors, normalizes via the clip helper, and clears the 0x400 status bit in this+0x18 after a successful fill.
- `0x005435C0` **SurfaceCompositorObject** — Index setter writing the argument into this+0x34 and returning it unchanged; interpreted as a texture-surface index by prior analysis (DERIVED, unconfirmed).
- `0x005438B0` **AudioUiStateObject** — Updates left/right pan values (this+0x194/0x198) with a non-negative left-pan guard and marks the object dirty via flag bit 0x10000 in this+0xEC.
- `0x00543920` **AudioUiStateObject** — Writes the parameter into the float field this+0x190 only when it lies in [0.0, 1.0] and sets flag bit 0x10000 in this+0xEC on success; out-of-range values are rejected silently.
- `0x00543960` **AudioUiStateObject** — Records a display-mode constant (0x20000/0x40000/0x80000 or 0) at this+0x19C and ORs the 0x10000 UI-update flag into this+0xEC on every path.
- `0x005439F0` **AudioUiStateObject** — Copies three 16-bit fields (this+0x188, 0x18A, 0x18C) into null-guarded caller output pointers and returns the fourth argument pointer.
- `0x00543A30` **AudioUiStateObject** — Copies this+0x194 and this+0x198 into two null-guarded caller output pointers and returns the a3 pointer.
- `0x00544C50` **UnknownObject** — Recursive tree accumulation: walks sibling/child node chains, increments child and visitation counters, and folds entry data into the selected accumulator slot.
- `0x00544DB0` **UnknownObject** — Recursively processes first/second children with error abort, then walks the list at this+0x204 returning -1 as soon as the per-node check reports an error.
- `0x00544E90` **UnknownObject** — Allocates a 444-byte sound-instance object, runs its constructor init and name configuration, stores the caller this-pointer as its first field, publishes it through the optional out-argument, and returns 0/-1.
- `0x00544F50` **UnknownObject** — Two-level linked-list search for a node whose string at node+0x8C equals the argument, returning the matching first- or second-level node or 0.
- `0x00545430` **UnknownObject** — Factory: allocates a 112-byte drawable object, initializes it, copies a string, registers it with the drawable node manager, and writes the result through the output parameter.
- `0x005455F0` **DrawableNodeListManager** — Unlinks a node from a category-tagged doubly-linked list (category from *a2 & 7) and decrements the corresponding category counter; advances the head when it pointed at the removed node.
- `0x00545670` **DrawableNodeListManager** — Copies this+0x11C, this+0x124 and this+0x12C into three null-guarded caller output pointers and returns the third pointer.
- `0x005456B0` **DrawableNodeListManager** — Searches the three category node lists for a node whose name string at node+88 equals the argument, walking each list via its counter and head and advancing along node+0x6C next pointers.
- `0x005457C0` **DrawableNodeListManager** — Indexed lookup over the category-1 list (count this+0x11C, head this+0x120) with bounds check and walk along node+0x6C next pointers.
- `0x005457F0` **DrawableNodeListManager** — Indexed lookup over the category-2 list (count this+0x124, head this+0x128) with bounds check and walk along node+0x6C next pointers.
- `0x00545820` **DrawableNodeListManager** — Indexed lookup over the category-3 list (count this+0x12C, head this+0x130) with bounds check and walk along node+0x6C next pointers.
- `0x005458D0` **AudioUiStateObject** — Selects or clears the 0x200000/0x400000 flag bits in this+0xEC according to the argument (0 clear, 1 set 0x200000, 2 set 0x400000) and returns the selector unchanged.
- `0x00546230` **UnknownObject** — Configuration entry point persisting a callback pointer and integer argument into globals dword_8B8F00/dword_8B8EFC and returning the callback pointer.
- `0x00546FE0` **UnknownObject** — Guarded configuration apply: when the argument lies strictly between the value at this+0xA4 and 8, runs a fixed group of four field setters with constants; always returns 0.

## Proposed classes

### ViewportBoundsObject

Holds a viewport-bounds rectangle expressed as X/Y minima plus per-axis extents and exposes them through multi-output getters; also performs screen-space clamping of projected points against those bounds.

Methods: `0x005424E0`, `0x005425A0`

- `this+0x00000054` `float boundExtentWidth` (read, GUESS)
- `this+0x00000058` `float boundExtentHeight` (read, GUESS)
- `this+0x00000064` `float boundMinY` (read, GUESS)
- `this+0x00000068` `float boundMinX` (read, GUESS)

### DrawableNodeListManager

Manages three category-tagged node lists, each carrying a counter and a head pointer. Provides indexed access, by-name lookup, and category-aware node unlink. Node next links are read at node+0x6C from the link-base objects stored at this+0x18C/0x194/0x19C.

Methods: `0x005455F0`, `0x00545670`, `0x005456B0`, `0x005457C0`, `0x005457F0`, `0x00545820`

- `this+0x0000011C` `dword category1Count` (read, DERIVED)
- `this+0x00000120` `pointer category1Head` (read, DERIVED)
- `this+0x00000124` `dword category2Count` (read_write, DERIVED)
- `this+0x00000128` `pointer category2Head` (read_write, DERIVED)
- `this+0x0000012C` `dword category3Count` (read, DERIVED)
- `this+0x00000130` `pointer category3Head` (read, DERIVED)
- `*(this+0x18C)+0x0000006C` `pointer category1NodeNext` (read, DERIVED)
- `*(this+0x194)+0x0000006C` `pointer category2NodeNext` (read, DERIVED)
- `*(this+0x19C)+0x0000006C` `pointer category3NodeNext` (read, DERIVED)

### AudioUiStateObject

Holds audio/UI state in the 0x188-0x19C region plus a shared dirty-flags dword at this+0xEC (bit 0x10000 marks an update). Provides guarded setters (bounded float, display mode, pan pair) and multi-output getters. Field roles are hedged; the audio/pan and UI interpretations come from prior analysis.

Methods: `0x005438B0`, `0x00543920`, `0x00543960`, `0x005439F0`, `0x00543A30`, `0x005458D0`

- `this+0x000000EC` `dword dirtyFlags` (read_write, DERIVED)
- `this+0x00000188` `word shortField188` (read, GUESS)
- `this+0x0000018A` `word shortField18A` (read, GUESS)
- `this+0x0000018C` `word shortField18C` (read, GUESS)
- `this+0x00000190` `float boundedFloat190` (write, GUESS)
- `this+0x00000194` `float value194` (read_write, GUESS)
- `this+0x00000198` `float value198` (read_write, GUESS)
- `this+0x0000019C` `dword displayMode` (write, GUESS)

### SurfaceCompositorObject

2D surface compositing object: holds a status/flags dword (bit 0x400 cleared after a successful blit) and source dimensions; draws and fills rectangles onto the global surface target at 0x008B78A0 after clip normalization.

Methods: `0x005432F0`, `0x00543440`, `0x005434A0`, `0x005435C0`

- `this+0x00000018` `dword statusFlags` (read_write, DERIVED)
- `this+0x0000001C` `float surfaceWidth` (read, DERIVED)
- `this+0x00000020` `float surfaceHeight` (read, DERIVED)
- `this+0x00000034` `dword textureSurfaceIndex` (write, GUESS)

### StreamConfigObject

Stream/sound configuration object: maps a video stream mode (1-13) to a bitmask, stores the mode and parameters, registers with the manager singleton at 0x008B78A0, and drives bitmap-file lookup using the low nibble of this+0x18 as a format mode and the registered data directories.

Methods: `0x005426E0`, `0x00542950`, `0x00542EC0`

- `this+0x00000018` `dword modeAndStatus` (read_write, DERIVED)
- `this+0x0000001C` `dword configValue1C` (write, GUESS)
- `this+0x00000020` `dword configValue20` (write, GUESS)
- `this+0x00000024` `dword modeBitmask` (write, DERIVED)
- `this+0x00000030` `dword modeValue` (write, DERIVED)

## Compatibility contracts

- **SurfaceBlitClearStatusBit** — After a successful 2D surface blit/fill against the global surface context at 0x008B78A0, the 0x400 status bit in this+0x18 must be cleared; a replacement must reproduce this ordering.
- **StreamModeToBitmaskMapping** — Stream-mode values 1-13 map to bitmask flags stored at this+0x24 (1, 2, 4, 8, 16, 24, 32) alongside the raw mode at this+0x30; a replacement consumer of this object must honor the mapping.
- **ViewportClampSemantics** — Screen-space X clamps to [this+0x68, this+0x68+this+0x54] and Y to [this+0x64, this+0x64+this+0x58] after perspective division; a replacement viewport projector must preserve this geometry.
- **BitmapSearchDirectoryContract** — Bitmap lookup proceeds only when the argument is non-null and the audio-init flag dword_8B8E28 is set, searching the default directory then each registered directory and the object list; returns -1 when not found.

## Unresolved

- All owner identities are UNKNOWN in the packet; the five proposed classes are groupings grounded in shared field-access evidence, not proven common ownership.
- Field offsets 0x18/0x1C/0x20 appear in both StreamConfigObject and SurfaceCompositorObject, and global 0x008B78A0 is used both as the sound/stream manager singleton and as the surface compositing target; this is consistent with a single video-manager object but the packet does not prove common ownership (rule 8).
- Global 0x0059E43C is listed as a read global but does not appear in the raw source text of any function; it cannot be tied to an operation.
- The viewport interpretation of fields 0x54/0x58/0x64/0x68 (minima plus extents) is grounded only in the clamp shape of 0x005425A0; the field names in ViewportBoundsObject are GUESS and the packet explicitly did not adopt the prior fill's viewport-dimension interpretation for GetFourFields.
- The category mapping (1/4/2) of the three node lists and the relationship between the node next-pointer link bases (*(this+0x18C)/0x194/0x19C) and the head pointers at this+0x120/0x128/0x130 are not reconciled by the packet.
- The texture-surface-index meaning of field 0x34 (0x005435C0) and the audio/pan/UI interpretations of the 0x188-0x19C fields and the 0x10000 flag in this+0xEC come from prior analysis and are DERIVED/GUESS, not independently confirmed.
- Functions kept ownerless (0x00542520, 0x00542680, 0x00543210, 0x00544C50, 0x00544DB0, 0x00544E90, 0x00544F50, 0x00545430, 0x00546230, 0x00546FE0) have no evidenced shared object identity; their fields, globals and callees are recorded in role and dependency evidence.
- The StreamModeConfigSetter switch is a mode-to-bitmask mapping (jpt_542716), not a state machine; it is intentionally not modeled in state_machines.
- The per-frame surface-draw callers (ConditionalSubsystemCallWithParameter 0x00408DE0, etc.) suggest a shared subsystem call site, but the dispatch relationship is not modeled here.
- TreeNodeAccumulator may write a second accumulator slot at this+0x40 when the node flag bit 0x10 is set; that slot is not present in the packet field table.
- The low-three-bit category tag in *a2 used by DoublyLinkedListRemove (0x005455F0) and the exact meaning of the a2 flag gating the second-child recursion in PriorityQueueRecursiveProcess (0x00544DB0) are not established.
- The registered-directories array (byte_8B5A3C, stride 132, count dword_8B8E30) and the linked-list walk contract of sub_560050 are inferred from the LocateBitmapFile call pattern, not proven.
- The comparison precision of the dbl_59E420/dbl_59E430 constants versus the 32-bit float fields in 0x00543920 is not established.
