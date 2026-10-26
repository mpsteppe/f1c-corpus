# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposes eleven defensive classes for the generic runtime objects: TextWidget (init, word-wrap, cursor), DriverCareerStatsScreen, ScreenData, a DeferredCleanupObject destructor family (four teardown entry points), TimedAnimationController, ScrollbarRenderer, ScrollView plus its vtable dispatch slots, ScrollableListView (layout + clipped blit), a surface-region helper, and EditField. Owner classes are proposals only; most packet owners are UNKNOWN.

## Function roles

- `0x0047AAB0` **TextWidget** — Text widget initialization: sets text-source holder and margins, renders key aTtgjz, returns AIOvertakeGapCalc() (relation unresolved).
- `0x0047B730` **TextWidget** — Menu text word-wrap measurer/backtracker; called by the four menu layout/cursor helpers.
- `0x0047B9C0` **TextWidget** — Positions the menu cursor on wrapped text and renders the active menu item.
- `0x0047DD10` **DriverCareerStatsScreen** — Rebuilds the driver career statistics UI screen: header labels plus seven career-data rows from a string-keyed linked list.
- `0x0047F1F0` **Utility** — Utility clamp: clamps *a1 into [a2,a3] and returns the pre-clamp value.
- `0x0047F370` **ScreenData** — ScreenData object constructor: zeroes struct, installs TextureManager vtable, seeds three (min,max) range sentinels.
- `0x00485720` **DeferredCleanupObject** — Destructor: writes vtable, cleans sub-object at +224, chains base destructor, conditional free.
- `0x00485870` **DeferredCleanupObject** — Teardown freeing three owned buffer pointers plus two sub-object cleanups.
- `0x00485900` **DeferredCleanupObject** — Teardown freeing two owned buffer pointers plus two sub-object cleanups.
- `0x00486730` **TimedAnimationController** — Advances a timed UI animation: accumulates progress, fires repeat/alpha-blend refresh on threshold.
- `0x004868C0` **ScrollbarRenderer** — Renders a scrollbar track/thumb rectangle via texture sub-rect blit or solid-fill fallback.
- `0x00486AC0` **ScrollView** — Renders a scrollable view with dirty-flag invalidation, scaled/non-scaled quad paths, and state-select surface blit.
- `0x004881B0` **DeferredCleanupObject** — Two-pass teardown (sub-object + base) with conditional free.
- `0x004881F0` **SurfaceRenderRegionHelper** — UI element render/position setup with dual child-vs-bounds path and finalization vtable dispatch.
- `0x00489D00` **ScrollableListView** — Recalculates scrollable-list column/row counts, per-page count, and scroll span; clamps offsets.
- `0x0048A240` **ScrollableListView** — Renders scrollable list area with viewport clipping, scrollbar, and per-item custom dispatch.
- `0x0048B560` **EditField** — Filters input characters by edit-field type mode (1 = text, 2 = restricted).
- `0x0048B950` **EditField** — Edit-text cursor reset / default-string reload, mode-flagged.

## Proposed classes

### TextWidget

Menu text widget: initialization, word-wrap measurement, and cursor positioning over a double-indirect text-source pointer.

Methods: `0x0047AAB0`, `0x0047B730`, `0x0047B9C0`

- `this+0x000000C8` `void * source_object_ptr` (read, GUESS)
- `*(this+0xC8)+0x00000040` `char * resource_path_ptr` (read, GUESS)
- `this+0x000000E0` `char ** text_ptr_holder` (read_write, GUESS)
- `*(this+0xE0)+0x00000000` `char * text_ptr` (read, GUESS)
- `this+0x000000E4` `int cursor_index` (read_write, GUESS)
- `this+0x000000E8` `int zeroed_field` (write, GUESS)
- `this+0x000000EC` `int zeroed_field` (write, GUESS)
- `this+0x000000F8` `int margin_value` (write, GUESS)
- `this+0x000000FC` `int margin_value` (write, GUESS)
- `this+0x00000100` `int width_constraint` (read, GUESS)
- `this+0x00000110` `int zeroed_field` (write, GUESS)

### DriverCareerStatsScreen

Builds the driver career statistics menu screen by walking a career-data string-keyed linked list and rendering header labels and statistic rows.

Methods: `0x0047DD10`

- `this+0x00000044` `void * menu_list_head` (read_write, GUESS)
- `*(this+0x44)+0x00000000` `void * node_payload_ptr` (read, GUESS)
- `this+0x00000048` `void * menu_list_curr` (read_write, GUESS)
- `*(this+0x48)+0x00000004` `void * node_next_ptr` (read, GUESS)
- `this+0x0000004C` `void * menu_list_tail` (write, GUESS)
- `this+0x00000050` `void * menu_list_guard` (write, GUESS)

### ScreenData

ScreenData construction: zeroes the large struct, installs the TextureManager vtable, clears a texture flag, and seeds three (min,max) range sentinels.

Methods: `0x0047F370`

- `this+0x00000000` `void ** vtable_ptr` (write, GUESS)
- `this+0x0000210C` `byte texture_flag` (write, GUESS)
- `this+0x0000218C` `int range0_min` (write, GUESS)
- `this+0x00002190` `int range0_max` (write, GUESS)
- `this+0x00002194` `int range1_min` (write, GUESS)
- `this+0x00002198` `int range1_max` (write, GUESS)
- `this+0x0000219C` `int range2_min` (write, GUESS)
- `this+0x000021A0` `int range2_max` (write, GUESS)

### DeferredCleanupObject

Destructor-chain teardown family: runs ConditionalDualCleanup on embedded sub-objects, chains the base destructor sub_485EB0, frees owned buffers, and frees self only when the a2 low bit is set.

Methods: `0x00485720`, `0x00485870`, `0x00485900`, `0x004881B0`

- `this+0x00000000` `void ** vtable_ptr` (write, GUESS)
- `this+0x00000118` `void * owned_buffer_0` (read, GUESS)
- `this+0x00000120` `void * owned_buffer_1` (read, GUESS)
- `this+0x00000128` `void * owned_buffer_2` (read, GUESS)
- `this+0x00000154` `void * owned_buffer_3` (read, GUESS)

### TimedAnimationController

Advances a timed UI animation: resolves a config block, accumulates progress, fires a repeat/alpha-blend refresh, and advances the frame index.

Methods: `0x00486730`

- `this+0x00000040` `float time_delta_source` (read, GUESS)
- `this+0x00000080` `float progress_accumulator` (read_write, GUESS)
- `this+0x00000084` `int config_selector` (read, GUESS)
- `this+0x00000088` `int frame_index` (read_write, GUESS)
- `this+0x000000DC` `int repeat_count` (read_write, GUESS)

### ScrollbarRenderer

Renders a scrollbar track/thumb rectangle, substituting instance-default coordinates for the -50000 sentinel and choosing between texture sub-rect blit and solid-fill fallback.

Methods: `0x004868C0`

- `this+0x00000004` `int default_left` (read, GUESS)
- `this+0x00000008` `int default_right` (read, GUESS)
- `this+0x0000000C` `int default_top` (read, GUESS)
- `this+0x00000010` `int default_bottom` (read, GUESS)

### ScrollView

Renders a scrollable view: dirty-flag invalidation, scroll-mode texture-source selection, scaled/non-scaled quad rendering, and state-selected surface blit.

Methods: `0x00486AC0`

- `this+0x00000000` `void ** vtable_ptr` (read, GUESS)
- `this+0x00000004` `int tex_origin_x` (read, GUESS)
- `this+0x0000000C` `int tex_origin_y` (read, GUESS)
- `this+0x00000040` `int mode_intermediate` (read, GUESS)
- `this+0x00000065` `byte clip_active_flag` (read, GUESS)
- `this+0x0000006C` `byte dirty_flag` (read_write, GUESS)
- `this+0x00000078` `int scroll_mode` (read_write, GUESS)
- `this+0x00000084` `int scroll_index` (read, GUESS)
- `this+0x00000088` `int walk_steps` (read, GUESS)

### ScrollViewVTableSlots

Vtable dispatch slot offsets consumed by the scroll-view renderers on the object referenced through this+0; each slot number is the byte offset divided by four.

Methods: 

- `obj+0x00000008` `fn * slot_2` (read, GUESS)
- `obj+0x0000000C` `fn * slot_3` (read, GUESS)
- `obj+0x00000010` `fn * slot_4` (read, GUESS)
- `obj+0x00000014` `fn * slot_5` (read, GUESS)
- `obj+0x0000001C` `fn * slot_7` (read, GUESS)
- `obj+0x00000024` `fn * slot_9` (read, GUESS)
- `obj+0x0000002C` `fn * slot_11` (read, GUESS)
- `obj+0x00000034` `fn * slot_13` (read, GUESS)
- `obj+0x00000088` `fn * slot_34` (read, GUESS)
- `obj+0x000000A0` `fn * slot_40` (read, GUESS)
- `obj+0x000000A8` `fn * slot_42` (unknown, UNKNOWN)

### ScrollableListView

Scrollable list: layout recalculation (column/row counts, page size, scroll span) and viewport-clipped surface rendering with scrollbar.

Methods: `0x00489D00`, `0x0048A240`

- `this+0x00000004` `int bounds_left` (read, GUESS)
- `this+0x00000008` `int bounds_right` (read, GUESS)
- `this+0x0000000C` `int bounds_top` (read, GUESS)
- `this+0x00000010` `int bounds_bottom` (read, GUESS)
- `this+0x00000094` `int item_count_span` (read, GUESS)
- `this+0x000000C8` `void * source_object_ptr` (read, GUESS)
- `this+0x00000134` `int column_count` (write, GUESS)
- `this+0x00000138` `int row_count` (write, GUESS)
- `this+0x0000014C` `int scroll_offset` (read_write, GUESS)
- `this+0x00000150` `int scroll_position` (read, GUESS)
- `this+0x00000154` `int available_extent` (read_write, GUESS)
- `this+0x00000158` `int text_width` (read_write, GUESS)
- `this+0x0000015C` `int delegate_height` (write, GUESS)
- `this+0x00000160` `int content_height` (read, GUESS)
- `this+0x00000164` `int items_per_page` (write, GUESS)
- `this+0x0000016C` `int vertical_pixel_span` (write, GUESS)

### SurfaceRenderRegionHelper

UI element render/position setup with a dual path (structured child vs bounds fallback) writing the resulting rectangle to outputs.

Methods: `0x004881F0`

- `this+0x00000000` `void ** vtable_ptr` (read, GUESS)
- `this+0x00000004` `int left` (read, GUESS)
- `this+0x00000008` `int right` (read, GUESS)
- `this+0x0000000C` `int top` (read, GUESS)
- `this+0x00000010` `int bottom` (read, GUESS)

### EditField

Edit-text control: input character filtering by field type mode and cursor reset / default-string reload.

Methods: `0x0048B560`, `0x0048B950`

- `this+0x00000000` `void ** vtable_ptr` (read, GUESS)
- `this+0x000002E8` `int field_type` (read, GUESS)
- `this+0x000002F0` `char * buffer_ptr` (read_write, GUESS)
- `this+0x000002F4` `char * cursor_ptr` (read_write, GUESS)

## Compatibility contracts

- **TextWidgetFieldLayout** — Text widget stores a double-indirect text-source pointer at +0xE0, a source object at +0xC8 (path string at +0x40), cursor index at +0xE4, width constraint at +0x100, and margin values at +0xF8/+0xFC.
- **ScreenDataConstruction** — ScreenData constructor installs the TextureManager vtable 0x5A6E70, clears texture flag +0x210C, zeroes the texture-data region, and seeds three (min,max) = (0,-1) range pairs at +0x218C..+0x21A0.
- **DestructorChainAndFreeFlag** — Teardown runs ConditionalDualCleanup on embedded sub-objects (e.g. +224/+288/+304), chains the base destructor sub_485EB0, and frees self only when the a2 low bit is set.
- **CareerStatsScreenDataPath** — Driver career stats screen resolves the career-data root via the dword_7CD8C0 command interface vtable slot 7 with argument 17, indexes the result linked list, and renders seven rows keyed by nationality/dateofbirth/starts/poles/wins/driverschampio.
- **ScrollableListViewLayout** — Scrollable list stores boundary box at +0x4..+0x10, source object at +0xC8, column/row counts at +0x134/+0x138, scroll offset +0x14C, position +0x150, text width +0x158, content height +0x160, per-page count +0x164, and pixel span +0x16C.
- **EditFieldCharFilter** — Edit field stores type at +0x2E8, buffer at +0x2F0, cursor at +0x2F4; type 1 blocks backslash/slash/colon/period/leading space, type 2 allows only classified characters plus period and colon.
- **TimedAnimationConfigBlock** — Timed animation config block exposes a frame-count field at +0x10, a progress threshold at +0x18, and an advance mode at +0x1C (0 = clamp to frame count, 1 = wrap modulo).
- **RenderStateGlobal** — unk_7CDE00 is the global render state/context object read by the scrollbar, scroll-view, and surface-region render paths through the accessor/getter/field-reader trio.

## Unresolved

- TextWidget field this+0x108 is present in the packet field evidence but has no reference in the raw source of 0x0047AAB0 or 0x00489D00.
- Global dword_8AD3B4 (0x008AD3B4) appears in the packet globals but has no reference in the raw decompiled source of 0x0047DD10.
- AIOvertakeGapCalc is used as the return value of TextWidgetInit but is not listed among the packet callees; its relation to the text widget is unresolved.
- The obj+0xA8 field of the child structure returned by the vtable+168 dispatch in Surface_Render_Region_Setup is not reachable from the shown raw source.
- callers 0x0048B600 and 0x0048B810 of InputCharFilterByFieldType and field obj+0x0000002C in StringCursorReset have no visible reference in the decompiled source.
- The scroll-mode guard in RenderScrollView is ambiguous: raw C reaches the compared value through this+64 plus offset 56, while the deterministic guard table attributes the == 2 test to this+0x78.
- Class grouping (TextWidget, DeferredCleanupObject, ScrollView, ScrollableListView) is inferred from shared field semantics; equal byte offsets on different this objects are not proven common ownership.
- The career-data anchor at (result + 0x3C), the node byte flag at node+8, and the vtable slot at byte offset 28 of the dword_7CD8C0 object have no packet field evidence refs.
- Block-local offsets of the animation config and the scroll-item node layout (node+0/4/8/12 and next link) are not represented in the packet field table.
- The -50000 sentinel semantics, the 65793 and 986895/11206570 constants, and the a3 fallback flag meanings are inferred and not named by the packet.
- Semantics of vtable slots 28 and 36 dimension getters and the delegate-derived this+0x15C value in RecalculateListLayout are DERIVED from layout semantics, not directly evidenced.
- The 0xFF wrap delimiter, the a2 relative cursor delta, and the count returned by MenuCursorNavigationHelper in the cursor-positioning path are inferred from usage only.
- The a2 low-bit free semantics in the destructor family are inferred from the free(this) pattern and not independently confirmed.
