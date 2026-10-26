// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C5FD0
// Canonical corpus name: FilterPropertiesListBuilder_5fd0
// Owner: FilterPropertiesList [DERIVED]
// Raw source: functions/FilterPropertiesListBuilder_5fd0_004c5fd0.c

void FilterPropertiesList::BuildFilterPropertiesList()
{
    // Builds a linked list of filter-property entries on `this`. Iterates the global filter-property table (dword_8AC488 entries, 396-byte stride, property name copied from the aFilterProperti pool at v12 + dword_8AC490 + 260). Skips keys already present via LinkedListKeySearch and entries whose copied name matches no element of the selection array a2 (sub_566810). For each selected entry, allocates a 16-byte node initialized with key v4 and the name via sub_4C5C80, wraps it in a 12-byte list element (element[0] = node, element[4] = next, element[8] = 1), and appends it to the list anchored at this+0x8 (head) / this+0xC (tail), incrementing the count at this+0x14. Returns the number of appended items; 0 when any guard fails.
    // GUARD: Require *a2 non-zero (valid selection array) and a3 > 0 (selection length) before building. [function:0x004C5FD0, source:raw]
    // CALCULATION: Read the global filter-property count dword_8AC488 as the loop bound v13. [global:0x008AC488, source:raw]
    // LOOP: Iterate property index v4 from 0 while v4 < dword_8AC488, advancing the pool offset v12 by 396 bytes each iteration. [global:0x008AC488, source:raw]
    // CALL: Skip the property when LinkedListKeySearch(this, v4) reports key v4 already present in the list. [callee:0x004C4CB0, source:raw]
    // GUARD: Skip the entry when the computed pool offset v12 + dword_8AC490 is zero. [global:0x008AC490, source:raw]
    // ASSIGNMENT: Initialize the local 256-byte name buffer: seed first byte from byte_5EA438, zero the remainder. [global:0x005EA438, source:raw]
    // CALL: Copy the property name from the aFilterProperti string pool at v12 + dword_8AC490 + 260 into the buffer via StringCopyWithValidation; on failure skip the entry. [callee:0x004C58A0, global:0x005D31EC, global:0x008AC490, source:raw]
    // LOOP: Scan the selection array a2 (length a3) for an element that sub_566810 matches against the copied name; skip the entry when no element matches. [callee:0x00566810, source:raw]
    // ASSIGNMENT: Allocate a 16-byte node with OperatorNewNhMallocWrapper and initialize it via sub_4C5C80(node, v4, name_buffer). [callee:0x00587C03, callee:0x004C5C80, source:raw]
    // ASSIGNMENT: Allocate a 12-byte list element: element[0] = node pointer, element[4] = 0 (next), element[8] = 1. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Append the element to this list: when head this+0x8 is null, set head = element and this+0x10 = element; otherwise set tail this+0xC -> next (element offset +4) = element. Always set tail = element and increment the count at this+0x14. [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, source:raw]
    // RETURN: Return the number of appended items (v11); return 0 when any guard fails. [function:0x004C5FD0, source:raw]

    // Conservative worker pseudocode:
    //   if (!*a2 || a3 <= 0) return 0;
    //   for (v4 = 0; v4 < dword_8AC488; ++v4, v12 += 396) {
    //       if (LinkedListKeySearch(this, v4)) continue;
    //       if (v12 + dword_8AC490 == 0) continue;
    //       copy name from aFilterProperti[v12 + dword_8AC490 + 260];
    //       if (no element of a2 matches name) continue;
    //       node = OperatorNewNhMallocWrapper(16);
    //       node = sub_4C5C80(node, v4, name);
    //       elem = OperatorNewNhMallocWrapper(12);
    //       elem[0] = node; elem[4] = 0; elem[8] = 1;
    //       append elem to (head, tail); ++this->count; ++added;
    //   }
    //   return added;
    // UNRESOLVED: Purpose of global unk_8AC368: present in the packet but absent from the decompiled body.
    // UNRESOLVED: Semantics of dword_8AC490 (base offset into the aFilterProperti pool) and of the +260 name field within each 396-byte entry.
    // UNRESOLVED: Role of this+0x10: written only for the first element, alongside the head write at this+0x8.
    // UNRESOLVED: Exact meaning of the element[8] == 1 byte flag and the 4-byte next-field layout of the 12-byte element.
}
