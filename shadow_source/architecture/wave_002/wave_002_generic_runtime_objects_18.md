# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Reconstruction of the generic runtime-object helpers in the packet address range 0x00565E00-0x0057F300. The functions group into: (1) a DirectoryIterator that recursively enumerates files/subdirectories over a linked list of entry nodes, builds paths, and advances a cursor; (2) a FileStreamObject carrying a handle at +0x0, a dispatch flag at +0x10, and a stream parameter at +0xC, whose close/read/write/line operations dispatch on that flag to different backends and which also serves as the line-oriented settings parser; (3) a KeyedDataHashTable that normalizes string keys, hashes them into at most nine buckets, and chains audio-related keys into a separate channel chain, and loads audio files into itself; (4) small StringUtils and FileIoUtilities free-function groups; (5) network plumbing: a NetworkEventMatcher, a mutex-protected NetworkReceiveQueue, a NetworkSession start path, and a MutexProtectedPointer accessor. Two functions (0x00565F70 double-indirect getter, 0x00567740 mask-extract) stay ungrouped because their owner objects are not evidenced. All class boundaries and field names are DERIVED or GUESS proposals on top of packet evidence; raw source and validated IR outrank worker synthesis.

## Function roles

- `0x00565EF0` **DirectoryIterator** — Path separator search: locate the last backslash in the iterator's current path string and return the position just after it.
- `0x00565F20` **DirectoryIterator** — Advance the enumeration cursor to the next list node (peek); true while a current node with a non-null data pointer exists.
- `0x00565F50` **DirectoryIterator** — Position the enumeration cursor at the first node; begin file/directory enumeration.
- `0x00565F70` **UnknownObject** — Double-indirect field getter: dereference this, read and return the DWORD at the object's +0xC. Vtable-style accessor used by vehicle, scene and tire-brand loaders; owner object not evidenced.
- `0x00565F80` **DirectoryIterator** — Recursive directory/file enumerator: reset and reentrancy-guarded walk of a path, descending into subdirectories when the flag is set, invoking the per-file visitor for each non-directory entry.
- `0x005662D0` **DirectoryIterator** — Current-path builder: concatenate the entry's base directory and name into the path buffer, optionally normalize against an additional path string; returns the constructed path or 0.
- `0x00566810` **StringUtils** — Case-insensitive substring search over a haystack; returns a pointer to the first matching run or 0. Shared name/token matching helper.
- `0x005668B0` **FileStreamObject** — Initializer for the 25-byte stream struct (zero DWORDs at 0x0/0x4/0xC/0x10/0x14, -1 sentinel at 0x8, zero byte at 0x18); returns the object pointer.
- `0x005668D0` **FileStreamObject** — Cleanup wrapper: delegate to the flag-dispatched handle close, then free the heap object at +0x4 when present; returns the free or close result.
- `0x00566B20` **FileStreamObject** — Open an audio stream on the receiver: close the previous handle, prepare a 1024-byte scratch buffer, open the file, store handle and stream parameter, set initialized/active flags, copy the filename when the handle is valid.
- `0x00566B90` **FileStreamObject** — Conditional file-handle close: when the close-method flag at +0x10 is zero close the handle directly, else close through the type-checked stream dispatch; null the handle on success.
- `0x00566C00` **FileStreamObject** — Backend-dispatch read/write wrapper: forward to the buffered reader when the +0x10 flag is non-zero, otherwise to the thread-safe read wrapper; return the selected backend's result.
- `0x00566C30` **FileStreamObject** — Variadic formatted-write dispatcher: direct locked file write when the mode flag at +0x10 is zero, otherwise format into a local buffer and fill the buffer sink, returning true only when every byte is written.
- `0x00566CC0` **FileStreamObject** — Line-reading dispatch: when the flag at +0x10 is non-zero read through the line-input reader, else read until newline from the raw FILE handle; returns the line buffer.
- `0x00566CF0` **FileStreamObject** — Dual-path dispatcher on the selector at +0x10: string-length dispatch when non-zero, string-write-to-file otherwise; true when the selected path returns something other than -1.
- `0x00567740` **UnknownObject** — Mask-extract of a 16-bit stack value with 0x300 (bits 8 and 9); reads an uninitialized local, likely a decompiler artifact of an FPU control-word read by physics/tire callers.
- `0x00567BB0` **FileStreamObject** — Line-oriented settings parser on a stream object: read lines, trim, recurse on a leading '{', return on '}', split the key at '.', and dispatch each key/value pair to the keyed-data processor with the base directory from +0x4.
- `0x00567F40` **KeyedDataHashTable** — Load an audio file into the receiver's hash table: initialize a local stream struct, open the audio stream, register the stream, load file settings/data, close and clean up; returns whether the load succeeded.
- `0x00567FB0` **KeyedDataHashTable** — Insert a normalized key/value pair into the data hash table: hash the normalized key into bucket 0..8, allocate a 44-byte entry, copy the strings, and chain the entry either into a caller list or into the hash bucket (audio keys into the channel chain).
- `0x00568210` **KeyedDataHashTable** — Name lookup wrapper: forward the receiver and a name string to the hash-table lookup with flag -1 and return its result; legacy ABI label implies an audio-channel stop path but the visible body is only a lookup.
- `0x00568540` **FileIoUtilities** — File-attributes existence/cleanup helper: toggle the read-only attribute (flag 128) then delete the file; true when the delete succeeded.
- `0x00568620` **StringUtils** — Sanitize a string into an output buffer under a size budget, encoding characters that need escaping as '+~XX' hex escapes and copying recognized '+~XX' runs verbatim.
- `0x00568A60` **FileIoUtilities** — Weighted file checksum: open the file, seek to 0, read bytes accumulating a sum of byte times a cycling multiplier, close; returns 1 on success.
- `0x0057A900` **MutexProtectedPointer** — Accessor that reads the DWORD at this+0x0 and delegates it to a mutex-protected pointer read-release helper; placed in the session/network layer by its callers.
- `0x0057B840` **NetworkEventMatcher** — Network event key comparison: dereference the event comparison structure at this+0x1C and test it against a two-component query key using two alternative match patterns; true when either matches.
- `0x0057E940` **NetworkReceiveQueue** — Receive the next network packet from a mutex-protected list: build a query key, wait on the mutex, walk the list testing each node with the event matcher, write the matched node's field to the output, release the mutex.
- `0x0057F2B0` **NetworkSession** — Network session start: query the config sub-object through its vtable, fill a config buffer, obtain a connection object through the main vtable, configure socket parameters, dispatch the mode, and run the session.

## Proposed classes

### DirectoryIterator

Recursive directory/file enumeration: maintains the linked list head pointer, the enumeration cursor, the managed path string, the raw-path/normalize flag and a reentrancy counter; builds and normalizes entry paths.

Methods: `0x00565F80`, `0x00565F50`, `0x005662D0`, `0x00565EF0`, `0x00565F20`

- `this+0x00000000` `void* linked_list_head` (read, DERIVED)
- `obj+0x00000008` `void* current_node` (read_write, DERIVED)
- `obj+0x00000210` `char* path_string` (read, DERIVED)
- `obj+0x00000218` `char raw_path_flag` (read_write, DERIVED)
- `obj+0x0000021C` `int reentrancy_count` (read_write, DERIVED)

### LinkedListNode

Node in the enumeration linked list: a data pointer to the directory entry and a next-node pointer; the cursor lives in the head structure, not the node.

Methods: 

- `*(obj+0x0)+0x00000000` `void* first_node_data` (read, DERIVED)
- `*(obj+0x8)+0x00000000` `void* current_node_data` (read, DERIVED)
- `*(obj+0x8)+0x00000004` `void* next_node` (read, DERIVED)

### DirectoryEntryData

Per-entry data structure reached from the enumeration node's data pointer; holds the base directory string used when building the full path.

Methods: 

- `*(*(obj+0x8)+0x0)+0x00000144` `char* base_directory` (read, DERIVED)

### FileStreamObject

Generic file/stream object reused across camera, scene, text/UI, vehicle, config, audio and damage-model paths: holds a handle at +0x0, a dispatch flag at +0x10 selecting the close/read/write/line backend, a stream parameter at +0xC, and active flags; also parses line-oriented settings into the keyed-data hash table.

Methods: `0x005668B0`, `0x005668D0`, `0x00566B20`, `0x00566B90`, `0x00566C00`, `0x00566C30`, `0x00566CC0`, `0x00566CF0`, `0x00567BB0`

- `this+0x00000000` `void* (FILE*/stream handle) file_handle` (read_write, DERIVED)
- `this+0x00000004` `void* (string buffer, base directory or heap object) string_or_heap_ptr` (read_write, GUESS)
- `this+0x00000008` `int (-1 sentinel set by initializer) type_sentinel` (write, GUESS)
- `this+0x0000000C` `int stream_parameter` (read_write, DERIVED)
- `this+0x00000010` `int (close-method / backend selector) dispatch_flag` (read, DERIVED)
- `this+0x00000014` `int reserved_zero` (write, GUESS)
- `this+0x00000018` `char stream_active_flag` (read_write, DERIVED)

### KeyedDataHashTable

Settings/audio data hash table keyed by normalized strings: registers loaded streams, hashes keys into up to nine buckets, classifies audio-related keys into a separate channel chain, and looks names up. Loads audio files whose settings/data are parsed into itself.

Methods: `0x00567F40`, `0x00567FB0`, `0x00568210`


### StringUtils

Free string-processing helpers: case-insensitive substring search and the sanitize/hex-escape encoder used by settings, path, file-IO and audio-open paths.

Methods: `0x00566810`, `0x00568620`


### FileIoUtilities

Free file-IO helpers: read-only-attribute toggle plus delete, and the weighted file checksum.

Methods: `0x00568540`, `0x00568A60`


### NetworkEventMatcher

Tests a received network event against a two-component query key using two alternative match patterns inside the event comparison structure at this+0x1C.

Methods: `0x0057B840`

- `this+0x0000001C` `void* event_comparison_struct_ptr` (read, DERIVED)
- `this+0x0000001E` `word match_key_low_word_a` (read, DERIVED)
- `this+0x00000020` `dword match_key_dword_a` (read, DERIVED)
- `this+0x0000002E` `word match_key_low_word_b` (read, DERIVED)
- `this+0x00000030` `dword match_key_dword_b` (read, DERIVED)

### NetworkReceiveQueue

Mutex-protected receive queue: guards a packet linked list (head/cursor/tail) with a mutex and timeout, walks the list matching each node's event key, and writes the matched node's field to the caller output.

Methods: `0x0057E940`

- `this+0x00000AC8` `void* list_head` (read, DERIVED)
- `this+0x00000AD0` `void* list_cursor` (read_write, DERIVED)
- `this+0x00000AD4` `void* list_tail` (read, DERIVED)
- `this+0x00000AD8` `HANDLE mutex_handle` (read, DERIVED)
- `this+0x00000ADC` `int mutex_timeout` (read, DERIVED)
- `*(this+0xAC8)+0x00000000` `void* node_data` (read, DERIVED)
- `*(this+0xAD4)+0x00000000` `void* tail_data` (read, DERIVED)

### NetworkSession

Network session start/configuration: resolves a config sub-object, queries and fills a config buffer through its vtable, obtains a connection object through the main vtable, configures socket parameters, and dispatches the session mode.

Methods: `0x0057F2B0`

- `this+0x00000000` `void* (vtable) vtable_ptr` (read, DERIVED)
- `obj+0x00000058` `void* (vtable function) vtable_entry_88` (read, DERIVED)
- `this+0x00000940` `void* (sub-object) config_sub_object` (read, DERIVED)
- `this+0x0000094C` `void* (vtable function) sub_object_vtable_entry_12` (read, DERIVED)
- `*(this+0x940)+0x00000010` `void* (vtable function) sub_object_vtable_entry_16` (read, DERIVED)

### MutexProtectedPointer

Accessor for a pointer value at this+0x0 whose read is delegated to a mutex-protected read-release helper; used by session/network-layer callers.

Methods: `0x0057A900`

- `this+0x00000000` `void* protected_value` (read, DERIVED)

## Compatibility contracts

- **StreamHandleCloseContract** — A stream/file object stores a handle at offset 0x0 and a close-method flag at offset 0x10. Closing must use the direct locked close when the flag is zero, otherwise the type-checked stream dispatch, and must null the handle after a successful close. A replacement must preserve both close paths and the null-after-close invariant.
- **DirectoryEnumerationCursorContract** — Directory enumeration advances a cursor at obj+0x8 over nodes whose data pointer sits at node+0x0 and next pointer at node+0x4. A reentrancy counter at obj+0x21C gates reset/pop, and subdirectory recursion increments then decrements it. A replacement enumerator must reproduce cursor advance, the reentrancy gate, and the per-file visitor call.
- **MutexProtectedPacketQueueContract** — The receive queue guards its packet list (head +0xAC8, cursor +0xAD0, tail +0xAD4) with a mutex at +0xAD8 and timeout at +0xADC. A replacement must acquire/release the mutex around the list walk, match each node's event key, and write the matched node's field at +0x14 into the caller output, returning a match flag.
- **KeyedDataHashTableInsertionContract** — Settings/audio data entries are keyed by a normalized string hashed to a bucket index 0..8 (keys hashing above 8 are rejected). Entries carry a key string and an optional value string, and audio-related keys chain into a separate channel chain. A replacement loader must reproduce the normalization, the bucket limit, and the audio-channel classification.

## Unresolved

- Owner classes for most functions are UnknownObject in the packet; the class grouping here (DirectoryIterator, FileStreamObject, KeyedDataHashTable, etc.) is a DERIVED/GUESS proposal, not recovered source.
- 0x00565F70 double-indirect getter: the object type behind this+0x0 and the meaning of the DWORD at obj+0xC are unknown; the function stays ungrouped.
- 0x00567740 reads an uninitialized stack local and masks it with 0x300; likely a decompiler artifact of an FPU control-word read by physics/tire callers, so it stays ungrouped with semantics LOW.
- FileStreamObject +0x4 has three different evidenced roles (audio filename string buffer, settings base directory, freeable heap object); the single shared field is a proposal and may actually be distinct per subsystem.
- The two close paths of 0x00566B90 and the read/write/line backend selection keyed on +0x10 are inferred from the dispatch structure, not proven by an independent source.
- 0x00566CF0 selector interpretation (string-length lookup versus string-write-to-file) is inferred; whether the value at +0x0 is a string, stream handle or internal buffer is undetermined.
- Which keys classify as audio via 0x00568210 and what the +12 channel chain represents are not established.
- The 44-byte data entry layout (key at dword index 4, value at index 6, chain and back-link fields at indices 3/9/10) and the hash bucket array are not represented as class fields because the packet provides no flat field refs for them.
- Directory entry layout beyond the base directory at +0x144 (e.g. entry name at +0x30) is partially inferred and not evidenced by packet field refs.
- Globals aS_4 (0x005C2C18), aSS_3 (0x005C2D64) and asc_5C2AB4 (0x005C2AB4) are referenced by the recursive enumerator but the association with inline '%s'/'%s\\%s' format literals is unconfirmed.
- Globals byte_FF00000000005396 and byte_FF0000000000539E carry out-of-range addresses and appear to be decompiler artifacts; their role is unknown.
- MutexProtectedPointerReadRelease has no callee address in the packet; whether the delegated read acquires a lock (making 0x0057A900 non-side-effect-free) is unconfirmed.
- The network session's three indirect vtable callees (+12, +16, +88) are unresolved; the socket parameter tuple (0, 10, 1, 2, -1) meaning is unknown.
- The receive-queue query key (family 2, port 0, address 0) as a sockaddr_in bind/match key and the two match patterns of 0x0057B840 (two record layouts versus two variants) are inferred.
- The copy destination this+0xA84 in 0x0057E940 has no packet field ref and is evidenced only through the callee and raw source.
- Whether 0x00565F20 is a pure peek or also consumes nodes is decided by caller semantics and is not settled by this packet.
