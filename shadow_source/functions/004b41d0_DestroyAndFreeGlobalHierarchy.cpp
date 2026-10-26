// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B41D0
// Canonical corpus name: sub_4B41D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B41D0_004b41d0.c

void UnknownObject::DestroyAndFreeGlobalHierarchy()
{
    // Conditional teardown of the object pointed to by global dword_8AB6EC. Captures the pointer, and when it is non-null destroys the UI widget hierarchy rooted at it via DestroyUIWidgetHierarchy and then frees the captured pointer via FreeWrapper_7bcf, returning that free's result. On the null branch the decompiler view returns an uninitialized result.
    // ASSIGNMENT: v0 = dword_8AB6EC; capture the global pointer before the guard. [source:raw]
    // GUARD: if (dword_8AB6EC) — proceed only when the global pointer is non-null. [source:raw]
    // CALL: DestroyUIWidgetHierarchy((int)dword_8AB6EC); destroy the UI widget hierarchy whose root is the global object. [source:raw]
    // CALL: return FreeWrapper_7bcf(v0); free the captured pointer and propagate the free's return value. [source:raw]
    // RETURN: return result; the null branch returns result, which the decompiler shows uninitialized. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4B41D0() {
    //     v0 = dword_8AB6EC;
    //     if (dword_8AB6EC) {
    //       DestroyUIWidgetHierarchy((int)dword_8AB6EC);
    //       return FreeWrapper_7bcf(v0);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The packet's global entry is dword_8AB6E4 (rw=R), but the raw source only touches dword_8AB6EC; dword_8AB6E4 is neither read nor written in this function and appears to be a stale or misaligned packet entry.
    // UNRESOLVED: Along the null branch result is returned uninitialized per the decompiler; the real source likely returned a different value or that branch was unreachable in practice.
    // UNRESOLVED: The exact contracts of DestroyUIWidgetHierarchy and FreeWrapper_7bcf are not described in this packet.
}
