// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00407F10
// Canonical corpus name: ResourceIDLookupByNameString
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResourceIDLookupByNameString_00407f10.c

void UnknownObject::ResourceIDLookupByString()
{
    // Searches a linked list of resource data nodes for the first node whose name string matches the input, skipping nodes whose ID at +0x5C is -1 (unregistered), and returns the matching node's integer ID. Returns -1 when the name is null, equals the global default string byte_5EA438, the list is empty, or no node matches.
    // GUARD: A null name argument a2 returns -1 immediately. [source:raw]
    // GUARD: A name equal to the global byte_5EA438 (default application-directory string) short-circuits the lookup and returns -1. [global:0x005EA438]
    // ASSIGNMENT: Reset the traversal cursor: this+0x20 = this+0x18 (list head); a null head returns -1. [field:this:0x00000020, field:this:0x00000018]
    // GUARD: If the node dereferenced from the head pointer is null, return -1. [source:raw]
    // LOOP: Walk the resource node chain. Nodes whose ID at +0x5C equals -1 (guard 0) are skipped; otherwise the node's name is fetched via StringPointerAccessor and compared with sub_588410; a zero result (name match) stops the walk. [guard:0, callee:0x00499E20, callee:0x00588410, field:*(this+0x18):0x0000005C]
    // CALCULATION: Advance the cursor: this+0x20 = next node (*(cursor+4)); when it becomes null the walk ends with -1. [field:this:0x00000020]
    // RETURN: Return the matching node's integer ID at +0x5C, or -1 when no node matches. [field:*(this+0x20):0x0000005C]

    // Conservative worker pseudocode:
    //   // 0x00407F10
    //   if (!name) return -1;
    //   if (!strcmp(name, &byte_5EA438)) return -1;
    //   int head = this[6];
    //   this[8] = head;
    //   if (!head) return -1;
    //   int node = *(int *)head;
    //   if (!node) return -1;
    //   for (;;) {
    //       if (*(int *)(node + 92) != -1) {
    //           char *s = StringPointerAccessor(node);
    //           if (!sub_588410(s, name)) break;
    //       }
    //       int cur = this[8];
    //       if (cur) this[8] = *(int *)(cur + 4);
    //       node = this[8] ? *(int *)this[8] : 0;
    //       if (!node) return -1;
    //   }
    //   return *(int *)(node + 92);
    // UNRESOLVED: this+0x24 (node count) is read per the field facts but is not referenced by the listed pseudocode; its role in this lookup is unclear.
    // UNRESOLVED: The global byte_5EA438 is a default application-directory string; why a name equal to it is rejected with -1 is not established.
    // UNRESOLVED: The -1 return value conflates 'name rejected by global', 'empty list', and 'not found'; callers cannot distinguish these cases.
    // UNRESOLVED: The resource node type (StringPointerAccessor node, ID at +0x5C) is not identified.
}
