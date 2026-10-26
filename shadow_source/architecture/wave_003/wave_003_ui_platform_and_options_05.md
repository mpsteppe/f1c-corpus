# UIPlatformAndOptions

Scope: `ui_platform_and_options`  
Trust: `DERIVED`

DERIVED architecture proposal for the ui_platform_and_options scope. The packet covers fifteen functions. (1) UI texture/resource layer: ResourceTextureManager (0x00546AA0) selects one of eight array slots by bitmask and acquires a named D3D-texture resource object, replacing an old object, reusing a shared linked-list object when found, or creating a new per-element texture set, with a -1 rollback on texture failure; UIListTextureManager (0x005510F0) is a constructor-style initializer for a UI list texture/scale manager and is reused by SceneUIListManager (0x0054BB40), which creates and links a UI list node into the scene chain; UIWidget (0x0054C1B0) recursively propagates widget state updates; UICleanupDispatcher (0x005528F0) conditionally dispatches cleanup through the UI cleanup iterator. (2) Device layer: DeviceStateParameter (0x00554610) notifies the global game device object (dword_8B89A0) through vtable slot +244, D3DResourceAcquirer (0x00554F80) acquires a texture-like resource with linked-list reuse and a device vtable slot +116 dispatch, and D3DDeviceManager (0x00555E50) performs Direct3D device-loss recovery (cooperative-level query, teardown, swap-chain recreation, restore) through the device vtable slots 0x3C/0xC/0x7C/0x38/0x40. (3) Session/platform layer: SessionValidateSender (0x005629B0) builds and sends a Base64-encoded UDP validate message, FileHandleObject (0x00566A70) opens files with a read/write mode selector, and PlatformServices groups four individually-evidenced free helpers: reserved DOS device-name rejection (0x005687F0), thread-safe stream read (0x0058803F), byte-buffer quicksort (0x005890AA) and per-thread TLS data (0x0058E0C7); ThreadHandleObject (0x00585550) performs thread shutdown with mutex-gated termination. Ownership of every object is UNKNOWN in the packet, so all class groupings are GUESS-level aggregations; equal offsets across owners are kept as separate base+offset fields.

## Function roles

- `0x00546AA0` **ResourceTextureManager** — Resource/texture manager acquisition: decodes the a2 bitmask into one of eight 148-byte-stride slots at this+0xA8, tears down a replaced object (refcount drop, per-element destructor, linked-list removal), builds per-element names via StringFormatWithBufferOverflowCheck with the extension literal global 0x005CC79C, reuses a linked-list object when found and slot flag 0x100 is clear, otherwise allocates a new object and creates one D3D texture per element, appends to the shared list, refreshes list membership into this+0xB4, clears this+0x9C bit 1, and returns 0, or -1 after rollback on texture failure.
- `0x0054BB40` **SceneUIListManager** — Creates a 40-byte UI list node from a source template, initializes it through the UI list texture manager (0x005510F0) using template data at a2+0xC, links it into the scene UI list-node chain (head at this+0x214, tail-next through the list-state container at this+0x238), fills per-item sequential indices, registers the node, collects rendering state via sub_557350, and conditionally attaches node state via sub_559200. Called by SceneNode (0x0055A910).
- `0x0054C1B0` **UIWidget** — Recursively propagates a widget state update to two linked child widgets (this+0x44, this+0x4C) gated by a3 / (a3 & a4), then, when the flag-state object at this+0x230 is non-null, sets the global bit-1 flag (Bit1FlagSet) or clears the state flag (StateFlagBitClear) based on a2.
- `0x005510F0` **UIListTextureManager** — Constructor-style initializer for a UI list texture/scale manager: zero-initializes the struct, allocates and initializes a 76-byte sub-object (sub_556220) stored at this+0x0, registers it (sub_556260), allocates a count-header-prefixed array of 136-byte-stride scale-default elements, fills count at this+0x14 and array pointer at this+0x18, zeroes this+0x8/0xC/0x10/0x1C/0x20/0x24, and sets the constant flag 0x20000 at this+0x4.
- `0x005528F0` **UICleanupDispatcher** — Conditional cleanup dispatch: when flag bit 0x20000 at this+0x24 is set and the pointer at this+0x868 is non-null, dispatches UICleanupIterator (0x00554D70) on the object at this+0x868; otherwise returns the (possibly uninitialized) earlier result.
- `0x00554610` **DeviceStateParameter** — Sets a device-backed parameter: when the new value pointer a2 differs from the stored pointer at this+0x30, dispatches the stdcall virtual at vtable slot +244 of the global game device object dword_8B89A0 with the object identifier this+0x0 and a parameter value read from *(*(a2+84)+20) (or 0 when a2 is null), then stores a2 (or 0) at this+0x30. Used by state field setters and cleanup iterators.
- `0x00554F80` **D3DResourceAcquirer** — Acquires a texture-like resource with reuse: reads the resource descriptor at a3+84 and, when its setup flag (index 6, bit 0x400) is clear, creates the resource via sub_554E90 into this+0x0; a -1 result triggers a linked-list search through ValueGetter(a2)+40 for a matching node to reuse, with a no-match fallback through StructFieldGetter and D3DResourceListCleanup before a retry; finally dispatches device vtable slot +116 via the device object at this+0x1100 when the descriptor has a target, marks the setup bit 0x400, clears descriptor index 14 and returns 1.
- `0x00555E50` **D3DDeviceManager** — Direct3D device-loss recovery: queries device state via the interface at this+0x1100 (vtable slot 0x3C, returning -2005530520 device-lost, then slot 0xC returning -2005530519 device-not-reset), resets the device (slot 0x7C), tears down (sub_53F6E0, RenderTargetCleanup), sets the display mode (slot 0x38, error reported via sub_53C590 with the aCouldNotSetDis message and format global 0x005DBCE4), recreates an additional swap chain (slot 0x40), maps the display-mode selector at this+0x1114 through the jump table, recreates via sub_53F3F0, re-resets, restores via sub_53EB70, and sets flag bit 2 on the caller result a3 when the reset completed.
- `0x005629B0` **SessionValidateSender** — Builds a network message over a UDP socket: when the validation string a4 is non-empty and at most 128 chars, combines it with object data at a1+72 (sub_562150), Base64-encodes it, formats a '\validate\%s' segment (format global 0x005E4EB4) and appends it (sub_562710); always appends the mandatory final segment from global aFinal (0x005E4EAC) and sends the composed buffer with sub_562610. Returns 0 without sending when a4 exceeds 128 chars.
- `0x00566A70` **FileHandleObject** — File open helper: optionally runs the a5-gated FileAttributeCheckSequence on the name a2, stores the mode arguments at this+0x0C and this+0x10, clears the local path buffer (sub_568620), opens through sub_587DB0 choosing the read-mode path global unk_5E517C or the write-mode path global unk_5E5180 based on this+0x0C, stores the handle at this+0x00, zeroes this+0x18, and copies the resolved path into this+0x04 when the handle is valid.
- `0x005687F0` **PlatformServices** — Reserved DOS device-name check: builds a 23-entry candidate table (CON, PRN, AUX, CLOCK$, COM1-COM9, LPT1-LPT9), copies up to 7 chars of the input name, truncates at the first separator or dot, compares against each candidate via sub_588410, and returns 1 on match else 0.
- `0x00585550` **ThreadHandleObject** — Thread shutdown and cleanup: retries ThreadResumeWithMutexWait up to 10 times with a 250 ms sleep, then, when the thread handle at this+0x4 is live, sets the termination flag at this+0xC under the mutex at this+0x10 (wait timeout this+0x14), waits indefinitely on the thread handle, closes it, and clears the handle/id fields at this+0x4/0x8.
- `0x0058803F` **PlatformServices** — Synchronous thread-safe read wrapper: acquires the stream lock via StreamBufferLockViaCriticalSection(a4), performs the read by forwarding (a1,a2,a3,a4) to sub_58806E, releases via AddressRangeCriticalSectionLeave(a4), and returns the inner read result. Shared across deserialization, file enumeration, scene parsing, mesh loading and file-write paths.
- `0x005890AA` **PlatformServices** — Iterative quicksort over an array of a2 elements each a3 bytes at base a1, ordered by the caller-supplied comparator a4: small subarrays (8 or fewer) are handed to sub_5891FE, the middle element becomes the pivot (ByteBufferSwap), a Hoare-style scan partitions the range, and the larger partition is processed in place while the smaller is pushed onto an explicit stack.
- `0x0058E0C7` **PlatformServices** — CRT-style per-thread data retrieval: saves GetLastError, reads the per-thread data block via TlsGetValue(dwTlsIndex); on first access lazily allocates a 116-byte block (sub_58AB58), registers it with TlsSetValue, initializes it (TwoFieldInitializer_e0b4), stamps it with the current thread id and a -1 sentinel, terminates with CRTAmsgExit(0x10) on failure, and restores the saved LastError before returning.

## Proposed classes

### ResourceTextureManager

Acquires named D3D-texture resource objects into one of eight slot-array entries at this+0xA8 (148-byte stride): replaces or tears down old objects, reuses shared linked-list objects, creates per-element textures, maintains linked-list membership (this+0xB0/this+0xB4) and flag state (this+0x9C).

Methods: `0x00546AA0`

- `this+0x0000009C` `dword Flags` (read_write, GUESS)
- `this+0x000000A8` `void* SlotArrayBase` (read, GUESS)
- `this+0x000000B0` `void* SharedObjectList` (read_write, GUESS)
- `this+0x000000B4` `void* ListMembershipResult` (write, GUESS)

### SceneUIListManager

Creates UI list nodes from templates, initializes them through the UI list texture manager, links them into the scene UI list-node chain (head at this+0x214, tail-next through the list-state container at this+0x238), fills per-item indices, and attaches rendering state.

Methods: `0x0054BB40`

- `this+0x00000214` `void* ListNodeHead` (read_write, GUESS)
- `this+0x00000218` `dword AttachStateFlag` (read, GUESS)
- `this+0x00000238` `void* ListStateContainer` (read, GUESS)
- `*(*(this+0x238)+0x24)+0x00000024` `void* TailNodeNext` (read_write, GUESS)

### UIWidget

Recursively propagates a widget state update to two linked child widgets and sets/clears a shared state flag through the flag-state object at this+0x230.

Methods: `0x0054C1B0`

- `this+0x00000044` `void* FirstChild` (read, GUESS)
- `this+0x0000004C` `void* SecondChild` (read, GUESS)
- `this+0x00000230` `void* FlagStateObject` (read, GUESS)

### UIListTextureManager

Constructor-style initializer for a UI list texture/scale manager: allocates a 76-byte sub-object, registers it, allocates a count-header-prefixed 136-byte-stride element array, and fills count/array/flag fields.

Methods: `0x005510F0`

- `this+0x00000000` `void* SubObject` (write, GUESS)
- `this+0x00000004` `dword ModeFlag` (write, GUESS)
- `this+0x00000008` `dword ZeroedField0` (write, GUESS)
- `this+0x0000000C` `dword ZeroedField1` (write, GUESS)
- `this+0x00000010` `dword ZeroedField2` (write, GUESS)
- `this+0x00000014` `int ElementCount` (write, GUESS)
- `this+0x00000018` `void* ElementArray` (write, GUESS)
- `this+0x0000001C` `dword ZeroedField3` (write, GUESS)
- `this+0x00000020` `dword ZeroedField4` (write, GUESS)
- `this+0x00000024` `dword ZeroedField5` (write, GUESS)

### UICleanupDispatcher

Conditional cleanup dispatch: when flag bit 0x20000 at this+0x24 is set and this+0x868 holds a non-null object, dispatches UICleanupIterator on it.

Methods: `0x005528F0`

- `this+0x00000024` `dword CleanupGateFlag` (read, GUESS)
- `this+0x00000868` `void* CleanupTargetPtr` (read, GUESS)

### DeviceStateParameter

Sets a device-backed parameter by dispatching a stdcall virtual (vtable slot +244) on the global game device object dword_8B89A0 and recording the applied pointer at this+0x30.

Methods: `0x00554610`

- `this+0x00000000` `dword ObjectIdentifier` (read, GUESS)
- `this+0x00000030` `void* StoredParameterPtr` (read_write, GUESS)

### D3DResourceAcquirer

Acquires a texture-like resource, reusing an existing linked-list node when possible, with a fallback cleanup/retry path and a final device vtable slot +116 dispatch through the device object at this+0x1100.

Methods: `0x00554F80`

- `this+0x00000000` `int ResourceHandle` (read_write, GUESS)
- `this+0x00001100` `void* DeviceObjectPtr` (read, GUESS)
- `*(this+0x1100)+0x00000000` `void* DeviceVtablePtr` (read, GUESS)

### D3DDeviceManager

Direct3D device-loss recovery and recreation: queries cooperative-level state through the device interface at this+0x1100, resets and re-creates the render targets and an additional swap chain, maps the display-mode selector, restores device state, and reports completion on the caller result.

Methods: `0x00555E50`

- `this+0x00000000` `int LastResult` (read_write, GUESS)
- `this+0x00001100` `void* DeviceInterfacePtr` (read, GUESS)
- `this+0x00001114` `dword DisplayModeSelector` (read, GUESS)
- `this+0x00001528` `void* SwapChainConfigPtr` (read, GUESS)
- `this+0x0000152C` `void* PresentParametersPtr` (read, GUESS)
- `*(this+0x1100)+0x00000000` `void* DeviceVtablePtr` (read, GUESS)
- `*(this+0x1528)+0x0000000C` `void* SwapChainPresentParamsPtr` (read, GUESS)
- `*(this+0x152C)+0x0000000C` `void* ResetPresentParamsPtr` (read, GUESS)
- `*(*(this+0x1528)+0xC)+0x00000000` `void* SwapChainObjectPtr` (read, GUESS)

### SessionValidateSender

Builds a UDP validate message: combines existing object data with the validation string, Base64-encodes it into a '\validate\%s' segment, appends a mandatory final segment, and sends the composed buffer.

Methods: `0x005629B0`


### FileHandleObject

File open helper object: stores mode arguments, opens the file through the mode-selected path, and keeps the handle, resolved path string and a zeroed flag byte.

Methods: `0x00566A70`

- `this+0x00000000` `void* Handle` (read_write, DERIVED)
- `this+0x00000004` `char* PathString` (write, DERIVED)
- `this+0x0000000C` `int Mode` (read_write, DERIVED)
- `this+0x00000010` `int ModeArgument` (read_write, DERIVED)
- `this+0x00000018` `byte FlagByte` (write, DERIVED)

### ThreadHandleObject

Thread shutdown object: retries resume, sets the termination flag under a mutex, waits on and closes the thread handle, and clears the handle/id fields.

Methods: `0x00585550`

- `this+0x00000004` `void* ThreadHandle` (read_write, DERIVED)
- `this+0x00000008` `dword ThreadId` (read_write, DERIVED)
- `this+0x0000000C` `dword TerminationFlag` (read_write, DERIVED)
- `this+0x00000010` `void* MutexHandle` (read, DERIVED)
- `this+0x00000014` `dword MutexWaitTimeout` (read, DERIVED)

### PlatformServices

Platform/utility helpers, each independently evidenced: reserved DOS device-name rejection (0x005687F0), thread-safe stream read wrapper (0x0058803F), generic byte-buffer quicksort (0x005890AA) and CRT per-thread TLS data access (0x0058E0C7).

Methods: `0x005687F0`, `0x0058803F`, `0x005890AA`, `0x0058E0C7`


## Compatibility contracts

- **ResourceTextureSlotContract** — The texture manager keeps 8 array slots at this+0xA8 (148-byte stride), each holding a resource object pointer at slot+140 and an element count at slot+72. Acquisition returns 0 on success (reuse or fresh create) and -1 on texture-creation failure after tearing down created elements, freeing the allocation and detaching slot+140. Reuse requires a shared linked-list match (StringSearchInLinkedList) plus slot flag 0x100 clear; the object refcount governs teardown.
- **D3DDeviceLossRecoveryContract** — Device-loss recovery must follow the observed sequence: vtable slot 0x3C cooperative-level query returning -2005530520 (device lost) and slot 0xC returning -2005530519 (device not reset) gate the recovery; then slot 0x7C Reset, teardown (sub_53F6E0 / RenderTargetCleanup 0x0053F270), slot 0x38 display-mode set, slot 0x40 additional swap-chain creation, recreation pass sub_53F3F0, second Reset and restore pass sub_53EB70, with the display-mode selector mapping at this+0x1114 (2->32, 3->256, 4->64, 0x10->0x100000) and return -1 on error or -2 on success with bit 2 set on the caller result.
- **GameDeviceParameterNotificationContract** — Setting a device-backed parameter must skip when a2 equals the stored pointer at this+0x30; otherwise dispatch the stdcall virtual at vtable slot +244 (0xF4) of the global game device object dword_8B89A0 with (object identifier this+0x0, parameter value read from *(*(a2+84)+20) or 0 when a2 is null), then store a2 (or 0) at this+0x30.
- **ReservedDosDeviceNameContract** — A device-name string must be rejected when its first up-to-7 characters, truncated at the first separator or dot (backslash, slash, colon, dot), equal one of the 23 reserved DOS device names (CON, PRN, AUX, CLOCK$, COM1-COM9, LPT1-LPT9); returns 1 on match, else 0.
- **ThreadSafeStreamReadContract** — A thread-safe synchronous read must acquire the stream lock (0x0058C1B1), forward (a1,a2,a3,a4) to the inner read (0x0058806E), release the lock (0x0058C203) and return the inner result unchanged.
- **ThreadShutdownContract** — Thread shutdown must retry ThreadResumeWithMutexWait up to 10 times with a 250 ms sleep, then, when the thread handle at this+0x4 is live, set the termination flag at this+0xC under the mutex at this+0x10 (wait timeout this+0x14), wait indefinitely on the thread handle, CloseHandle it, and clear the handle/id fields at this+0x4/0x8.
- **ValidateMessageProtocolContract** — The UDP validate message must: when the validation string a4 is non-empty and at most 128 chars, combine it with object data at a1+72 (sub_562150), Base64-encode it, format a '\validate\%s' segment (format global 0x005E4EB4) and append it (sub_562710); always append the mandatory final segment from global aFinal (0x005E4EAC) and send the composed buffer (sub_562610); return 0 without sending when a4 exceeds 128 chars.
- **FileOpenModeContract** — File open must store the mode arguments (a4 at this+0x0C, a3 at this+0x10), optionally gate on the a5-driven FileAttributeCheckSequence, clear the 1024-byte path buffer (sub_568620), open through sub_587DB0 with the read-mode path global unk_5E517C when this+0x0C is nonzero else the write-mode path global unk_5E5180, store the handle at this+0x00, zero this+0x18, and copy the resolved path into this+0x04 when the handle is valid.
- **PerThreadDataContract** — Per-thread data access must preserve GetLastError across the TLS setup path: read the block via TlsGetValue(dwTlsIndex 0x005E6D40), lazily allocate a 116-byte block (sub_58AB58), register it with TlsSetValue, initialize it (TwoFieldInitializer 0x0058E0B4), stamp it with the current thread id and a -1 sentinel, and terminate via CRTAmsgExit(0x10) on allocation/registration failure.

## Unresolved

- Owner of every packet object is UNKNOWN; all class groupings are GUESS-level aggregations of individually-evidenced functions and may split or merge when independent class evidence arrives.
- Shared this+0x1100 device-object pointer appears in both D3DDeviceManager (0x00555E50) and D3DResourceAcquirer (0x00554F80); the packet does not prove the two owners are the same class, so they are kept as separate base+offset fields and the possible merge is left unresolved.
- acquireOrCreateResource (0x00546AA0): the slot layout (slot+64/+68/+96/+128) and the individual D3DTextureCreation flag bits are DERIVED from usage only, not confirmed by any independent source; the per-element destructor loop 'for (i = v50; i > 0; ++i)' cannot terminate as shown (presumed a decompiler sign artifact); element count is stored both in the allocation header (obj-4) and at object+0x4C with the reuse of obj+0 as refcount/element-0 field unresolved; unk_800000 may be IDA's rendering of a literal 0x800000 constant rather than a global read; the D3DTextureCreation nonzero=failure return convention is inferred from the rollback path; the aSS/aS2dS globals' exact '%s%s'/'%s%.2d%s' literals are inferred from adjacent format calls.
- CreateUIListNode (0x0054BB40): global dword_8B8F28 is flagged as a read but appears nowhere in the decompiled body; the packet models the tail-node next pointer through base *(*(this+0x238)+0x24) while the raw source walks the chain from this[133] via node+0x24; the two anchors are not reconciled here.
- UIListTextureManagerInit (0x005510F0): the purpose of the 76-byte sub-object constructor sub_556220 and the registration helper sub_556260 is inferred; the meaning of the 0x20000 flag at this+0x4 and the element type of the 136-byte-stride array are caller-contract details; element count is stored both in the array header (v6[0]) and at this+0x14 with no established authoritative copy.
- ConditionalUICleanupDispatch (0x005528F0): global dword_8B78A0 is listed as read by packet facts but is absent from the raw source; the 0x20000 gate flag at this+0x24 (existing analysis labels it a texture-mode gate) and the object at this+0x868 (possibly a font texture object) are DERIVED, not confirmed.
- StateParameterSetterWithVirtualDeviceNotify (0x00554610): the concrete callee behind the indirect dispatch at vtable slot +244 of dword_8B89A0 is not established; the parameter-source object layout (offsets +84 and +84+20) is not in the packet field set.
- ResourceAcquisitionWithReuse (0x00554F80): the descriptor struct at a3+84 and its fields at indices 5/6/14 are not established; the node identity-match fields (a3+80, node +28/+32/+48, node value at +56) carry no owner-level meaning; flt_59E440 is flagged as a referenced global but is absent from the raw body; the virtual slot +116 (0x74) of the device object is uncharacterized.
- resetAndRestoreDeviceResources (0x00555E50): field *(*(*(this+0x1528)+0xC)+0x0):0x00000008 (backbuffer/surface format read) is not visible in the decompiled body; the role of the this+0x1104 argument passed to vtable slot 0x38 is unknown; the semantic meaning of the mapped flag values 32/256/64/0x100000 is not established; the return-code contract (0/-1/-2) with caller 0x0055C060 is inferred.
- BuildAndSendValidateMessage (0x005629B0): the content of the final segment string aFinal (global 0x005E4EAC) is not present in the packet; the purpose of the data at object offset a1+72 and what sub_562150 does with it is unknown; the claim that this is player/session validation on the game networking path is a DERIVED hypothesis, not packet evidence.
- PlatformServices grouping (0x005687F0, 0x0058803F, 0x005890AA, 0x0058E0C7): these are individually-evidenced free helpers grouped only by their platform/utility role; sub_5891FE's body (assumed small-range sorter), the quicksort comparator convention (a4 sign relative to the pivot), and the per-thread block layout beyond Value[0] thread id / Value[1] -1 sentinel are unestablished.
- OpenFileWithReadWriteMode (0x00566A70): the exact purpose of the a5-gated FileAttributeCheckSequence and the distinct roles of a3 (this+0x10) versus a4 (mode at this+0x0C) are not documented in this packet.
