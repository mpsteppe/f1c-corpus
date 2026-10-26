// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585E30
// Canonical corpus name: sub_585E30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_585E30_00585e30.c

void UnknownObject::RefCountDecrementWithCleanupWrapper()
{
    // Trivial forwarding function: the entire body delegates to RefCountDecrementWithCleanup() and returns its result unchanged. Static extraction records a read of the global at 0x008D3E2D, which is not visible in the raw body and is therefore attributed to the delegated routine. The callee's address is not present in the packet evidence.
    // CALL: Delegate the entire behavior to RefCountDecrementWithCleanup(); the callee address is not in the packet callee list. [source:raw]
    // RETURN: Return the delegated routine's result unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_585E30() {
    //     return RefCountDecrementWithCleanup();
    //   }
    // UNRESOLVED: RefCountDecrementWithCleanup is absent from the packet callee list; its address and body are outside this function's evidence.
    // UNRESOLVED: Global read 0x008D3E2D is recorded by static extraction but does not appear in the raw source body; it is likely consumed inside the delegated routine, and its exact role is unresolved here.
}
