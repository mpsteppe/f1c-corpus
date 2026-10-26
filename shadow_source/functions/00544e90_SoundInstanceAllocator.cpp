// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00544E90
// Canonical corpus name: sub_544E90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_544E90_00544e90.c

void UnknownObject::SoundInstanceAllocator()
{
    // Allocates a 444-byte sound-instance object via OperatorNewNhMallocWrapper, runs ConstructorInit on it, then stores the caller-supplied `this` pointer as the instance's first field and configures it with a name string via SoundInstanceInit. On success writes the instance pointer to the optional out-argument a2 and returns 0; on allocation or construction failure logs the "Error creating vertex" message via sub_53C590 and returns -1.
    // ASSIGNMENT: Allocate a 444-byte object via OperatorNewNhMallocWrapper and hold it in v4. [callee:0x00587C03, source:raw]
    // GUARD: Proceed only if v4 is non-null AND ConstructorInit(v4) returns a non-null initialized instance v5; otherwise take the error path. [callee:0x005418B0, source:raw]
    // ASSIGNMENT: Store the caller-provided `this` pointer as the first field of the new instance: *v5 = this. [function:0x00544E90, source:raw]
    // CALL: Configure the sound instance with the name string a3 via SoundInstanceInit(v5, a3). [callee:0x005418E0, source:raw]
    // GUARD: If the out-argument a2 is non-null, write the created instance into it. [source:raw]
    // ASSIGNMENT: Publish the instance to the caller: *a2 = v5. [source:raw]
    // RETURN: Return 0 to signal success on the construction path. [source:raw]
    // CALL: On allocation or construction failure, report the error via sub_53C590(-1, aErrorCreatingV_0), logging the "Error creating vertex" string. [callee:0x0053C590, global:0x005DBE1C, source:raw]
    // RETURN: Return -1 to signal failure on the error path. [source:raw]

    // Conservative worker pseudocode:
    //   int SoundInstanceAllocator(void* ownerThis, _DWORD* outInstance, const char* name) {
    //     _DWORD* block = OperatorNewNhMallocWrapper(444);
    //     _DWORD* inst = block ? ConstructorInit(block) : 0;
    //     if (inst) {
    //       inst[0] = ownerThis;
    //       SoundInstanceInit((int)inst, name);
    //       if (outInstance) *outInstance = inst;
    //       return 0;
    //     }
    //     sub_53C590(-1, aErrorCreatingV_0);
    //     return -1;
    //   }
    // UNRESOLVED: Type and layout of the allocated sound-instance object are not evidenced by this function alone; the owner object is unknown.
    // UNRESOLVED: Meaning of the first-field `this` back-pointer (creator/owner handle) is inferred from the write only.
    // UNRESOLVED: Semantics of the name string a3 depend on the SoundInstanceInit contract, which is not visible here.
    // UNRESOLVED: The single static caller sub_55A060 (0055a060) is known but its construction context is not part of this evidence.
}
