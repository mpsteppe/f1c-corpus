// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00433B60
// Canonical corpus name: AddVehicleConfigEntryToLinkedList
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AddVehicleConfigEntryToLinkedList_00433b60.c

void UnknownObject::AddVehicleConfigEntryToLinkedList()
{
    // Adds a vehicle-config entry to the config list object (this: head 0x1C, tail 0x20, iterator 0x24, count 0x28). Resolves the settings folder (a3, or via SettingsFolderResolver when null) and the active game filter (v9, string at v9+444), then searches the linked list for an entry whose folder and filter strings match. On a match: returns 1 when the copy flag a4 is clear, otherwise copies the vehicle path a2 and filter string into the matched entry. On no match: allocates a 28-byte entry (SessionConfigDefaultInit + string copies + iteration count), links it through a 12-byte node appended to the list tail, and increments the count. Always finishes by copying a2 once more and writing the list out via ConfigFileParser with the config path buffer byte_7CE498; returns 0 on added/updated, 1 on matched-and-skipped.
    // GUARD: When argument a3 (caller settings folder) is null, resolve the active settings folder through SettingsFolderResolver using dword_7CE5EC when set, else the default application-directory buffer byte_5EA438. [callee:0x004326A0, global:0x007CE5EC, global:0x005EA438]
    // ASSIGNMENT: Store the caller-supplied or resolved settings folder as the working folder string used for all later comparisons and entry copies. [callee:0x004326A0, global:0x007CE5EC]
    // CALL: Compute the iteration count for the session type from global dword_7C56A4 via IterationCountMap; the value is later stored in each newly created entry. [callee:0x00432E50, global:0x007C56A4]
    // CALL: Resolve the active game filter data pointer via ConditionalDispatch_40b0 from dword_7CE64C (fallback byte_5EA438); the filter string is read at v9 + 444. [callee:0x004C40B0, global:0x007CE64C, global:0x005EA438]
    // ASSIGNMENT: Seed the traversal iterator: this+0x24 = this+0x1C (list head). [field:this:0x0000001C, field:this:0x00000024]
    // GUARD: Traversal only runs when the head pointer at this+0x1C and its first entry are both non-null. [field:this:0x0000001C]
    // LOOP: Walk the linked list; for each entry compare the entry folder string (entry[0], fallback byte_5EA438) against the working folder via sub_588410 (case-insensitive comparison, zero means equal). [callee:0x00588410, global:0x005EA438, field:this:0x00000024]
    // GUARD: When the folder matches, the entry filter string (entry[2], fallback byte_5EA438) must also be empty or equal to the active filter at v9 + 444; otherwise the search stops on this entry. [callee:0x00588410, global:0x005EA438]
    // STATE_TRANSITION: Advance the iterator to the next link: this+0x24 = next-pointer stored at (this+0x24)+4. [field:this:0x00000024]
    // RETURN: If a matching entry was found and the copy flag a4 is clear, return 1 without modifying the entry. [source:raw]
    // CALL: Found-entry update: copy the vehicle path a2 and the active filter string (v9+444 fallback byte_5EA438) into the matched entry's string buffers via StringCopyWithBufferRealloc. [callee:0x00566650]
    // CALL: Allocate a 28-byte entry object via OperatorNewNhMallocWrapper. [callee:0x00587C03]
    // ASSIGNMENT: Initialize the new entry defaults: field[0]=0, field[1]=-1, field[2]=0, field[3]=-1, field[5]=0, field[6]=-1. [source:raw]
    // CALL: Run SessionConfigDefaultInit on the new entry to fill its session-config defaults. [callee:0x00432CC0]
    // CALL: Copy the resolved settings folder (v24), the filter string (v18 = v9+444 fallback byte_5EA438), and the vehicle path a2 into the new entry's string buffers via StringCopyWithBufferRealloc. [callee:0x00566650]
    // ASSIGNMENT: Store the iteration count into the new entry's field[4]. [source:raw, callee:0x00432E50]
    // CALL: Allocate a 12-byte link node via OperatorNewNhMallocWrapper. [callee:0x00587C03]
    // ASSIGNMENT: Fill the link node: [0] = new entry pointer, [4] = 0 (next), [8] = 1 (entry-present flag). [source:raw]
    // STATE_TRANSITION: Append the link node to the list: when this+0x1C (head) is set, chain it after the tail at (this+0x20)+4; otherwise set head this+0x1C and iterator this+0x24. Then set tail this+0x20 to the new node and increment the count at this+0x28. [field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028]
    // CALL: Re-copy the vehicle path a2 via StringCopyWithBufferRealloc before writing the config (final buffer refresh). [callee:0x00566650]
    // CALL: Write the whole list out via ConfigFileParser with the config file path buffer byte_7CE498. [callee:0x004330D0, global:0x007CE498]
    // RETURN: Return the status: 0 when the entry was added or updated, 1 when an existing match was found and the copy flag was clear. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_433B60(list *this, const char *vehiclePath, const char *folder, int copyFlag) {
    //     if (!folder) folder = SettingsFolderResolver(dword_7CE5EC ? dword_7CE5EC : byte_5EA438);
    //     int iterCount = IterationCountMap(dword_7C56A4);
    //     filter = ConditionalDispatch_40b0(dword_7CE64C ? dword_7CE64C : byte_5EA438);
    //     this->iterator = this->head;
    //     if (this->head && *(this->head)) {
    //       entry = *this->iterator;
    //       for (;;) {
    //         if (folder_equals(entry->folder) && (entry->filter empty || filter_equals(entry->filter))) break;
    //         if (this->iterator) this->iterator = *(this->iterator + 4);
    //         if (!this->iterator || !*(this->iterator)) goto append;
    //         entry = *(this->iterator);
    //       }
    //       if (!copyFlag) return 1;
    //       StringCopyWithBufferRealloc(vehiclePath);
    //       StringCopyWithBufferRealloc(filter ? filter + 444 : byte_5EA438);
    //     } else {
    //   append:
    //       entry = OperatorNewNhMallocWrapper(28);
    //       if (entry) {
    //         entry[0]=0; entry[1]=-1; entry[2]=0; entry[3]=-1; entry[5]=0; entry[6]=-1;
    //         SessionConfigDefaultInit(entry);
    //         StringCopyWithBufferRealloc(folder);
    //         StringCopyWithBufferRealloc(filter ? filter + 444 : byte_5EA438);
    //         entry[4] = iterCount;
    //         StringCopyWithBufferRealloc(vehiclePath);
    //         node = OperatorNewNhMallocWrapper(12);
    //         if (node) { node[0]=entry; node[4]=0; node[8]=1; } else node = 0;
    //         if (this->head) *(this->tail + 4) = node; else { this->head = node; this->iterator = node; }
    //         this->tail = node;
    //         ++this->count;
    //       }
    //     }
    //     StringCopyWithBufferRealloc(vehiclePath);
    //     ConfigFileParser(this, byte_7CE498);
    //     return status;
    //   }
    // UNRESOLVED: Destination buffer descriptors for every StringCopyWithBufferRealloc call are passed through a hidden this/ECX register that the decompiler does not expose, so the exact entry field each copy targets cannot be confirmed from the packet.
    // UNRESOLVED: The purpose of the final StringCopyWithBufferRealloc(a2) immediately before ConfigFileParser (unconditional) is ambiguous; it may refresh a path buffer used by the config writer.
    // UNRESOLVED: Argument a2 is treated as a vehicle path string; callers pass a path buffer (SettingsCopySetupFileCopy passes a stack buffer, ClearBufferAndInit passes a PathBuilderWithBackslash result), but its exact role as a copy source versus an output/scratch buffer is not fully resolvable from this function alone.
    // UNRESOLVED: The filter string is read at v9 + 444 where v9 comes from ConditionalDispatch_40b0; that field offset is derived from decompiled arithmetic and has no direct packet evidence reference.
    // UNRESOLVED: sub_588410 is characterized as a case-insensitive string comparison (zero means equal) from its call pattern here and its own decompiled source; the equality semantics are inferred, not stated in the packet.
}
