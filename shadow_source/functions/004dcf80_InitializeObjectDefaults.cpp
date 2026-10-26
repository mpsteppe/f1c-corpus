// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DCF80
// Canonical corpus name: sub_4DCF80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4DCF80_004dcf80.c

void UnknownObject::InitializeObjectDefaults()
{
    // Object initializer: copies the global path buffer byte_5EA438 into the object via StringCopyWithBufferRealloc (0x00566650), resets the two scale fields this+0x30 (this[12]) and this+0x34 (this[13]) to 1065353216 (1.0f), then delegates to ShortComputation_cb70(this) and returns its result. Called by ShortComputation_b360 (0x0045B360).
    // CALL: Copy the global path buffer byte_5EA438 (0x005EA438) with StringCopyWithBufferRealloc (0x00566650) [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Write this[12] (this+0x30) to 1065353216 (1.0f) [field:this:0x00000030, source:raw]
    // ASSIGNMENT: Write this[13] (this+0x34) to 1065353216 (1.0f) [field:this:0x00000034, source:raw]
    // CALL: Delegate to ShortComputation_cb70(this) and pass through its result [source:raw]
    // RETURN: Return the result of ShortComputation_cb70 [source:raw]
    // CALL: Invoked by ShortComputation_b360 (0x0045B360) during object construction [caller:0x0045B360, source:raw]

    // Conservative worker pseudocode:
    //   int InitializeObjectDefaults(_DWORD *this) {
    //     StringCopyWithBufferRealloc(byte_5EA438);
    //     this[12] = 1065353216;
    //     this[13] = 1065353216;
    //     return ShortComputation_cb70(this);
    //   }
    // UNRESOLVED: ShortComputation_cb70 is invoked by the raw source but is not present in the packet callee facts, so its address and behavior cannot be referenced or confirmed here
    // UNRESOLVED: Object type and the purpose of the two scale fields at +0x30/+0x34 depend on the unknown owner class
}
