=== TRIAGE LINES ===

=== FULL ENTRIES ===
<!-- target: docs/01-engine-architecture.md -->
### FUN_0042C1A0 — DynMan::Init

Dynamic manager initialization. Sets up vehicle grid array, initializes session state, and loads driver data per vehicle.

**Key logic:**
- If RaceMode != 4, assigns sequential index+1 to VehicleGridArray (+0x364 offset, stride 0x1230)
- Iterates VehicleGridArray entries (max 0x68 = 104 slots); empty slot (entry == 0) triggers FUN_0042bbd0/FUN_0042bc40 and exits loop
- Checks SessionType 1–4 (practice sessions) for early-out branch
- If InitStateFlag (DAT_007c5690) == 0: loads file via FUN_004b1520, calls session init (FUN_004bfd90), conditionally calls FUN_004bff70/FUN_004c01a0 based on RaceMode and FormationLap
- Calls FUN_004f9480 per vehicle (VehicleCount iterations) with FUN_004c6c40 (driver data load)
- If CurrentVehicleIndex valid (0..0x67) and vehicle at array[CurrentVehicleIndex] + 13000 == 0, calls FUN_004336f0 (vehicle setup init)

**Calls:** FUN_004d7a50 (debug trace gate), FUN_004d7aa0 (debug print), FUN_0040fe50, FUN_0042bbd0, FUN_0042bc40, FUN_0042bc80, FUN_004b1520 (file load), FUN_004bfd90, FUN_004bff70, FUN_004c01a0, FUN_004c6c40 (driver data), FUN_004f9480, FUN_004326e0, FUN_004336f0 (vehicle init), FUN_005895a2 (timer/angle)

**Moddability:** `hardcoded` — init path, no config fields

<!-- target: docs/01-engine-architecture.md -->
### FUN_0049EF40 — OnScreen::Enter (Debug Stub)

Debug trace-only entry for the OnScreen module. Flags entry via debug system, no other logic.

**Key logic:**
- Calls debug trace gate (FUN_004d7a50) with source "onscreen.cpp" line 0xa2c
- Prints "Entered OnScreen::Enter()" if tracing enabled
- Returns immediately

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace print)

<!-- target: docs/01-engine-architecture.md -->
### FUN_00455E70 — HWInput::Post

Hardware input post-processing. Polls input devices, dispatches callbacks, manages device lifecycle.

**Key logic:**
- Skips debug trace when SessionType5 == 5 (server/non-interactive session)
- Calls FUN_0044f070(1) — input device poll/update
- If param_1[0x665] (joystick/controller active flag) non-zero, calls FUN_004526c0 (joystick processing)
- Calls FUN_0044fbe0 twice and FUN_0044efe0 — input buffer flush/state sync
- If vtable pointer at *param_1 non-null, calls virtual method at slot +8 (likely Release/Close), then nulls the pointer

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace print), FUN_0044f070, FUN_004526c0 (joystick handler), FUN_0044fbe0, FUN_0044efe0

<!-- target: docs/01-engine-architecture.md -->
### FUN_004B40A0 — Screenshot Save Handler

Handles screenshot save triggered by keyboard hotkey ('X'). Writes screenshot file and posts "Screen Saved" message to UI.

**Key logic:**
- Iterates DAT_007cb218 entries at DAT_007cb21c looking for byte value 0x58 ('X' — screenshot hotkey flag)
- When hit: calls FUN_00551fd0 (file write) using DAT_008b8dd4/d8 as file handle params and DAT_005ec478/DAT_005ea438 as path
- Copies "Screen Saved" string to DAT_005ec4cc (MessageBuffer) via char-by-char copy
- Sends message via FUN_0045bd10(message, 3, 0x1020304) — UI message with type 3, ID 0x1020304
- Calls FUN_004fbd70, FUN_004b3dc0, FUN_00557120 — post-save cleanup

**Calls:** FUN_00551fd0 (file I/O), FUN_00423a00 (string op), FUN_0045bd10 (message dispatch), FUN_004fbd70, FUN_004b3dc0, FUN_00557120

<!-- target: docs/08-file-formats.md -->
### FUN_004B18D0 — PlayerFile::Restart (Debug Stub)

Debug trace-only entry for PlayerFile module restart path. Flags entry via debug system, no other logic.

**Key logic:**
- Calls debug trace gate (FUN_004d7a50) with source "plrfile.cpp" line 0x9ce
- Prints "Entered PlayerFile::Restart()" if tracing enabled
- Returns immediately

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace print)

<!-- target: docs/09-track-system.md -->
### FUN_004CEE90 — SpecialFX::Enter (Debug Stub)

Debug trace-only entry for SpecialFX module. Flags entry via debug system, no other logic.

**Key logic:**
- Calls debug trace gate (FUN_004d7a50) with source "specialfx.cpp" line 0xaee
- Prints "Entered SpecialFX::Enter()" if tracing enabled
- Returns immediately

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace print)

<!-- target: docs/10-vehicle-physics.md -->
### FUN_0052835F — Fixed-Point Color/Signal Mixer (Render Pipeline)

Per-channel fixed-point mixing/transform with 10-bit lookup table. Processes 8 source channels into 2 output channels using weighted dot-product blend.

**Key logic:**
- Reads pointers from param_1+0x11c (lookup table base), param_2+0x50 (first coefficient array), param_3+0x30 (second coefficient array)
- First loop (8→1, skipping channels 6, 4, 2): checks four short values at psVar6 offsets (-0x18, -0x10, 0, +0x10, +0x20)
- If all four coefficients zero: computes simple `coeff1 * coeff2 * 4` product
- If any non-zero: computes `coeff1 * coeff2 * 0x8000` base, then adds dot product with fixed-point weights (0x1b37, -0x1712, 0x73fc, -0x28ba), shifts right 13 bits
- Second loop (2 channels): reads first loop results, if all zero uses `(value + 0x10 >> 5) & 0x3ff` lookup index; otherwise `(base + dot_alt + 0x80000 >> 0x14) & 0x3ff`
- Writes byte results to param_4[channel] + param_5 offset
- Fixed-point arithmetic suggests audio mixing or pixel color-space transform (YUV→RGB)

**Uses DAT_0059e8a4, DAT_0059e9d4** as scaling constants (via FUN_005895a2 in related functions)

**Calls:** (none — leaf computation function)

<!-- target: docs/10-vehicle-physics.md -->
### FUN_005418E0 — Camera/Viewport Object Constructor

Initializes a camera/viewport object with default projection parameters and string copy.

**Key logic:**
- Sets float fields: +0x04 = 1.0f (scale/zoom), +0x08 = 1000.0f (far plane), +0x6c = 90.0f (FOV), +0x70 = 75.0f, +0x74 = 1.0f, +0x88 = 1.0f
- Zeroes fields at +0x0c through +0x20, +0x3c through +0x68, +0x78, +0x19c through +0x1b8
- Calls FUN_00541cd0(0,0,0,0,0,0) — camera subsystem init
- Sets vtable pointer at +0x7c to 0x00484848
- Sets +0x80 = 0x22 (34), +0x84 = -1
- Copies null-terminated string from param_2 into offset +0x8c (name/target identifier)
- Zeroes 0x18 dwords (96 bytes) starting at +0x9c — array of state/config data

**Calls:** FUN_00541cd0 (camera subsystem init)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x04 | ZoomScale | 1.0f |
| +0x08 | FarPlaneDist | 1000.0f |
| +0x0c–+0x20 | Zeroed | Position/rotation init |
| +0x6c | FOV_X | 90.0f |
| +0x70 | FOV_Y | 75.0f |
| +0x74 | AspectScale | 1.0f |
| +0x7c | VTablePtr | 0x00484848 |
| +0x80 | Flags | 0x22 (34) |
| +0x84 | Sentinel | -1 |
| +0x88 | UniformScale | 1.0f |
| +0x8c | NameBuffer | null-terminated string copy |
| +0x9c–+0xfc | StateArray | 96 bytes zeroed (0x18 dwords) |
