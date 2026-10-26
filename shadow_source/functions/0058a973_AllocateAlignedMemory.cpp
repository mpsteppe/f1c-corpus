// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058A973
// Canonical corpus name: sub_58A973
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58A973_0058a973.c

void UnknownObject::AllocateAlignedMemory()
{
    // Aligned memory allocator wrapper used by NhMalloc. Rounds the requested size up to a 16-byte boundary and dispatches on OS-version code dword_8D4908: code 3 sub-allocates small blocks (size <= dword_8D4900) from a pool via sub_59416F under critical section 9; code 2 pulls 16-byte blocks from a block pool (index size/16, bounded by dword_5E998C) via sub_594C12; any other code or an oversized request falls back to HeapAlloc(hHeap, 0, rounded). Every pool path falls back to HeapAlloc when it returns null.
    // GUARD: If OS-version code dword_8D4908 == 3, take the code-3 sub-allocation path. [global:0x008D4908, source:raw]
    // GUARD: On the code-3 path, sub-allocate only when a1 <= dword_8D4900; larger requests fall through to the shared HeapAlloc fallback. [global:0x008D4900, source:raw]
    // CALL: Enter critical section 9, call sub_59416F(a1) for the pool sub-allocation, then leave critical section 9. [callee:0x0058DFEA, callee:0x0059416F, callee:0x0058E04B, source:raw]
    // GUARD: If the code-3 pool allocation returned non-null, return it immediately; otherwise fall through to the shared HeapAlloc fallback. [source:raw]
    // GUARD: If OS-version code dword_8D4908 != 2, use the shared fallback: round a1 up to a 16-byte multiple and HeapAlloc. [global:0x008D4908, source:raw]
    // CALCULATION: Shared fallback size: base = a1, or 1 when a1 is zero; v4 = (base + 15) with the low nibble cleared to align to 16. [source:raw]
    // CALL: Fallback allocation through the HeapAlloc global (0x0059E1C0) on heap hHeap. [global:0x0059E1C0, global:0x008D4904, source:raw]
    // CALCULATION: Code-2 path: aligned size v2 = a1 rounded up to a 16-byte multiple, or 16 when a1 is zero. [source:raw]
    // GUARD: Code-2 path: if aligned size v2 exceeds the block-pool cap dword_5E998C, bypass the pool and HeapAlloc(hHeap, 0, v2). [global:0x005E998C, source:raw]
    // CALL: Enter critical section 9, call sub_594C12(v2 / 16) to fetch the pool block by index, then leave critical section 9. [callee:0x0058DFEA, callee:0x00594C12, callee:0x0058E04B, source:raw]
    // GUARD: Code-2 path: if the pool returned null, fall back to HeapAlloc(hHeap, 0, v2). [source:raw]
    // RETURN: Return the pool block, or the HeapAlloc result when any pool path failed. [source:raw]

    // Conservative worker pseudocode:
    //   LPVOID AllocateAlignedMemory(unsigned int size) {
    //     if (OSVersionCode == 3) {
    //       if (size <= dword_8D4900) {
    //         EnterCS(9); p = sub_59416F(size); LeaveCS(9);
    //         if (p) return p;
    //       }
    //       goto fallback;
    //     }
    //     if (OSVersionCode != 2) {
    //   fallback:
    //       n = size ? size : 1;
    //       n = (n + 15) & ~0xF;
    //       return HeapAlloc(hHeap, 0, n);
    //     }
    //     n = size ? ((size + 15) & 0xFFFFFFF0) : 16;
    //     if (n > dword_5E998C) return HeapAlloc(hHeap, 0, n);
    //     EnterCS(9); p = sub_594C12(n / 16); LeaveCS(9);
    //     return p ? p : HeapAlloc(hHeap, 0, n);
    //   }
    // UNRESOLVED: Globals ScriptFrameProcessor (0x0058895C) and stru_5B8CD0 (0x005B8CD0) are listed in the packet but do not appear in the raw decompilation; their role here is unknown.
    // UNRESOLVED: TLS-access addresses 0xFF00000000001692 / 0xFF00000000001695 / 0xFF0000000000169B are listed in the packet but do not appear in the raw decompilation; their role here is unknown.
    // UNRESOLVED: dword_8D4908 values 2 and 3 are interpreted as Win2K/WinXP pool modes from surrounding code (DERIVED); only the numeric comparisons are grounded.
    // UNRESOLVED: Pool implementation details of sub_59416F and sub_594C12 are opaque at this level.
}
