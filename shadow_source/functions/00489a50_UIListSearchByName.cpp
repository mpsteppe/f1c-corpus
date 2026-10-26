// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00489A50
// Canonical corpus name: UIListSearchByName
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIListSearchByName_00489a50.c

void UnknownObject::UIListSearchByName()
{
    // Searches a linked list starting at this offset 0x90 (this[36]). Walks nodes, comparing each node string (at node+176, defaulting to byte_5EA438 when null) against a2 via sub_588410, and returns 1 with the match index written to *a3 on success. Returns 0 on null inputs or when the list is exhausted without a match.
    // GUARD: If a2 is null, or the head v3 = this[36] (this offset 0x90) is null, return 0 immediately. [field:this:0x00000090, source:raw]
    // ASSIGNMENT: v5 = node string at current node + 176; when null, fall back to byte_5EA438. [global:0x005EA438, source:raw]
    // GUARD: When !sub_588410(v5, a2) the node string matches the search name and the loop breaks. [callee:0x00588410, source:raw]
    // ASSIGNMENT: Advance: v3 = next link of the current node (node+140, corresponding to field at base *(this+0x11C) offset 0x8C) and increment the index v4. [field:*(this+0x11C):0x0000008C, source:raw]
    // GUARD: If the list is exhausted (v3 becomes null), return 0 without a match. [source:raw]
    // ASSIGNMENT: On match, write the index v4 into *a3 when a3 is non-null. [source:raw]
    // RETURN: Returns 1 on a match, 0 on a miss or null inputs. [source:raw]

    // Conservative worker pseudocode:
    //   if (!a2 || !head) return 0;
    //   node = head; index = 0;
    //   while (1) {
    //     name = node->string_at_plus_176;
    //     if (!name) name = byte_5EA438;
    //     if (!sub_588410(name, a2)) break;
    //     node = node->next_at_plus_140;
    //     index++;
    //     if (!node) return 0;
    //   }
    //   if (a3) *a3 = index;
    //   return 1;
    // UNRESOLVED: Field this+0x140 is listed in the packet but is not directly referenced by this function's source; role unknown.
    // UNRESOLVED: Semantics of sub_588410 return convention assumed to be 0-on-equal from the negated use in the loop.
}
