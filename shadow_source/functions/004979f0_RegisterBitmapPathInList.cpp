// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004979F0
// Canonical corpus name: BitmapLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitmapLoader_004979f0.c

void UnknownObject::RegisterBitmapPathInList()
{
    // Builds a full bitmap path from a base directory (dword_5EC408, or byte_5EA438 when unset) plus a filename argument a2, validates the path with ConditionalFieldClear, then allocates and appends a 12-byte registry node into a singly-linked list owned by the loader object (head at 0xF0, tail at 0xF4, cursor at 0xF8, count at 0xFC). Returns 0 on path validation failure, 1 on success. Called by sub_4920B0.
    // ASSIGNMENT: Choose base directory: dword_5EC408 if non-null, else byte_5EA438. Format full path into v8 with StringFormatWithBufferOverflowCheck(v8, "%s%s", base, a2); the packet flags 0x005BE860 (aSS) as the read-only format-string storage. [callee:0x0058815F, global:0x005EA438, global:0x005EC408, global:0x005BE860, source:raw]
    // GUARD: If ConditionalFieldClear(v8, &v7) returns non-zero the constructed path is invalid and the function returns 0 immediately. [callee:0x00494FE0, source:raw]
    // ASSIGNMENT: Allocate the PathRegistry object: OperatorNewNhMallocWrapper(12); on success v4 = StructInitPathRegistry(a2, v7), otherwise v4 = 0. [callee:0x00587C03, callee:0x00499AB0, source:raw]
    // GUARD: Only proceed with the list insert when the PathRegistry object v4 was allocated successfully. [source:raw]
    // ASSIGNMENT: Allocate a 12-byte node via OperatorNewNhMallocWrapper(12); on success initialize node+0 = v4 (registry pointer), node+4 = 0 (next), node+8 = 1 (alive flag), else node = 0. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Append node to the singly-linked list: if head at 0xF0 is non-null set old tail's next (*(this[61]+4)) = node; else set head (0xF0) and cursor (0xF8) to node. Set tail (0xF4) = node and increment the count field at 0xFC. [field:this:0x000000F0, field:this:0x000000F4, field:this:0x000000F8, field:this:0x000000FC, source:raw]
    // RETURN: Return 1 on successful registration; return 0 only on the path-validation failure path. [function:0x004979F0, source:raw]
    // CALL: Invoked by sub_4920B0 (004920B0) to register a bitmap path into the loader's list. [caller:0x004920B0, source:raw]

    // Conservative worker pseudocode:
    //   base = dword_5EC408 ? dword_5EC408 : byte_5EA438;
    //   StringFormatWithBufferOverflowCheck(v8, "%s%s", base, a2);
    //   if (ConditionalFieldClear(v8, &v7)) return 0;
    //   v4 = OperatorNewNhMallocWrapper(12) ? StructInitPathRegistry(a2, v7) : 0;
    //   if (v4) {
    //     v5 = OperatorNewNhMallocWrapper(12);
    //     if (v5) { v5[0] = v4; v5[1] = 0; *(v5+8) = 1; } else v5 = 0;
    //     if (this[60]) *(this[61]+4) = v5;
    //     else { this[60] = v5; this[62] = v5; }
    //     this[61] = v5;
    //     ++this[63];
    //   }
    //   return 1;
    // UNRESOLVED: global 0x007CDE00 (unk_7CDE00) is flagged as a read-only reference by packet facts but appears nowhere in the raw decompiled source; the existing analysis labels it Unknown_Render_CDE00 [DERIVED] and its role here is not verifiable from this function alone
    // UNRESOLVED: The 12-byte node layout (registry pointer at +0, next at +4, flag at +8) is inferred from the decompiler's field writes, not from a declared struct
}
