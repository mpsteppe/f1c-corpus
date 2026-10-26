// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A8D8
// Canonical corpus name: CallbackChainIteration
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CallbackChainIteration_0059a8d8.c

void UnknownObject::CallbackChainIteration()
{
    // Iterates a singly-linked callback list whose head is stored at this+0x1C. For each node, invokes the function pointer at node offset 0x8 as a __cdecl callback with arguments (a2, this, node_userdata), where node_userdata is at node offset 0x4. Advances via the next pointer at node offset 0x0. Returns the result of the last callback executed.
    // ASSIGNMENT: Initialize the loop cursor i from the list head stored at this+0x1C. [field:this:0x0000001C, source:raw]
    // LOOP: for-loop over the singly-linked callback list; continues while the current node pointer is non-null and advances i through the next pointer at node offset 0x0. [field:*(this+0x1C):0x00000000, source:raw]
    // CALL: Invoke the callback function pointer at node offset 0x8 as __cdecl(a2, this, node_userdata), passing the user data at node offset 0x4; store its return value as result. [field:*(this+0x1C):0x00000008, field:*(this+0x1C):0x00000004, source:raw]
    // RETURN: Return the result of the last callback invoked (result of the final list node, or an indeterminate value if the list was empty). [source:raw]
    // CALL: Invoked by sub_59A980 (0x0059A980) to run this callback chain. [caller:0x0059A980, source:raw]

    // Conservative worker pseudocode:
    //   int sub_59A8D8(_DWORD *this, int a2) {
    //     int result;
    //     int **i;
    //     for (i = (int **)this[7]; i; i = (int **)*i)
    //       result = ((int (__cdecl *)(int, _DWORD *, int *))i[2])(a2, this, i[1]);
    //     return result;
    //   }
    // UNRESOLVED: Identity and purpose of the per-node callback (node offset 0x8) is caller-supplied and unknown here.
    // UNRESOLVED: Semantics of node_userdata (node offset 0x4) depend on the callback's contract; the node layout is caller-defined.
}
