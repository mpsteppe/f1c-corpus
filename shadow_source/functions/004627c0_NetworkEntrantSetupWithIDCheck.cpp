// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004627C0
// Canonical corpus name: NetworkEntrantSetupWithIDCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkEntrantSetupWithIDCheck_004627c0.c

void UnknownObject::NetworkEntrantSetupWithIDCheck()
{
    // Setup routine for a network-style entrant/entry that validates a 128-byte copy and stamps two fields. Queries a COM-style interface object via VTableQueryWithStackBufferResult(*(*(this)+0x3FB8)), invokes its vtable slot 0xC4 (COMVTableCallVia0xc4), copies the caller structure a2 into/through an on-stack 128-byte sentinel buffer (ByteAlignedMemoryCopyFromStruct) and records whether the sentinel survived as the return value. Then writes *(a2+101) = StructFieldReadAt0x3e14(this) - 1 and *(a2+102) = v4[43]; when a3 is non-null it stores the result of the thiscall at (*(_DWORD*)v4 + 24) into *a3. Finally invokes vtable slot 0x7C (VTableCallViaOffset0x7c) on the object with the queried interface, and returns the sentinel-test boolean.
    // CALL: Query the interface object: v4 = VTableQueryWithStackBufferResult(*(DWORD*)(*(DWORD*)this + 0x3FB8)), where *(this) is the object's first member and +0x3FB8 selects the interface handle. [callee:0x0057A880, field:this:0x00000000, field:obj:0x00003FB8, source:raw]
    // CALL: COMVTableCallVia0xc4(v4): invoke the method at vtable slot 0xC4 on the queried interface. [callee:0x0057A8E0, source:raw]
    // ASSIGNMENT: v7 = 128: initialize the on-stack sentinel buffer before the copy. [source:raw]
    // CALL: ByteAlignedMemoryCopyFromStruct(a2, &v7): perform the copy between the caller structure a2 and the on-stack 128-byte buffer. [callee:0x0057A230, source:raw]
    // ASSIGNMENT: v5 = (v7 == 128): record whether the copy left the sentinel dword untouched, i.e. the copied region did not overwrite the first word of the stack buffer. [source:raw]
    // ASSIGNMENT: *(_BYTE*)(a2 + 101) = StructFieldReadAt0x3e14(this) - 1: write a 0-based index derived from the object member read by callee 0x00462370. [callee:0x00462370, source:raw]
    // ASSIGNMENT: *(_BYTE*)(a2 + 102) = v4[43]: copy byte 43 of the queried interface into the output structure. [source:raw]
    // GUARD: If a3 is non-null, store the result of the thiscall invoked through the function pointer at (*(_DWORD*)v4 + 24) into *a3. [source:raw]
    // CALL: VTableCallViaOffset0x7c(*(DWORD*)(*(DWORD*)this + 0x3FB8), v4): invoke vtable slot 0x7C on the object with the queried interface as the argument. [callee:0x0057A8B0, field:this:0x00000000, field:obj:0x00003FB8, source:raw]
    // RETURN: Return v5, the boolean indicating whether the 128-byte sentinel survived the copy. [source:raw]

    // Conservative worker pseudocode:
    //   v4 = VTableQueryWithStackBufferResult(*(*(this) + 0x3FB8));
    //   COMVTableCallVia0xc4(v4);
    //   v7 = 128;
    //   ByteAlignedMemoryCopyFromStruct(a2, &v7);
    //   v5 = (v7 == 128);
    //   *(BYTE*)(a2 + 101) = StructFieldReadAt0x3e14(this) - 1;
    //   *(BYTE*)(a2 + 102) = v4[43];
    //   if (a3) *a3 = (*(thiscall_fn)(*(v4) + 24))(v4);
    //   VTableCallViaOffset0x7c(*(*(this) + 0x3FB8), v4);
    //   return v5;
    // UNRESOLVED: The meaning of the a2 byte fields at +101 and +102 and the returned boolean (sentinel test) depends on the caller contract; no caller-side evidence is in the packet.
    // UNRESOLVED: The prelabel is cluster_copy from the structural twin BufferSendWithLocks (00462760) at DERIVED trust; the network-entrant naming is adopted from the canonical/ABI label but ownership evidence is absent, so owner stays UNKNOWN.
    // UNRESOLVED: The concrete interfaces behind the vtable slots 0xC4 and 0x7C and the +24 thiscall are named only by the wrapper callees and the raw source; their types are not in the packet.
}
