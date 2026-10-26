// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054E080
// Canonical corpus name: FlagSetLoop
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FlagSetLoop_0054e080.c

void UnknownObject::FlagSetLoop()
{
    // Calls ValueGetter with the global dword_8B8F28, then, when the element count at this+0x120 is greater than 0, iterates the secondary element array at this+0x124 (36-byte stride). Each element is dereferenced twice (element + 8, then + 4) to reach an object whose flags word at +156 (0x9C) is read; when bit 2 (0x2) is set, bit 1 (0x1) is ORed into the same word. Returns the element count as the function result.
    // CALL: ValueGetter(dword_8B8F28) is invoked at function entry, passing the global UI/context pointer [callee:0x00545F40, global:0x008B8F28, source:raw]
    // GUARD: Loop guard: the element count at this+0x120 must be greater than 0 for the iteration body to run; the count is also the function result [field:this:0x00000120, source:raw]
    // LOOP: Iterate from 0 up to the count at this+0x120 over the secondary element array base at this+0x124 with a 36-byte per-entry stride [field:this:0x00000120, field:this:0x00000124, source:raw]
    // GUARD: For each element, dereference element + 8 then + 4 to reach the target object, and test bit 2 (0x2) in the flags word at +0x9C; the flag write happens only when that bit is set [source:raw]
    // ASSIGNMENT: When bit 0x2 was set, OR bit 1 (0x1) into the same flags word at v5 + 0x9C [source:raw]
    // RETURN: Return the element count read from this+0x120 (the value that also drove the loop) [field:this:0x00000120, source:raw]
    // CALL: Called by VertexBufferTransform (0054c6c0) after vertex transform [caller:0x0054C6C0, source:raw]

    // Conservative worker pseudocode:
    //   ValueGetter(dword_8B8F28);
    //   int result = this->count_0x120;
    //   if (result > 0) {
    //       for (int i = 0; i < result; ++i) {
    //           int obj = *(_DWORD*)(*(_DWORD*)((char*)this->array_0x124 + i * 36 + 8) + 4);
    //           int flags = *(_DWORD*)(obj + 0x9C);
    //           if ((flags & 0x2) != 0)
    //               *(_DWORD*)(obj + 0x9C) = flags | 0x1;
    //       }
    //   }
    //   return result;
    // UNRESOLVED: The intermediate pointer arithmetic (element entry + 8, then its + 4 pointer) is described only through source:raw; no packet field evidence refs exist for those sub-offsets, so the element-entry layout is not established
    // UNRESOLVED: The purpose of the ValueGetter(dword_8B8F28) call at entry is unknown: its return value is not used by the code shown in the packet
    // UNRESOLVED: The semantics of flag bits 0x2 and 0x1 in the per-object flags word at +0x9C, and why bit 0x1 is propagated onto objects that already carry bit 0x2, are unknown
    // UNRESOLVED: The owning object type and the class of the target objects reached through the element array are not identified
}
