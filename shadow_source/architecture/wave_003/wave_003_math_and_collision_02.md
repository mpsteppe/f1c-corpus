# MathAndCollision

Scope: `math_and_collision`  
Trust: `DERIVED`

This scope is a mixture of math utility and resource lifecycle code. AngleAxisRotateMatrixToEuler (0x00567120) applies a Rodrigues angle-axis rotation to an in-place 3x3 float matrix and extracts Euler angles, skipping the rotation when the axis magnitude is zero or non-finite. ObjectIDLookupAcross9Arrays (0x005684A0) and NinePointerArrayCleanup (0x00567F10) share a receiver shaped as nine dword slots: the first resolves a name to a hash entry and walks each bucket chain, the second releases every non-null slot pointer and nulls the slot. DisplayModeArrayAllocFromSoundManager (0x0055BE80) and freePointerArrayWithLinkedListCleanup (0x0055BF70) both operate on a list object with a count at +0x04 and a pointer array at +0x08; one builds 292-byte DisplayMode structs from sound-manager entries and the other frees them. ResourceTeardownWithStateArrayReset (0x00558990) releases two audio sub-resources (object at sub-context+0x1C, drain at sub-context+0x24) and resets a 128-byte-stride state array. ResetAndFreeMemberArrays (0x0056E970) tears down an owner holding four counted arrays (580/48/48/72-byte elements) plus three optional pointers and a trailing four-pointer block. No receiver class identity is proven for any function; all owners are labeled UnknownObject in the source packet and every class here is a DERIVED/GUESS grouping of shared offset patterns.

## Function roles

- `0x00558990` **ResourceTeardownOwner** — teardown - release audio sub-resources (reset+free object at this+0x6C via ObjectResetWithVirtualRelease, finalize+free drain at this+0x74 via DrainingLoopFinalizer), clear flag bit 0x100 at this+0x20, reset every 128-byte state-struct element and zero the counters
- `0x0055BE80` **DisplayModeList** — build - allocate a 292-byte DisplayMode struct per sound-manager entry, copy the entry name, record the index, register the struct and append it to the slot array; invoked from RenderUISystemGlobalInit; on zero-init failure free the partial struct
- `0x0055BF70` **DisplayModeList** — teardown - iterate the count of pointer slots at this+0x8, free each slot's linked list via LinkedListFreeWithTraversalAndNulling, free each non-null slot pointer, and null the slot; returns the count
- `0x00567120` **RotationMatrixMath** — math - apply an angle-axis (Rodrigues) rotation in place to the 3x3 float matrix this, skipping the rotation when the axis squared-magnitude is zero or non-finite (FPU status 0x4100), then always extract Euler angles into the a3 output buffer
- `0x00567F10` **NineBucketTable** — teardown - iterate the nine dword slots of the receiver, call sub_567CC0 on each non-null slot pointer, then null the slot; returns the last processed slot's result
- `0x005684A0` **NineBucketTable** — lookup - resolve a name string to a hash-table entry index via HashTableEntrySearch, then walk the nine buckets and their node chains (ShortComputation_adb0 / SimpleFieldGetter_bfc0), calling sub_568320 on every node whose FieldGetter_79d0 equals the index; returns the found flag
- `0x0056E970` **MultiArrayOwner** — teardown - free four counted arrays (580-byte elements with per-element destructor at 0x00568E60; 48/48/72-byte pointer-element arrays) and the three optional pointers, clear all slots, then free the trailing four-pointer block at this+0x34

## Proposed classes

### ResourceTeardownOwner

Receiver of ResourceTeardownWithStateArrayReset. Holds a flags dword, a sub-context at +0x50 containing an audio object pointer (+0x1C inside the sub-context, absolute this+0x6C) and a drain pointer (+0x24 inside the sub-context, absolute this+0x74), plus a 128-byte-stride state-struct array at +0x34 with a count at +0x2C and two counters at +0x30/+0x38.

Methods: `0x00558990`

- `this+0x00000020` `uint32 flags` (read_write, DERIVED)
- `this+0x0000002C` `uint32 stateArrayCount` (read, DERIVED)
- `this+0x00000030` `uint32 counterA` (read_write, GUESS)
- `this+0x00000034` `StateArrayElement* stateArray` (read, DERIVED)
- `this+0x00000038` `uint32 counterB` (read_write, GUESS)
- `this+0x00000050` `SubContext* audioSubContext` (read, GUESS)
- `this+0x0000006C` `void* audioObjectPtr` (read_write, DERIVED)
- `this+0x00000074` `void* drainPtr` (read_write, DERIVED)
- `this+0x000000AC` `uint32 stateElementField30` (write, GUESS)
- `this+0x000000B0` `uint32 stateElementField31` (write, GUESS)

### DisplayModeList

Container for DisplayMode structs built from the sound manager. Count/counter dword at +0x00, count at +0x04, pointer array of DisplayMode slots at +0x08. Build path (0x0055BE80) allocates and registers 292-byte structs; teardown path (0x0055BF70) frees each slot's linked list and the slot pointer.

Methods: `0x0055BE80`, `0x0055BF70`

- `this+0x00000000` `uint32 headCount` (read_write, GUESS)
- `this+0x00000004` `uint32 count` (read_write, DERIVED)
- `this+0x00000008` `DisplayMode** slots` (read_write, DERIVED)

### DisplayMode

292-byte display-mode descriptor allocated and populated by DisplayModeArrayAllocFromSoundManager: index written at +0x00, name string copied at +0x04 from the sound-manager entry at entry+24 (evidence only via callee refs), index mirror at +0x104 and two zero-initialized dwords at +0x108 and +0x10C. Partially zero-initialized by PartialStructZeroInit and registered by DisplayModeEnumeratorWrapper. Only the +0x104/+0x108/+0x10C fields carry field evidence refs in this packet; the +0x00/+0x04 layout is from operation text.

Methods: 

- `*(this+0x8)+0x00000104` `int32 indexCopy` (write, GUESS)
- `*(this+0x8)+0x00000108` `uint32 reservedA` (write, GUESS)
- `*(this+0x8)+0x0000010C` `uint32 reservedB` (write, GUESS)

### RotationMatrixMath

Receiver of AngleAxisRotateMatrixToEuler: an in-place row-major 3x3 float matrix (this[0..8], floats at +0x00..+0x20). Applies Rodrigues angle-axis rotation when the axis squared-magnitude is finite and non-zero, then always extracts Euler angles into the output buffer; gimbal lock handled at |this[5]| == 1.0.

Methods: `0x00567120`

- `this+0x00000000` `float m00` (read_write, DERIVED)
- `this+0x00000004` `float m01` (read, DERIVED)
- `this+0x00000008` `float m02` (read, DERIVED)
- `this+0x0000000C` `float m10` (read, DERIVED)
- `this+0x00000010` `float m11` (read, DERIVED)
- `this+0x00000014` `float m12` (read_write, DERIVED)
- `this+0x00000018` `float m20` (read, DERIVED)
- `this+0x0000001C` `float m21` (read, GUESS)
- `this+0x00000020` `float m22` (read, DERIVED)

### NineBucketTable

Receiver shared by ObjectIDLookupAcross9Arrays and NinePointerArrayCleanup: nine dword slots acting as linked-list bucket heads at +0x00..+0x20. The lookup resolves a name to a hash index and walks each bucket's chain (advancing via ShortComputation_adb0 / SimpleFieldGetter_bfc0, comparing FieldGetter_79d0); the cleanup releases each non-null slot pointer via sub_567CC0 and nulls it.

Methods: `0x00567F10`, `0x005684A0`

- `this+0x00000000` `Node* bucket0` (read_write, GUESS)
- `this+0x00000004` `Node* bucket1` (read_write, GUESS)
- `this+0x00000008` `Node* bucket2` (read_write, GUESS)
- `this+0x0000000C` `Node* bucket3` (read_write, GUESS)
- `this+0x00000010` `Node* bucket4` (read_write, GUESS)
- `this+0x00000014` `Node* bucket5` (read_write, GUESS)
- `this+0x00000018` `Node* bucket6` (read_write, GUESS)
- `this+0x0000001C` `Node* bucket7` (read_write, GUESS)
- `this+0x00000020` `Node* bucket8` (read_write, GUESS)

### MultiArrayOwner

Receiver of ResetAndFreeMemberArrays: four counted arrays anchored at +0x04 (580-byte elements), +0x0C (48-byte pointer elements), +0x14 (48-byte pointer elements) and +0x1C (72-byte pointer elements), each with a count in the header at array-4 and an owner slot at the even offsets; three optional pointers at +0x24/+0x28/+0x2C and a trailing four-pointer block at +0x34.

Methods: `0x0056E970`

- `this+0x00000000` `uint32 clearSlot0` (write, GUESS)
- `this+0x00000004` `uint8* arrayA` (read_write, DERIVED)
- `this+0x00000008` `uint32 clearSlot2` (write, GUESS)
- `this+0x0000000C` `void** arrayB` (read_write, DERIVED)
- `this+0x00000010` `uint32 clearSlot4` (write, GUESS)
- `this+0x00000014` `void** arrayC` (read_write, DERIVED)
- `this+0x00000018` `uint32 clearSlot6` (write, GUESS)
- `this+0x0000001C` `void** arrayD` (read_write, DERIVED)
- `this+0x00000020` `uint32 clearSlot8` (write, GUESS)
- `this+0x00000024` `void* optionalA` (read_write, DERIVED)
- `this+0x00000028` `void* optionalB` (read_write, DERIVED)
- `this+0x0000002C` `void* optionalC` (read_write, DERIVED)
- `this+0x00000030` `uint32 clearSlot12` (write, GUESS)
- `this+0x00000034` `void*[4] quadPointerBlock` (read, DERIVED)

## Compatibility contracts

- **DisplayModeListLayout** — DisplayModeList: count/counter dword at +0x00, count at +0x04, DisplayMode pointer array at +0x08. Each DisplayMode is a 292-byte block: index at +0x00, name string at +0x04, index mirror at +0x104, two dwords zero-initialized at +0x108/+0x10C. A replacement display-mode registry must preserve this layout for the build and teardown paths.
- **SoundManagerEntryEnumeration** — GUESS: global sound-manager handle 0x008B78A0 is prepared with a configuration argument via 0x0053D970, exposes an entry count via 0x0053D880 and a per-entry accessor via 0x0053D890 whose result holds the name string at +24. DisplayMode construction depends on this enumeration; a replacement must reproduce it if display-mode building is retained.
- **AudioSubResourceTeardown** — Teardown must reset+free the audio object at sub-context+0x1C (absolute this+0x6C) via ObjectResetWithVirtualRelease with global 0x008B78A0, finalize+free the drain at sub-context+0x24 (absolute this+0x74) via DrainingLoopFinalizer, free both when still non-null, zero both pointers, and clear flag bit 0x100 at this+0x20.
- **StateArrayReset** — State-struct array at this+0x34 with 128-byte stride and element count at this+0x2C. Reset clears header bit 6 of each element and zeroes element fields at +0x78 and +0x7C (absolute this+0xAC and this+0xB0 for element 0), then zeroes the counters at this+0x30 and this+0x38.
- **EulerRotationMatrixLayout** — Rotation helper operates on an in-place row-major 3x3 float matrix (this[0..8] at +0x00..+0x20). The Rodrigues step is skipped when the axis squared-magnitude is zero or non-finite (FPU status mask 0x4100). Euler extraction must handle gimbal lock at fabs(this[5]) == 1.0.

## Unresolved

- No receiver class identity is proven for any function; every owner is labeled UnknownObject in the source packet and the class names here are synthetic groupings of shared offset patterns.
- dword_8B78A0 is treated as a sound-manager handle but its concrete type is not proven; the same global is passed to ObjectResetWithVirtualRelease and DrainingLoopFinalizer, whose role as first argument is unexplained.
- Nature of the sub-context at this+0x50 (holding the audio object and drain pointers) and its owner class are unknown.
- State-struct array element layout beyond the 128-byte stride is unknown, including the meaning of header bit 6.
- Why flag bit 8 at this+0x20 is cleared only when the audio sub-resources existed is unclear.
- Purpose of the unused second argument (a2/a3) of DisplayModeArrayAllocFromSoundManager is unknown.
- Relationship between the this[1] tail counter and the slot array at this+0x8 is unverified.
- DisplayMode layout at +0x00 (index) and +0x04 (name) is supported only by operation text, not by a field evidence ref, so no field entries could be produced for them.
- EmptyStub_7470 (0x00557470) is described as a no-op stub; its actual behavior is not evidenced in this packet.
- The per-slot linked lists freed by LinkedListFreeWithTraversalAndNulling (0x0055BBA0) are not reconciled with the 292-byte DisplayMode struct contents.
- Globals dbl_59E420, flt_59E43C, flt_59E440 and flt_59E670 are read by AngleAxisRotateMatrixToEuler per the fact table but do not appear in the decompiled text; they may back the FPU-status (0x4100) or threshold comparisons.
- Exact Euler extraction output-slot ordering (which angle maps to a3[0], a3[1], a3[2]) is inferred from matrix element reads, not evidenced by names.
- Matrix element this[7] (offset 0x1C) is read during the rotation loop but has no dedicated field evidence ref in the packet; it is listed on RotationMatrixMath with only source:raw alongside the general field ref.
- Semantics of sub_567CC0 (per-bucket release) and sub_568320 (action on a matching node) are unknown from this packet.
- The two FieldGetter_79d0 comparisons in ObjectIDLookupAcross9Arrays pass uninitialized decompiler registers v8/v11; the intended node arguments are inferred, and whether this[v4] buckets and the two chain levels are distinct or overlapping is not established.
- QuadPointerFree appears only as a name in the raw text of ResetAndFreeMemberArrays with no address evidence, so the trailing four-pointer block teardown target cannot be referenced.
- Element types of the four counted arrays (580-, 48-, 48- and 72-byte strides) are not identified; the prelabel template's ctor_init categorization contradicts the observed teardown body and is treated as a false lead.
