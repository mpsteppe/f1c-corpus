// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057ABB0
// Canonical corpus name: sub_57ABB0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57ABB0_0057abb0.c

void UnknownObject::NetworkModuleCreateAndRegister()
{
    // Creates a network socket object from 12 parameter DWORDs and an output pointer, validates it, then registers it as the data pointer of a 16-byte node inserted into a global doubly-linked module list. Allocates the socket (4 bytes) and node (16 bytes) through OperatorNewNhMallocWrapper, runs a FieldGetter_5cc0 sub-object vtable call plus EmptyStub_0170, and increments the global pool counter on success. Returns 0 on success, 1 on allocation failure or validation failure.
    // ASSIGNMENT: Zero the caller's output DWORD *a13 and its low byte at function entry. [source:raw]
    // CALL: Allocate 4 bytes for the socket object via OperatorNewNhMallocWrapper. [callee:0x00587C03, source:raw]
    // GUARD: If the 4-byte allocation succeeded, create the socket via NetworkSocketObjectCreate from the parameter block; otherwise leave the socket pointer null. [callee:0x00587C03, callee:0x0057A420, source:raw]
    // GUARD: Abort with return 1 when the status low byte is set or the socket's vtable method at offset 72 returns non-zero. [source:raw]
    // CALL: Retrieve a sub-object via FieldGetter_5cc0(*v15) and invoke its vtable method (offset 0) on the result. [callee:0x00585CC0, source:raw]
    // CALL: Call the no-op EmptyStub_0170. [callee:0x004B0170, source:raw]
    // ASSIGNMENT: Store the created socket pointer into the caller's output *v13 (the zeroed a13). [source:raw]
    // CALL: Allocate 16 bytes for the list node via OperatorNewNhMallocWrapper. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initialize the list node: data=v15, prev=0, next=0, flag byte at +12 = 1. [source:raw]
    // GUARD: Branch on dword_8D3BFC to choose the first-insert path vs. the append path into the global list. [global:0x008D3BFC, source:raw]
    // ASSIGNMENT: Link the new node into the global doubly-linked list, updating head dword_8D3BFC, tail dword_8D3C00 and dword_8D3C04 on first insert, and dword_8D3C00 on every insert. [global:0x008D3BFC, global:0x008D3C00, global:0x008D3C04, source:raw]
    // CALCULATION: Increment the pool allocation counter dword_8D3C08. [global:0x008D3C08, source:raw]
    // RETURN: Return 1 on allocation or validation failure, 0 after successful registration into the global module list. [function:0x0057ABB0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_57ABB0(int p1..p12, _DWORD *out) {
    //     *out = 0;
    //     char ok = 0;
    //     _DWORD *sock = OperatorNewNhMallocWrapper(4);
    //     _DWORD *node;
    //     sock = sock ? NetworkSocketObjectCreate(sock, &p1, &out) : 0;
    //     if (ok || (*(int (__thiscall **)(_DWORD))(*(_DWORD*)sock + 72))(sock)) return 1;
    //     void (__thiscall ***f)() = FieldGetter_5cc0(*sock); (**f)(f);
    //     EmptyStub_0170();
    //     *out = sock;
    //     node = OperatorNewNhMallocWrapper(16);
    //     if (node) { node[0]=sock; node[1]=0; node[2]=0; *(byte*)(node+12)=1; }
    //     if (dword_8D3BFC) { *(dword_8D3C00+4)=node; node[2]=dword_8D3C00; }
    //     else { dword_8D3BFC=node; dword_8D3C04=node; }
    //     dword_8D3C00 = node;
    //     ++dword_8D3C08;
    //     return 0;
    //   }
    // UNRESOLVED: Purpose of the socket vtable method at offset 72 consulted before registration is unknown.
    // UNRESOLVED: Meaning of the status byte in a13 and of the FieldGetter_5cc0 sub-object vtable method at offset 0 is unknown.
    // UNRESOLVED: Relationship to caller StackBufferCopyPredicateCall (0x0057AAF0) is not established.
    // UNRESOLVED: Global 0x0059C79B is SEH exception registration for this function; its exact handler is external.
}
