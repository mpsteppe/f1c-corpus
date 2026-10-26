// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00407E40
// Canonical corpus name: ResourceNodeLookupByStringOrID
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResourceNodeLookupByStringOrID_00407e40.c

void UnknownObject::ResourceNodeLookupByStringOrID()
{
    // Looks up a resource node in a linked list owned by this, in one of two modes selected by a3: when a3 != -1 it matches the node's integer ID field, and when a3 == -1 it matches the node's string name against a2 using sub_588410 (a string compare that returns 0 on a match). The list head is this[14] (offset 0x38); the traversal cursor this[16] (offset 0x40) is reset to the head on entry and advanced through each node's +4 next pointer per iteration. Returns the data pointer of the matching node, or 0 when the list is empty, the key is absent, or the list is exhausted.
    // GUARD: Dual-mode dispatch on a3: when a3 != -1 the function matches on the integer ID; when a3 == -1 it matches on the string name in a2 (via sub_588410). [abi:lead, source:raw]
    // ASSIGNMENT: ID mode: reset the traversal cursor this[16] = this[14] (list head, offset 0x38); when the head is null return 0 immediately. [field:this:0x00000038, field:this:0x00000040, source:raw]
    // LOOP: ID mode: iterate the list, advancing the cursor through each node's +4 next pointer (this[16] = *(node + 4)), comparing the resource ID at data+16 with a3 and returning the matching data pointer; return 0 when the next pointer is null before a match. [field:*(this+0x40):0x00000010, field:*(this+0x38):0x00000004, field:this:0x00000040, source:raw]
    // RETURN: ID mode: return the data pointer of the matching node, or 0 when the list is empty or the ID is absent. [source:raw]
    // ASSIGNMENT: String mode: when a2 is non-null, reset the cursor this[16] = this[14] (list head); return 0 when the list is empty. [field:this:0x00000038, field:this:0x00000040, source:raw]
    // LOOP: String mode: read the node's name string at data+4 (using the byte_5EA438 default string when the name pointer is null), call sub_588410(name, a2), and stop on a 0 return (match); otherwise advance the cursor through node->next and return 0 on exhaustion. [field:*(this+0x38):0x00000004, global:0x005EA438, callee:0x00588410, field:this:0x00000040, source:raw]
    // RETURN: String mode: return the data pointer of the matching node, or 0 when a2 is null, the list is empty, or the name is absent. [source:raw]

    // Conservative worker pseudocode:
    //   if (a3 != -1) {
    //       this[16] = this[14];
    //       if (!this[14]) return 0;
    //       data = *this[14];
    //       while (data && *(DWORD*)(data + 16) != a3) {
    //           if (!this[16]) return 0;
    //           this[16] = *(this[16] + 4);
    //           if (!this[16]) return 0;
    //           data = *this[16];
    //           if (!data) return 0;
    //       }
    //       return data;
    //   }
    //   if (a2) {
    //       this[16] = this[14];
    //       if (!this[14]) return 0;
    //       data = *this[14];
    //       while (data) {
    //           name = *(char**)(data + 4) ? *(char**)(data + 4) : &byte_5EA438;
    //           if (sub_588410(name, a2) == 0) break;
    //           if (!this[16]) return 0;
    //           this[16] = *(this[16] + 4);
    //           if (!this[16]) return 0;
    //           data = *this[16];
    //           if (!data) return 0;
    //       }
    //       return data;
    //   }
    //   return 0;
    // UNRESOLVED: The packet frames the resource-struct accesses with bases *(this+0x38) and *(this+0x40), while the raw source dereferences the list-node data pointer (v4 = *node) and reads the name at data+4 and the ID at data+16; the exact node-vs-data struct layout is not fully reconciled.
    // UNRESOLVED: field:this:0x00000044 (offset 0x44) is recorded by the deterministic facts as read, but no read of this[17] appears in the raw source text; its role (node count per the fill) is unverified.
    // UNRESOLVED: sub_588410 returning 0 on a match is inferred from the loop breaking on a 0 return, consistent with strcmp semantics; the fill asserts this and it is not independently evidenced.
}
