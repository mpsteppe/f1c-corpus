// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00540FC0
// Canonical corpus name: sub_540FC0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_540FC0_00540fc0.c

void UnknownObject::CreateIndexBuffer()
{
    // Creates an index buffer through a virtual call at vtable offset 96 on the sub-object stored at this+0x1100. Derives usage flags from a2[0] bits (0x2/0x10 -> 8, 0x20 -> 0x200) and passes buffer size 2 * a2[1] with format id 101. Stores the call result in *this; returns 0 on success, or -1 (with an error log) on NULL a2 or a failed creation. Called by sub_53EB70, sub_540940 and sub_558310.
    // GUARD: If a2 is NULL, log sub_53C590(-1, aInvalidParamet) and return -1 [callee:0x0053C590, global:0x005DBCD0, source:raw]
    // CALCULATION: Derive usage flags from a2[0] bits: set v3 = 8 when bit 0x2 set, OR 8 when bit 0x10 set, OR 0x200 when bit 0x20 set [source:raw]
    // CALL: Virtual call at offset 96 (vtable[24]) on the sub-object at this+0x1100 with arguments (this[1088], 2 * a2[1], v3, 101, 0, a2 + 6) to create the index buffer [field:*(this+0x1100):0x00000060, field:this:0x00001100, source:raw]
    // ASSIGNMENT: Store the virtual call result v5 into *this [field:this:0x00000000, source:raw]
    // GUARD: If the virtual call result is nonzero, log sub_53C590(-1, aErrorCreatingI) and return -1 [callee:0x0053C590, global:0x005DBD60, source:raw]
    // RETURN: Return 0 on successful buffer creation, -1 on NULL a2 or creation failure [function:0x00540FC0, source:raw]
    // CALL: Invoked by sub_53EB70 (0053EB70), sub_540940 (00540940) and sub_558310 (00558310) to allocate GPU index buffers [caller:0x0053EB70, caller:0x00540940, caller:0x00558310, source:raw]

    // Conservative worker pseudocode:
    //   if (!a2) { sub_53C590(-1, aInvalidParamet); return -1; }
    //   v3 = 0;
    //   if (a2[0] & 2) v3 = 8;
    //   if (a2[0] & 0x10) v3 |= 8;
    //   if (a2[0] & 0x20) v3 |= 0x200;
    //   v5 = vtable_at(this[1088], 96)(this[1088], 2 * a2[1], v3, 101, 0, a2 + 6);
    //   *this = v5;
    //   if (v5) { sub_53C590(-1, aErrorCreatingI); return -1; }
    //   return 0;
    // UNRESOLVED: Exact meaning of the format id 101 and of the trailing argument a2 + 6 is not documented in this function
    // UNRESOLVED: The usage flag constants (8, 0x200) are used verbatim from the source but their symbolic names are not recoverable here
    // UNRESOLVED: The virtual call at vtable offset 96 on the sub-object at this+0x1100 is not resolved to a named device method
}
