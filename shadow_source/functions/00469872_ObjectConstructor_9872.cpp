// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00469872
// Canonical corpus name: ObjectConstructor_9872
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectConstructor_9872_00469872.c

void UnknownObject::ObjectConstructor_9872()
{
    // Unreliable reconstruction: the decompiler reports a stack-pointer imbalance at a call, so the whole body is suspect. As rendered, it performs an indirect call through an uninitialized location, emits a debug trap (icebp), calls sub_4893C0, then writes several field constants through an uninitialized base v1 (including storing vtable pointer off_59F7C8 at v1+0), calls StringCopyWithBufferRealloc(0), and returns v1. The written offsets are relative to a base whose identity is not recoverable from this packet.
    // CALL: Indirect call through a function pointer read from (v1 - 117); v1 is uninitialized, so the target is not recoverable. [source:raw]
    // UNKNOWN: Debug trap instruction (icebp) emitted by the decompiler at this point, consistent with the reported stack-pointer imbalance. [source:raw]
    // CALL: Call sub_4893C0 with no arguments. [callee:0x004893C0, source:raw]
    // ASSIGNMENT: Write dword 0 at (v1 + 384). [source:raw]
    // ASSIGNMENT: Write dword -1 at (v1 + 388). [source:raw]
    // ASSIGNMENT: Store vtable pointer off_59F7C8 at (v1 + 0). [global:0x0059F7C8, source:raw]
    // ASSIGNMENT: Write dword 0 at (v1 + 372). [source:raw]
    // ASSIGNMENT: Write dword 0 at (v1 + 376). [source:raw]
    // ASSIGNMENT: Write byte 1 at (v1 + 380). [source:raw]
    // CALL: Call StringCopyWithBufferRealloc with argument 0. [callee:0x00566650, source:raw]
    // RETURN: Return v1. [source:raw]
    // UNRESOLVED: Reported bad stack-pointer value at a call means the decompiled body may be wrong.
    // UNRESOLVED: Base v1 is uninitialized in the rendered source, so the base object and every field offset (v1+384, v1+388, v1+372, v1+376, v1+380) cannot be grounded.
    // UNRESOLVED: Indirect call target (v1 - 117) is unrecoverable.
    // UNRESOLVED: Meaning of StringCopyWithBufferRealloc(0) and of the constants written (0, -1, 1) is unknown.
    // UNRESOLVED: No caller information is present to contextualize the object type.
}
