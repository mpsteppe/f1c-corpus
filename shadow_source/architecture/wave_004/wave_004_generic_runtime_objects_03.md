# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Reconstructs the generic runtime object layer from twenty-nine validated functions. DERIVED class DynamicObjectBatchContainer (0x00410890) dispatches StateDependentUpdateDispatch over six arrays of 36-byte objects (count/base pairs at +0x24/0x28, +0x30/0x34, +0x3C/0x40, +0x48/0x4C, +0x54/0x58, +0x60/0x64), the last three starting at fixed indices 416/208/832, resetting +0x6C and returning the last count; invoked by DynMan_Restart. DERIVED class MultiFieldPointerResource groups the three structural teardown twins (0x00414380, 0x00415900, 0x00418CF0) that reset a text-format struct, free 5-dword-strided pointer slots in high-to-low sweep order plus the main pointer at +0 via FreeWrapper_7bcf, and optionally self-free the object on a flag bit. DERIVED class TextFormatSlotRecord (0x00414FE0) and DERIVED class SmallEntryStruct (0x00415520) reset (DWORD,DWORD,BYTE) sentinel slot groups, interleaved with StringCopyWithBufferRealloc on the global byte_5EA438 path buffer. GUESS class SinglyLinkedList groups four indexed/flag-reset accessors (0x00415650, 0x00415680, 0x004156C0, 0x00415700) over singly-linked lists whose head/count offsets differ per variant. GUESS class CharacterTableResolver groups the font-rendering support functions (0x00411A00, 0x00411A50, 0x00411B50, 0x00411DB0) around the 9875/9876 special character codes and the two character-to-event tables. GUESS class SoundSystemCleanup (0x00418900) tears down the sound subsystem (vtable queries, drawable cleanup list, audio object at +0xAF4); DERIVED class StateGatedActionDispatcher (0x004189B0) dispatches a vtable action slot only when the state id at +0xAEC matches and the target's gate slot passes. DERIVED class ExpiringSlotArray (0x00418AC0) expires and gap-compacts 20 slots of 32 bytes at +0x864. GUESS class StandingsDataAccessor (0x0041ED20, 0x0041EF40) reads indexed dwords and compares standings entries with a season-match tiebreak; GUESS class ConstructorChampionshipResolver (0x0041F340) finds the highest-scoring constructor over 14 team-name literals; GUESS class TrackNameResolver (0x00420000, 0x004203D0) maps the scene entry name to track message/track ids; GUESS class DirectoryPathResolver (0x00422FD0) prepends a base directory path to a caller string. FileStreamSubobject (0x0040FD70), AllocationReleaseHelper (0x0040FDA0), AudioCommentaryDispatcher (0x00411740), GlobalDwordPairSelector (0x00414180, 0x004141A0) and FontObjectRefCounter (0x00414140) are small GUESS classes.

## Function roles

- `0x0040FD70` **FileStreamSubobject** — FileStreamSubobject destructor helper: overwrites the vtable pointer at this+0 with the global off_59E720 vtable, delegates teardown of a nested subobject located 53 dwords past this (call target absent from the packet), and returns the cleanup destructor's result; invoked by GraphicsResourceDestructor (0x0040FB30) during object destruction.
- `0x0040FDA0` **AllocationReleaseHelper** — AllocationReleaseHelper flag-driven release: optionally backs the pointer to this-4 when flag bit 2 is set, frees via FreeWrapper_7bcf (0x00587BCF) when bit 1 is set, and returns the possibly-adjusted pointer; likely used by graphics resource teardown to release a resource header plus its allocation.
- `0x00410890` **DynamicObjectBatchContainer** — DynamicObjectBatchContainer update dispatch: dispatches StateDependentUpdateDispatch (0x0040F130) over six arrays of 36-byte objects; batches 1-3 start at index 0 (count/base at +0x24/0x28, +0x30/0x34, +0x3C/0x40), batches 4-6 start at fixed indices 416/208/832 (count/base at +0x48/0x4C, +0x54/0x58, +0x60/0x64); resets this+0x6C to 0 and returns the last batch's count (this+0x60); called by DynMan_Restart (0x0042C3B0).
- `0x00411740` **AudioCommentaryDispatcher** — AudioCommentaryDispatcher channel dispatch: when the global object pointer dword_8AC4C4 is non-null, initializes four query outputs (-1,-1,0,0), calls AudioCommentaryChannelConfiguration (0x004117B0); when that returns zero, dispatches vtable slot 76 twice on the object (once per resolved channel v2/v3); reached from sound/exit paths.
- `0x00411A00` **CharacterTableResolver** — CharacterTableResolver table selector: resolves a1 through TableLookupByIndex (0x004144C0); special results 9875/9876 pass through unchanged and negative results are rejected; otherwise returns the indexed WORD from word_5BEBB0 (a2==0) or word_5BF2F8 (a2==1), or -1 for any other a2; called by FontRenderingPrep.
- `0x00411A50` **CharacterTableResolver** — CharacterTableResolver circular-buffer index advance: dispatch over word index a2 into a circular buffer owned by this; values above 0x218 return 0, reserved sentinel indexes (0, 397, 291, 292, 426, 536) return 0/-1 without advancing, otherwise returns CircularBufferIndexIncrement(&this[2*a2]) (0x00411650); a2 is a glyph/font slot index from FontRenderingPrep.
- `0x00411B50` **CharacterTableResolver** — CharacterTableResolver character-to-event mapper: special codes 9875 (variant 397/426 maps to 45/46) and 9876 (variant 1/2 maps to 42/43); otherwise indexes a1 into unk_5BEE08 (a2==0) or unk_5BF4C0 (a2==1); on success copies a path via StringCopyWithBufferRealloc (0x00566650) into byte_5EA438, writes (a1, mapped id) at a3+8/a3+12 and returns 0, else 1; invoked by FontRenderingPrep.
- `0x00411DB0` **CharacterTableResolver** — CharacterTableResolver font-character render dispatcher: code 9875 with a5 in {397,426} renders via sub_412490 (0x00412490) then DecrementCounterWithFloorAtZero; code 9876 with a5 in 1..2 uses EnumValueTranslation (0x00414010) then the same counter decrement; general case resolves a field index via GlobalFieldSelectorByIndex (0x00414160), copies the string at *(a2) (fallback byte_5EA438) via StringCopyWithBufferRealloc, writes code/field-index/zero-flag at a4+8/+12/+16 and returns 1; called by FontRenderingPrep.
- `0x00414140` **FontObjectRefCounter** — FontObjectRefCounter decrement: decrements the int counter at this+8, flooring at 0 (writes value-1 only when the current value is > 0) and returns the possibly-decremented value; used by the font rendering path (FontRenderingPrep, FontCharacterRenderDispatcher), consistent with a reference/outstanding-work counter on a font object.
- `0x00414180` **GlobalDwordPairSelector** — GlobalDwordPairSelector index-based selector over two global DWORDs: returns dword_5BF8CC when a1==0, dword_5BF8D4 when a1==1, and -1 for any other index; no state is modified.
- `0x004141A0` **GlobalDwordPairSelector** — GlobalDwordPairSelector unsigned small-index lookup over a two-entry set of module globals: returns dword_5BF8CC (a1==0), dword_5BF8D4 (a1==1), and -1 for any a1 > 1; callers include DriverNameIDLookup and TrackNameDisplayIDLookup.
- `0x00414380` **MultiFieldPointerResource** — MultiFieldPointerResource full teardown: resets the text-format struct via TextFormatStructInitializer_4d70 (0x00414D70), then four two-iteration countdown loops free eight pointer slots spaced 5 dwords below the anchors this+43/+33/+23/+13 via FreeWrapper_7bcf when non-null, and finally frees the main pointer at this+0 when non-null; shared by GlobalListTripleCleanupWithTimerRemoval (0x00414210) and DrawableResourceCleanup (0x004150C0).
- `0x00414FE0` **TextFormatSlotRecord** — TextFormatSlotRecord initializer: resets a text-format struct by reinitializing the global path buffer byte_5EA438 via StringCopyWithBufferRealloc (0x00566650) between writes, clearing (DWORD,DWORD,BYTE) slot groups at +8..0x10, +0x14..0x1C, +0x28..0x30, +0x3C..0x44 (sentinels -1/-1/0), plus a final slot group after this += 72; returns the last buffer-reinit result; called by 0x00414420, DrawableResourceCleanup, SceneListBuilderFromGlobalArray and 0x00418CF0.
- `0x00415520` **SmallEntryStruct** — SmallEntryStruct initializer of a 20-byte entry struct: clears the DWORD at +0x0, resets +0x4/+0x8/+0xC to -1, clears the byte at +0x10, reinitializes byte_5EA438 via StringCopyWithBufferRealloc, and returns this; used during entry setup by NamedEntryLookupInFormatList, VehicleListBuilderFromGlobalArray and SceneListBuilderFromGlobalArray.
- `0x00415650` **SinglyLinkedList** — SinglyLinkedList indexed accessor (variant A): list object stores the head at this+0 and the count at this+0xC; walks the head a2 times through each node's +4 next pointer and returns the first DWORD of the node at that index, or 0 out-of-bounds; called by SessionStringNameLookup (0x004122C0) and ShortComputation_5730 (0x00415730).
- `0x00415680` **SinglyLinkedList** — SinglyLinkedList indexed accessor (variant B): returns the first DWORD of the node at index a2 in a singly-linked list with head at this+0x10 and count at this+0x1C; returns 0 out-of-bounds or when the list is exhausted; called by TextAttributeLookup callers (0x004133B0, 0x004134D0).
- `0x004156C0` **SinglyLinkedList** — SinglyLinkedList indexed accessor (variant C): returns the first DWORD of the node at 0-based index a2 in a singly-linked list with head this+0x20 and count this+0x2C; bounds-checks a2 and walks node +4 next pointers; index 0 returns the head's first DWORD directly.
- `0x00415700` **SinglyLinkedList** — SinglyLinkedList active-flag reset: iterates the singly-linked list whose head is *this (this[0]), clearing the active-flag byte at node+0xC to 0 for every reachable node, tracking the current node in this+0x8; returns the final traversal pointer; when the head is null the list is empty and the function returns immediately.
- `0x00415900` **MultiFieldPointerResource** — MultiFieldPointerResource full teardown twin of 0x00414380: reinitializes via TextFormatStructInitializer (0x004149A0), four two-iteration countdown loops free 5-dword-strided pointer slots (indices 39/34, 29/24, 19/14, 9/4) via FreeWrapper_7bcf when non-null, frees the main pointer at +0, and self-frees this when flag bit a2&1 is set; returns this; called by 0x00415780.
- `0x00418900` **SoundSystemCleanup** — SoundSystemCleanup sound-exit teardown: runs global vtable dispatch queries with indices 0 and 1 (0x00411740), frees drawable resources from the global cleanup list dword_5EA5E8 via DrawableResourceCleanup (0x004150C0), then releases the audio object stored at this+0xAF4 through its vtable (argument 1) and nulls the pointer; called by Sound_Exit (0x004C8D00).
- `0x004189B0` **StateGatedActionDispatcher** — StateGatedActionDispatcher state-checked virtual dispatch: returns 0 when the state id at this+0xAEC differs from the requested a2, or when the target at this+0xAF4 is null or its vtable gate-check slot (vtable+0x8) returns 0; otherwise invokes the vtable action slot (vtable+0xC) on the target and returns 1; shared by BooleanOROfTwoChecks (0x00418A20) and PitSelectionStateMachine (0x0041B3C0).
- `0x00418AC0` **ExpiringSlotArray** — ExpiringSlotArray expired-slot compaction: maintains a 20-slot array (32 bytes each, stride 8 dwords) at this+0x864 with slot id at dword[0] (-1 = empty) and expiry float at dword[3] (+0xC); phase 1 resets slots whose expiry float is not the -1.0f sentinel and is older than dbl_8AFEA8 via StructInitWithSentinelValues (0x004144D0), recording first-empty and last-non-empty indices; phase 2, when a gap exists, shifts later non-empty slots into the nearest preceding empty slot via StructCopy (0x004145C0) and resets the vacated slot; called by TextOverlayDisplayTimer (0x004186F0).
- `0x00418CF0` **MultiFieldPointerResource** — MultiFieldPointerResource shallow teardown twin: resets the text-format struct via TextFormatStructInitializer_4fe0 (0x00414FE0), runs two two-iteration countdown loops freeing four 5-dword-strided pointer slots below the anchors this+23 and this+13 via FreeWrapper_7bcf when non-null, frees the main pointer at +0, and self-frees this when a2 bit 0 is set; returns this; invoked by SceneListBuilderFromGlobalArray (0x00415C40).
- `0x0041ED20` **StandingsDataAccessor** — StandingsDataAccessor fastcall getter: returns the dword at a1 + 4*a2 + 216 (indexed field read with fixed base offset 216), or 0 when a1 is null; callers cluster around scoring and championship aggregation.
- `0x0041EF40` **StandingsDataAccessor** — StandingsDataAccessor two-entry comparator: null a1/a2 return the other entry; reads the primary sort key at offset 0x19C of each entry and returns the smaller-key entry when they differ; on equal keys iterates positions 1..dword_5C329C comparing CountMatchingSeasonEntries (0x0041EFE0), returning the entry with the greater per-position count, a1 on a full tie, or 0 when the bound is below 1; invoked by SeasonDisplayIDResolver (0x0041DAF0).
- `0x0041F340` **ConstructorChampionshipResolver** — ConstructorChampionshipResolver highest-scoring constructor: allocates an 8-byte [name, score] object via OperatorNewNhMallocWrapper (0x00587C03) (name=0, score=-1), loops the 14 constructor team-name literals through StringCopyWithBufferRealloc, scores each with ChampionshipPointsAccumulator (0x0041F220); a candidate beats the best when its score is higher and (if a1 non-null) passes the sub_566810 (0x00566810) filter; when a2 is non-zero returns the [name, score] object immediately, otherwise a second 14-team pass returns 0 when any team ties the best score, else the object.
- `0x00420000` **TrackNameResolver** — TrackNameResolver track-name to message-id mapper: computes the current scene entry as dword_8AC490 + 396 * dword_8AC48C; when the entry exists, compares the name string at entry offset 260 against 17 track-name literals via sub_566810 (0x00566810), returning the matching message id (338..354), or -1 when no track matches.
- `0x004203D0` **TrackNameResolver** — TrackNameResolver track-name to track-id mapper: computes the element base v3 = dword_8AC490 + 396 * dword_8AC48C and reads the name field at v3 + 260; performs a linear chain of string equality tests against 18 track-name literals via sub_566810, returning the associated track id (355-372, non-monotonic order) on the first match or -1 otherwise; called by 0x0041C4C0.
- `0x00422FD0` **DirectoryPathResolver** — DirectoryPathResolver base-path composition: prepends the base directory path from this[32] (offset 0x80), falling back to the global default path byte_5EA438 when null, to the caller-supplied string a2; returns 0 when a2 is null or when sub_588410 (0x00588410) reports the resolved base equals the default global; otherwise copies a2 into a 1024-byte local buffer, formats base + original into a2 via StringFormatWithBufferOverflowCheck (0x0058815F) using the %s%s literal global aSS (0x005BE860), and returns 1; called by FileLoadWithRetryLoop.

## Proposed classes

### FileStreamSubobject

Subobject whose first dword holds a vtable pointer (written to the global off_59E720 vtable during destruction) and which embeds a nested subobject 53 dwords in, torn down through a multi-field cleanup destructor; invoked as part of graphics resource destruction.

Methods: `0x0040FD70`

- `this+0x00000000` `void* vtable_ptr` (read_write, GUESS)

### AllocationReleaseHelper

Flag-driven release helper: backs a pointer to its allocation header (this-4) when flag bit 2 is set and frees through the shared free wrapper when flag bit 1 is set, returning the possibly-adjusted pointer; used by graphics resource teardown.

Methods: `0x0040FDA0`


### DynamicObjectBatchContainer

Container of six arrays of 36-byte dynamic objects with count/base pointer pairs, three of which hold objects only from a fixed start index (416/208/832); a per-frame or per-restart update dispatches StateDependentUpdateDispatch over each populated batch and resets a counter; invoked by DynMan_Restart.

Methods: `0x00410890`

- `this+0x00000024` `dword batch1_entry_count` (read, DERIVED)
- `this+0x00000028` `void* batch1_base_ptr` (read, DERIVED)
- `this+0x00000030` `dword batch2_entry_count` (read, DERIVED)
- `this+0x00000034` `void* batch2_base_ptr` (read, DERIVED)
- `this+0x0000003C` `dword batch3_entry_count` (read, DERIVED)
- `this+0x00000040` `void* batch3_base_ptr` (read, DERIVED)
- `this+0x00000048` `dword batch4_entry_count_start416` (read, DERIVED)
- `this+0x0000004C` `void* batch4_base_ptr` (read, DERIVED)
- `this+0x00000054` `dword batch5_entry_count_start208` (read, DERIVED)
- `this+0x00000058` `void* batch5_base_ptr` (read, DERIVED)
- `this+0x00000060` `dword batch6_entry_count_start832` (read, DERIVED)
- `this+0x00000064` `void* batch6_base_ptr` (read, DERIVED)
- `this+0x0000006C` `dword reset_counter` (write, GUESS)

### AudioCommentaryDispatcher

Global (dword_8AC4C4) audio-commentary object dispatch: resolves two channel identifiers through AudioCommentaryChannelConfiguration and, when the query reports them unhandled, dispatches vtable slot 76 once per resolved channel; reached from the sound subsystem and exit paths.

Methods: `0x00411740`


### CharacterTableResolver

Font-rendering support family feeding FontRenderingPrep: table-based selection between two character/word tables, circular-buffer index advancement with reserved sentinel indexes, character-code to event-id mapping with special codes 9875/9876, and the font-character render dispatcher that routes special codes to dedicated rendering/translation paths and general codes through a field-indexed string copy.

Methods: `0x00411A00`, `0x00411A50`, `0x00411B50`, `0x00411DB0`


### FontObjectRefCounter

Object with an int counter at +8 that is decremented with a floor at zero by the font rendering path; consistent with a reference count or outstanding-work counter on a font object.

Methods: `0x00414140`

- `this+0x00000008` `int counter` (read_write, GUESS)

### GlobalDwordPairSelector

Index selector over the two adjacent module globals dword_5BF8CC / dword_5BF8D4 (near 0x005BF8C8): returns one of the two values for index 0/1 and -1 otherwise; context-dependent display/name lookup helper.

Methods: `0x00414180`, `0x004141A0`


### MultiFieldPointerResource

Resource object holding a main pointer at +0 plus pointer fields spaced 5 dwords apart in a repeating sub-structure; teardown resets the embedded text-format struct via a TextFormatStructInitializer variant, frees the pointer slots in high-to-low sweep order and the main pointer through the shared free wrapper, and optionally frees the object itself when the caller's flag bit is set. Three structural twins (0x00414380, 0x00415900, 0x00418CF0) differ in the initializer called and in the number of sweep groups.

Methods: `0x00414380`, `0x00415900`, `0x00418CF0`

- `this+0x00000000` `void* main_pointer` (read_write, DERIVED)

### TextFormatSlotRecord

Text-format record of (DWORD, DWORD, BYTE) slot groups initialized to sentinel values (-1, -1, 0); its initializer reinitializes the global path-string buffer byte_5EA438 at every slot boundary and clears groups at +8..0x10, +0x14..0x1C, +0x28..0x30, +0x3C..0x44 plus a final group reached after advancing the record by 72 bytes.

Methods: `0x00414FE0`

- `this+0x00000008` `dword slot0_dword_a` (write, GUESS)
- `this+0x0000000C` `dword slot0_dword_b` (write, GUESS)
- `this+0x00000010` `byte slot0_flag_byte` (write, GUESS)
- `this+0x00000014` `dword slot1_dword_a` (write, GUESS)
- `this+0x00000018` `dword slot1_dword_b` (write, GUESS)
- `this+0x0000001C` `byte slot1_flag_byte` (write, GUESS)
- `this+0x00000028` `dword slot2_dword_a` (write, GUESS)
- `this+0x0000002C` `dword slot2_dword_b` (write, GUESS)
- `this+0x00000030` `byte slot2_flag_byte` (write, GUESS)
- `this+0x0000003C` `dword slot3_dword_a` (write, GUESS)
- `this+0x00000040` `dword slot3_dword_b` (write, GUESS)
- `this+0x00000044` `byte slot3_flag_byte` (write, GUESS)

### SmallEntryStruct

20-byte entry struct initialized to the empty state: link/field dword at +0 cleared, three dwords at +4/+8/+0xC reset to -1, flag byte at +0x10 cleared, with the global path buffer byte_5EA438 reinitialized during setup; used when building named/vehicle/scene entries.

Methods: `0x00415520`

- `this+0x00000000` `dword link_field` (write, GUESS)
- `this+0x00000004` `dword entry_id` (write, GUESS)
- `this+0x00000008` `dword entry_dword_b` (write, GUESS)
- `this+0x0000000C` `dword entry_dword_c` (write, GUESS)
- `this+0x00000010` `byte flag_byte` (write, GUESS)

### SinglyLinkedList

Singly-linked list container with head and entry-count fields and nodes whose first dword is a payload and whose +4 field is the next pointer; provides indexed reads (return the first dword of the nth node) and an active-flag reset that clears a byte at node+0xC across every reachable node. The three indexed-accessor variants use different header offsets (head/count at +0/+0xC, +0x10/+0x1C and +0x20/+0x2C), so this GUESS class groups structurally related list containers without asserting a single header layout.

Methods: `0x00415650`, `0x00415680`, `0x004156C0`, `0x00415700`

- `this+0x00000000` `void* head_ptr_variant_a` (read, GUESS)
- `this+0x00000008` `void* traversal_ptr` (read_write, GUESS)
- `this+0x0000000C` `dword entry_count_variant_a` (read, GUESS)
- `obj+0x00000004` `void* node_next_ptr` (read, GUESS)
- `obj+0x00000008` `dword node_field_b` (unknown, UNKNOWN)
- `*(obj+0x0)+0x00000000` `void* head_deref_first_ptr` (read, GUESS)
- `*(*(obj+0x0)+0x0)+0x00000000` `void* node_next_link` (read, GUESS)
- `*(*(obj+0x0)+0x0)+0x0000000C` `byte node_active_flag` (read_write, GUESS)

### SoundSystemCleanup

Sound-exit teardown: runs the global audio-commentary vtable queries for indices 0 and 1, frees drawable resources from the global cleanup list dword_5EA5E8 via DrawableResourceCleanup, then releases the audio object stored at +0xAF4 through its vtable and nulls the slot; invoked by Sound_Exit.

Methods: `0x00418900`

- `this+0x00000AF4` `void* audio_object` (read_write, GUESS)

### StateGatedActionDispatcher

State-machine infrastructure helper holding a current state id at +0xAEC and a vtable-equipped dispatch target at +0xAF4; invokes the target's vtable action slot (vtable+0xC) only when the state id matches the requested state and the target's gate slot (vtable+0x8) passes; used by BooleanOROfTwoChecks and PitSelectionStateMachine.

Methods: `0x004189B0`

- `this+0x00000AEC` `dword current_state_id` (read, GUESS)
- `this+0x00000AF4` `void* dispatch_target` (read, GUESS)
- `*(this+0xAF4)+0x00000000` `void* target_vtable_ptr` (read, GUESS)
- `*(this+0xAF4)+0x00000008` `void* gate_slot` (read, GUESS)
- `*(this+0xAF4)+0x0000000C` `void* action_slot` (read, GUESS)

### ExpiringSlotArray

Array of 20 slots (32 bytes each) anchored at +0x864 with a per-slot id dword (dword[0], -1 = empty) and an expiry float (dword[3]); expired slots are reset to their empty state and later non-empty slots are compacted into the earliest gap; called by TextOverlayDisplayTimer.

Methods: `0x00418AC0`

- `this+0x00000864` `dword slot0_id` (read, DERIVED)
- `this+0x00000870` `float slot0_expiry_float` (read, DERIVED)
- `this+0x00000884` `dword slot1_id` (read, DERIVED)

### StandingsDataAccessor

Standings/championship data helper: fastcall indexed dword getter (base offset 216) and a two-entry comparator that orders entries by the sort key at +0x19C with a per-position season-match-count tiebreak bounded by dword_5C329C; callers cluster around scoring and championship aggregation (SeasonDisplayIDResolver).

Methods: `0x0041ED20`, `0x0041EF40`

- `this+0x0000019C` `dword primary_sort_key` (read, GUESS)

### ConstructorChampionshipResolver

Resolves the constructor team with the highest championship-points score over the 14 hardcoded team-name literals, using the global byte_5EA438 buffer as the name staging area and StringCopyWithBufferRealloc for name management; returns an 8-byte [name, score] object, or null when a second pass detects a tied best score (tie-check suppressed when the caller's a2 is non-zero).

Methods: `0x0041F340`


### TrackNameResolver

Maps the current track/scene name to track-specific message ids (338..354) and track ids (355..372) by resolving the current scene entry (dword_8AC490 + 396 * dword_8AC48C, name at entry+260) and comparing the name against the 17-18 hardcoded track-name literals via the string-equality helper sub_566810.

Methods: `0x00420000`, `0x004203D0`


### DirectoryPathResolver

Composes a caller-supplied file path string with a base directory path read from +0x80 (falling back to the global default path byte_5EA438), skipping composition when the base is null or equals the default, and formatting the joined path with the %s%s format literal (global aSS at 0x005BE860) through the overflow-checked format helper; used by file-load retry paths.

Methods: `0x00422FD0`

- `this+0x00000080` `char* base_directory` (read, GUESS)

## Compatibility contracts

- **MultiFieldPointerResourceTeardownOrder** — A replacement must reset the embedded text-format struct before freeing, then free the pointer slots in high-to-low sweep order (5-dword stride groups from dword anchors 44/34/24/14, or 23/13 for the shallow twin), free the main pointer at +0 only when non-null, and free the object itself only when the caller's flag bit is set.
- **FlaggedFreeHelperContract** — The release helper must step the pointer back to this-4 when flag bit 2 is set, release the (adjusted) pointer through the shared free wrapper when flag bit 1 is set, and return the pointer that was freed.
- **FontCharacterSpecialCodeContract** — Character codes 9875 and 9876 with variant selectors {397,426} and {1,2} must be routed to the dedicated rendering/translation paths; circular-buffer indexes 0, 397, 291, 292, 426 and 536 must be treated as reserved (return 0/-1 without advancing) and indexes above 0x218 must return 0.
- **TrackSceneEntryLayout** — The track/scene table is indexed as dword_8AC490 + 396 * dword_8AC48C with the track name string at entry offset 260; the track message-id lookup (338..354) and track-id lookup (355..372) must preserve this stride and offset and the fixed literal order.
- **StandingsComparatorTiebreak** — The two-entry comparator returns the smaller primary-key entry when keys at +0x19C differ; on a tie it must compare per-position season match counts (CountMatchingSeasonEntries) through the dword_5C329C bound and return the entry with the greater count, falling back to a1 on a full tie.

## Unresolved

- 0x0040FD70: the multi-field cleanup destructor call target is absent from the packet's callee list, so the nested subobject at 53 dwords past this cannot be named; off_59E720 is only DERIVED as a file-stream vtable, the exact object type is unrecoverable from this packet.
- 0x0040FDA0: meaning of flag bits beyond bit1=free and bit2=header-backstep is unknown; ownership of the freed object and the header layout at this-4 are unknown.
- 0x00410890: the per-batch 36-byte object type and the reason batches 4-6 use fixed start indices (416/208/832) are not established; batch-1 and batch-6 count guards exist in raw source but are not indexed in the packet guards array.
- 0x00411740: semantics of the four query outputs (v5/v4 used only to satisfy the call signature) and of the repeated vtable slot 76 are unknown; the caller argument a1 and the meaning of dword_8AC4C4 are unknown.
- 0x00411A00: meanings of the 9875/9876 pass-through sentinels and of the two WORD tables (word_5BEBB0/word_5BF2F8) depend on the caller FontRenderingPrep, not analyzed in this packet.
- 0x00411A50: exact semantics of the sentinel indexes (reserved glyphs vs invalid slots) and the buffer element size/stride at this[2*a2] are not evidenced.
- 0x00411B50: purpose of the lookup tables unk_5BEE08/unk_5BF4C0 (fill names SoundBankIndexMap and Setup_OptionTable_5BF4C0 are DERIVED only) and of the byte_5EA438 path buffer; variant-selector meanings are unknown.
- 0x00411DB0: the a2 (+8/+0) and a3 (+20) offsets describe the font character state block and its parent data but have no packet field evidence refs; the a4 output buffer layout (+8/+12/+16) is not evidenced.
- 0x00414140: the counter at +8 is not named and its exact purpose (refcount vs pending-work) is not evidenced; owner object type UNKNOWN.
- 0x00414180/0x004141A0: meanings of dword_5BF8CC/dword_5BF8D4 and the selector index are unknown; the 8-byte spacing between them (0x5BF8CC vs 0x5BF8D4) is unexplained; the packet global list names 0x005BF8C8 (read) while raw source reads 0x5BF8CC/0x5BF8D4, so the exact table base is unconfirmed.
- 0x00414380/0x00415900/0x00418CF0: identity of the freed pointer fields is not established (loop slot offsets are dword-slot displacements, not verified byte field offsets); the three twins call different text-format initializers (0x00414D70, 0x004149A0, 0x00414FE0) and differ in sweep-group count, so a shared class is a structural proposal, not proven common ownership.
- 0x00414FE0: the final slot group written after this += 72 lies beyond the packet field list (ends at 0x44) and has no packet field evidence; raw writes to +0x14/0x18/0x1C and +0x28/0x2C/0x30 differ from the extraction's (DWORD,DWORD,BYTE) triple reading.
- 0x00415520: the purpose of the -1-initialized dwords (+0x4/+0x8/+0xC) and the byte at +0x10 is not evidenced beyond reset-on-init; why byte_5EA438 is reinitialized during entry init is not evidenced.
- 0x00415650/0x00415680/0x004156C0/0x00415700: the three indexed accessors use different container header offsets (head/count at +0/+0xC, +0x10/+0x1C, +0x20/+0x2C) and are grouped into one GUESS class without asserting a single layout; node layout (payload at node+0, next at node+4) is inferred, and the packet-listed node+8 and container fields this+0x10/0x14/0x18/0x1C/0x20/0x24/0x28/0x2C are not read by the respective bodies.
- 0x00418900: semantics of the two global vtable dispatch queries (indices 0 and 1), the release-call argument 1, and the class identity of the audio object at +0xAF4 are unknown.
- 0x004189B0: the owner classes of the state object (this) and the dispatch target are unknown; the state id at +0xAEC is a gating check, not a full transition machine, so the state_machines entry is a GUESS with empty transitions; the +0xAEC/+0xAF4 offsets are on a different this base than 0x00418900's +0xAF4, so common ownership with SoundSystemCleanup is not asserted.
- 0x00418AC0: dbl_8AFEA8 (fill name InputAxisDeadZone, DERIVED) is compared against slot expiry floats, implying a current-time value; the slot struct type and owning class are not confirmed; the compaction loop starts at index 1, so slot 0 may be reserved/non-movable.
- 0x0041ED20: owner struct type is unknown; the indexed dword field at base offset 216 has no allowed field evidence ref in the packet.
- 0x0041EF40: winner-direction of the primary-key test is unusual (a1/smaller-key wins when a2's key is larger, while the tiebreak returns a1 when its own count is larger); the 'return 0 after ++v7' path appears unreachable because the v7==dword_5C329C break precedes it; meaning of the 0x19C key and per-position counts depends on the standings model owned by SeasonDisplayIDResolver.
- 0x0041F340: StringCopyWithBufferRealloc destination semantics are unconfirmed (the raw source never writes *v10 yet the second pass reads it); the raw source shows no call site for FreeWrapper_7bcf although the packet lists it as a callee; sub_566810 return semantics and a1's filter role are not grounded; byte_5EA438's fixed size and ownership are unknown.
- 0x00420000/0x004203D0: consumers and meaning of track message ids 338..354 and track ids 355..372 are unknown here; the 396-byte scene-entry stride and the name field at offset 260 are inferred from raw arithmetic, not independent struct evidence; the id sequence is non-monotonic (365 before 364, 372 before 369), likely reflecting internal track ordering.
- 0x00422FD0: parameter a3 is present in the prototype but unused by the body; the pairing of the format call with the aSS (0x005BE860) %s%s literal is DERIVED; whether the 1024-byte copy preserves a caller contract or guards a fixed-size a2 constraint is not stated.
