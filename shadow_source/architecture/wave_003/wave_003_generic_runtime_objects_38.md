# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

The packet covers 28 functions forming the game's generic runtime-object layer: a linked-list merge sorter (0x00566380) over head/tail/cursor fields, string-keyed linked-list and hash-bucket list containers (0x005679C0, 0x00567A00, 0x00567A30, 0x00567E10, 0x00568220) with a name-based hash lookup (0x00567DB0) and a modulo-9 string hash helper (0x00567D00), a family of dual-path stream/file read dispatchers sharing the handle at this+0x0 and a mode flag at this+0x10 (0x00566BD0, 0x00566D30, 0x00566D70, 0x00566DB0, 0x00566E20), a file-or-comm-port open helper (0x00566940) assembling mode strings from byte tables, file copy (0x00568B00) and model-error log writing (0x0056D8F0), a QPC-backed high-resolution timer trio (0x00568BE0, 0x00568C60, 0x00568D90), data-entry-path access (0x00567970), string prefix/character validation (0x005685B0, 0x00568750), generic struct zero-init helpers (0x00567900, 0x00568BA0), and thin wrappers (0x005679A0, 0x005681F0, 0x00579FC0, 0x00567780). Ownership is largely UNKNOWN; class grouping rests on overlapping field evidence, and every grouping is a DERIVED/GUESS proposal, not a claim about original source organization.

## Function roles

- `0x00566380` **LinkedObjectList** — In-place merge sort of a singly linked list: stores sort mode at obj+0x220, counts nodes, splits in half, recursively sorts each half via sub_5664A0, merges with sub_565BB0 as comparator, rebuilds head/tail/cursor.
- `0x00566940` **ResourceFileHandle** — Open a file or serial/comm-port handle: stores access mode at this+0x10 and sub-mode at this+0xC, assembles a mode string from byte_5E5164/5E5168/5E516C over dword_5E5170 (optionally text mode), resolves the path from unk_5E5174/5E5178, stores the handle at this+0x0, copies the path into this+0x4 and clears the byte at this+0x18 on success.
- `0x00566BD0` **StreamReadDispatcher** — Two-way read dispatcher: when this+0x10 is non-zero reads via BufferFillWithTimeout(*this, a2, a3); when zero reads via FileReadWrapperWithLock(a2, 1, a3, *this); relays the selected callee's result unchanged.
- `0x00566D30` **StreamReadDispatcher** — Conditional stream read/init dispatch: this+0x10 non-zero selects AudioStreamBufferRead(*this, 0, 0), otherwise sub_587F64(*this, 0, 0); returns the boolean (==0) outcome.
- `0x00566D70` **StreamReadDispatcher** — 2-byte size query dispatch: this+0x10 non-zero reads via AudioStreamBufferRead(*this, 0, 2), zero via sub_587F64(*this, 0, 2); returns true iff the chosen read reports 0.
- `0x00566DB0` **StreamReadDispatcher** — Read-dispatch wrapper: when the flag at this+0x10 is non-zero reads a2 bytes via AudioStreamBufferRead(*this, a2, 0); otherwise sub_587F64(*this, a2, 0), returning -1 on failure and a2 on success.
- `0x00566E20` **StreamReadDispatcher** — Resource query dispatcher: this+0x10 non-zero selects AudioStreamBufferRead(this[0], 0, 1) (callee address absent from packet), zero selects FileSizeQueryWrapper(this[0]); both take the handle at this+0x0.
- `0x00567780` **BitfieldCombineHelper** — 16-bit combination helper: returns a1 | (v2 & 0xFCFF), forcing bits 8 and 9 from a1; v2 is read before any write (uninitialized stack in the decompiled source). Used on tire-model and rigid-body physics paths.
- `0x00567900` **FileDataProcessorContext** — Struct initializer: stores a2 at this+0x0, zeroes this+0x4..0x10, 0x18, 0x24, 0x28, writes sentinels -1 at this+0x14 and this+0x1C, and reads this+0x20 via FieldGetter_79d0(a2) when a2 is non-null (else keeps default -1).
- `0x00567970` **PathAccessor** — thiscall accessor returning the custom data-entry path at this+0x18 when non-null, else the default application-directory path byte_5EA438.
- `0x005679A0` **UtilityDispatchWrapper** — Thunk wrapper (attributes: thunk): forwards (this, a2) unchanged to NullCheckedCallWrapper; no local logic, field access or global access.
- `0x005679C0` **StringKeyedLinkedList** — Searches a string-keyed singly-linked list: walks from the head at this+0x8 via the node next pointer at node+0x4, fetches each node string via StringPointerAccessor, compares with sub_588410, returns the first node whose comparison yields 0, or null when the key is null or the list is exhausted.
- `0x00567A00` **StringHashBucketList** — Struct initializer: memsets the first 0x24 bytes to zero, then zeroes the five trailing dwords at this+0x24, 0x28, 0x2C, 0x30 and 0x34; returns this. Layout matches the bucket-list region also used by LinkedListDestructorWithInnerFree.
- `0x00567A30` **StringHashBucketList** — Resource destructor: runs F_9PointerArrayCleanup(this), walks the singly-linked list starting at this+0x24, frees each node's data pointer (and its sub-pointer) when the per-node flag is set, frees each node, then zeroes the head fields at this+0x24..0x30 and returns 0.
- `0x00567D00` **StringHashingUtility** — Stdcall string-hash helper: returns -1 for a null pointer, 0 for an empty string, otherwise hashes four sampled characters (first, one-sixth, midpoint, last) via sub_589A35 and reduces the weighted sum modulo 9 to a 0..8 bucket index.
- `0x00567DB0` **HashTable** — Name-based hash-table lookup: when the supplied hash is -1 the key is hashed via StringHash; the bucket at that index is the head of a collision chain whose node names (falling back to byte_5EA438 when null) are compared to the key with sub_588410; returns the first matching node or 0.
- `0x00567E10` **StringHashBucketList** — Hash-bucket list insert-or-find: walks the bucket list comparing the key at a2+4 (falling back to byte_5EA438) with sub_588410; on a match returns 0, otherwise allocates a 12-byte entry node (string copied via StringCopyWithBufferRealloc) and a 12-byte wrapper node, appends to the bucket updating head/tail/walk/count/next-id fields, and returns the wrapper.
- `0x005681F0` **UtilityDispatchWrapper** — Conditional dispatch: calls AudioChannelStop(a1); if it returns a non-null pointer, forwards that pointer to DataEntryAccessor (0x00567970) and returns its char* result, otherwise returns 0.
- `0x00568220` **StringHashBucketList** — Get-or-create lookup in a string-keyed bucket list: walks from this+0x24 comparing each entry's string (fallback byte_5EA438) with sub_588410; returns a matched stored index other than -1, otherwise creates a 12-byte entry keyed via StringCopyWithBufferRealloc, assigns the next-id counter value, wraps it and returns the freshly assigned index.
- `0x005685B0` **StringNormalizationUtility** — Prefix-pattern predicate: returns 1 only when the string has length >= 4 and its first four bytes are '+', '~' and two characters accepted by sub_589BC6; default return is 0.
- `0x00568750` **StringNormalizationUtility** — Character-class validator: accepts a character immediately when sub_589C1B accepts it, otherwise dispatches through a switch over a fixed set of printable punctuation characters and returns 1 for any of them, 0 otherwise.
- `0x00568B00` **FileTransferUtility** — File copy: opens the source with the 'rb' mode string 0x005BE828 and the destination against the config-directory path 0x005C2AB0, loops reading up to 2048 bytes via ThreadSafeReadWrapper_803f and writing via FileReadWrapperWithLock until the read returns zero, closes both handles and returns 1 (0 on any open failure).
- `0x00568BA0` **RuntimeObjectHeader** — Zero-init of a 72-byte header block: writes 0 to this[0] and this[2]..this[17] (offsets 0x0 and 0x8..0x44), leaving the single slot at this[1] untouched; returns this. Used by collision, physics, resource and timer setup paths.
- `0x00568BE0` **HighResolutionTimer** — QPC timer initialization: when a2==1 and QueryPerformanceFrequency succeeds, snapshots the QPC counter (low/high at 0x18/0x1C) and the frequency low dword at 0x0, copies the snapshot into the working pair 0x20/0x24, computes the tick-to-time scale double at 0x8 as 4294967296.0/frequency, stores the mode at 0x48 and zeroes accumulators; always returns 0.
- `0x00568C60` **HighResolutionTimer** — QPC timer reset: gated on the frequency base at 0x0 being non-zero; when the mode at 0x48 has bit 0 set, refreshes the QPC snapshot via QueryPerformanceCounter into 0x18/0x1C, copies it into the working pair 0x20/0x24, zeroes six accumulator dwords (0x10/0x14, 0x28/0x2C, 0x30/0x34) and returns the snapshot low dword at 0x18.
- `0x00568D90` **HighResolutionTimer** — Performance-counter difference with scaling: reads a fresh timestamp via QPCTimestampReadWrapper, subtracts two stored 64-bit counter pairs (this+0x18/0x1C and this+0x28/0x2C), and converts the difference to a double using a divisor from this+0x0, the scale double at this+0x8 and the offset double at this+0x10.
- `0x0056D8F0` **ErrorLogWriter** — Model-error log writer: opens the error text log file (sub_587DB0 with the string literals 0x005E5248/0x005E525C), writes the formatted string via StringFormatWithNestedIO (0x005887B1), closes the handle with FileCloseWithLock; returns 0 when the open fails.
- `0x00579FC0` **CallbackRegistration** — Callback-registration wrapper: returns BooleanToIntConversion((int)sub_579FD0), reading the function pointer stored at the global 0x00579FD0. Callback intent is carried only by the canonical/ABI name.

## Proposed classes

### LinkedObjectList

Singly linked list object sorted in place by merge sort; owns head/tail/cursor pointers and a sort-mode field. Called by file/profile/texture scanner objects.

Methods: `0x00566380`

- `obj+0x00000000` `void* head` (read_write, DERIVED)
- `obj+0x00000004` `void* tail` (read_write, DERIVED)
- `obj+0x00000008` `void* cursor` (read_write, GUESS)
- `obj+0x00000220` `int sortMode` (write, GUESS)
- `*(obj+0x0)+0x00000004` `void* next` (read_write, DERIVED)
- `*(obj+0x0)+0x00000008` `int linkOrZeroFlag` (read_write, GUESS)

### ResourceFileHandle

Openable file or serial/comm-port handle: stores the resulting handle, access/sub-mode, a resolved name buffer and an error flag; assembles comm mode strings from global byte tables. Used across config/IO paths.

Methods: `0x00566940`

- `this+0x00000000` `void* handle` (write, DERIVED)
- `this+0x00000004` `char* nameBuffer` (write, GUESS)
- `this+0x0000000C` `int subMode` (read_write, GUESS)
- `this+0x00000010` `int accessMode` (read_write, GUESS)
- `this+0x00000018` `byte errorFlag` (write, GUESS)

### StreamReadDispatcher

Shared read front-end that selects between a buffered/stream read path and a file/fallback read path from the mode flag at this+0x10, always passing the resource at this+0x0. Serves file/stream/network and vehicle callers.

Methods: `0x00566BD0`, `0x00566D30`, `0x00566D70`, `0x00566DB0`, `0x00566E20`

- `this+0x00000000` `void* handle` (read, DERIVED)
- `this+0x00000010` `int modeFlag` (read, DERIVED)

### BitfieldCombineHelper

16-bit bitmask combine helper (a1 | (v2 & 0xFCFF)) invoked from tire-model and rigid-body physics initialization and integration paths; reads an apparently uninitialized stack local.

Methods: `0x00567780`


### FileDataProcessorContext

Struct initialized to an 11-dword layout with zeroed fields, -1 sentinels and a conditionally read value; the only established caller context is FileDataProcessor-style data processing.

Methods: `0x00567900`

- `this+0x00000000` `void* sourcePtr` (write, DERIVED)
- `this+0x00000004` `int zeroField` (write, GUESS)
- `this+0x00000008` `int zeroField` (write, GUESS)
- `this+0x0000000C` `int zeroField` (write, GUESS)
- `this+0x00000010` `int zeroField` (write, GUESS)
- `this+0x00000014` `int sentinelMinusOne` (write, GUESS)
- `this+0x00000018` `int zeroField` (write, GUESS)
- `this+0x0000001C` `int sentinelMinusOne` (write, GUESS)
- `this+0x00000020` `int readValue` (write, GUESS)
- `this+0x00000024` `int zeroField` (write, GUESS)
- `this+0x00000028` `int zeroField` (write, GUESS)

### PathAccessor

Returns the custom data-entry path stored at this+0x18, falling back to the global default application-directory path. Widespread caller base across commentary, settings, results, career and HUD paths.

Methods: `0x00567970`

- `this+0x00000018` `const char* dataEntryPath` (read, DERIVED)

### UtilityDispatchWrapper

Thin dispatch wrappers with no own state: a thunk forwarding (this, a2) to NullCheckedCallWrapper, and a conditional dispatcher that forwards a non-null AudioChannelStop result to DataEntryAccessor.

Methods: `0x005679A0`, `0x005681F0`


### StringKeyedLinkedList

Singly linked list of string-keyed nodes searched by key comparison against node strings fetched through StringPointerAccessor; head pointer at this+0x8.

Methods: `0x005679C0`

- `this+0x00000008` `void* head` (read, DERIVED)
- `this+0x00000010` `void* secondaryListPtr` (read, UNKNOWN)

### StringHashBucketList

String-keyed hash-bucket list container: holds head/tail/walk pointers, a count and a next-id counter at 0x24..0x34; supports get-or-create entry search, insert-or-find, zero-init and a deep destructor that frees node data and nodes.

Methods: `0x00567A00`, `0x00567A30`, `0x00567E10`, `0x00568220`

- `this+0x00000024` `void* bucketHead` (read_write, DERIVED)
- `this+0x00000028` `void* bucketTail` (read_write, DERIVED)
- `this+0x0000002C` `void* walkPtr` (read_write, DERIVED)
- `this+0x00000030` `int count` (read_write, DERIVED)
- `this+0x00000034` `int nextId` (read_write, DERIVED)
- `*(this+0x24)+0x00000000` `void* nodeData` (read, DERIVED)
- `*(this+0x2C)+0x00000008` `int storedIndex` (read, GUESS)

### HashTable

Name-based hash-table lookup over a bucket array: computes or accepts the bucket index, walks the collision chain comparing node names (fallback default string) with a string comparator and returns the first match.

Methods: `0x00567DB0`


### StringHashingUtility

Free stdcall string-hash helper: null yields -1, empty yields 0, otherwise a weighted sum of four sampled characters is reduced modulo 9 to a 0..8 bucket index.

Methods: `0x00567D00`


### StringNormalizationUtility

String-normalization predicates: rejects or accepts a '+~..' prefix pattern with validated characters and validates characters against an alphanumeric/character-class plus a fixed punctuation set.

Methods: `0x005685B0`, `0x00568750`

- `this+0x00000000` `char firstChar` (read, GUESS)
- `this+0x00000001` `char secondChar` (read, GUESS)
- `this+0x00000002` `char thirdChar` (read, GUESS)
- `this+0x00000003` `char fourthChar` (read, GUESS)

### FileTransferUtility

Copies a file from one path to another in 2048-byte chunks through thread-safe read and lock-protected write wrappers, closing both handles afterwards.

Methods: `0x00568B00`


### RuntimeObjectHeader

Generic zero-init helper for a 72-byte header block; zeroes this[0] and this[2]..this[17], leaving the slot at this[1] untouched. Reused by collision, physics, resource and timer setup paths.

Methods: `0x00568BA0`

- `this+0x00000000` `dword headerField0` (write, UNKNOWN)
- `this+0x00000008` `dword headerField2` (write, UNKNOWN)
- `this+0x0000000C` `dword headerField3` (write, UNKNOWN)
- `this+0x00000010` `dword headerField4` (write, UNKNOWN)
- `this+0x00000014` `dword headerField5` (write, UNKNOWN)
- `this+0x00000018` `dword headerField6` (write, UNKNOWN)
- `this+0x0000001C` `dword headerField7` (write, UNKNOWN)
- `this+0x00000020` `dword headerField8` (write, UNKNOWN)
- `this+0x00000024` `dword headerField9` (write, UNKNOWN)
- `this+0x00000028` `dword headerField10` (write, UNKNOWN)
- `this+0x0000002C` `dword headerField11` (write, UNKNOWN)
- `this+0x00000030` `dword headerField12` (write, UNKNOWN)
- `this+0x00000034` `dword headerField13` (write, UNKNOWN)
- `this+0x00000038` `dword headerField14` (write, UNKNOWN)
- `this+0x0000003C` `dword headerField15` (write, UNKNOWN)
- `this+0x00000040` `dword headerField16` (write, UNKNOWN)
- `this+0x00000044` `dword headerField17` (write, UNKNOWN)

### HighResolutionTimer

QPC-backed high-resolution timer: snapshots QueryPerformanceCounter/QueryPerformanceFrequency, tracks a snapshot pair, a working pair and accumulator pairs, computes a tick-to-time scale factor, and supports initialization, reset and scaled-difference reads.

Methods: `0x00568BE0`, `0x00568C60`, `0x00568D90`

- `this+0x00000000` `dword frequencyBase` (read_write, DERIVED)
- `this+0x00000008` `double scaleFactor` (write, GUESS)
- `this+0x00000010` `double offsetDouble` (read, GUESS)
- `this+0x00000014` `dword accumulatorLow` (write, GUESS)
- `this+0x00000018` `dword counterLow` (read_write, DERIVED)
- `this+0x0000001C` `dword counterHigh` (read_write, DERIVED)
- `this+0x00000020` `dword workingLow` (read_write, DERIVED)
- `this+0x00000024` `dword workingHigh` (read_write, DERIVED)
- `this+0x00000028` `dword accPairLow` (read_write, GUESS)
- `this+0x0000002C` `dword accPairHigh` (read_write, GUESS)
- `this+0x00000030` `dword acc2Low` (write, GUESS)
- `this+0x00000034` `dword acc2High` (write, GUESS)
- `this+0x00000048` `int mode` (read_write, GUESS)

### ErrorLogWriter

Opens the model error text log file, writes a formatted string through the nested IO formatter and closes the handle; invoked from the vehicle-physics joint-system loader frame path.

Methods: `0x0056D8F0`


### CallbackRegistration

Registers a cleanup-routine callback by passing the function pointer stored at the global 0x00579FD0 through a boolean-to-int conversion helper. The target routine's behavior is not evidenced.

Methods: `0x00579FC0`


## Compatibility contracts

- **SortedListHeadTailCursorInvariant** — The linked-list object keeps head at +0x0, tail at +0x4 and cursor at +0x8; the merge sort must preserve these and rebuild them after reordering, and must store the caller's sort-mode at +0x220.
- **ListNodeLinkLayout** — Nodes are linked via the next pointer at node+0x4 and the split zeroes the link; static extraction also flags node+0x8 as a zeroed init flag, so the node+0x4 vs node+0x8 layout is internally inconsistent and unresolved.
- **DualPathReadDispatch** — A non-zero dword at this+0x10 routes reads to the buffered/stream path, zero routes to the file/fallback path; the resource at this+0x0 is passed as the first argument to both paths and the selected call's result is relayed unchanged.
- **HashKeyFallback** — Null string keys/names and null entry string pointers fall back to the global default string byte_5EA438 before comparison or copy.
- **StringHashBucketRange** — StringHash returns -1 for a null pointer, 0 for an empty string and otherwise a value in 0..8 (weighted sum of four sampled characters reduced modulo 9), constraining the bucket-array size to 9.
- **HashBucketListLayout** — The bucket-list container stores head at +0x24, tail at +0x28, walk pointer at +0x2C, count at +0x30 and the next-id counter at +0x34; entry nodes carry a key string and a stored index/flag.
- **QPCTimerScale** — The tick-to-time scale factor double is 4294967296.0 divided by the frequency base; the timer struct tracks a QPC snapshot pair, a working pair, accumulator pairs and a mode selector at +0x48.
- **FileCopyChunkedTransfer** — File copy opens the source with the 'rb' mode string and the destination against the config-directory path, transfers content in 2048-byte chunks via a thread-safe read and a lock-protected write, then closes both handles.
- **CommModeStringAssembly** — Comm-port open assembles a mode string from byte_5E5164/5E5168/5E516C selected by the mode value over the dword_5E5170 prefix, optionally marking text mode, and stores the open result at this+0x0.
- **NameCharacterPolicy** — Normalized names accept the '+~' prefix only when length is at least 4 and both following characters pass validation, and accept a fixed punctuation set (space, !, #, $, %, &, ', (, ), comma, hyphen, dot, slash, colon, semicolon, =, @, [, backslash, ], ^, _, backtick, {, }, ~).

## Unresolved

- sortList (0x00566380): raw code zeroes the split node's link at node+0x4 and links via node+0x4, but static field extraction classifies node+0x8 as the zeroed flag (init 0) and node+0x4 as read-only; node layout is internally inconsistent.
- Exact comparator semantics of sub_565BB0 (data pointers at node+0x0) and whether the sort order depends on the mode stored at obj+0x220.
- sortList owner object identity is unknown; the caller set (profile/bitmap/texture scanners) is consistent with directory or file-name sorting but is not proven.
- OpenFileOrPortWithMode (0x00566940): semantics of a2 (consumed only by FileAttributeCheckSequence 0x005668F0), contents of the byte_5E5164/5E5168/5E516C mode strings and the dword_5E5170 prefix, exact open behavior of sub_534B00 (comm/port) and sub_587DB0 (file), and contents/meaning of the unk_5E5174/5E5178 path buffers are all unresolved.
- OpenFileOrPortWithMode object layout beyond this[0..4] and +24 is unknown; the name-copy target this+1 (offset 0x4) is not represented in the packet field list.
- StreamReadDispatcher: the dword at this+0x0 is only evidenced as the first argument of both read calls (handle, buffer or object pointer unproven); the constant argument 1 to FileReadWrapperWithLock is uninterpreted; return semantics of the two read backends are unknown.
- sub_587F64 is unidentified; its role as the alternate read/init path is inferred from the parallel call shape and the cluster_twin note pointing at 0x00566BD0.
- The AudioStreamBufferRead call inside ResourceLookupDispatcher (0x00566E20) has no callee evidence reference; its target address is unavailable.
- sub_588410's comparison convention (whether a 0 return means equal) is assumed from decompiler usage but not independently confirmed.
- StringPointerAccessor (0x00499E20) node-side layout is not visible; field:this:0x00000010 in StringKeyedLinkedListSearch is read but never referenced in the body (likely a second list pointer, unconfirmed).
- OrWithMaskedStackLocal (0x00567780): v2 is read uninitialized in the decompiled source; the purpose of forcing bits 8 and 9 from a1 is not established; the canonical label 'EmptyStub_7780' conflicts with the real bitwise operation.
- StructInitWithConditionalDefaultRead (0x00567900): the meaning of the -1 sentinels at 0x14/0x1C, what FieldGetter_79d0 reads from a2, and the semantics of this+0x20 are not determinable from this function alone.
- StructZeroInit_7a00 (0x00567A00): zeroed-field semantics and object type unknown; the trailing five-dword write order is a compiler artifact.
- LinkedListDestructorWithInnerFree (0x00567A30): node next-link and flag offsets come from raw decompiled source only, with no dedicated packet field evidence.
- Hash-bucket list: wrapper node +8 byte set to 1 is likely an owned-data flag (DERIVED only); entry-node vs wrapper-node layout is ambiguous because HashTableEntrySearch reads a stored index at node+8 while HashTableListInsertOrFind writes the index at the entry node.
- Content and role of the fallback global string byte_5EA438 (default application-directory path) are unknown beyond its use as a null-key substitute.
- StructZeroInit_8ba0 (0x00568BA0): the 4-byte slot between this[0] and this[2] (dword index 1, offset 0x4) is not written; its role is unknown.
- QPCTimerInitialization (0x00568BE0): the mapping of the read-only double global 0x005AF448 to 4294967296.0 is DERIVED only; the malformed high import-table artifact byte_FF00000000005406 has no identified semantic role.
- PerformanceCounterDiffWithScaling (0x00568D90): the divisor composition is decompiler-artifacted; what the two stored 64-bit counter pairs represent and the owning timer class are unknown.
- ErrorModelLogOpenAndFormatWrite (0x0056D8F0): literal contents of aPmodelErrorTxt, aA and the aS_4 format string are unknown; the error-reporting duty in caller VehiclePhysicsJointSystemLoader (0x0056D930) is not established.
- CallbackRegistrationForCleanupRoutine (0x00579FC0): identity/purpose of sub_579FD0 unknown; the callback-registration intent is carried only by the canonical/ABI name (LEGACY trust).
- ConditionalDispatch_81f0 (0x005681F0): semantics of AudioChannelStop and DataEntryAccessor not determined; why the intermediate pointer is typed DWORD* while the final return is char* is unexplained.
- StringHash (0x00567D00): sub_589A35 is a per-character transform (likely case folding) whose behavior is outside the packet; field:this:0x00000000 is a decompiler artifact of the a1[0] dereference; strlen is an external CRT routine not in the callee table.
- ASCIICharCodeValidation (0x00568750): the character set accepted by sub_589C1B is not visible; the punctuation-set rationale (accepting '#' and '_' but rejecting '*', '"' and '|') is unknown; jump-table globals jpt_568774/byte_56878C are unanalyzed.
- NullCheckedCallWrapper (target of the 0x005679A0 thunk) is not a tracked callee in the packet; its 0-on-null-parameter semantics come only from the legacy ABI name.
- The bucket-array layout behind HashTableLookupByName (how many buckets, stride, ownership) is outside the packet.
