// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046D6C0
// Canonical corpus name: VTableSetInitCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableSetInitCall_0046d6c0.c

void UnknownObject::VTableSetInitCall()
{
    // Object init entry: writes the vtable pointer off_59FCB8 into this->vtable at offset 0x0, then delegates to InitWithVTableCleanup(this) for further initialization and returns its result. Called from SubCallConditionalFree.
    // ASSIGNMENT: Store the vtable pointer &off_59FCB8 into this->vtable at offset 0x0. [field:this:0x00000000, global:0x0059FCB8]
    // CALL: Call InitWithVTableCleanup(this) to finish initialization and pass through its result. [source:raw]
    // RETURN: Return the value produced by InitWithVTableCleanup(this). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_46D6C0(void **this) {
    //     *this = &off_59FCB8;
    //     return InitWithVTableCleanup(this);
    //   }
    // UNRESOLVED: InitWithVTableCleanup has no callee record in this packet; its target address is unknown here.
    // UNRESOLVED: Object type owning the off_59FCB8 vtable variant is unknown.
}
