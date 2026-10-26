// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585E70
// Canonical corpus name: sub_585E70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_585E70_00585e70.c

void UnknownObject::RefCountDecrementWithCheckWrapper()
{
    // Trivial forwarding function: the entire body delegates to RefCountDecrementWithCheck() and returns its result unchanged. Static extraction records a read of the global at 0x008D3E2C, which is not visible in the raw body and is therefore attributed to the delegated routine. The callee's address is not present in the packet evidence.
    // CALL: Delegate the entire behavior to RefCountDecrementWithCheck(); the callee address is not in the packet callee list. [source:raw]
    // RETURN: Return the delegated routine's result unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   char *sub_585E70() {
    //     return RefCountDecrementWithCheck();
    //   }
    // UNRESOLVED: RefCountDecrementWithCheck is absent from the packet callee list; its address and body are outside this function's evidence.
    // UNRESOLVED: Global read 0x008D3E2C is recorded by static extraction but does not appear in the raw source body; it is likely consumed inside the delegated routine, and its exact role is unresolved here.
}
