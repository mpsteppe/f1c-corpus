// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057AB50
// Canonical corpus name: sub_57AB50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57AB50_0057ab50.c

void UnknownObject::ModuleListCleanupUnconditional()
{
    // Traverses the module init list whose head is global dword_8D3BFC. For each node with its flag byte at node+12 set, reads the object pointer at node+0 and, if nonzero, destroys it via VTableDestructorThenNullPointer and frees it through FreeWrapper_7bcf. After the traversal unconditionally resets all four list globals (dword_8D3BFC, dword_8D3C00, dword_8D3C04, dword_8D3C08) to 0. Returns the last FreeWrapper_7bcf result.
    // LOOP: for i = dword_8D3BFC; i nonzero; advance through the linked list of module init nodes [global:0x008D3BFC]
    // ASSIGNMENT: v1 = i (current node); i = *(_DWORD*)(i + 4) (next node pointer at node+4) [source:raw, global:0x008D3BFC]
    // GUARD: if node flag byte at offset 12 (v1[12]) is nonzero [source:raw]
    // ASSIGNMENT: v2 = *(void**)v1; capture object pointer stored at node+0 [source:raw]
    // GUARD: if the object pointer at node+0 is nonzero [source:raw]
    // CALL: VTableDestructorThenNullPointer(*(_DWORD**)v1); destroy the object via its vtable destructor and null the pointer [callee:0x0057A4C0]
    // CALL: FreeWrapper_7bcf(v2); free the object block (also the for-loop post-expression) [callee:0x00587BCF]
    // ASSIGNMENT: dword_8D3BFC = 0; reset module init list head [global:0x008D3BFC]
    // ASSIGNMENT: dword_8D3C00 = 0; reset list tail/counter global [global:0x008D3C00]
    // ASSIGNMENT: dword_8D3C04 = 0; reset list/counter global [global:0x008D3C04]
    // ASSIGNMENT: dword_8D3C08 = 0; reset list/counter global [global:0x008D3C08]
    // RETURN: return result; value of the last FreeWrapper_7bcf call from the loop post-expression [callee:0x00587BCF]

    // Conservative worker pseudocode:
    //   for (node = dword_8D3BFC; node != 0; result = FreeWrapper_7bcf(node)) {
    //       next = *(_DWORD*)(node + 4);
    //       if (*(_BYTE*)(node + 12)) {
    //           obj = *(void**)node;
    //           if (obj) {
    //               VTableDestructorThenNullPointer(obj);
    //               FreeWrapper_7bcf(obj);
    //           }
    //       }
    //       node = next;
    //   }
    //   dword_8D3BFC = 0; dword_8D3C00 = 0; dword_8D3C04 = 0; dword_8D3C08 = 0;
    //   return result;
    // UNRESOLVED: Node structure (next at +4, flag at +12, object pointer at +0) is inferred from raw dereferences; the node type is unnamed
    // UNRESOLVED: The returned result is the last FreeWrapper_7bcf return value and is uninitialized when the list head is null; the caller's use of it is unknown
    // UNRESOLVED: Roles of dword_8D3C00, dword_8D3C04, dword_8D3C08 beyond being reset are unproven
}
