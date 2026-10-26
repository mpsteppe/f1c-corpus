# CrtRuntimeSupport

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Twenty-five runtime-support functions reconstructed as CRT-style infrastructure. A BufferedStream type (fields +0x0 pointer, +0x4 count, +0x8 data start, +0xC flags, +0x10 OS handle) is served by StreamGetChar, BufferFlushWrite, FileStreamClose, StringWriteToFile, the lock/validate/unlock wrapper, and the FdopenWithMode factory, all bracketed by a common critical-section lock/unlock pair. A CrtHeapAllocator layer dispatches on an OS-version code (dword_8D4908) between region/large-pool (value 3), block-pool (value 2) and raw HeapAlloc/HeapReAlloc/HeapSize strategies, with an OOM-callback retry gated by a debug-heap flag (dword_8D41B0); ValidateAllHeapSlots sweeps the thread-heap slot array as an integrity check. CriticalSectionEnter/Leave are dispatcher helpers routing low indices to a lazy-init array and high indices to the imported Enter/LeaveCriticalSection. Fatal error/exit handling (CRTAmsgExit, ErrorHandlerWithOptionalCleanupThenExit) share the error-display flag dword_8D3EBC and cleanup call, terminating with 0xFF. TLS block access via +2/+3 DWORD getters feeds path resolution and file I/O error slots. TimeSecondsToBrokenDownTime applies timezone bias and DST handling above a 259200-second threshold. All proposals are DERIVED; ownership of every function is UNKNOWN at the packet level.

## Function roles

- `0x00589E6C` **TimeConverter** — Converts elapsed seconds or absolute timestamps to a broken-down time structure with timezone bias and DST adjustment; thresholds at 259200 seconds, DST marker at structure index 8.
- `0x00589FCC` **BufferedStream** — Reads one buffered byte from a stream under the critical section, refilling via sub_58C255 on underflow; decrements remaining count at +0x4 and advances the pointer at +0x0.
- `0x00589FFD` **BufferedStream** — Locks a stream buffer, validates it as a memory block via MemoryBlockValidationCheck, and unlocks; null argument short-circuits through sub_58A0BF.
- `0x0058A05A` **BufferedStream** — Flushes buffered bytes to the OS file handle when write mode and initialization flags are set; resets buffer pointers, sets error flag on partial/failed write, returns -1 on failure.
- `0x0058A0BF` **CrtHeapAllocator** — Sweeps the thread-heap slot array (dword_8D4A24 / dword_8D5A40) and validates 0x83-flagged entries under per-slot and global critical sections; counts clean slots in mode 1, reports failed writable streams in mode 0.
- `0x0058A2A6` **CrtErrorHandler** — CRT _amsg_exit-style error-exit handler: optionally displays the error dialog when dword_8D3EBC==1, runs cleanup via sub_5932F3, then calls the registered exit function off_5E65B0 with 0xFF.
- `0x0058A2CB` **CrtErrorHandler** — Fatal error handler: displays message when dword_8D3EBC==1, runs cleanup via sub_5932F3, then terminates via ExitProcess with exit code 0xFF; __noreturn.
- `0x0058A6EB` **ForwardCallbackDriver** — Generic forward iterator invoking a __thiscall callback a4(a1) exactly a3 times, advancing the element pointer by stride a2; returns the final counter.
- `0x0058A947` **CrtHeapAllocator** — nh_malloc entry: rejects sizes above 0xFFFFFFE0, attempts low-level allocation sub_58A973, retries after the GlobalCallbackDispatcherWithNullCheck OOM callback when the retry flag is set.
- `0x0058A973` **CrtHeapAllocator** — 16-byte-aligned allocation wrapper dispatching on dword_8D4908: code 3 sub-allocates small blocks via sub_59416F under critical section 9, code 2 pulls blocks from the pool via sub_594C12, otherwise HeapAlloc; every pool path falls back to HeapAlloc.
- `0x0058AB58` **CrtHeapAllocator** — Counted allocator (count * element size): rounds to a 16-byte boundary, dispatches through dword_8D4908 pool paths, zero-fills successful pool allocations via sub_58BB10, falls back to HeapAlloc(hHeap, 8u), and retries through the OOM callback when dword_8D41B0 is set.
- `0x0058AC95` **SafeStringFormatter** — Safe string formatting wrapper: sets a size counter, formats a2/a3 via sub_58D04D into the a1 buffer, then NUL-terminates or takes the sub_58CF35 failure path when the counter is exhausted.
- `0x0058AE69` **BufferedStream** — CRT _fdopen-style stream factory: validates the open-file slot against uNumber, allocates a stream via sub_58C5AC, parses the mode string, ORs default flags dword_8D41BC, records the descriptor and increments the open-file count.
- `0x0058AFCF` **TlsBlockAccess** — Returns the TLS block base advanced by 2 DWORDs (8 bytes), obtained via TLSValueRetrievalWithInit; used by file and path error-slot writers.
- `0x0058AFD8` **TlsBlockAccess** — Returns the TLS block base advanced by 3 DWORDs (12 bytes), obtained via TLSValueRetrievalWithInit.
- `0x0058AFE1` **BufferedStream** — CRT fclose-style stream close: reads the file-handle index at +0x10, locks, flushes via BufferFlushWrite, clears stream flags at +0xC, resets the per-handle buffer descriptor, closes the OS handle via sub_58C724, releases the critical section.
- `0x0058B130` **MemoryCopyRoutine** — memmove-style copy with overlap detection: backward copy when the destination lies inside the source range, otherwise DWORD-aligned forward bulk copy with jump-table-dispatched alignment and byte-tail completion; returns the destination address.
- `0x0058B4D4` **CharacterCaseConverter** — Character lowercase conversion: multibyte-encoding-aware path via sub_591FA1 when dword_8D3F38 is set, else ASCII fast path adding 32 to uppercase letters.
- `0x0058B5D4` **CrtHeapAllocator** — Reallocation wrapper dispatching on dword_8D4908: code 3 region-tracked realloc, code 2 pool-allocator realloc, otherwise raw HeapReAlloc; NULL input allocates, zero size frees, OOM callback retry when dword_8D41B0 is set.
- `0x0058B903` **PathResolver** — Critical-section-guarded entry into path resolution: enters lazily-initialized section key 12, delegates the query to sub_58B92A, leaves the section, returns the query result.
- `0x0058B92A` **PathResolver** — Resolves a file path to its absolute form with a drive-letter prefix and ':.\' relative prefix via GetFullPathNameA, or the current directory via GetCurrentDirectoryA; writes TLS error codes 12/13/15/34 on failure paths.
- `0x0058BABB` **BufferedStream** — Writes a length-prefixed string into a buffered stream under the critical section: measures via Strlen, locks, writes via sub_5886A7, conditionally clears stream fields, unlocks, returns 0 on full write else -1.
- `0x0058BB68` **CrtHeapAllocator** — Queries the usable size of an allocation: dword_8D4908 code 3 reads the region header via sub_593E1B, code 2 scales the pool block index via MemoryRegionValidationHeapLookup, otherwise falls back to HeapSize; runs under critical section 9.
- `0x0058C1E0` **CriticalSectionManager** — Critical-section enter dispatcher: index >= 20 calls the imported EnterCriticalSection at base+32, otherwise delegates to CriticalSectionLazyInitEnter(index + 28).
- `0x0058C232` **CriticalSectionManager** — Critical-section leave dispatcher: index >= 20 calls the imported LeaveCriticalSection at base+32, otherwise delegates to CritSectLeave(index + 28).

## Proposed classes

### BufferedStream

CRT FILE-style buffered stream: byte reads with underflow refill, buffered flush to the OS handle, stream close, string writes, stream factory with mode parsing, and lock/validate/unlock wrappers, all protected by a shared critical-section protocol.

Methods: `0x00589FCC`, `0x00589FFD`, `0x0058A05A`, `0x0058AE69`, `0x0058AFE1`, `0x0058BABB`

- `this+0x00000000` `unsigned char * currentBufferPointer` (read_write, DERIVED)
- `this+0x00000004` `int32 bufferRemainingCount` (read_write, DERIVED)
- `this+0x00000008` `unsigned char * bufferDataStart` (read, DERIVED)
- `this+0x0000000C` `uint32 streamFlags` (read_write, DERIVED)
- `this+0x00000010` `int32 osFileHandle` (read_write, DERIVED)

### CrtHeapAllocator

Heap allocation, reallocation, block-size query and heap-slot validation layer dispatching on an OS-version code (dword_8D4908) between region/large-pool, block-pool and raw HeapAlloc/HeapReAlloc/HeapSize strategies, with an out-of-memory callback retry gated by the debug-heap flag.

Methods: `0x0058A0BF`, `0x0058A947`, `0x0058A973`, `0x0058AB58`, `0x0058B5D4`, `0x0058BB68`


### CriticalSectionManager

Dispatcher helpers that route critical-section index below 20 through the lazy-init array and index 20+ to the imported Enter/LeaveCriticalSection at base+32.

Methods: `0x0058C1E0`, `0x0058C232`


### TimeConverter

Converts seconds or absolute timestamps into a broken-down time structure with timezone bias and daylight-saving adjustment, splitting at a 259200-second threshold.

Methods: `0x00589E6C`

- `this+0x00000000` `int32 inputTimeValue` (read, DERIVED)

### TlsBlockAccess

Provides per-thread data block base pointers advanced by fixed DWORD offsets for error-slot and file-state access.

Methods: `0x0058AFCF`, `0x0058AFD8`


### PathResolver

Resolves file paths to absolute form with drive-letter prefixing and current-directory fallback, reporting failures through TLS error slots; entered under a critical section.

Methods: `0x0058B903`, `0x0058B92A`


### MemoryCopyRoutine

memmove-style copy with overlap detection, aligned bulk copying and jump-table-dispatched alignment and tail completion.

Methods: `0x0058B130`

- `this+0x00000000` `uint8 destinationByte0` (write, DERIVED)
- `this+0x00000001` `uint8 destinationByte1` (write, DERIVED)
- `this+0x00000002` `uint8 destinationByte2` (write, DERIVED)

### CharacterCaseConverter

Converts a character to lowercase, using a multibyte-encoding conversion path when enabled or a plain ASCII fast path otherwise.

Methods: `0x0058B4D4`


### SafeStringFormatter

Size-limited safe string formatting with NUL termination and a failure path when the format size counter is exhausted.

Methods: `0x0058AC95`


### CrtErrorHandler

CRT error/exit handling: optional error dialog, cleanup, and process or exit-function termination with code 0xFF.

Methods: `0x0058A2A6`, `0x0058A2CB`


### ForwardCallbackDriver

Generic forward iteration over a caller-supplied element array, invoking a __thiscall callback per element with a fixed stride.

Methods: `0x0058A6EB`


## Compatibility contracts

- **NhMallocSizeGuard** — Allocation requests larger than 0xFFFFFFE0 return NULL without attempting an allocation (0x0058A947); a replacement allocator must preserve this guard.
- **OsVersionPoolDispatch** — Allocation, reallocation and size queries dispatch on dword_8D4908: 3 uses region/large-pool paths (sub_59416F family), 2 uses the block-pool path (sub_594C12 family), anything else uses raw HeapAlloc/HeapReAlloc/HeapSize; callers that depend on block layout require the dispatch to be preserved.
- **BufferedStreamLockProtocol** — Stream operations (byte read, flush, write, close) must bracket buffer access with the enter (0x0058C1B1) / leave (0x0058C203) critical-section pair so concurrent file I/O remains serialized.
- **BufferedStreamLayout** — Stream struct offsets evidenced: +0x0 current pointer, +0x4 remaining count, +0x8 data start, +0xC flags, +0x10 OS handle. Field +0x4 has conflicting interpretations (remaining count vs buffer start) pending runtime evidence.
- **FatalErrorExitContract** — Fatal error paths display a message when dword_8D3EBC==1, run cleanup via sub_5932F3, then terminate with exit code 0xFF through either the registered exit function off_5E65B0 or ExitProcess; termination must never return to the caller.
- **TlsErrorSlotReporting** — Path resolution reports failures through per-thread TLS slots: validation failure writes codes 15 and 13, too-small caller buffer writes 34, allocation failure writes 12; callers read these via the TLSOffsetGetter family.
- **TimeBreakdownThreshold** — Time conversion treats inputs above 259200 seconds as absolute timestamps (subtract timezone bias dword_5E7758, apply DST via dword_5E775C/dword_5E7760, flag index 8) and smaller values as time-of-day offsets normalized by mod 60/60/24.
- **CriticalSectionIndexProtocol** — Critical-section index below 20 routes through the lazy-init array (slot at index+28); index >= 20 routes to the imported Enter/LeaveCriticalSection on the LPCRITICAL_SECTION at base+32.

## Unresolved

- BufferedStream field +0x4 is read as a remaining-byte count by StreamGetChar (decrement, underflow refill) but as a buffer-start pointer reset by BufferFlushWrite; the packet offers no single interpretation and the conflict needs runtime evidence.
- The broken-down time structure produced by sub_592787 (indices 0-8) is not covered by any packet field evidence ref; only the input field this+0x0 is evidenced.
- dword_8D4908 values 2/3 (OS-version pool discriminator) and dword_8D41B0 (debug heap flag) semantics are DERIVED from the surrounding corpus fill, not packet-confirmed.
- The contracts of the pool/region routines sub_59416F, sub_594C12, sub_593E1B, sub_593E46, sub_594624, sub_594F3E, sub_594B76 and sub_594BCD are opaque at this level.
- SEH-related globals (ScriptFrameProcessor 0x0058895C and stru_5B8CB8 / 5B8CD0 / 5B8D00 / 5B8D18 / 5B8D30) and the TLS guard bytes 0xFF00000000001692 / 695 / 69B do not appear in the raw decompilations; they belong to surrounding SEH frames.
- Jump-table target mappings inside MemoryCopyWithOverlapHandling (jpt_58B18C / jpt_58B165 / jpt_58B314 / jpt_58B2F2) are assembly-level and not recoverable from the C listing; the listed loc_/byte_ globals are jump-table data and case targets.
- TLS error codes 12/13/15/34 and the +2/+3 DWORD TLS offsets have DERIVED meanings only.
- The meaning of dword_8D3F38 (encoding-path handle) and the 0x100 argument passed to sub_591FA1 are not established.
- The identity of the exit function pointer off_5E65B0 and the writers of dword_8D3EBC are not visible in this packet.
- sub_589CB5 appears as a callee of CRTAmsgExit in the fact table but is not called anywhere in the raw source body.
- The 2147224447 upper bound in TimeSecondsToBrokenDownTime has no documented purpose in the packet.
- The critical-section array layout dword_8D4920 (36-byte entries, per-handle open bit at entry+4) and the heap-slot array (dword_8D4A24 / dword_8D5A40) are taken from the raw source only.
- All class fields use the packet's evidence base 'this'; equal offsets across classes (this+0x0 in BufferedStream, TimeConverter and MemoryCopyRoutine) are NOT merged because the packet proves no common ownership (rule 8). Class membership and field names carry the separation.
