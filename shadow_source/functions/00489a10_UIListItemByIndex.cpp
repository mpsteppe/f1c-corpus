// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00489A10
// Canonical corpus name: UIListItemByIndex
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIListItemByIndex_00489a10.c

void UnknownObject::UIListItemByIndex()
{
    // Linked-list item lookup by index: starts from the list head pointer stored at this+0x90, walks next-node links at node+0x8C for a2 steps, then returns the string pointer at node+0xB0 of the target node. Returns null if the index is negative, the head is null, or the chain ends before the index is reached. If the target node's string field is null, returns the byte_5EA438 default instead. The ABI lead names it UI_List_Item_by_Index; the canonical UI corpus calls it UIListItemByIndex.
    // GUARD: Early-out: if a2 is negative, or the head pointer at this+0x90 is null, return null without traversing [field:this:0x00000090, source:raw]
    // LOOP: Walk the list: repeat a2 times advancing from the current node via the next-node link at +0x8C; if the chain ends (null) before the index is exhausted, return null [field:*(this+0x11C):0x0000008C, source:raw]
    // ASSIGNMENT: Read the string/text pointer field at the target node's +0xB0 into result [field:*(this+0x11C):0x000000B0, source:raw]
    // RETURN: If result is null, return the byte_5EA438 default string; otherwise return result. Sole caller is sub_46BA20 (0046BA20); ABI lead and corpus name label it UI_List_Item_by_Index / UIListItemByIndex [global:0x005EA438, caller:0x0046BA20, function:0x00489A10, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   if (index < 0 || this->head == NULL) return NULL;
    //   node = this->head;
    //   while (index-- > 0) {
    //     node = node->next;   // link at +0x8C
    //     if (node == NULL) return NULL;
    //   }
    //   result = node->text;   // string at +0xB0
    //   return (result != NULL) ? result : byte_5EA438;
    // UNRESOLVED: byte_5EA438 is returned as the fallback when the node string is null; its content and role (likely an empty default string) are not established by this packet
}
