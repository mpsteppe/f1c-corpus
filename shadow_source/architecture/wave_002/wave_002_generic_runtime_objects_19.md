# RuntimeObjectInfrastructure

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

DERIVED reconstruction of 26 runtime helper functions. Cluster A (network teardown): 0x0057FBE0 drains two mutex-protected linked lists, runs a subsystem cleanup helper, invokes the vtable+48 virtual cleanup, and conditionally calls WSACleanup gated on the winsockInitialized flag at this+0xA74. Cluster B (multi-block bitfield): 0x00586800 encodes four bitfield blocks into a bitmap array using a metadata table at this+0x1C, 0x00586AA0 resets the same state, and 0x00586F40 builds entry-count-clipped masks; they share the bitmap base at this+0x14 and index fields at this+0x34..0x44, and use 0x00585E80 as the bit-index-to-mask utility. Cluster C (stream I/O): 0x00587CA0, 0x00587D02, 0x00587F64, 0x00588678, 0x005887B1 and 0x0058ACE6 all serialize through StreamBufferLockViaCriticalSection (0x0058C1B1) / AddressRangeCriticalSectionLeave (0x0058C203), forming a single locked file/stream contract. Cluster D (string helpers): bounded copy (0x00587DD0), bounded compare (0x00588640), delimiter tokenizer with TLS scan state (0x005897CA), locale/ASCII uppercase (0x00589901), masked stream read (0x0058801D), formatting wrappers (0x005887B1, 0x0058969D). Cluster E (Win32/D3D/Winsock surface): directory create (0x00589671), read-only toggle (0x0058BA36), import thunks WSAStartup (0x0059869C) and Direct3DCreate8 (0x0059B250), plus small helpers 0x00587B3E, 0x00587DB0, 0x00587F59, 0x00595058 and the no-op SEH stub 0x0058A5D8. No CONFIRMED claim is made about original source names or class layout.

## Function roles

- `0x0057FBE0` **NetworkSessionResources** — network subsystem teardown: drain/release two mutexes, destroy linked lists, run subsystem cleanup helper, invoke vtable+48 virtual cleanup, conditionally WSACleanup
- `0x00585E80` **FreeRuntimeHelper** — bit-index to byte-offset/mask conversion utility: writes a1>>3 through a2, computes 1<<(a1&7), stores through a3 and returns it
- `0x00586800` **MultiBlockBitfieldState** — encode up to four bitfield blocks into a bitmap byte array using per-block metadata and bit set/clear primitives
- `0x00586AA0` **MultiBlockBitfieldState** — reset/initialize multi-block bitmap state: clear first dword, process four bitmap blocks, final BitfieldEncoder call, SimpleSetter on this+0x8, zero trailing dwords
- `0x00586F40` **MultiBlockBitfieldState** — entry-count bitmask helper: AND a caller-supplied mask with (1<<count)-1 built from the 16-bit count in table entry a2 of the table at this+0x8
- `0x00587B3E` **FreeRuntimeHelper** — boolean-to-integer conversion helper: normalize sub_587AC0(a1) to true->0 / false->-1 and return it
- `0x00587CA0` **FileStream** — critical-section-protected read-until-newline into a caller buffer with refill path
- `0x00587D02` **FileStream** — flag-guarded locked file close: skip close and return -1 when the 0x40 bit at this+0xC is set, otherwise lock, CRT-close, unlock
- `0x00587DB0` **FreeRuntimeHelper** — thin cdecl delegation thunk: forward a1,a2 plus fixed literal 64 to sub_587D7F and return its result
- `0x00587DD0` **FreeRuntimeHelper** — bounded NUL-terminated string copy with destination zero-padding and dword fast path
- `0x00587F59` **FreeRuntimeHelper** — byte-string pass-through wrapper: return sub_587ECE(a1) unchanged
- `0x00587F64` **FileStream** — critical-section-protected file position query wrapping FileTellSeekPositionQuery
- `0x0058801D` **FileStream** — stream read wrapper: store FileIOThreeStepSequence 8-byte result at a2, report 0 when (a2[4]&a2[0]) != -1 else -1
- `0x00588640` **FreeRuntimeHelper** — bounded case-sensitive byte-string compare with normalized -1/0/1 verdict
- `0x00588678` **FileStream** — critical-section-protected file read wrapper around sub_5886A7
- `0x005887B1` **FileStream** — critical-section-protected varargs formatted write: lock, capture state, format, conditionally clear fields, unlock
- `0x00589671` **FreeRuntimeHelper** — CreateDirectoryA wrapper returning 0 on success and -1 via ErrorIDLookupTable on failure
- `0x0058969D` **FreeRuntimeHelper** — capacity-guarded null-terminated varargs format: format, detect capacity underflow, route overlong result to sub_58CF35 or NUL-terminate in place
- `0x005897CA` **FreeRuntimeHelper** — delimiter-set tokenizer with 32-byte delimiter bitmap and thread-local scan position at TLS+24
- `0x00589901` **FreeRuntimeHelper** — locale-aware or plain ASCII in-place uppercase string normalization returning the original pointer
- `0x0058A5D8` **FreeRuntimeHelper** — compiler-emitted SEH handler registration stub: bare RETN with no side effects
- `0x0058ACE6` **FileStream** — critical-section-protected stream size query wrapping sub_58AD08
- `0x0058BA36` **FreeRuntimeHelper** — toggle file read-only attribute (bit 0) via GetFileAttributesA/SetFileAttributesA with GetLastError + ErrorIDLookupTable on failure
- `0x00595058` **FreeRuntimeHelper** — bit-field mask merge: v2 = (a2&a1) | (~a2&sub_5950A3()), persist via sub_595135(v2), return v2
- `0x0059869C` **ExternalImportThunk** — Winsock2 import thunk: forward both arguments to __imp_WSAStartup and return its result
- `0x0059B250` **ExternalImportThunk** — D3D8 import thunk: forward argument to imported Direct3DCreate8 entry point and return its result

## Proposed classes

### NetworkSessionResources

Network subsystem object holding two mutex-protected linked lists, mutex handles with per-mutex timeouts, and a Winsock-initialized flag; torn down by CleanupNetworkResources which also dispatches a virtual cleanup at vtable+48.

Methods: `0x0057FBE0`

- `this+0x00000000` `void** vtable` (read, GUESS)
- `obj+0x00000030` `void(*)(void*) virtualCleanup` (read, GUESS)
- `this+0x00000A74` `int winsockInitialized` (read_write, DERIVED)
- `this+0x00000AD8` `HANDLE firstMutexHandle` (read, DERIVED)
- `this+0x00000ADC` `unsigned int firstMutexTimeout` (read, DERIVED)
- `this+0x00000AF4` `HANDLE secondMutexHandle` (read, DERIVED)
- `this+0x00000AF8` `unsigned int secondMutexTimeout` (read, DERIVED)

### MultiBlockBitfieldState

State for a multi-block bitfield: a bitmap byte array at this+0x14, a block metadata table at this+0x1C, per-block table indices at this+0x34/0x38/0x3C/0x40/0x44, a bitmap entry-count table at this+0x8, and trailing zeroed dwords at this+0x48/0x4C/0x50. Encoded or reset by the two multi-block functions using shared bitmask primitives.

Methods: `0x00586800`, `0x00586AA0`, `0x00586F40`

- `this+0x00000000` `unsigned int firstDword` (write, DERIVED)
- `this+0x00000008` `const BitmapEntry* bitmapEntryTable` (read, DERIVED)
- `this+0x00000014` `unsigned char* bitmapBytes` (read_write, DERIVED)
- `this+0x0000001C` `const BlockMetadata* blockMetadataTable` (read, DERIVED)
- `this+0x00000034` `int blockIndexA` (read, DERIVED)
- `this+0x00000038` `int blockIndexB` (read, DERIVED)
- `this+0x0000003C` `int blockIndexC` (read, DERIVED)
- `this+0x00000040` `int blockIndexD` (read, DERIVED)
- `this+0x00000044` `int blockIndexE` (read, DERIVED)
- `this+0x00000048` `int trailingDwordA` (write, DERIVED)
- `this+0x0000004C` `int trailingDwordB` (write, DERIVED)
- `this+0x00000050` `int trailingDwordC` (write, DERIVED)

### FileStream

Stream/file object serialized by a critical section (acquired via StreamBufferLockViaCriticalSection 0x0058C1B1, released via AddressRangeCriticalSectionLeave 0x0058C203). Carries a current-position pointer at +0x0 (evidence: FileReadUntilNewline) and a close-guard flag dword at +0xC (evidence: closeFileWithLock). The +0x0 and +0xC offsets come from two different stream-typed arguments and common ownership is NOT proven; both fields are GUESS.

Methods: `0x00587CA0`, `0x00587D02`, `0x00587F64`, `0x0058801D`, `0x00588678`, `0x005887B1`, `0x0058ACE6`

- `this+0x00000000` `char* streamPosition` (read_write, GUESS)
- `this+0x0000000C` `int closeGuardFlags` (read_write, GUESS)

## Compatibility contracts

- **Win32_Import_Table** — A replacement executable must preserve loader resolution of the import pointers used by these helpers: GetFileAttributesA (0x0059E0D8), SetFileAttributesA (0x0059E17C), GetLastError (0x0059E188), WaitForSingleObject (0x0059E1A0), ReleaseMutex (0x0059E1A4), CreateDirectoryA (0x0059E1EC), InterlockedIncrement (0x0059E238) / InterlockedDecrement (0x0059E234), WSAStartup (0x0059E314), WSACleanup (0x0059E318), Direct3DCreate8 (0x0059E370).
- **StreamCriticalSection** — All file/stream operations serialize through StreamBufferLockViaCriticalSection (0x0058C1B1) and AddressRangeCriticalSectionLeave (0x0058C203). A replacement stream layer must preserve this single-lock contract for line reads, closes, position queries, reads, formatted writes and size queries.
- **StringTerminationAndBounds** — String helpers guarantee NUL-termination and bounded writes: boundedStringCopy pads and terminates within its count, the formatted wrappers NUL-terminate in place and route overlong output to sub_58CF35, and the delimiter tokenizer truncates tokens with a NUL at the delimiter.
- **Win32ErrorReturnCode** — Win32 wrapper helpers return 0 on success and -1 on failure, mapping GetLastError through ErrorIDLookupTable (0x0058AF5C); callers depend on this 0/-1 boolean convention (CreateDirectoryAWrapper, ToggleFileReadOnlyAttributeViaWin32API).
- **WinsockSessionFlag** — Network teardown is gated on the winsockInitialized flag at this+0xA74: WSACleanup is invoked only when the flag is set, and the flag is then cleared to 0. A replacement must preserve this guard to avoid tearing down a Winsock session that was never started.

## Unresolved

- Class identity of the network teardown object and the exact virtual method at vtable+48 are unresolved; the vtable pointer base at this+0x0 carries no type evidence.
- Which specific linked lists correspond to the mutex pairs at this+0xAD8 / +0xAF4 is inferred only from call ordering and matching mutex-protected destruction helpers.
- FileStream aggregates offsets +0x0 (stream position, from FileReadUntilNewline's a3[0]) and +0xC (close-guard flag, from closeFileWithLock's a1) which come from different stream-typed arguments; common ownership is NOT proven, so the class and both fields are GUESS.
- StringStreamReadWithMaskCheck (0x0058801D) is grouped with FileStream by stream-operation affinity but is not lock-wrapped like the other FileStream methods.
- The multi-block bitfield metadata layout (start-position word at +0, bit-count word at +2 per 4-byte entry in the table at this+0x1C) is DERIVED from the raw access pattern and not independently documented.
- The roles of BitfieldEncoder (0x00586FA0), ComputeBitmaskFromBitmapEntryCount output, SimpleSetter_7500 (0x00587500) and BitSetClearOperation (0x00586F70) depend on callees outside this packet.
- sub_587AC0 (behind BooleanToIntConversion) has unknown identity; the true->0 / false->-1 mapping is DERIVED from literal arithmetic.
- Semantics of the formatting chain sub_58D04D / sub_58E41B / sub_58E4A8 / sub_58CF35 (formatter, state capture, conditional field clear, exhausted-buffer path) are not evidenced inside this packet.
- Semantics of the locale-conversion chain sub_591FA1 (code page 0x200) / sub_58FCA0 / sub_58AA6F and the caller-visible contract of returning the original pointer are not established.
- SEHHandlerInit (0x0058A5D8) reduces to a bare RETN; whether it originally registered a functional SEH handler is unrecoverable from this packet.
- The purpose of ErrorIDLookupTable (0x0058AF5C) on failure paths (log, message, or abort) is unknown.
- The caller contract of the a2 sign convention in ToggleFileReadOnlyAttributeViaWin32API (non-negative sets, negative clears read-only) is not established.
- The thread-local slot at TLS+24 used as persistent tokenizer scan state has unverified semantics.
- The refill counter a3[1] (offset +4 of the stream object) referenced by FileReadUntilNewline is not present in the packet field evidence set; the stream struct layout is unconfirmed.
- ExternalImportThunk and FreeRuntimeHelper are role-ownership labels, not reconstructed classes; the owning objects of the free helpers remain UNKNOWN.
