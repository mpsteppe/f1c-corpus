# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Proposal for the generic_runtime_objects scope: a heterogeneous set of runtime helpers clustered by evidence into HUD text row rendering (HudRowRenderState, TextRenderPipeline), session-value formatting (SessionHudFormatter), the session HUD overlay (SessionHudOverlay), 2D textured-quad rendering (TexturedQuadRenderer), string-keyed resource lookup (StringKeyedResourceService), a word-pair linked list (WordPairLinkedList), offset accumulation (OffsetAccumulatorState), and several small session/command helpers (SessionInitFlagSetter, CyclicSlotSelector, StandingsCommandDispatch, AudioEffectGate, RandomColorSource, DistanceThresholdGate). All function owners are UnknownObject in the IR; class boundaries are GUESS synthesis over shared this-field usage and shared callees, and every named field is a DERIVED interpretation of evidenced offsets.

## Function roles

- `0x0049A490` **StringKeyedResourceService** — String-keyed resource lookup: transforms a copied string via sub_589901, then on HashTableSearch hit dispatches a3 through FunctionCallWrapper_a2e0, on miss calls ResourceLookupOrCreate. Always returns 0.
- `0x0049A9C0` **OffsetAccumulatorState** — Straight-line setter storing four arguments into fields 0x4, 0x8, 0xC, 0x10 and returning the value stored at 0xC.
- `0x0049AA30` **OffsetAccumulatorState** — Offset accumulator: tracks the primary value a2 (per-call delta into this+0x10, baseline this+0xC), accumulates a reference delta into this+0x8, and stores a3 as the new reference baseline at this+0x4. Returns the primary delta.
- `0x0049AA70` **OffsetAccumulatorState** — Positional offset accumulator: adds parameters to baselines at this+0x4 and this+0xC and stores the results at this+0x8 and this+0x10. Returns the computed this+0x10 value.
- `0x0049AD50` **StringKeyedResourceService** — String path helper: when the source string is non-null, preprocesses it with sub_589901 then returns the StringCopyWithBufferRealloc (00566650) copy; otherwise returns an undefined value.
- `0x0049ADC0` **WordPairLinkedList** — Appends a node holding a 16-bit word pair (a2/a3) to a linked list with head at this+0x0, tail at this+0x8, tail link at this+0x4, and node count at this+0xC; returns 1 on success, 0 on first-allocation failure.
- `0x0049B200` **RandomColorSource** — Time-driven packed color generator: adds session-time global dbl_8AFEA0 to the float argument, runs the InterruptDispatch side-effect, folds the value with a triangle wave, clamps to [0,1], and packs CRTFtol conversions into an integer.
- `0x0049B630` **SessionHudFormatter** — Pure time-unit split: truncates the input, divides by 60 (0.016666668 scale) for whole minutes into *a2, computes remainder seconds into *a3, and returns the minutes. Shared decomposition helper.
- `0x0049BAD0` **DistanceThresholdGate** — Boolean gate with no arguments: computes a float distance projection of dword_7C54E0 offset by 12, then returns whether RingBufferAccessWithWrap or IndexedFloatArrayLookup of it equals 2.
- `0x0049BE50` **SessionHudFormatter** — Formats a signed '+/-MM:SS.mmm' sector-time gap into the output buffer, reading the reference from the ghost lap-time array (byte_7CFFF0 bit 2) or directly from the race struct, and returns 0.
- `0x0049C670` **SessionHudFormatter** — Formats a lap-count string: current lap = dword_7C54E0+16444 plus 1 clamped to total lap count dword_8ACF8C, using the unlimited-lap format when that total is 0x7FFFFFFF. Always returns 0.
- `0x0049C770` **SessionHudFormatter** — Formats a fuel quantity (dword_7C54E0+14724) with a unit suffix computed or copied from literal data, rendering US gallons (0.26417205, one decimal) when CostDisplayMode dword_7D0450 equals 1, otherwise a rounded integer. Returns 0.
- `0x0049C960` **SessionHudFormatter** — Formats the remaining session time (flt_8ACF94 minus dbl_8AFEA0) as a countdown clock ' MM:SS.FFF', suppressed when the session type is 7 or championship mode is active. Always returns 0.
- `0x0049D700` **HudRowRenderState** — Renders a four-row dual-column HUD: initializes the dual-text element, stacks Y positions by the row stride, and renders format-helper value/label pairs through StringFormatAndRender using the surface at this+0x8 and the display context at (this+0x14)+84.
- `0x0049D8B0` **HudRowRenderState** — Text-display helper: renders the dual-text baseline, then when this+0x8 is nonzero emits a sequence of formatted lines (per-line buffer helpers) at stepped offsets through StringFormatAndRender with the literal 240 on the final line.
- `0x0049DA60` **HudRowRenderState** — HUD text-row updater: always renders the dual-text baseline, then when this[2] is non-null formats a value (sub_49C8F0) and label (sub_49C960) into a 64-byte buffer and renders both with StringFormatAndRender at an offset Y position.
- `0x0049DB00` **SessionHudFormatter** — Formats a temperature value as an integer with a unit suffix, converting Celsius to Fahrenheit (linear scale about -40 degrees) when CostDisplayMode dword_7D0450 equals 1.
- `0x0049DE40` **SessionHudOverlay** — Renders the session-state HUD overlay: clipped backdrop, two blink-gated status widgets, four suspension corner bars and indicators, a delta/highlight row, a fixed green marker, and four formatted text rows using the render surface at this+0x8.
- `0x0049E410` **HudRowRenderState** — Formats and renders a label/value pair at the same Y: label via sub_49BB40 rendered at X a2, value via sub_49BBB0 rendered at X a3, both through StringFormatAndRender with the surface at this+0x8 and the display context at (this+0x14)+84.
- `0x0049E4E0` **AudioEffectGate** — Conditionally forwards an audio-effect request (a1, a2) to sub_5506A0(a1, a2, 0) based on two flag dwords on the base object dword_7C54E0 (offsets 0xF90 and 0xF7C); falls back to returning the base pointer.
- `0x0049EA10` **TexturedQuadRenderer** — Renders a 2D textured quad: guards on the render-data pointer at this+0x8, runs the pre-render computation, allocates/initializes a render object, stores X/Y/width/height and texture-derived UV scales, and emits four corner vertices through sub_553650.
- `0x0049EB40` **TexturedQuadRenderer** — Renders a second 2D textured quad: guards on the resource node at this+0xC, releases the previous single field, re-initializes the sub-object at this+4, and when the constructor reports failure stores rectangle parameters at this+0x3C..0x48 and emits four vertices.
- `0x0049F150` **SessionInitFlagSetter** — Session-init flag setter: stores a2 into this+0x0 and writes the global byte_8AD384 flag to 1 exactly when a2 equals 1, returning the boolean result of that test.
- `0x0049F170` **CyclicSlotSelector** — Advances or decrements the cyclic index at this+0x4 (range 0-4, re-wrapping at bounds) and keeps stepping until the 5-entry table at dword_7C54E8+13004 has a value greater than 1 at entry offset 40 + (index << 6). Returns the table base pointer.
- `0x0049F6A0` **TextRenderPipeline** — Render helper: nested guards on a1/a4/a5, then applies an alignment modifier in place to a2 (SubtractionWithGuard when a6==1, CenterCalc when a6==2) and tail-calls sub_553070 to commit the render.
- `0x004A0AD0` **StandingsCommandDispatch** — Command dispatch helper: fetches an object through a __thiscall vtable method at offset 28 with argument 27 on the global object dword_7CD8C0, and when non-null passes it to StandingsDisplay. Always returns 0.

## Proposed classes

### HudRowRenderState

HUD dual-column text row rendering state: render surface, display context, and row layout used by the multi-row text renderers and the label/value pair renderer.

Methods: `0x0049D700`, `0x0049D8B0`, `0x0049DA60`, `0x0049E410`

- `this+0x00000008` `void* renderSurface` (read, DERIVED)
- `this+0x00000014` `void* displayContext` (read, DERIVED)
- `this+0x00000068` `void* unresolvedData` (read, UNKNOWN)

### TextRenderPipeline

Shared text format-and-render commit helper with selectable alignment modifiers (left-adjust subtraction and centering) feeding a final render commit.

Methods: `0x0049F6A0`


### SessionHudFormatter

Formats session-derived values (lap counter, fuel, countdown timer, temperature, sector time gaps) into caller buffers by reading the global race-state object dword_7C54E0 and session globals; includes the pure minute/second split helper.

Methods: `0x0049B630`, `0x0049BE50`, `0x0049C670`, `0x0049C770`, `0x0049C960`, `0x0049DB00`


### SessionHudOverlay

Session-state HUD overlay renderer: clipped backdrop, blink-gated status widgets, suspension corner bars and indicators, a delta highlight row, and formatted text rows.

Methods: `0x0049DE40`

- `this+0x00000008` `void* renderSurface` (read, DERIVED)
- `this+0x00000014` `void* displayContext` (read, DERIVED)
- `this+0x0000001C` `void* secondaryContext` (read, DERIVED)
- `this+0x00000068` `void* unresolvedData` (read, UNKNOWN)

### TexturedQuadRenderer

2D textured-quad render state: render-data/resource pointers, rectangle parameters, texture-derived UV scales, and four-corner vertex emission through sub_553650.

Methods: `0x0049EA10`, `0x0049EB40`

- `this+0x00000008` `void* renderData` (read, DERIVED)
- `this+0x0000000C` `void* resourceNode` (read, DERIVED)
- `this+0x00000024` `float positionX` (read_write, DERIVED)
- `this+0x00000028` `float positionY` (read_write, DERIVED)
- `this+0x0000002C` `float width` (read_write, DERIVED)
- `this+0x00000030` `float height` (read_write, DERIVED)
- `this+0x00000034` `float uScale` (read_write, DERIVED)
- `this+0x00000038` `float vScale` (read_write, DERIVED)
- `this+0x0000003C` `float secondaryX` (read_write, DERIVED)
- `this+0x00000040` `float secondaryY` (read_write, DERIVED)
- `this+0x00000044` `float secondaryWidth` (read_write, DERIVED)
- `this+0x00000048` `float secondaryHeight` (read_write, DERIVED)

### StringKeyedResourceService

String-keyed lookup/create service: preprocesses copied strings through the transform step sub_589901, then resolves them by hash-table lookup with a dispatch-on-hit or resource-create-on-miss contract.

Methods: `0x0049A490`, `0x0049AD50`


### WordPairLinkedList

Linked list of nodes holding 16-bit word pairs, with head/tail pointers and a node count; nodes are individually allocated and appended at the tail.

Methods: `0x0049ADC0`

- `this+0x00000000` `void* head` (read_write, DERIVED)
- `this+0x00000004` `void* tailNext` (read_write, GUESS)
- `this+0x00000008` `void* tail` (read_write, DERIVED)
- `this+0x0000000C` `int count` (read_write, DERIVED)

### OffsetAccumulatorState

Small stateful accumulator/setter object maintaining reference and primary baselines plus running accumulations at offsets 0x4..0x10; the three methods store or accumulate the same four fields with differing semantics.

Methods: `0x0049A9C0`, `0x0049AA30`, `0x0049AA70`

- `this+0x00000004` `int referenceBaseline` (read_write, GUESS)
- `this+0x00000008` `int referenceAccumulation` (read_write, GUESS)
- `this+0x0000000C` `int primaryBaseline` (read_write, GUESS)
- `this+0x00000010` `int primaryAccumulation` (read_write, GUESS)

### SessionInitFlagSetter

Stores a mode/state value at this+0x0 and mirrors an a2==1 test to the global session-init-complete flag byte_8AD384.

Methods: `0x0049F150`

- `this+0x00000000` `int modeValue` (read_write, GUESS)

### CyclicSlotSelector

Cyclic index (0-4) stepper that advances forward or backward until a 64-byte-strided candidate-table entry passes a value-greater-than-1 validity check.

Methods: `0x0049F170`

- `this+0x00000004` `int cyclicIndex` (read_write, DERIVED)

### StandingsCommandDispatch

Opens the standings display through a __thiscall virtual method (vtable offset 28, argument 27) on the global object dword_7CD8C0.

Methods: `0x004A0AD0`


### AudioEffectGate

Conditionally forwards an audio-effect request when one of two flag fields (offsets 0xF90 and 0xF7C) on the base object dword_7C54E0 is set.

Methods: `0x0049E4E0`


### RandomColorSource

Time-driven packed color generation from the session-time global dbl_8AFEA0 and a clamped triangle wave.

Methods: `0x0049B200`


### DistanceThresholdGate

Boolean distance-projection threshold check over the global race-state object dword_7C54E0 comparing two lookups against the value 2.

Methods: `0x0049BAD0`


## Compatibility contracts

- **RaceStateTimingGate** — Sector-time difference formatting must be suppressed unless the race-state object (dword_7C54E0) reports state 2 at byte offset +16532.
- **SessionTimeFormatScale** — Session/display time values are expressed in seconds: formatting must decompose whole minutes with a 1/60 scale and a remainder in seconds, rendered as '+/-%.2d:%06.3f' with the sign prefix chosen by the difference sign.
- **CostDisplayUnitSelection** — When dword_7D0450 equals 1, fuel is rendered in US gallons (value * 0.26417205, one decimal) and temperature is converted from Celsius to Fahrenheit (linear scale about -40 degrees); otherwise fuel is a rounded integer and temperature is the raw value, both with a unit suffix.
- **UnlimitedLapSentinel** — A total-lap value of 0x7FFFFFFF must render the lap counter as ' %d/--' instead of ' %d/%d', and the current lap is the lap counter at dword_7C54E0+16444 plus 1 clamped to the total.
- **GhostReplayTimeReference** — When byte_7CFFF0 bit 2 is set, the sector-time reference is read from the ghost lap-time array (global 0x005F0780, stride 4656) using the ghost car index from sub_4D1B50(0), not from the race struct; an invalid ghost index (255) suppresses formatting.
- **DualColumnHudLayout** — Multi-row HUD text is laid out in two columns at row positions stacked by the dword_5CCBBC stride onto the base dword_5CCBB8, with value lines rendered in the first-region display state and label lines in the second-region display state dword_7CE238.

## Unresolved

- All function owners are UnknownObject in the validated IR; the class boundaries and names in this proposal are GUESS synthesis over shared this-field usage and shared callees, not proven ownership.
- What sub_589901 does to the string (reverse, case-normalize, or other transform) before lookup/copy is unverified.
- The two quad renderers use disjoint field families (0x24-0x38 for 0x0049EA10, 0x3C-0x48 for 0x0049EB40); grouping them into TexturedQuadRenderer is not proven, and the allocation constants 32/192 plus the trailing -1 vertex argument are unexplained.
- Field semantics of OffsetAccumulatorState vary across its three methods (QuadFieldSetter stores, AccumulateOffset accumulates, UpdatePositionFromBaselines recomputes); the twin relationship to 0x0049A9C0 is DERIVED from a prelabel cluster_copy, not independently proven.
- Format-string globals aDD_1/aD_2/aDS_3/a1fS_0 (0x005CCE80/0x005CCE88/0x005CCE90/0x005CCE98) contents are inferred DERIVED from branch behavior, not confirmed byte-wise.
- The global float constants at 0x0059E420, 0x0059E43C, 0x0059E450, 0x005CCE34, 0x005CCE44, 0x007CE048 and 0x007CE234 are listed in packet facts but do not appear in the decompiled bodies; their per-function roles are unknown.
- Race-state offsets 14724 (fuel), 13384 (unit multiplier), 16444 (lap counter), 16532 (state), 16552 (reference times), 16460 (live times) and the dword_7C54E0 +12 projection base have no confirmed field names in this packet.
- The this+0x68 field is read on HUD render paths but its role is unresolved (a sub-struct pointer label exists in the skeleton fill, unverifiable here).
- AudioEffectGate's fallback of returning the base pointer dword_7C54E0 when neither flag is set is unexplained.
- The candidate-table layout at dword_7C54E8+13004 (64-byte stride, selector at +40) and the meaning of values <= 1 are unresolved; the table owner is not established.
- The purpose of the InterruptDispatch side-effect call (callee 0x0058957A) inside RandomColorSource is unknown.
- The exact byte layout of the packed color result in RandomColorSource is decompiler-artifact dependent and unverified.
- The semantics of the -1 color/UV argument and the leading float arguments to sub_553650 are unresolved; the UV/color split is inferred.
- The uninitialized return on failing-guard paths of StringFormatAndRender and the uninitialized null-input return of sub_49AD50 are decompiler artifacts; effective behavior is undefined.
- The identity of the global object at dword_7CD8C0 and the meaning of vtable offset 28 / argument 27 in StandingsCommandDispatch are unknown.
