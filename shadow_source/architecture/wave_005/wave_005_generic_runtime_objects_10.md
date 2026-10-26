# RuntimeObjectUtils

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposal groups 30 validated functions into 15 weakly-typed classes plus unresolved free helpers. The strongest evidence links are the string-keyed bucket table (lookup 0x0049A360, insert 0x0049A3B0, membership 0x0049A520, 26-bucket destructor 0x0049A2F0, all sharing the node next-link at +24) and the indexed 16-bit linked list (read 0x0049AEC0, write 0x0049AE40, two-channel read 0x00499F00, sharing head/cursor/length layout). The HUD text formatters (0x0049BFF0, 0x0049C280, 0x0049C310, 0x0049C370, 0x0049C490, 0x0049C4E0, 0x0049C8A0) all consume a global post-process input object behind dword_7C54E0. Three identical single-call forwarders to StringCopyWithBufferRealloc form a behavioral group. Most owners remain GUESS/UNKNOWN; no class assignment implies confirmed C++ ownership.

## Function roles

- `0x00499E90` **StringCopyForwarder** — stdcall single-call delegate forwarding its one argument to StringCopyWithBufferRealloc and returning the helper's result unchanged
- `0x00499EA0` **StringCopyForwarder** — stdcall single-call forwarder delegating its one argument to StringCopyWithBufferRealloc and returning its result unchanged
- `0x00499EB0` **DwordFieldPairAccessor** — clamps two arguments to non-negative and stores max(a2,0) at this+0x60 and max(a3,0) at this+0x64; returns the original a3
- `0x00499EE0` **DwordFieldPairAccessor** — copies the two consecutive DWORD fields this+0x60 and this+0x64 into output pointers a2/a3 and returns the second field value
- `0x00499F00` **IndexedListAccessor** — gated two-channel 16-bit list read: proceeds only when ShortComputation_adb0(this+0x6C) is > 2, then publishes two shorts per channel via LinkedListIndexedFieldReader(0) and (1), each gated on a nonzero read result
- `0x0049A180` **UnknownObject** — zeroes the first dword (offset 0x0) of an object and returns the this pointer; generic per-field zero-init helper
- `0x0049A1C0` **UnknownObject** — conditional head store with chain iteration: rejects zero a2 (-1), lazily stores a2 as list head at this+0x0 when head is NULL, otherwise walks the chain via sub_499E00 and invokes FieldSetterAt0x68 on a traversed node
- `0x0049A250` **StringHashNode** — initializes seven consecutive dword fields (0x0..0x18) with the alternating pattern 0,-1,0,-1,0,-1,0 and returns this; ctor_init-style node initializer used on a fresh 28-byte allocation
- `0x0049A2E0` **StringCopyForwarder** — stdcall single-call forwarder delegating its one argument to StringCopyWithBufferRealloc and returning its result unchanged; shared by ResourceLookupOrCreate and StringReverseCopyLookup
- `0x0049A2F0` **StringHashTable** — destructor draining 26 singly-linked buckets this[0..25]: per node reads next at node index 6 (offset 24), runs sub_49A270 teardown, frees via FreeWrapper_7bcf, and zeroes each bucket head
- `0x0049A360` **StringHashTable** — bucket-chain string lookup by normalized key: CharToIndexConversion bucket index, walks the node chain at node+24 comparing each node string via sub_588410; returns matching node or 0
- `0x0049A3B0` **StringHashTable** — validates and inserts a string-keyed node: normalize via sub_589901, reject on sub_49A520 failure, CharToIndexConversion index, allocate 28-byte node, PatternedFieldInit, process string/a3, then link the node at this[index] (appending to list tail via the +24 next pointer)
- `0x0049A520` **StringHashTable** — string-keyed membership lookup: normalize, CharToIndexConversion index (-1 -> return -1), bucket head null -> 0, node-string comparison via sub_588410 returning 1 on match, 0 when the chain is exhausted
- `0x0049A580` **UnknownObject** — initializes a 7-dword object: zeros offsets 0x0,0x4,0xC,0x14,0x18 and sets sentinel -1 at offsets 0x8,0x10; returns the object pointer
- `0x0049A930` **SentinelInitializedObject** — constructor installing vtable off_5ACAB0 at +0, initializing the sub-object at dword index 9 via ThunkToFUN00491330, zeroing +4..+10 and +34/+3C, and filling +14..+20 and +38 with the -1 sentinel
- `0x0049A9E0` **RectangleRegionState** — computes rectangle edge offsets relative to the reference point at this+0x4/+0xC, writing left/top/right/bottom into +0x14/+0x18/+0x1C/+0x20 and returning the relative bottom edge
- `0x0049AA10` **QuadDwordFieldWriter** — writes four caller-supplied parameters into consecutive dword fields +0x14/+0x18/+0x1C/+0x20 and returns the fourth parameter; straight-line writer with no reads
- `0x0049ACC0` **ScrollOffsetState** — applies scroll offsets to the four extent fields +0x4/+0x8/+0xC/+0x10 with 16-bit overflow-aware clamping; when the +0x40 render flag is set obtains the render surface via Accessor() and calls RenderSurfaceFillCopy, then accumulates the raw offsets and returns this[4]
- `0x0049AE40` **IndexedListAccessor** — writes two 16-bit values (a3,a4) into the list entry at index a2: appends via ObjectConstructor_adc0 when a2 equals the length from ShortComputation_adb0, otherwise walks the node chain from this+0x0 (next at node+4) and writes the payload slots
- `0x0049AEC0` **IndexedListAccessor** — reads two 16-bit values from the list node at index a2 into *a3/*a4: bounds-checks against the length at this+0xC, seeds the cursor this+0x8 at the head, walks the node chain, and copies the node payload words (zeroing outputs and returning 0 on any invalid node)
- `0x0049B6D0` **VehicleGapUtility** — computes the time and lap gap between two vehicle objects: reads lap counters at +0x403C and times via sub_4F01B0(+12); equal laps -> signed time gap, one-lap wrap with v9<v7 -> flt_5EA408-v7+v9, otherwise lap difference with decrement
- `0x0049BA30` **PostProcessInputState** — session-mode predicate: returns true only when the dword at dword_7C54E0+0x3450 is in the range 1..3
- `0x0049BFF0` **HudDebugTextFormatter** — formats the next lap time into a HUD/replay buffer: computes the next lap index at dword_7C54E0+16448 (wrapping 2->0), copies prefix asc_5CCE18, selects ghost (flt_5F0780[4656*index+lap], via sub_4D1B50) or race-struct (dword_7C54E0+4*lap+16552) time source, and appends " %.2d:%06.3f" when positive
- `0x0049C280` **HudDebugTextFormatter** — formats one of three circular-recorded times on the post-process input object into the caller buffer: next circular index at dword_7C54E0+16448, reads float at +4*index+16552, appends " MM:SS.FFF" when positive; always returns 0
- `0x0049C310` **HudDebugTextFormatter** — formats a debug label with a name from a global object: copies prefix asc_5CCE54, and unless the flag at dword_7C54E0+16484 is set, reads the pointer at +16592 and appends "%s:" from v3+18168 then emits via sub_589901
- `0x0049C370` **HudDebugTextFormatter** — formats the time or lap-count gap to a target object into HUD text: seeds prefix asc_5CCE54, bails on suppression/target guards, then either fabs+SpatialGridCell "-%.2d:%06.3f" (behind) or a pluralized " -%d %s" via the string table in byte_5EC4CC (ahead)
- `0x0049C490` **HudDebugTextFormatter** — copies prefix asc_5CCE54 into the output buffer and, unless the flag at dword_7C54E0+16484 is set, appends the name at (dword_7C54E0+16596)+18168 as "%s:"; always returns 0
- `0x0049C4E0` **HudDebugTextFormatter** — formats the signed gap to a target object into HUD text: seed prefix, target at dword_7C54E0+16596, LapTimeGapCalculation; v7<=0 renders "+MM:SS.FFF" via fabs+SpatialGridCell, else " +N %s" with pluralizer chosen by off_5CCE74/aLaps_0 through the string table
- `0x0049C8A0` **HudDebugTextFormatter** — formats the championship score threshold: ChampionshipScoreThresholdSearch on dword_7C54E0+13004; renders the integer when positive, otherwise the placeholder word_5C694C; always returns 0
- `0x0049D3F0` **HudElementRenderer** — HUD speed readout: selects SpeedMagnitude (0x0049B900) or SpeedMagnitude_b950 (0x0049B950) on byte_7D0474, formats the magnitude as "%.3d" into a stack buffer, and renders it through sub_553070 to the display resource at this+0x10

## Proposed classes

### StringCopyForwarder

Behavioral group of three __stdcall single-call forwarders that each delegate their single argument to StringCopyWithBufferRealloc and return its result unchanged. Grouped by identical body shape; not proven to share an owning object.

Methods: `0x00499E90`, `0x00499EA0`, `0x0049A2E0`


### DwordFieldPairAccessor

Accessor pair over two consecutive DWORD fields at +0x60/+0x64: a clamped setter (negative inputs become 0) and a getter copying both fields out. Common ownership of the base is GUESS (callers differ: 0x00493060 vs 0x004861A0); only offset usage is evidenced.

Methods: `0x00499EB0`, `0x00499EE0`

- `this+0x00000060` `int field_0x60` (read_write, GUESS)
- `this+0x00000064` `int field_0x64` (read_write, GUESS)

### StringHashTable

String-keyed bucket table of singly-linked nodes: key normalization, char-to-bucket-index conversion, lookup/membership/insert, a 26-bucket destructor, and the shared node next-link at +24. The 26-bucket count is direct evidence from the destructor; that CharToIndexConversion's range equals 0..25 is GUESS.

Methods: `0x0049A2F0`, `0x0049A360`, `0x0049A3B0`, `0x0049A520`

- `this+0x00000000` `void*[26] bucket_heads` (read_write, GUESS)

### StringHashNode

28-byte singly-linked node of the string table: key string at +0, next link at +24, initialized with the alternating 0/-1 pattern. The +4..+14 fields are written only by the initializer and never read within this packet.

Methods: `0x0049A250`

- `this+0x00000000` `char* key_string` (read_write, GUESS)
- `this+0x00000004` `int pattern_field_1` (write, GUESS)
- `this+0x00000008` `int pattern_field_2` (write, GUESS)
- `this+0x0000000C` `int pattern_field_3` (write, GUESS)
- `this+0x00000010` `int pattern_field_4` (write, GUESS)
- `this+0x00000014` `int pattern_field_5` (write, GUESS)
- `this+0x00000018` `void* next` (read_write, GUESS)

### IndexedListAccessor

Linked list with head at +0, traversal cursor at +8, length at +0xC and nodes linked through the next pointer at node+4; supports indexed 16-bit-pair read/write and a gated two-channel read. Layout is cross-corroborated by 0x0049AE40 and 0x0049AEC0.

Methods: `0x00499F00`, `0x0049AE40`, `0x0049AEC0`

- `this+0x00000000` `IndexedListNode* head` (read, GUESS)
- `this+0x00000008` `IndexedListNode* walk_cursor` (read_write, GUESS)
- `this+0x0000000C` `int length` (read, GUESS)

### IndexedListNode

Node of the indexed list: data pointer at +0 (holding two 16-bit payload values) and next-node link at +4. No packet function is a node method; layout is inferred from the two walkers.

Methods: 

- `this+0x00000000` `void* data` (read_write, GUESS)
- `this+0x00000004` `void* next` (read, GUESS)

### ScrollOffsetState

Scroll/region state with four extent dwords at +4/+8/+C/+10 updated by accumulated offsets, a render flag at +0x40, and an optional render-surface fill-copy path.

Methods: `0x0049ACC0`

- `this+0x00000004` `int extent_1` (read_write, GUESS)
- `this+0x00000008` `int extent_2` (read_write, GUESS)
- `this+0x0000000C` `int extent_3` (read_write, GUESS)
- `this+0x00000010` `int extent_4` (read_write, GUESS)
- `this+0x00000040` `int render_flag` (read, GUESS)

### RectangleRegionState

Rectangle region with reference coordinates at +4/+C and four computed relative edge offsets at +14/+18/+1C/+20. Corner/axis semantics are inferred from prose, not independently evidenced.

Methods: `0x0049A9E0`

- `this+0x00000004` `int ref_y` (read, GUESS)
- `this+0x0000000C` `int ref_x` (read, GUESS)
- `this+0x00000014` `int left` (write, GUESS)
- `this+0x00000018` `int top` (write, GUESS)
- `this+0x0000001C` `int right` (write, GUESS)
- `this+0x00000020` `int bottom` (write, GUESS)

### QuadDwordFieldWriter

Struct writer storing four parameters into consecutive DWORD fields at +14/+18/+1C/+20 and returning the fourth. No read-back; the base is unknown and distinct from RectangleRegionState because common ownership is not proven.

Methods: `0x0049AA10`

- `this+0x00000014` `int value_1` (write, GUESS)
- `this+0x00000018` `int value_2` (write, GUESS)
- `this+0x0000001C` `int value_3` (write, GUESS)
- `this+0x00000020` `int value_4` (write, GUESS)

### SentinelInitializedObject

Object constructed with vtable off_5ACAB0 at +0, a sub-object at dword index 9 (offset 0x24, initialized via ThunkToFUN00491330), zeroed fields at +4..+10 and +34/+3C, and -1 sentinel fields at +14..+20 and +38. Offsets 0x4..0x20 overlap ScrollOffsetState and RectangleRegionState fields, but common ownership is not proven and they are kept as separate bases.

Methods: `0x0049A930`

- `this+0x00000000` `void* vtable` (write, GUESS)
- `this+0x00000004` `int zero_field_1` (write, GUESS)
- `this+0x00000008` `int zero_field_2` (write, GUESS)
- `this+0x0000000C` `int zero_field_3` (write, GUESS)
- `this+0x00000010` `int zero_field_4` (write, GUESS)
- `this+0x00000014` `int sentinel_field_1` (write, GUESS)
- `this+0x00000018` `int sentinel_field_2` (write, GUESS)
- `this+0x0000001C` `int sentinel_field_3` (write, GUESS)
- `this+0x00000020` `int sentinel_field_4` (write, GUESS)
- `this+0x00000034` `int zero_field_5` (write, GUESS)
- `this+0x00000038` `int sentinel_field_5` (write, GUESS)
- `this+0x0000003C` `byte zero_byte` (write, GUESS)

### PostProcessInputState

Global race/post-process input state behind dword_7C54E0 exposing a championship-threshold source (+0x32CC), a session-mode field (+0x3450), a circular time-slot index (+0x4040), a debug suppression flag (+0x4064), a lap-time array (+0x40A8), and name/target object pointers (+0x40D0/+0x40D4) consumed by the HUD text formatters. These offsets are reached through the global base (global:0x007C54E0), not through a this-relative field ref, so the packet provides no dedicated field:this refs for them and they are recorded here in prose only.

Methods: `0x0049BA30`


### HudDebugTextFormatter

Family of HUD/debug text formatters that seed a caller buffer with a prefix string, conditionally read name/target/gap data from the post-process input object behind dword_7C54E0, and append formatted lap-time, gap, label, or threshold text via the safe string formatter.

Methods: `0x0049BFF0`, `0x0049C280`, `0x0049C310`, `0x0049C370`, `0x0049C490`, `0x0049C4E0`, `0x0049C8A0`


### HudElementRenderer

HUD element renderer that formats a value into a stack buffer and renders it to a display resource at this+0x10 via the low-level render helper. Only the speed readout formatter is evidenced.

Methods: `0x0049D3F0`

- `this+0x00000010` `void* render_resource` (read, GUESS)

### VehicleGapUtility

Computes the time and lap gap between two vehicle objects by reading lap counters at +0x403C and per-vehicle time via a time sub-object at +12.

Methods: `0x0049B6D0`


### RaceVehicle

Vehicle-like object evidenced only by the lap counter at +0x403C and an unnamed time sub-object at +12 consumed by gap computation. No packet function is a method of this object; fields are read cross-object.

Methods: 

- `this+0x0000403C` `int lap_count` (read, GUESS)

## Compatibility contracts

- **StringKeyedTableLayout** — A replacement string table must keep bucket heads at array base +0 and a next-node link at node+24; insert appends to the tail and the destructor drains exactly 26 buckets.
- **IndexedListLayout** — A replacement indexed 16-bit list must keep the head at +0, a traversal cursor at +8, a length at +0xC, node data pointer at node+0 (two 16-bit values) and next-node link at node+4; index==length appends.
- **ForwardingWrapperSemantics** — The three single-call forwarders must delegate their single argument to StringCopyWithBufferRealloc and return the helper's result unchanged.
- **LapGapCalculationContract** — Gap computation: equal lap counts yield a signed time gap; a one-lap wrap with the leading time smaller yields flt_5EA408 - v7 + v9; otherwise an integer lap difference is emitted (decremented when the leading time is smaller); null input or behind-on-lap returns 1.
- **HudTimeFormatContract** — HUD time formatters seed the buffer with a prefix string and append " MM:SS.FFF" only when the selected time float is positive.

## Unresolved

- The callee StringCopyWithBufferRealloc is named in the source text but has no entry in the packet's callee list; its address, owner and buffer semantics are unknown.
- Owner identities are not established for ZeroInitInt (0x0049A180), SevenFieldSentinelInit (0x0049A580) and ConditionalHeadStoreOrIterateAndSet (0x0049A1C0); the latter's chain-step sub_499E00 and the FieldSetterAt0x68 node field at +0x68 are not documented.
- StringHashTable bucket-count (26, from the destructor) vs CharToIndexConversion's range are not proven to be the same array; the +4..+14 node fields written by PatternedFieldInit are never read inside this packet, so their role (flag array?) is unknown.
- TwoChannel16BitReader (0x00499F00) gating via ShortComputation_adb0(this + 0x6C) > 2 and its ambiguous return value are not resolved; its owner assignment to IndexedListAccessor is GUESS.
- IndexedListAccessor's +0xC field is ambiguous between length and capacity: the append path compares it against the length while the out-of-range path uses it as an upper bound.
- RectangleRegionState, QuadDwordFieldWriter and SentinelInitializedObject overlap the same offsets (+0x14..+0x20 and +0x4..+0x10) across different callers; common ownership is NOT proven, so they are kept as separate bases rather than merged.
- The postProcessInput label for dword_7C54E0 comes from existing analysis prose, not packet evidence; the meaning of its offsets (16448, 16552, 16484, 16592, 16596, 18168, 13004) and the 4656 ghost stride are inferred.
- The global 0x007CE234 (DriverAppearanceFlag per the skeleton fill) is absent from the raw source of 0x0049D3F0, as are globals 0x0059E440, 0x005CCE24, 0x008ACEE0 (0x0049BFF0), 0x005CCE34/0x005CCE64 (0x0049C370), 0x005CCE44/0x005CCE78 (0x0049C4E0) and 0x005C3280 (0x0049C8A0); their roles are unresolved.
- The constant return-0 on every path of the formatters is not evident as success/failure/void-like; LapTimeGapCalculation's time sub-object offset +12 has no dedicated field evidence reference.
- String format literals (asc_5CCE18, asc_5CCE54, aS_6, a3d, word_5C694C, off_5CCE74 vs aLaps_0) are read from existing analysis; exact string contents are not verified in the packet.
- PostProcessInputState offsets (championship threshold source +0x32CC, session mode +0x3450, time slot index +0x4040, debug suppression +0x4064, lap times +0x40A8, name/target pointers +0x40D0/+0x40D4) and the SentinelInitializedObject sub-object at +0x24 have no field:this evidence refs in the packet (the packet only allows field:this offsets 0x0..0x64 and 0x403C); they are recorded as prose in the class responsibilities rather than as class fields.
