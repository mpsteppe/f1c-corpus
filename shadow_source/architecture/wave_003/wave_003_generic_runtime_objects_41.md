# CRTRuntimeSupport

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Derived architecture proposal for 24 validated functions in scope generic_runtime_objects. Two packet-DERIVED owners anchor classes: 0x005932F3 owns CRTRuntimeErrorHandler and 0x005989D7 owns LocaleStreamObject. All other packet owners are UNKNOWN, so functions are grouped into conservative GUESS classes by shared globals and call topology: CRTStreamBuffer (7 stream/FILE buffer functions sharing the off_5E6748 stream array, dword_8D4920 descriptor table, unk_5E6768/unk_5E6788 sentinels and this+0x0/+0x4/+0x8/+0xC/+0x10/+0x18 buffer layout), CriticalSectionManager (0x0058DFEA/0x0058E04B over the dword_5E6C80 lazy lock table), CRTLocaleString (0x0058B465/0x00596C80/0x00591FA1 sharing the locale flag, the dword_8D5A5C interlocked counter, the dword_8D5A58 thread gate and critical-section 19), LocaleStreamObject (0x005989D7 plus three istream/ostream/streambuf SEH constructors/destructor), LocaleEncodingState (0x005991C3), and CleanupRegistrationList (five one-line wrappers funneling function addresses into BooleanToIntConversion 0x00587B3E). 0x0058FCA0 is a zero-body JUMPOUT thunk left ownerless. CRTStreamBuffer and CRTLocaleString both reach CriticalSectionManager's indexed table, making that class the shared lock primitive. Several stream offsets (+32 embedded CS, 32-byte slot stride, +28 index base, text descriptor flags) are DERIVED from decompiled arithmetic and are flagged in unresolved rather than asserted.

## Function roles

- `0x0058B465` **CRTLocaleString** — Locale-aware single-character lowercase conversion: locale flag dword_8D3F38 selects the thread-safe locale path (interlocked refcount dword_8D5A5C, optional critical-section 19, sub_58B4D4 fold) over the ASCII fast path (+32 on 'A'..'Z'); shared character normalizer for sub_5645A0/sub_566810/sub_58BCCF
- `0x0058C1B1` **CRTStreamBuffer** — Stream lock acquire dispatch: streams inside the CRT array [off_5E6748, unk_5E69A8] lock lazy-init CS index ((a1-base)>>5)+28 via CriticalSectionLazyInitEnter; external streams lock their embedded +32 CRITICAL_SECTION via EnterCriticalSection; common lock entry for the CRT stream/file wrappers
- `0x0058C203` **CRTStreamBuffer** — Stream lock release dispatch mirroring 0x0058C1B1: CRT-array streams leave lazy-init CS ((a1-base)>>5)+28 via CritSectLeave; external streams call LeaveCriticalSection on the embedded +32 CRITICAL_SECTION
- `0x0058C255` **CRTStreamBuffer** — CRT _filbuf-style buffer refill on read underflow: stream-flag validation, MemoryAllocatorInit buffer allocation, sub_58C9B4 read up to this+0x18 bytes, EOF/error flag write, text-mode descriptor copy from unk_5E7898/dword_8D4920, 512->4096 auto-grow; returns the first buffered byte and advances the read pointer
- `0x0058CF35` **CRTStreamBuffer** — CRT fputc/_flsbuf character output: read-to-write mode switch, buffer allocation when none assigned, flush when full via sub_58E22B, direct one-byte write for unbuffered streams; returns a1 on success or -1 with error bit 0x20 set
- `0x0058D04D` **CRTStreamBuffer** — printf-family format engine: byte_5B8D88 state-machine dispatch over d/i/u/o/x/X/c/s/S/C/p/n/e/E/f/F/g/G/Z conversions, va-list reads via IntPeekFromPointer, width/precision/length modifiers, float helpers off_5E6730/5E6734/5E673C, padding via LoopWithSentinelTermination and CharByCharStringProcessingWithTerminatorCheck; returns the total character count
- `0x0058DFEA` **CriticalSectionManager** — Lazy-init indexed critical-section entry: allocate a 24-byte RTL_CRITICAL_SECTION via MallocWrapperForNhMalloc, double-checked install under guard slot 17 (recursive self-call), InitializeCriticalSection, lost-race free via sub_58AA6F, fatal CRTAmsgExit(0x11) on allocation failure; every path ends by entering the table entry
- `0x0058E04B` **CriticalSectionManager** — Indexed critical-section release: selects the lock at &dword_5E6C80 + a1 and calls LeaveCriticalSection on it; release half of the enter/init helpers in the same address range
- `0x0058E41B` **CRTStreamBuffer** — Buffered I/O context init: handle validation via sub_596007, bank index 0/1 by sentinel identity unk_5E6768/unk_5E6788, open-count dword_8D3EC8 increment, 4096-byte heap buffer via MallocWrapperForNhMalloc cached in dword_8D3F50 (or 2-byte inline fallback at this+20), buffer pointers/capacity/count setup, ORs 0x1102 into the flags
- `0x0058E4A8` **CRTStreamBuffer** — Conditional buffer flush and field reset: when guard a1 is nonzero and the byte flag at a2+13 has bit 0x10 set, call BufferFlushWrite(a2), clear the 0x10 bit, and zero the dwords at a2+24/+0/+8; returns the BufferFlushWrite result on that path
- `0x0058FCA0` **UnknownObject** — Zero-body JUMPOUT thunk: unconditionally transfers control to 0x58FD11 and never continues in this frame; reached from 17 call sites, no fields/globals/callees evidenced
- `0x00591FA1` **CRTLocaleString** — Locale-sensitive string mapping (LCMapString) with automatic code-page conversion: lazy platform-mode detection via dword_8D3FBC (wide vs ANSI), MultiByteToWideChar up-conversion, LCMapStringW, sortkey 0x400 direct-to-destination path or WideCharToMultiByte conversion back; returns mapped length or 0 on failure
- `0x005932F3` **CRTRuntimeErrorHandler** — MSVC runtime error display handler: scans the (code, description) table dword_5E78C0..off_5E7950, writes the description to the stderr handle via WriteFile when a console is attached, else builds the 'Runtime Error!' message box with GetModuleFileNameA path shortening past 0x3C characters
- `0x00596C80` **CRTLocaleString** — Case-insensitive bounded string comparison: locale path folds each character pair through sub_58B4D4 under critical-section 19 with interlocked-counter/thread-gate bookkeeping; ASCII fast path manually lowercases 'A'..'Z' by +32; returns -1/0/1 against the remaining-length countdown
- `0x0059871B` **CleanupRegistrationList** — Straight-line cleanup-registration wrapper: passes the integer value of WrapperThunk (global 0x00598727) to BooleanToIntConversion for append on the global callback list; returns 0 on success / -1 on failure
- `0x0059875F` **CleanupRegistrationList** — Straight-line cleanup-registration wrapper: passes the integer value of ForwardingWrapper (global 0x0059876B) to BooleanToIntConversion for append on the global callback list; returns 0 on success / -1 on failure
- `0x005989D7` **LocaleStreamObject** — Inlined MSVC locale/stream object construction: SEH handler registration, conditional streambuf + std::ios vtable install gated by the flag at this+0x14, std::ostream vtable written into the sub-object slot from the installed vtable, conditional ObjectInitWithVTableFlagSet(this+0x8, this+0xC); returns the constructed object pointer
- `0x00598AF5` **LocaleStreamObject** — istream-derived __userpurge constructor with SEH handler: gated by a1[4] (offset 0x10) installs the primary vtable unk_5B9BC0 and the std::ios vftable, always installs the std::istream vftable at the vtable-relative slot and calls ObjectInitWithVTableFlagSet with arguments from offsets 0x8/0xC; returns the constructed object
- `0x00598B5D` **LocaleStreamObject** — istream-derived SEH constructor gated by the flag at this+0xC: installs the primary vtable unk_5B9BC0 and the std::ios vftable, writes the std::istream vftable to the vtable-relative sub-object slot, and finalizes via sub_59A8FA; returns the object pointer
- `0x00598E39` **LocaleStreamObject** — Destructor for an object wrapping a file handle and a refcounted buffer, behind a registered SEH handler: installs the most-derived vtable off_5B9BCC, closes the file at this+0x48 via FileCloseWrapperWithStatus, releases the buffer at this+0x44 (ReferenceCountDecrementWithConditionalFree then FreeWrapper_7bcf), runs null-checked virtual cleanup on this+0x4C and this+0x34, and rebases to the std::streambuf vftable
- `0x005991C3` **LocaleEncodingState** — Locale encoding-state query: reads the object pointer at this+0x50, tests encoding match via sub_587F64, reads two stream dwords via StringStreamReadWithMaskCheck, assembles a 24-byte record (zero, two stream dwords, this+0x40) and copies it into the caller buffer; sub_59942B(-1) default state on the fallback path
- `0x0059977E` **CleanupRegistrationList** — Straight-line cleanup-registration wrapper: passes the address of the no-op EmptyStub_aa60 (0x0047AA60) to BooleanToIntConversion for append on the global callback list; returns 0 on success / -1 on failure
- `0x00599802` **CleanupRegistrationList** — Straight-line cleanup-registration wrapper: passes the address of the physics cleanup routine PhysicsBlockWrapper (0x0059980E, runs CDestructorWithVTableChain) to BooleanToIntConversion for append on the global callback list; returns 0 on success / -1 on failure
- `0x005998CF` **CleanupRegistrationList** — Straight-line cleanup-registration wrapper: passes the address of the stdcall trampoline TrampolineToFUN005998E5 (0x005998DB, four-argument forwarder to VTableSetSubCall) to BooleanToIntConversion for append on the global callback list; returns 0 on success / -1 on failure

## Proposed classes

### CRTStreamBuffer

CRT FILE/stream buffer object operations reconstructed from seven packet functions: stream lock acquire/release dispatch (0x0058C1B1, 0x0058C203), read-underflow refill (0x0058C255), character output (0x0058CF35), the printf-family format engine (0x0058D04D), buffered I/O context init (0x0058E41B) and conditional flush/reset (0x0058E4A8). All treat `this` as a CRT stream struct with read pointer at +0x0, byte count +0x4, buffer base +0x8, flags +0xC, OS file handle +0x10 and buffer size +0x18, referencing the CRT global stream array off_5E6748..unk_5E69A8 and the dword_8D4920 descriptor table.

Methods: `0x0058C1B1`, `0x0058C203`, `0x0058C255`, `0x0058CF35`, `0x0058D04D`, `0x0058E41B`, `0x0058E4A8`

- `this+0x00000000` `pointer readPointer` (read_write, DERIVED)
- `this+0x00000004` `int bufferByteCount` (read_write, DERIVED)
- `this+0x00000008` `pointer bufferBase` (read_write, DERIVED)
- `this+0x0000000C` `int streamFlags` (read_write, DERIVED)
- `this+0x00000010` `int fileHandle` (read, DERIVED)
- `this+0x00000018` `int bufferSize` (read_write, DERIVED)
- `obj+0x00000000` `byte bufferedByte` (read, DERIVED)

### CriticalSectionManager

Indexed lazy-initialized critical-section primitive over the global lock-pointer table dword_5E6C80: enter (0x0058DFEA) lazily allocates and initializes a 24-byte RTL_CRITICAL_SECTION under a double-checked lock guarded by recursive slot-17 entry and release via CritSectLeave (0x0058E04B). The table is the shared serialization primitive for the CRT stream locks and the locale paths.

Methods: `0x0058DFEA`, `0x0058E04B`


### CRTLocaleString

Locale-aware character/string helpers sharing the global locale flag, the dword_8D5A5C interlocked reference counter, the dword_8D5A58 thread gate and critical-section 19: single-character lowercase conversion (0x0058B465), case-insensitive bounded comparison (0x00596C80), and LCMapString mapping with code-page conversion (0x00591FA1). All fold characters through sub_58B4D4 on the locale path with an ASCII 'A'..'Z'+32 fast path.

Methods: `0x0058B465`, `0x00596C80`, `0x00591FA1`

- `this+0x00000000` `char pointer stringData` (read, DERIVED)

### CRTRuntimeErrorHandler

Microsoft Visual C++ runtime error display handler (0x005932F3, packet-DERIVED owner CRTErrorHandler): scans the (error code, description) table rooted at dword_5E78C0 with sentinel off_5E7950 and parallel description table off_5E78C4, then either writes to the stderr handle or shows the titled 'Runtime Error!' message box.

Methods: `0x005932F3`


### LocaleStreamObject

MSVC locale/stream object construction and destruction: the packet-DERIVED constructor 0x005989D7 plus three GUESS siblings sharing the std::ios/std::istream/std::ostream/std::streambuf vtable globals (0x005B9BB4, 0x005B9BA4, 0x005B9BAC, 0x005B9BB8, 0x005B9BC0, 0x005B9BCC, 0x005B9C04) and the ObjectInitWithVTableFlagSet / sub_59A8FA finalizers: istream constructor 0x00598AF5, SEH constructor 0x00598B5D and the file-handle/buffer destructor 0x00598E39.

Methods: `0x005989D7`, `0x00598AF5`, `0x00598B5D`, `0x00598E39`

- `this+0x00000010` `int initFlag` (read, DERIVED)
- `this+0x00000014` `int constructionFlag` (read, DERIVED)

### LocaleEncodingState

Locale/encoding state query (0x005991C3): reads the encoding-state object pointer at this+0x50, validates the encoding parameters through sub_587F64, reads two dwords through StringStreamReadWithMaskCheck, and copies a 24-byte encoding record (zero header + two stream dwords + the value at this+0x40) into the caller buffer, falling back to a default state from sub_59942B(-1).

Methods: `0x005991C3`

- `this+0x00000040` `int encodingStateValue` (read, DERIVED)
- `this+0x00000050` `pointer encodingStateObjectPtr` (read, DERIVED)

### CleanupRegistrationList

Straight-line atexit-style cleanup-registration wrappers: each reads a code address (global callback target) and hands it to BooleanToIntConversion (0x00587B3E), which under a critical section appends the pointer to a global growable callback list and returns 0 on success / -1 on failure. Wrappers: 0x0059871B, 0x0059875F, 0x0059977E, 0x00599802, 0x005998CF.

Methods: `0x0059871B`, `0x0059875F`, `0x0059977E`, `0x00599802`, `0x005998CF`


## Compatibility contracts

- **CRTStreamArrayLayout** — The stream lock/unlock dispatchers (0x0058C1B1, 0x0058C203) classify a stream pointer against the CRT global stream array [off_5E6748, unk_5E69A8]: in-array streams use the lazy-init indexed critical section ((a1-base)>>5)+28; out-of-array streams lock an embedded CRITICAL_SECTION at +32. A replacement executable must preserve the array bounds, the 32-byte slot stride, the +28 index base and the +32 embedded lock offset.
- **CRTStreamDescriptorTable** — The stream buffer functions (0x0058C255, 0x0058CF35) resolve text-mode descriptors as dword_8D4920[handle>>5] + 36*(handle&0x1F) with the default descriptor unk_5E7898 for handle -1, and drive the flags at this+0xC (0x83 write-capable, 0x40 EOF, bit 0 read-mode, 0x10 own-buffer, 0x10C buffer established). A replacement must keep the descriptor indexing and flag bit meanings.
- **BufferedIOContextLayout** — BufferedIOContextInit (0x0058E41B) uses a 4096-byte heap buffer cached in dword_8D3F50 by bank (sentinel identity unk_5E6768=bank 0, unk_5E6788=bank 1) with a 2-byte inline fallback at this+20, writes buffer pointers this+0x0/+0x8, capacity this+0x18, remaining count this+0x4, ORs 0x1102 into this+0xC, and increments the open counter dword_8D3EC8. A replacement must preserve the cache, fallback and flag constants.
- **LocaleCharFoldContract** — Locale-aware case folding (0x0058B465, 0x00596C80) must preserve the ASCII fast path ('A'..'Z' +32, unchanged otherwise) and the locale path that folds each character through sub_58B4D4 under critical-section 19, serialized by the interlocked counter dword_8D5A5C and the thread gate dword_8D5A58; the compare returns -1/0/1 bounded by the maximum length.
- **RuntimeErrorTableLayout** — ShowRuntimeErrorWithCodeLookup (0x005932F3) scans the (error code, description) pair table rooted at dword_5E78C0 in 2-dword steps to the sentinel off_5E7950, fetching the description from the parallel table off_5E78C4; console path writes via GetStdHandle/WriteFile, message-box path uses GetModuleFileNameA with a 260-char buffer and path shortening beyond 0x3C characters, and code 252 suppresses display. A replacement must keep the table pair and sentinel.
- **LazyCriticalSectionTable** — CriticalSectionLazyInitEnter (0x0058DFEA) treats dword_5E6C80 as an array of lock pointers indexed by slot a1; slots are lazily allocated (24 bytes) and initialized under a double-checked guard (recursive slot 17) and every enter is paired with a CritSectLeave (0x0058E04B) on the same slot. A replacement must reproduce the slot indexing and the enter/leave pairing.

## Unresolved

- The exact stream type behind `this` in 0x0058C255/0x0058CF35/0x0058E41B (CRT FILE* vs an internal stream struct) is not established by the packet; the buffer layout (+0/+4/+8/+0xC/+0x10/+0x18) is DERIVED from decompiled field usage.
- The +28 index base and the 32-byte slot stride for CRT-array streams in 0x0058C1B1/0x0058C203 are DERIVED from the shift/offset arithmetic, not independently proven.
- Critical-section identifier 19 is a literal not mapped to a named resource in the packet.
- Semantics of the interlocked counter dword_8D5A5C and the thread gate dword_8D5A58 (thread/critical-section bookkeeping) are inferred and unverified.
- The exact locale-aware mapping performed by sub_58B4D4 is external to this packet.
- Identity and semantics of sub_58AA6F (lost-race free/cleanup) are not established by this packet.
- The dword_8D3F50 buffer-cache lifecycle (allocation/reuse/free) outside 0x0058E41B is not visible in this packet.
- 0x0058FCA0 is a zero-body JUMPOUT thunk whose target 0x58FD11 has no packet entry; whether it is a tail call, jump-table dispatch or plain JMP cannot be determined, and its owner is unknown.
- The character-classification table aIsprocessorfea used by 0x0058D04D has no packet evidence entry and its backing address is unverified.
- jpt_58D0BB (global 0x0058D76E) is the compiler-generated switch jump table for the 0x0058D04D state dispatch; it has no direct source reference.
- sub_594FF0 and sub_596100 are called as 64-bit divide/modulo helpers by 0x0058D04D, but their exact semantics are only inferred from usage.
- The SEH exception type descriptors 0x0059D23E, 0x0059D286, 0x0059D2AA, 0x0059D2EF participate in the LocaleStreamObject frames but are not referenced by name in the visible constructor/destructor bodies.
- The a1-relative stack slots (a1-20/-16/-4/-5/-1) written by the LocaleStreamObject constructors belong to inlined caller frames; the exact object layout they describe is not recoverable from these functions alone.
- The this+0x44 refcounted buffer, the this+0x48 file-open flag and the this+0x4C/this+0x34 sub-object virtual-cleanup slots in 0x00598E39 are unproven beyond ordering evidence.
- In 0x005991C3 this+0x50 doubles as both the masked-read stream and the encoding-state object pointer; the exact class contract is not recoverable from this packet alone.
- Whether the CleanupRegistrationList callbacks fire through atexit-style teardown, a destructor chain, or manual dispatch is not established by this packet.
- BooleanToIntConversion (0x00587B3E) returns 0 on successful append and -1 on failure per the wrapper prose; this contract is DERIVED and unverified.
- EnterCriticalSection/LeaveCriticalSection/InitializeCriticalSection and the other Win32 entry points are indirect global function pointers (0x0059E16C/0x0059E170/0x0059E174); their import bindings are assumed, not proven.
