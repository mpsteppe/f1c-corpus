// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047AA80
// Canonical corpus name: DestructorWithVTableReset_aa80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorWithVTableReset_aa80_0047aa80.c

void UnknownObject::DestructorWithVTableReset_aa80()
{
    // Scalar-deleting destructor idiom: resets the object vtable pointer to the type vtable off_5A66E0, runs sub_485EB0 (00485EB0) for teardown, then, when the deletion flag a2 bit 0 is set, frees the object memory via FreeWrapper_7bcf (00587BCF). Returns the object pointer. Owner object type is not identified by the packet.
    // ASSIGNMENT: Reset the vtable pointer: store the address of off_5A66E0 into the object's first field (vtable slot at offset 0) [field:this:0x00000000, global:0x005A66E0, source:raw]
    // CALL: Call sub_485EB0 (00485EB0) with this to perform object teardown/cleanup [callee:0x00485EB0, source:raw]
    // GUARD: Test deletion flag: if (a2 & 1) != 0 the object memory is freed; otherwise the destructor returns without freeing [source:raw]
    // CALL: Call FreeWrapper_7bcf (00587BCF) with this to free the object memory block when a2 bit 0 is set [callee:0x00587BCF, source:raw]
    // RETURN: Return the object pointer this [function:0x0047AA80, source:raw]

    // Conservative worker pseudocode:
    //   this->vtable = &off_5A66E0;
    //   sub_485EB0(this);
    //   if ((a2 & 1) != 0) FreeWrapper_7bcf(this);
    //   return this;
    // UNRESOLVED: The object type owning this destructor is not identified; off_5A66E0 is a vtable data address only
    // UNRESOLVED: sub_485EB0 is an unnamed cleanup routine; its object relation and side effects are not documented in the packet
    // UNRESOLVED: The a2 deletion flag follows the MSVC scalar-deleting-destructor convention but the producer call sites are not in the packet, so that role is inference, not packet evidence
}
