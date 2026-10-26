// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00559820
// Canonical corpus name: sub_559820
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_559820_00559820.c

void UnknownObject::ResourceLookupAndBind()
{
    // Looks up an actor/resource by name through the linked list rooted at dword_8B8F2C. On success stores the found node pointer at this+0x220 and the caller value a3 at this+0x21C, returning 0. On failure formats an error message with StringFormatWithBufferOverflowCheck and reports it through sub_53C590, returning -1.
    // GUARD: Branch on the resource list head dword_8B8F2C (0x008B8F2C): non-zero proceeds with the name lookup, zero takes the not-initialized error path. [global:0x008B8F2C, source:raw]
    // CALL: Search the linked list for the name a2 via UTF16StringSearchInLinkedList (0x00559760), storing the result node pointer in v3. [callee:0x00559760, source:raw]
    // GUARD: Branch on the search result v3: non-zero means the actor was found and the bind path is taken. [source:raw]
    // ASSIGNMENT: Store the found node pointer v3 into field this+0x220 (0x220). [field:this:0x00000220, source:raw]
    // ASSIGNMENT: Store the caller value a3 into field this+0x21C (0x21C). [field:this:0x0000021C, source:raw]
    // RETURN: Return 0 on successful lookup and bind. [source:raw]
    // CALL: Format the not-found message into v5 with StringFormatWithBufferOverflowCheck (0x0058815F) using the format string aCouldNotFindAc (0x005DC1F4) and the searched name a2. [callee:0x0058815F, global:0x005DC1F4, source:raw]
    // CALL: Report the formatted error via sub_53C590 (0x0053C590) with code -1 and the message v5. [callee:0x0053C590, source:raw]
    // CALL: On the not-initialized path report the static message aCouldNotFindRe (0x005DC1D8) via sub_53C590 (0x0053C590) with code -1. [callee:0x0053C590, global:0x005DC1D8, source:raw]
    // RETURN: Return -1 when the lookup failed or the resource list was unavailable. [source:raw]
    // CALL: Used by SceneNode (0x0055A910) to bind a named actor/resource into an output object. [caller:0x0055A910, source:raw]

    // Conservative worker pseudocode:
    //   int sub_559820(int a1, const char *a2, int a3) {
    //     if (dword_8B8F2C) {
    //       int v3 = UTF16StringSearchInLinkedList(dword_8B8F2C, a2);
    //       if (v3) {
    //         *(a1 + 0x220) = v3;
    //         *(a1 + 0x21C) = a3;
    //         return 0;
    //       }
    //       char v5[256];
    //       StringFormatWithBufferOverflowCheck(v5, "Could not find actor %s", a2);
    //       sub_53C590(-1, v5);
    //     } else {
    //       sub_53C590(-1, aCouldNotFindRe);
    //     }
    //     return -1;
    //   }
    // UNRESOLVED: The object type of a1 and the semantic meaning of fields 0x21C/0x220 (node pointer and bound value) are not proven.
    // UNRESOLVED: dword_8B8F2C is named only as a list head; its element/string layout is not resolved here.
    // UNRESOLVED: The exact behavior of sub_53C590 (error logging/handling) is external to this function.
}
