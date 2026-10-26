// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049A5A0
// Canonical corpus name: DualConditionalFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualConditionalFree_0049a5a0.c

void UnknownObject::DualConditionalFree()
{
    // Destructor-style helper that conditionally frees two pointer fields of this: first the pointer at offset 0x0C, then the pointer at offset 0x04, each only when non-NULL, via FreeWrapper_7bcf. Returns the result of the last free call that fired, or 0 when neither pointer was set.
    // ASSIGNMENT: Read the pointer field at offset 0x0C into the running result. [field:this:0x0000000C, source:raw]
    // GUARD: Guard: only free the field at offset 0x0C when it is non-NULL. [field:this:0x0000000C, source:raw]
    // CALL: Call FreeWrapper_7bcf on the pointer at offset 0x0C and keep its return value as result. [callee:0x00587BCF, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Read the pointer field at offset 0x04. [field:this:0x00000004, source:raw]
    // GUARD: Guard: only free the field at offset 0x04 when it is non-NULL. [field:this:0x00000004, source:raw]
    // CALL: Call FreeWrapper_7bcf on the pointer at offset 0x04 and return its result. [callee:0x00587BCF, field:this:0x00000004, source:raw]
    // RETURN: Return the result of the last free call, or the earlier result / 0 when neither field was set. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_49A5A0(this) {
    //     int result = *(int*)(this + 0x0C);
    //     if (result) result = FreeWrapper_7bcf(*(void**)(this + 0x0C));
    //     void* v3 = *(void**)(this + 0x04);
    //     if (v3) return FreeWrapper_7bcf(v3);
    //     return result;
    //   }
    // UNRESOLVED: Object type owning the two freed pointer fields is unknown.
    // UNRESOLVED: Whether offsets 0x04 and 0x0C are sibling members of one object or separate allocations is not proven here.
}
