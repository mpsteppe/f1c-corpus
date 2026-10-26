// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004780D0
// Canonical corpus name: StateDependentVirtualDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateDependentVirtualDispatch_004780d0.c

void UnknownObject::StateDependentVirtualDispatch()
{
    // Reads the current session state via SessionStateCheck; if state equals 3 (in-game), invokes virtual dispatch through the global object at dword_7CD8C0 with opcode 23, otherwise with opcode 21. If the dispatched call returns a non-zero pointer, caches it in this+0xE0 (this[56]). Always returns 0.
    // CALL: Call SessionStateCheck(dword_7CD25C) to read current session state; result selects the dispatch opcode. [callee:0x00461CD0, global:0x007CD25C]
    // GUARD: Branch on session state: state == 3 selects opcode 23 (in-game path), otherwise opcode 21; both opcodes are dispatched through the object pointed to by dword_7CD8C0. [abi:lead, function:0x004780D0, global:0x007CD8C0, source:raw]
    // CALL: Indirect virtual dispatch: read vtable pointer at dword_7CD8C0 and call slot +28 with arguments (dword_7CD8C0, opcode) where opcode is 23 or 21 depending on the session state guard. [function:0x004780D0, global:0x007CD8C0, source:raw]
    // ASSIGNMENT: If the dispatched call returns non-zero, write the returned reference into this[56] (offset 0xE0); on a null return the field is left unchanged. [field:this:0x000000E0, function:0x004780D0, source:raw]
    // RETURN: Return constant 0 from the function. [function:0x004780D0, source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall StateDependentVirtualDispatch(_DWORD *this)
    //   {
    //     int v2;
    //     if ( SessionStateCheck(dword_7CD25C) == 3 )
    //       v2 = vtable[7](dword_7CD8C0, 23);   // in-game opcode
    //     else
    //       v2 = vtable[7](dword_7CD8C0, 21);   // non-in-game opcode
    //     if ( v2 )
    //       this[56] = v2;   // cache dispatch result at +0xE0
    //     return 0;
    //   }
    // UNRESOLVED: Identity and type of the object behind dword_7CD8C0 (only the indirect vtable slot +28 call is evidenced).
    // UNRESOLVED: Semantic meaning of opcodes 21 and 23 dispatched to that object.
    // UNRESOLVED: Purpose of the cached reference at this+0xE0 and the caller/consumer of the cache.
    // UNRESOLVED: Why the function always returns 0 despite caching a result.
    // UNRESOLVED: Callers of this function are unknown (no static callers in packet); owner object is UnknownObject.
}
