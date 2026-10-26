// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005450E0
// Canonical corpus name: MeshResourceAllocator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MeshResourceAllocator_005450e0.c

void UnknownObject::MeshResourceAllocator()
{
    // Allocates a 572-byte heap block, constructs a mesh-resource object in it, stores a caller-supplied ID at dword index 15, and copies a name string into the object. On success writes the object pointer back through the output argument a1 and returns 0; on string-copy failure runs the object cleanup routine, frees the block, and returns -1.
    // GUARD: If the output pointer a1 is non-null, clear it to zero before any allocation. [field:this:0x00000000, source:raw]
    // CALL: Allocate a 572-byte heap block via OperatorNewNhMallocWrapper. [callee:0x00587C03]
    // GUARD: If the allocation returned non-null, construct the object at the block with sub_54A600; otherwise the object pointer stays null. [callee:0x0054A600, source:raw]
    // CALL: Run the mesh resource constructor sub_54A600 on the freshly allocated block. [callee:0x0054A600]
    // ASSIGNMENT: Store the caller-supplied ID a4 into dword index 15 of the new object. [source:raw]
    // CALL: Copy the name string from a2 into the object via SelfCopyStringWithValidation, with a3 supplying the copy length. [callee:0x0054A730]
    // GUARD: If the string copy failed (non-zero return), tear the object down and return -1. [callee:0x0054A710, callee:0x00587BCF, source:raw]
    // CALL: Run the object cleanup routine TwoFunctionCallChain on the failure path. [callee:0x0054A710]
    // CALL: Free the object's heap block with FreeWrapper_7bcf on the failure path. [callee:0x00587BCF]
    // RETURN: Return -1 on the string-copy failure path. [source:raw]
    // ASSIGNMENT: On success, write the constructed object pointer into *a1 when a1 is non-null. [field:this:0x00000000, source:raw]
    // RETURN: Return 0 on the success path. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_5450E0(_DWORD *out, int name, int name_len, int id) {
    //     if (out) *out = 0;
    //     void *block = OperatorNewNhMallocWrapper(572);
    //     _DWORD *obj = block ? (_DWORD *)sub_54A600(block) : 0;
    //     obj[15] = id;
    //     if (SelfCopyStringWithValidation(obj, name, name_len)) {
    //       TwoFunctionCallChain(obj);
    //       FreeWrapper_7bcf(obj);
    //       return -1;
    //     }
    //     if (out) *out = obj;
    //     return 0;
    //   }
    // UNRESOLVED: Concrete class of the allocated object is not proven here; callers PitCrewMeshLoader and PitCrewAnimationLoader suggest a mesh/animation resource, but the object type is not independently established.
    // UNRESOLVED: Meaning of the stored ID a4 at dword index 15 and of the copy length a3 depend on the caller's resource contract.
    // UNRESOLVED: Semantics of TwoFunctionCallChain and SelfCopyStringWithValidation are taken from existing-analysis labels, not independently verified.
}
