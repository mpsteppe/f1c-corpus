# UIPlatformAndOptions

Scope: `ui_platform_and_options`  
Trust: `DERIVED`

The packet covers the UI platform and options subsystem: a constructor template shared by many UI elements (base-init, vtable install, bound-data pointer at +0x31C, config flags at +0x324..+0x330, value preset at +0x334, text-handle list registration) with display-update methods that format values into a checked buffer and push them to the UI edit buffer; menu page objects that rebuild an entry linked list at +0x44..+0x50 (race-standings pages, team statistics, game options by category); list-driven browsers (network game sessions, VCR replay files); a menu-item text-fit measurer and a render dispatcher that resolves string-table tokens, derives alignment, fits/truncates text, and draws by alignment mode; and a UI list destructor. Owners are largely UNKNOWN in the packet; only the camera constructor carries a DERIVED owner label (UICamera). Architecture is a DERIVED/GUESS proposal; equal offsets on base 'this' are grouped conservatively and contested dual-use fields are flagged in unresolved.

## Function roles

- `0x004732D0` **UIElementBase** — Display-update method: stores the driving-mode globals, applies driving-mode parameters, reads the list-index value through the double-dereferenced pointer at +0x320, formats it into a checked stack buffer, and pushes the string into the UI edit buffer; returns 0.
- `0x00473430` **UIElementBase** — UI element constructor: base-init, vtable off_5A2880 install, bound-data pointer to dword_7D032C at +0x31C, config flags 1/0/1/1, preset 271 at +0x334, registration of two text-handle nodes.
- `0x004735B0` **UIElementBase** — Counter display update: returns 0 immediately when the global dword_7D0110 equals the cached value at +0x31C, else caches it and formats a list string or the raw integer ('%d') into the edit buffer; returns 0.
- `0x00473CC0` **UIElementBase** — Constructor: base-init, vtable off_5A3000, pointer to the AuthorizationBypassFlag global dword_7CF638 at +0x31C, flags 1/0/1/1, preset 381, two text-handle nodes, virtual dispatch init.
- `0x00473DD0` **UIElementBase** — Constructor: base-init, vtable off_5A3180, pointer to unk_7CFBD8 at +0x31C, flags 1/0/1/1, preset 383, two text-handle nodes, virtual dispatch init.
- `0x00473E50` **UIElementBase** — Constructor: base-init, vtable off_5A3240, pointer to unk_7CFBB4 at +0x31C, flags 1/0/1/1, preset 384, two text-handle nodes, virtual dispatch init.
- `0x00473ED0` **UIElementBase** — Constructor: base-init, vtable off_5A3300, pointer unk_7CFD10 at +0x31C, flags 1/0/1/1, preset 385, text nodes off_5C32A4 and aHigh, virtual dispatch init.
- `0x00473F50` **UIElementBase** — Constructor: base-init, vtable off_5A33C0, pointer dword_7CFC68 at +0x31C, flags 2/0/1/1, preset 386, three text nodes (off_5BE704, off_5C32A4, aHigh); no virtual dispatch init.
- `0x00473FD0` **UIElementBase** — Constructor: base-init, vtable off_5A3480, data-source pointer unk_7CF764 at +0x31C, state fields 2/0/1/1, component id 387 at +0x334, three text nodes, virtual dispatch init.
- `0x00474900` **UICamera** — Camera UI constructor: base-init, vtable off_5A3CC0, data pointer unk_7CFC44 at +0x31C, config flags 1/0/1/1, preset 398, text nodes off_5BE704 and aOn, virtual dispatch init.
- `0x00474F40` **UIListTextItem** — Constructor/initializer: base-init sub_48C070, vtable off_5A4200, registration of two resource nodes (unk_5C6E18, off_5C6E14) with index -1; no guards.
- `0x00475150` **UINetworkGameBrowser** — Network game browser list update: reads search text, notifies state cleanup, sorts sessions by filter, builds one menu row per session (description + translated name + '%d/%d' players + '%d' id), sets row outline color by locked/joined and player-count flags, restores search selection, and shows a Searching/No-games-available status item when no rows exist.
- `0x004761C0` **UIGameFilterObject** — Game-filter UI object constructor: base UI object constructor, zeroes the query/index at +0x40, sets record sentinel -1 at +0x44, installs the off_5A4478 vtable; called once by GameFilterSetup.
- `0x0047B910` **UIMenuItemLayoutHelper** — Menu-item text-fit measurer: loads the text buffer pointer at +0xE0, measures characters against the available width with TextRenderToSurface, and returns the character index at which the menu-item text must be truncated.
- `0x0047BF30` **VcrFileBrowser** — VCR replay file browser rebuild: scans the replay directory with the aVcr_0 pattern, strips file extensions, creates one UI menu item per file, re-selects the saved file name, and resets the search-result list.
- `0x0047C360` **UIMenuPage** — Menu page rebuild: frees the entry-list node chain at +0x44, notifies state cleanup, stores the page direction at +0x174, builds one menu item per race-standings entry (scene name + position number), skips names already present, installs red/black title strings and the list management handler for the page direction.
- `0x0047E0A0` **UIMenuPage** — Team statistics menu build: resolves the team record through the global accessor, frees and clears the entry list at +0x44, inserts seven stat category headers, creates seven formatted stat menu items plus a final separator-only item.
- `0x0047E960` **UIMenuPage** — Game options constructor: base vtable init, clears the legacy list at +0x44, stores the option category argument at +0xF4, then inserts the label set selected by category via the jump table (Allowed/Disallowed, On/Off, Normal+X2..X7, Normal/TimeScaled/SelectedSeason).
- `0x00485960` **UIListObject** — List object destructor: frees three buffer pointers (+0x150/+0x158/+0x160), runs conditional cleanup on two sub-objects (+0xE0/+0x118), chains to the base destructor, and frees the object itself when the delete flag is set.
- `0x00488BE0` **UIRenderDispatcher** — Main text render dispatcher: resolves the stored text through the string table when flagged, derives the alignment mode from the alignment string, measures and fits/truncates the text against the width limit, re-centers on overflow, dispatches the draw by alignment mode, and writes the final rectangle to out-parameters; returns 0.

## Proposed classes

### UIElementBase

Shared UI element template used by most constructors in the packet: base-init via ShortComputation_6d60(this, 1), vtable install, bound-data pointer at +0x31C, four config/state fields at +0x324..+0x330, value preset at +0x334, and registration of text-handle nodes into an internal linked list. Also hosts display-update methods that format a list string or integer into a checked stack buffer and push it into the UI edit buffer.

Methods: `0x004732D0`, `0x004735B0`, `0x00473430`, `0x00473CC0`, `0x00473DD0`, `0x00473E50`, `0x00473ED0`, `0x00473F50`, `0x00473FD0`

- `this+0x00000000` `void* vtable_ptr` (write, DERIVED)
- `this+0x0000031C` `void* bound_data_ptr` (read_write, GUESS)
- `this+0x00000320` `void* list_index_data_ptr` (write, DERIVED)
- `this+0x00000324` `int config_flag_0` (read_write, DERIVED)
- `this+0x00000328` `int config_flag_1` (write, DERIVED)
- `this+0x0000032C` `int config_flag_2` (write, DERIVED)
- `this+0x00000330` `int config_flag_3` (write, DERIVED)
- `this+0x00000334` `int value_preset` (write, DERIVED)

### UICamera

Camera control UI element constructed with the same template as UIElementBase: base-init, vtable off_5A3CC0, bound-data pointer unk_7CFC44 at +0x31C, config flags 1/0/1/1, preset 398, text-handle registration. Prior analysis labels this owner DERIVED; whether it inherits UIElementBase is not proven.

Methods: `0x00474900`

- `this+0x00000000` `void* vtable_ptr` (write, DERIVED)
- `this+0x0000031C` `void* bound_data_ptr` (write, DERIVED)
- `this+0x00000324` `int config_flag_0` (write, DERIVED)
- `this+0x00000328` `int config_flag_1` (write, DERIVED)
- `this+0x0000032C` `int config_flag_2` (write, DERIVED)
- `this+0x00000330` `int config_flag_3` (write, DERIVED)
- `this+0x00000334` `int value_preset` (write, DERIVED)

### UIMenuPage

Menu page object owning an entry linked list at +0x44..+0x50. Rebuilds one page of entries (race-standings pages, team statistics, game options): frees the old node chain, notifies state cleanup, inserts entries selected by category/page direction, and creates formatted menu items. Concrete subtypes stamp category (+0xF4), page direction (+0x174) or scene-name fields (+0xA0/+0xA8).

Methods: `0x0047C360`, `0x0047E0A0`, `0x0047E960`

- `this+0x00000044` `void* entry_list_head` (read_write, GUESS)
- `this+0x00000048` `void* entry_list_next` (read_write, GUESS)
- `this+0x0000004C` `int entry_list_size` (write, GUESS)
- `this+0x00000050` `int entry_list_reserved` (write, GUESS)
- `this+0x000000A0` `void* prev_page_scene_name` (read, GUESS)
- `this+0x000000A8` `void* next_page_scene_name` (read, GUESS)
- `this+0x000000F4` `int option_category` (write, GUESS)
- `this+0x00000174` `int page_direction` (write, GUESS)

### UIListTextItem

Constructor-style initializer for a proposed UI list text item: base-init sub_48C070(this, 1), vtable off_5A4200, registration of two resource-handle nodes (unk_5C6E18, off_5C6E14) with index -1.

Methods: `0x00474F40`

- `this+0x00000000` `void* vtable_ptr` (write, DERIVED)

### UINetworkGameBrowser

Network game browser menu state: reads the search text, sorts the session list from the session manager (dword_7CD25C), builds one menu row per session with a locked/joined-dependent outline color, restores the search selection, and falls back to Searching/No-games-available status items.

Methods: `0x00475150`

- `this+0x00000094` `int row_owner_index` (read, GUESS)
- `this+0x000000B8` `void* resource_path` (read, GUESS)

### UIGameFilterObject

Game-filter UI object: base UI object constructor (0x0048FC50), query/index at +0x40, record sentinel -1 at +0x44, vtable off_5A4478; built by GameFilterSetup.

Methods: `0x004761C0`

- `this+0x00000000` `void* vtable_ptr` (write, DERIVED)
- `this+0x00000040` `int filter_query_index` (write, GUESS)
- `this+0x00000044` `int record_sentinel` (write, GUESS)

### VcrFileBrowser

VCR replay file browser: scans the replay directory with the aVcr_0 pattern through the file-search linked list (unk_8AD3B0), strips extensions, creates one menu item per file, re-selects the saved file name, and clears the selection flag at +0x131.

Methods: `0x0047BF30`

- `this+0x00000131` `int selection_flag` (write, GUESS)

### UIMenuItemLayoutHelper

Menu-item text-fit measurer: loads the text buffer pointer at +0xE0 (falling back to byte_5EA438), measures characters against the available width, and returns the truncation index.

Methods: `0x0047B910`

- `this+0x000000E0` `void** text_buffer_ptr` (read, GUESS)

### UIListObject

UI list object whose destructor frees three buffer pointers (+0x150/+0x158/+0x160), runs conditional cleanup on sub-objects at +0xE0 and +0x118, chains to the base destructor, and frees itself when the delete flag is set.

Methods: `0x00485960`

- `this+0x00000150` `void* column_buffer_a` (read, GUESS)
- `this+0x00000158` `void* column_buffer_b` (read, GUESS)
- `this+0x00000160` `void* column_buffer_c` (read, GUESS)

### UIRenderDispatcher

Main text render dispatcher: resolves the stored text pointer (+0xB0) through the shared string table when the +0xE8 flag is set, derives the alignment mode (1 left / 2 center / 3 right) from the alignment string (+0xB8), measures the text in the render box (+0x4..+0x10), fits or truncates against the width limit (+0xE4), re-centers on overflow, and dispatches the draw by alignment mode.

Methods: `0x00488BE0`

- `this+0x00000004` `int render_box_top` (read, DERIVED)
- `this+0x00000008` `int render_box_left` (read, DERIVED)
- `this+0x0000000C` `int render_box_right` (read, DERIVED)
- `this+0x00000010` `int render_box_bottom` (read, DERIVED)
- `this+0x000000B0` `void* stored_text_ptr` (read, DERIVED)
- `this+0x000000B8` `void* alignment_string_ptr` (read, DERIVED)
- `this+0x000000E0` `int alignment_mode` (read_write, DERIVED)
- `this+0x000000E4` `int max_width_limit` (read, DERIVED)
- `this+0x000000E8` `int string_table_flag` (read, DERIVED)

## Compatibility contracts

- **UIElementTextUpdateContract** — When the bound mode/config value differs from the cached value, the element formats a representation (list string or raw integer via '%d') into a fixed stack buffer using overflow-checked formatting and pushes it into the UI edit buffer; the update method returns 0.
- **MenuPageRebuildContract** — Before repopulating, free the entry-list node chain at +0x44 (nodes with payload at node+0, next pointer at node+4, flag byte at node+8) and clear +0x44..+0x50, then notify state cleanup, insert new entries, and create menu items only for names not already present.
- **NetworkBrowserSessionRowContract** — One menu row per session built as description + translated session name + '%d/%d' player count + '%d' session id; row outline color is grey when the locked/joined flag is set, red when the player-count bit flag holds, otherwise black. When no rows exist, show the Searching status item while the manager is searching and the No-games-available item otherwise.
- **TextFitTruncationContract** — Menu-item text is measured character-by-character with the text renderer against the available width and truncated at the character index where the width is exceeded (with a midpoint correction); the render dispatcher truncates to the +0xE4 width limit, and when the limit is disabled re-centers the text in the box on overflow.
- **OptionsCategoryEntryContract** — The option-category argument stored at +0xF4 selects the label set inserted into the options list: Allowed/Disallowed for categories 484-494, On/Off for 498, Normal plus X2..X7 speed multipliers for 499-500, and Normal/Time Scaled/Selected Season for 501.
- **StringTableResolutionContract** — Text flagged by the +0xE8 string-table flag is resolved through the shared string table (BinarySearchInStringTable(byte_5EC4C0, text, byte_5EC4CC)) before display; the shared buffer byte_5EC4CC is also used as the carrier for search-status text.
- **VcrFileBrowserContract** — The browser scans the replay directory with the aVcr_0 pattern, strips file extensions, creates one menu item per file, and re-selects the saved file name; the selection flag at +0x131 is cleared before the scan.

## Unresolved

- The concrete class names behind the UIElementBase constructor template are not identified by the packet; the instances are distinguished only by installed vtable and the preset at +0x334.
- Field +0x31C is dual-use: constructors store a pointer to a bound global there, while UIFrontendCounterDisplayUpdate caches an integer. Common ownership of the two uses is not proven by the packet.
- UICameraConstructor2 follows the same template as UIElementBase, but prior analysis labels its owner UICamera; no packet evidence proves whether the camera shares the element base class.
- The three menu rebuilders (UIMenuPagePopulator, TeamStatsMenuBuilder, GameOptionsUIConstructor) share the entry-list layout at +0x44..+0x50 but use different base initialization (StateCleanupNotification vs ConstructorInitVTable) and different subtype fields (+0xA0/+0xA8, +0xF4, +0x174); whether they are one class is unproven.
- Field +0xE0 is interpreted as a text-buffer pointer in MenuItemRenderHelper and as an alignment-mode int in UILargeRenderDispatcher; the packet does not prove these are the same object type.
- Semantics of the preset values at +0x334 (271, 381-387, 398) and the meaning of the flag fields at +0x324..+0x330 are unknown.
- The linked-list node layout used at +0x44 (payload at +0, next at +4, flag byte at +8) appears in three functions, but the node type and the meaning of the -1 insertion key in LinkedListInsertWithNodeAllocation are unidentified.
- The network-session info query is invoked indirectly (loc_462010) and is not present in the packet callee table; the session-id ceiling 9999 and the v25 semantics are inferred from usage only.
- The sub-objects cleaned by ConditionalDualCleanup at +0xE0 and +0x118 in UIListObjectDestructor, and the purpose of the three freed buffers (+0x150/+0x158/+0x160), are not evidenced.
- The base-destructor chain target sub_485EB0 and the base-init sub_48C070 are not characterized by this packet.
- The callers of the VCR browser and the menu page populator are not evidenced in the packet (caller refs for the page populator are listed unresolved).
- The format-string associations (aS_4 '%s' at 0x005C2C18, aD_1 '%d' at 0x005C3280, aSSS_0 at 0x005C6784) are DERIVED from IDA naming conventions rather than pinned by the raw source.
