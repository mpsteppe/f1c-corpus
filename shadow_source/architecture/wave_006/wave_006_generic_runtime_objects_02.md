# GenericRuntimeObjectFacilities

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Conservative architecture for 27 validated runtime-object functions. Dominant patterns: (1) teardown routines gated on a this+0x8 enable byte that free a data block and optionally the container (TextDisplayStructure, LinkedListContainer, DestructorWithDoubleFreePattern); (2) bounds-checked indexed accessors returning the first char* of a linked-list entry with a global fallback (StringListContainerA/B, SubObjectPropertyWrapper, DirectoryListSorter); (3) display formatters sharing a this+0x4 unit/selection flag, the byte_5C3734/byte_5C3738 unit strings and StringFormatWithBufferOverflowCheck (MenuDisplayFormatter); (4) small double-coefficient physics objects evaluated on the per-frame path (QuadraticSpringModel, QuadraticFormMatrix); (5) a large vehicle/physics state object whose fields span this+0x0..this+0x453C (VehicleObject) including construction-time reference stores, lateral torque output, wheel target setter and the AI target-vehicle pointer; (6) session-lifecycle global-driven handlers (DynManPostProcessor, SessionTypeHandler). Most owners are UNKNOWN in the packet; class boundaries and field names are DERIVED/GUESS proposals only.

## Function roles

- `0x00410F60` **SceneNodeDecoder** — Scene-node transform decoder: decodes a 6-bit node-group type and 16-bit node index from the packed node header, dispatches via jump table 0x00411100 into six node groups, bounds-checks the index against the group count, resolves a target pointer as base + stride*idx + 208, and forwards a decoded 24-byte transform (six floats) to the transform consumer at 0x0054B4D0.
- `0x00411AB0` **RandomRangeTable** — Two-phase initializer for a 537-entry table of (range, random-offset) 16-bit pairs behind this: defaults every pair to (1, 0), then for index bands 1..290 (word_5BEBB0) and 293..535 (word_5BF2F8) derives a range from the boundary tables via TableLookupByIndex and draws a random offset via RandLCGRandomNumberGenerator; indices {0, 291, 292, 536} keep the default.
- `0x00418C10` **TextDisplayStructure** — Deep cleanup of a text display structure: when this+0x8 is set and the data block at this+0x0 is non-null, reinitializes the block via TextFormatStructInitializer, frees nine internal pointers (eight at 5-dword stride plus the first) and the block via FreeWrapper_7bcf, then optionally frees the container when a2 bit 0 is set; returns this.
- `0x00418D60` **TextDisplayStructure** — Destructor-like cleanup for a pointer container: if this+0x8 is non-zero and the data block *this is non-null, frees the first internal pointer and the block via FreeWrapper_7bcf; optionally frees the container when a2 bit 0 is set; returns this.
- `0x00418DB0` **GlobalStateReset** — Unconditional global state reset: writes 0 into the four consecutive dwords dword_5EBB18..dword_5EBB24 and returns 0.
- `0x004190C0` **LinkedListContainer** — Linked-list teardown: walks the list whose head is at this+0x1A0, frees each node's data pointer when the node+8 byte flag is zero and frees every node via FreeWrapper_7bcf, then zeroes the four list-management fields this+0x1A0..0x1AC; returns the last FreeWrapper result.
- `0x00424040` **VehicleObject** — Vehicle construction-time setter: stores the input at this[0] and again at this[0x4034], invoking F_4FieldPropagation on the input in between, and returns that call's result.
- `0x00426CC0` **VehicleObject** — AI speed-delta helper: returns the difference of the float at +76 between a caller-supplied vehicle and the target vehicle pointer at this+0x4354; returns 0.0 for a null input and -1.0 when no target vehicle is set.
- `0x0042AD00` **VehicleObject** — Lateral torque helper on the per-frame physics tick: multiplies the input force by the coefficient at this+0x44F4 and the fixed scaling constant 0.0099999998, storing the product into this+0x453C (a recalculated field).
- `0x0042BB50` **VehicleArrayConstructor** — Bulk construction loop: calls VehicleObjectConstructor on 104 slots starting at 0x005EC6D8 with stride 0x48C0 and returns the last constructor result.
- `0x0042C9F0` **DynManPostProcessor** — DynMan post-processing handler: optionally logs a debug entry gated on StringSplitLoop, resets every vehicle in the array at 0x7C54F0 (count at 0x5C329C) via per-vehicle reset 0x004C6E80, initializes wheel dynamics from race-elapsed-time at 0x7C7428, resets season scoring, and destroys graphics resources through the global instance at 0x5EA560.
- `0x0042CE20` **SessionTypeHandler** — Single-purpose no-op passthrough: invokes an unresolved stub with the address of global dword_7C569C and returns the stub's result unchanged.
- `0x0042DD80` **WeightedLookupTable** — Weighted-ratio lookup over a 1D 8-byte-entry table: rejects negative / out-of-range indexes (count at this+0x8), non-positive base entries (this+0xC) and non-positive divisors (this+0x10); otherwise returns (scale*weight)/(base*divisor) using scale at this+0x14.
- `0x0042E470` **StateChangeTrigger** — State-change event trigger: when the entity IDs at a2+16 and a3+16 match and the state at a3+20 differs from a2+20, copies the reference state into a3+20 and raises the flags at this+0x0 and this+0x19A4 to 1; returns the matched state.
- `0x0042E4A0` **WeightedBalanceStruct** — Weighted-sum balancer: while a2's weighted sum (base + index*coefficient) exceeds a1's beyond a tolerance multiplier, decrements a2's index (when flag and index > 0) or increments a1's index (below maxIndex - 1), re-checking after each step.
- `0x0042EC00` **MenuDisplayFormatter** — UI message formatter: selects a format template by the this+0x4 flag (byte_5C3738 vs byte_5C3734), resolves it through BinarySearchInStringTable into byte_5EC4CC, then formats with the argument table off_5C3730 via StringFormatWithBufferOverflowCheck.
- `0x004313C0` **VehicleObject** — Physics-state pressure/force field mapping: builds blend factors from tire surface-contact floats (this+0x1CA8/0x1CAC/0x1CB0/0x1CB4), clamps grid-index fields via PositionIndexClamp, fills a local table via SessionStateIndexedLookup, runs a minimum-deviation index search over this+0x1640/0x1644 entries and a nearest-index loop over this+0x16C0/0x16C4 elements (stride 0x40).
- `0x00431950` **MenuDisplayFormatter** — Temperature formatter: converts Kelvin to Celsius (a2 - 273.16), optionally to Fahrenheit when this+0x4 == 1, selects the unit string (byte_5C3738 Fahrenheit / byte_5C3734 Celsius) and formats the integer plus unit via the "%d %s" template with StringFormatWithBufferOverflowCheck.
- `0x00431A50` **VehicleObject** — Unconditional flagged setter on the wheel-dynamics path: stores the input as a dword at this+0x1CBC and raises the byte flag at this+0x1CB8 to 1; returns the input.
- `0x00431AA0` **MenuDisplayFormatter** — Telemetry triplet formatter: reads three consecutive Kelvin floats from the index-derived temperature array, converts to Celsius, optionally to Fahrenheit by the this+0x4 flag, formats either the full triplet ("%3d/%3d/%3d %s") or a single value, clears a per-index flag byte, and returns the format result.
- `0x00432820` **StringListContainerA** — Bounds-checked indexed list-entry accessor (container layout A): rejects out-of-range indexes against the count at *(this)+0x2C, walks the list from the head at *(this)+0x20 via next pointers at node+4, and returns the first char* at entry-data+0, falling back to byte_5EA438 for a null string.
- `0x00432920` **SubObjectPropertyWrapper** — Wrapper accessor: dereferences this[0] to a sub-object and returns the DWORD at sub-object offset 0x3C.
- `0x00432930` **StringListContainerB** — Bounds-checked indexed list-entry accessor (container layout B, offsets +0x30/+0x3C instead of +0x20/+0x2C): structurally identical to 0x00432820, walking next pointers at node+4 and returning the first char* at entry-data+0 with the byte_5EA438 fallback.
- `0x00433EB0` **PathStateCleanup** — Cleanup wrapper: resets the shared AI state buffer at byte_7C56C0 via AIStateBufferInitialize and copies the default application-directory path byte_5EA438 into the object's path buffer via StringCopyWithBufferRealloc, returning the copy result.
- `0x00434090` **DirectoryListSorter** — Merge sort over a singly linked list of string entries with the result head/tail stored into this[0]/this[4]/this[8]: splits at the midpoint, recursively sorts both halves, merges in ascending order with a 2-byte-stride lexicographic comparison (null strings fall back to byte_5EA438) and reconnects head and tail.
- `0x00436230` **QuadraticFormMatrix** — 3-axis quadratic form evaluator: per axis selects one of two 3-element coefficient rows of `this` by the sign of a2[i], accumulates row * a2[i]^2 into a 3-double output copied to a4, and builds an anti-symmetric 3-element output a5 from this+0x90/0x98/0xA0 scaled by a3[i]^2, negated when a3[i] is positive.
- `0x00436470` **QuadraticSpringModel** — Quadratic spring evaluation: evaluates two quadratics at a2 (force set from +0x4/+0xC/+0x14 into +0x34; derivative set from +0x1C/+0x24/+0x2C into +0x3C) on the per-frame suspension solver path.

## Proposed classes

### SceneNodeDecoder

Decodes packed scene-node transforms by dispatching a 6-bit node-group type to one of six node groups, each holding a count and a base pointer; resolves base + stride*idx + 208 and forwards six decoded floats (rotations and packed position) to a transform consumer.

Methods: `0x00410F60`

- `this+0x00000024` `unsigned int groupACount` (read, GUESS)
- `this+0x0000002C` `void* groupABasePointer` (read, GUESS)
- `this+0x00000030` `unsigned int groupBCount` (read, GUESS)
- `this+0x00000038` `void* groupBBasePointer` (read, GUESS)
- `this+0x0000003C` `unsigned int groupCCount` (read, GUESS)
- `this+0x00000044` `void* groupCBasePointer` (read, GUESS)
- `this+0x00000048` `unsigned int groupDCount` (read, GUESS)
- `this+0x00000050` `void* groupDBasePointer` (read, GUESS)
- `this+0x00000054` `unsigned int groupECount` (read, GUESS)
- `this+0x0000005C` `void* groupEBasePointer` (read, GUESS)
- `this+0x00000060` `unsigned int groupFCount` (read, GUESS)
- `this+0x00000068` `void* groupFBasePointer` (read, GUESS)

### RandomRangeTable

Owns a 537-entry table of (range, random-offset) 16-bit pairs populated at startup from two index-banded boundary tables and an LCG; most indices get randomized ranges, edge indices keep a (1, 0) default.

Methods: `0x00411AB0`


### TextDisplayStructure

Text-display container whose cleanup (and optionally container deletion) is gated on a this+0x8 enable byte; deep cleanup frees a set of internal pointers plus the data block, a shallow variant frees the first pointer only.

Methods: `0x00418C10`, `0x00418D60`

- `this+0x00000000` `void* dataBlock` (read, DERIVED)
- `this+0x00000008` `byte cleanupEnableFlag` (read, DERIVED)

### GlobalStateReset

Resets four consecutive global dwords (dword_5EBB18..dword_5EBB24) to zero; purpose of the globals is unknown.

Methods: `0x00418DB0`


### LinkedListContainer

Holds a singly linked list (head at this+0x1A0) of nodes with +0 data, +4 next, +8 flag; teardown frees node data conditionally and every node, then zeroes the four list-management fields.

Methods: `0x004190C0`

- `this+0x000001A0` `ListNode* listHead` (read_write, GUESS)
- `this+0x000001A4` `ListNode** listNodeNextField` (write, GUESS)
- `this+0x000001A8` `unsigned int listCount` (read_write, GUESS)
- `this+0x000001AC` `dword listAuxiliaryField` (write, GUESS)

### VehicleObject

Large per-vehicle state object (offsets span this+0x0..this+0x453C within a 0x48C0-stride slot): construction-time reference store, AI target-vehicle pointer, lateral-torque coefficient and output, tire surface-contact floats and pressure/force-field index tables, and a flagged wheel target value setter. Field ownership is inferred from offset range and physics/AI context, not proven by the packet.

Methods: `0x00424040`, `0x00426CC0`, `0x0042AD00`, `0x004313C0`, `0x00431A50`

- `this+0x00000000` `void* or dword storedReference` (read_write, GUESS)
- `this+0x00001640` `unsigned int pressureEntryCount` (read, GUESS)
- `this+0x00001644` `unsigned int pressureSelectedIndex` (read_write, GUESS)
- `this+0x00001648` `unsigned int pressureElementHeader` (read, GUESS)
- `this+0x000016C0` `unsigned int pressureSubEntryCount` (read, GUESS)
- `this+0x000016C4` `unsigned int pressureElementIndexSlot` (read_write, GUESS)
- `this+0x000016C8` `unsigned int pressureElementIndexSource` (read, GUESS)
- `this+0x000016CC` `byte pressureElementFlag` (read, GUESS)
- `this+0x00001CA8` `float tireSurfaceContactA` (read, GUESS)
- `this+0x00001CAC` `float tireSurfaceContactB` (read, GUESS)
- `this+0x00001CB0` `float tireSurfaceContactC` (read, GUESS)
- `this+0x00001CB4` `float tireSurfaceContactD` (read, GUESS)
- `this+0x00001CB8` `byte wheelValueChangedFlag` (write, GUESS)
- `this+0x00001CBC` `dword wheelTargetValue` (write, GUESS)
- `this+0x00004034` `void* or dword storedReferenceCopy` (read_write, GUESS)
- `this+0x00004354` `void* targetVehiclePointer` (read, GUESS)
- `this+0x000044F4` `float lateralForceCoefficient` (read, GUESS)
- `this+0x0000453C` `float lateralTorqueOutput` (write, GUESS)

### VehicleArrayConstructor

Constructs the fixed 104-slot vehicle array at 0x005EC6D8 (stride 0x48C0) by calling VehicleObjectConstructor on each slot.

Methods: `0x0042BB50`


### DynManPostProcessor

Post-race (DynMan_Post) handler driven entirely by globals: optionally logs a debug entry, resets all live vehicles, initializes wheel dynamics from race elapsed time, resets season scoring, and destroys graphics resources.

Methods: `0x0042C9F0`


### SessionTypeHandler

Per-session-type placeholder handler that passes the address of global dword_7C569C to an unresolved stub and returns its result.

Methods: `0x0042CE20`


### WeightedLookupTable

Reads a weighted ratio from a 1D 8-byte-entry table guarded by count, entry base and divisor; returns a scaled ratio or a 0.0 sentinel.

Methods: `0x0042DD80`

- `this+0x00000008` `unsigned int dataCount` (read, GUESS)
- `this+0x0000000C` `void* dataArrayPointer` (read, GUESS)
- `this+0x00000010` `double divisor` (read, GUESS)
- `this+0x00000014` `double scaleFactor` (read, GUESS)

### StateChangeTrigger

Detects a state change on a tracked entity (entity ID at +16, state at +20) and raises two trigger flags on itself when the reference state differs.

Methods: `0x0042E470`

- `this+0x00000000` `dword eventTriggerFlag` (write, GUESS)
- `this+0x000019A4` `dword stateChangeDetectedFlag` (write, GUESS)

### WeightedBalanceStruct

A weighted-sum struct (base at +0, coefficient at +8, maxIndex at +0x10, currentIndex at +0x14) whose current index is adjusted to balance two such structs within a tolerance.

Methods: `0x0042E4A0`

- `this+0x00000000` `double weightedBaseValue` (read, GUESS)
- `this+0x00000008` `double weightedCoefficient` (read, GUESS)
- `this+0x00000010` `int maxIndex` (read, GUESS)
- `this+0x00000014` `int currentIndex` (read_write, GUESS)

### MenuDisplayFormatter

Menu/telemetry display formatting object sharing a this+0x4 selection/unit flag (1 selects the primary format buffer / Fahrenheit), the byte_5C3738 and byte_5C3734 unit/format strings, and safe string formatting via StringFormatWithBufferOverflowCheck; all three methods are called by MenuCommandDispatcher.

Methods: `0x0042EC00`, `0x00431950`, `0x00431AA0`

- `this+0x00000004` `dword unitOrSelectionFlag` (read, GUESS)

### StringListContainerA

Container (via a this[0] pointer) holding a linked list head at +0x20 and an entry count at +0x2C; provides bounds-checked indexed access to the first char* of each entry with a global fallback string.

Methods: `0x00432820`

- `this+0x00000000` `void* containerPointer` (read, GUESS)
- `obj+0x00000020` `ListNode* containerListHead` (read, GUESS)
- `obj+0x0000002C` `unsigned int containerEntryCount` (read, GUESS)

### SubObjectPropertyWrapper

Thin wrapper over a sub-object reached through this[0]; reads a DWORD property at sub-object offset 0x3C.

Methods: `0x00432920`

- `this+0x00000000` `void* subObjectPointer` (read, GUESS)
- `obj+0x0000003C` `dword subObjectPropertyDword` (read, GUESS)

### StringListContainerB

Container (via a this[0] pointer) holding a linked list head at +0x30 and an entry count at +0x3C; structurally identical accessor to StringListContainerA but with a different field group. Whether this is a second field group of the same class or a distinct class is unresolved.

Methods: `0x00432930`

- `this+0x00000000` `void* containerPointer` (read, GUESS)
- `obj+0x00000030` `ListNode* containerListHead` (read, GUESS)
- `obj+0x0000003C` `unsigned int containerEntryCount` (read, GUESS)

### PathStateCleanup

Resets the shared AI state buffer and copies the default application-directory path into an object path field during cleanup.

Methods: `0x00433EB0`


### DirectoryListSorter

Merge sorts a singly linked list of string entries, storing the sorted head/tail (and a duplicate head) into this[0]/this[4]/this[8]; used during directory entry enumeration.

Methods: `0x00434090`

- `this+0x00000000` `ListNode* sortedHead` (read_write, GUESS)
- `this+0x00000004` `ListNode* sortedTail` (write, GUESS)
- `this+0x00000008` `ListNode* sortedHeadDuplicate` (write, GUESS)

### QuadraticFormMatrix

3-axis quadratic-form coefficient matrix with per-axis row selection by input sign and an anti-symmetric output built from this+0x90/0x98/0xA0; used on the suspension-force path.

Methods: `0x00436230`

- `this+0x00000090` `double antiSymmetricCoefficient0` (read, GUESS)
- `this+0x00000098` `double antiSymmetricCoefficient1` (read, GUESS)
- `this+0x000000A0` `double antiSymmetricCoefficient2` (read, GUESS)

### QuadraticSpringModel

Double-coefficient suspension spring model: evaluates force and derivative quadratics at a travel input and stores both results into the coefficient object.

Methods: `0x00436470`

- `this+0x00000004` `double forceConstantTerm` (read, GUESS)
- `this+0x0000000C` `double forceLinearCoefficient` (read, GUESS)
- `this+0x00000014` `double forceQuadraticCoefficient` (read, GUESS)
- `this+0x0000001C` `double derivativeConstantTerm` (read, GUESS)
- `this+0x00000024` `double derivativeLinearCoefficient` (read, GUESS)
- `this+0x0000002C` `double derivativeQuadraticCoefficient` (read, GUESS)
- `this+0x00000034` `double forceResult` (write, GUESS)
- `this+0x0000003C` `double derivativeResult` (write, GUESS)

## Compatibility contracts

- **VehicleSlotArrayLayout** — The game constructs 104 vehicle slots starting at 0x005EC6D8 with a stride of 0x48C0, each slot constructed by the vehicle constructor at 0x004C6920. A replacement must preserve this base/stride/count and the per-slot construction entry point.
- **SceneNodeTransformDecode** — Packed scene-node headers encode a 6-bit node-group type and a 16-bit node index; the decoder dispatches into six node groups (stride 792, group D stride 808), resolves a target at base + stride*idx + 208, and converts the packed 24-byte transform into six floats using scale constants 0.00048828125 (rotation int16s at node+19/21/23) and 0.000030517578 (packed position across node+10..18), forwarding them to the transform consumer at 0x0054B4D0.
- **RandomRangeTableInit** — A 537-entry table of (range, random-offset) 16-bit pairs is initialized to (1, 0) everywhere, then indices 1..290 and 293..535 are randomized from boundary tables word_5BEBB0 / word_5BF2F8 with the LCG at 0x005884ED; indices {0, 291, 292, 536} must keep the default.
- **TextDisplayCleanupPattern** — Text-display containers gate cleanup on the byte flag at +0x8 and a non-null data block at +0x0. Deep cleanup frees nine internal pointers plus the block; a shallow variant frees the first pointer plus the block. When the caller's a2 bit 0 is set the container itself is freed as well. All frees go through FreeWrapper_7bcf.
- **StringListEntryAccessorContract** — Indexed accessors over linked-list containers return 0 for out-of-range indexes, null nodes and null entry data, and return the first char* of the Nth entry (entry data at node+0, first string at data+0); a null string falls back to the global byte_5EA438. Both layout variants (+0x20/+0x2C and +0x30/+0x3C) must preserve this behavior.
- **TemperatureDisplayUnits** — Display formatters convert Kelvin to Celsius by subtracting 273.16 and, when the unit flag at +0x4 equals 1, convert Celsius to Fahrenheit via (C + 40.0) * 1.8 - 40.0, selecting the byte_5C3738 (Fahrenheit) or byte_5C3734 (Celsius) unit string; formatting goes through StringFormatWithBufferOverflowCheck.

## Unresolved

- Most function owners are UNKNOWN in the packet; the class boundaries proposed here (especially the broad VehicleObject grouping) are inferred from this-field offset ranges and shared callers, not proven. Per rule 8, equal offsets on different bases (e.g. obj:0x3C in both SubObjectPropertyWrapper and StringListContainerB) were not merged.
- Behavior of the transform consumer 0x0054B4D0 on the six decoded floats is unknown; the meaning of the value returned to the caller LinkedListIteratorWithStateUpdate (0x004B5760) is not established.
- The semantic mapping of the six node-group types and the reason for the stride difference (792 vs 808) in group D are not established.
- The purpose and consumer of the 537-entry (range, random-offset) table, and the meaning of boundary indices {291, 292} and the two index bands, are unknown.
- Whether the DestructorWithDoubleFreePattern (0x00418D60) double-free is intended depends on the caller contract; the element type behind *v3 is unknown.
- Purpose of the four consecutive globals dword_5EBB18..dword_5EBB24 is unknown.
- The node struct layout (+0 data, +4 next, +8 flag) in LinkedListContainer and the meaning of the node+8 flag are inferred from dereferences, not named by the packet.
- The purpose of storing the input at both this[0] and this[0x4034] in 0x00424040 and what F_4FieldPropagation propagates into are unknown.
- Read-only globals dbl_59E420, dbl_59E880 (0x004313C0), dbl_59E444 (0x0042AD00), dbl_59EAB0/59EAB8/59EAC0/59EAC8 and aDS 0x5C3778 (0x00431950/0x00431AA0) are flagged by packet facts but absent from the raw decompiled source; their roles (coefficient storage, temperature transform constants) are not deterministically tied.
- The float at +76 in each vehicle in 0x00426CC0 is not proven to be the same quantity; field this+0x43A0 is accessed in the IDB but absent from the decompiled body.
- The coefficient rows this[0..17] of QuadraticFormMatrix are read by the raw source but have no packet field entries; the fill's 'compression stiffness' label for 0x90/0x98/0xA0 conflicts with their use as anti-symmetric a5 coefficients.
- The meaning of the second quadratic set in 0x00436470 as a 'derivative' comes from prior fill prose, not from this function alone.
- The base/weight/divisor/scale roles in WeightedLookupTable and the weighted-sum field roles in 0x0042E4A0 are derived from arithmetic shape, not named by the packet; dbl_59E9F0 as tolerance is inferred.
- The a2 argument of LinkedListMergeSort (0x00434090) is never referenced in the visible decompilation; the sort-result class and the wide-character (2-byte stride) comparison interpretation are DERIVED.
- The unresolved stub callee of SessionTypeHandler (0x0042CE20) and the final graphics-resource destructor of DynManPostProcessor (0x0042C9F0) are absent from the packet callee table; their call targets are unknown.
- Whether StringListContainerA (+0x20/+0x2C) and StringListContainerB (+0x30/+0x3C) are two field groups of one class or two classes is unresolved; they are modeled as distinct classes behind the shared IStringListEntryAccessor interface.
- The unit/selection flag at this+0x4 is only observed as binary (1 vs else); the full set of meaningful values is not evident. The MenuDisplayFormatter grouping (three methods sharing this+0x4, the unit strings and caller 0x004674E0) is a DERIVED proposal, not proven common ownership.
- Semantics of the index-derived temperature array base this + (3*a2 + 1851)*4 and the reset byte this + a2 + 7400 in 0x00431AA0, and of the a4 selector values other than 3, are not documented.
- The returned char* of the two list accessors (a directory/file path per existing analysis) and the content of the default string byte_5EA438 are inferred, not established.
- The role of the returned values in 0x004190C0 (last FreeWrapper result), 0x00431AA0 (format result) and 0x00434090 (trailing merge value) have no meaningful semantic contract.
