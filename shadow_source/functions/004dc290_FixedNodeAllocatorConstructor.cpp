// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DC290
// Canonical corpus name: FixedNodeAllocator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FixedNodeAllocator_004dc290.c

void UnknownObject::FixedNodeAllocatorConstructor()
{
    // Constructor-like factory for an unknown object. Allocates 16 bytes via OperatorNewNhMallocWrapper (0x00587C03); on allocation failure returns 0. On success initializes the object: first dword becomes the vtable pointer off_5AD11C (0x005AD11C), dword +4 set to 4, byte +8 set to 0, dword +12 set to 0, and returns the pointer. The legacy ABI name Fixed_Node_Allocator suggests a fixed-node allocator node constructor. Called from sub_4D88D0 (0x004D88D0).
    // CALL: Allocate 16 bytes via OperatorNewNhMallocWrapper (0x00587C03); result holds the new allocation pointer or NULL on failure. [callee:0x00587C03]
    // GUARD: If result is NULL, the allocation failed and the function returns 0 without initializing the object. [source:raw]
    // RETURN: Return 0 when the allocation failed. [function:0x004DC290, source:raw]
    // ASSIGNMENT: Store the address of off_5AD11C into the first dword of the new object (byte offset +0), establishing it as the vtable pointer. [global:0x005AD11C, source:raw]
    // ASSIGNMENT: Store 4 into the dword at byte offset +4 of the new object. [source:raw]
    // ASSIGNMENT: Store 0 into the byte at byte offset +8 of the new object. [source:raw]
    // ASSIGNMENT: Store 0 into the dword at byte offset +12 of the new object. [source:raw]
    // RETURN: Return the initialized allocation pointer. [function:0x004DC290, source:raw]

    // Conservative worker pseudocode:
    //   void* FixedNodeAllocatorConstructor(void) {
    //     void* result = OperatorNewNhMallocWrapper(16);
    //     if (!result) return 0;
    //     *(DWORD*)result = &off_5AD11C;
    //     *(DWORD*)((char*)result + 4) = 4;
    //     *(BYTE*)((char*)result + 8) = 0;
    //     *(DWORD*)((char*)result + 12) = 0;
    //     return result;
    //   }
    // UNRESOLVED: The object class is unknown; the packet owner is UnknownObject with no evidence. The legacy ABI name Fixed_Node_Allocator and vtable off_5AD11C suggest a fixed-node allocator node, but class identity is unverified.
    // UNRESOLVED: The meaning of the stored literals (4 at +4, 0 at +8, 0 at +12) is not grounded by this packet.
}
