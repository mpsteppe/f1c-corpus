// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058A947
// Canonical corpus name: NhMalloc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NhMalloc_0058a947.c

void UnknownObject::NhMalloc()
{
    // Memory allocation entry point identified as nh_malloc. Takes a requested size a1 and a retry-flag a2. Rejects requests larger than 0xFFFFFFE0 by returning 0 immediately. Otherwise attempts the low-level allocation sub_58A973(a1); on failure it retries only when the retry flag is set, first invoking GlobalCallbackDispatcherWithNullCheck(a1) as a cleanup callback to free memory before the next attempt. Returns the allocated pointer, or 0 when allocation ultimately fails or the cleanup callback reports failure.
    // GUARD: Size guard: when the requested size a1 exceeds 0xFFFFFFE0, return 0 immediately without attempting an allocation. [source:raw]
    // LOOP: Retry loop: keep attempting allocation while it fails and retries are permitted (retry flag a2 non-zero). [source:raw]
    // CALL: Perform the low-level allocation attempt: result = sub_58A973(a1). [callee:0x0058A973, source:raw]
    // CALL: On a failed allocation with retries enabled, invoke GlobalCallbackDispatcherWithNullCheck(a1) as a cleanup callback to free memory so the next allocation attempt can succeed. [callee:0x00593DB8, source:raw]
    // GUARD: Abort guard: when the cleanup callback returns 0 the allocation is abandoned and the function returns 0. [source:raw]
    // RETURN: Return the allocated pointer from the successful low-level allocation, or 0 when the allocation fails and cannot be retried. [source:raw]
    // CALL: Used as the core allocation entry by OperatorNewNhMallocWrapper and MallocWrapperForNhMalloc. [caller:0x00587C03, caller:0x0058A935, source:raw]

    // Conservative worker pseudocode:
    //   void* NhMalloc(unsigned int size, int retry) {
    //     if (size > 0xFFFFFFE0) return 0;
    //     for (;;) {
    //       void* result = sub_58A973(size);
    //       if (result || !retry) return result;
    //       if (!GlobalCallbackDispatcherWithNullCheck(size)) return 0;
    //     }
    //   }
    // UNRESOLVED: The allocation policy and backing heap of sub_58A973 are not described by this packet.
    // UNRESOLVED: The exact cleanup action performed by GlobalCallbackDispatcherWithNullCheck is defined by the global callback dispatcher, outside this function.
}
