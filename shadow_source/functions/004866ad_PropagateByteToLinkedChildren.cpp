// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004866AD
// Canonical corpus name: UIWidgetPropertyPropagator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIWidgetPropertyPropagator_004866ad.c

void UnknownObject::PropagateByteToLinkedChildren()
{
    // __userpurge UI widget value propagator. First calls the virtual function at vtable+44 (cdecl, argument 1), stores byte parameter a1 at this+101, then walks a child-node chain whose head is at this+144. For each node it invokes the virtual at that node's vtable+60 (thiscall, argument a1) and advances via StructFieldAccessor, which yields the next node pointer. Iteration stops when StructFieldAccessor returns 0; the function returns that final result (or the vtable+44 call result when the chain head is null).
    // CALL: Invoke the function pointer at vtable+44 of this with argument 1 (cdecl); store its return value as result. [source:raw]
    // ASSIGNMENT: Store byte parameter a1 at this+101. [source:raw]
    // ASSIGNMENT: Load the head of the child-node chain from this+144 into v4. [source:raw]
    // GUARD: If v4 is null, skip the traversal loop and return the initial result directly. [source:raw]
    // LOOP: do/while traversal: iterate over the node chain while the next-pointer read returns nonzero. [source:raw]
    // CALL: Invoke the virtual function at the current node's vtable+60 (thiscall on v4, argument a1). [source:raw]
    // CALL: Read the next node pointer by calling StructFieldAccessor(v4); assign the result to both result and v4. [callee:0x00486320, source:raw]
    // RETURN: Return result: the final StructFieldAccessor result (0 at normal loop exit), or the vtable+44 call result when the chain was empty. [function:0x004866AD, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4866AD(char a1, int a2, int a3) {
    //     int result = (*(int (__cdecl **)(int))(*(_DWORD *)a2 + 44))(1);
    //     *(_BYTE *)(a2 + 101) = a1;
    //     _DWORD *v4 = *(_DWORD **)(a2 + 144);
    //     if (v4) {
    //       do {
    //         (*(void (__thiscall **)(_DWORD *, char))(*v4 + 60))(v4, a1);
    //         result = StructFieldAccessor(v4);
    //         v4 = (_DWORD *)result;
    //       } while (result);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Purpose of the vtable+44 call with constant argument 1 is unknown; its return value is discarded when the node chain is non-empty.
    // UNRESOLVED: Meaning of the byte value a1 propagated to this+101 and to every child virtual at vtable+60 is not established.
    // UNRESOLVED: Third parameter a3 is present in the signature but unused in the decompiled body.
    // UNRESOLVED: Semantics of the virtual called per node (vtable+60) and of StructFieldAccessor's next-pointer read depend on the unknown owner type.
}
