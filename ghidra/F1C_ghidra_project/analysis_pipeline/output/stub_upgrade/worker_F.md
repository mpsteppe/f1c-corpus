=== TRIAGE LINES ===

=== FULL ENTRIES ===
<!-- target: docs/01-engine-architecture.md -->
### FUN_0042c170 — DynMan::Setup (Debug Entry)

Debug-logging wrapper for DynamicManager setup. Posts "Entered DynMan::Setup()" message if logging enabled at level 2.

**Key logic:**
- Checks logging guard FUN_004d7a50(2, ...) — level 2 diagnostic
- If enabled, logs entry string via FUN_004d7aa0
- No actual initialization performed — pure trace function

**Calls:** FUN_004d7a50 (logging guard, docs/20), FUN_004d7aa0 (log string, docs/20)

<!-- target: docs/01-engine-architecture.md -->
### FUN_004c8d00 — Sound::Exit

Sound subsystem shutdown. Calls cleanup sequence for audio system modules.

**Key logic:**
- Debug-log entry if level 2 enabled
- Calls FUN_00411740(1) and FUN_00411740(0) — subsystem release (two instances)
- Calls FUN_00418900 — additional cleanup
- Calls FUN_004c8630 and FUN_004c8350 — sound-specific shutdown routines

**Calls:** FUN_004d7a50 (logging guard), FUN_004d7aa0 (log string), FUN_00411740 (subsystem release), FUN_00418900 (cleanup), FUN_004c8630 (sound shutdown), FUN_004c8350 (sound shutdown)

<!-- target: docs/01-engine-architecture.md -->
### FUN_00455da0 — HWInput::Restart

Hardware input subsystem restart. Resets input state and optionally reinitializes audio input processing.

**Key logic:**
- Skips debug log if SessionType5 (DAT_007c569c) == 5 (server mode)
- Calls FUN_0044f680 with DAT_005d6d60/64 — resets input devices (keyboard, mouse, joystick)
- Calls FUN_0044f0a0 — input device enumeration
- If AudioQualityLevel (DAT_007d1ffc) != 0, calls FUN_0044ff50 — audio input pipeline restart
- Writes 0 to param_1+0x2428 (restart state flag)
- Loops through input state entries at param_1+0x1f98 (stride 0x2c, 8 entries), checks if any has entry[0]==0 and entry[1]==0x59 (keyboard key held) → sets flag at +0x2428 to 1 if found

**Globals:**
- DAT_007c569c — SessionType5 (5=server)
- DAT_007d1ffc — AudioQualityLevel
- DAT_005d6d60/DAT_005d6d64 — input device parameters

**Calls:** FUN_004d7a50 (logging guard), FUN_004d7aa0 (log string), FUN_0044f680 (input device reset), FUN_0044f0a0 (input enumeration), FUN_0044ff50 (audio input pipeline)

<!-- target: docs/01-engine-architecture.md -->
### FUN_004b4060 — Render::Restart

Render subsystem restart. Initializes render state block with identity values.

**Key logic:**
- Debug-log entry if level 2 enabled
- Fills 26 dwords (104 bytes) of param_1 with 0x01010101 pattern — render state initialization vector

**Calls:** FUN_004d7a50 (logging guard), FUN_004d7aa0 (log string)

<!-- target: docs/08-file-formats.md -->
### FUN_004b1870 — PlayerFile::Setup

Player file system setup. Loads PLR configuration file and game profile data.

**Key logic:**
- Debug-log entry if level 2 enabled
- Calls FUN_004b0770(1) — loads PLR file parser
- If PLR load succeeds, returns true
- Otherwise calls FUN_004b0540(1) — loads game profile data
- Returns success if either loader succeeds

**Calls:** FUN_004d7a50 (logging guard), FUN_004d7aa0 (log string), FUN_004b0770 (PLR file load), FUN_004b0540 (game profile load)

<!-- target: docs/09-track-system.md -->
### FUN_00463160 — NetComm Command Line Parser

Parses command-line arguments for network session configuration. Handles password, autohost, autojoin, game name, network name, and max players settings.

**Key logic:**
- Skips most debug logging if SessionType5 (DAT_007c569c) == 5 (server mode)
- Calls FUN_00566810 (command line arg iterator) repeatedly to parse:
  - **Password:** Extracts string after `-password`, stores to buffer, sets null terminator via FUN_00587c20
  - **Autohost mode:** If `-connect` not found but `-gamename` found: sets +0xc5 flag, parses game name to param_1+0x16c
  - **Autojoin mode:** If `-connect` found: copies address to param_1+200, parses port via FUN_00587ece, sets +0xc6 flag, copies autojoin address from DAT_007d1004
  - **Network name:** Parses quoted/simple string after unrecognized args, copies to param_1+0x11c
  - **Max players:** Parses `-maxplayers` value, clamps between 2-104 (0x68), stores to param_1+0x1ac

**Globals:**
- DAT_007c569c — SessionType5 (5=server mode gate)
- DAT_007d1004 — autojoin address string

**Calls:** FUN_004d7a50 (logging guard), FUN_004d7aa0 (log string), FUN_00566810 (command line arg iterator), FUN_00587c20 (string alloc/init), FUN_00587ece (string to int), FUN_0058815f (address lookup), FUN_005897ca (string search), FUN_00463710 (password set)

<!-- target: docs/10-vehicle-physics.md -->
### FUN_00410f60 — Scene Graph Drawable Lookup

Resolves a drawable object pointer from a scene graph node using an indexed selector. Processes vertex data for rendering.

**Key logic:**
- Decodes selector from param_2[0] bits 18-23 (`(*param_2 >> 0x12) & 0x3f`) — 6-bit case index (1-6)
- Each case accesses a different child array on param_1 struct:
  - Case 1: +0x24 (count), +0x2c (base ptr), stride 0x318 — children at +0xd0
  - Case 2: +0x30 (count), +0x38 (base ptr), stride 0x318
  - Case 3: +0x3c (count), +0x44 (base ptr), stride 0x318
  - Case 4: +0x48 (count), +0x50 (base ptr), stride 0x328
  - Case 5: +0x54 (count), +0x5c (base ptr), stride 0x318
  - Case 6: +0x60 (count), +0x68 (base ptr), stride 0x318
- Indexed by param_2[2] cast to short (signed bound check)
- If resolved pointer non-null, extracts packed vertex data from param_2 (+0xa, +0xe, +0x12, +0x13, +0x15, +0x17) and calls FUN_0054b4d0 with scaled vertex transform
- Uses DAT_0059e780 (VertexScaleFactor) and DAT_0059e77c for short-to-float vertex conversion

**Globals:**
- DAT_0059e780 — VertexScaleFactor (short-to-float scale ~1/32768)
- DAT_0059e77c — secondary vertex scale factor

**Calls:** FUN_0054b4d0 (vertex transform, scene graph renderer)

<!-- target: docs/10-vehicle-physics.md -->
### FUN_004c2e20 — Linked List Merge Sort (Float Key)

Recursive merge sort for singly-linked list sorted by float key value. Generic utility operating on linked nodes with next pointer at +4.

**Key logic:**
- Walks list to count nodes (next ptr at entry[1])
- Finds midpoint via half-count traversal
- Splits list at midpoint (sets entry[1]=0 on left half's last node)
- Recursively sorts left and right halves via FUN_004c2e20
- Merges sorted halves comparing float key at `(*entry[0]+4)` — node values stored in sub-struct at entry[0]+4
- Returns new list head pointer
- Standard merge sort: O(n log n), stable
- Comparison: `*(float*)(*left + 4) <= *(float*)(*right + 4)`
- Operates on linked list nodes — each node has (data_ptr, next_ptr) layout

**Calls:** Recursive self-call, called by upstream sorting routines
