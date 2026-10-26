## CockpitDashboardLEDGaugeSetup_0049ca00 — Cockpit Dashboard LED Gauge Initialization

**Summary:** One-shot initialization of the cockpit dashboard LED gauge HUD widget: creates sub-elements, loads BMP texture resources, allocates animation control memory, and resolves UI manager handles. Returns success/failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommPlayerSlotSync (0045fc50), OnScreen_Init (0049efa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1 | InitFlag (byte guard: 0 = not initialized, set to 1 after first run to skip) |
| this | 0x4 | R | — | TextureHandle1 (BMP texture loaded via sub_53CFE0) |
| this | 0x8 | R | — | TextureHandle2 (BMP texture loaded via sub_53CFE0) |
| this | 0xC | R | — | TextureHandle3 (BMP texture loaded via sub_53CFE0) |
| this | 0x10 | RW | — | AnimControlHandle1 (memory-allocated control struct from off_5CCB5C) |
| this | 0x14 | RW | — | AnimControlHandle2 (memory-allocated control struct from off_5CCB68) |
| this | 0x18 | R | — | AdditionalControl1 (allocated via off_5CCB6C if AnimControlHandle2 valid) |
| this | 0x1C | R | — | AdditionalControl2 (allocated via off_5CCB6C if AnimControlHandle2 valid) |
| this | 0x20 | RW | — | UIManagerHandle0 (sub_548890 from off_5CCB88) |
| this | 0x24 | RW | — | UIManagerHandle1 (sub_548890 from off_5CCB8C) |
| this | 0x28 | RW | — | UIManagerHandle2 (sub_548890 from off_5CCB90) |
| this | 0x2C | RW | — | UIManagerHandle3 (sub_548890 from off_5CCB94) |
| this | 0x30 | RW | — | UIManagerHandle4 (sub_548890 from off_5CCB98) |
| this | 0x34 | RW | — | UIManagerHandle5 (sub_548890 from off_5CCB9C) |
| this | 0x38 | RW | — | UIManagerHandle6 (sub_548890 from off_5CCBA0) |
| this | 0x3C | RW | — | UIManagerHandle7 (sub_548890 from off_5CCBA4) |
| this | 0x40 | RW | — | UIManagerHandle8 (sub_548890 from off_5CCBA8) |
| this | 0x44 | RW | — | UIManagerHandle9 (sub_548890 from off_5CCBAC) |
| this | 0x48 | RW | — | UIManagerHandle10 (sub_548890 from off_5CCBB0) |

**Written-by note (persistence):**
- this 0x0: one-shot init (set to 1, never cleared) — external poke does NOT persist (re-init resets all fields)
- this 0x10: one-shot init — external poke does NOT persist
- this 0x14: one-shot init — external poke does NOT persist
- this 0x20: one-shot init — external poke does NOT persist
- this 0x24: one-shot init — external poke does NOT persist
- this 0x28: one-shot init — external poke does NOT persist
- this 0x2C: one-shot init — external poke does NOT persist
- this 0x30: one-shot init — external poke does NOT persist
- this 0x34: one-shot init — external poke does NOT persist
- this 0x38: one-shot init — external poke does NOT persist
- this 0x3C: one-shot init — external poke does NOT persist
- this 0x40: one-shot init — external poke does NOT persist
- this 0x44: one-shot init — external poke does NOT persist
- this 0x48: one-shot init — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c6784 | aSSS_0 | R | sFormatPath [DERIVED] |
| 005ccb58 | off_5CCB58 | R | BMP filename pointer (first texture name) |
| 005ccb5c | off_5CCB5C | R | Linked-list head for control handle lookup (AnimControl1 source) |
| 005ccb60 | off_5CCB60 | R | BMP filename pointer (second texture name) |
| 005ccb64 | off_5CCB64 | R | BMP filename pointer (third texture name) |
| 005ccb68 | off_5CCB68 | R | Linked-list head for control handle lookup (AnimControl2 source) |
| 005ccb6c | off_5CCB6C | R | VTable for additional animation controls |
| 005ccb70 | off_5CCB70 | R | VTable for sub-element 0 (sub_49CD80 param) |
| 005ccb74 | off_5CCB74 | R | VTable for sub-element 1 (sub_49CD80 param) |
| 005ccb78 | off_5CCB78 | R | VTable for sub-element 2 (debug callback / sub_49CD80 param) |
| 005ccb7c | off_5CCB7C | R | VTable for sub-element 3 (sub_49CD80 param) |
| 005ccb80 | off_5CCB80 | R | VTable for sub-element 4 (sub_49CD80 param) |
| 005ccb88 | off_5CCB88 | R | UI Manager vtable pointer (for handle 0) |
| 005ccb8c | off_5CCB8C | R | UI Manager vtable pointer (for handle 1) |
| 005ccb90 | off_5CCB90 | R | UI page jump table (for handle 2) |
| 005ccb94 | off_5CCB94 | R | UI vtable pointer (for handle 3) |
| 005ccb98 | off_5CCB98 | R | UI vtable pointer (for handle 4) |
| 005ccb9c | off_5CCB9C | R | File data pointer (for handle 5) |
| 005ccba0 | off_5CCBA0 | R | VTable for this function's own object (handle 6) |
| 005ccba4 | off_5CCBA4 | R | Offscreen buffer pointer (for handle 7) |
| 005ccba8 | off_5CCBA8 | R | UI vtable pointer (for handle 8) |
| 005ccbac | off_5CCBAC | R | Scoring config table pointer (for handle 9) |
| 005ccbb0 | off_5CCBB0 | R | UI vtable pointer (for handle 10) |
| 005ccea8 | aSBmp | R | Format string for ".BMP" suffix |
| 005cceb0 | aCmapsMas | R | Track cmaps.mas path suffix |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 005ec428 | dword_5EC428 | R | SeasonName [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle (guards all subsequent init — if 0, skip texture/UI loading) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049cd80 | sub_49CD80 | Create a sub-element widget (LED segment) with position, scale, and vtable — called 5 times |
| 0053cb20 | MemoryAllocation_cb20 | Allocate memory block for animation control structs |
| 0053cbc0 | sub_53CBC0 | Open a file/resource bundle (cmaps.mas) from season directory |
| 0053ce40 | PhysicsObjectLinkedListRemoval | Remove/resource cleanup of the opened file handle |
| 0053cfe0 | sub_53CFE0 | Load BMP texture resource from file into handle with flags (67585) |
| 00545f40 | ValueGetter | Retrieve value from collision geometry handle (existence check) |
| 00547920 | StringSearchInLinkedList | Search linked list for control handle by name |
| 00548890 | sub_548890 | Resolve UI manager handle from vtable pointer |
| 0058815f | StringFormatWithBufferOverflowCheck | Build formatted file path string (season dir + name + cmaps.mas / .BMP) |

**Guard conditions:** Guard: `this+0x0 == 0` — InitFlag. If non-zero (already initialized), function returns immediately with v2=1 (success). All inner logic gated behind `dword_8AFE88 != 0` (collision geometry handle must exist) and `ValueGetter` returning non-null.
