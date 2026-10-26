// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00560B90
// Canonical corpus name: ConditionalFreeOfField
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalFreeOfField_00560b90.c

void UnknownObject::conditionalFreeOfField()
{
    // Conditional single-field free: loads the pointer stored at this+0x4 (this[1]) and, when it is non-null, releases it through the shared FreeWrapper_7bcf deallocation wrapper and returns the wrapper's result; when the field is null, returns the null field value unchanged. Invoked by MultiFieldObjectDestructorWithCleanupCalls (00560e50) to release a sub-object's field during teardown.
    // ASSIGNMENT: Load the field pointer at this+0x4 (this[1]) into result. [field:this:0x00000004, source:raw]
    // GUARD: If result (the pointer at this+0x4) is non-null, enter the free path. [field:this:0x00000004, source:raw]
    // CALL: Release the allocation pointed to by this+0x4 via FreeWrapper_7bcf. [callee:0x00587BCF, field:this:0x00000004, source:raw]
    // RETURN: Return FreeWrapper_7bcf's result on the non-null path, or the null field pointer on the null path. [source:raw, function:0x00560B90]
    // CALL: Used by MultiFieldObjectDestructorWithCleanupCalls (00560e50) as the third sub-object teardown step. [caller:0x00560E50, source:raw]

    // Conservative worker pseudocode:
    //   LPVOID conditionalFreeOfField(LPVOID* this) {
    //     LPVOID result = this[1];
    //     if (result)
    //       return FreeWrapper_7bcf(this[1]);
    //     return result;
    //   }
    // UNRESOLVED: The type of the allocation at this+0x4 and the owner class are unknown; free semantics are inferred from the shared FreeWrapper_7bcf used across the teardown cluster.
    // UNRESOLVED: FreeWrapper_7bcf's body is not in the packet; its deallocation semantics are inferred from the caller context.
}
