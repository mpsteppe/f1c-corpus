// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00491E80
// Canonical corpus name: UtilityFunction_1e80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_1e80_00491e80.c

void UnknownObject::ConditionalFreeAllocation()
{
    // Loads the pointer stored at this+0x0. If it is non-null, treats the stored value as a pointer to the payload of an allocation whose base lies 4 bytes earlier, and hands that base to FreeWrapper_7bcf for release. If the stored pointer is null, returns null without freeing. Used during resource linked-list teardown (caller ResourceLinkedListTeardown 0x00490850); structurally a twin of ConditionalFreeWithBit0Flag (00404f70) per the packet prelabel.
    // ASSIGNMENT: Read the pointer stored at this+0x0 into result. [field:this:0x00000000, source:raw]
    // GUARD: Guard on the stored pointer being non-null; when it is null the free path is skipped and the null pointer is returned unchanged. [field:this:0x00000000, source:raw]
    // CALCULATION: Derive the allocation base by subtracting 4 from the stored pointer (result - 4). [source:raw]
    // CALL: Call FreeWrapper_7bcf with the allocation base (result - 4) to release the wrapped object and return its result. [callee:0x00587BCF, source:raw]
    // RETURN: Return null when the stored pointer at this+0x0 was null. [field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   int ConditionalFreeAllocation(int *this) {
    //     int result = *this;
    //     if (result) return FreeWrapper_7bcf((void *)(result - 4));
    //     return result;
    //   }
    // UNRESOLVED: Object layout: which owner type stores an allocation pointer at this+0x0 with its base 4 bytes earlier is not established by this packet.
    // UNRESOLVED: The prelabel claims a structural twin relationship with ConditionalFreeWithBit0Flag (00404f70), but this function's raw source shows only a null check, not a bit-0 flag check; the relationship is DERIVED and unverified.
    // UNRESOLVED: Relationship to ResourceLinkedListTeardown (0x00490850): the caller is known but the teardown path that reaches this function is not reconstructed here.
}
