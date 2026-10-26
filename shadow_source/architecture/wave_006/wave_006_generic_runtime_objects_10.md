# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Reconstruction of generic runtime objects from 35 validated function IR records. No packet owner is named, so all classes are GUESS-level groupings anchored on shared field layouts and call patterns. The strongest cross-function grouping is the SpeedScalarProvider cluster (0x0049B8D0, 0x0049B900, 0x0049B950) which all read float fields under the same global pointer dword_7C54E0 (velocity components at +0x34F8/0x34FC/0x3500, speed float at +0x39A0). The doubly-linked list (0x00496750, head/tail/secondary/count at this+0x18BC/0x18C0/0x18C4/0x18C8 with 16-byte nodes) and the named search list (0x00497650, head this+0x4, cursor this+0xC, node name at +0x34) form two distinct list families. Widget rectangle arithmetic links 0x0049AAD0 and 0x0049AB60 through the shared 16-bit rectangle at this+0x24..0x2A. Constructor/destructor wrappers (0x00498D20, 0x00499260, 0x004995E0, 0x0049A5A0) and UI state field accessors form single-method classes. Every function's matched node data, call relationships, and field bases are attributed in function_roles; contradictions (packet-listed fields absent from raw source, ABI names that do not match raw semantics) are recorded in unresolved.

## Function roles

- `0x00496750` **DoublyLinkedListWithFlag** — DoublyLinkedListAppendWithFlag: allocates a 16-byte node (value, next, prev, byte) via OperatorNewNhMallocWrapper (0x00587C03), links it after the tail this+0x18C0 (or initializes head this+0x18BC and secondary this+0x18C4 on first insertion), updates the tail and increments the count this+0x18C8; when a3 is non-zero sets the byte flag this+0x24 to 1; returns a3. Called by GameObjectUpdateFrame and DirectoryChangeHandler.
- `0x00497650` **NamedListContainer** — SearchListItemByName: caches the list head this+0x4 into the traversal cursor this+0xC, walks nodes (first dword = data, +4 = next, name at node+0x34 defaulting to global byte_5EA438) comparing names with a2 via sub_588410 (returns 0 on match per existing analysis); returns the matched node's data dword or 0 when empty/exhausted/no match. Sole caller sub_49A5D0.
- `0x00497980` **SpriteBitmapNameProvider** — GetSpriteBitmapName: guarded accessor returning the name string of a bitmap/sprite descriptor. Reads the descriptor pointer from this+0x18; returns 0 when it or the guard field this+0x60 is null. Otherwise reads the sub-descriptor pointer at this+0x68 and returns the name pointer at its offset 0x34, falling back to global byte_5EA438 when null. Invoked by sub_404B60 and KeyBindingUIPressKeyOrController.
- `0x004979B0` **ComputationDelegationThunk** — delegateToShortComputation5b30: thin __thiscall delegation thunk forwarding this unchanged to ShortComputation_5b30; returns void. Reached from sub_49A5D0. The ABI-name 'polling loop' is not visible in the raw thunk source.
- `0x004979E0` **UiStateFieldOwner** — clearField20: trivial void thiscall that unconditionally writes 0 to the DWORD at this+0x20. Acts as a reset/clear for a UI state field. Invoked by UIWidgetVisibilityToggle at 0x0048B91A.
- `0x00497D00` **DataAndDirtyFlagSetterOwner** — SetDwordAndFlag: stores parameter a2 into the DWORD field this+0x18A8, sets the byte field this+0x18EC to 1 (activation/dirty flag), and returns a2. Unconditional, no guards. Called by sub_49A5D0.
- `0x004988C0` **ByteFlagSetterOwner** — setByteField18F5: char-returning thiscall writing the byte argument a2 to the single-byte field this+0x18F5 and returning a2 unchanged. Simple flag/toggle setter. Invoked by KeyBindingUIPressKeyOrController (0x0046B0C0) and sub_46BF10 (0x0046BF10).
- `0x00498940` **FloatFieldGetterOwner** — getFloatFieldC4: double-returning thiscall reading the float at this+0xC4 and returning it widened to double. Read-only getter, no side effects. Invoked by UIScrollListUpdate (0x0048A8D0).
- `0x00498D20` **VTableInitConstructorOwner** — InitWithVTableParam: thiscall constructor. Calls parent constructor ConstructorWith1Sentinels (0x0049A930), writes the vtable pointer off_5AC9E8 to this+0x0, calls MultiFieldStructInit (0x00498DF0), stores constructor argument a2 at this+0x44, and returns this. Called by ConstructorWithVTableAndSubInit_9140 (0x00499140).
- `0x00498EB0` **ChildLinkedListContainer** — LinkedListAppendWithChildLinking: increments the node counter this+0x5C, walks a2's child list (first child a2[36], linked via offset 0x8C) setting each child's back-links (child+0x98 = this, child+0x9C = 0), calls MultiRegionOffsetAccumulationWithVTableDispatch (0x004869E0) with (a2, this[3], this[1]), then appends a2 to the tail of the list anchored at this+0x4C via the 0x8C next pointers (or sets this+0x4C = a2 on empty). Returns a2. Called by SetInitCall (0x004975B0).
- `0x00498F60` **DwordField4CGetterOwner** — GetDwordField0x4C: trivial getter returning the dword at this+0x4C. No side effects, guards, or callees. Invoked by ShortComputation_58d0 (0x004958D0), ObjectSearchWithDoubleIteration (0x00495980) and DualListDestruction (0x00498D90).
- `0x00499260` **ScalarDeletingDestructorOwner** — ConditionalDestructor_9260: scalar deleting-destructor wrapper (MSVC pattern). Always runs DestructorWithListWalk (0x00499280); when the low bit of flag a2 is set frees the object via FreeWrapper_7bcf (0x00587BCF); returns this. No field or global access.
- `0x004995E0` **DataFreeDestructorOwner** — DestructorWithDataFree: destructor helper. When the flag byte at this+0x8 is set, captures the pointer at this+0x0 and, if non-null, calls FreeIfNonNull (0x00499AE0) on it and frees the captured block via FreeWrapper_7bcf (0x00587BCF). When (a2 & 1) is set additionally frees the object itself via FreeWrapper_7bcf. Returns this. Invoked by sub_495300 (0x00495300).
- `0x00499690` **RecursiveDirectoryCleaner** — recursiveDeleteFiles: recursively deletes files under a directory path. Validates the path, normalizes a trailing backslash (word_5C2AAC), appends the file search pattern pointed to by dword_5C2AB8, then enumerates with FindFirstFileA/FindNextFileA/FindClose (globals 0x0059E0E0/0x0059E0E4/0x0059E0E8). For files it clears the read-only attribute (ToggleFileReadOnlyAttributeViaWin32API 0x0058BA36) and deletes (FileDeleteWithErrorHandling 0x0058986E); the first successful file deletion aborts the walk. Directory entries (0x10 attribute) are skipped when ".." or matching word_5BEB48, otherwise the function recurses (self-call). On exhaustion without a deletion, calls sub_59B9F3 and returns (result == 0). Called by ProfileAlreadyExistsPageHandler (0x0046CB50).
- `0x00499850` **SmallStructInitOwner** — SmallStructInit: struct initializer writing literal 3 into the dword at this+0x0, a zero byte at this+0x4, then zeroing dwords this+0x8/0xC/0x10/0x14. No reads, globals, or callees. Returns 0. Invoked by 0x00499840 and 0x004998E0.
- `0x00499870` **LinkedListIteratorOwner** — LinkedListIteratorAdvance: advances a linked-list iterator by one node. Guards on the current node this+0x10 (false when exhausted); loads the container this+0xC, refreshes the container traversal slot (container+0xC) from the current node's link field (+4 via the temporary at this+0x18), dereferences the first dword of the next-candidate node (*(this+0x18)) to obtain the new current node, stores it to this+0x10, updates this+0x14 with FieldGetter_8e30 (0x00498E30). Returns (this+0x10 != 0). Invoked from sub_499910.
- `0x004998C0` **LinkedListCursorOwner** — LinkedListNodeTraversal_98c0: advances a linked-list iterator one step: reads the next node pointer at node+72 (0x48) from the current node stored at this+0x14, replaces this+0x14 with it, and returns true while a node remains; returns false when the current node is NULL.
- `0x00499A30` **StringSlotSetterOwner** — StringFieldSetter: string-and-id thiscall setter. Calls StringCopyWithBufferRealloc (0x00566650) on a2, assigns the result to the DWORD slot this+0x8, and returns the copy result. Used by SpriteTextureEnumeration (0x00498950) during string/resource field assignment.
- `0x00499B10` **ZeroFieldConstructorOwner** — ObjectConstructorInit: thiscall constructor initializing 13 DWORD fields this+0x0 through this+0x30, all zeroed except this+0x18 set to 1036831949 (float 0.1). No callees or guards. Called by UIObjectConstructor_7ea0 (0x00477EA0), UIObjectConstructor_8e10 (0x00478E10), UITextDisplayConstructor (0x00488180) and sub_499F70 (0x00499F70).
- `0x00499B80` **IndirectLookupInitOwner** — ObjectFieldInitWithIndirectLookup: constructor-style initializer storing parameter a2 into this+0x20 and zeroing this+0x0 and this+0x8. When a2 is non-null, reads two values through two-level pointer indirection from a2+12 (offsets +28 into this+0x4 and +32 into this+0xC); otherwise this+0x4 is zeroed and this+0xC stays 0. Returns a2 if null, else the dereferenced a2+12 value. Called by ProfileIconDFTBmpDefaultIconLoader (0x00478020).
- `0x00499BB0` **SixDwordEqualityOwner** — StructEquality: compares two DWORD-array objects field by field, short-circuiting on the first mismatch. Checks six DWORD fields at offsets 0x0, 0x4, 0x8, 0xC, 0x1C and 0x20 in order; returns TRUE only if all six match. Fields between 0x10-0x18 and above 0x24 are not compared. Called by ShortComputation_9bf0 (0x00499BF0).
- `0x00499DF0` **DwordField68SetterOwner** — SetDwordField0x68: trivial setter storing argument a2 into this+0x68 and returning a2 unchanged. No guards, callees, or globals. Invoked by ConditionalSingleStoreWithIteration (0x0049A1C0).
- `0x00499F70` **ResourceNodeRegistry** — LookupOrCreateResourceNodeAndLink: looks up a named resource via sub_497AD0 with the context at this+0x4. On success allocates a 52-byte node (OperatorNewNhMallocWrapper 0x00587C03), initializes it via sub_499B10, fills slots with caller arguments a2-a5 and the lookup result, optionally overrides slots from the resource's indirect data when a7 is set, then links the node either into a named node's child list (when a9 matches a list node) or into the main list anchored at this+0x8 (next pointers at +36/0x24), incrementing the counter at this+0xC. On lookup failure with a8 set, formats an error message (0x0058815F) and shows a MessageBoxA (titles/strings 0x005CCB18/0x005CCB30, window 0x0059E2A4). Returns the new node or 0.
- `0x0049A190` **ListCleanupWithVTableDestructorOwner** — ListCleanupWithVTableDestructor: repeatedly pops the head node of a linked list stored at this[0], advancing the stored head via sub_499E00 (0x00499E00), and for each node invokes its vtable destructor with argument 1. Runs while the stored head is non-null. Called by sub_495300.
- `0x0049A2C0` **StringCopyForwardingThunk** — ThunkToFUN00566650: __thiscall forwarding thunk to StringCopyWithBufferRealloc (0x00566650). Passes both arguments through unchanged (this as destination, a2 as source string) and returns the callee's result. Invoked by ResourceLookupOrCreate (0x0049A3B0).
- `0x0049A330` **CharToIndexConverter** — CharToIndexConversion: __stdcall helper converting the first character of a string to an index: calls sub_589901 (0x00589901) on the string, computes result = first_char - 65 ('A'); returns -1 when result >= 0x1A (26) (non A-Z), otherwise the 0-based index (A -> 0, Z -> 25). Used by hash/resource lookup paths (callers 0x0049A360, 0x0049A3B0, 0x0049A520).
- `0x0049A460` **StringNormalizeHashLookupOwner** — StringNormalizeLookup_a460: string lookup helper that normalizes the input string via sub_589901 (0x00589901), searches the hash table owned by this (0x0049A360), and returns the stored string pointer through StringPointerAccessor_a2d0 (0x0049A2D0) if found, else null. Callers are UI control handlers.
- `0x0049A5A0` **DualPointerFreeOwner** — DualConditionalFree: destructor-style helper that conditionally frees two pointer fields of this (first this+0xC, then this+0x4), each only when non-NULL, via FreeWrapper_7bcf (0x00587BCF). Returns the result of the last free call that fired, or 0 when neither pointer was set.
- `0x0049AAD0` **WidgetRectBoundsProvider** — WidgetRectBounds: computes a widget's output bounding rectangle into four caller-supplied output pointers. When the 16-bit height this+0x28 or width this+0x2A is not greater than 0, copies the raw dword rectangle at this+0x4/0x8/0xC/0x10 straight through. Otherwise computes pixel-accurate bounds from the 16-bit start coordinates and extents: left = this+0x26, right = this+0x26 + this+0x2A - 1, top = this+0x24, bottom = this+0x24 + this+0x28 - 1. Returns the a4 output pointer.
- `0x0049AB60` **RectangleClipDispatcher** — RectangleClipAndDispatch: clips an input rectangle against a widget's stored 16-bit rectangle at this+0x24..0x2A, then dispatches the result to ShortComputation_16e0 (0x004916E0). When either widget extent (0x28 or 0x2A) is <= 0 the clipping is skipped and the original unclipped bounds are dispatched; otherwise the rectangle is clamped (top/bottom against origin 0x26 and extent 0x2A, left/right against origin 0x24 and extent 0x28) and the clipped rectangle is dispatched.
- `0x0049AFC0` **CleanupCallbackRegisterOwner** — CleanupCallbackRegister: thin wrapper calling EmptyStub_0170 with the global dword_7CE048 (0x007CE048) as its argument and returning the result. The raw source shows only this single call/return; the global's content and the stub's behavior are not established.
- `0x0049AFE0` **ScoringStateBlockResetter** — resetScoringStateBlock: resets five consecutive global data structures by calling sub_49E8F0 (0x0049E8F0) on each (0x7CE0B8, 0x7CE104, 0x7CE150, 0x7CE19C, 0x7CE1E8), then zeroes dword_7CE058 and the 96-byte global block 0x7CE058..0x7CE0B4. Returns 0. Unconditional sequence.
- `0x0049B8D0` **SpeedScalarProvider** — SpeedMultiplier: reads a float from the global-pointered data block dword_7C54E0 at field offset 14752 (0x39A0), scales it by the fixed constant 9.549296585513721 (dbl_59EA38), and returns the product as a double. No arguments or side effects. Caller 0x0049F530.
- `0x0049B900` **SpeedScalarProvider** — SpeedMagnitude: computes the scalar speed magnitude of the object referenced by dword_7C54E0. Reads three float components at offsets 13560/13564/13568 (0x34F8/0x34FC/0x3500, interpreted as velocity), squares and sums them, takes the square root, multiplies by the conversion constant 3.5999999 (flt_5ACAF4, m/s-to-km/h per existing analysis), and returns the result truncated to int. Called by GlobalStateBranchFormat (0x0049D3F0) and UILayoutDispatchWithDataPrep (0x004DB550).
- `0x0049B950` **SpeedScalarProvider** — SpeedMagnitude_b950: sibling of SpeedMagnitude. Reads the same three float velocity components at dword_7C54E0 + 0x34F8/0x34FC/0x3500, squares and sums, takes the square root, multiplies by the conversion constant 2.2369363 (flt_59F128, m/s-to-mph per existing analysis), and returns the result truncated to int. Selected by the calling formatter based on an encoding flag. Same callers as SpeedMagnitude.

## Proposed classes

### DoublyLinkedListWithFlag

Doubly-linked list container with head this+0x18BC, tail this+0x18C0, a secondary pointer this+0x18C4 (possibly a read cursor, inferred), node count this+0x18C8, and an append flag byte this+0x24. Single method appends 16-byte DoublyLinkedListNode records and, when the third argument is non-zero, marks the append flag.

Methods: `0x00496750`

- `this+0x00000024` `byte append_flag` (write, DERIVED)
- `this+0x000018BC` `pointer list_head` (write, DERIVED)
- `this+0x000018C0` `pointer list_tail` (read_write, DERIVED)
- `this+0x000018C4` `pointer secondary_ptr` (write, GUESS)
- `this+0x000018C8` `int node_count` (read_write, DERIVED)

### DoublyLinkedListNode

Doubly-linked list node record: 16-byte layout with a value slot at +0, next at +4, prev at +8 and a byte flag at +12, inferred from the initialization literals of 0x00496750 (the meaning of the byte at +12 is unknown). Only the next pointer at +4 is directly evidenced by the packet (as the old tail's next write); the other members are recorded as prose only.

Methods: 

- `*(this+0x18C0)+0x00000004` `pointer next_ptr` (read_write, GUESS)

### NamedListContainer

Linked-list container whose nodes carry a name string: list head at this+0x4 and traversal cursor at this+0xC; nodes hold a data dword at +0, a next pointer at +4 and a name pointer at +0x34 (defaulting to global byte_5EA438). Single method searches the list by name using sub_588410 as the comparison predicate.

Methods: `0x00497650`

- `this+0x00000004` `pointer list_head` (read, DERIVED)
- `this+0x0000000C` `pointer traversal_cursor` (read_write, DERIVED)

### NamedListNode

Linked-list node record for NamedListContainer: data dword at +0, next link at +4, and name string pointer at +0x34 (fallback global byte_5EA438). Only the name pointer at +0x34 is directly evidenced by the packet; the data/next members are recorded as prose only.

Methods: 

- `*(this+0x4)+0x00000034` `pointer name_ptr` (read, GUESS)

### SpriteBitmapNameProvider

Object exposing a bitmap/sprite descriptor name accessor: descriptor pointer at this+0x18, a guard field at this+0x60 (descriptor+0x48), and a sub-descriptor pointer at this+0x68 (descriptor+0x50) whose name pointer at sub+0x34 is returned (fallback global byte_5EA438).

Methods: `0x00497980`

- `this+0x00000018` `pointer descriptor_ptr` (read, DERIVED)
- `this+0x00000060` `pointer descriptor_guard` (read, DERIVED)
- `this+0x00000068` `pointer sub_descriptor_ptr` (read, DERIVED)
- `*(this+0x68)+0x00000034` `pointer name_ptr` (read, DERIVED)

### ComputationDelegationThunk

Thin __thiscall delegation thunk forwarding its this pointer unchanged to ShortComputation_5b30 and returning void. Provides no field evidence; the delegated callee address is not named by the packet.

Methods: `0x004979B0`


### UiStateFieldOwner

Object with a DWORD state field at this+0x20 that is unconditionally cleared to 0 by a UI visibility-toggle callback path. The field semantics are unknown.

Methods: `0x004979E0`

- `this+0x00000020` `int reset_state_dword` (write, DERIVED)

### DataAndDirtyFlagSetterOwner

Object with a data DWORD at this+0x18A8 and an activation/dirty flag byte at this+0x18EC; the setter stores an argument into the data field and sets the flag to 1 unconditionally. Meaning of the fields is not established.

Methods: `0x00497D00`

- `this+0x000018A8` `int data_dword` (write, DERIVED)
- `this+0x000018EC` `byte dirty_flag` (write, DERIVED)

### ByteFlagSetterOwner

Object with a single-byte flag at this+0x18F5 that a char-returning setter writes from its argument and returns unchanged. Likely a boolean/toggle given the UI/key-binding callers.

Methods: `0x004988C0`

- `this+0x000018F5` `byte flag_byte` (write, DERIVED)

### FloatFieldGetterOwner

Object exposing a float field at this+0xC4 read through a double-returning getter; consumed by a UI scroll-list update path. Field semantics unknown.

Methods: `0x00498940`

- `this+0x000000C4` `float float_field` (read, DERIVED)

### VTableInitConstructorOwner

Object constructed by 0x00498D20: parent constructor (0x0049A930) first, vtable off_5AC9E8 installed at this+0x0, a block of fields initialized via MultiFieldStructInit (0x00498DF0), and a constructor argument stored at this+0x44. Purpose of the stored argument is unknown.

Methods: `0x00498D20`

- `this+0x00000000` `pointer vtable_ptr` (write, DERIVED)
- `this+0x00000044` `int arg_dword` (write, DERIVED)

### ChildLinkedListContainer

Container that appends nodes with child-list linking: node counter this+0x5C, two accumulation arguments this+0x4 and this+0xC fed to MultiRegionOffsetAccumulationWithVTableDispatch (0x004869E0), a list head this+0x4C, and an anchor object this+0xD8 used for the 0x8C traversal (role inferred). Children are linked via 0x8C next pointers and receive back-links at child+0x98 (parent) and child+0x9C.

Methods: `0x00498EB0`

- `this+0x00000004` `pointer accumulation_arg` (read, DERIVED)
- `this+0x0000000C` `pointer accumulation_arg` (read, DERIVED)
- `this+0x0000004C` `pointer list_head` (read_write, DERIVED)
- `this+0x0000005C` `int node_counter` (read_write, DERIVED)
- `this+0x000000D8` `pointer anchor_object` (read, GUESS)
- `*(*(this+0xD8)+0x8C)+0x0000008C` `pointer child_next_ptr` (read_write, GUESS)

### DwordField4CGetterOwner

Object exposing a dword field at this+0x4C through a trivial getter. Read by three unrelated callers (0x004958D0, 0x00495980, 0x00498D90); equal offsets on unrelated this pointers are not proof of identical classes.

Methods: `0x00498F60`

- `this+0x0000004C` `int field_dword` (read, DERIVED)

### ScalarDeletingDestructorOwner

Object whose teardown is a scalar deleting-destructor wrapper: an unconditional list-walking body (DestructorWithListWalk, 0x00499280) plus a flag-gated self-free (FreeWrapper_7bcf, 0x00587BCF when a2 & 1). The list layout inside the body is not evidenced here.

Methods: `0x00499260`


### DataFreeDestructorOwner

Object with a data pointer at this+0x0 and an ownership/state flag byte at this+0x8; the destructor helper releases the data pointer (FreeIfNonNull 0x00499AE0 + block free 0x00587BCF) when the flag is set, and self-frees when the caller flag bit is set.

Methods: `0x004995E0`

- `this+0x00000000` `pointer data_ptr` (read, DERIVED)
- `this+0x00000008` `byte ownership_flag` (read, DERIVED)

### RecursiveDirectoryCleaner

Free procedural helper (no instance fields) that recursively deletes files under a directory using the Win32 FindFirstFileA/FindNextFileA/FindClose enumeration API, clearing read-only attributes before deletion, skipping ".." and the word_5BEB48 entry, recursing into subdirectories, and aborting on the first successful file deletion.

Methods: `0x00499690`


### SmallStructInitOwner

Small struct whose initializer writes literal 3 to the first dword this+0x0, a zero byte at this+0x4, and zeroes four dwords (this+0x8/0xC/0x10/0x14). Role of the literal and the mixed byte/dword layout are unknown.

Methods: `0x00499850`

- `this+0x00000000` `int type_literal` (write, DERIVED)
- `this+0x00000004` `byte byte_field` (write, GUESS)
- `this+0x00000008` `int zero_dword` (write, GUESS)
- `this+0x0000000C` `int zero_dword` (write, GUESS)
- `this+0x00000010` `int zero_dword` (write, GUESS)
- `this+0x00000014` `int zero_dword` (write, GUESS)

### LinkedListIteratorOwner

Linked-list iterator object: container pointer this+0xC, current node this+0x10, extracted value this+0x14, and a traversal temporary this+0x18 through which the container traversal slot (at container+0xC) and the next-candidate node (first dword of *(this+0x18)) are read. The advance method refreshes the container slot and extracts the new node's value via FieldGetter_8e30 (0x00498E30).

Methods: `0x00499870`

- `this+0x0000000C` `pointer container_ptr` (read, DERIVED)
- `this+0x00000010` `pointer current_node` (read_write, DERIVED)
- `this+0x00000014` `pointer extracted_value` (write, DERIVED)
- `this+0x00000018` `pointer traversal_temp` (read, GUESS)
- `*(this+0x18)+0x00000000` `pointer next_candidate` (read, GUESS)
- `*(this+0x18)+0x00000004` `pointer link_field` (read, GUESS)

### LinkedListCursorOwner

Object holding an iterator cursor at this+0x14; the advance method replaces the cursor with the next node pointer read at node+72 (0x48) and returns whether a node remains. The node type and the meaning of the +72 next pointer are not established beyond pointer math.

Methods: `0x004998C0`

- `this+0x00000014` `pointer current_node` (read_write, DERIVED)

### StringSlotSetterOwner

Object with a DWORD slot at this+0x8 assigned during string assignment; the string is copied through StringCopyWithBufferRealloc (0x00566650) and the copy result is returned to the caller (SpriteTextureEnumeration). Whether this+0x8 stores the copy or the separate id argument is contradictory in the packet and unresolved.

Methods: `0x00499A30`

- `this+0x00000008` `int slot_dword` (write, DERIVED)

### ZeroFieldConstructorOwner

Object constructed by 0x00499B10: thirteen DWORD fields this+0x0..0x30 initialized to zero except this+0x18 set to float 0.1 (1036831949). Reused as a base/embedded init by four UI-object constructors (0x00477EA0, 0x00478E10, 0x00488180, 0x00499F70).

Methods: `0x00499B10`

- `this+0x00000000` `int init_dword` (write, GUESS)
- `this+0x00000004` `int init_dword` (write, GUESS)
- `this+0x00000008` `int init_dword` (write, GUESS)
- `this+0x0000000C` `int init_dword` (write, GUESS)
- `this+0x00000010` `int init_dword` (write, GUESS)
- `this+0x00000014` `int init_dword` (write, GUESS)
- `this+0x00000018` `float init_float` (write, DERIVED)
- `this+0x0000001C` `int init_dword` (write, GUESS)
- `this+0x00000020` `int init_dword` (write, GUESS)
- `this+0x00000024` `int init_dword` (write, GUESS)
- `this+0x00000028` `int init_dword` (write, GUESS)
- `this+0x0000002C` `int init_dword` (write, GUESS)
- `this+0x00000030` `int init_dword` (write, GUESS)

### IndirectLookupInitOwner

Object whose initializer stores a caller-provided source pointer at this+0x20, zeroes this+0x0 and this+0x8, and copies two values from a two-level indirect read (through a2+12, offsets +28 and +32) into this+0x4 and this+0xC when the source is non-null. The source object's layout is unknown.

Methods: `0x00499B80`

- `this+0x00000020` `pointer source_ptr` (write, DERIVED)
- `this+0x00000000` `int zero_dword` (write, GUESS)
- `this+0x00000008` `int zero_dword` (write, GUESS)
- `this+0x00000004` `int indirect_value_a` (read_write, DERIVED)
- `this+0x0000000C` `int indirect_value_b` (read_write, DERIVED)

### SixDwordEqualityOwner

Object whose equality operation compares six DWORD fields (this+0x0/0x4/0x8/0xC/0x1C/0x20) against a peer and short-circuits on the first mismatch. The skipped regions (0x10-0x18, 0x24+) are deliberately omitted; the object type is unidentified.

Methods: `0x00499BB0`

- `this+0x00000000` `int eq_dword` (read, GUESS)
- `this+0x00000004` `int eq_dword` (read, GUESS)
- `this+0x00000008` `int eq_dword` (read, GUESS)
- `this+0x0000000C` `int eq_dword` (read, GUESS)
- `this+0x0000001C` `int eq_dword` (read, GUESS)
- `this+0x00000020` `int eq_dword` (read, GUESS)

### DwordField68SetterOwner

Object exposing a dword field at this+0x68 through a trivial setter that stores and returns its argument. Field meaning unknown; the structural-twin relation to 0x00464BB0 is a cluster observation, not proof of class identity.

Methods: `0x00499DF0`

- `this+0x00000068` `int field_dword` (write, DERIVED)

### ResourceNodeRegistry

Registry of named resource nodes: lookup context at this+0x4, main list head at this+0x8 (nodes linked by +36/0x24 next pointers), and node counter at this+0xC. The create-or-link method (0x00499F70) allocates and initializes 52-byte ResourceNode records, optionally links them under a matching named node, and reports lookup failures through a formatted message box when the reporting flag is set.

Methods: `0x00499F70`

- `this+0x00000004` `pointer lookup_context` (read, DERIVED)
- `this+0x00000008` `pointer main_list_head` (read_write, DERIVED)
- `this+0x0000000C` `int node_counter` (read_write, DERIVED)
- `*(this+0x8)+0x00000024` `pointer parent_list_next` (read_write, GUESS)
- `*(*(*(this+0x8)+0x24)+0x24)+0x00000024` `pointer parent_list_next` (read, GUESS)

### ResourceNode

52-byte resource record allocated by 0x00499F70 and initialized by sub_499B10. Slots are filled from caller arguments and the lookup result, with an optional indirect-data override; the +36/0x24 next pointer chains the main list and a child-list is reachable through a later slot. Only the +0x24 next pointer is directly evidenced by the packet; slot meanings (0-10, including counters, resource handle, parent/child-list next) are recorded as prose only.

Methods: 

- `*(this+0x8)+0x00000024` `pointer next_ptr` (read_write, GUESS)

### ListCleanupWithVTableDestructorOwner

Object with a list head at this+0x0 whose cleanup method pops each head node (successor via sub_499E00, 0x00499E00) and dispatches the node's vtable destructor with argument 1 until the head is null.

Methods: `0x0049A190`

- `this+0x00000000` `pointer list_head` (read_write, DERIVED)

### StringCopyForwardingThunk

Thin __thiscall forwarding thunk that passes its this pointer and a2 unchanged to StringCopyWithBufferRealloc (0x00566650) and returns the callee's result. Used while resolving/creating resources (caller 0x0049A3B0).

Methods: `0x0049A2C0`


### CharToIndexConverter

Free __stdcall helper converting the first character of a string (via sub_589901 0x00589901) into a 0-based A-Z index (first_char - 65), returning -1 for any character outside A-Z. The 'this' base label is the string argument. Used by hash/resource lookup paths.

Methods: `0x0049A330`

- `this+0x00000000` `byte first_char` (read, DERIVED)

### StringNormalizeHashLookupOwner

Object owning a string hash table (this); the lookup method normalizes the input via sub_589901 (0x00589901), searches the table (0x0049A360), and returns the stored string through StringPointerAccessor_a2d0 (0x0049A2D0) on a hit. Hash-table layout and entry semantics are unknown.

Methods: `0x0049A460`


### DualPointerFreeOwner

Object with two pointer fields (this+0xC and this+0x4) that a helper frees via FreeWrapper_7bcf (0x00587BCF), each only when non-null, returning the last free result. Whether the two offsets are sibling members of one object or separate allocations is unproven.

Methods: `0x0049A5A0`

- `this+0x00000004` `pointer free_ptr` (read, DERIVED)
- `this+0x0000000C` `pointer free_ptr` (read, DERIVED)

### WidgetRectBoundsProvider

Widget object exposing a bounding-rectangle computation: a raw dword rectangle at this+0x4/0x8/0xC/0x10 and a 16-bit layout rectangle at this+0x24 (top start) / this+0x26 (left start) / this+0x28 (height extent) / this+0x2A (width extent). The computed path returns pixel-accurate bounds (right = left + width - 1, bottom = top + height - 1).

Methods: `0x0049AAD0`

- `this+0x00000004` `int raw_rect_dword` (read, GUESS)
- `this+0x00000008` `int raw_rect_dword` (read, GUESS)
- `this+0x0000000C` `int raw_rect_dword` (read, GUESS)
- `this+0x00000010` `int raw_rect_dword` (read, GUESS)
- `this+0x00000024` `short start_top` (read, DERIVED)
- `this+0x00000026` `short start_left` (read, DERIVED)
- `this+0x00000028` `short extent_height` (read, DERIVED)
- `this+0x0000002A` `short extent_width` (read, DERIVED)

### RectangleClipDispatcher

Object whose clip method clamps an input rectangle against the widget 16-bit rectangle at this+0x24..0x2A (origin 0x24/0x26, extents 0x28/0x2A) and dispatches the clipped (or unclipped when an extent is <= 0) result to ShortComputation_16e0 (0x004916E0). Origin-vs-extent and x-vs-y roles are inferred from the clamp arithmetic.

Methods: `0x0049AB60`

- `this+0x00000024` `short origin_edge` (read, GUESS)
- `this+0x00000026` `short origin_edge` (read, GUESS)
- `this+0x00000028` `short extent` (read, GUESS)
- `this+0x0000002A` `short extent` (read, GUESS)

### CleanupCallbackRegisterOwner

Thin wrapper over a single call to EmptyStub_0170 with the global dword_7CE048 (0x007CE048) as its argument; returns the stub result. The global's content, the stub's behavior, and the ABI-name cleanup-callback role are not corroborated by raw source evidence.

Methods: `0x0049AFC0`


### ScoringStateBlockResetter

Procedural reset of five consecutive global data structures (0x7CE0B8, 0x7CE104, 0x7CE150, 0x7CE19C, 0x7CE1E8) via per-struct reset sub_49E8F0 (0x0049E8F0), plus zeroing of dword_7CE058 and the 96-byte block 0x7CE058..0x7CE0B4. Per-member roles of the zeroed block are unnamed.

Methods: `0x0049AFE0`


### SpeedScalarProvider

Reader set over the global data block rooted at dword_7C54E0: velocity components at offsets 0x34F8/0x34FC/0x3500 (squared-summed, square-rooted and scaled by 3.6 or 2.2369363 to yield truncated int speed) and a speed float at offset 0x39A0 scaled by 9.549296585513721. The packet provides no field refs under the *(dword_7C54E0) base, so these offsets are recorded as prose only; the three methods form one cluster because they share the same base pointer and velocity layout.

Methods: `0x0049B8D0`, `0x0049B900`, `0x0049B950`


## Compatibility contracts

- **DoublyLinkedListWithFlagContract** — The doubly-linked list must keep head this+0x18BC, tail this+0x18C0, secondary pointer this+0x18C4 and node count this+0x18C8, with 16-byte nodes (value at +0, next at +4, prev at +8, byte at +12) allocated through the new/malloc wrapper 0x00587C03; an append with a non-zero third argument sets the byte flag this+0x24 to 1, and the function returns that third argument.
- **NamedListSearchContract** — The named-list search walks from head this+0x4 through cursor this+0xC comparing each node's name pointer at node+0x34 (fallback global byte_5EA438) with the target via sub_588410 (0 on match per existing analysis) and returns the matched node's data dword or 0 when the list is empty or exhausted.
- **ResourceNodeRegistryContract** — The resource registry keeps a lookup context at this+0x4, a main list head at this+0x8 with nodes chained by +36 (0x24) next pointers, and a node counter at this+0xC; successful lookups allocate 52-byte nodes through 0x00587C03, initialize them via sub_499B10, and link them into the main list or a matching node's child list; failed lookups with the report flag set format a message (0x0058815F) and show a MessageBoxA.
- **WidgetRectangleLayoutContract** — The widget geometry must keep the 16-bit rectangle at this+0x24..0x2A (top start this+0x24, left start this+0x26, height extent this+0x28, width extent this+0x2A) and a raw dword rectangle at this+0x4/0x8/0xC/0x10; bounds math uses right = left + width - 1 and bottom = top + height - 1, and the raw dword rectangle is emitted when either 16-bit extent is not greater than 0.
- **VelocityMagnitudeConversionContract** — Speed magnitude readers over the dword_7C54E0 data block must read three velocity floats at +0x34F8/0x34FC/0x3500, compute sqrt(x^2+y^2+z^2), and scale by the unit conversion constant (3.6 in flt_5ACAF4 for km/h, 2.2369363 in flt_59F128 for mph) before truncating to int; the speed-float reader at +0x39A0 multiplies by 9.549296585513721 (dbl_59EA38) and returns a double.
- **RecursiveFileDeletionContract** — The recursive deletion must enumerate a directory with FindFirstFileA/FindNextFileA using the search pattern from dword_5C2AB8 appended to the normalized path (backslash word_5C2AAC), clear the read-only attribute (0x0058BA36) before deleting (0x0058986E), skip ".." and the word_5BEB48 entry, recurse into other subdirectories, and abort the whole walk (closing the handle and returning false) on the first successful file deletion.
- **ScalarDeletingDestructorContract** — The deleting-destructor wrapper must run its teardown body unconditionally (DestructorWithListWalk, 0x00499280) and free the object allocation through FreeWrapper_7bcf (0x00587BCF) only when the low bit of the caller flag is set; the data-free variant frees the pointer at this+0x0 (via FreeIfNonNull 0x00499AE0 and block free 0x00587BCF) only when the flag byte at this+0x8 is set, with the object self-free also gated on the caller flag bit.
- **DeletingDestructorContract** — Conditional free helpers must release only non-null pointers (dual-pointer free at this+0xC then this+0x4 via 0x00587BCF) and propagate the last free result; the deleting-destructor family must preserve the a2&1 self-free flag convention shared with the standard MSVC scalar deleting-destructor pattern.
- **StringCopyContract** — String assignment must be routed through StringCopyWithBufferRealloc (0x00566650): the field setter (0x00499A30) stores into this+0x8 and returns the copy, and the forwarding thunk (0x0049A2C0) passes this/a2 through unchanged and returns the callee result.

## Unresolved

- 0x00496750 DoublyLinkedListAppendWithFlag: role of this+0x18C4 (secondary pointer, possibly a read cursor) is inferred from the append pattern; the 16-byte node layout (value, next, prev, byte) and the meaning of the byte at node+12 are inferred from initialization literals only.
- 0x00497650 SearchListItemByName: sub_588410 is assumed to be a string comparison returning 0 on equality from existing analysis; its exact contract is not established by this packet; the node and list-owner object types are unidentified; this+0x10 is packet-listed as read-only but never accessed in the raw source.
- 0x00497980 GetSpriteBitmapName: whether byte_5EA438 is an empty-string placeholder or a sentinel default is unverifiable; the bitmap/sprite descriptor layout and the meaning of the guard field at this+0x60 are not established; the owning object identity is unknown.
- 0x004979B0 delegateToShortComputation5b30: the ABI-name 'polling loop' is not visible in the raw thunk source (any loop would live inside ShortComputation_5b30); the delegated callee address is not named by the packet; the class layout of this is unknown.
- 0x004979E0 clearField20: semantics of the field at this+0x20 are unknown; only that it is cleared to 0; caller UIWidgetVisibilityToggle (0x0048B91A) context not reconstructed.
- 0x00497D00 SetDwordAndFlag: meaning of the two written fields (data 0x18A8, flag 0x18EC) is not established; the flag is set to 1 unconditionally.
- 0x004988C0 setByteField18F5: meaning of the byte flag at this+0x18F5 is unknown (likely boolean/toggle given the UI/key-binding callers); caller contexts not reconstructed.
- 0x00498940 getFloatFieldC4: semantics of the float field at this+0xC4 are unknown; it is read by a UI scroll-list update path but its meaning is not established.
- 0x00498D20 InitWithVTableParam: meaning and purpose of the a2 value stored at this+0x44 are unknown; the fields written by MultiFieldStructInit (0x00498DF0) are outside this function's evidence.
- 0x00498EB0 LinkedListAppendWithChildLinking: field this+0xD8 (anchor object for the 0x8C traversal) is inferred, not literal in the raw source; the child-list fields a2[36]/a2[38]/a2[39] (offsets 0x90/0x98/0x9C) are named only by their back-link pattern.
- 0x00498F60 GetDwordField0x4C: meaning of the field and the owning object type are unknown; three unrelated callers reading the same offset are not proof of identical classes.
- 0x00499260 ConditionalDestructor_9260: DestructorWithListWalk's list layout and element type are not evidenced here; FreeWrapper_7bcf (0x00587BCF) is unconfirmed as the global operator delete.
- 0x004995E0 DestructorWithDataFree: meaning of the flag byte at this+0x8 is unknown; the packet prelabel clusters this with 0x004081E0 as a structural twin but the callee sets differ and class identity is not established; the FreeIfNonNull vs FreeWrapper_7bcf distinction is undocumented.
- 0x00499690 recursiveDeleteFiles: purpose and exact return semantics of sub_59B9F3 (likely removes the now-empty directory) are not evidenced; global asc_5C2AB4 (0x005C2AB4) is adjacent to the pattern pointer dword_5C2AB8 and likely the string it points to, but that linkage is unproven; the extension pattern content is not present in the packet; byte_FF00000000005391/396/39E are decompiler artifacts.
- 0x00499850 SmallStructInit: field this+0x4 is written as a single byte while all other fields are dwords; semantic role of the literal 3 at this+0x0 is unknown.
- 0x00499870 LinkedListIteratorAdvance: container and node layouts are DERIVED from existing analysis, not named by the packet; the role of the traversal temporary at this+0x18 is inferred; FieldGetter_8e30 (0x00498E30) body is outside this packet.
- 0x004998C0 LinkedListNodeTraversal_98c0: the list node type and the meaning of the next pointer at node+72 (0x48) are not established beyond pointer math; this+0x14 is interpreted as the iterator cursor; packet-listed field this+0x5C is not accessed here.
- 0x00499A30 StringFieldSetter: the returned copy pointer is not written back to any field inside this function (its disposition is decided by the caller); the packet is self-contradictory on whether this+0x8 stores the copied string or the separate a3 id - unresolved here.
- 0x00499B10 ObjectConstructorInit: packet lists a read of global dword_5ACAA8 (0x005ACAA8) not visible in the raw decompiled text; why this+0x18 is initialized to float 0.1 (1036831949) instead of zero is unexplained.
- 0x00499B80 ObjectFieldInitWithIndirectLookup: the object behind a2+12 and the meaning of its +28 and +32 fields are unknown; the purpose of the values copied into this+0x4 and this+0xC is not resolvable from this packet.
- 0x00499BB0 StructEquality: meaning of the skipped regions (0x10-0x18, 0x24+) is unknown; equality on six DWORDs does not identify a specific object type; whether the caller relies on the ordering of the checks is unproven.
- 0x00499DF0 SetDwordField0x68: meaning of the field at this+0x68 and the owning object type are unknown; the structural-twin relation to 0x00464BB0 is a cluster observation, not proof of identical classes.
- 0x00499F70 LookupOrCreateResourceNodeAndLink: node slot semantics (slots 4, 6, 8, 9, 10) are inferred from indexing, not a named type; the a7 indirect override depends on the layout of the sub_497AD0 lookup result; whether the a9 child-list structure and the main list at this+0x8 form a hierarchy or two independent lists is unconfirmed.
- 0x0049A190 ListCleanupWithVTableDestructor: v3 (ecx) is not initialized by the decompiler output; the destructor dispatch target and the meaning of its argument 1 are unresolved.
- 0x0049A2C0 ThunkToFUN00566650: the object type behind the this pointer and the exact destination buffer written by StringCopyWithBufferRealloc are unknown; why this thunk exists alongside direct calls is unknown.
- 0x0049A330 CharToIndexConversion: purpose of sub_589901 is unknown (may validate/normalize the string); the A-Z range and index use by callers are inferred from the arithmetic; the 'this' base label is the string argument; the prelabel cluster name ConditionalFreeWithBit0Flag (0x00404F70) does not match the raw semantics and was not adopted.
- 0x0049A460 StringNormalizeLookup_a460: exact normalization performed by sub_589901 (lowercasing/trimming/case folding), the hash-table layout, and the semantics of the strings behind StringPointerAccessor_a2d0 are unknown.
- 0x0049A5A0 DualConditionalFree: owning object type is unknown; whether offsets 0x04 and 0x0C are sibling members of one object or separate allocations is not proven.
- 0x0049AAD0 WidgetRectBounds: the roles of the 16-bit start fields (0x24/0x26) versus extent fields (0x28/0x2A) are consistent with the guard and arithmetic but not independently labelled by the packet; the meaning of the raw dword fallback rectangle (0x4..0x10) is not grounded; the owner class is unidentified.
- 0x0049AB60 RectangleClipAndDispatch: origin-vs-extent and x-vs-y roles of the 16-bit fields are inferred from the clamp arithmetic only (the 0x28/0x2A extent naming may be swapped); the exact meaning of the two input pairs and ShortComputation_16e0's five arguments are unknown from static evidence alone.
- 0x0049AFC0 CleanupCallbackRegister: dword_7CE048 is unnamed and its content unknown; EmptyStub_0170 is named only in the raw source text (absent from the packet callees, so no address or semantic contract); the ABI-name cleanup-callback role is not corroborated by raw source evidence.
- 0x0049AFE0 resetScoringStateBlock: what sub_49E8F0 does per-struct is unestablished; the members of the 0x7CE058..0x7CE0B4 zeroed block are unnamed except dword_7CE058 (the raw source zeroes 24 dwords).
- 0x0049B8D0 SpeedMultiplier: meaning of the float field at offset 0x39A0 and of the scale factor 9.549296585513721 depends on caller context; dword_7C54E0 as the root of the data block is DERIVED only.
- 0x0049B900 / 0x0049B950 SpeedMagnitude: the constant-to-global attribution (flt_5ACAF4 / flt_59F128) and the m/s-to-km/h / m/s-to-mph interpretations are DERIVED; the object type behind dword_7C54E0 is not named by the packet.
- General: no evidence in the packet establishes runtime truth; every class in this proposal is a GUESS grouping over UNKNOWN packet owners, and equal byte offsets on unrelated this pointers are never merged unless a base expression links them.
