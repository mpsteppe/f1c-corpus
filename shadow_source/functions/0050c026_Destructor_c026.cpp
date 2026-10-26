// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050C026
// Canonical corpus name: Destructor_c026
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Destructor_c026_0050c026.c

void UnknownObject::Destructor_c026()
{
    // Conditional destructor: runs the underlying RenderObjectDestructor_c021 on a2 (a render-object frame), then, if the flag bit (a3 & 1) is set, frees the object memory via FreeWrapper_7bcf(a1), and returns a1.
    // CALL: RenderObjectDestructor_c021(a2) runs the underlying render-object destructor [callee:0x0050C021]
    // GUARD: if (a3 & 1) — conditional free flag decides whether the object memory is released [source:raw]
    // CALL: FreeWrapper_7bcf(a1) frees the object memory when the flag bit is set [callee:0x00587BCF]
    // RETURN: returns a1 (the object pointer), consistent with a delete-style operator returning the operand [abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   RenderObjectDestructor_c021(a2);
    //   if (a3 & 1)
    //       FreeWrapper_7bcf(a1);
    //   return a1;
    // UNRESOLVED: callers are not listed in this packet; the relationship between a1 (freed this-pointer) and a2 (ebp render-object frame) is unresolved
    // UNRESOLVED: __userpurge register-based parameter passing is a decompiler artifact; the canonical prototype is uncertain
}
