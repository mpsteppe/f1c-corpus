# GenericRuntimeUtilities

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Thirty-six small runtime helpers with largely unknown ownership. The packet supports a handful of defensible shapes: a doubly-linked list owner (head at +0x2C, node next/prev at +0x30/+0x34, unlink at 00560F10); a singly-linked copy-list owner (head/tail/extra/count at +0x0/+0x4/+0x8/+0xC, 332-byte payload + 12-byte node, append at 00565CA0); a managed string buffer (char* at +0x0, capacity at +0x4, insert/shift at 005666B0/005667B0); a session/connection tracker (identifier at +0x4, last-activity ticks at +0xD8, retry byte at +0xE8, timeout handler at 00561ED0); Base64 and cipher primitives (RC4-style 00562150, keystream generator 00564F10, rolling-key XOR 00565140, byte swaps 005622B0/00562605); comparator callbacks over the shared context global 008D46B4 (00563F20, 00564090) and plain dword comparators (00564600, 00564620); file-path lookup with alternating output buffers (00562530); settings-line sanitization (00567B10); vtable-slot accessor (005662CA); two triangular run-length integrity validators (0056F818, 00575882); address-of-global accessor thunks (0056F7F9, 0056F7FF, 0056F805, 00575863, 00575869, 0057586F); and callback/refcount lifecycle wrappers (00579FD0, 0057A000). 00568FA4 is a decompiler-corrupted stub and is left unclassified.

## Function roles

- `0x00560F10` **DoublyLinkedNodeList** — Unlinks a node from the doubly-linked list, patches successor/predecessor link slots, advances the this+0x2C head when the unlinked node was the head, and returns the node or the new head.
- `0x00561D40` **SessionDescriptor** — Allocates a 260-byte descriptor via MallocWrapperForNhMalloc (falling back to global unk_5E4CF8 when the output pointer is null) and populates string slots at +8/+72, scalar slots and flag/zero fields.
- `0x00561ED0` **NetworkSessionTracker** — Connection inactivity timeout handler: guards on identifier at +0x4 (0xFFFFFFFF disables tracking), computes elapsed vs last-activity ticks at +0xD8, runs retry logic on the +0xE8 retry byte, and resets state via sub_562AC0 on expiry.
- `0x00561FF0` **UnknownObject** — Thin __fastcall wrapper forwarding a2, hostshort and a4 to sub_562010 with a hard-coded zero fourth argument and returning 0; incoming a1 is ignored.
- `0x00562090` **Base64Codec** — Encodes a2 bytes from a1 into a null-terminated Base64 string in a3, consuming input in 3-byte groups (zero-padded final group) and mapping indices through Base64IndexToCharEncoding.
- `0x00562150` **StreamCipher** — Keyed byte cipher matching the RC4 structure: 256-entry state table, key-scheduling loop via ByteSwap, then a stream phase XORing each data byte against a table-selected keystream byte; returns the data length.
- `0x005622B0` **ByteSwapHelper** — Two-byte exchange helper: swaps the byte at a1 with the byte at a2 and returns the original a1 byte.
- `0x00562530` **FilePathResolver** — Builds a backslash-terminated search string, toggles the global buffer selector at 0x008CF080, resolves the path via sub_587C20, and extracts the filename (characters after the last backslash) into one of two alternating buffers at unk_8CF088.
- `0x00562605` **ByteSwapHelper** — Exchanges the single bytes stored at two char pointers a1 and a2 and returns the original a1 byte; structural twin of FloatClamp per the packet prelabel.
- `0x00563EB0` **UnknownObject** — Single-step delegation: reads the pointer slot at byte offset 0x4 of this and forwards it as the sole argument to sub_563E70, returning that call's result.
- `0x00563F20` **ContextStringSortCallbacks** — Comparator over two indirect string pointers against the shared context reference string at (dword_8D46B4 + 128) via StringComparisonWithConstantDispatch; negates the result when the direction flag at (dword_8D46B4 + 132) is zero.
- `0x00564090` **ContextStringSortCallbacks** — Comparator callback resolving two indirect handles through sub_5644B0 (context reference string at dword_8D46B4+128, byte_5EA438 buffer), comparing with sub_588410, and negating on the +132 reverse-sort flag.
- `0x00564480` **UnknownObject** — Getter returning the 16-bit field at byte offset 0x6 of this, widened to int; no side effects.
- `0x005645A0` **UnknownObject** — Computes a rolling 32-bit hash over a null-terminated string (folding characters through sub_58B465 with multiplier 1664117991) and returns the hash modulo a caller-supplied divisor.
- `0x00564600` **GenericComparatorCallbacks** — Dereferences both dword operands a1 and a2 and delegates the comparison; the raw source names sub_588410 but the packet excludes it from this function's callee evidence, so the delegate is not statically grounded here.
- `0x00564620` **GenericComparatorCallbacks** — Trivial comparator returning the signed difference *a1 - *a2 of two dereferenced dwords; comparator-shaped for an ordering callback but with no packet callers to confirm the role.
- `0x00564630` **UnknownObject** — Thin free wrapper: forwards the pointer at this+0x0 to the NULL-safe deallocation dispatcher FreeMemoryDispatched (sub_58AA6F); void result.
- `0x00564C40` **Base64Codec** — Maps a 6-bit index in [0,63] to its Base64 ASCII character ('A'-'Z', 'a'-'z', '0'-'9', '+', '/'); index >= 64 maps to 0. Shared by Base64Encode and PadOutputWithSpacesUpToLengthLimit.
- `0x00564F10` **StreamCipher** — PRNG-style keystream generator over four persistent state words in a1 (dword indices 304-307) and byte-indexed tables around dword indices 256/272/288; refills a 16-entry table below counter 0x10000 and emits mixed keystream words.
- `0x00565140` **StreamCipher** — Stream cipher applying a rolling key stream (living at a1 + 309, dword index 325) to XOR a3 bytes of a2; refills 16-dword blocks via sub_564F10 when the pointer is null or consumed offset reaches 0x3F bytes.
- `0x00565CA0` **PayloadCopyList** — Appends a copy of an item to a singly-linked list: allocates a 332-byte payload (owner back-pointer, 0x140-byte item copy, zero/-1 dword pair), wraps it in a 12-byte node (payload, next, valid flag = 1), links at the tail, updates head/tail/count, and returns 0.
- `0x005662CA` **VtableDispatchHelper** — Vtable entry getter: reads the vtable pointer at this+0x0 and returns the dword at vtable offset +0xC (fourth slot).
- `0x005666B0` **ManagedStringBuffer** — Inserts string a3 into a managed buffer (char* at +0x0, capacity at +0x4) at position a2, growing/reallocating the buffer as needed; returns 0 on success, -1 on out-of-range position.
- `0x005667B0` **ManagedStringBuffer** — In-place string range shift: copies the substring from a3 through the terminator leftward by (a3 - a2); returns 0 on success, -1 for null buffer with a shift requested, negative a2, or a3 beyond the string length.
- `0x00567B10` **SettingsStringSanitizer** — String sanitation helper used while parsing settings data: copies a1 into a2, trims leading/trailing characters accepted by CharacterClassCheck, and truncates at the delimiter found via sub_587C20 at unk_5C30B8; returns 1 when non-empty, 0 otherwise.
- `0x00568FA4` **UnknownObject** — Decompiler-corrupted stub (Hex-Rays positive stack value): recovered body writes the low byte of a1 to a2 + a1 and sums global byte_5E5F0000; signature and purpose unknown.
- `0x0056F7F9` **GlobalAnchorAccessors** — Address getter returning the address of the global double dbl_8D3A28 (0x008D3A28).
- `0x0056F7FF` **GlobalAnchorAccessors** — Accessor returning the address of the global double dbl_8CFBF0 (0x008CFBF0).
- `0x0056F805` **GlobalAnchorAccessors** — Accessor returning the address of the global dword dword_8D3988 (0x008D3988).
- `0x0056F818` **IntegrityValidator** — Validates the zero/non-zero run-length pattern of a 40-by-41 triangular double sweep against a hardcoded 84-word pattern table; returns true only when the pattern is fully consumed and the final run length equals 194.
- `0x00575863` **GlobalAnchorAccessors** — Accessor returning the address of the global double dbl_8D3870 (0x008D3870).
- `0x00575869` **GlobalAnchorAccessors** — Accessor returning the address of the global double dbl_8D2120 (0x008D2120) as a double*.
- `0x0057586F` **GlobalAnchorAccessors** — Accessor returning the address of the global dword dword_8D3B68 (0x008D3B68) as an int*.
- `0x00575882` **IntegrityValidator** — Structural twin of DataPatternSequenceValidator: validates the zero/non-zero run-length pattern of a 34-by-35 triangular double sweep against a hardcoded 108-word pattern table; true only when the pattern is fully consumed and the final run length equals 49.
- `0x00579FD0` **CallbackLifecycleHelpers** — Delegation wrapper invoking the named helper RefCountDecrementWithCleanup() with no arguments and returning its integer result; helper target address is not in the packet.
- `0x0057A000` **CallbackLifecycleHelpers** — Thin callback-registration stub: casts the code address of sub_57A010 to int and passes it to BooleanToIntConversion, returning that result; effective behavior is a non-null check of the callback pointer.

## Proposed classes

### DoublyLinkedNodeList

Doubly-linked list owner holding the link head at +0x2C; nodes carry successor at +0x30 and predecessor at +0x34.

Methods: `0x00560F10`

- `this+0x0000002C` `void* linkHead` (read_write, DERIVED)

### PayloadCopyList

Singly-linked list of copied items. Owner holds head (+0x0), tail (+0x4), an extra pointer (+0x8, role DERIVED) and count (+0xC). Each item is a 332-byte payload wrapped in a 12-byte node.

Methods: `0x00565CA0`

- `this+0x00000000` `void* head` (read_write, DERIVED)
- `this+0x00000004` `void* tail` (read_write, DERIVED)
- `this+0x00000008` `void* extraPtr` (read_write, GUESS)
- `this+0x0000000C` `int count` (read_write, DERIVED)

### ManagedStringBuffer

Growable managed string buffer: character buffer at +0x0 with tracked capacity at +0x4; supports position-based insertion and in-place range shifts.

Methods: `0x005666B0`, `0x005667B0`

- `this+0x00000000` `char* buffer` (read_write, DERIVED)
- `this+0x00000004` `int capacity` (read_write, DERIVED)

### NetworkSessionTracker

Tracks connection/session activity and performs time-based retry and reset actions. Identifier at +0x4 (0xFFFFFFFF disables tracking), last-activity tick stamp at +0xD8, retry byte at +0xE8.

Methods: `0x00561ED0`

- `this+0x00000004` `int connectionIdentifier` (read, GUESS)
- `this+0x000000D8` `dword lastActivityTicks` (read, GUESS)
- `this+0x000000E8` `byte retryCounter` (read_write, GUESS)

### SessionDescriptor

260-byte descriptor allocated and populated from construction parameters: two string slots at +8 and +72, scalar dword slots at +0/+4/+200/+204/+208/+212/+228/+256, a flag dword 1 at +220, a byte flag 1 at +232, and zeroed dwords at +216/+224/+252. Global unk_5E4CF8 is the fallback instance.

Methods: `0x00561D40`

- `this+0x00000000` `dword field_0x00` (write, GUESS)
- `this+0x00000004` `dword field_0x04` (write, GUESS)
- `this+0x00000008` `char* nameString` (write, GUESS)
- `this+0x000000D8` `dword zeroed_0xD8` (write, GUESS)
- `this+0x000000E8` `byte enabledFlagByte` (write, GUESS)

### FilePathResolver

Resolves a file path from a backslash-terminated search string via sub_587C20 and extracts the filename into one of two alternating output buffers (unk_8CF088 + 256 * selector, selector toggled at dword_8CF080).

Methods: `0x00562530`


### VtableDispatchHelper

Resolves a vtable entry: reads the vtable pointer at this+0x0 and returns the dword at vtable offset +0xC (fourth slot).

Methods: `0x005662CA`

- `this+0x00000000` `void** vtablePtr` (read, DERIVED)
- `obj+0x0000000C` `dword slotAtPlusC` (read, DERIVED)

### SettingsStringSanitizer

Sanitizes one line of settings data: copies the input, trims characters accepted by CharacterClassCheck, and truncates at the delimiter found via sub_587C20 (unk_5C30B8). Returns 1 when the result is non-empty.

Methods: `0x00567B10`


### IntegrityValidator

Load-time integrity checks of hardcoded double matrices: walks a triangular row-pointer array and validates the zero/non-zero run-length sequence against a hardcoded word pattern table. Two structural twins with different dimensions and tables.

Methods: `0x0056F818`, `0x00575882`

- `this+0x00000000` `double** rowPointerArray` (read, DERIVED)

### CallbackLifecycleHelpers

Callback registration and reference-count lifecycle wrappers: a boolean conversion of a callback code address, and a no-argument delegation to a refcount decrement-with-cleanup helper.

Methods: `0x00579FD0`, `0x0057A000`


## Compatibility contracts

- **DoublyLinkedListUnlinkContract** — Doubly-linked nodes place successor at +0x30 and predecessor at +0x34; the list owner keeps the link head at +0x2C. Unlinking must patch the successor's +0x34 and predecessor's +0x30, advance the head to the node's predecessor when the head pointed at the node, and return the new head in that case.
- **PayloadCopyListContract** — List owner layout: head +0x0, tail +0x4, extra pointer +0x8, count +0xC. Items are 332-byte payloads (owner back-pointer at +0x0, 0x140-byte item copy at +0x4, zero dword at +324, -1 dword at +328) wrapped in 12-byte nodes (payload +0x0, next +0x4, valid flag byte +0x8). Append always returns 0 and skips on null item.
- **ManagedStringBufferContract** — Managed string object holds char* at +0x0 and capacity at +0x4. Insertion at a character position returns 0 on success and -1 when the position is negative or beyond the current length; the buffer grows by max(a4, strlen(insert)) on realloc.
- **NetworkSessionTimeoutContract** — A connection tracker disables timeout tracking when its +0x4 identifier is 0xFFFFFFFF. Activity is measured against the last-activity tick stamp at +0xD8 (valid window 0x493E0 ms; stamp must be non-zero and not in the future). Retry runs via sub_562AC0 when elapsed exceeds 0x7530 ms and the +0xE8 retry byte is above 0; the retry byte increments and is reset once it exceeds 10. Any invalid/expired window also triggers sub_562AC0.
- **Base64AlphabetContract** — Base64 output is produced by mapping each 6-bit index through a fixed alphabet (0-25 to 'A'-'Z', 26-51 to 'a'-'z', 52-61 to '0'-'9', 62 to '+', 63 to '/'). The encoder consumes 3-byte groups, zero-pads a partial final group, writes no '=' padding, and null-terminates the output.
- **RC4StructureContract** — The byte cipher initializes a 256-entry state table to 0..255, mixes the key in a scheduling loop, and XORs data bytes against table-selected keystream bytes in a stream phase, swapping table entries between phases; returns the processed data length.
- **RollingKeyStreamContract** — A stream XOR helper keeps its rolling key pointer at dword index 325 of the owning object and the 16-dword (64-byte) keystream block at a1 + 309 (dword index 309). The block is regenerated via the keystream generator whenever the pointer is null or 0x3F bytes of the block have been consumed, then one byte is XORed per destination byte.
- **TriangularMatrixIntegrityContract** — Two twin validators sweep a triangular array of double rows (40 rows x up to 40 elements with an 84-word pattern and final run 194; and 34 rows x up to 34 elements with a 108-word pattern and final run 49). Each requires element count and run-length sequence to match exactly, and returns false on any mismatch or early pattern exhaustion.
- **FilePathAlternatingBufferContract** — Path resolution keeps two alternating filename buffers at unk_8CF088 with a 256-byte stride selected by dword_8CF080 (toggled ^= 1 per lookup). The resolved filename is the substring after the last backslash of the located path; a failed lookup returns null.

## Unresolved

- Ownership is UNKNOWN for almost every function; class groupings (DoublyLinkedNodeList, PayloadCopyList, ManagedStringBuffer, NetworkSessionTracker, SessionDescriptor, FilePathResolver, VtableDispatchHelper, SettingsStringSanitizer, IntegrityValidator, CallbackLifecycleHelpers) are behavioral-shape proposals, not recovered types.
- Equal byte offsets +0x4 on NetworkSessionTracker (connection identifier int) and SingleDelegationCall (delegated pointer slot) are distinct fields on different bases and are not merged.
- 0x00564600's packet explicitly excludes callee:0x00588410 as evidence even though the raw source names it; the delegate relationship is therefore not statically grounded for that function.
- 0x00563EB0's delegation target sub_563E70 has no evidence reference in the packet.
- 0x00561FF0 ignores its a1 argument; the meaning of the hard-coded zero fourth argument to sub_562010 is unknown.
- SessionDescriptor field semantics are unknown; the two string slots at +8/+72 are presumed names/labels, and the initialization state of the unk_5E4CF8 fallback global is unknown.
- Base64 partial final groups are zero-padded here but no '=' padding characters are emitted; the a3 output-buffer aliasing in the decompiler cannot be fully separated.
- RC4 identification is DERIVED; the stream-phase index advance may be a decompiler artifact, and the a2 <= 0 divide-by-zero path is unevidenced.
- 0x00564F10's byte-mixing arithmetic is not reduced to a named cipher; the object is accessed at dword indices 256..307 yet only offset 0x0 is field-evidenced.
- ListAppendCopy may execute qmemcpy at payload + 4 even when the 332-byte allocation failed (potential null dereference in raw source); the StringCopyWithBufferRealloc side-effect assumption is DERIVED.
- FilePathLookupByString writes a 16-bit word (backslash plus following byte) at the end of the search string; the trailing byte's role and the lifetime of the sub_587C20 result are unverified.
- ManagedStringBuffer's a4 (minimum extra capacity) is caller policy; StringInsertAt/InPlaceStringShift index semantics (a2/a3) are inferred and a2 > a3 is unguarded.
- StringTrimAndTruncate's trailing-trim loop writes through an uninitialized decompiler variable; the delimiter value at unk_5C30B8 and the CharacterClassCheck class are unknown.
- CorruptedMathStub (0x00568FA4) is a decompiler-corrupted stub (positive stack value); its true signature and purpose are unknown and most parameters are unused.
- DataPatternSequenceValidator/Alt: dbl_59E430 is flagged read by packet facts but absent from the raw source; the purpose of the validated matrices and their callers are unknown.
- refCountDecrementWithCleanupWrapper: the helper's target address is not in the packet and unk_8D3BF1 is flagged read but absent from the raw source; the refcount interpretation rests on the raw-source name only.
- CallbackRegistrationStub's callback-registration interpretation rests on the legacy ABI name only; BooleanToIntConversion semantics are taken from its name.
- The prelabel twin relationship to FloatClamp (004646c0) reported for ByteSwap/CharSwap and the cluster grouping of freeReferencedObject with conditionalFreeWithBit0Flag are not reflected in the raw decompiled bodies.
- ContextStringSortCallbacks: identity of dword_8D46B4 (existing analysis labels it NetworkContextPtr [DERIVED]) and the +128/+132 slot semantics are not independently confirmed; no static callers are recorded.
- DoublyLinkedNodeList: node successor/predecessor slots at +0x30/+0x34 are inferred from unlink symmetry and documented in class responsibility prose only; the packet carries no field evidence ref for base 'node', so they are not declared as schema fields.
- PayloadCopyList: the 12-byte node (payload +0x0, next +0x4, valid flag +0x8) and the 332-byte payload (back-pointer +0x0, 0x140-byte item copy at +0x4, zero/-1 dwords at +0x144/+0x148) are documented in class responsibility prose only; the packet carries no field evidence refs for bases 'node'/'payload', so they are not declared as schema fields.
- SessionDescriptor: only offsets with packet field evidence refs (+0x0/+0x4/+0x8/+0xD8/+0xE8) are declared as fields; the remaining populated slots (string +0x48, dwords +0xC8..+0xD4, +0xDC/+0xE0/+0xE4/+0xFC/+0x100, flag byte +0xE8 documented in prose) are recorded in class responsibility prose only because the packet supplies no field evidence refs for them.
