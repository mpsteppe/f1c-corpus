# UIPlatformAndOptions

Scope: `ui_platform_and_options`  
Trust: `DERIVED`

DERIVED architecture proposal for the ui_platform_and_options scope, packet 03. Twenty validated functions recover a broad set of UI/platform primitives. The only packet-claimed owners are UIListComboBox (DERIVED, for the combo-box state-buffer constructor 0x0051A4F2) and DrawableObjectNodeManager (DERIVED, for 0x005454D0). A strong shared-layout link joins the threaded-worker constructor 0x005837F0 and the mutex-protected int accessor 0x00585770 through the identical mutex/timeout fields at this+0xF0/+0xF4 (plus value at this+0xEC), so both are grouped into one ThreadedWorkerObject class. Every other function has an UnknownObject owner, so its class grouping is a DERIVED/GUESS aggregation over field and callee evidence, not a recovered original type. Two subsystems worth of behavior sit in this packet: HUD/UI (0x004DB550, 0x0051A4F2, 0x00537E40, 0x00542200, 0x005454D0, 0x0055CE50, 0x0055ED10) and platform/threading/network (0x004DEF70, 0x004EA010, 0x0052D8D0, 0x0057D6C0, 0x0057EDD0, 0x005837F0, 0x00583D90, 0x00585770, 0x0058E060, 0x00591727), plus two standalone math utilities (0x00568FB0, 0x0056C3A0) and one forwarding wrapper (0x0055D3F0). Contradiction to note: the combination of HUD rendering, constraint math and UDP networking in one scope is a manifest grouping, not evidence of a single class family; class boundaries here are intentionally conservative.

## Function roles

- `0x004DB550` **HudLayoutDispatcher** — HUD layout dispatcher: selects a speed-magnitude variant on global byte_7D0474 (SpeedMagnitude 0x0049B900 vs SpeedMagnitude_b950 0x0049B950), reads engine RPM via EngineRevValueAccessor 0x0049B8F0, and dispatches the three HUD element renderers PositionOrderNameDisplay 0x004DB6F0, UtilityFunction_b9a0 0x004DB9A0 and sub_4DB7F0 (fed by sub_49B7A0 over global 0x007CE234) with the layout parameter a1 and per-element constants 20/68/10.
- `0x004DEF70` **SpatialLRUCache** — Spatial cache population: builds a 9-float entry (a2 seed + a3 position triple), subtracts the stored origin from the a3 triple when the flag byte at (this+0x4)+0x42 is set, copies the a4 triple, computes its magnitude, and on a positive magnitude inserts the entry into a sorted LRU array via SortedArrayInsertWithLRUEviction 0x004DEDB0.
- `0x004EA010` **PooledCollisionSlotAllocator** — Fixed-capacity pool slot allocator: returns &unk_8AD3F8 + 56*dword_8ADAF8 and post-increments the pool counter; once the counter reaches 32 returns the shared overflow buffer &unk_8ADAC0. Supplies temporary collision records to 0x004EA040 and 0x004EA970.
- `0x0051A4F2` **UIListComboBox** — UI list combo-box state-buffer constructor: allocates a 116-byte state buffer through the sub-allocator vtable at this+0x4 and stores it at this+0x184, seeds function pointers (InitAndChain 0x005199C5, ProtocolStateHandler 0x0051A4B7), then branches on a2: per-object copy mode (descriptor array this+0xC4 gated on this+0x20, AlignUp 0x00515927, per-object allocations through vtable entry 5) or flat 1280-byte compositing mode (vtable entry 1, ten 128-byte strided pointers).
- `0x0052D8D0` **RenderObjectFactory** — Lazily allocates and constructs a 11584-byte RenderObject into the output slot *this: OperatorNewNhMallocWrapper 0x00587C03, RenderObjectConstructor_e170 0x0052E170, vtable +4 init dispatch with a4; on failure runs VirtualCleanup 0x0052D990 and returns 0.
- `0x00537E40` **UIElementInitializer** — Initializes an object: EmptyStub_7eb0 0x00537EB0, installs self-relative buffer pointers (this+0xB0E/+0xB1A/+0xB26) and static table pointers (this+0xB16/+0xB22/+0xB2E to 0x005DA928/0x005DA93C/0x005DA950), sets capacity word 8 at this+0x16A7, zeroes this+0x16AB/+0x16AD, then returns ScorecardZero(this).
- `0x00542200` **ViewportProjection** — Computes a viewport/window rectangle in pixels: scales normalized width/height/travel by global scale dword_8B8DD4/8B8DD8 (or unity when a6 set), converts via CRTFtol 0x00587BDC, writes integer and float center/width/height fields, derives half-width/half-height projection terms (this+0xC/+0x10) and aspect ratio this+0x74; bit 0x10 of this+0x80 controls half-width negation.
- `0x005454D0` **DrawableObjectNodeManager** — Appends drawable node a2 to a category-selected singly-linked list (switch on a3 selecting counter/head pairs), updates the total count this+0x60 from the category counters, then rebuilds the flat 56-byte-slot array at this+0x138 with a 4-byte count header, running per-slot cleanup/free (0x004B0170, 0x00587BCF) and zero-init (0x0055D200).
- `0x0055CE50` **UITextFieldRouter** — Three sequential vtable property-set calls on the sub-object at this+0x1100: two through vtable entry +0x94 (property enums 2 and 3) writing through this+1302/+1318, one through entry +0xA0 writing through this+1334; every return stored into *this, final value returned.
- `0x0055D3F0` **ByteUnpackForwarder** — Forwarding wrapper: decomposes packed a3 into its three low bytes (BYTE2/BYTE1/BYTE0) and forwards them as separate arguments to sub_55D320 0x0055D320, returning the callee result unchanged.
- `0x0055ED10` **SceneNodeCollector** — Collects up to 8 scene nodes from the linked list at this+0x128 into the caller array at a3+272 (56-byte stride, pointer + reciprocal weight 1.0/node+0x50). Gated by a3+20 bit 0x20 (skip) and by bit 0x100 of the flag dword at *(this+0x194)+0; world position fetched via SceneNodePositionGetter 0x0054B950 when a2+60 bit 0x10 is clear.
- `0x00568FB0` **ConstraintJacobianBuilder** — Builds a sparse identity-structured matrix in output buffer a2 from three element groups (counts this+0x22C/0x234/0x23C, arrays this+0x230/0x238/0x240): sums the group counts, classifies each element by index, and for each id pair writes a zero tag and value 1072693248 into symmetric slots.
- `0x0056C3A0` **QuaternionBasisBuilder** — Copies an input 4-DWORD + double record, normalizes the 3-vector, selects a perpendicular branch on fabs(x) >= 0.7 (dbl_59E830), builds two orthonormal basis vectors (second as cross product) and normalizes both outputs. Used for constraint-axis construction.
- `0x0057D6C0` **StructuredPacketSender** — Builds a structured packet via StructuredMemoryCopyWithHeaderPrepend 0x0057D5D0 (length v4 = buf[0]+buf[1]+4), fills a sockaddr from a3, and sends over socket this+0x93C with sendto. On failure dispatches on WSAGetLastError: most codes log via MutexProtectedLinkedListLookupByID 0x0057DFF0 with per-code strings; WSAENOBUFS 10055 retries through ThreadSafeMutexQueueWithTimedWait 0x0057EE80 and a vtable callback via FieldGetter_5cc0 0x00585CC0. Returns 1 on success.
- `0x0057EDD0` **ConnectionCleanupTable** — Mutex-protected connection cleanup: waits on the mutex this+0xB10 with timeout this+0xB14, searches the connection list at this+0xB00 for a node whose data first dword equals INADDR_ANY, zeroes that node's data dwords at +4/+8/+0xC, releases the mutex.
- `0x005837F0` **ThreadedWorkerObject** — Constructor-style initializer for a large threaded worker object: installs the timed callback loop with a mutex pair (0x0058A6EB), zero-initializes structures, creates a mutex-protected quad-buffer array, sets timing/config fields (capacity 64 at this+0x60, timing 0/7.7629/90 at this+0xE0/+0xE4/+0xE8), sets vtable off_5B8B60 at *this, self-links this[336], final count 750 at this+0x64C.
- `0x00583D90` **FloatAnimationThread** — Thread start routine (__stdcall): runs a float-accumulation loop guarded by MutexProtectedDataReadWithTimedWait 0x00583D40, accumulates frame values from timer v20, clamps to 0.0..10.0, dispatches via sub_584110, polls the object vtable at +80/+84, and when the accumulated total reaches 0.333 invokes EmptyStub_0170, sub_583F50 and the vtable dispatch at +12. Sleeps 5 ms per iteration via SleepEx.
- `0x00585770` **ThreadedWorkerObject** — Thread-safe int accessor: acquires the mutex at this+0xF0 with timeout this+0xF4, reads the protected int at this+0xEC, releases, returns the value. Operates on the same mutex/timeout layout initialized by the worker object.
- `0x0058E060` **TlsAllocationBootstrap** — One-time TLS initialization for allocation tracking: sub_58DFC1 sync setup, TlsAlloc into global dwTlsIndex, allocates a 116-byte per-thread block via sub_58AB58, stores it via TlsSetValue, initializes via TwoFieldInitializer_e0b4 0x0058E0B4, records GetCurrentThreadId and -1 sentinel. Returns 1 on success.
- `0x00591727` **FpuExceptionContextBuilder** — Builds an FPU exception context record (exception-type bitfield, control/status-word flag words, two double operands with classification flags) from a decoded exception-code bitmask, raises it via RaiseException, then decodes precision/rounding back into *a2 and returns the context base.

## Proposed classes

### HudLayoutDispatcher

HUD layout dispatch: picks a speed-magnitude variant from global state, reads engine RPM, and calls the three HUD element renderers with a layout parameter and per-element constants. Owner of the dispatch itself is unknown; the speed/RPM accessors and element renderers are external.

Methods: `0x004DB550`


### SpatialLRUCache

Spatial cache object: holds an origin sub-struct (with an offset-enabling flag) and inserts position/magnitude entries into a sorted LRU array.

Methods: `0x004DEF70`

- `this+0x00000004` `void* PositionSubstruct` (read, DERIVED)
- `*(this+0x4)+0x00000042` `byte OffsetEnabledFlag` (read, GUESS)
- `*(this+0x4)+0x00000004` `float OriginX` (read, GUESS)
- `*(this+0x4)+0x00000008` `float OriginY` (read, GUESS)
- `*(this+0x4)+0x0000000C` `float OriginZ` (read, GUESS)

### PooledCollisionSlotAllocator

Static fixed-capacity slot pool: hands out one 56-byte slot of a 32-entry static array per call (counter-selected), falling back to a shared overflow buffer when exhausted. No instance fields; state is global.

Methods: `0x004EA010`


### UIListComboBox

UI list combo-box object: sub-allocates a 116-byte state buffer (held at this+0x184), walks a sprite-descriptor array (this+0xC4) and builds either per-object copy buffers or a flat 1280-byte compositing buffer depending on the construction mode.

Methods: `0x0051A4F2`

- `this+0x00000004` `void** SubAllocatorVtable` (read, DERIVED)
- `this+0x00000184` `void* StateBuffer` (read_write, DERIVED)
- `this+0x00000020` `int DescriptorCount` (read, DERIVED)
- `this+0x000000C4` `void* DescriptorArray` (read, DERIVED)
- `this+0x000000C8` `byte TripleWidthFlag` (read, DERIVED)
- `*(this+0x4)+0x00000000` `void* AllocVtableEntry0` (read, GUESS)
- `*(this+0x4)+0x00000004` `void* AllocVtableEntry1` (read, GUESS)
- `*(this+0x4)+0x00000014` `void* AllocVtableEntry5` (read, GUESS)
- `*(this+0xC4)+0x0000000C` `int DescriptorWidth` (read, GUESS)
- `*(this+0xC4)+0x0000001C` `int DescriptorHeight` (read, GUESS)
- `*(this+0xC4)+0x00000020` `int DescriptorStrideField` (read, GUESS)

### RenderObjectFactory

Lazy factory for a large (11584-byte) render object: allocates, constructs via RenderObjectConstructor, stores into an output slot, and dispatches a vtable +4 init; on any failure runs VirtualCleanup and reports failure.

Methods: `0x0052D8D0`

- `this+0x00000000` `void* OutputSlot` (read_write, DERIVED)

### UIElementInitializer

Initializes a UI element object: installs self-relative buffer pointers and static table pointers, sets a capacity word, zeroes trailing fields, and finishes through an outer initialization call.

Methods: `0x00537E40`

- `this+0x00000B0E` `void* SelfRelBufferA` (write, DERIVED)
- `this+0x00000B1A` `void* SelfRelBufferB` (write, DERIVED)
- `this+0x00000B26` `void* SelfRelBufferC` (write, DERIVED)
- `this+0x00000B16` `void* StaticTableA` (write, DERIVED)
- `this+0x00000B22` `void* StaticTableB` (write, DERIVED)
- `this+0x00000B2E` `void* UnkDataPtr` (write, DERIVED)
- `this+0x000016A7` `int CapacityWord` (write, DERIVED)
- `this+0x000016AB` `short ZeroWord` (write, DERIVED)
- `this+0x000016AD` `int ZeroDword` (write, DERIVED)

### ViewportProjection

Viewport/window rectangle computation: scales normalized inputs by a global screen scale, converts to integer pixels, and derives projection half-width/half-height terms plus aspect ratio with a sign flag.

Methods: `0x00542200`

- `this+0x0000000C` `float HalfWidthProjection` (write, DERIVED)
- `this+0x00000010` `float HalfHeightProjection` (write, DERIVED)
- `this+0x00000014` `float CenterXFloat` (write, DERIVED)
- `this+0x00000018` `float CenterYFloat` (write, DERIVED)
- `this+0x0000001C` `float WidthDivisor` (read, GUESS)
- `this+0x00000020` `float HeightDivisor` (read, GUESS)
- `this+0x00000054` `int ViewportWidth` (write, DERIVED)
- `this+0x00000058` `int ViewportHeight` (write, DERIVED)
- `this+0x0000005C` `int CenterXInt` (write, DERIVED)
- `this+0x00000060` `int CenterYInt` (write, DERIVED)
- `this+0x00000064` `int CenterBaseY` (write, DERIVED)
- `this+0x00000068` `int CenterBaseX` (write, DERIVED)
- `this+0x00000074` `float AspectRatio` (write, DERIVED)
- `this+0x00000080` `byte NegateHalfWidthFlag` (read, GUESS)

### DrawableObjectNodeManager

Drawable object node manager: maintains category-selected singly-linked node lists with per-category counters, a summed total count, and a rebuilt flat 56-byte-slot array with a 4-byte count header.

Methods: `0x005454D0`

- `this+0x00000060` `int TotalCount` (write, DERIVED)
- `this+0x00000124` `int Category4Counter` (read, DERIVED)
- `this+0x00000128` `void* Category4Head` (read_write, DERIVED)
- `this+0x0000012C` `int Category2Counter` (read, DERIVED)
- `this+0x00000134` `int ArrayValidFlag` (write, DERIVED)
- `this+0x00000138` `void* FlatArray` (read_write, DERIVED)
- `*(this+0x128)+0x0000006C` `void* NodeNext` (read_write, DERIVED)
- `*(*(*(this+0x128)+0x6C)+0x6C)+0x0000006C` `void* TailNext` (write, GUESS)

### UITextFieldRouter

Router that issues sequential property-set calls through the vtable of a sub-object at this+0x1100, storing each result into *this and returning the last one.

Methods: `0x0055CE50`

- `this+0x00001100` `void* TargetObject` (read, DERIVED)
- `this+0x00000000` `void* ResultSlot` (read_write, DERIVED)
- `*(this+0x1100)+0x00000094` `void* PropertySetVtable94` (read, DERIVED)
- `*(this+0x1100)+0x000000A0` `void* PropertySetVtableA0` (read, DERIVED)

### ByteUnpackForwarder

Thin forwarding wrapper that unpacks a packed value into three byte arguments and forwards them to a single callee; no own state.

Methods: `0x0055D3F0`


### SceneNodeCollector

Scene-node collector: walks a linked list at this+0x128, accepting nodes by a byte pattern, and fills a caller array with node pointers and reciprocal weights, gated by a skip flag and an enable bit in the struct at this+0x194.

Methods: `0x0055ED10`

- `this+0x00000128` `void* NodeListHead` (read, DERIVED)
- `*(this+0x194)+0x00000000` `int NodeFlagDword` (read, GUESS)
- `*(this+0x194)+0x00000050` `float NodeWeight` (read, GUESS)
- `*(this+0x194)+0x0000006C` `void* NodeNext` (read, GUESS)

### ConstraintJacobianBuilder

Constraint matrix builder: classifies elements into three groups by index ranges and writes an identity-structured sparse matrix (zero tags plus value 1072693248) into an output buffer.

Methods: `0x00568FB0`

- `this+0x0000022C` `int Group1Count` (read, DERIVED)
- `this+0x00000230` `void* Group1Array` (read, DERIVED)
- `this+0x00000234` `int Group2Count` (read, DERIVED)
- `this+0x00000238` `void* Group2Array` (read, DERIVED)
- `this+0x0000023C` `int Group3Count` (read, DERIVED)
- `this+0x00000240` `void* Group3Array` (read, DERIVED)

### QuaternionBasisBuilder

Constraint-axis math utility: copies an input 4-DWORD + double record, normalizes the 3-vector, and builds two orthonormal basis vectors (perpendicular selection + cross product). No instance fields; operates on caller-provided buffers.

Methods: `0x0056C3A0`

- `this+0x00000000` `int InputDword0` (read, DERIVED)
- `this+0x00000004` `int InputDword1` (read, DERIVED)
- `this+0x00000008` `int InputDword2` (read, DERIVED)
- `this+0x0000000C` `int InputDword3` (read, DERIVED)
- `this+0x00000010` `double InputDouble` (read, DERIVED)

### StructuredPacketSender

UDP structured packet sender: builds a header-prepended packet, populates a sockaddr, sends over the socket at this+0x93C, and dispatches WSA errors (per-code logging vs WSAENOBUFS queue-retry).

Methods: `0x0057D6C0`

- `this+0x0000093C` `int SocketHandle` (read, DERIVED)

### ConnectionCleanupTable

Network connection table guarded by a mutex: waits on the mutex, searches the connection list for an INADDR_ANY entry, and resets its send-state data dwords.

Methods: `0x0057EDD0`

- `this+0x00000B00` `void* ConnectionListHead` (read, DERIVED)
- `this+0x00000B10` `void* ConnectionMutex` (read, DERIVED)
- `this+0x00000B14` `int MutexTimeout` (read, DERIVED)
- `*(this+0xB04)+0x00000000` `void* NodeDataPtr` (read, GUESS)
- `*(this+0xB04)+0x00000004` `int DataLatestValue` (write, GUESS)
- `*(this+0xB04)+0x00000008` `int DataAccumulatedSum` (write, GUESS)
- `*(this+0xB04)+0x0000000C` `int DataSendCounter` (write, GUESS)

### ThreadedWorkerObject

Large threaded worker object: constructor-style initializer builds a timed callback loop, a mutex-protected quad-buffer array, and timing/config state; the accessor reads a mutex-protected int in the same layout. Same mutex/timeout fields (this+0xF0/+0xF4) are initialized here and consumed by 0x00585770.

Methods: `0x005837F0`, `0x00585770`

- `this+0x00000000` `void* VtablePtr` (write, DERIVED)
- `this+0x0000005C` `byte EnableByte` (write, DERIVED)
- `this+0x0000005D` `byte StateByte` (write, DERIVED)
- `this+0x00000060` `int CapacityDword` (write, DERIVED)
- `this+0x00000064` `byte EnableByte2` (write, DERIVED)
- `this+0x00000078` `int ConfigDwordA` (write, DERIVED)
- `this+0x0000007C` `int ConfigDwordB` (write, DERIVED)
- `this+0x00000080` `short ConfigWord16` (write, DERIVED)
- `this+0x000000D4` `int WorkerStateValue1` (write, DERIVED)
- `this+0x000000D8` `int WorkerStateHandle1` (write, DERIVED)
- `this+0x000000DC` `byte WorkerStateByte1` (write, DERIVED)
- `this+0x000000E0` `float TimingValue0` (write, DERIVED)
- `this+0x000000E4` `float TimingValue7629` (write, DERIVED)
- `this+0x000000E8` `float TimingValue90` (write, DERIVED)
- `this+0x000000EC` `int ProtectedInt` (read, DERIVED)
- `this+0x000000F0` `void* ProtectedIntMutex` (read_write, DERIVED)
- `this+0x000000F4` `int ProtectedIntTimeout` (read_write, DERIVED)
- `this+0x000000F8` `byte StateByte2` (write, DERIVED)
- `this+0x00000540` `void* SelfLink` (write, DERIVED)
- `this+0x0000064C` `int FinalCount750` (write, DERIVED)

### FloatAnimationThread

Animation thread start routine: accumulates clamped float frame values from a timer, dispatches via sub_584110 and, on a 0.333 threshold, through vtable dispatches of the worker object; runs while a mutex-protected shutdown flag reads zero.

Methods: `0x00583D90`

- `obj+0x0000000C` `void* VtableDispatch12` (read, DERIVED)
- `obj+0x00000050` `void* VtableDispatch80` (read, DERIVED)
- `obj+0x00000054` `void* VtableDispatch84` (read, DERIVED)
- `this+0x00000000` `void* VtablePtr` (read, DERIVED)

### TlsAllocationBootstrap

One-time thread-local-storage bootstrap for the allocation tracker: allocates a TLS index and a 116-byte per-thread block, storing thread ID and a -1 sentinel. No instance fields; state is global.

Methods: `0x0058E060`


### FpuExceptionContextBuilder

FPU exception context record builder: decodes an exception-code bitmask, encodes FPU control/status flags, stores two double operands with classification flags, raises the exception, and decodes precision/rounding back into caller state.

Methods: `0x00591727`

- `this+0x00000000` `int ContextFlagWord` (read_write, DERIVED)
- `this+0x00000004` `int ExceptionTypeBits` (read_write, DERIVED)
- `this+0x00000008` `int ControlWordFlags` (read_write, DERIVED)
- `this+0x0000000C` `int StatusWordFlags` (read_write, DERIVED)
- `this+0x00000010` `double Operand1` (write, DERIVED)
- `this+0x00000020` `int Operand1Flags` (write, DERIVED)
- `this+0x00000040` `double Operand2` (write, DERIVED)
- `this+0x00000050` `int Operand2Flags` (write, DERIVED)

## Compatibility contracts

- **HudLayoutDispatchContract** — A replacement HUD layout dispatcher must select a speed-magnitude variant on global byte_7D0474 (0x0049B900 vs 0x0049B950), read engine RPM (0x0049B8F0), and call the three element renderers with the layout parameter and constants 20/68/10 in the order PositionOrderNameDisplay (0x004DB6F0), UtilityFunction_b9a0 (0x004DB9A0), sub_4DB7F0 (0x004DB7F0, fed by sub_49B7A0 over global 0x007CE234). The return of the final renderer is the dispatcher result.
- **PooledCollisionSlotContract** — A replacement slot allocator must hand out 56-byte slots from a 32-entry static pool (base unk_8AD3F8) selected by a global counter (dword_8ADAF8), post-incrementing the counter per call, and return the fixed overflow buffer unk_8ADAC0 once the counter reaches 32. Reset of the counter is outside this function.
- **SpatialCacheEntryContract** — A replacement spatial-cache population routine must build a flat entry (seed value + a3 position triple), optionally subtract a stored origin from the a3 triple when the flag byte at (this+0x4)+0x42 is set, compute the magnitude of the a4 triple, and insert into a sorted LRU array only when the magnitude is positive (threshold flt_59E440 approximately 0.0).
- **UdpStructuredSendContract** — A replacement UDP structured sender must build a header-prepended packet (length = buf[0]+buf[1]+4), populate the destination sockaddr from the 4 dwords of the address argument, send over the socket stored at this+0x93C with sendto, and return 1 on success. On failure it must dispatch on WSAGetLastError: codes 10038/10047/10049/10050/10053/10054/10058/10060 log via MutexProtectedLinkedListLookupByID with per-code strings and return 0; WSAENOBUFS (10055) goes through ThreadSafeMutexQueueWithTimedWait plus a vtable callback and returns 0.
- **MutexProtectedIntReadContract** — A replacement accessor must acquire the mutex handle at this+0xF0 with the timeout at this+0xF4 (WaitForSingleObject), read the protected int at this+0xEC, release via ReleaseMutex, and return the value. The layout is initialized by the threaded worker constructor (same offsets).
- **DrawableNodeRebuildContract** — A replacement drawable-node manager must maintain category-selected singly-linked node lists (next pointer at node+0x6C), sum only the category-4 (this+0x124) and category-2 (this+0x12C) counters into the total at this+0x60, and rebuild a flat array at this+0x138 with a 4-byte count header followed by count 56-byte slots, running per-slot cleanup before free.
- **ViewportRectContract** — A replacement viewport configuration must scale normalized width/height/travel inputs by the global screen scale (dword_8B8DD4/dword_8B8DD8) when they are <= 1.0 (or use unity scale when the a6 switch is set), convert via CRTFtol, write integer width/height/center fields and float copies, and derive half-width/half-height projection terms and aspect ratio. Bit 0x10 of the flag byte at this+0x80 controls half-width negation.
- **ThreadedWorkerLayoutContract** — A replacement threaded-worker object must install vtable off_5B8B60 at *this, capacity 64 at this+0x60, timing values 0/7.7629/90 at this+0xE0/+0xE4/+0xE8, self-link at this+0x540, final count 750 at this+0x64C, and a mutex-protected int region (mutex this+0xF0, timeout this+0xF4, value this+0xEC). The timed callback loop is installed with the mutex-pair callbacks 0x00585EA0/0x00583AA0.
- **SceneNodeCollectContract** — A replacement scene-node collector must walk the linked list at this+0x128, accept nodes whose byte at offset 0 matches (byte & 0xA0) == 0x80, store each accepted node pointer plus a reciprocal weight (1.0 / node float at node+0x50) at 56-byte stride into the caller array at a3+272 (max 8 entries), and skip collection entirely when the byte at a3+20 has bit 0x20 set or the flag dword at *(this+0x194)+0 lacks bit 0x100.

## Unresolved

- The per-call constants 20/68/10 in the HUD dispatcher are interpreted as HUD Y positions by existing analysis but not proven; the meaning of global unk_7CE234 and of byte_7D0474 in selecting the speed-magnitude variant is unestablished.
- The owning objects of most functions are UnknownObject/UNKNOWN; all class groupings are DERIVED/GUESS synthesis over field evidence, not recovered original classes. In particular HudLayoutDispatcher, SpatialLRUCache, PooledCollisionSlotAllocator, RenderObjectFactory, UIElementInitializer, ViewportProjection, UITextFieldRouter, ByteUnpackForwarder, SceneNodeCollector, ConstraintJacobianBuilder, QuaternionBasisBuilder, StructuredPacketSender, ConnectionCleanupTable, FloatAnimationThread, TlsAllocationBootstrap and FpuExceptionContextBuilder are aggregations, not proven types.
- The 116-byte combo-box state buffer slots (InitAndChain, ProtocolStateHandler) beyond their function-pointer slots, the sub-allocator vtable object at this+0x4, and the self-referential buffer+18 slot contract at caller 00516C7B are unresolved.
- The SpatialLRUCache entry layout (flat 9-float record) and the meaning of the v16/v17 raw-dword fields are unresolved; whether a4 is a vector, direction or packed record is unknown.
- The 32-entry pool element type, the purpose of the shared overflow buffer unk_8ADAC0, and the reset path of dword_8ADAF8 are unresolved.
- RenderObject type behind *this, the vtable +4 init sentinel -1, and SEH_52D8D0's role are unresolved.
- ScorecardZero target address is not in packet callee evidence; the scorecard/D3D/audio interpretation from existing prose is not adopted as fact.
- Viewport fields this+0x1C and this+0x20 (FOV/aspect denominators) are inferred from division only; a2 is declared but unused.
- DrawableObjectNodeManager case-1/case-2 counter/head pointer pairs and the per-entry cleanup semantics of EmptyStub_0170 are not covered by this packet's field evidence; the category-1 counter is excluded from the total by the raw source.
- The vtable property-set target object at this+0x1100 and the meaning of the property enums 2/3 are unresolved; the output offsets this+1302/1318/1334 have no field evidence refs.
- SceneNodeCollector collector-array structure at a3+268/+272/+284 has no named field evidence; the relationship between the traversal head (this+0x128) and the node-struct base (this+0x194) is not fully established.
- The meaning of constant 1072693248 written into the constraint matrix (identity inferred from structure only), element struct offsets 48/124, and group strides 56/132/88 are unresolved.
- WSA error string globals 0x005E624C..0x005E62BC are attributed per-code by the raw source mapping only; the write-only globals byte_FF00000000005430 and byte_FF00000000005431 look like decompiler artifacts.
- ConnectionCleanupTable node data target is opaque beyond the zeroed dwords; this+0xB04/+0xB08 roles are inferred; the htons(0) result is computed and discarded.
- ThreadedWorkerObject argument a3 is unused; dword_5B8B5C is read by packet facts but absent from the body; SEH_5837F0 exception semantics are unknown.
- FloatAnimationThread: globals flt_59E440, flt_59E5FC, dbl_59ED98, flt_5B8B58 and SEH_583D90 are flagged but absent from the raw source; the +80/+84 vtable poll status bytes are uninterpreted; the physical frame/sleep relationship of 0.0078125 (1/128) and 0.333 (1/3) is not provable from this packet.
- The decompiled accessor dereferences a pointer that would be null when the mutex wait fails, implying callers only invoke ThreadSafeIntReadWithMutex with a valid lock; the owning object is unidentified.
- TLS per-thread 116-byte block layout beyond the first two dwords (thread ID, -1 sentinel) and the consuming subsystem are unknown.
- BuildFPUExceptionContextAndRaise: exact Win32 STATUS_* names for the five decoded FPU exception codes are not confirmed; the discarded FPUStatusWordRead result is unexplained.
- Read-only globals flagged by packet facts but absent from raw source text (dbl_59E420, flt_59E43C, flt_59E440, flt_59E450, flt_59E5FC, dbl_59ED98, flt_5B8B58, dbl_59E830) are not verifiable from this packet; their role must be confirmed statically before building on them.
