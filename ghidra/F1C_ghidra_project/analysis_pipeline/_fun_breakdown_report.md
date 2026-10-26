# Structured Breakdown of 01-engine-architecture.md ## FUN_ Entries (After Line 960)

**Total ## FUN_ sections in file:** 833
**Total after line 960:** 809

## Distribution by Target Doc

### docs/01-engine-architecture.md (408 entries)

#### FUN_00465d70 — Recursive Linked List Merge Sort
- **Source:** Unknown. Sorts a singly-linked list of game objects using recursive merge sort with priority table.
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00561a41 — 2D Array Fill with Stride Support
- **Source:** unknown | Confidence: high (Data fill pattern)
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00563a30 — Query with Context + Cleanup
- **Source:** unknown | Confidence: high (Engine/Call pattern)
- **Key Logic:** 
- **Calls:** FUN_00564110 (unknown query), FUN_005648c0 (call wrapper → FUN_005648d0)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057a990 — Free Callback Registered Cleanup
- **Source:** unknown | Confidence: high (Memory/Free pattern)
- **Key Logic:** 
- **Calls:** FUN_00587b3e (deferred function registration, _atexit-like)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057b820 — Object Init with Copy (Socket Close Helper)
- **Source:** unknown | Confidence: high (DataStructure / network pattern)
- **Key Logic:** 
- **Calls:** FUN_00587370 (mutex-protected send/close, per docs/21)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00585770 — Thread-Safe Int Read with Mutex
- **Source:** unknown | Confidence: high (Threading pattern)
- **Key Logic:** 
- **Calls:** WaitForSingleObject, ReleaseMutex (Win32 API)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0058a323 — Atomic LOCK/UNLOCK with Indirect Call
- **Source:** unknown | Confidence: medium (decompilation degraded — unrecoverable jumptable)
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059a728 — Exception Cleanup with Destructor Call
- **Source:** unknown (likely MSVC CRT) | Confidence: high (Except pattern)
- **Key Logic:** 
- **Globals:** PTR_FUN_005b9d28
- **Calls:** FUN_0058a5d8 (stack probe), FUN_005993af(1) (buffer flush, per docs/20), exception::~exception (MSVC exception destructor)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### Unwind_0059c40a — SEH Unwind Handler (Free Field)
- **Source:** unknown (MSVC CRT) | Confidence: high (Sys/Unwind pattern)
- **Key Logic:** 
- **Calls:** FUN_00587bcf (memory free/dealloc)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### Unwind_0059c68e — SEH Unwind Handler (Free Field at EBP+8)
- **Source:** MSVC CRT | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf (memory free/dealloc)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### Unwind_0059c812 — SEH Unwind Handler (Call FUN_00581880)
- **Source:** MSVC CRT | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00581880 (unknown cleanup)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### Unwind_0059c956 — SEH Unwind Handler (Call FUN_00581c20)
- **Source:** MSVC CRT | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00581c20 (unknown cleanup)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### Unwind_0059d070 — SEH Unwind Handler (Call FUN_0047aa60)
- **Source:** MSVC CRT | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0047aa60 (unknown cleanup — in renderer address range)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### Unwind_0059d427 — SEH Unwind Handler (Call FUN_00598c70)
- **Source:** MSVC CRT | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00598c70 (unknown cleanup — likely locale/stream)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00581820 — Linked List Destroy + CloseHandle
- **Key Logic:** 
- **Target:** docs/01-engine-architecture.md

#### FUN_00556510 — Performance Counter Timer with Scaling
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_005564b0 — QPC wrapper returning 64-bit timestamp
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00558cf0 — Bounds-Checked Array Write (0x80 stride)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00566cc0 — Conditional Dispatch Based on Flag
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587ca0 — File read until newline (IO) - FUN_005351d0 — Arithmetic/comparison (math_util)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00568c60 — Timer Reset Using QueryPerformanceCounter
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** QueryPerformanceCounter (Win32 API)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0056d880 — Zero-Fill Arrays and Call Init Routine Repeatedly
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00568fb0 — (init routine, called *param_1 times per element)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057a4c0 — VTable Destructor Then Null Pointer
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00581a20 — Handle Close + Linked-List Destruction with VTable Release
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - CloseHandle (Win32 API) - FUN_00587bcf — Free wrapper
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00583650 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_004b0170 — (lookup needed)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00585860 — Single Field Setter (Returns 1)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** configurable — field write, caller provides value
- **Target:** docs/01-engine-architecture.md

#### FUN_005865c0 — Create Mutex via Win32 API
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** CreateMutexA, CloseHandle (Win32 API)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005870e0 — Field Reset with Sub-Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587500 — (sub-routine, called first)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0058a331 — SEH Unwind Handler (RtlUnwind)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** RtlUnwind (NTDLL API)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00595a61 — Critical Section Enter with Lazy Init
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Globals:** DAT_008d4920
- **Calls:**  - InitializeCriticalSection, EnterCriticalSection (Win32 API) - FUN_0058dfea(0x11) — pre-lock function - FUN_0058e04b(0x11) — post-unlock function
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059cf0b — SEH Unwind with Single Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00586170 — (cleanup handler)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059d07b — SEH Unwind with Single Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0047aa60 — math_util (short computation)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059d1f8 — SEH Unwind Release Locale Refcount
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Globals:** DAT_008d43c8
- **Calls:** FUN_00599796 — locale refcount release
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059d43c — SEH Unwind with Single Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00599d17 — (cleanup handler)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c698 — SEH Unwind with Field Free
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf — Free wrapper
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c81a — SEH Unwind Cleanup Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_005818e0 — (cleanup handler)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005502c0 — Destructor with Conditional Free + Flag Clear
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_00542e50 — unknown (methodology doc, 36 lines) - FUN_00557470 — empty no-op stub (triage index line 6346, docs/20) - FUN_00587bcf — free/operat...
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00551830 — Wide-String Comparison Walking Linked List
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0055bff0 — Array Slot Check + Conditional Call
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0055bd20 — render command matching and dispatch (docs/19)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00568cb0 — QPC Timestamp Read Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - QueryPerformanceCounter — Win32 kernel32 API
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0056ead0 — Linear Search with Large Struct Stride
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00588410 — byte string compare (docs/06)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057a4f0 — Virtual Function Dispatch with Stack Frames
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_00585860 — field setter (triage index) - FUN_00585030 — allocation wrapper (triage index) - FUN_00584ff0 — string copy (triage index)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00583660 — Float Set with Timing Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00568c60 — timer reset using QPC (triage index line 6519)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00585bf0 — Iterate Triggers via Vtable, Call Handlers per Tick
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_005871c0 — dual query into two output params (triage index) - FUN_00585cc0 — struct field getter at +0x78 (triage index) - FUN_00587220 — struc...
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00587b7f — Init Wrapper Calling 3 Subroutines
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Globals:** DAT_008d3e44
- **Calls:**  - FUN_00587b97 — init CRT float conversion function pointers (triage index line 6748) - FUN_0058bca6 — unknown (methodology doc, 23 lines) - FUN_0058...
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059373e — Struct Matching with Bit Flags + strcmp
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00595ac0 — File Critical Section Leave
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Globals:** DAT_008d4920
- **Calls:**  - LeaveCriticalSection — Win32 kernel32 API
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059a7de — Destructor with SEH + VTable Reset
- **Source:** unknown | Confidence: low (register variable unaff_EBP — partial decompilation)
- **Key Logic:** 
- **Calls:**  - FUN_0058a5d8 — SEH handler init (triage index) - FUN_005993af — reference count decrement and conditional free (triage index) - exception::~excepti...
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059afff — Exception Throw Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0059b038 — object init with vtable (triage index) - __CxxThrowException_8 — MSVC CRT exception throw
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c43c — SEH Unwind with Field Free
- **Source:** unknown | Confidence: low (register variable unaff_EBP)
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — free/operator delete (docs/09, 19, 21)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c5a8 — SEH Unwind Free Object at +8
- **Source:** unknown | Confidence: low (register variable unaff_EBP)
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — free/operator delete
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059cbc0 — SEH Unwind Cleanup Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0057bc70 — single vtable pointer set (triage index)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059cd6b — SEH Unwind with Field Free
- **Source:** unknown | Confidence: low (register variable unaff_EBP)
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — free/operator delete
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059cf19 — SEH Unwind Cleanup Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_005833e0 — walk linked list, call destructor, free nodes (triage index)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059d444 — SEH Unwind Cleanup Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00598c70 — null check with virtual dispatch / error handling (triage index)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005519e0 — Doubly-Linked List Node Removal
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00550ac0 — math_util (13 lines, cleanup/update) - FUN_00557470 — release/unload resource - FUN_00587bcf — memory free/deallocation
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00563e80 — Index-Bounds Checked Array Read
- **Source:** network subsystem | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00563e70 — math_util, returns pointer/array size value - FUN_005648b0 — math_util, returns array base pointer (linear interpolation pattern)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0056eb30 — Linear Search in Struct Array by String
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00588410 — string compare (docs/06, 75 lines)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057a570 — Byte Field Setter at Offset +0x5d
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057aaf0 — Stack Buffer Copy + Predicate Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0057abb0 — large predicate/processing function (248 bytes, SEH-protected)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00583690 — Single Function Call Wrapper (Timer Delta)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00568cf0 — high-res timer delta with state update (timer math)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0058b8ad — Semaphore Release (Slot 9)
- **Source:** synchronization | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0058e04b — semaphore/critsec release (typically pairs with acquire)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0058d7f4 — Char-by-Char String Processing with Terminator Check
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0058d78e — char processing/handler function
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0058f8eb — Multi-Field Free (7 Allocations)
- **Source:** memory manager | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0058aa6f — memory deallocation (called 7 times)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059875f — Free Callback Registered Cleanup
- **Source:** initialization/cleanup | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587b3e — deferred function/callback registration (MSVC _atexit-like)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059a81b — C++ Exception Throw Wrapper
- **Source:** runtime | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0059a854 — exception object preparation - __CxxThrowException_8 — MSVC C++ exception throw
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059b038 — Object Init with VTable
- **Source:** runtime | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0059ae7d — base class constructor
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### Unwind_0059cbe0 — SEH Unwind: Call FUN_005834c0
- **Source:** runtime | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_005834c0 — pool/resource cleanup function
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### Unwind_0059d45c — SEH Unwind: Call FUN_0059a9c2
- **Source:** runtime | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0059a9c2 — cleanup function
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00461440 — References Global State / Session Flag Check
- **Source:** steward/session | Confidence: high
- **Key Logic:** 
- **Globals:** DAT_007d1074
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00465430 — Short Computation / Player Control Set
- **Source:** game logic | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00464e90 — lookup by player/vehicle index - FUN_00464a60 — set control state
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00466d60 — Short Computation / Object Init + VTable
- **Source:** game logic/UI | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0048c070 — setup function
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0046fd00 — Short Computation / Object Init with VTable + Field
- **Source:** game logic | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00487220 — init function
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_004715d0 — Short Computation / Object Init with Globals
- **Source:** game logic | Confidence: high
- **Key Logic:** 
- **Globals:** DAT_007ce850, PTR_DAT_005be704, DAT_005c32c8
- **Calls:** FUN_00466d60, FUN_00486f30 (×2), FUN_004670e0
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00485570 — Short Computation / Destructor with VTable
- **Source:** UI | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00487250, FUN_00587bcf
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00489f40 — Unidentified / Clamped Index Computation
- **Source:** UI | Confidence: medium
- **Key Logic:** 
- **Calls:** __ftol (CRT float-to-long)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0048c9d0 — Short Computation / VTable Set Only
- **Source:** UI | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_004a0ad0 — Short Computation / Command Dispatch (0x1b) + Standings
- **Source:** game logic | Confidence: high
- **Key Logic:** 
- **Globals:** DAT_007cd8c0
- **Calls:**  - Virtual dispatch through DAT_007cd8c0+0x1c - FUN_0046a560 — standings display (docs/06)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_004dc320 — Short Computation / Callback Registration
- **Source:** initialization | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587b3e — callback registration (MSVC _atexit-like)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057a820 — Short Computation / Thunk to FUN_00585810
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00585810 — target function
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### Unwind_0059d358 — MSVC Exception Handler Unwind with DAT_008d4400
- **Source:** runtime | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00599796
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00561e00 — Two-Step Init Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00561ed0 — unknown init - FUN_00561e30 — unknown init
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00568d90 — Performance Counter Diff with Scaling
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00568cb0 — current time read
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0056ec00 — Batch Processing Loop, 3 Passes
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0056cf70 — process pass 1 - FUN_0056d020 — process pass 2 - FUN_0056d2d0 — process pass 3
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005836a0 — Large Structure Zero-Initialization
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0058a42f — SEH Exception Handler Trampoline Setup
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_0058e0c7 — unknown
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0058b903 — Semaphore-Guarded Query Call
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_0058b92a — query function
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059977e — Cleanup Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587b3e — cleanup dispatcher
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### Unwind_0059c6c0 — SEH Unwind Handler
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### Unwind_0059c846 — SEH Unwind with Single Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00581ad0 — cleanup function
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### Unwind_0059cc00 — SEH Unwind Handler
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00583570
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### Unwind_0059d0a7 — SEH Unwind Handler
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0047aa60 — empty stub
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### Unwind_0059d248 — SEH Unwind Handler with Flag Check
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00598aea — conditional cleanup
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### Unwind_0059d470 — SEH Unwind with ~Exception Destructor
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00587bcf
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00585d70 — Thread-Safe String Read with Mutex
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - WaitForSingleObject — Win32 API - ReleaseMutex — Win32 API
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00586a00 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587510 — Target function
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0058d839 — Pointer Advance + Read-Back
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** None
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00590440 — Short-in-Range Check Against Static Table
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** None
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057adc0 — Free Callback Registration
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587b3e — Callback registration
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00558e10 — Pixel Write to Texture Buffer
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_00558d10(0) — clear/reset
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0055c7d0 — Input State Query Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0055c450 — Input state query function
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0055fe30 — Dual Field Cleanup with Null Checks
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587d02 — Free/deallocate (specialized) - FUN_00587bcf — Free/deallocate (generic)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00561ed0 — Tick Count Comparison, Handle Inactivity Timeout
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00562ac0 — Timeout/activity handler
- **Moddability:** hardcoded (thresholds 300000ms, 30000ms, cap at 10)
- **Target:** docs/01-engine-architecture.md

#### FUN_00564270 — Singleton/Global Accessor with Fallback Alloc
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_005647d0 — Singleton/global getter - FUN_00564690 — Singleton/global allocator - FUN_00564780 — Singleton/global registrar
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00550620 — Scrolling Data Offset Across Linked Entries
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** none (pure logic, no sub-calls)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00551f80 — Conditional Free with Bink Close
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00551ce0 — BinkClose, closes Bink video/audio stream - FUN_00557470 — no-op stub (empty function, likely placeholder) - FUN_00587bcf — heap mem...
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005592b0 — Doubly-Linked List Node Removal by Pointer
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_005574b0 — complex sub-element cleanup at matched node - FUN_00557470 — no-op stub - FUN_00587bcf — heap memory free
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00568f20 — Multi-Field Pointer Cleanup with Null Checks
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — heap memory free (called up to 4 times)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057adf0 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00599958 — object constructor with SEH frame and vtable initialization (docs/08)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057d5d0 — Structured Memory Copy with Header Prepend
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0053d880 — short computation (returns small int written to header) - FUN_00587580 — buffer query: validate/return ptr+size
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00582310 — CloseHandle Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - CloseHandle — Win32 API kernel32.dll
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00583d40 — Mutex-Protected Data Read with Timed Wait
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - WaitForSingleObject — Win32 API (kernel32) - ReleaseMutex — Win32 API (kernel32)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00585de0 — QueueUserAPC Async Procedure Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - QueueUserAPC — Win32 API (kernel32) - FUN_0041a160 — APC callback procedure
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00586a10 — Bounded Memory Copy with Size Validation
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0053d880 — short computation (returns minimum size threshold) - FUN_00587580 — buffer query: validate and return ptr+size
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00587370 — Copy Buffer Header Fields + Call Init
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587620 — buffer write/init with parameters (buffer management)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005905dd — Hex String to Int Parser
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** none (pure logic)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005997ab — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587b3e — function taking code pointer
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059a2d0 — Locale Encoding Check
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0059bb00 — locale/encoding conversion function
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059a8bc — Sub-Call + Conditional Free
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0059a86c — sub-function - FUN_00587bcf — heap memory free (conditional)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059b390 — Dual-Pointer Free
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — heap memory free (twice)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c482 — SEH Unwind with Field Free
- **Source:** CRT / MSVC runtime | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — heap memory free
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c5da — SEH Unwind Free Object at +8
- **Source:** CRT / MSVC runtime | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — heap memory free
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059cf53 — SEH Unwind Cleanup Call
- **Source:** CRT / MSVC runtime | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00586210 — cleanup/teardown function
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0053d850 — Object Release with Vtable Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00540760 - (indirect virtual) sub-object vtable+8
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00546370 — Array Cleanup with Dual Free
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — heap free (multiple) - FUN_00557470 — no-op stub
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00547400 — Guarded Call with Status
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00548620
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00559330 — Small Struct Init with Parent Call
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0053c2a0 — parent constructor / subsystem init (docs/06)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0055ca40 — Enum-to-VTable-Call Mapper (3 Cases)
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - Virtual call at vtable+0x94 on object at param_1[0x440] — dispatch with mapped ID
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00560b30 — Conditional Free of Struct Field
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — memory free / deallocation
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057a660 — Dual Virtual Dispatch Wrapper
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - Virtual call at vtable+0x74 — first dispatch (unknown purpose) - Virtual call at vtable+0x9C — second dispatch (unknown purpose, with args 0,0)
- **Moddability:** hookable
- **Target:** docs/01-engine-architecture.md

#### FUN_0057ae70 — Single Function Call Wrapper (to constructor)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00599958 — Entity constructor with SEH + vtable init (docs/08)
- **Moddability:** hookable
- **Target:** docs/01-engine-architecture.md

#### FUN_0057d660 — Buffer Unpack with Size Check + Byte/Word Copy
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_00587510 — cleanup/advance function (not yet documented)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00582340 — VTable Call with Flag Check
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Moddability:** hookable
- **Target:** docs/01-engine-architecture.md

#### FUN_005840d0 — Mutex Wait with 1ms Timeout + Release
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded (mutex handle stored in struct)
- **Target:** docs/01-engine-architecture.md

#### FUN_00585e10 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00598815 — Entity constructor (docs/08)
- **Moddability:** hookable
- **Target:** docs/01-engine-architecture.md

#### FUN_00586a80 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0053d880 — render iterator (used in render_setup.cpp, docs/19)
- **Moddability:** hookable
- **Target:** docs/01-engine-architecture.md

#### FUN_005997d5 — Callback Registration (atexit-style)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059a336 — Conditional Free with Flag Check
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00599be5, FUN_00587bcf
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059a8d8 — Callback Chain Iteration
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hookable
- **Target:** docs/01-engine-architecture.md

#### FUN_0059b530 — Grow Dynamic Element Array
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** operator_new, FUN_00587bcf
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059cc1e — SEH Unwind: Free at -0x1C
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00554610 — State Parameter Setter with Virtual Device Notify
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Globals:** DAT_008b89a0
- **Calls:** DAT_008b89a0 vtable+0xf4 (state parameter setter notification)
- **Target:** docs/01-engine-architecture.md

#### FUN_00579fc0 — Callback Registration for Cleanup Routine
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00587b3e (callback registration/dispatch)
- **Target:** docs/01-engine-architecture.md

#### FUN_0057a690 — Virtual Method Dispatch (vtable+100)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** virtual method at vtable+0x64 on *param_1 object
- **Target:** docs/01-engine-architecture.md

#### FUN_00582360 — Win32 Mutex Create/Recreate
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** CloseHandle, CreateMutexA (Win32 API)
- **Target:** docs/01-engine-architecture.md

#### FUN_00586c90 — Counter Increment with Cap Check
- **Source:** unknown | Confidence: medium
- **Key Logic:** Reads counter from *param_1, increments by 1 Stores incremented value back Returns (incremented < 6) as boolean in upper byte, value in lower 3 bytes Acts as a bounded counter that saturates/is checke...
- **Target:** docs/01-engine-architecture.md

#### FUN_0058a5f7 — N-Time Callback Loop with SEH
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** (*param_4)() -- caller-provided callback, FUN_0058a65f (SEH cleanup/epilog)
- **Target:** docs/01-engine-architecture.md

#### FUN_00593c24 — SEH Frame Offset Calculation Helper
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** None -- pure address arithmetic
- **Target:** docs/01-engine-architecture.md

#### FUN_00599232 — Conditional Delegate Call with Null Guard
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_0059bb00 (delegate dispatch with context params)
- **Target:** docs/01-engine-architecture.md

#### FUN_00599802 — Callback Registration for Cleanup Routine
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00587b3e (callback registration)
- **Target:** docs/01-engine-architecture.md

#### FUN_00408050 — Linked List Node Search by ID + Operation
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00406a90 (operation on matched node)
- **Target:** docs/01-engine-architecture.md

#### FUN_00408de0 — Conditional Subsystem Call with Parameter
- **Source:** unknown | Confidence: low
- **Key Logic:** 
- **Calls:** FUN_00541ca0, FUN_00543440
- **Target:** docs/01-engine-architecture.md

#### FUN_0040c070 — Random State Machine with Timer and Trigger
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Globals:** DAT_0059e440
- **Calls:** FUN_0040c780 (elapsed time), _rand, FUN_0040cd60, FUN_0040cde0, FUN_0040d290, FUN_0040d360
- **Target:** docs/01-engine-architecture.md

#### FUN_0040d980 — Global Data Struct Init with File Paths
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00434860, FUN_00567a00, FUN_00567f10
- **Target:** docs/01-engine-architecture.md

#### thunk_FUN_004201e0 — at 004203d0 -- Thunk to FUN_004201e0
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_004201e0 (target function)
- **Target:** docs/01-engine-architecture.md

#### FUN_0045bf60 — Callback Registration for Cleanup
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00587b3e
- **Target:** docs/01-engine-architecture.md

#### FUN_0046af00 — Dual Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0046ae60, FUN_00489ab0
- **Target:** docs/01-engine-architecture.md

#### FUN_0046da20 — Dispatch Chain with VTable Calls
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_0042d210, vtable+0x1c, FUN_0046bf10, FUN_004d2450, vtable+0x38
- **Target:** docs/01-engine-architecture.md

#### FUN_0046fe50 — Conditional UI/Subsystem Dispatch
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Globals:** DAT_007cd8c0
- **Calls:** FUN_0048fec0, FUN_00490160, vtable+0x1c, FUN_00477280
- **Target:** docs/01-engine-architecture.md

#### FUN_00471860 — Object Constructor with VTable and Field Init
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00466d60, FUN_00486f30, FUN_004670e0
- **Target:** docs/01-engine-architecture.md

#### FUN_00473b90 — Conditional Init with Global Ref Setup
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Globals:** DAT_007cd8c0
- **Calls:** vtable+0x1c, FUN_00477280
- **Target:** docs/01-engine-architecture.md

#### FUN_00475040 — VTable Setter with Sub-call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00487250
- **Target:** docs/01-engine-architecture.md

#### FUN_004773a0 — Bounds Check with Position Query
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00498880, FUN_0048ea60
- **Target:** docs/01-engine-architecture.md

#### FUN_00478320 — Resource Query and Stored Setup
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Globals:** DAT_007cd8c0
- **Calls:** vtable+0x1c, FUN_00478390
- **Target:** docs/01-engine-architecture.md

#### FUN_004798e0 — VTable Setter with Float Params
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00466980
- **Target:** docs/01-engine-architecture.md

#### FUN_00479ed0 — Call + Flag Set
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0047abb0
- **Target:** docs/01-engine-architecture.md

#### FUN_0047bae0 — Bounded Counter Update
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0047bd90 (update after change), FUN_0047bc90 (get max bound)
- **Target:** docs/01-engine-architecture.md

#### FUN_0047e940 — Conditional Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00566650
- **Target:** docs/01-engine-architecture.md

#### FUN_00486f30 — Linked List Insert with Node Allocation
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** operator_new, FUN_00566650
- **Target:** docs/01-engine-architecture.md

#### FUN_004879e0 — Init Dispatch with VTable Check
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_004874e0, FUN_00487760, FUN_00487960, vtable+0x98, FUN_00486600
- **Target:** docs/01-engine-architecture.md

#### FUN_00488f90 — VTable Set with Flag
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00485e30
- **Target:** docs/01-engine-architecture.md

#### FUN_0048b4e0 — VTable Setter + Sub-call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00485eb0
- **Target:** docs/01-engine-architecture.md

#### FUN_0048cc20 — Linked List Size Calc with Max Tracking
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Target:** docs/01-engine-architecture.md

#### FUN_0048e0b0 — Destructor with Conditional Free
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0048e0d0, FUN_00587bcf
- **Target:** docs/01-engine-architecture.md

#### FUN_0048faf0 — Decrement Counter with Clamp
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0048f870
- **Target:** docs/01-engine-architecture.md

#### FUN_00491e10 — Conditional Resource Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf
- **Target:** docs/01-engine-architecture.md

#### FUN_0049d480 — Local Buffer + Subsystem Call
- **Source:** unknown | Confidence: low
- **Key Logic:** 
- **Calls:** FUN_0049c670, FUN_00553070
- **Target:** docs/01-engine-architecture.md

#### FUN_004b9870 — Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_004b7a90
- **Target:** docs/01-engine-architecture.md

#### FUN_004ba740 — Guarded Dispatch with State Check
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Globals:** DAT_007d005c
- **Calls:** FUN_004b9880, FUN_004b97e0
- **Target:** docs/01-engine-architecture.md

#### FUN_004c82c0 — Init with Status Check
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Globals:** DAT_008ac4c4
- **Calls:** FUN_004c8350, FUN_004c7c10
- **Target:** docs/01-engine-architecture.md

#### FUN_004d7d90 — Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_004d7ad0
- **Target:** docs/01-engine-architecture.md

#### FUN_004d8950 — Batch VTable Dispatch and Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** vtable+0 method
- **Target:** docs/01-engine-architecture.md

#### FUN_004f8ae0 — Dual Source Acquire with Fallback
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_004f8b50, FUN_004f8c70
- **Target:** docs/01-engine-architecture.md

#### FUN_004f9240 — Multi-Table Coordinate Search
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Globals:** DAT_008afe6c
- **Calls:** FUN_004f9150, FUN_004f9160, FUN_004f9190, FUN_004f91b0
- **Target:** docs/01-engine-architecture.md

#### FUN_0050a8f5 — VTable Setter with Sub-init (Type 1)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00507496
- **Target:** docs/01-engine-architecture.md

#### FUN_005161dd — Linked List Node Alloc and Insert
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00515f23, vtable+0
- **Target:** docs/01-engine-architecture.md

#### FUN_0052d9d0 — Destructor with Conditional Free
- **Source:** unknown | Confidence: high
- **Key Logic:** Indirect jmp to AVIFileRelease (Video for Windows API) **Used by system:** docs/08-file-formats.md -- AVI import trampoline <!-- target: docs/01-engine-architecture.md -->
- **Calls:** FUN_0052d9b0, FUN_00587bcf
- **Target:** docs/01-engine-architecture.md

#### FUN_00536160 — Buffer Copy with Size Tracking
- **Source:** unknown | Confidence: high
- **Key Logic:** Computes copy size = min(*(param_1+0x10), *(source+0x14)) Copies data in dwords then residual bytes Advances both src and dst pointers Updates all 4 size fields: +0xc (dst consumed), +0x14 (total), +0...
- **Target:** docs/01-engine-architecture.md

#### FUN_0053ac70 — Empty Stub with Flag Check
- **Source:** unknown | Confidence: high
- **Key Logic:** If (param_2 & 4): returns early Otherwise: returns Effective no-op regardless of path **Used by system:** docs/01-engine-architecture.md -- empty stub <!-- target: docs/01-engine-architecture.md -->
- **Target:** docs/01-engine-architecture.md

#### FUN_0053c140 — Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00556220
- **Target:** docs/01-engine-architecture.md

#### FUN_00541670 — VTable Dispatch with Field Check
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** vtable+200 dispatch
- **Target:** docs/01-engine-architecture.md

#### FUN_00543440 — Render/Draw Operation with Clipping
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00543540, FUN_005404d0
- **Target:** docs/01-engine-architecture.md

#### FUN_005469c0 — Reference Counted Resource Release
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_005502c0, FUN_005478b0
- **Target:** docs/01-engine-architecture.md

#### FUN_005568d0 — Callback Registration
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587b3e
- **Target:** docs/01-engine-architecture.md

#### FUN_0057aa20 — Callback Registration
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587b3e
- **Target:** docs/01-engine-architecture.md

#### FUN_00583aa0 — Close Handle Pair Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** CloseHandle (Win32 API)
- **Target:** docs/01-engine-architecture.md

#### FUN_0059982f — Callback Registration
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587b3e
- **Target:** docs/01-engine-architecture.md

#### FUN_00554660 — Float State Setter with Change Notification
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** vtable dispatch at DAT_008b89a0+0xfc (state change notification)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0055ce50 — Set UI Text Fields via Vtable Calls
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** vtable dispatch at manager+0x94, manager+0xa0 (text field setters)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00579ff0 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00599958 (resource scan/refresh, docs/08)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057db80 — Two-Field Equality Check
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** none
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00582720 — Mutex Create/Replace Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** CloseHandle (Win32), CreateMutexA (Win32)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00584dd0 — Mutex-Protected Dispatch Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** WaitForSingleObject, ReleaseMutex (Win32), FUN_00586000 (list append, docs/20)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00550800 — Dual Field Zero-Init
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005528f0 — Conditional UI Cleanup Dispatch
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00554d70 — notify device / release (renderer resource cleanup, docs/19)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005546a0 — Multi-Field Setter Dispatching to 7 Sub-Setters
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_00553fc0 — entity factory/creation (docs/20) - FUN_005542f0 — entity property set (docs/06) - FUN_005545e0 — unknown setter - FUN_00554560 — UI...
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057a020 — Struct Zero-Init (4 + 8 Words)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057a750 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00585440 — target function (unknown, not documented)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057b050 — Linked List Node Removal with Memory Free
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — free/delete operator (docs throughout)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00584f30 — Mutex-Protected Function Call with Wait
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - WaitForSingleObject — Win32 API - FUN_00586000 — unknown callback (not documented) - ReleaseMutex — Win32 API
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059a9c2 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_005993af — buffer flush / callback chain execution (docs/08, docs/20)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059bacc — Exception Destructor with Conditional Free
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0059baa3 — pre-destructor cleanup (unknown) - FUN_00587bcf — free/delete operator
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### Unwind_0059c4c8 — SEH Unwind with Field Free
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — free/delete operator
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### Unwind_0059c60c — SEH Unwind Free Object at +8
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — free/delete operator
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### Unwind_0059c896 — Unwind Handler (SEH)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00581c20 — cleanup/destructor (unknown)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### Unwind_0059ce60 — Unwind Handler (SEH) — Array Destructor
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0058a5f7 — destructor iterator / array cleanup
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### Unwind_0059cfbe — SEH Unwind Cleanup Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_004b0170 — destructor (docs/19, docs/18)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### Unwind_0059d110 — SEH Unwind Cleanup Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00586460 — cleanup function (unknown)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### Unwind_0059d2e4 — SEH Unwind Cleanup Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00598c70 — cleanup function (unknown)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00593c9c — SEH Wrapper Dispatching to Handler Function
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0058e0c7 — TLS value retrieval (docs/20) - (*fnptr)() — callback from TLS context - FUN_00597371 — SEH epilogue/unwind (unknown)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00597321 — IsBadReadPtr Wrapper
- **Source:** Win32 API wrapper | Confidence: high
- **Key Logic:** 
- **Calls:**  - IsBadReadPtr — Win32 API (kernel32)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00586d00 — Bitmap Range Occupancy Test via Bit Ops
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00556980 — Animation Dispatch with Skip Flag
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0054b570 — object set resolver - FUN_00556b10 — animation handler (new/empty slot) - FUN_005569f0 — animation handler (existing slot)
- **Moddability:** hookable
- **Target:** docs/01-engine-architecture.md

#### FUN_0057a040 — Pass-Through Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0057a070 — target function
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00584f90 — Mutex-Guarded Timer Read
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - WaitForSingleObject — Win32 mutex acquisition - ReleaseMutex — Win32 mutex release - FUN_00583680 — timer/clock read
- **Moddability:** hookable
- **Target:** docs/01-engine-architecture.md

#### FUN_0057dff0 — Mutex-Protected Linked-List Lookup by ID
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - WaitForSingleObject — Win32 mutex wait - ReleaseMutex — Win32 mutex release - FUN_0057de30 — process matched node
- **Moddability:** hookable (mutex timeout)
- **Target:** docs/01-engine-architecture.md

#### FUN_00582eb0 — Linked-List Node Removal with Cleanup Callback
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_004b0170 — cleanup/free wrapper
- **Moddability:** hardcoded (constant 2)
- **Target:** docs/01-engine-architecture.md

#### FUN_00589d6b — Lock Acquire by Index
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0058dfea � lock acquisition
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059733d — IsBadWritePtr Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - IsBadWritePtr -- Win32 API
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00598aea — Vtable Set + Sub-Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0059a86c
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005992ef — Buffer Append with Memset
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0059ad49, FUN_00599560, _memset
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059988b — Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587b3e
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059a407 — Pointer Offset Adjuster
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - none
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00554b20 — Resource Factory via VTable Dispatch
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_005424e0 — arithmetic helper (4 locals initialized) - FUN_00543250 — clear/blit destination (used in renderer, per docs/17)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0055d2a0 — String Copy with Flag Union
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_00541500 — hash/checksum computation from flag value
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057e6e0 — Thread-Safe Linked List Destruction with Mutex
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — memory free/deallocation - (vtable[0]) — virtual destructor call on object
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00582f60 — SEH-Protected Linked List Destruction
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — memory free/deallocation - (vtable[0]) — virtual destructor call on object
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00598af5 — Object Constructor with VTable Setup and SEH
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0058a5d8 — CRT/object pre-initialization - FUN_005993eb — sub-constructor/initializer
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00599348 — Buffer Truncation/Shrink
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0059af68 — error handler / assertion - FUN_005995e5 — pre-modify buffer check - FUN_0058b130 — memcpy/memmove (docs/06) - FUN_00599560 — capaci...
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00554c30 — State Flag Iteration Across Entries
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0053f720 — format/device validation call (docs/19 renderer)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005570c0 — Nested Linked List Traversal with Dirty Mark
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_00556cd0 — D3DMarkDirty: sets dirty flags on scene graph resource descriptors (docs/19)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00564650 — Sleep Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** Sleep (Win32 API)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00565ef0 — Reverse Path Search for Backslash Separator
- **Source:** unknown (filesystem/path utils) | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_005662d0 — Directory Entry Iterator (docs/08)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057a0c0 — 16-Byte Memory Comparison for Equality
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** None (inline comparison)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057a850 — VTable Bool Check (Inverted)
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057b550 — Ring Buffer Push with Wrap Check
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057e760 — Mutex-Protected Linked List Flush/Destroy
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - WaitForSingleObject (Win32 API) - FUN_00587bcf — memory free/dealloc (used throughout engine) - ReleaseMutex (Win32 API)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00583050 — Destroy Linked List with SEH, Call Destructors
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — memory free/dealloc - ExceptionList manipulation (SEH frame)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00585030 — Allocation Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0057a0f0 — byte-aligned memory copy with offset (triage: Mem/Copy)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00586170 — Handle Close & Linked List Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - CloseHandle (Win32 API) - FUN_005867b0 — SEH-guarded pool/free helper - FUN_00587bcf — memory free/dealloc
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00586f10 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00599958 — object constructor with SEH + vtable init (docs/08)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00598b5d — Object Constructor with SEH + Vtable Init
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0058a5d8 — allocation/pre-init - FUN_0059a8fa — post-init
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005993eb — Object Init with VTable + Flag Set
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0059a948 — post-init - FUN_0059a5fe — flag set operation - FUN_0059a8fa — secondary init
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005998cf — Cleanup Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587b3e — deferred function registration (MSVC _atexit-like)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059a428 — Double Indirect Counter Update
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c634 — SEH Unwind with Field Free
- **Source:** CRT/exception handling | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — memory free/dealloc
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c790 — SEH Unwind with Field Free (EBP-0x10)
- **Source:** CRT/exception handling | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — memory free/dealloc
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059ce9a — SEH Unwind with Single Call
- **Source:** CRT/exception handling | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00586460 — cleanup/dealloc (unknown)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059cff6 — SEH Unwind with Single Call
- **Source:** CRT/exception handling | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00586170 — Handle Close & Linked List Cleanup (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059d15b — SEH Unwind with Field Free (EBP-0x10)
- **Source:** CRT/exception handling | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — memory free/dealloc
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059d338 — SEH Unwind Release Locale Refcount
- **Source:** CRT/exception handling | Confidence: medium
- **Key Logic:** 
- **Globals:** DAT_008d4478
- **Calls:**  - FUN_00599796 — locale refcount release (empty stub)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00551440 — Entity Flag Set + Sub-Init Chain
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_00551390(0,0) — renderable/scene attach - FUN_005563e0 — unknown init - FUN_00556440 — unknown init (called by bounds check function at 0x00556...
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00553050 — Two-Field Setter
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Moddability:** hookable — values passed as parameters
- **Target:** docs/01-engine-architecture.md

#### FUN_0057a0f0 — Byte-Aligned Memory Copy with Offset
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057a880 — VTable Query with Stack Buffer Result
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** vtable[0x1e] (offset +0x78) — query method returning success/fail
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057b5c0 — Ring Buffer Pop with Wrap Check
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00585220 — Status Check via VTable Dispatch
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** vtable[+0xa4] — status query method
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005861e0 — CloseHandle Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** CloseHandle — Win32 API
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00586f20 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587b3e — atexit/callback registration
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005532a0 — Object Allocation with Zero-Init
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0053c2a0 — Parent constructor (engine subsystem, docs/06)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005550a0 — VTable Getter Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** Virtual call via vtable+0x88 on embedded object
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00557480 — Flag-Conditional Branch Dispatch
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00557ce0 (CRT utility, docs/20), FUN_00557670 (MTS init/mesh, docs/00)
- **Moddability:** hookable
- **Target:** docs/01-engine-architecture.md

#### FUN_0055baf0 — Small Struct Init (9 uint32 fields)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** None
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0055d410 — UI Property Value Setter
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_005416a0 — DirectX vertex buffer texture coord setup (docs/19)
- **Moddability:** hookable
- **Target:** docs/01-engine-architecture.md

#### FUN_00560fd0 — State Flag Bit Clear
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** None
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00563000 — Polling Loop with Process Calls
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00563410 (engine processing, docs/00), FUN_00564650 (Sleep wrapper)
- **Moddability:** hookable
- **Target:** docs/01-engine-architecture.md

#### FUN_005646d0 — Allocate Int Array via Factory
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** _malloc, FUN_00564810 (alloc 0x18 struct + inner buffer, docs/08)
- **Moddability:** hookable
- **Target:** docs/01-engine-architecture.md

#### FUN_0057a1b0 — Memcpy with Advance Pointer
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** None
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00585320 — Linked-List Walk with Input Dispatch
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587720 (field getter +0x410), FUN_005878a0 (vtable-mediated), FUN_00587710 (state setter)
- **Moddability:** hookable
- **Target:** docs/01-engine-architecture.md

#### FUN_005876c0 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00599958 (constructor, docs/08)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0058aad9 — Semaphore Release (Slot 9)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0058e04b (CritSect leave)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0058c232 — Critical Section Leave
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0058e04b, LeaveCriticalSection
- **Moddability:** hookable
- **Target:** docs/01-engine-architecture.md

#### FUN_00462760 — Buffer Send with Locks
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0057a880, FUN_0057a8e0, FUN_0057a200, FUN_0057a8c0, FUN_0057a8b0
- **Moddability:** hookable
- **Target:** docs/01-engine-architecture.md

#### FUN_0046e7f0 — Polling Loop with Branch
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_004328f0, FUN_00432a10, FUN_00489920, FUN_00432980, FUN_00432180
- **Moddability:** hookable
- **Target:** docs/01-engine-architecture.md

#### FUN_00470670 — UI Screen Constructor (Type 1)
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00466d60, FUN_00486f30, FUN_004670e0
- **Moddability:** hookable
- **Target:** docs/01-engine-architecture.md

#### FUN_00472400 — Virtual Factory + Path Format
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** Virtual factory, FUN_00477280, FUN_0058815f, FUN_0048b810
- **Moddability:** hookable
- **Target:** docs/01-engine-architecture.md

#### FUN_00553310 — Conditional Resource Cleanup
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00587bcf (free/delete), FUN_00540eb0 (object destructor), FUN_004b0170 (general cleanup)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005550c0 — VTable Dispatch Getter
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0055d4f0 — Set UI Property Group with Chain Update
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Globals:** DAT_008b8f28
- **Calls:** FUN_005416a0 (DirectX VB texture coord setup, docs/19)
- **Moddability:** configurable — params 2-4 are caller-supplied values
- **Target:** docs/01-engine-architecture.md

#### FUN_00561620 — Recursive Tree Node Traversal
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00561660 (tree node processor, docs/18-physics-dynamics.md)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057a1e0 — Small Struct Field Init (6 Fields)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057a8c0 — Virtual Dispatch Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057b780 — Object Init with VTable + Field Set
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00587030 (stack/param setup, docs/21)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00581750 — Handle Close with Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** CloseHandle (Win32 API)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005833e0 — Walk Linked List, Call Destructor, Free Nodes
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_005867b0 (SEH-guarded cleanup), FUN_00587bcf (free/delete)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00585380 — VTable Dispatch with Conditional Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00584c70 (callback/resource processor — undocumented), virtual method at vtable+0x38
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00598c4a — Counter Increment Thread-Safe
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0059a54d (critical section enter/lock), FUN_0059a5e9 (critical section leave/unlock)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005994bc — Object Initialization with Buffer/Bounds Setup
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Globals:** DAT_008d5a68
- **Calls:** FUN_00598c70 (init helper A), FUN_00598c1c (init helper B), FUN_0059a4c9 (common init)
- **Moddability:** configurable — param_2 is caller-supplied buffer pointer
- **Target:** docs/01-engine-architecture.md

#### FUN_00599933 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00599b86 (object constructor with vtable setup)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059a473 — Object Init with Buffer/Data Pointer Assignment
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Globals:** DAT_008d5a60
- **Calls:** FUN_00598c70, FUN_00598c1c, FUN_0059a4c9
- **Moddability:** configurable — param_2 is caller-supplied buffer pointer
- **Target:** docs/01-engine-architecture.md

#### FUN_005514c0 — Timer-Based State Update with Cap
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_00556440 — bounds check / timer reset callback - FUN_005565b0 — high-precision timer counter arithmetic (docs/20) - FUN_005514a0 — flag update ...
- **Moddability:** hookable
- **Target:** docs/01-engine-architecture.md

#### FUN_00553630 — Two-Field Setter
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0055bb70 — Partial Struct Zero-Init
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0055d530 — State Field Setter with Global Dirty Flag
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Globals:** DAT_008b8f28
- **Calls:**  - FUN_005416a0 — DirectX Vertex Buffer Texture Coordinate Setup (docs/19), mode 7
- **Moddability:** configurable — param_2 sets the field at +0x50
- **Target:** docs/01-engine-architecture.md

#### FUN_00564780 — Function Pointer Call with Error Handling
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_00564a20 — buffer index computation with stride-based division - FUN_005648c0 — single function call wrapper (error path) - FUN_005649d0 — call...
- **Moddability:** hookable — function pointer at +0xc is pluggable
- **Target:** docs/01-engine-architecture.md

#### FUN_0057a200 — memcpy-like Copy with Word/Byte Split + Size Store
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057a910 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_005855e0 — thread suspend with mutex wait/lock (thread management)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057b7b0 — Conditional Free Based on Flag Bit
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0057b7f0 — VTable pointer init - FUN_00587bcf — free wrapper
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00581780 — Linked List Node Advance
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005834c0 — List Destruction with Virtual Release
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00585550 — Thread Termination with Wait Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00586460 — Destroy Linked List with VTable Destructor Dispatch
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0058a5f7 — N-time callback loop with SEH - FUN_004b0170 — empty stub (render register / callback) - FUN_00587bcf — free wrapper
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00587030 — Object Init with VTable Setup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005982f8 — Bounded String Length with Cap
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00598c70 — Null Check with Virtual Dispatch
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00599534 — Buffer Boundary Marker Check + Set
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c53e — SEH Unwind (Free EBP-0x14)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c666 — SEH Unwind (Free EBP+8)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c464 — SEH Unwind (Free EBP-0x30)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059ca10 — SEH Unwind (Free EBP-0x10)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c7e0 — SEH Unwind Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c91e — SEH Unwind Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059cb48 — SEH Unwind Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059cd00 — SEH Unwind Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059ced7 — SEH Unwind Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059d036 — SEH Unwind Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059d09c — SEH Unwind Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059d1a8 — SEH Unwind Release Locale Refcount
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059d3cc — SEH Unwind Conditional Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0045ebd0 — Linked List Purge by Threshold (0x40)
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Moddability:** hardcoded (threshold 0x40)
- **Target:** docs/01-engine-architecture.md

#### FUN_004646f0 — Conditional Destructor
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_004698c0 — Destructor with Sub-Object Free
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0048e890 — Resource Cleanup (Free + Zero)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0048fdf0 — Conditional Dispatch with Cleanup
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00490aa0 — Linked List Node Prepend
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00491960 — Dual Dispatch with Guard
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00494620 — Callback Registration
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_004952e0 — Destructor with Conditional Free
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00496840 — Linked List Summation with Iterator
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00497d00 — Two-Field Setter
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** configurable
- **Target:** docs/01-engine-architecture.md

#### FUN_00498e30 — Field Getter (+0x48)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00499520 — Linked List Virtual Dispatch
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_004b4470 — File Handle + Close Registration
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_004b5760 — Linked List Iterator with State Update
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_004b9d20 — Float Comparison with Fallback
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_004ba950 — Conditional Allocation
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_004bf640 — Linked List Destruction
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_004c2850 — Linked List Dereference
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_004cb5a0 — Array Element Removal (Swap-Out)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0050af3b — Object Init with VTable (alloc 0x20)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0050fb3b — State Machine with Dispatch
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Moddability:** hookable
- **Target:** docs/01-engine-architecture.md

#### FUN_00511b5c — Conditional Dispatch with Guard
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057b6c0 — Setter at +0x24
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00598994 — Ref Count Decrement with Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Globals:** DAT_005e9ef4
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00553980 — Object Constructor with Allocation and Sub-Init
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - operator_new(0x24) — heap alloc, 36 bytes - FUN_005532a0 — Object allocation with zero-init (constructor) - FUN_00553370 — Sub-object init - FUN_00...
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005563e0 — Timer Start via QueryPerformanceCounter
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - QueryPerformanceCounter — Win32 high-res timer - FUN_0055687b — Alternative timer start wrapper
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00558990 — Resource Teardown with State Array Reset
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_00540eb0 — Resource release - FUN_00587bcf — Free wrapper (FUN_0058aa6f) - FUN_00541040 — Resource release - FUN_00587bcf — Free wrapper
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0055bba0 — Linked List Free with Traversal and Nulling
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — Free wrapper (FUN_0058aa6f)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057a230 — Byte-Aligned Memory Copy from Struct
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** none
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057a920 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00585680 — target function
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0057b7d0 — Object Copy-Init with VTable Setup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587090 — Base initialization
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00581880 — Linked List Destruction with VTable Release Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — Free wrapper (FUN_0058aa6f)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00583530 — Zero-Fill Memory Region with Step
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00586000 — Pre-init call - FUN_00583210 — Per-block zero-fill
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00587070 — Destructor with Conditional Free
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_005870d0 — Base cleanup - FUN_00587bcf — Free wrapper
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005921c5 — Lazy-Init Singleton with Flag Guard
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0058dfea — Acquire lock (type 0xb) - FUN_005921f3 — Actual initialization routine - FUN_0058e04b — Release lock
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00595524 — String Parse via Delegate
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_005953b8 — String parse implementation
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0040d0b0 — Mode-Dispatched Subsystem Call
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0040a610 — Subsystem call with mode parameter
- **Moddability:** configurable — DAT_007cfdc4 controls routing
- **Target:** docs/01-engine-architecture.md

#### FUN_0040e1f0 — Global Vector Offset Update
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0054c210 — Get vehicle/object count - FUN_0054c230 — Get vehicle by index - FUN_0054e100 — Get part count for vehicle - FUN_0054e120 — Get part...
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00461ed0 — Directory String Processing with Decode
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - _strncpy — CRT string copy - FUN_00587c20 — String decode/parse - FUN_005897ca — String processing - FUN_00587ece — String/ID conversion - FUN_0056...
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005539f0 — Resource Cascade Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0055c2e0 (list unlink), FUN_00553310 (resource cleanup), FUN_00587bcf (free)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_005818e0 — List Destruction with Handle Close
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** CloseHandle, vtable[0] (destructor), FUN_00587bcf (free)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00583570 — List Destruction with COM Release
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0058a5f7 (SEH callback), FUN_0047aa60 (math), FUN_00587bcf (free)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00585680 — Thread Resume with Mutex Wait
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** WaitForSingleObject, ReleaseMutex, ResumeThread, Sleep, FUN_00583680 (timing), FUN_00583660 (timing)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00586500 — Mutex Create/Recreate
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** CloseHandle, CreateMutexA
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059247a — Critical Section Guarded Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0058dfea (critsect enter), FUN_0059249b (operation), FUN_0058e04b (critsect leave)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059557d — String Parse with Format
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00596245 (format/parse), FUN_0059553a (delegation)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00471a00 — Object Constructor
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_00560c00 — State Flag Setter + Cleanup
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_004b0170 — general cleanup/release signal (docs/01, docs/20)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059a541 — Cleanup Callback Registration
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587b3e — MSVC _atexit-like deferred callback registration (docs/01) - FUN_00599796 — empty stub / locale refcount release (no-op, docs/20)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c50e — SEH Unwind: Free Object at EBP-0x3C
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — heap memory free wrapper (docs/20)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c6ca — SEH Unwind: Free Object at EBP+8
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — heap memory free wrapper (docs/20)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c846 — SEH Unwind: Call FUN_00581ad0 Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00581ad0 — close handle + destroy linked list + free nodes (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059caa0 — SEH Unwind: Call FUN_0047aa60 Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0047aa60 — empty stub / small destructor / no-op (docs/20)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059cb40 — SEH Unwind: Call FUN_00583270 Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00583270 — linked list destructor with vtable cleanup (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059cb88 — SEH Unwind: Call FUN_00583050 Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00583050 — destroy linked list with SEH, call destructors (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059cd88 — SEH Unwind: Call FUN_005819c0 Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_005819c0 — linked list destroy with vtable destructor (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059ce40 — SEH Unwind: Call FUN_004b0170 Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_004b0170 — general cleanup/release signal (docs/01, docs/20)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059cea2 — SEH Unwind: Call FUN_00586240 Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00586240 — linked-list destruction with SEH + alloc cleanup (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059d0b2 — SEH Unwind: Call FUN_0047aa60 Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0047aa60 — empty stub / small destructor / no-op (docs/20)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059d110 — SEH Unwind: Call FUN_00586460 Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00586460 — destroy linked list with vtable destructor dispatch (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059d248 — SEH Unwind: Conditional Call FUN_00598aea
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00598aea — vtable set + sub-call cleanup (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059ae24 — Exception Destructor SEH Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0058a5d8 -- SEH handler init / stack probe (docs/20-math-utilities.md) - FUN_005993af(1) -- Reference count decrement with conditional free (do...
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c414 — SEH Unwind: Free Field at -0x48
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf -- Memory free/deallocation (docs/08, docs/20)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c620 — SEH Unwind: Free Object at +8
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf -- Memory free/deallocation (docs/08, docs/20)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c980 — SEH Unwind: Call FUN_00581880
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00581880 -- Linked list destruction with vtable release (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059cc88 — SEH Unwind: Call FUN_00582f60
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00582f60 -- SEH-protected linked list destruction (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059d058 — SEH Unwind: Call FUN_00583650
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00583650 -- Single function call wrapper (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059d358 — SEH Unwind: Call FUN_00599796 (Cleanup with Descriptor)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00599796 -- Cleanup with type descriptor / empty stub (docs/20-math-utilities.md) - DAT_008d4400 -- Global type descriptor
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c4d2 — SEH Unwind Free Object at -0x1c
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — heap free / memory deallocation
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c52c — SEH Unwind with Single Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00506ccc — Vtable Set + Free Child / destructor continuation
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c582 — SEH Unwind Free Object at -0x24
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — heap free / memory deallocation
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c5d0 — SEH Unwind Free Object at +8
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — heap free / memory deallocation
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c6fc — SEH Unwind Free Object at +8
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — heap free / memory deallocation
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059c910 — SEH Unwind: Call FUN_00581a20
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00581a20 — Handle Close + Linked-List Destruction with VTable Release (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059ca80 — SEH Unwind: Call FUN_0047aa60
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0047aa60 — Empty stub / no-op cleanup function (docs/20)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059cc60 — SEH Unwind Free Object at -0x14
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — heap free / memory deallocation
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059cd80 — SEH Unwind: Call FUN_005834c0
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_005834c0 — List Destruction with Virtual Release (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059d427 — SEH Unwind: Call FUN_00598c70
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00598c70 — Null Check with Virtual Dispatch (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059d484 — SEH Unwind: Destroy Exception Object
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - exception::~exception (MSVC C++ exception destructor)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

#### FUN_0059d508 — SEH Unwind: Call FUN_0059ac3f
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0059ac3f — VTable Pointer Setter / constructor helper (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/01-engine-architecture.md

### docs/20-math-utilities.md (284 entries)

#### FUN_004bd7f0 — Object Cleanup (Thunk Target FUN_004bd800)
- **Source:** unknown | Confidence: high (Memory/Cleanup pattern)
- **Key Logic:** 
- **Calls:** FUN_00587bcf (memory free/dealloc, per docs/08)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_005564b0 — QueryPerformanceCounter Wrapper with Mode Dispatch
- **Source:** unknown | Confidence: high (Timer/Perf pattern)
- **Key Logic:** 
- **Calls:** QueryPerformanceCounter (Win32 API), FUN_0055687b (timer finalize/read, per docs/06)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0055be60 — Global Call with Fixed Argument
- **Key Logic:** 
- **Globals:** DAT_008b8f28
- **Calls:** FUN_00555e50 (unknown)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_005819c0 — Linked List Destroy with Vtable Destructor Call
- **Source:** unknown | Confidence: high (Memory/Cleanup pattern)
- **Key Logic:** 
- **Calls:** FUN_00587bcf (memory free/dealloc, per docs/08)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00586560 — Mutex Create/Replace Wrapper
- **Source:** unknown | Confidence: high (System/Threading pattern)
- **Key Logic:** 
- **Calls:** CloseHandle, CreateMutexA (Win32 API)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00587a60 — Free Callback Registered Cleanup (2)
- **Source:** unknown | Confidence: high (Memory/Free pattern)
- **Key Logic:** 
- **Calls:** FUN_00587b3e (deferred function registration, _atexit-like)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0058ef48 — Conditional Free if Handle Not -1
- **Source:** unknown | Confidence: high (Memory/Cleanup pattern)
- **Key Logic:** 
- **Calls:** FUN_00596888 (cleanup/release function — unknown)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059964a — Buffer Allocation with Size Rounding
- **Source:** unknown | Confidence: medium (Mem/Alloc pattern — degraded decompilation uses unaff_EBP)
- **Key Logic:** 
- **Calls:** FUN_0058a5d8 (stack probe/SEH init), operator_new (malloc), FUN_005996ae (buffer size management, per decompiled_full_index)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059af17 — C++ Exception Throw Wrapper
- **Source:** unknown (MSVC CRT) | Confidence: high (Except pattern)
- **Key Logic:** 
- **Calls:** FUN_0059af50 (exception prep), __CxxThrowException_8 (MSVC throw)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059c582 — SEH Unwind Handler (Free Field at EBP-0x24)
- **Source:** MSVC CRT | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf (memory free/dealloc)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059cb88 — SEH Unwind Handler (Call FUN_00583050)
- **Source:** MSVC CRT | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00583050 (unknown cleanup)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059cd48 — SEH Unwind Handler (Call FUN_005833e0)
- **Source:** MSVC CRT | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_005833e0 (unknown cleanup)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059cf03 — SEH Unwind Handler (Call FUN_005833e0, duplicate)
- **Source:** MSVC CRT | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_005833e0 (unknown cleanup)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059d1e8 — SEH Unwind Handler with Exception Cleanup
- **Source:** MSVC CRT | Confidence: high
- **Key Logic:** 
- **Globals:** DAT_008d42d8
- **Calls:** FUN_00599796 (cleanup with type descriptor)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059d6ff — Flag Set with Boolean-to-Float Conversion
- **Source:** unknown | Confidence: high (GameLogic pattern)
- **Key Logic:** 
- **Calls:** FUN_004c7774 (post-update callback — unknown)
- **Moddability:** configurable (controls float parameter via boolean)
- **Target:** docs/20-math-utilities.md

#### FUN_004bd800 — Struct Cleanup (9 fields)
- **Key Logic:** 
- **Target:** docs/20-math-utilities.md

#### FUN_00586000 — Linked-List Node Append
- **Key Logic:** 
- **Target:** docs/20-math-utilities.md

#### FUN_0055bf70 — Array of Pointers Cleanup with Free Loop
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0055bba0 — Linked-list free with traversal - FUN_00557470 — No-op stub - FUN_00587bcf — Free wrapper (calls FUN_0058aa6f)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00587a90 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00599958 — (lookup needed)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0058b59f — GetSystemTimeAsFileTime to 64-bit Tick
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Globals:** DAT_008d3ec0
- **Calls:** GetSystemTimeAsFileTime (Win32 API), __allmul (MSVC CRT)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0058ef5f — Increment Wrapper Around Call Loop
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0058ef2e — (lookup needed) - FUN_00589bf3 — (lookup needed, condition test)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059d7b5 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0043fffb — (lookup needed)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0040d240 — Game State Dispatch Chain
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** Multiple game state functions (per triage index)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059a781 — Exception Object Constructor (Copy String)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0058a5d8 — SEH prolog - FUN_0059bf56 — string copy helper - FUN_005993af — refcount increment - FUN_0059a9ca — string/encoding setup - DAT_005b...
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059c964 — SEH Unwind Cleanup Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0047a800 — math_util (short computation)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0050fdf3 — OS Version Detection (GetVersionEx)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** GetVersionExA, IsProcessorFeaturePresent, FUN_0050fd4e, FUN_0050fd16
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00553db0 — Struct Init with Default Values
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0055f060 — GlobalMemoryStatus Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - GlobalMemoryStatus — Win32 kernel32 API
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00564930 — Accumulator with Realloc on Growth
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0058b5d4 — memory reallocation wrapper (docs/06)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0057aa70 — Cleanup Wrapper with SEH
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587b3e — boolean-to-int conversion wrapper (triage index)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00586620 — Node Destruction with Virtual Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00588f66 — Batch Function Call over Varargs
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0058fcb0 — strncpy replacement, copies N chars and null-terminates (docs/20)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0058b75f — Mutex Unlock Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0058e04b — CriticalSection leave (triage index line 6852)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_005996ae — Buffer Size Management with Copy
- **Source:** unknown | Confidence: low (register variables unaff_ESI/EBP/EDI — partial decompilation)
- **Key Logic:** 
- **Calls:**  - FUN_0058cc00 — memmove backward/forward copy (triage index) - FUN_005993af — reference count decrement and conditional free (triage index line 7365...
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059c6a2 — SEH Unwind Free Object at +8
- **Source:** unknown | Confidence: low (register variable unaff_EBP)
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — free/operator delete
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059d086 — SEH Unwind Cleanup Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0047aa60 — small destructor (triage index)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059d948 — Global Flag Setter via Function Call
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Globals:** DAT_005c7530
- **Calls:**  - FUN_0049bad0 — math_util short computation (triage index line 2216) - FUN_004dbac3 — unknown
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00553de0 — Struct Zero-Init Constructor
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0053c2a0 — math_util (3 lines, parent constructor) - FUN_00553db0 — subsystem init
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0055c2e0 — Doubly-Linked List Node Unlink by Match
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0057bc70 — Single VTable Pointer Set
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** none
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00587230 — Counter Increment/Decrement by Flag
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00598de3 — Memory Copy from ID Lookup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0059942b — data lookup/initializer by ID (reads globals DAT_005b9cd8, DAT_005b9cdc, DAT_008d5a6c)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059c446 — SEH Unwind: Free Object at EBP-0x14
- **Source:** runtime | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf — memory free
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059c5b2 — SEH Unwind: Free Object at EBP+8
- **Source:** runtime | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf — memory free
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059c6ac — SEH Unwind: Free Object at EBP+8
- **Source:** runtime | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf — memory free
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059c83e — SEH Unwind: Call FUN_00581a80
- **Source:** runtime | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00581a80 — pool/resource cleanup function
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059c988 — SEH Unwind: Call FUN_005822b0
- **Source:** runtime | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_005822b0 — pool/resource cleanup function
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059cd80 — SEH Unwind: Call FUN_005834c0
- **Source:** runtime | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_005834c0 — pool/resource cleanup function
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059cf21 — SEH Unwind: Call FUN_00586170
- **Source:** runtime | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00586170 — pool/resource cleanup function
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059d091 — SEH Unwind: Call FUN_0047aa60
- **Source:** runtime | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0047aa60 — game logic cleanup function
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059d224 — SEH Unwind: Conditional Call FUN_00598aea
- **Source:** runtime | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00598aea — cleanup function
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00407dd0 — Short Computation / Linked List Walker with Progress Callback
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00406640 — progress/callback function
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0040fd70 — Short Computation / VTable Init + Thunk
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** thunk_FUN_00568f20 — struct initializer thunk
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00418c10 — Memory Allocation / Nested Pointer Free with Conditional Dealloc
- **Source:** memory manager | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00414d70, FUN_00587bcf (×9+)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_004562c0 — Short Computation / Destructor with VTable Reset
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf (conditional ×2)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00462140 — Short Computation / Refresh Flag Clear
- **Source:** track/scene | Confidence: high
- **Key Logic:** 
- **Globals:** DAT_007cd2a0
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0046a530 — Short Computation / Destructor VTable Reset + Free
- **Source:** game logic | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf, FUN_00489440
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_004733a0 — References Global State / Object Constructor
- **Source:** game logic | Confidence: high
- **Key Logic:** 
- **Globals:** DAT_007d02e4, PTR_DAT_005be704, DAT_005c32c8
- **Calls:** FUN_00466d60, FUN_00486f30 (×4)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00478200 — Short Computation / Game Command Dispatch
- **Source:** game logic | Confidence: high
- **Key Logic:** 
- **Globals:** DAT_007cd8c0
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0047a9e0 — Unidentified / UI Object Init
- **Source:** UI/game logic | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00485e30
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00487720 — Short Computation / State Value Transform
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00486720 — state getter
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00498560 — Unidentified / String Copy to Struct Buffer
- **Source:** UI/text | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00566810, _strncpy
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0049a150 — Short Computation / Linked List Nth Element
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_004b2100 — Unidentified Logic / Linked List Destructor
- **Source:** resource manager | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf (×many)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0052e5b0 — Short Computation / Callback Registration
- **Source:** initialization | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587b3e — callback registration
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0055bde0 — Unidentified Logic / Linked List Indexed Traversal
- **Source:** data structure | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00583270 — Unidentified Logic / Linked List Destructor with VTable Cleanup
- **Source:** resource manager | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf, virtual destructor at vtable+0(3)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059aaa3 — Short Computation / Callback Registration
- **Source:** initialization | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587b3e — callback registration
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059c620 — SEH Unwind: Free at EBP+8
- **Source:** runtime | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059cc88 — SEH Unwind: Thunk to FUN_00582f60
- **Source:** runtime | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00582f60
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_005504d0 — Indexed Array Lookup with Bounds Check
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_00551dd0 — flag/bit manipulation
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00563ec0 — Switch Param Store + Global Set
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00564a00 — update/refresh
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0057a580 — VTable Call via Offset 0x6c
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00585d20 — Mutex-Protected Pointer Read + Release
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** WaitForSingleObject, ReleaseMutex (Win32 API)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00587bcf — Free Wrapper (Thunk to FUN_0058aa6f)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0058aa6f — heap deallocation function
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0058d82c — Int Peek from Pointer
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00593839 — Multi-Arg Rendering Dispatch with Layout
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - Renders via function pointer PTR_005bd9f8
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00598775 — Vtable Fixup with Destructor
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00598aea — destructor/cleanup
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00599e66 — VTable Pointer Setter
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059b07a — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587b3e — cleanup dispatcher
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059c45a — SEH Unwind Handler
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf — operator delete wrapper
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059c5c6 — SEH Unwind Handler
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059c9a0 — SEH Unwind with Single Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0047aa60 — empty stub
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059cd88 — SEH Unwind Cleanup Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_005819c0
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059cf3d — SEH Unwind Handler
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_005861e0
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059d984 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_004e9537
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_005505a0 — Linked-List Animation Timer Decrement
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** None directly (pure struct manipulation)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00587310 — Binary Packet Field Parser with Offset Math
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_00587510 — Validation function
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_005938b4 — SEH Wrapper Around CRT Function Call
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0058e0c7 — TLS value retrieval - FUN_0058a3b6 — Target function - FUN_00593981 — SEH cleanup/destroy
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00598794 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0058ace6 — Resource lookup (primary) - FUN_00535550 — Resource lookup (secondary/fallback)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_005649d0 — Call Chain Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00564890 — Prepare/setup call - FUN_00564960 — Primary operation call
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_005544c0 — Game State Setting via Virtual Dispatch
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Globals:** DAT_008b89a0
- **Calls:** none direct — virtual dispatch through DAT_008b89a0
- **Moddability:** hookable — state dispatch via global virtual device
- **Target:** docs/20-math-utilities.md

#### FUN_0059c6d4 — SEH Unwind Free Object at +8 (Duplicate)
- **Source:** CRT / MSVC runtime | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — heap memory free
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059c9d0 — SEH Unwind Cleanup Call
- **Source:** CRT / MSVC runtime | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0047aa60 — cleanup function
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059d0bd — SEH Unwind Cleanup Call (dup)
- **Source:** CRT / MSVC runtime | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0047aa60 — cleanup function
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059dad5 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_004e513e — target function
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_004066c0 — Mutex-Protected Value Read with Timeout
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - WaitForSingleObject — Win32 API - ReleaseMutex — Win32 API
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00548eb0 — Multi-List Free with Traversal
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_004b0170 — pre-free callback - FUN_00587bcf — heap free - FUN_00549110 — custom per-node cleanup (5th list)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0056cf10 — Quad-Pointer Free
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf (up to 4 times)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059ae7d — C++ Object Constructor with Vtable
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0058a5d8 — SEH init - FUN_0059bf56 — source setup - FUN_005993af — init - FUN_0059a9ca — field init
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00554510 — Enum-to-ID Mapping with VTable Notify
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Globals:** DAT_008b89a0
- **Calls:**  - Virtual call at (*DAT_008b89a0 + 0xFC) — state notification dispatcher (docs/08)
- **Moddability:** hookable
- **Target:** docs/20-math-utilities.md

#### FUN_00561f60 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00562ac0 — target function (unknown, no doc entry found)
- **Moddability:** hookable
- **Target:** docs/20-math-utilities.md

#### FUN_0058bbd2 — Lock Release by Index (CritSect leave #9)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0058e04b(9) — CritSect leave for critical section #9 (docs/20)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00593bbd — SEH-Wrapped Render Dispatch Call
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0058a323 — atomic LOCK/UNLOCK with indirect call (docs/20, triage: Sync/Lock) - ExceptionList — SEH handler registration
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_005987ff — Callback Registration (atexit-style)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587b3e (callback registration)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059c48c — SEH Unwind: Free Object at -0x2C
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059ce00 — SEH Unwind (Call FUN_005819c0)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059daef — Single Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hookable
- **Target:** docs/20-math-utilities.md

#### FUN_005507d0 — Refcount Decrement / Resource Release Wrapper
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_0053b4a0 (refcount decrement / resource release — resource manager context)
- **Target:** docs/20-math-utilities.md

#### FUN_0055687b — RDTSC Timestamp Read
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** None
- **Target:** docs/20-math-utilities.md

#### FUN_0055cdf0 — Triple Vtable Query and Store
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** subsystem vtable+0x98 (query by ID into buffer), subsystem vtable+0xa4 (direct query into buffer)
- **Target:** docs/20-math-utilities.md

#### FUN_00584c70 — Thread-Safe Call with Mutex
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** WaitForSingleObject, ReleaseMutex (Win32 API), FUN_00586000 (protected operation)
- **Target:** docs/20-math-utilities.md

#### FUN_0058bc4d — Critical Section Leave (Slot 9)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0058e04b (indexed critical section release)
- **Target:** docs/20-math-utilities.md

#### FUN_00597218 — Lazy-Init Singleton with Flag Guard
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Globals:** DAT_008d5a4c
- **Calls:** FUN_00596e40 (subsystem initialization with parameter -3/0xfffffffd)
- **Target:** docs/20-math-utilities.md

#### FUN_0059a371 — Sub-call + Conditional Free
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00599d17, FUN_00587bcf (free)
- **Target:** docs/20-math-utilities.md

#### FUN_0059db09 — Flag/State Setter with 3 Special-Case Values
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_004e23ad (notification/update after state change)
- **Target:** docs/20-math-utilities.md

#### FUN_0040e990 — Struct Init with Float Constants and Sub-calls
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00459950, FUN_00459990, FUN_0040e770
- **Target:** docs/20-math-utilities.md

#### FUN_00418df0 — Linked List Destructor with Conditional Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_004190c0, FUN_00587bcf
- **Target:** docs/20-math-utilities.md

#### FUN_00421a50 — Dual Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00421890, FUN_00566650
- **Target:** docs/20-math-utilities.md

#### FUN_00454d30 — Parameter Lookup with Fallback
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00454350, FUN_004541d0
- **Target:** docs/20-math-utilities.md

#### FUN_0045d500 — Guarded Init Call
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Globals:** DAT_007ce260
- **Calls:** FUN_0045d240
- **Target:** docs/20-math-utilities.md

#### FUN_00485660 — Destructor with Conditional Free
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00487250, FUN_00587bcf
- **Target:** docs/20-math-utilities.md

#### FUN_004902c0 — Linked List Destructor with VTable Notification
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** vtable+0, FUN_00587bcf, FUN_00485eb0
- **Target:** docs/20-math-utilities.md

#### FUN_00495060 — Guarded Subsystem Release
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Globals:** DAT_007cde1c
- **Calls:** FUN_00554d70
- **Target:** docs/20-math-utilities.md

#### FUN_004975b0 — Set + Init Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00498eb0
- **Target:** docs/20-math-utilities.md

#### FUN_00499140 — Constructor with VTable and Sub-init
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00498d20
- **Target:** docs/20-math-utilities.md

#### FUN_0049ed10 — Guarded Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00553700
- **Target:** docs/20-math-utilities.md

#### FUN_004b3d50 — Callback Registration
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587b3e
- **Target:** docs/20-math-utilities.md

#### FUN_004baeb0 — Linked List Destructor with Callback
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_004b0170, FUN_00587bcf
- **Target:** docs/20-math-utilities.md

#### FUN_004c8f80 — VTable Dispatch with Negation
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_0054b950, vtable+4
- **Target:** docs/20-math-utilities.md

#### FUN_0050b3d1 — VTable Setter with Sub-init (Type 3)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00507496
- **Target:** docs/20-math-utilities.md

#### FUN_00511457 — State Counter with Dispatch
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_005110fc, vtable+4, vtable+0x14
- **Target:** docs/20-math-utilities.md

#### FUN_0053cac0 — Object Allocation with Init
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** operator_new, FUN_005473d0, FUN_00547400
- **Target:** docs/20-math-utilities.md

#### FUN_005474d0 — Resource/Object Creation with Config
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00548890, operator_new, FUN_00546250, FUN_00546330, FUN_0054fb90, FUN_00547100, FUN_0054fc10, FUN_00546f30, FUN_00546f70, FUN_00547670
- **Target:** docs/20-math-utilities.md

#### FUN_00566d30 — Conditional Alloc/Init Dispatch
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00587f64, FUN_00535390
- **Target:** docs/20-math-utilities.md

#### FUN_005871c0 — Dual Query into Two Output Params
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00596175
- **Target:** docs/20-math-utilities.md

#### FUN_0059b086 — Callback Registration
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587b3e
- **Target:** docs/20-math-utilities.md

#### Unwind_0059c730 — SEH Unwind Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf
- **Target:** docs/20-math-utilities.md

#### Unwind_0059ce7e — C++ Unwind Helper Thunk
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00585f30
- **Target:** docs/20-math-utilities.md

#### FUN_00556900 — Add Float to Animation Channels
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** none
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00560b90 — Conditional Free of Field
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf (memory free, docs/20)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0057a730 — Two-Step Init Sub-Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00585320 � list iteration with dispatch (docs/20) - FUN_00585de0 � queue APC call (docs/20)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00585f30 — Handle Close with Flag Check
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** CloseHandle (Win32), FUN_00583650 (call wrapper, docs/20)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00587460 — Array/Struct Alloc with Count + Init
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_005874d0 � operator new with result check (docs/20)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0058a677 — N-Time Callback Loop with SEH
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** (*param_4)() � user-supplied callback function pointer
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00593c50 — CRT __CallSettingFrame@12
- **Source:** MSVC CRT | Confidence: high
- **Key Logic:** 
- **Calls:** __NLG_Notify1 (MSVC NLG runtime), function pointer dispatch
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00598a41 — Vtable/Cctor Init
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0058a5d8 � SEH handler init (docs/20) - FUN_0059a8fa � vtable/constructor helper (docs/18)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00599822 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00599e66 � vtable pointer setter/constructor (docs/20)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00556930 — Recursive State Traversal with Flag Check
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Globals:** DAT_008b8e34
- **Calls:**  - FUN_00556980 — node processing callback (unknown, same module) - FUN_00556930 (self) — recursive call on child
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0057dbb0 — Vtable Call + Format Dispatch + Timer Dispatch Chain
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - Virtual method (slot 0x58) — vtable dispatch - FUN_00586800 — renderer message begin (docs/19) - FUN_00584f90 — mutex-guarded timer read (triage: S...
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00585f60 — Mutex Wait with Success Check
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - WaitForSingleObject — Win32 API
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059c706 — SEH Unwind Free Object at +8
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — free/delete operator
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059ca80 — SEH Unwind with Single Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0047aa60 — array destructor / small destructor (docs/19)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059cc6b — Unwind Handler (SEH)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — free/delete operator
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059d508 — SEH Unwind Cleanup Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0059ac3f — vtable pointer setter / constructor
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00598aa0 — Status Check with Error Dispatch
- **Source:** unknown | Confidence: low
- **Key Logic:** 
- **Calls:**  - Virtual method (slot 0x2c) — status check - FUN_0059a5fe — error dispatch (unknown)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0058a6eb — N-Time Callback Loop with SEH
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - (*param_4)() — callback function pointer - FUN_0058a755 — SEH unwind/epilogue handler
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0040c610 — Conditional Mode Dispatch with Global Gate
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Globals:** DAT_007cfcc8
- **Calls:**  - FUN_0040cde0 — game action state machine (docs/01, 06, 07, 09, 18)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_005874d0 — operator new with Result Check
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - operator_new — heap allocation (C++ operator new)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00562890 — Buffer Zero-Init with Virtual Method Call
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - (*(param_1+0xd0))(*(param_1+0x100)) — virtual method dispatch - FUN_00562710 — string duplication with character replacement (docs/06)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_005596e0 — Function Pointer Dispatch via Linked Traversal
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00587580 — Buffer Query: Return Ptr+Size If Valid
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00585770 — target function
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00565dc0 — Allocate Struct with Default Values
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hookable (default values)
- **Target:** docs/20-math-utilities.md

#### FUN_0057a810 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00585770 — target function
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0058a755 — Conditional Callback with SEH
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - __startOneArgErrorHandling -- CRT error handler
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_005569f0 — Scene Node State Update with Transform
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Globals:** DAT_008b8f24
- **Calls:**  - FUN_00551760 — scene begin update - FUN_0054b570 — Euler-angle to 4x4 transform matrix (docs/19) - FUN_0054d9f0 — bounding box computation (docs/19...
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_005697f0 — Triple Buffer Allocation
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - operator_new — C++ allocation operator (malloc wrapper)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0057a830 — VTable Boolean Test Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - (vtable+0x9c) — virtual method returning char/byte
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00584ff0 — String Copy to Buffer with Length Cap
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - _strncpy — CRT string copy with length limit
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00589d74 — Critical Section Leave (Slot 0xd)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0058e04b — CritSect leave by slot index (docs/20, docs/21)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00593db8 — Global Callback Dispatcher with Null Check
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Globals:** DAT_008d41b4
- **Calls:**  - (indirect) callback via DAT_008d41b4
- **Moddability:** hookable — replaceable via global function pointer
- **Target:** docs/20-math-utilities.md

#### FUN_005998a1 — VTable Fixup During Construction
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00599be5 — sub-object initializer
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0040dcd0 — State Machine Initializer
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0040d490 — preparation step - FUN_00568210 — section/entry lookup - FUN_0040ddf0 — processing step
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_005511a0 — Object Destructor with Array Cleanup
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_00557470 — resource release/unload (per element, per docs/06, docs/17, docs/19) - FUN_00587bcf — memory free/deallocation (per docs/01, docs/06...
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00551390 — Per-Entity Data Block Copy from Parameter Table
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0053b4c0 — copy/init call (unknown, triage: unidentified logic) - FUN_0054b330 — BitmaskClear on scene graph node (docs/06)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00559a40 — Large Buffer Zero-Init (0x60 Dwords)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0058dfea — Critical Section Lazy Init + Enter
- **Source:** CRT/threading support | Confidence: high
- **Key Logic:** 
- **Globals:** DAT_005e6c80
- **Calls:**  - _malloc — CRT allocator - InitializeCriticalSection (Win32 API) - EnterCriticalSection (Win32 API) - __amsg_exit — CRT error on allocation failure ...
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00594b76 — Memory Region Validation & Heap Lookup
- **Source:** CRT heap internals | Confidence: medium
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059ac3f — VTable Pointer Setter
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059c8d8 — SEH Unwind Cleanup Call
- **Source:** CRT/exception handling | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0057bc70 — single vtable pointer set (triage: Entity/Vtable set)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059d544 — SEH Unwind with Single Call
- **Source:** CRT/exception handling | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0059a9c2 — single function call wrapper (triage: Engine/Call)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00554d70 — UI Cleanup Iterator
- **Source:** unknown | Confidence: low
- **Key Logic:** 
- **Calls:**  - FUN_00554610(0) — dispose/cleanup helper (renderer, docs/19) - Vtable dispatch at +0xf0 — get item by index - Vtable destructor at +8 — dispose ite...
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00564690 — String Malloc + Copy (strdup)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** `_malloc` — CRT heap allocation
- **Moddability:** hookable — source string passed as parameter
- **Target:** docs/20-math-utilities.md

#### FUN_005684a0 — Object ID Lookup Across 9 Arrays
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_00568220 — hash table entry search (docs/08-file-formats) - FUN_0049adb0 — linked list node traversal helper - FUN_004979d0 — get object ID/has...
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0057e7e0 — Mutex-Protected Linked List Destruction
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - WaitForSingleObject — Win32 API - ReleaseMutex — Win32 API - FUN_00587bcf — memory deallocation (operator delete)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0058a02c — Memory Block Validation Check
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0058a05a — memory block base validation - FUN_00592891 — error/overflow flag check (docs/06)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0058c1e0 — Critical Section Enter
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0058dfea — enter critical section by index - EnterCriticalSection — Win32 API
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00598bbc — Object Constructor with SEH + VTable Init Chain
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0058a5d8 — SEH handler init / stack probe - FUN_00598c1c — sub-init (constructor chain) - FUN_0059a4c9 — sub-init (constructor chain) - FUN_005...
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_005998e5 — VTable Set + Sub-Call
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00599be5 — init continuation
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_004a11b0 — Global Flag Clear
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0057a8b0 — VTable Call via Offset 0x7c
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** Virtual call via vtable+0x7c
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0057ee80 — Thread-Safe Mutex Queue with Timed Wait
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** WaitForSingleObject, ReleaseMutex, FUN_0057b840 (msg compare), FUN_005871f0 (field read)
- **Moddability:** hookable
- **Target:** docs/20-math-utilities.md

#### FUN_0058e060 — TLS Allocation + Thread ID Init
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0058dfc1, TlsAlloc, TlsSetValue, GetCurrentThreadId, FUN_0058ab58 (CRT alloc), FUN_0058e0b4 (init)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00599913 — Free Callback Registration
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587b3e (atexit-like registration, docs/06/17/18)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059ac7f — Object Teardown with Iterator Cleanup
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_0058a5d8, FUN_0059a54d, FUN_00598c88, FUN_0058aa6f, FUN_0059a5e9, FUN_005993af
- **Moddability:** hookable
- **Target:** docs/20-math-utilities.md

#### FUN_00408260 — Callback Registration
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587b3e (atexit-like)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0040e170 — Tick/Update Dispatch
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_004347c0, FUN_004186a0 (session update), FUN_0040da30
- **Moddability:** hookable
- **Target:** docs/20-math-utilities.md

#### FUN_00464670 — Conditional Object Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0057a8b0, FUN_0057ab20, FUN_0045d510
- **Moddability:** hookable
- **Target:** docs/20-math-utilities.md

#### FUN_00473f50 — UI Screen Constructor (Type 2)
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00466d60, FUN_00486f30 (x3)
- **Moddability:** hookable
- **Target:** docs/20-math-utilities.md

#### FUN_00478090 — Virtual Factory + Store
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** Virtual factory via DAT_007cd8c0+0x1c
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00585810 — Mutex-Protected Worker Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** WaitForSingleObject, FUN_00587210, ReleaseMutex
- **Moddability:** hookable
- **Target:** docs/20-math-utilities.md

#### FUN_00599c58 — C++ Constructor with SEH
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_0058a5d8, FUN_0059a8fa
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0050f6f2 — VTable Dtor + Null Fields
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** Virtual method at vtable+0x28 on subobject (destructor/cleanup)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_005575f0 — Flag Check with Conditional Path Dispatch
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00558310 (handler A — unknown), FUN_0047abb0 (deactivation handler, docs/06)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00586240 — Linked-List Destruction with SEH + Alloc Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_004b0170 (general object cleanup/release), FUN_00587bcf (free/delete)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0058ab31 — Lock Release by Index (CritSect 9)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0058e04b (CritSect leave, index 9)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059ad3d — Free Callback Registered Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587b3e (callback/deferred function registration), FUN_00599796 (target cleanup function)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00407070 — Array + Linked-List Virtual Dispatch Iterator
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00414420 — Multi-Pointer Free (5 pointers)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00414fe0 (text format struct cleanup), FUN_00587bcf (free)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_004627c0 — Network/Entrant Setup with ID Check
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_0057a880 (entrant create, docs/19), FUN_0057a8e0 (entrant setup), FUN_0057a230 (session check), FUN_00462370 (get slot ID), FUN_0057a8b0 (entrant ...
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0049afb0 — Callback Registration (atexit)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587b3e (atexit/deferred function registration)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_004a11e0 — Callback Registration
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587b3e (atexit/deferred function registration)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_004d0040 — Callback Registration
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587b3e (atexit registration)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_005987d0 — Callback Registration
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** vtable+0x10, Gninc
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059c414 — MSVC Exception Handler Unwind Trampoline
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf (free)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059c980 — C++ Unwind Helper (thunk to FUN_00581880)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00581880
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### Unwind_0059d058 — C++ Unwind Helper (thunk to FUN_00583650)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00583650
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_005668d0 — Sub-Call with Conditional Field Free
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00566b90 — conditional file handle close with flag-based dispatch - FUN_00587bcf — free wrapper (memory management)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00587710 — Field Setter at +0x410
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0058abf1 — Critical Section Leave (Slot 9)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0058e12e — Encoding/Locale Detection from Parse Result
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00599ad9 — Ref Count Decrement with Check
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Globals:** DAT_005ea04c
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_004189b0 — State-Checked Virtual Dispatch
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hookable
- **Target:** docs/20-math-utilities.md

#### FUN_0045bb90 — Object Allocator (0x32c bytes)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00461dc0 — State Check Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00499af0 — Object Reset with VTable Dispatch
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_004bb460 — Destructor with Conditional Free
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_004c3030 — Callback Registration
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00513b36 — Flag Setter with Guard
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00516937 — Virtual Dispatch + Conditional Value
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0053d2b0 — Guarded Delegation
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00567a90 — Recursive Tree Traversal + Free
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00585e20 — Callback Registration
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00599e71 — C++ Destructor with VTable Chain
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00568750 — ASCII Char Code Validation (Printable vs Special)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00589c1b — Character classification (alphanumeric check)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_005855e0 — Thread Suspend with Mutex Wait/Lock
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - WaitForSingleObject — Win32 mutex wait - SuspendThread — Win32 thread suspend - Sleep — Win32 sleep - ReleaseMutex — Win32 mutex release
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00598502 — Null-Terminated Int Array Copy with Alloc
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - _malloc — CRT heap alloc - __amsg_exit — Fatal error (out of memory) - FUN_00598600 — Element copy/transform
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0040f300 — Mode-Dispatched Render/Physics Call
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0045ae00 — Render setup - FUN_004f0430 — Physics setup - FUN_004ef180 — Physics finalize
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00462d30 — Enum-to-Enum Translator
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0057a900 — Pre-check - FUN_0057a590 — Enum source
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_004a1830 — Windows Message Pump with Sleep
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** PeekMessageA, GetMessageA, TranslateMessage, DispatchMessageA, Sleep
- **Moddability:** hookable � sleep via DAT_007ce2e4
- **Target:** docs/20-math-utilities.md

#### FUN_0057a950 — Cleanup Wrapper with SEH
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00587b3e — callback registration
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00587090 — Object Copy-Construct from Source
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00587490 (struct init)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00598600 — String Alloc+Copy
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** _strlen, _malloc, FUN_0058fca0 (string copy)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00599615 — Buffer Write with Null-Terminate
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00599560 (validation), FUN_0058cc00 (memory write)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059d6a9 — Null-Checked Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_005679a5 (list traversal with early exit)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00456010 — Utility Function
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00473cc0 — Object Constructor
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00477810 — Utility Function
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0049d8b0 — Utility Function
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_004a0de0 — Function Call Wrapper
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00582290 — Conditional Free by Flag Check
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — heap memory free wrapper (docs/20)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059c400 — SEH Unwind: Free Object at EBP-0x54
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — heap memory free wrapper (docs/20)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059c566 — SEH Unwind: Call FUN_00506ccc Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00506ccc — vtable set + free child (docs/19)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059c706 — SEH Unwind: Free Object at EBP+8
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — heap memory free wrapper (docs/20)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059c88e — SEH Unwind: Call FUN_00582a10 Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00582a10 — system/list cleanup (docs/20)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059cc08 — SEH Unwind: Call FUN_005822b0 Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_005822b0 — linked-list free standard (docs/20)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059cce0 — SEH Unwind: Free Object at EBP-0x14
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — heap memory free wrapper (docs/20)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059cedf — SEH Unwind: Call FUN_00586170 Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00586170 — handle close & linked list cleanup (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059d17b — SEH Unwind: Call FUN_0059b390 Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0059b390 — dual-pointer free (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059d2dc — SEH Unwind: Call FUN_00598cc1 Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00598cc1 — set locale vtable and call cleanup (docs/20)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059d3f0 — SEH Unwind: Conditional Call FUN_00599be5
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00599be5 — set locale vtable and call destructor (docs/20)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_00561f40 — Dispatch Wrapper to Timeout Handler
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00562ac0 -- Timeout/activity handler (docs/01-engine-architecture.md line 5287-5300)
- **Moddability:** hookable
- **Target:** docs/20-math-utilities.md

#### FUN_0059c670 — SEH Unwind: Free Object at +8
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf -- Memory free/deallocation (docs/08, docs/20)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059d03e — SEH Unwind: Call FUN_00585fb0
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00585fb0 -- Linked list cleanup with sub-object delete (docs/20-math-utilities.md)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059c4c8 — SEH Unwind: Free Field at -0x14
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf -- Memory free/deallocation (docs/08, docs/20)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059c6ac — SEH Unwind: Free Object at +8
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf -- Memory free/deallocation (docs/08, docs/20)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059c896 — SEH Unwind: Call FUN_00581c20
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00581c20 -- Cleanup function (docs/06)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059cbe0 — SEH Unwind: Call FUN_005834c0
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_005834c0 -- List destruction with virtual release (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059ce60 — SEH Unwind: Call FUN_0058a5f7 (Array Destructor)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0058a5f7 -- N-time callback loop with SEH (docs/01-engine-architecture.md) - FUN_00583aa0 -- Close handle pair wrapper (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059d091 — SEH Unwind: Call FUN_0047aa60
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0047aa60 -- Small destructor / empty stub (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059d2e4 — SEH Unwind: Call FUN_00598c70
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00598c70 -- Null check with virtual dispatch (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059c730 — SEH Unwind: Free Field at -0x10
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf -- Memory free/deallocation (docs/08, docs/20)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059ce7e — SEH Unwind: Call FUN_00585f30
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00585f30 -- Handle close with flag check (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059c446 — SEH Unwind Free Object at -0x14
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — heap free / memory deallocation
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059c60c — SEH Unwind Free Object at +8
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — heap free / memory deallocation
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059c7b0 — SEH Unwind Free Object at -0x10
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — heap free / memory deallocation
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059c880 — SEH Unwind: Call FUN_00581b30
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00581b30 — Cleanup callback dispatch (docs/20)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059c956 — SEH Unwind: Call FUN_00581c20
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00581c20 — Cleanup/destructor function (docs/06)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059cb28 — SEH Unwind Free Object at +4
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — heap free / memory deallocation
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059ccc8 — SEH Unwind: Call FUN_00581880
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00581880 — Linked List Destruction with VTable Release Call (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059ce20 — SEH Unwind Free Object at -0x10
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — heap free / memory deallocation
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059cfbe — SEH Unwind: Call FUN_004b0170
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_004b0170 — Game state update / object release / destructor (docs/01, docs/06, docs/17)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059d0f6 — SEH Unwind: Call FUN_0047aa60
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0047aa60 — Empty stub / no-op cleanup function (docs/20)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

#### FUN_0059d224 — SEH Unwind: Conditional Call FUN_00598aea
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00598aea — Vtable Set + Sub-Call / conditional cleanup (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/20-math-utilities.md

### docs/19-renderer.md (40 entries)

#### FUN_00413820 — Cascading Threshold Level Mapper
- **Source:** Unknown. Maps an integer value to a discrete level (0-17) through cascading threshold comparisons.
- **Key Logic:** 
- **Calls:** FUN_00414180
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_004c2e20 — Recursive Linked List Merge Sort (Float Field Compare)
- **Source:** Unknown. Sorts singly-linked list by float at second field using merge sort.
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_0045f4a0 — Input Command Dispatch to Entities
- **Source:** unknown. Distributes input commands from input buffer to all active game entities.
- **Key Logic:** 
- **Calls:** FUN_004b3b30, FUN_004b3af0, FUN_00461440, FUN_00462310, FUN_00461530, FUN_004614c0, FUN_00462250, FUN_00465300, FUN_00461470, FUN_00462300, FUN_004654...
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_00551800 — Conditional Entity Call on Non-Null
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_005514a0 (Flag update with cascade, per decompiled_full_index)
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_00551810 — Conditional Dispatch by Flag
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00551210 — (lookup needed)
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_00585cd0 — Thread-Safe Write with Mutex
- **Source:** threading/synchronization | Confidence: high
- **Key Logic:** 
- **Calls:** WaitForSingleObject, ReleaseMutex (Win32 API)
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_0058924c — Byte Buffer Swap (In-Place)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** none
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_0048d6a0 — Short Computation / VTable Init + Call
- **Source:** UI | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00488b30
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_004a1b70 — Short Computation / Conditional Path Registry
- **Source:** file system | Confidence: high
- **Key Logic:** 
- **Globals:** DAT_007ce2e8
- **Calls:** FUN_004a1dc0 — path/setup operation
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_004c7e80 — Unidentified Logic / Double-Linked List Destroy with Virtual Call
- **Source:** resource manager | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf (×many), virtual destructor at vtable+0
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_0058957a — Interrupt Dispatch
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** __cintrindisp2 — compiler interrupt dispatch
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_0055c7f0 — Key Event Dispatch to Sub-Handlers
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0055c650 — integer-to-ID mapping with switch dispatch - FUN_0055c450 — key/ID to values mapper (477 bytes, complex switch) - FUN_0055c7d0 — sub...
- **Moddability:** hookable — maps control bindings to actions
- **Target:** docs/19-renderer.md

#### FUN_0056f060 — Batch Iteration with Counter
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0056a150 — copy struct fields + 3x3 matrix×vector multiply (physics transform update)
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_005410f0 — Guarded Virtual Decrement
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - (indirect virtual) vtable+0x30
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_004b19b0 — VTable + Patterned Field Init
- **Source:** unknown | Confidence: high
- **Key Logic:** [1]=0, [2]=-1, [3]=0, [4]=-1 *param_1 = PTR_LAB_005acc20 **Used by system:** docs/01-engine-architecture.md -- object construction <!-- target: docs/19-renderer.md -->
- **Target:** docs/19-renderer.md

#### FUN_00517963 — Resource Reset with Counter
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_0052765a
- **Target:** docs/19-renderer.md

#### FUN_00550820 — Array-of-Struct Destructor with Countdown
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_00550810 — element destructor/free wrapper (per-element) - FUN_00587bcf — memory deallocation (frees block) - FUN_004b0170 — cleanup/free wrapp...
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_00585f90 — ReleaseMutex Wrapper Returning Success
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - ReleaseMutex — Win32 API
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_00560e50 — Multi-Field Object Destructor with Cleanup Calls
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_004b0170 — game state update/release signal (docs/01, docs/09) - FUN_00557470 — resource unload/release (docs/06, docs/17, docs/19) - FUN_00587...
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_00586210 — CloseHandle + Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** CloseHandle, FUN_005870d0 (vtable init)
- **Moddability:** hookable
- **Target:** docs/19-renderer.md

#### FUN_004526c0 — Array Destructor via Virtual Dispatch
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_00556330 — Timer Accumulate via QueryPerformanceCounter
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0055687b — alternate timer source (when QPC flag not set) - QueryPerformanceCounter — Win32 high-precision timer API
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_0040ad90 — Bounded Index Setter
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** configurable
- **Target:** docs/19-renderer.md

#### FUN_00452700 — Conditional Field Setter with State
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** configurable
- **Target:** docs/19-renderer.md

#### FUN_00464f50 — Division with Cap Computation
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_0046c7b0 — Indexed Array Insert with Shift
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Globals:** DAT_007cd2b8
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_00472720 — String Path Resolution with Fallback
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** configurable
- **Target:** docs/19-renderer.md

#### FUN_004780d0 — State-Dependent Virtual Dispatch
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_00486580 — Linked List Node Insert
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_004881b0 — Dual Cleanup with Conditional Free
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_0049afe0 — Multi-Call Sequence
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_004b1ac0 — Multi-Field Setter with Strings
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** configurable
- **Target:** docs/19-renderer.md

#### FUN_004d0060 — Zero-Init + Sub-Call
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_004d93e0 — Range Check (1-5)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_004f8d20 — Callback Registration
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_0054c0b0 — Bit Flag Reader
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_00559a30 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_0055d560 — Field Getter by Index (1/2/3)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_00556440 — High-Resolution Timer Reset
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** QueryPerformanceCounter, FUN_0055687b (RDTSC)
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

#### FUN_0055d590 — Triple-Field Getter
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/19-renderer.md

### docs/08-file-formats.md (36 entries)

#### FUN_005648c0 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high (Engine/Call pattern)
- **Key Logic:** 
- **Calls:** FUN_005648d0 (target function — unknown)
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_0058afd8 — TLS Offset Getter (+12)
- **Source:** unknown | Confidence: high (Threading pattern)
- **Key Logic:** 
- **Calls:** FUN_0058e0c7 (TLS value retrieval, per decompiled_full_index)
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_00461f90 — Conditional Network/System Dispatch
- **Source:** unknown | Confidence: high (game_logic)
- **Key Logic:** 
- **Calls:** FUN_00563e70 (query), FUN_00563df0 (action dispatch)
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_005986ec — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587b3e — Boolean-to-int conversion helper (math_util)
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_0059871b — Cleanup Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587b3e — boolean-to-int conversion wrapper (triage index)
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_00564960 — Aligned Memory Copy from Struct Buffer
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_005648b0 — math_util, returns buffer/pointer
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_0059379b — SEH-Aware Virtual Call Dispatch Loop
- **Source:** runtime/exception | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00593cfd — error/exception handler for out-of-range, __CallSettingFrame_12
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_005997a1 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00598815 — Target function
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_00587c03 — operator new(uint) → __nh_malloc Wrapper
- **Source:** CRT (Visual Studio 2003 Release) | Confidence: high
- **Key Logic:** 
- **Calls:**  - `__nh_malloc` — MSVC CRT internal malloc (no-throw, returns null on failure)
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_00593981 — Exception Frame Data Setup
- **Source:** CRT / MSVC runtime | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0058e0c7 — SEH handler lookup/registration (called twice) - __abnormal_termination — MSVC CRT terminate handler - FUN_00593bbd — exception hand...
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_005987f0 — Locale Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00598a41 — locale/encoding function
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_00587430 — Single Function Call Wrapper (to constructor)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00599958 — Entity constructor with SEH + vtable init (docs/08)
- **Moddability:** hookable
- **Target:** docs/08-file-formats.md

#### FUN_00587440 — Callback Registration for Cleanup Routine
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00587b3e (callback registration/dispatch)
- **Target:** docs/08-file-formats.md

#### FUN_00466080 — Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00566650
- **Target:** docs/08-file-formats.md

#### FUN_004d22c0 — Field Setter with Init
- **Source:** unknown | Confidence: low
- **Key Logic:** 
- **Calls:** FUN_0042d140
- **Target:** docs/08-file-formats.md

#### FUN_0055c060 — Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0055be60
- **Target:** docs/08-file-formats.md

#### FUN_0059a980 — Double Linked List Free
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0059a8d8 � callback chain iteration (docs/20) - FUN_00587bcf � memory free (docs/20)
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_0059ab83 — Object Destructor with SEH
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0058a5d8, FUN_0059a54d, FUN_00598c88, FUN_0059a5e9
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_005875c0 — Buffer Reallocation and Data Copy
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_005874d0 — buffer allocation (new with size) - FUN_00587bcf — memory free/deallocation
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_00587620 — Buffer Write with Params
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_00587510 — Memory copy, memcpy-like with word-aligned fast path
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_00587690 — Free Callback Registered Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587b3e — atexit/callback registration
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_0059ac63 — Exception Destructor with Conditional Free
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_0059ac7f — base destructor - FUN_00587bcf — memory deallocation
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_00565f50 — Linked List Pop Front
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** None
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_005881c0 — Stack Probe / alloca
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** None — asm pattern
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_00564860 — Batch Loop with Memory Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00564890 — Per-element cleanup - FUN_0058aa6f — Memory free
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_00587930 — Buffer Copy via Virtual Type Dispatch
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - Virtual call at ( +0x58 ) — Type size query - FUN_00587510 — Child processing - FUN_00585400 — Entry finalization
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_00564890 — Indirect Call via Function Pointer
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_005648b0 — linear interpolation utility
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_0058af5c — Error ID Lookup Table
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0058afd8 (TLS getter), FUN_0058afcf (TLS access)
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_0059c5c6 — SEH Unwind: Free Object at +8
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587bcf -- Memory free/deallocation (docs/08, docs/20)
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_0059c812 — SEH Unwind: Call FUN_00581880
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00581880 -- Linked list destruction with vtable release (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_0059c9a0 — SEH Unwind: Call FUN_0047aa60
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0047aa60 -- Small destructor / empty stub (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_0059cd48 — SEH Unwind: Call FUN_005833e0
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_005833e0 -- Walk list, call destructor, free nodes (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_0059cf3d — SEH Unwind: Call FUN_005861e0
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_005861e0 -- CloseHandle wrapper (docs/01)
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_0059d1e8 — SEH Unwind: Call FUN_00599796 (Cleanup with Descriptor)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00599796 -- Cleanup with type descriptor / empty stub (docs/20-math-utilities.md) - DAT_008d42d8 -- Global type descriptor
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_0059d470 — SEH Unwind: Exception Destructor at -0x14
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** exception::~exception -- MSVC exception destructor
- **Moddability:** hardcoded
- **Target:** docs/08-file-formats.md

#### FUN_0059d56c — SEH Unwind: Destroy Exception Object
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Globals:** DAT_007c56a4, DAT_008ab6e4, DAT_007ce254, DAT_007ce2d8, DAT_007c569c, DAT_007ce2a0, DAT_005ec4a4, DAT_007ce2dc, DAT_008afe64, DAT_007ce260, DAT_007ce264, DAT_007ce250, DAT_007ce25c, DAT_005ccfe4, DAT_007c5690, DAT_007c569c
- **Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log)
- **Moddability:** `hardcoded` — reads device config from player file
- **Target:** docs/08-file-formats.md

### docs/21-audio-network-internals.md (15 entries)

#### FUN_00466350 — Camera Yaw/Zoom Controller
- **Source:** Unknown. Controls camera rotation (yaw) and zoom based on player input and game mode.
- **Key Logic:** 
- **Calls:** FUN_00498730, FUN_00498880, FUN_00542420, FUN_00541cd0, FUN_0054b3f0
- **Moddability:** configurable (DAT_007d0398)
- **Target:** docs/21-audio-network-internals.md

#### FUN_00410f60 — Command Dispatch with Array Lookup
- **Source:** Unknown. Dispatches commands (6-bit opcode) to indexed arrays with 0x318/0x328 stride elements.
- **Key Logic:** 
- **Calls:** FUN_0054b4d0
- **Moddability:** hardcoded
- **Target:** docs/21-audio-network-internals.md

#### FUN_0057aa10 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_004b3db0 — (lookup needed)
- **Moddability:** hardcoded
- **Target:** docs/21-audio-network-internals.md

#### FUN_004df030 — Unidentified Logic / Struct Build + Dispatch
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_004dedb0 — parameter block dispatch
- **Moddability:** hardcoded
- **Target:** docs/21-audio-network-internals.md

#### FUN_00553fa0 — State Field Set with Chained Init
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00553fc0 — init function (docs/20-math-utilities.md) - FUN_00554610 — render resource init (docs/19-renderer.md)
- **Moddability:** hardcoded
- **Target:** docs/21-audio-network-internals.md

#### FUN_0057ae80 — Callback Registration for Cleanup Routine
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00587b3e (callback registration/dispatch)
- **Target:** docs/21-audio-network-internals.md

#### FUN_00405630 — Struct Init with VTable Dispatch and Zero Fill
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_0052d990, vtable+4 method
- **Target:** docs/21-audio-network-internals.md

#### FUN_005507e0 — Struct Init with Vtable Zero
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0053c2a0 (base init/short computation, docs/20)
- **Moddability:** hardcoded
- **Target:** docs/21-audio-network-internals.md

#### FUN_005628f0 — Large Stack Struct Zero-Init with Vtable Call
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_00562710 — stack-based operation with the zeroed buffer
- **Moddability:** hardcoded
- **Target:** docs/21-audio-network-internals.md

#### FUN_00563020 — Multi-Stage Initialization Chain with Error Checking
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00562d20 (SocketArrayCreate, docs/21), FUN_00563080 (CreateUdpBroadcastSocket, docs/21), FUN_005630d0 (session init, unknown), FUN_00563000 (liste...
- **Moddability:** hardcoded
- **Target:** docs/21-audio-network-internals.md

#### FUN_00404e60 — Linked-List Node Insertion
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** operator_new (2 allocs), FUN_00566650 (path/name registry)
- **Moddability:** configurable — param_2 is user-supplied name/identifier
- **Target:** docs/21-audio-network-internals.md

#### FUN_00561940 — Field Cleanup with Null Check
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - FUN_00587bcf — free wrapper (memory management, per triage index)
- **Moddability:** hardcoded
- **Target:** docs/21-audio-network-internals.md

#### FUN_004fd840 — Dual Linked List Destruction
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/21-audio-network-internals.md

#### FUN_0050b77b — Object Init with VTable (alloc 0x40)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/21-audio-network-internals.md

#### FUN_0052e1c0 — Thunk with VTable + Flag Check
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/21-audio-network-internals.md

### docs/18-physics-dynamics.md (15 entries)

#### FUN_0040c3b0 — Module Asset Path Resolver
- **Source:** Unknown. Resolves a full file path to a module-relative asset path by extracting filename and stripping extension, then loads via module virtual-dispatch.
- **Key Logic:** 
- **Globals:** DAT_008ac48c, DAT_008ac490, DAT_005be880
- **Calls:** FUN_0040b560 (module object allocation)
- **Moddability:** hardcoded
- **Target:** docs/18-physics-dynamics.md

#### FUN_004dd000 — Short Computation / Two-Call Sequence
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_004dcd10, FUN_004dcf80
- **Moddability:** hardcoded
- **Target:** docs/18-physics-dynamics.md

#### FUN_004f23b0 — Short Computation / Callback Registration
- **Source:** initialization | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00587b3e — callback registration (MSVC _atexit-like)
- **Moddability:** hardcoded
- **Target:** docs/18-physics-dynamics.md

#### thunk_FUN_00458020 — at 00457cf0 -- Resource Cleanup with Conditional Free
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_00587bcf (free)
- **Target:** docs/18-physics-dynamics.md

#### FUN_004a1e20 — Triple Dispatch Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00566650, FUN_004a1b70
- **Target:** docs/18-physics-dynamics.md

#### FUN_004c1820 — Linked List Node Removal with Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_004c2850, FUN_004c0b10, FUN_00587bcf
- **Target:** docs/18-physics-dynamics.md

#### FUN_004dfb60 — Init with Dual Call
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** FUN_004dfb00, FUN_004dfa50
- **Target:** docs/18-physics-dynamics.md

#### FUN_004fc650 — String Copy with Ring Buffer
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Globals:** DAT_008aae64, DAT_0083ee60
- **Calls:** FUN_004b33b0
- **Target:** docs/18-physics-dynamics.md

#### FUN_0051eb6e — Object Setup with Bounds Check
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:** vtable dispatch, FUN_0051e2ba, FUN_0051e3e7, FUN_0051ea5a
- **Target:** docs/18-physics-dynamics.md

#### FUN_00560ba0 — Object Init with Parameter Linking
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Calls:**  - FUN_0053c2a0 — parent constructor / subsystem init (docs/06, docs/20)
- **Moddability:** hardcoded
- **Target:** docs/18-physics-dynamics.md

#### FUN_00567a00 — Struct Zero-Init (9 Words + Loop)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/18-physics-dynamics.md

#### FUN_0050b75f — Destructor with Self-Free
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** thunk_FUN_00506ccc, FUN_00587bcf
- **Moddability:** hardcoded
- **Target:** docs/18-physics-dynamics.md

#### FUN_004ddf70 — Zero-Init Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/18-physics-dynamics.md

#### FUN_005388d0 — Frequency Table Construction
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/18-physics-dynamics.md

#### FUN_00568ba0 — Struct Zero-Init (17 Fields)
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/18-physics-dynamics.md

### docs/17-physics-collision.md (5 entries)

#### FUN_0059d963 — Single Function Call Wrapper
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_004bffa4 — target function (0x004B range = game logic)
- **Moddability:** hardcoded
- **Target:** docs/17-physics-collision.md

#### FUN_00485eb0 — Unidentified / Multi-Struct Destructor
- **Source:** UI/resource manager | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_00486080, FUN_00587bcf (×many), FUN_00414370, FUN_0049a990
- **Moddability:** hardcoded
- **Target:** docs/17-physics-collision.md

#### FUN_004f9160 — Utility Function / Global Index Setter
- **Source:** game logic | Confidence: high
- **Key Logic:** 
- **Globals:** DAT_008afe6c, DAT_008afe68
- **Calls:** FUN_0055bfc0, FUN_0055bfd0
- **Moddability:** hardcoded
- **Target:** docs/17-physics-collision.md

#### FUN_004db550 — UI Layout Dispatch with Data Prep
- **Source:** unknown | Confidence: medium
- **Key Logic:** 
- **Globals:** DAT_007d0474
- **Calls:** FUN_0049b950, FUN_0049b900, FUN_0049b8f0, FUN_004db6f0, FUN_004db9a0, FUN_0049b7a0, FUN_004db7f0
- **Target:** docs/17-physics-collision.md

#### FUN_0059d5a8 — SEH Unwind Cleanup
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/17-physics-collision.md

### no-target (3 entries)

#### FUN_0057c950 — Thread-Safe Linked-List Lookup with Mutex + Data Copy
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:**  - WaitForSingleObject — Win32 API - ReleaseMutex — Win32 API - FUN_004b3db0 — Data copy/retrieval
- **Moddability:** hardcoded
- **Target:** 

#### Unwind_0059d524 — C++ Unwind Helper Thunk
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0059a9c2
- **Target:** 

#### FUN_0059d524 — SEH Unwind: Call FUN_0059a9c2
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Calls:** FUN_0059a9c2 -- Single function call wrapper (docs/01)
- **Moddability:** hardcoded
- **Target:** 

### docs/10-vehicle-physics.md (1 entries)

#### FUN_004c6810 — Recursive Linked List Merge Sort (Float Comparator)
- **Source:** Unknown. Sorts singly-linked list by float key using recursive merge sort.
- **Key Logic:** 
- **Calls:** FUN_004c5d30
- **Moddability:** hardcoded
- **Target:** docs/10-vehicle-physics.md

### docs/06-session-race-logic.md (1 entries)

#### FUN_0040b6c0 — Short Computation / Index Search in Struct Array
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/06-session-race-logic.md

### docs/09-track-system.md (1 entries)

#### FUN_0040e1d0 — Callback Registration
- **Source:** unknown | Confidence: high
- **Key Logic:** 
- **Moddability:** hardcoded
- **Target:** docs/09-track-system.md

## Distribution by Subsystem Category

### seh_exception_handling (227 entries)
| Address | Name | Key Logic | Globals | Target |
|---------|------|-----------|---------|--------|
| FUN_004bd7f0 | Object Cleanup (Thunk Target FUN_004bd800) |  | — | docs/20-math-utilities.md |
| FUN_00563a30 | Query with Context + Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_0057a990 | Free Callback Registered Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_00587a60 | Free Callback Registered Cleanup (2) |  | — | docs/20-math-utilities.md |
| FUN_0059a728 | Exception Cleanup with Destructor Call |  | PTR_FUN_005b9d28 | docs/01-engine-architecture.md |
| FUN_0059af17 | C++ Exception Throw Wrapper |  | — | docs/20-math-utilities.md |
| Unwind_0059c40a | SEH Unwind Handler (Free Field) |  | — | docs/01-engine-architecture.md |
| Unwind_0059c582 | SEH Unwind Handler (Free Field at EBP-0x24) |  | — | docs/20-math-utilities.md |
| Unwind_0059c68e | SEH Unwind Handler (Free Field at EBP+8) |  | — | docs/01-engine-architecture.md |
| Unwind_0059c812 | SEH Unwind Handler (Call FUN_00581880) |  | — | docs/01-engine-architecture.md |
| Unwind_0059c956 | SEH Unwind Handler (Call FUN_00581c20) |  | — | docs/01-engine-architecture.md |
| Unwind_0059cb88 | SEH Unwind Handler (Call FUN_00583050) |  | — | docs/20-math-utilities.md |
| Unwind_0059cd48 | SEH Unwind Handler (Call FUN_005833e0) |  | — | docs/20-math-utilities.md |
| Unwind_0059cf03 | SEH Unwind Handler (Call FUN_005833e0, duplicate) |  | — | docs/20-math-utilities.md |
| Unwind_0059d070 | SEH Unwind Handler (Call FUN_0047aa60) |  | — | docs/01-engine-architecture.md |
| Unwind_0059d1e8 | SEH Unwind Handler with Exception Cleanup |  | DAT_008d42d8 | docs/20-math-utilities.md |
| Unwind_0059d427 | SEH Unwind Handler (Call FUN_00598c70) |  | — | docs/01-engine-architecture.md |
| FUN_004bd800 | Struct Cleanup (9 fields) |  | — | docs/20-math-utilities.md |
| FUN_0055bf70 | Array of Pointers Cleanup with Free Loop |  | — | docs/20-math-utilities.md |
| FUN_0058a331 | SEH Unwind Handler (RtlUnwind) |  | — | docs/01-engine-architecture.md |
| FUN_0059cf0b | SEH Unwind with Single Call |  | — | docs/01-engine-architecture.md |
| FUN_0059d07b | SEH Unwind with Single Call |  | — | docs/01-engine-architecture.md |
| FUN_0059d1f8 | SEH Unwind Release Locale Refcount |  | DAT_008d43c8 | docs/01-engine-architecture.md |
| FUN_0059d43c | SEH Unwind with Single Call |  | — | docs/01-engine-architecture.md |
| FUN_0059a781 | Exception Object Constructor (Copy String) |  | — | docs/20-math-utilities.md |
| FUN_0059c698 | SEH Unwind with Field Free |  | — | docs/01-engine-architecture.md |
| FUN_0059c81a | SEH Unwind Cleanup Call |  | — | docs/01-engine-architecture.md |
| FUN_0059c964 | SEH Unwind Cleanup Call |  | — | docs/20-math-utilities.md |
| FUN_0057aa70 | Cleanup Wrapper with SEH |  | — | docs/20-math-utilities.md |
| FUN_0059871b | Cleanup Wrapper |  | — | docs/08-file-formats.md |
| FUN_0059afff | Exception Throw Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_0059c43c | SEH Unwind with Field Free |  | — | docs/01-engine-architecture.md |
| FUN_0059c5a8 | SEH Unwind Free Object at +8 |  | — | docs/01-engine-architecture.md |
| FUN_0059c6a2 | SEH Unwind Free Object at +8 |  | — | docs/20-math-utilities.md |
| FUN_0059cbc0 | SEH Unwind Cleanup Call |  | — | docs/01-engine-architecture.md |
| FUN_0059cd6b | SEH Unwind with Field Free |  | — | docs/01-engine-architecture.md |
| FUN_0059cf19 | SEH Unwind Cleanup Call |  | — | docs/01-engine-architecture.md |
| FUN_0059d086 | SEH Unwind Cleanup Call |  | — | docs/20-math-utilities.md |
| FUN_0059d444 | SEH Unwind Cleanup Call |  | — | docs/01-engine-architecture.md |
| FUN_0059875f | Free Callback Registered Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_0059a81b | C++ Exception Throw Wrapper |  | — | docs/01-engine-architecture.md |
| Unwind_0059c446 | SEH Unwind: Free Object at EBP-0x14 |  | — | docs/20-math-utilities.md |
| Unwind_0059c5b2 | SEH Unwind: Free Object at EBP+8 |  | — | docs/20-math-utilities.md |
| Unwind_0059c6ac | SEH Unwind: Free Object at EBP+8 |  | — | docs/20-math-utilities.md |
| Unwind_0059c83e | SEH Unwind: Call FUN_00581a80 |  | — | docs/20-math-utilities.md |
| Unwind_0059c988 | SEH Unwind: Call FUN_005822b0 |  | — | docs/20-math-utilities.md |
| Unwind_0059cbe0 | SEH Unwind: Call FUN_005834c0 |  | — | docs/01-engine-architecture.md |
| Unwind_0059cd80 | SEH Unwind: Call FUN_005834c0 |  | — | docs/20-math-utilities.md |
| Unwind_0059cf21 | SEH Unwind: Call FUN_00586170 |  | — | docs/20-math-utilities.md |
| Unwind_0059d091 | SEH Unwind: Call FUN_0047aa60 |  | — | docs/20-math-utilities.md |
| Unwind_0059d224 | SEH Unwind: Conditional Call FUN_00598aea |  | — | docs/20-math-utilities.md |
| Unwind_0059d45c | SEH Unwind: Call FUN_0059a9c2 |  | — | docs/01-engine-architecture.md |
| FUN_00583270 | Unidentified Logic / Linked List Destructor with VTable Clea |  | — | docs/20-math-utilities.md |
| Unwind_0059c620 | SEH Unwind: Free at EBP+8 |  | — | docs/20-math-utilities.md |
| Unwind_0059cc88 | SEH Unwind: Thunk to FUN_00582f60 |  | — | docs/20-math-utilities.md |
| Unwind_0059d358 | MSVC Exception Handler Unwind with DAT_008d4400 |  | — | docs/01-engine-architecture.md |
| FUN_0058a42f | SEH Exception Handler Trampoline Setup |  | — | docs/01-engine-architecture.md |
| FUN_0059977e | Cleanup Wrapper |  | — | docs/01-engine-architecture.md |
| Unwind_0059c45a | SEH Unwind Handler |  | — | docs/20-math-utilities.md |
| Unwind_0059c5c6 | SEH Unwind Handler |  | — | docs/20-math-utilities.md |
| Unwind_0059c6c0 | SEH Unwind Handler |  | — | docs/01-engine-architecture.md |
| Unwind_0059c846 | SEH Unwind with Single Call |  | — | docs/01-engine-architecture.md |
| Unwind_0059c9a0 | SEH Unwind with Single Call |  | — | docs/20-math-utilities.md |
| Unwind_0059cc00 | SEH Unwind Handler |  | — | docs/01-engine-architecture.md |
| Unwind_0059cd88 | SEH Unwind Cleanup Call |  | — | docs/20-math-utilities.md |
| Unwind_0059cf3d | SEH Unwind Handler |  | — | docs/20-math-utilities.md |
| Unwind_0059d0a7 | SEH Unwind Handler |  | — | docs/01-engine-architecture.md |
| Unwind_0059d248 | SEH Unwind Handler with Flag Check |  | — | docs/01-engine-architecture.md |
| Unwind_0059d470 | SEH Unwind with ~Exception Destructor |  | — | docs/01-engine-architecture.md |
| FUN_0055fe30 | Dual Field Cleanup with Null Checks |  | — | docs/01-engine-architecture.md |
| FUN_00568f20 | Multi-Field Pointer Cleanup with Null Checks |  | — | docs/01-engine-architecture.md |
| FUN_00593981 | Exception Frame Data Setup |  | — | docs/08-file-formats.md |
| FUN_0059c482 | SEH Unwind with Field Free |  | — | docs/01-engine-architecture.md |
| FUN_0059c5da | SEH Unwind Free Object at +8 |  | — | docs/01-engine-architecture.md |
| FUN_0059c6d4 | SEH Unwind Free Object at +8 (Duplicate) |  | — | docs/20-math-utilities.md |
| FUN_0059c9d0 | SEH Unwind Cleanup Call |  | — | docs/20-math-utilities.md |
| FUN_0059cf53 | SEH Unwind Cleanup Call |  | — | docs/01-engine-architecture.md |
| FUN_0059d0bd | SEH Unwind Cleanup Call (dup) |  | — | docs/20-math-utilities.md |
| FUN_00546370 | Array Cleanup with Dual Free |  | — | docs/01-engine-architecture.md |
| FUN_0059c48c | SEH Unwind: Free Object at -0x2C |  | — | docs/20-math-utilities.md |
| FUN_0059cc1e | SEH Unwind: Free at -0x1C |  | — | docs/01-engine-architecture.md |
| FUN_0059ce00 | SEH Unwind (Call FUN_005819c0) |  | — | docs/20-math-utilities.md |
| FUN_00579fc0 | Callback Registration for Cleanup Routine |  | — | docs/01-engine-architecture.md |
| FUN_0057ae80 | Callback Registration for Cleanup Routine |  | — | docs/21-audio-network-internals.md |
| FUN_00587440 | Callback Registration for Cleanup Routine |  | — | docs/08-file-formats.md |
| FUN_00599802 | Callback Registration for Cleanup Routine |  | — | docs/01-engine-architecture.md |
| FUN_00418df0 | Linked List Destructor with Conditional Cleanup |  | — | docs/20-math-utilities.md |
| thunk_FUN_00458020 | at 00457cf0 -- Resource Cleanup with Conditional Free |  | — | docs/18-physics-dynamics.md |
| FUN_0045bf60 | Callback Registration for Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_00491e10 | Conditional Resource Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_004c1820 | Linked List Node Removal with Cleanup |  | — | docs/18-physics-dynamics.md |
| FUN_004d8950 | Batch VTable Dispatch and Cleanup |  | — | docs/01-engine-architecture.md |
| Unwind_0059c730 | SEH Unwind Cleanup |  | — | docs/20-math-utilities.md |
| FUN_005528f0 | Conditional UI Cleanup Dispatch |  | — | docs/01-engine-architecture.md |
| FUN_0059bacc | Exception Destructor with Conditional Free |  | — | docs/01-engine-architecture.md |
| Unwind_0059c4c8 | SEH Unwind with Field Free |  | — | docs/01-engine-architecture.md |
| Unwind_0059c60c | SEH Unwind Free Object at +8 |  | — | docs/01-engine-architecture.md |
| Unwind_0059c706 | SEH Unwind Free Object at +8 |  | — | docs/20-math-utilities.md |
| Unwind_0059c896 | Unwind Handler (SEH) |  | — | docs/01-engine-architecture.md |
| Unwind_0059ca80 | SEH Unwind with Single Call |  | — | docs/20-math-utilities.md |
| Unwind_0059cc6b | Unwind Handler (SEH) |  | — | docs/20-math-utilities.md |
| Unwind_0059ce60 | Unwind Handler (SEH) — Array Destructor |  | — | docs/01-engine-architecture.md |
| Unwind_0059cfbe | SEH Unwind Cleanup Call |  | — | docs/01-engine-architecture.md |
| Unwind_0059d110 | SEH Unwind Cleanup Call |  | — | docs/01-engine-architecture.md |
| Unwind_0059d2e4 | SEH Unwind Cleanup Call |  | — | docs/01-engine-architecture.md |
| Unwind_0059d508 | SEH Unwind Cleanup Call |  | — | docs/20-math-utilities.md |
| FUN_00582eb0 | Linked-List Node Removal with Cleanup Callback |  | — | docs/01-engine-architecture.md |
| FUN_00560e50 | Multi-Field Object Destructor with Cleanup Calls |  | — | docs/19-renderer.md |
| FUN_005511a0 | Object Destructor with Array Cleanup |  | — | docs/20-math-utilities.md |
| FUN_00586170 | Handle Close & Linked List Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_005998cf | Cleanup Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_0059c634 | SEH Unwind with Field Free |  | — | docs/01-engine-architecture.md |
| FUN_0059c790 | SEH Unwind with Field Free (EBP-0x10) |  | — | docs/01-engine-architecture.md |
| FUN_0059c8d8 | SEH Unwind Cleanup Call |  | — | docs/20-math-utilities.md |
| FUN_0059ce9a | SEH Unwind with Single Call |  | — | docs/01-engine-architecture.md |
| FUN_0059cff6 | SEH Unwind with Single Call |  | — | docs/01-engine-architecture.md |
| FUN_0059d15b | SEH Unwind with Field Free (EBP-0x10) |  | — | docs/01-engine-architecture.md |
| FUN_0059d338 | SEH Unwind Release Locale Refcount |  | DAT_008d4478 | docs/01-engine-architecture.md |
| FUN_0059d544 | SEH Unwind with Single Call |  | — | docs/20-math-utilities.md |
| FUN_00554d70 | UI Cleanup Iterator |  | — | docs/20-math-utilities.md |
| FUN_00587690 | Free Callback Registered Cleanup |  | — | docs/08-file-formats.md |
| FUN_0059ac63 | Exception Destructor with Conditional Free |  | — | docs/08-file-formats.md |
| FUN_00586210 | CloseHandle + Cleanup |  | — | docs/19-renderer.md |
| FUN_0059ac7f | Object Teardown with Iterator Cleanup |  | — | docs/20-math-utilities.md |
| FUN_00464670 | Conditional Object Cleanup |  | — | docs/20-math-utilities.md |
| FUN_00553310 | Conditional Resource Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_00581750 | Handle Close with Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_00586240 | Linked-List Destruction with SEH + Alloc Cleanup |  | — | docs/20-math-utilities.md |
| FUN_0059ad3d | Free Callback Registered Cleanup |  | — | docs/20-math-utilities.md |
| Unwind_0059c414 | MSVC Exception Handler Unwind Trampoline |  | — | docs/20-math-utilities.md |
| FUN_00561940 | Field Cleanup with Null Check |  | — | docs/21-audio-network-internals.md |
| FUN_00585550 | Thread Termination with Wait Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_0059c53e | SEH Unwind (Free EBP-0x14) |  | — | docs/01-engine-architecture.md |
| FUN_0059c666 | SEH Unwind (Free EBP+8) |  | — | docs/01-engine-architecture.md |
| FUN_0059c464 | SEH Unwind (Free EBP-0x30) |  | — | docs/01-engine-architecture.md |
| FUN_0059ca10 | SEH Unwind (Free EBP-0x10) |  | — | docs/01-engine-architecture.md |
| FUN_0059c7e0 | SEH Unwind Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_0059c91e | SEH Unwind Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_0059cb48 | SEH Unwind Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_0059cd00 | SEH Unwind Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_0059ced7 | SEH Unwind Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_0059d036 | SEH Unwind Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_0059d09c | SEH Unwind Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_0059d1a8 | SEH Unwind Release Locale Refcount |  | — | docs/01-engine-architecture.md |
| FUN_0059d3cc | SEH Unwind Conditional Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_0059d5a8 | SEH Unwind Cleanup |  | — | docs/17-physics-collision.md |
| FUN_004881b0 | Dual Cleanup with Conditional Free |  | — | docs/19-renderer.md |
| FUN_0048e890 | Resource Cleanup (Free + Zero) |  | — | docs/01-engine-architecture.md |
| FUN_0048fdf0 | Conditional Dispatch with Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_00598994 | Ref Count Decrement with Cleanup |  | DAT_005e9ef4 | docs/01-engine-architecture.md |
| FUN_00564860 | Batch Loop with Memory Cleanup |  | — | docs/08-file-formats.md |
| FUN_005539f0 | Resource Cascade Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_0057a950 | Cleanup Wrapper with SEH |  | — | docs/20-math-utilities.md |
| FUN_00560c00 | State Flag Setter + Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_0059a541 | Cleanup Callback Registration |  | — | docs/01-engine-architecture.md |
| FUN_0059c400 | SEH Unwind: Free Object at EBP-0x54 |  | — | docs/20-math-utilities.md |
| FUN_0059c50e | SEH Unwind: Free Object at EBP-0x3C |  | — | docs/01-engine-architecture.md |
| FUN_0059c566 | SEH Unwind: Call FUN_00506ccc Cleanup |  | — | docs/20-math-utilities.md |
| FUN_0059c6ca | SEH Unwind: Free Object at EBP+8 |  | — | docs/01-engine-architecture.md |
| FUN_0059c706 | SEH Unwind: Free Object at EBP+8 |  | — | docs/20-math-utilities.md |
| FUN_0059c846 | SEH Unwind: Call FUN_00581ad0 Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_0059c88e | SEH Unwind: Call FUN_00582a10 Cleanup |  | — | docs/20-math-utilities.md |
| FUN_0059caa0 | SEH Unwind: Call FUN_0047aa60 Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_0059cb40 | SEH Unwind: Call FUN_00583270 Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_0059cb88 | SEH Unwind: Call FUN_00583050 Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_0059cc08 | SEH Unwind: Call FUN_005822b0 Cleanup |  | — | docs/20-math-utilities.md |
| FUN_0059cce0 | SEH Unwind: Free Object at EBP-0x14 |  | — | docs/20-math-utilities.md |
| FUN_0059cd88 | SEH Unwind: Call FUN_005819c0 Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_0059ce40 | SEH Unwind: Call FUN_004b0170 Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_0059cea2 | SEH Unwind: Call FUN_00586240 Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_0059cedf | SEH Unwind: Call FUN_00586170 Cleanup |  | — | docs/20-math-utilities.md |
| FUN_0059d0b2 | SEH Unwind: Call FUN_0047aa60 Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_0059d110 | SEH Unwind: Call FUN_00586460 Cleanup |  | — | docs/01-engine-architecture.md |
| FUN_0059d17b | SEH Unwind: Call FUN_0059b390 Cleanup |  | — | docs/20-math-utilities.md |
| FUN_0059d248 | SEH Unwind: Conditional Call FUN_00598aea |  | — | docs/01-engine-architecture.md |
| FUN_0059d2dc | SEH Unwind: Call FUN_00598cc1 Cleanup |  | — | docs/20-math-utilities.md |
| FUN_0059d3f0 | SEH Unwind: Conditional Call FUN_00599be5 |  | — | docs/20-math-utilities.md |
| FUN_0059ae24 | Exception Destructor SEH Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_0059c670 | SEH Unwind: Free Object at +8 |  | — | docs/20-math-utilities.md |
| FUN_0059d03e | SEH Unwind: Call FUN_00585fb0 |  | — | docs/20-math-utilities.md |
| FUN_0059c4c8 | SEH Unwind: Free Field at -0x14 |  | — | docs/20-math-utilities.md |
| FUN_0059c5c6 | SEH Unwind: Free Object at +8 |  | — | docs/08-file-formats.md |
| FUN_0059c6ac | SEH Unwind: Free Object at +8 |  | — | docs/20-math-utilities.md |
| FUN_0059c812 | SEH Unwind: Call FUN_00581880 |  | — | docs/08-file-formats.md |
| FUN_0059c896 | SEH Unwind: Call FUN_00581c20 |  | — | docs/20-math-utilities.md |
| FUN_0059c9a0 | SEH Unwind: Call FUN_0047aa60 |  | — | docs/08-file-formats.md |
| FUN_0059cbe0 | SEH Unwind: Call FUN_005834c0 |  | — | docs/20-math-utilities.md |
| FUN_0059cd48 | SEH Unwind: Call FUN_005833e0 |  | — | docs/08-file-formats.md |
| FUN_0059ce60 | SEH Unwind: Call FUN_0058a5f7 (Array Destructor) |  | — | docs/20-math-utilities.md |
| FUN_0059cf3d | SEH Unwind: Call FUN_005861e0 |  | — | docs/08-file-formats.md |
| FUN_0059d091 | SEH Unwind: Call FUN_0047aa60 |  | — | docs/20-math-utilities.md |
| FUN_0059d1e8 | SEH Unwind: Call FUN_00599796 (Cleanup with Descriptor) |  | — | docs/08-file-formats.md |
| FUN_0059d2e4 | SEH Unwind: Call FUN_00598c70 |  | — | docs/20-math-utilities.md |
| FUN_0059d470 | SEH Unwind: Exception Destructor at -0x14 |  | — | docs/08-file-formats.md |
| FUN_0059c414 | SEH Unwind: Free Field at -0x48 |  | — | docs/01-engine-architecture.md |
| FUN_0059c620 | SEH Unwind: Free Object at +8 |  | — | docs/01-engine-architecture.md |
| FUN_0059c730 | SEH Unwind: Free Field at -0x10 |  | — | docs/20-math-utilities.md |
| FUN_0059c980 | SEH Unwind: Call FUN_00581880 |  | — | docs/01-engine-architecture.md |
| FUN_0059cc88 | SEH Unwind: Call FUN_00582f60 |  | — | docs/01-engine-architecture.md |
| FUN_0059ce7e | SEH Unwind: Call FUN_00585f30 |  | — | docs/20-math-utilities.md |
| FUN_0059d058 | SEH Unwind: Call FUN_00583650 |  | — | docs/01-engine-architecture.md |
| FUN_0059d358 | SEH Unwind: Call FUN_00599796 (Cleanup with Descriptor) |  | — | docs/01-engine-architecture.md |
| FUN_0059d524 | SEH Unwind: Call FUN_0059a9c2 |  | — |  |
| FUN_0059c446 | SEH Unwind Free Object at -0x14 |  | — | docs/20-math-utilities.md |
| FUN_0059c4d2 | SEH Unwind Free Object at -0x1c |  | — | docs/01-engine-architecture.md |
| FUN_0059c52c | SEH Unwind with Single Call |  | — | docs/01-engine-architecture.md |
| FUN_0059c582 | SEH Unwind Free Object at -0x24 |  | — | docs/01-engine-architecture.md |
| FUN_0059c5d0 | SEH Unwind Free Object at +8 |  | — | docs/01-engine-architecture.md |
| FUN_0059c60c | SEH Unwind Free Object at +8 |  | — | docs/20-math-utilities.md |
| FUN_0059c6fc | SEH Unwind Free Object at +8 |  | — | docs/01-engine-architecture.md |
| FUN_0059c7b0 | SEH Unwind Free Object at -0x10 |  | — | docs/20-math-utilities.md |
| FUN_0059c880 | SEH Unwind: Call FUN_00581b30 |  | — | docs/20-math-utilities.md |
| FUN_0059c910 | SEH Unwind: Call FUN_00581a20 |  | — | docs/01-engine-architecture.md |
| FUN_0059c956 | SEH Unwind: Call FUN_00581c20 |  | — | docs/20-math-utilities.md |
| FUN_0059ca80 | SEH Unwind: Call FUN_0047aa60 |  | — | docs/01-engine-architecture.md |
| FUN_0059cb28 | SEH Unwind Free Object at +4 |  | — | docs/20-math-utilities.md |
| FUN_0059cc60 | SEH Unwind Free Object at -0x14 |  | — | docs/01-engine-architecture.md |
| FUN_0059ccc8 | SEH Unwind: Call FUN_00581880 |  | — | docs/20-math-utilities.md |
| FUN_0059cd80 | SEH Unwind: Call FUN_005834c0 |  | — | docs/01-engine-architecture.md |
| FUN_0059ce20 | SEH Unwind Free Object at -0x10 |  | — | docs/20-math-utilities.md |
| FUN_0059cfbe | SEH Unwind: Call FUN_004b0170 |  | — | docs/20-math-utilities.md |
| FUN_0059d0f6 | SEH Unwind: Call FUN_0047aa60 |  | — | docs/20-math-utilities.md |
| FUN_0059d224 | SEH Unwind: Conditional Call FUN_00598aea |  | — | docs/20-math-utilities.md |
| FUN_0059d427 | SEH Unwind: Call FUN_00598c70 |  | — | docs/01-engine-architecture.md |
| FUN_0059d484 | SEH Unwind: Destroy Exception Object |  | — | docs/01-engine-architecture.md |
| FUN_0059d508 | SEH Unwind: Call FUN_0059ac3f |  | — | docs/01-engine-architecture.md |
| FUN_0059d56c | SEH Unwind: Destroy Exception Object |  | DAT_007c56a4, DAT_008ab6e4, DAT_007ce254 | docs/08-file-formats.md |

### unknown (87 entries)
| Address | Name | Key Logic | Globals | Target |
|---------|------|-----------|---------|--------|
| FUN_00551800 | Conditional Entity Call on Non-Null |  | — | docs/19-renderer.md |
| FUN_0055be60 | Global Call with Fixed Argument |  | DAT_008b8f28 | docs/20-math-utilities.md |
| FUN_00561a41 | 2D Array Fill with Stride Support |  | — | docs/01-engine-architecture.md |
| FUN_00558cf0 | Bounds-Checked Array Write (0x80 stride) |  | — | docs/01-engine-architecture.md |
| FUN_0056d880 | Zero-Fill Arrays and Call Init Routine Repeatedly |  | — | docs/01-engine-architecture.md |
| FUN_005870e0 | Field Reset with Sub-Call |  | — | docs/01-engine-architecture.md |
| FUN_0050fdf3 | OS Version Detection (GetVersionEx) |  | — | docs/20-math-utilities.md |
| FUN_00553db0 | Struct Init with Default Values |  | — | docs/20-math-utilities.md |
| FUN_0055bff0 | Array Slot Check + Conditional Call |  | — | docs/01-engine-architecture.md |
| FUN_00588f66 | Batch Function Call over Varargs |  | — | docs/20-math-utilities.md |
| FUN_00563e80 | Index-Bounds Checked Array Read |  | — | docs/01-engine-architecture.md |
| FUN_00465430 | Short Computation / Player Control Set |  | — | docs/01-engine-architecture.md |
| FUN_00487720 | Short Computation / State Value Transform |  | — | docs/20-math-utilities.md |
| FUN_00489f40 | Unidentified / Clamped Index Computation |  | — | docs/01-engine-architecture.md |
| FUN_004dd000 | Short Computation / Two-Call Sequence |  | — | docs/18-physics-dynamics.md |
| FUN_0057a820 | Short Computation / Thunk to FUN_00585810 |  | — | docs/01-engine-architecture.md |
| FUN_00561e00 | Two-Step Init Call |  | — | docs/01-engine-architecture.md |
| FUN_00563ec0 | Switch Param Store + Global Set |  | — | docs/20-math-utilities.md |
| FUN_0058d82c | Int Peek from Pointer |  | — | docs/20-math-utilities.md |
| FUN_0058d839 | Pointer Advance + Read-Back |  | — | docs/01-engine-architecture.md |
| FUN_00590440 | Short-in-Range Check Against Static Table |  | — | docs/01-engine-architecture.md |
| FUN_00550620 | Scrolling Data Offset Across Linked Entries |  | — | docs/01-engine-architecture.md |
| FUN_0056f060 | Batch Iteration with Counter |  | — | docs/19-renderer.md |
| FUN_00585de0 | QueueUserAPC Async Procedure Call |  | — | docs/01-engine-architecture.md |
| FUN_0059a2d0 | Locale Encoding Check |  | — | docs/01-engine-architecture.md |
| FUN_005410f0 | Guarded Virtual Decrement |  | — | docs/19-renderer.md |
| FUN_00547400 | Guarded Call with Status |  | — | docs/01-engine-architecture.md |
| FUN_00559330 | Small Struct Init with Parent Call |  | — | docs/01-engine-architecture.md |
| FUN_0059b530 | Grow Dynamic Element Array |  | — | docs/01-engine-architecture.md |
| FUN_0055687b | RDTSC Timestamp Read |  | — | docs/20-math-utilities.md |
| FUN_00586c90 | Counter Increment with Cap Check | Reads counter from *param_1, increments by 1 Stores incremented value back Returns (incremented < 6) | — | docs/01-engine-architecture.md |
| FUN_00593c24 | SEH Frame Offset Calculation Helper |  | — | docs/01-engine-architecture.md |
| FUN_00599232 | Conditional Delegate Call with Null Guard |  | — | docs/01-engine-architecture.md |
| FUN_00408de0 | Conditional Subsystem Call with Parameter |  | — | docs/01-engine-architecture.md |
| thunk_FUN_004201e0 | at 004203d0 -- Thunk to FUN_004201e0 |  | — | docs/01-engine-architecture.md |
| FUN_0045d500 | Guarded Init Call |  | DAT_007ce260 | docs/20-math-utilities.md |
| FUN_00473b90 | Conditional Init with Global Ref Setup |  | DAT_007cd8c0 | docs/01-engine-architecture.md |
| FUN_004773a0 | Bounds Check with Position Query |  | — | docs/01-engine-architecture.md |
| FUN_00478320 | Resource Query and Stored Setup |  | DAT_007cd8c0 | docs/01-engine-architecture.md |
| FUN_0047bae0 | Bounded Counter Update |  | — | docs/01-engine-architecture.md |
| FUN_0048faf0 | Decrement Counter with Clamp |  | — | docs/01-engine-architecture.md |
| FUN_00495060 | Guarded Subsystem Release |  | DAT_007cde1c | docs/20-math-utilities.md |
| FUN_004975b0 | Set + Init Call |  | — | docs/20-math-utilities.md |
| FUN_0049ed10 | Guarded Call |  | — | docs/20-math-utilities.md |
| FUN_004c82c0 | Init with Status Check |  | DAT_008ac4c4 | docs/01-engine-architecture.md |
| FUN_004dfb60 | Init with Dual Call |  | — | docs/18-physics-dynamics.md |
| FUN_00517963 | Resource Reset with Counter |  | — | docs/19-renderer.md |
| FUN_0051eb6e | Object Setup with Bounds Check |  | — | docs/18-physics-dynamics.md |
| FUN_005469c0 | Reference Counted Resource Release |  | — | docs/01-engine-architecture.md |
| FUN_005871c0 | Dual Query into Two Output Params |  | — | docs/20-math-utilities.md |
| Unwind_0059ce7e | C++ Unwind Helper Thunk |  | — | docs/20-math-utilities.md |
| Unwind_0059d524 | C++ Unwind Helper Thunk |  | — |  |
| FUN_0057a730 | Two-Step Init Sub-Call |  | — | docs/20-math-utilities.md |
| FUN_0057db80 | Two-Field Equality Check |  | — | docs/01-engine-architecture.md |
| FUN_00593c50 | CRT __CallSettingFrame@12 |  | — | docs/20-math-utilities.md |
| FUN_005874d0 | operator new with Result Check |  | — | docs/20-math-utilities.md |
| FUN_0059a407 | Pointer Offset Adjuster |  | — | docs/01-engine-architecture.md |
| FUN_0057a0c0 | 16-Byte Memory Comparison for Equality |  | — | docs/01-engine-architecture.md |
| FUN_0059a428 | Double Indirect Counter Update |  | — | docs/01-engine-architecture.md |
| FUN_00563000 | Polling Loop with Process Calls |  | — | docs/01-engine-architecture.md |
| FUN_0046e7f0 | Polling Loop with Branch |  | — | docs/01-engine-architecture.md |
| FUN_00478090 | Virtual Factory + Store |  | — | docs/20-math-utilities.md |
| FUN_00561620 | Recursive Tree Node Traversal |  | — | docs/01-engine-architecture.md |
| FUN_00563020 | Multi-Stage Initialization Chain with Error Checking |  | — | docs/21-audio-network-internals.md |
| FUN_0057a1e0 | Small Struct Field Init (6 Fields) |  | — | docs/01-engine-architecture.md |
| Unwind_0059c980 | C++ Unwind Helper (thunk to FUN_00581880) |  | — | docs/20-math-utilities.md |
| Unwind_0059d058 | C++ Unwind Helper (thunk to FUN_00583650) |  | — | docs/20-math-utilities.md |
| FUN_00564780 | Function Pointer Call with Error Handling |  | — | docs/01-engine-architecture.md |
| FUN_0058e12e | Encoding/Locale Detection from Parse Result |  | — | docs/20-math-utilities.md |
| FUN_00599ad9 | Ref Count Decrement with Check |  | DAT_005ea04c | docs/20-math-utilities.md |
| FUN_00464f50 | Division with Cap Computation |  | — | docs/19-renderer.md |
| FUN_0046c7b0 | Indexed Array Insert with Shift |  | DAT_007cd2b8 | docs/19-renderer.md |
| FUN_0049afe0 | Multi-Call Sequence |  | — | docs/19-renderer.md |
| FUN_004cb5a0 | Array Element Removal (Swap-Out) |  | — | docs/01-engine-architecture.md |
| FUN_004d93e0 | Range Check (1-5) |  | — | docs/19-renderer.md |
| FUN_005388d0 | Frequency Table Construction |  | — | docs/18-physics-dynamics.md |
| FUN_0053d2b0 | Guarded Delegation |  | — | docs/20-math-utilities.md |
| FUN_00558990 | Resource Teardown with State Array Reset |  | — | docs/01-engine-architecture.md |
| FUN_00568750 | ASCII Char Code Validation (Printable vs Special) |  | — | docs/20-math-utilities.md |
| FUN_00583530 | Zero-Fill Memory Region with Step |  | — | docs/01-engine-architecture.md |
| FUN_0040e1f0 | Global Vector Offset Update |  | — | docs/01-engine-architecture.md |
| FUN_00462d30 | Enum-to-Enum Translator |  | — | docs/20-math-utilities.md |
| FUN_004a1830 | Windows Message Pump with Sleep |  | — | docs/20-math-utilities.md |
| FUN_00564890 | Indirect Call via Function Pointer |  | — | docs/08-file-formats.md |
| FUN_00456010 | Utility Function |  | — | docs/20-math-utilities.md |
| FUN_00477810 | Utility Function |  | — | docs/20-math-utilities.md |
| FUN_0049d8b0 | Utility Function |  | — | docs/20-math-utilities.md |

### vtable_dispatch (80 entries)
| Address | Name | Key Logic | Globals | Target |
|---------|------|-----------|---------|--------|
| FUN_0057a4c0 | VTable Destructor Then Null Pointer |  | — | docs/01-engine-architecture.md |
| FUN_0057a4f0 | Virtual Function Dispatch with Stack Frames |  | — | docs/01-engine-architecture.md |
| FUN_00585bf0 | Iterate Triggers via Vtable, Call Handlers per Tick |  | — | docs/01-engine-architecture.md |
| FUN_00586620 | Node Destruction with Virtual Call |  | — | docs/20-math-utilities.md |
| FUN_0059a7de | Destructor with SEH + VTable Reset |  | — | docs/01-engine-architecture.md |
| FUN_0057bc70 | Single VTable Pointer Set |  | — | docs/20-math-utilities.md |
| FUN_0059379b | SEH-Aware Virtual Call Dispatch Loop |  | — | docs/08-file-formats.md |
| FUN_0059b038 | Object Init with VTable |  | — | docs/01-engine-architecture.md |
| FUN_0040fd70 | Short Computation / VTable Init + Thunk |  | — | docs/20-math-utilities.md |
| FUN_004562c0 | Short Computation / Destructor with VTable Reset |  | — | docs/20-math-utilities.md |
| FUN_00466d60 | Short Computation / Object Init + VTable |  | — | docs/01-engine-architecture.md |
| FUN_0046a530 | Short Computation / Destructor VTable Reset + Free |  | — | docs/20-math-utilities.md |
| FUN_0046fd00 | Short Computation / Object Init with VTable + Field |  | — | docs/01-engine-architecture.md |
| FUN_00485570 | Short Computation / Destructor with VTable |  | — | docs/01-engine-architecture.md |
| FUN_0048c9d0 | Short Computation / VTable Set Only |  | — | docs/01-engine-architecture.md |
| FUN_0048d6a0 | Short Computation / VTable Init + Call |  | — | docs/19-renderer.md |
| FUN_0057a580 | VTable Call via Offset 0x6c |  | — | docs/20-math-utilities.md |
| FUN_00598775 | Vtable Fixup with Destructor |  | — | docs/20-math-utilities.md |
| FUN_00599e66 | VTable Pointer Setter |  | — | docs/20-math-utilities.md |
| FUN_005544c0 | Game State Setting via Virtual Dispatch |  | DAT_008b89a0 | docs/20-math-utilities.md |
| FUN_0053d850 | Object Release with Vtable Call |  | — | docs/01-engine-architecture.md |
| FUN_0059ae7d | C++ Object Constructor with Vtable |  | — | docs/20-math-utilities.md |
| FUN_00554510 | Enum-to-ID Mapping with VTable Notify |  | DAT_008b89a0 | docs/20-math-utilities.md |
| FUN_0055ca40 | Enum-to-VTable-Call Mapper (3 Cases) |  | — | docs/01-engine-architecture.md |
| FUN_0057a660 | Dual Virtual Dispatch Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_00582340 | VTable Call with Flag Check |  | — | docs/01-engine-architecture.md |
| FUN_0055cdf0 | Triple Vtable Query and Store |  | — | docs/20-math-utilities.md |
| FUN_0057a690 | Virtual Method Dispatch (vtable+100) |  | — | docs/01-engine-architecture.md |
| FUN_00405630 | Struct Init with VTable Dispatch and Zero Fill |  | — | docs/21-audio-network-internals.md |
| FUN_0046da20 | Dispatch Chain with VTable Calls |  | — | docs/01-engine-architecture.md |
| FUN_00471860 | Object Constructor with VTable and Field Init |  | — | docs/01-engine-architecture.md |
| FUN_00475040 | VTable Setter with Sub-call |  | — | docs/01-engine-architecture.md |
| FUN_004798e0 | VTable Setter with Float Params |  | — | docs/01-engine-architecture.md |
| FUN_004879e0 | Init Dispatch with VTable Check |  | — | docs/01-engine-architecture.md |
| FUN_00488f90 | VTable Set with Flag |  | — | docs/01-engine-architecture.md |
| FUN_0048b4e0 | VTable Setter + Sub-call |  | — | docs/01-engine-architecture.md |
| FUN_00499140 | Constructor with VTable and Sub-init |  | — | docs/20-math-utilities.md |
| FUN_004b19b0 | VTable + Patterned Field Init | [1]=0, [2]=-1, [3]=0, [4]=-1 *param_1 = PTR_LAB_005acc20 **Used by system:** docs/01-engine-architec | — | docs/19-renderer.md |
| FUN_004c8f80 | VTable Dispatch with Negation |  | — | docs/20-math-utilities.md |
| FUN_0050a8f5 | VTable Setter with Sub-init (Type 1) |  | — | docs/01-engine-architecture.md |
| FUN_0050b3d1 | VTable Setter with Sub-init (Type 3) |  | — | docs/20-math-utilities.md |
| FUN_00541670 | VTable Dispatch with Field Check |  | — | docs/01-engine-architecture.md |
| FUN_005507e0 | Struct Init with Vtable Zero |  | — | docs/21-audio-network-internals.md |
| FUN_0055ce50 | Set UI Text Fields via Vtable Calls |  | — | docs/01-engine-architecture.md |
| FUN_00598a41 | Vtable/Cctor Init |  | — | docs/20-math-utilities.md |
| FUN_0057dbb0 | Vtable Call + Format Dispatch + Timer Dispatch Chain |  | — | docs/20-math-utilities.md |
| FUN_005628f0 | Large Stack Struct Zero-Init with Vtable Call |  | — | docs/21-audio-network-internals.md |
| FUN_00598aea | Vtable Set + Sub-Call |  | — | docs/01-engine-architecture.md |
| FUN_00554b20 | Resource Factory via VTable Dispatch |  | — | docs/01-engine-architecture.md |
| FUN_0057a830 | VTable Boolean Test Wrapper |  | — | docs/20-math-utilities.md |
| FUN_00598af5 | Object Constructor with VTable Setup and SEH |  | — | docs/01-engine-architecture.md |
| FUN_005998a1 | VTable Fixup During Construction |  | — | docs/20-math-utilities.md |
| FUN_0057a850 | VTable Bool Check (Inverted) |  | — | docs/01-engine-architecture.md |
| FUN_00598b5d | Object Constructor with SEH + Vtable Init |  | — | docs/01-engine-architecture.md |
| FUN_005993eb | Object Init with VTable + Flag Set |  | — | docs/01-engine-architecture.md |
| FUN_0059ac3f | VTable Pointer Setter |  | — | docs/20-math-utilities.md |
| FUN_0057a880 | VTable Query with Stack Buffer Result |  | — | docs/01-engine-architecture.md |
| FUN_00585220 | Status Check via VTable Dispatch |  | — | docs/01-engine-architecture.md |
| FUN_00598bbc | Object Constructor with SEH + VTable Init Chain |  | — | docs/20-math-utilities.md |
| FUN_005998e5 | VTable Set + Sub-Call |  | — | docs/20-math-utilities.md |
| FUN_005550a0 | VTable Getter Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_0057a8b0 | VTable Call via Offset 0x7c |  | — | docs/20-math-utilities.md |
| FUN_0050f6f2 | VTable Dtor + Null Fields |  | — | docs/20-math-utilities.md |
| FUN_005550c0 | VTable Dispatch Getter |  | — | docs/01-engine-architecture.md |
| FUN_0057a8c0 | Virtual Dispatch Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_0057b780 | Object Init with VTable + Field Set |  | — | docs/01-engine-architecture.md |
| FUN_00585380 | VTable Dispatch with Conditional Call |  | — | docs/01-engine-architecture.md |
| FUN_00407070 | Array + Linked-List Virtual Dispatch Iterator |  | — | docs/20-math-utilities.md |
| FUN_004526c0 | Array Destructor via Virtual Dispatch |  | — | docs/19-renderer.md |
| FUN_00587030 | Object Init with VTable Setup |  | — | docs/01-engine-architecture.md |
| FUN_00598c70 | Null Check with Virtual Dispatch |  | — | docs/01-engine-architecture.md |
| FUN_004189b0 | State-Checked Virtual Dispatch |  | — | docs/20-math-utilities.md |
| FUN_004780d0 | State-Dependent Virtual Dispatch |  | — | docs/19-renderer.md |
| FUN_00499af0 | Object Reset with VTable Dispatch |  | — | docs/20-math-utilities.md |
| FUN_0050af3b | Object Init with VTable (alloc 0x20) |  | — | docs/01-engine-architecture.md |
| FUN_0050b77b | Object Init with VTable (alloc 0x40) |  | — | docs/21-audio-network-internals.md |
| FUN_00516937 | Virtual Dispatch + Conditional Value |  | — | docs/20-math-utilities.md |
| FUN_0052e1c0 | Thunk with VTable + Flag Check |  | — | docs/21-audio-network-internals.md |
| FUN_00599e71 | C++ Destructor with VTable Chain |  | — | docs/20-math-utilities.md |
| FUN_0057b7d0 | Object Copy-Init with VTable Setup |  | — | docs/01-engine-architecture.md |

### call_wrappers (66 entries)
| Address | Name | Key Logic | Globals | Target |
|---------|------|-----------|---------|--------|
| FUN_005564b0 | QueryPerformanceCounter Wrapper with Mode Dispatch |  | — | docs/20-math-utilities.md |
| FUN_005648c0 | Single Function Call Wrapper |  | — | docs/08-file-formats.md |
| FUN_0057aa10 | Single Function Call Wrapper |  | — | docs/21-audio-network-internals.md |
| FUN_00583650 | Single Function Call Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_00587a90 | Single Function Call Wrapper |  | — | docs/20-math-utilities.md |
| FUN_0058ef5f | Increment Wrapper Around Call Loop |  | — | docs/20-math-utilities.md |
| FUN_005986ec | Single Function Call Wrapper |  | — | docs/08-file-formats.md |
| FUN_0059d7b5 | Single Function Call Wrapper |  | — | docs/20-math-utilities.md |
| FUN_0055f060 | GlobalMemoryStatus Wrapper |  | — | docs/20-math-utilities.md |
| FUN_00568cb0 | QPC Timestamp Read Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_00587b7f | Init Wrapper Calling 3 Subroutines |  | DAT_008d3e44 | docs/01-engine-architecture.md |
| FUN_00583690 | Single Function Call Wrapper (Timer Delta) |  | — | docs/01-engine-architecture.md |
| FUN_0059d963 | Single Function Call Wrapper |  | — | docs/17-physics-collision.md |
| FUN_0059b07a | Single Function Call Wrapper |  | — | docs/20-math-utilities.md |
| FUN_0059d984 | Single Function Call Wrapper |  | — | docs/20-math-utilities.md |
| FUN_005997a1 | Single Function Call Wrapper |  | — | docs/08-file-formats.md |
| FUN_00586a00 | Single Function Call Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_005938b4 | SEH Wrapper Around CRT Function Call |  | — | docs/20-math-utilities.md |
| FUN_00598794 | Single Function Call Wrapper |  | — | docs/20-math-utilities.md |
| FUN_0055c7d0 | Input State Query Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_005649d0 | Call Chain Wrapper |  | — | docs/20-math-utilities.md |
| FUN_0057adf0 | Single Function Call Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_00582310 | CloseHandle Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_005987f0 | Locale Function Call Wrapper |  | — | docs/08-file-formats.md |
| FUN_005997ab | Single Function Call Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_0059dad5 | Single Function Call Wrapper |  | — | docs/20-math-utilities.md |
| FUN_00561f60 | Single Function Call Wrapper |  | — | docs/20-math-utilities.md |
| FUN_0057ae70 | Single Function Call Wrapper (to constructor) |  | — | docs/01-engine-architecture.md |
| FUN_00585e10 | Single Function Call Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_00586a80 | Single Function Call Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_00587430 | Single Function Call Wrapper (to constructor) |  | — | docs/08-file-formats.md |
| FUN_0059daef | Single Call Wrapper |  | — | docs/20-math-utilities.md |
| FUN_005507d0 | Refcount Decrement / Resource Release Wrapper |  | — | docs/20-math-utilities.md |
| FUN_00421a50 | Dual Call Wrapper |  | — | docs/20-math-utilities.md |
| FUN_00466080 | Call Wrapper |  | — | docs/08-file-formats.md |
| FUN_0046af00 | Dual Call Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_0047e940 | Conditional Call Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_004a1e20 | Triple Dispatch Wrapper |  | — | docs/18-physics-dynamics.md |
| FUN_004b9870 | Call Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_004d7d90 | Call Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_0053c140 | Call Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_0055c060 | Call Wrapper |  | — | docs/08-file-formats.md |
| FUN_00583aa0 | Close Handle Pair Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_00579ff0 | Single Function Call Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_00599822 | Single Function Call Wrapper |  | — | docs/20-math-utilities.md |
| FUN_0057a750 | Single Function Call Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_0059a9c2 | Single Function Call Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_00593c9c | SEH Wrapper Dispatching to Handler Function |  | — | docs/01-engine-architecture.md |
| FUN_00597321 | IsBadReadPtr Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_0057a040 | Pass-Through Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_0057a810 | Single Function Call Wrapper |  | — | docs/20-math-utilities.md |
| FUN_0059733d | IsBadWritePtr Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_0059988b | Function Call Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_00564650 | Sleep Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_00586f10 | Single Function Call Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_005861e0 | CloseHandle Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_00586f20 | Single Function Call Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_005876c0 | Single Function Call Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_00599933 | Single Function Call Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_0057a910 | Single Function Call Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_00461dc0 | State Check Wrapper |  | — | docs/20-math-utilities.md |
| FUN_00559a30 | Single Function Call Wrapper |  | — | docs/19-renderer.md |
| FUN_0057a920 | Single Function Call Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_0059d6a9 | Null-Checked Call Wrapper |  | — | docs/20-math-utilities.md |
| FUN_004a0de0 | Function Call Wrapper |  | — | docs/20-math-utilities.md |
| FUN_00561f40 | Dispatch Wrapper to Timeout Handler |  | — | docs/20-math-utilities.md |

### memory_cleanup (53 entries)
| Address | Name | Key Logic | Globals | Target |
|---------|------|-----------|---------|--------|
| FUN_0058ef48 | Conditional Free if Handle Not -1 |  | — | docs/20-math-utilities.md |
| FUN_0059964a | Buffer Allocation with Size Rounding |  | — | docs/20-math-utilities.md |
| FUN_005502c0 | Destructor with Conditional Free + Flag Clear |  | — | docs/01-engine-architecture.md |
| FUN_00564930 | Accumulator with Realloc on Growth |  | — | docs/20-math-utilities.md |
| FUN_0058f8eb | Multi-Field Free (7 Allocations) |  | — | docs/01-engine-architecture.md |
| FUN_00418c10 | Memory Allocation / Nested Pointer Free with Conditional Dea |  | — | docs/20-math-utilities.md |
| FUN_00485eb0 | Unidentified / Multi-Struct Destructor |  | — | docs/17-physics-collision.md |
| FUN_00587bcf | Free Wrapper (Thunk to FUN_0058aa6f) |  | — | docs/20-math-utilities.md |
| FUN_0057adc0 | Free Callback Registration |  | — | docs/01-engine-architecture.md |
| FUN_00564270 | Singleton/Global Accessor with Fallback Alloc |  | — | docs/01-engine-architecture.md |
| FUN_00551f80 | Conditional Free with Bink Close |  | — | docs/01-engine-architecture.md |
| FUN_00587c03 | operator new(uint) → __nh_malloc Wrapper |  | — | docs/08-file-formats.md |
| FUN_0059a8bc | Sub-Call + Conditional Free |  | — | docs/01-engine-architecture.md |
| FUN_0059b390 | Dual-Pointer Free |  | — | docs/01-engine-architecture.md |
| FUN_00548eb0 | Multi-List Free with Traversal |  | — | docs/20-math-utilities.md |
| FUN_0056cf10 | Quad-Pointer Free |  | — | docs/20-math-utilities.md |
| FUN_00560b30 | Conditional Free of Struct Field |  | — | docs/01-engine-architecture.md |
| FUN_0059a336 | Conditional Free with Flag Check |  | — | docs/01-engine-architecture.md |
| FUN_0059a371 | Sub-call + Conditional Free |  | — | docs/20-math-utilities.md |
| FUN_00485660 | Destructor with Conditional Free |  | — | docs/20-math-utilities.md |
| FUN_0048e0b0 | Destructor with Conditional Free |  | — | docs/01-engine-architecture.md |
| FUN_0052d9d0 | Destructor with Conditional Free | Indirect jmp to AVIFileRelease (Video for Windows API) **Used by system:** docs/08-file-formats.md - | — | docs/01-engine-architecture.md |
| FUN_0053cac0 | Object Allocation with Init |  | — | docs/20-math-utilities.md |
| FUN_00566d30 | Conditional Alloc/Init Dispatch |  | — | docs/20-math-utilities.md |
| FUN_00560b90 | Conditional Free of Field |  | — | docs/20-math-utilities.md |
| FUN_00587460 | Array/Struct Alloc with Count + Init |  | — | docs/20-math-utilities.md |
| FUN_00550820 | Array-of-Struct Destructor with Countdown |  | — | docs/19-renderer.md |
| FUN_00565dc0 | Allocate Struct with Default Values |  | — | docs/20-math-utilities.md |
| FUN_0059ab83 | Object Destructor with SEH |  | — | docs/08-file-formats.md |
| FUN_005697f0 | Triple Buffer Allocation |  | — | docs/20-math-utilities.md |
| FUN_005875c0 | Buffer Reallocation and Data Copy |  | — | docs/08-file-formats.md |
| FUN_00585030 | Allocation Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_00564690 | String Malloc + Copy (strdup) |  | — | docs/20-math-utilities.md |
| FUN_005532a0 | Object Allocation with Zero-Init |  | — | docs/01-engine-architecture.md |
| FUN_005646d0 | Allocate Int Array via Factory |  | — | docs/01-engine-architecture.md |
| FUN_005881c0 | Stack Probe / alloca |  | — | docs/08-file-formats.md |
| FUN_00599913 | Free Callback Registration |  | — | docs/20-math-utilities.md |
| FUN_00414420 | Multi-Pointer Free (5 pointers) |  | — | docs/20-math-utilities.md |
| FUN_0050b75f | Destructor with Self-Free |  | — | docs/18-physics-dynamics.md |
| FUN_005668d0 | Sub-Call with Conditional Field Free |  | — | docs/20-math-utilities.md |
| FUN_0057b7b0 | Conditional Free Based on Flag Bit |  | — | docs/01-engine-architecture.md |
| FUN_0045bb90 | Object Allocator (0x32c bytes) |  | — | docs/20-math-utilities.md |
| FUN_004646f0 | Conditional Destructor |  | — | docs/01-engine-architecture.md |
| FUN_004698c0 | Destructor with Sub-Object Free |  | — | docs/01-engine-architecture.md |
| FUN_004952e0 | Destructor with Conditional Free |  | — | docs/01-engine-architecture.md |
| FUN_004ba950 | Conditional Allocation |  | — | docs/01-engine-architecture.md |
| FUN_004bb460 | Destructor with Conditional Free |  | — | docs/20-math-utilities.md |
| FUN_00567a90 | Recursive Tree Traversal + Free |  | — | docs/20-math-utilities.md |
| FUN_00553980 | Object Constructor with Allocation and Sub-Init |  | — | docs/01-engine-architecture.md |
| FUN_00587070 | Destructor with Conditional Free |  | — | docs/01-engine-architecture.md |
| FUN_00598502 | Null-Terminated Int Array Copy with Alloc |  | — | docs/20-math-utilities.md |
| FUN_00598600 | String Alloc+Copy |  | — | docs/20-math-utilities.md |
| FUN_00582290 | Conditional Free by Flag Check |  | — | docs/20-math-utilities.md |

### threading_synchronization (50 entries)
| Address | Name | Key Logic | Globals | Target |
|---------|------|-----------|---------|--------|
| FUN_00585770 | Thread-Safe Int Read with Mutex |  | — | docs/01-engine-architecture.md |
| FUN_00586560 | Mutex Create/Replace Wrapper |  | — | docs/20-math-utilities.md |
| FUN_0058a323 | Atomic LOCK/UNLOCK with Indirect Call |  | — | docs/01-engine-architecture.md |
| FUN_0058afd8 | TLS Offset Getter (+12) |  | — | docs/08-file-formats.md |
| FUN_005865c0 | Create Mutex via Win32 API |  | — | docs/01-engine-architecture.md |
| FUN_00595a61 | Critical Section Enter with Lazy Init |  | DAT_008d4920 | docs/01-engine-architecture.md |
| FUN_0058b75f | Mutex Unlock Wrapper |  | — | docs/20-math-utilities.md |
| FUN_00595ac0 | File Critical Section Leave |  | DAT_008d4920 | docs/01-engine-architecture.md |
| FUN_00585cd0 | Thread-Safe Write with Mutex |  | — | docs/19-renderer.md |
| FUN_0058b8ad | Semaphore Release (Slot 9) |  | — | docs/01-engine-architecture.md |
| FUN_00585d20 | Mutex-Protected Pointer Read + Release |  | — | docs/20-math-utilities.md |
| FUN_0058b903 | Semaphore-Guarded Query Call |  | — | docs/01-engine-architecture.md |
| FUN_00585d70 | Thread-Safe String Read with Mutex |  | — | docs/01-engine-architecture.md |
| FUN_0057c950 | Thread-Safe Linked-List Lookup with Mutex + Data Copy |  | — |  |
| FUN_00583d40 | Mutex-Protected Data Read with Timed Wait |  | — | docs/01-engine-architecture.md |
| FUN_004066c0 | Mutex-Protected Value Read with Timeout |  | — | docs/20-math-utilities.md |
| FUN_005840d0 | Mutex Wait with 1ms Timeout + Release |  | — | docs/01-engine-architecture.md |
| FUN_0058bbd2 | Lock Release by Index (CritSect leave #9) |  | — | docs/20-math-utilities.md |
| FUN_00582360 | Win32 Mutex Create/Recreate |  | — | docs/01-engine-architecture.md |
| FUN_00584c70 | Thread-Safe Call with Mutex |  | — | docs/20-math-utilities.md |
| FUN_0058bc4d | Critical Section Leave (Slot 9) |  | — | docs/20-math-utilities.md |
| FUN_00582720 | Mutex Create/Replace Wrapper |  | — | docs/01-engine-architecture.md |
| FUN_00584dd0 | Mutex-Protected Dispatch Call |  | — | docs/01-engine-architecture.md |
| FUN_00584f30 | Mutex-Protected Function Call with Wait |  | — | docs/01-engine-architecture.md |
| FUN_00585f60 | Mutex Wait with Success Check |  | — | docs/20-math-utilities.md |
| FUN_00584f90 | Mutex-Guarded Timer Read |  | — | docs/01-engine-architecture.md |
| FUN_00585f90 | ReleaseMutex Wrapper Returning Success |  | — | docs/19-renderer.md |
| FUN_0057dff0 | Mutex-Protected Linked-List Lookup by ID |  | — | docs/01-engine-architecture.md |
| FUN_00589d6b | Lock Acquire by Index |  | — | docs/01-engine-architecture.md |
| FUN_0057e6e0 | Thread-Safe Linked List Destruction with Mutex |  | — | docs/01-engine-architecture.md |
| FUN_00589d74 | Critical Section Leave (Slot 0xd) |  | — | docs/20-math-utilities.md |
| FUN_00551390 | Per-Entity Data Block Copy from Parameter Table |  | — | docs/20-math-utilities.md |
| FUN_0057e760 | Mutex-Protected Linked List Flush/Destroy |  | — | docs/01-engine-architecture.md |
| FUN_0058dfea | Critical Section Lazy Init + Enter |  | DAT_005e6c80 | docs/20-math-utilities.md |
| FUN_0057e7e0 | Mutex-Protected Linked List Destruction |  | — | docs/20-math-utilities.md |
| FUN_0058a02c | Memory Block Validation Check |  | — | docs/20-math-utilities.md |
| FUN_0058c1e0 | Critical Section Enter |  | — | docs/20-math-utilities.md |
| FUN_0057ee80 | Thread-Safe Mutex Queue with Timed Wait |  | — | docs/20-math-utilities.md |
| FUN_0058aad9 | Semaphore Release (Slot 9) |  | — | docs/01-engine-architecture.md |
| FUN_0058c232 | Critical Section Leave |  | — | docs/01-engine-architecture.md |
| FUN_0058e060 | TLS Allocation + Thread ID Init |  | — | docs/20-math-utilities.md |
| FUN_00462760 | Buffer Send with Locks |  | — | docs/01-engine-architecture.md |
| FUN_00585810 | Mutex-Protected Worker Call |  | — | docs/20-math-utilities.md |
| FUN_0058ab31 | Lock Release by Index (CritSect 9) |  | — | docs/20-math-utilities.md |
| FUN_00598c4a | Counter Increment Thread-Safe |  | — | docs/01-engine-architecture.md |
| FUN_0058abf1 | Critical Section Leave (Slot 9) |  | — | docs/20-math-utilities.md |
| FUN_005855e0 | Thread Suspend with Mutex Wait/Lock |  | — | docs/20-math-utilities.md |
| FUN_00585680 | Thread Resume with Mutex Wait |  | — | docs/01-engine-architecture.md |
| FUN_00586500 | Mutex Create/Recreate |  | — | docs/01-engine-architecture.md |
| FUN_0059247a | Critical Section Guarded Call |  | — | docs/01-engine-architecture.md |

### linked_list_operations (46 entries)
| Address | Name | Key Logic | Globals | Target |
|---------|------|-----------|---------|--------|
| FUN_00465d70 | Recursive Linked List Merge Sort |  | — | docs/01-engine-architecture.md |
| FUN_004c6810 | Recursive Linked List Merge Sort (Float Comparator) |  | — | docs/10-vehicle-physics.md |
| FUN_004c2e20 | Recursive Linked List Merge Sort (Float Field Compare) |  | — | docs/19-renderer.md |
| FUN_005819c0 | Linked List Destroy with Vtable Destructor Call |  | — | docs/20-math-utilities.md |
| FUN_00581820 | Linked List Destroy + CloseHandle |  | — | docs/01-engine-architecture.md |
| FUN_00586000 | Linked-List Node Append |  | — | docs/20-math-utilities.md |
| FUN_00581a20 | Handle Close + Linked-List Destruction with VTable Release |  | — | docs/01-engine-architecture.md |
| FUN_00551830 | Wide-String Comparison Walking Linked List |  | — | docs/01-engine-architecture.md |
| FUN_005519e0 | Doubly-Linked List Node Removal |  | — | docs/01-engine-architecture.md |
| FUN_0055c2e0 | Doubly-Linked List Node Unlink by Match |  | — | docs/20-math-utilities.md |
| FUN_00407dd0 | Short Computation / Linked List Walker with Progress Callbac |  | — | docs/20-math-utilities.md |
| FUN_0049a150 | Short Computation / Linked List Nth Element |  | — | docs/20-math-utilities.md |
| FUN_004b2100 | Unidentified Logic / Linked List Destructor |  | — | docs/20-math-utilities.md |
| FUN_004c7e80 | Unidentified Logic / Double-Linked List Destroy with Virtual |  | — | docs/19-renderer.md |
| FUN_0055bde0 | Unidentified Logic / Linked List Indexed Traversal |  | — | docs/20-math-utilities.md |
| FUN_005592b0 | Doubly-Linked List Node Removal by Pointer |  | — | docs/01-engine-architecture.md |
| FUN_00408050 | Linked List Node Search by ID + Operation |  | — | docs/01-engine-architecture.md |
| FUN_00486f30 | Linked List Insert with Node Allocation |  | — | docs/01-engine-architecture.md |
| FUN_0048cc20 | Linked List Size Calc with Max Tracking |  | — | docs/01-engine-architecture.md |
| FUN_004902c0 | Linked List Destructor with VTable Notification |  | — | docs/20-math-utilities.md |
| FUN_004baeb0 | Linked List Destructor with Callback |  | — | docs/20-math-utilities.md |
| FUN_005161dd | Linked List Node Alloc and Insert |  | — | docs/01-engine-architecture.md |
| FUN_0059a980 | Double Linked List Free |  | — | docs/08-file-formats.md |
| FUN_0057b050 | Linked List Node Removal with Memory Free |  | — | docs/01-engine-architecture.md |
| FUN_00582f60 | SEH-Protected Linked List Destruction |  | — | docs/01-engine-architecture.md |
| FUN_005570c0 | Nested Linked List Traversal with Dirty Mark |  | — | docs/01-engine-architecture.md |
| FUN_00583050 | Destroy Linked List with SEH, Call Destructors |  | — | docs/01-engine-architecture.md |
| FUN_00565f50 | Linked List Pop Front |  | — | docs/08-file-formats.md |
| FUN_005833e0 | Walk Linked List, Call Destructor, Free Nodes |  | — | docs/01-engine-architecture.md |
| FUN_00404e60 | Linked-List Node Insertion |  | — | docs/21-audio-network-internals.md |
| FUN_00581780 | Linked List Node Advance |  | — | docs/01-engine-architecture.md |
| FUN_005834c0 | List Destruction with Virtual Release |  | — | docs/01-engine-architecture.md |
| FUN_00586460 | Destroy Linked List with VTable Destructor Dispatch |  | — | docs/01-engine-architecture.md |
| FUN_0045ebd0 | Linked List Purge by Threshold (0x40) |  | — | docs/01-engine-architecture.md |
| FUN_00486580 | Linked List Node Insert |  | — | docs/19-renderer.md |
| FUN_00490aa0 | Linked List Node Prepend |  | — | docs/01-engine-architecture.md |
| FUN_00496840 | Linked List Summation with Iterator |  | — | docs/01-engine-architecture.md |
| FUN_00499520 | Linked List Virtual Dispatch |  | — | docs/01-engine-architecture.md |
| FUN_004b5760 | Linked List Iterator with State Update |  | — | docs/01-engine-architecture.md |
| FUN_004bf640 | Linked List Destruction |  | — | docs/01-engine-architecture.md |
| FUN_004c2850 | Linked List Dereference |  | — | docs/01-engine-architecture.md |
| FUN_004fd840 | Dual Linked List Destruction |  | — | docs/21-audio-network-internals.md |
| FUN_0055bba0 | Linked List Free with Traversal and Nulling |  | — | docs/01-engine-architecture.md |
| FUN_00581880 | Linked List Destruction with VTable Release Call |  | — | docs/01-engine-architecture.md |
| FUN_005818e0 | List Destruction with Handle Close |  | — | docs/01-engine-architecture.md |
| FUN_00583570 | List Destruction with COM Release |  | — | docs/01-engine-architecture.md |

### memory_operations (44 entries)
| Address | Name | Key Logic | Globals | Target |
|---------|------|-----------|---------|--------|
| FUN_0057b820 | Object Init with Copy (Socket Close Helper) |  | — | docs/01-engine-architecture.md |
| FUN_005996ae | Buffer Size Management with Copy |  | — | docs/20-math-utilities.md |
| FUN_00553de0 | Struct Zero-Init Constructor |  | — | docs/20-math-utilities.md |
| FUN_00564960 | Aligned Memory Copy from Struct Buffer |  | — | docs/08-file-formats.md |
| FUN_0057aaf0 | Stack Buffer Copy + Predicate Call |  | — | docs/01-engine-architecture.md |
| FUN_0058924c | Byte Buffer Swap (In-Place) |  | — | docs/19-renderer.md |
| FUN_00598de3 | Memory Copy from ID Lookup |  | — | docs/20-math-utilities.md |
| FUN_00498560 | Unidentified / String Copy to Struct Buffer |  | — | docs/20-math-utilities.md |
| FUN_005836a0 | Large Structure Zero-Initialization |  | — | docs/01-engine-architecture.md |
| FUN_00558e10 | Pixel Write to Texture Buffer |  | — | docs/01-engine-architecture.md |
| FUN_0057d5d0 | Structured Memory Copy with Header Prepend |  | — | docs/01-engine-architecture.md |
| FUN_00586a10 | Bounded Memory Copy with Size Validation |  | — | docs/01-engine-architecture.md |
| FUN_00587370 | Copy Buffer Header Fields + Call Init |  | — | docs/01-engine-architecture.md |
| FUN_0057d660 | Buffer Unpack with Size Check + Byte/Word Copy |  | — | docs/01-engine-architecture.md |
| FUN_0049d480 | Local Buffer + Subsystem Call |  | — | docs/01-engine-architecture.md |
| FUN_004fc650 | String Copy with Ring Buffer |  | DAT_008aae64, DAT_0083ee60 | docs/18-physics-dynamics.md |
| FUN_00536160 | Buffer Copy with Size Tracking | Computes copy size = min(*(param_1+0x10), *(source+0x14)) Copies data in dwords then residual bytes  | — | docs/01-engine-architecture.md |
| FUN_00550800 | Dual Field Zero-Init |  | — | docs/01-engine-architecture.md |
| FUN_0057a020 | Struct Zero-Init (4 + 8 Words) |  | — | docs/01-engine-architecture.md |
| FUN_00562890 | Buffer Zero-Init with Virtual Method Call |  | — | docs/20-math-utilities.md |
| FUN_00587580 | Buffer Query: Return Ptr+Size If Valid |  | — | docs/20-math-utilities.md |
| FUN_005992ef | Buffer Append with Memset |  | — | docs/01-engine-architecture.md |
| FUN_0055d2a0 | String Copy with Flag Union |  | — | docs/01-engine-architecture.md |
| FUN_00584ff0 | String Copy to Buffer with Length Cap |  | — | docs/20-math-utilities.md |
| FUN_00599348 | Buffer Truncation/Shrink |  | — | docs/01-engine-architecture.md |
| FUN_00559a40 | Large Buffer Zero-Init (0x60 Dwords) |  | — | docs/20-math-utilities.md |
| FUN_00567a00 | Struct Zero-Init (9 Words + Loop) |  | — | docs/18-physics-dynamics.md |
| FUN_0057b550 | Ring Buffer Push with Wrap Check |  | — | docs/01-engine-architecture.md |
| FUN_00587620 | Buffer Write with Params |  | — | docs/08-file-formats.md |
| FUN_0057a0f0 | Byte-Aligned Memory Copy with Offset |  | — | docs/01-engine-architecture.md |
| FUN_0057b5c0 | Ring Buffer Pop with Wrap Check |  | — | docs/01-engine-architecture.md |
| FUN_0057a1b0 | Memcpy with Advance Pointer |  | — | docs/01-engine-architecture.md |
| FUN_005994bc | Object Initialization with Buffer/Bounds Setup |  | DAT_008d5a68 | docs/01-engine-architecture.md |
| FUN_0059a473 | Object Init with Buffer/Data Pointer Assignment |  | DAT_008d5a60 | docs/01-engine-architecture.md |
| FUN_0055bb70 | Partial Struct Zero-Init |  | — | docs/01-engine-architecture.md |
| FUN_0057a200 | memcpy-like Copy with Word/Byte Split + Size Store |  | — | docs/01-engine-architecture.md |
| FUN_00599534 | Buffer Boundary Marker Check + Set |  | — | docs/01-engine-architecture.md |
| FUN_004d0060 | Zero-Init + Sub-Call |  | — | docs/19-renderer.md |
| FUN_004ddf70 | Zero-Init Wrapper |  | — | docs/18-physics-dynamics.md |
| FUN_0057a230 | Byte-Aligned Memory Copy from Struct |  | — | docs/01-engine-architecture.md |
| FUN_00587930 | Buffer Copy via Virtual Type Dispatch |  | — | docs/08-file-formats.md |
| FUN_00568ba0 | Struct Zero-Init (17 Fields) |  | — | docs/18-physics-dynamics.md |
| FUN_00587090 | Object Copy-Construct from Source |  | — | docs/20-math-utilities.md |
| FUN_00599615 | Buffer Write with Null-Terminate |  | — | docs/20-math-utilities.md |

### callback_registration (28 entries)
| Address | Name | Key Logic | Globals | Target |
|---------|------|-----------|---------|--------|
| FUN_004dc320 | Short Computation / Callback Registration |  | — | docs/01-engine-architecture.md |
| FUN_004f23b0 | Short Computation / Callback Registration |  | — | docs/18-physics-dynamics.md |
| FUN_0052e5b0 | Short Computation / Callback Registration |  | — | docs/20-math-utilities.md |
| FUN_0059aaa3 | Short Computation / Callback Registration |  | — | docs/20-math-utilities.md |
| FUN_005987ff | Callback Registration (atexit-style) |  | — | docs/20-math-utilities.md |
| FUN_005997d5 | Callback Registration (atexit-style) |  | — | docs/01-engine-architecture.md |
| FUN_0059a8d8 | Callback Chain Iteration |  | — | docs/01-engine-architecture.md |
| FUN_0058a5f7 | N-Time Callback Loop with SEH |  | — | docs/01-engine-architecture.md |
| FUN_004b3d50 | Callback Registration |  | — | docs/20-math-utilities.md |
| FUN_005568d0 | Callback Registration |  | — | docs/01-engine-architecture.md |
| FUN_0057aa20 | Callback Registration |  | — | docs/01-engine-architecture.md |
| FUN_0059982f | Callback Registration |  | — | docs/01-engine-architecture.md |
| FUN_0059b086 | Callback Registration |  | — | docs/20-math-utilities.md |
| FUN_0058a677 | N-Time Callback Loop with SEH |  | — | docs/20-math-utilities.md |
| FUN_0058a6eb | N-Time Callback Loop with SEH |  | — | docs/20-math-utilities.md |
| FUN_0058a755 | Conditional Callback with SEH |  | — | docs/20-math-utilities.md |
| FUN_00593db8 | Global Callback Dispatcher with Null Check |  | DAT_008d41b4 | docs/20-math-utilities.md |
| FUN_00408260 | Callback Registration |  | — | docs/20-math-utilities.md |
| FUN_0049afb0 | Callback Registration (atexit) |  | — | docs/20-math-utilities.md |
| FUN_004a11e0 | Callback Registration |  | — | docs/20-math-utilities.md |
| FUN_004d0040 | Callback Registration |  | — | docs/20-math-utilities.md |
| FUN_005987d0 | Callback Registration |  | — | docs/20-math-utilities.md |
| FUN_0040e1d0 | Callback Registration |  | — | docs/09-track-system.md |
| FUN_00494620 | Callback Registration |  | — | docs/01-engine-architecture.md |
| FUN_004b4470 | File Handle + Close Registration |  | — | docs/01-engine-architecture.md |
| FUN_004c3030 | Callback Registration |  | — | docs/20-math-utilities.md |
| FUN_004f8d20 | Callback Registration |  | — | docs/19-renderer.md |
| FUN_00585e20 | Callback Registration |  | — | docs/20-math-utilities.md |

### network (27 entries)
| Address | Name | Key Logic | Globals | Target |
|---------|------|-----------|---------|--------|
| FUN_00410f60 | Command Dispatch with Array Lookup |  | — | docs/21-audio-network-internals.md |
| FUN_00461f90 | Conditional Network/System Dispatch |  | — | docs/08-file-formats.md |
| FUN_00551810 | Conditional Dispatch by Flag |  | — | docs/19-renderer.md |
| FUN_00566cc0 | Conditional Dispatch Based on Flag |  | — | docs/01-engine-architecture.md |
| FUN_0040d240 | Game State Dispatch Chain |  | — | docs/20-math-utilities.md |
| FUN_00478200 | Short Computation / Game Command Dispatch |  | DAT_007cd8c0 | docs/20-math-utilities.md |
| FUN_004a0ad0 | Short Computation / Command Dispatch (0x1b) + Standings |  | DAT_007cd8c0 | docs/01-engine-architecture.md |
| FUN_004df030 | Unidentified Logic / Struct Build + Dispatch |  | — | docs/21-audio-network-internals.md |
| FUN_0058957a | Interrupt Dispatch |  | — | docs/19-renderer.md |
| FUN_0055c7f0 | Key Event Dispatch to Sub-Handlers |  | — | docs/19-renderer.md |
| FUN_0046fe50 | Conditional UI/Subsystem Dispatch |  | DAT_007cd8c0 | docs/01-engine-architecture.md |
| FUN_004ba740 | Guarded Dispatch with State Check |  | DAT_007d005c | docs/01-engine-architecture.md |
| FUN_004db550 | UI Layout Dispatch with Data Prep |  | DAT_007d0474 | docs/17-physics-collision.md |
| FUN_00511457 | State Counter with Dispatch |  | — | docs/20-math-utilities.md |
| FUN_005546a0 | Multi-Field Setter Dispatching to 7 Sub-Setters |  | — | docs/01-engine-architecture.md |
| FUN_00598aa0 | Status Check with Error Dispatch |  | — | docs/20-math-utilities.md |
| FUN_0040c610 | Conditional Mode Dispatch with Global Gate |  | DAT_007cfcc8 | docs/20-math-utilities.md |
| FUN_00556980 | Animation Dispatch with Skip Flag |  | — | docs/01-engine-architecture.md |
| FUN_005596e0 | Function Pointer Dispatch via Linked Traversal |  | — | docs/20-math-utilities.md |
| FUN_00557480 | Flag-Conditional Branch Dispatch |  | — | docs/01-engine-architecture.md |
| FUN_0040e170 | Tick/Update Dispatch |  | — | docs/20-math-utilities.md |
| FUN_005575f0 | Flag Check with Conditional Path Dispatch |  | — | docs/20-math-utilities.md |
| FUN_004627c0 | Network/Entrant Setup with ID Check |  | — | docs/20-math-utilities.md |
| FUN_00491960 | Dual Dispatch with Guard |  | — | docs/01-engine-architecture.md |
| FUN_0050fb3b | State Machine with Dispatch |  | — | docs/01-engine-architecture.md |
| FUN_00511b5c | Conditional Dispatch with Guard |  | — | docs/01-engine-architecture.md |
| FUN_0040d0b0 | Mode-Dispatched Subsystem Call |  | — | docs/01-engine-architecture.md |

### field_accessors (25 entries)
| Address | Name | Key Logic | Globals | Target |
|---------|------|-----------|---------|--------|
| FUN_0059d6ff | Flag Set with Boolean-to-Float Conversion |  | — | docs/20-math-utilities.md |
| FUN_00585860 | Single Field Setter (Returns 1) |  | — | docs/01-engine-architecture.md |
| FUN_0059d948 | Global Flag Setter via Function Call |  | DAT_005c7530 | docs/20-math-utilities.md |
| FUN_0057a570 | Byte Field Setter at Offset +0x5d |  | — | docs/01-engine-architecture.md |
| FUN_004f9160 | Utility Function / Global Index Setter |  | DAT_008afe6c, DAT_008afe68 | docs/17-physics-collision.md |
| FUN_00553fa0 | State Field Set with Chained Init |  | — | docs/21-audio-network-internals.md |
| FUN_00554610 | State Parameter Setter with Virtual Device Notify |  | DAT_008b89a0 | docs/01-engine-architecture.md |
| FUN_0059db09 | Flag/State Setter with 3 Special-Case Values |  | — | docs/20-math-utilities.md |
| FUN_00479ed0 | Call + Flag Set |  | — | docs/01-engine-architecture.md |
| FUN_004d22c0 | Field Setter with Init |  | — | docs/08-file-formats.md |
| FUN_00554660 | Float State Setter with Change Notification |  | — | docs/01-engine-architecture.md |
| FUN_00551440 | Entity Flag Set + Sub-Init Chain |  | — | docs/01-engine-architecture.md |
| FUN_00553050 | Two-Field Setter |  | — | docs/01-engine-architecture.md |
| FUN_0055d410 | UI Property Value Setter |  | — | docs/01-engine-architecture.md |
| FUN_00553630 | Two-Field Setter |  | — | docs/01-engine-architecture.md |
| FUN_0055d530 | State Field Setter with Global Dirty Flag |  | DAT_008b8f28 | docs/01-engine-architecture.md |
| FUN_00587710 | Field Setter at +0x410 |  | — | docs/20-math-utilities.md |
| FUN_0040ad90 | Bounded Index Setter |  | — | docs/19-renderer.md |
| FUN_00452700 | Conditional Field Setter with State |  | — | docs/19-renderer.md |
| FUN_00497d00 | Two-Field Setter |  | — | docs/01-engine-architecture.md |
| FUN_00498e30 | Field Getter (+0x48) |  | — | docs/01-engine-architecture.md |
| FUN_00513b36 | Flag Setter with Guard |  | — | docs/20-math-utilities.md |
| FUN_0057b6c0 | Setter at +0x24 |  | — | docs/01-engine-architecture.md |
| FUN_0055d560 | Field Getter by Index (1/2/3) |  | — | docs/19-renderer.md |
| FUN_0055d590 | Triple-Field Getter |  | — | docs/19-renderer.md |

### state_flags (11 entries)
| Address | Name | Key Logic | Globals | Target |
|---------|------|-----------|---------|--------|
| FUN_00587230 | Counter Increment/Decrement by Flag |  | — | docs/20-math-utilities.md |
| FUN_00462140 | Short Computation / Refresh Flag Clear |  | DAT_007cd2a0 | docs/20-math-utilities.md |
| FUN_00597218 | Lazy-Init Singleton with Flag Guard |  | DAT_008d5a4c | docs/20-math-utilities.md |
| FUN_0053ac70 | Empty Stub with Flag Check | If (param_2 & 4): returns early Otherwise: returns Effective no-op regardless of path **Used by syst | — | docs/01-engine-architecture.md |
| FUN_00585f30 | Handle Close with Flag Check |  | — | docs/20-math-utilities.md |
| FUN_00556930 | Recursive State Traversal with Flag Check |  | DAT_008b8e34 | docs/20-math-utilities.md |
| FUN_00554c30 | State Flag Iteration Across Entries |  | — | docs/01-engine-architecture.md |
| FUN_004a11b0 | Global Flag Clear |  | — | docs/20-math-utilities.md |
| FUN_00560fd0 | State Flag Bit Clear |  | — | docs/01-engine-architecture.md |
| FUN_0054c0b0 | Bit Flag Reader |  | — | docs/19-renderer.md |
| FUN_005921c5 | Lazy-Init Singleton with Flag Guard |  | — | docs/01-engine-architecture.md |

### string_operations (10 entries)
| Address | Name | Key Logic | Globals | Target |
|---------|------|-----------|---------|--------|
| FUN_0059373e | Struct Matching with Bit Flags + strcmp |  | — | docs/01-engine-architecture.md |
| FUN_0056eb30 | Linear Search in Struct Array by String |  | — | docs/01-engine-architecture.md |
| FUN_0058d7f4 | Char-by-Char String Processing with Terminator Check |  | — | docs/01-engine-architecture.md |
| FUN_005905dd | Hex String to Int Parser |  | — | docs/01-engine-architecture.md |
| FUN_005982f8 | Bounded String Length with Cap |  | — | docs/01-engine-architecture.md |
| FUN_00472720 | String Path Resolution with Fallback |  | — | docs/19-renderer.md |
| FUN_004b1ac0 | Multi-Field Setter with Strings |  | — | docs/19-renderer.md |
| FUN_00595524 | String Parse via Delegate |  | — | docs/01-engine-architecture.md |
| FUN_00461ed0 | Directory String Processing with Decode |  | — | docs/01-engine-architecture.md |
| FUN_0059557d | String Parse with Format |  | — | docs/01-engine-architecture.md |

### timing_performance (9 entries)
| Address | Name | Key Logic | Globals | Target |
|---------|------|-----------|---------|--------|
| FUN_00556510 | Performance Counter Timer with Scaling |  | — | docs/01-engine-architecture.md |
| FUN_00568c60 | Timer Reset Using QueryPerformanceCounter |  | — | docs/01-engine-architecture.md |
| FUN_00568d90 | Performance Counter Diff with Scaling |  | — | docs/01-engine-architecture.md |
| FUN_005505a0 | Linked-List Animation Timer Decrement |  | — | docs/20-math-utilities.md |
| FUN_0040c070 | Random State Machine with Timer and Trigger |  | DAT_0059e440 | docs/01-engine-architecture.md |
| FUN_005514c0 | Timer-Based State Update with Cap |  | — | docs/01-engine-architecture.md |
| FUN_00556330 | Timer Accumulate via QueryPerformanceCounter |  | — | docs/19-renderer.md |
| FUN_005563e0 | Timer Start via QueryPerformanceCounter |  | — | docs/01-engine-architecture.md |
| FUN_00556440 | High-Resolution Timer Reset |  | — | docs/19-renderer.md |

### algorithms_sorting_search (8 entries)
| Address | Name | Key Logic | Globals | Target |
|---------|------|-----------|---------|--------|
| FUN_0056ead0 | Linear Search with Large Struct Stride |  | — | docs/01-engine-architecture.md |
| FUN_0040b6c0 | Short Computation / Index Search in Struct Array |  | — | docs/06-session-race-logic.md |
| FUN_005504d0 | Indexed Array Lookup with Bounds Check |  | — | docs/20-math-utilities.md |
| FUN_00454d30 | Parameter Lookup with Fallback |  | — | docs/20-math-utilities.md |
| FUN_004f9240 | Multi-Table Coordinate Search |  | DAT_008afe6c | docs/01-engine-architecture.md |
| FUN_00594b76 | Memory Region Validation & Heap Lookup |  | — | docs/20-math-utilities.md |
| FUN_005684a0 | Object ID Lookup Across 9 Arrays |  | — | docs/20-math-utilities.md |
| FUN_0058af5c | Error ID Lookup Table |  | — | docs/08-file-formats.md |

### rendering_camera (7 entries)
| Address | Name | Key Logic | Globals | Target |
|---------|------|-----------|---------|--------|
| FUN_00466350 | Camera Yaw/Zoom Controller |  | — | docs/21-audio-network-internals.md |
| FUN_00593839 | Multi-Arg Rendering Dispatch with Layout |  | — | docs/20-math-utilities.md |
| FUN_00593bbd | SEH-Wrapped Render Dispatch Call |  | — | docs/20-math-utilities.md |
| FUN_00543440 | Render/Draw Operation with Clipping |  | — | docs/01-engine-architecture.md |
| FUN_00586d00 | Bitmap Range Occupancy Test via Bit Ops |  | — | docs/01-engine-architecture.md |
| FUN_005569f0 | Scene Node State Update with Transform |  | DAT_008b8f24 | docs/20-math-utilities.md |
| FUN_0040f300 | Mode-Dispatched Render/Physics Call |  | — | docs/20-math-utilities.md |

### math_utilities (7 entries)
| Address | Name | Key Logic | Globals | Target |
|---------|------|-----------|---------|--------|
| FUN_00413820 | Cascading Threshold Level Mapper |  | — | docs/19-renderer.md |
| FUN_00583660 | Float Set with Timing Call |  | — | docs/01-engine-architecture.md |
| FUN_0056ec00 | Batch Processing Loop, 3 Passes |  | — | docs/01-engine-architecture.md |
| FUN_00587310 | Binary Packet Field Parser with Offset Math |  | — | docs/20-math-utilities.md |
| FUN_0040e990 | Struct Init with Float Constants and Sub-calls |  | — | docs/20-math-utilities.md |
| FUN_00556900 | Add Float to Animation Channels |  | — | docs/20-math-utilities.md |
| FUN_004b9d20 | Float Comparison with Fallback |  | — | docs/01-engine-architecture.md |

### file_config (7 entries)
| Address | Name | Key Logic | Globals | Target |
|---------|------|-----------|---------|--------|
| FUN_0040c3b0 | Module Asset Path Resolver |  | DAT_008ac48c, DAT_008ac490, DAT_005be880 | docs/18-physics-dynamics.md |
| FUN_0058b59f | GetSystemTimeAsFileTime to 64-bit Tick |  | DAT_008d3ec0 | docs/20-math-utilities.md |
| FUN_004a1b70 | Short Computation / Conditional Path Registry |  | DAT_007ce2e8 | docs/19-renderer.md |
| FUN_0040d980 | Global Data Struct Init with File Paths |  | — | docs/01-engine-architecture.md |
| FUN_005474d0 | Resource/Object Creation with Config |  | — | docs/20-math-utilities.md |
| FUN_00565ef0 | Reverse Path Search for Backslash Separator |  | — | docs/01-engine-architecture.md |
| FUN_00472400 | Virtual Factory + Path Format |  | — | docs/01-engine-architecture.md |

### object_lifecycle (6 entries)
| Address | Name | Key Logic | Globals | Target |
|---------|------|-----------|---------|--------|
| FUN_004715d0 | Short Computation / Object Init with Globals |  | DAT_007ce850, PTR_DAT_005be704, DAT_005c32c8 | docs/01-engine-architecture.md |
| FUN_004733a0 | References Global State / Object Constructor |  | DAT_007d02e4, PTR_DAT_005be704, DAT_005c32c8 | docs/20-math-utilities.md |
| FUN_00560ba0 | Object Init with Parameter Linking |  | — | docs/18-physics-dynamics.md |
| FUN_00599c58 | C++ Constructor with SEH |  | — | docs/20-math-utilities.md |
| FUN_00471a00 | Object Constructor |  | — | docs/01-engine-architecture.md |
| FUN_00473cc0 | Object Constructor |  | — | docs/20-math-utilities.md |

### ui_rendering (6 entries)
| Address | Name | Key Logic | Globals | Target |
|---------|------|-----------|---------|--------|
| FUN_0047a9e0 | Unidentified / UI Object Init |  | — | docs/20-math-utilities.md |
| FUN_004f8ae0 | Dual Source Acquire with Fallback |  | — | docs/01-engine-architecture.md |
| FUN_0055baf0 | Small Struct Init (9 uint32 fields) |  | — | docs/01-engine-architecture.md |
| FUN_00470670 | UI Screen Constructor (Type 1) |  | — | docs/01-engine-architecture.md |
| FUN_00473f50 | UI Screen Constructor (Type 2) |  | — | docs/20-math-utilities.md |
| FUN_0055d4f0 | Set UI Property Group with Chain Update |  | DAT_008b8f28 | docs/01-engine-architecture.md |

### input_handling (2 entries)
| Address | Name | Key Logic | Globals | Target |
|---------|------|-----------|---------|--------|
| FUN_0045f4a0 | Input Command Dispatch to Entities |  | — | docs/19-renderer.md |
| FUN_00585320 | Linked-List Walk with Input Dispatch |  | — | docs/01-engine-architecture.md |

### game_state_machine (2 entries)
| Address | Name | Key Logic | Globals | Target |
|---------|------|-----------|---------|--------|
| FUN_00461440 | References Global State / Session Flag Check |  | DAT_007d1074 | docs/01-engine-architecture.md |
| FUN_0040dcd0 | State Machine Initializer |  | — | docs/20-math-utilities.md |

### handle_management (1 entries)
| Address | Name | Key Logic | Globals | Target |
|---------|------|-----------|---------|--------|
| FUN_00561ed0 | Tick Count Comparison, Handle Inactivity Timeout |  | — | docs/01-engine-architecture.md |