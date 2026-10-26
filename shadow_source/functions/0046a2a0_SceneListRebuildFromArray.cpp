// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046A2A0
// Canonical corpus name: sub_46A2A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_46A2A0_0046a2a0.c

void UnknownObject::SceneListRebuildFromArray()
{
    // Rebuilds a scene linked list from a global scene array. Clears the existing list via LinkedListDestructionWithVTableCall, reads the scene count from dword_8AC488, then iterates the scene array at dword_8AC490 (stride 396, scene name string at entry+4). For each entry it copies the name, trims to the last path separator (backslash 92), formats the filename portion with StringFormatWithBufferOverflowCheck using the format table at off_5C6660, loads/creates the scene object via sub_497AD0 (falling back to the string at off_5C665C when the load returns zero), and appends the node with LinkedListNodeAppend.
    // CALL: LinkedListDestructionWithVTableCall clears the existing scene linked list before the rebuild [callee:0x0048D230, source:raw]
    // ASSIGNMENT: Read the scene count from dword_8AC488 into the result register; this global is also the loop bound [global:0x008AC488, source:raw]
    // GUARD: The rebuild loop only runs when the scene count at dword_8AC488 is greater than zero [global:0x008AC488, source:raw]
    // LOOP: Iterate the scene array at dword_8AC490 from offset 0, advancing 396 bytes per entry, for the count read from dword_8AC488 [global:0x008AC490, global:0x008AC488, source:raw]
    // ASSIGNMENT: Copy the scene name string located at the current array position plus 4 into the local path buffer [source:raw]
    // GUARD: Only when the copied string length is greater than zero does the backslash search run [source:raw]
    // CALCULATION: Walk backward from the buffer end to find the last backslash (value 92), zeroing characters in the trim buffer as the terminator search advances [source:raw]
    // CALCULATION: From the end of the scene name, scan backward past the last backslash to isolate the final path component pointer [source:raw]
    // CALL: StringFormatWithBufferOverflowCheck formats the final path component into the trim buffer using the format string table entry off_5C6660 [callee:0x0058815F, global:0x005C6660, source:raw]
    // CALCULATION: Append the formatted component to the copied scene path buffer [source:raw]
    // CALL: sub_497AD0 loads or creates the scene object for the assembled path with a zero flag argument [callee:0x00497AD0, source:raw]
    // GUARD: When the scene load returns zero, retry with the fallback string stored at off_5C665C [global:0x005C665C, source:raw]
    // CALL: LinkedListNodeAppend appends the loaded scene node to the rebuilt list [callee:0x0048D2B0, source:raw]
    // LOOP: Advance the array offset by 396 and decrement the remaining count until it reaches zero [global:0x008AC490, global:0x008AC488, source:raw]
    // RETURN: Return the final loop counter value (zero when the loop ran; the initial count otherwise) [function:0x0046A2A0, source:raw]

    // Conservative worker pseudocode:
    //   LinkedListDestructionWithVTableCall();
    //   result = dword_8AC488;
    //   if (dword_8AC488 > 0) {
    //     offset = 0; remaining = dword_8AC488;
    //     do {
    //       name = (char*)dword_8AC490 + offset + 4;
    //       strcpy(path, name);
    //       if (strlen(path) > 0) {
    //         for (p = &trim[strlen(path) + 15]; p >= path; --p) {
    //           if (*p == 92) break;
    //           *p = 0;
    //         }
    //       }
    //       last = name + strlen(name);
    //       if (last > name) {
    //         while (*last != 92) {
    //           if (--last <= name) goto formatted;
    //         }
    //         ++last;
    //       }
    //     formatted:
    //       StringFormatWithBufferOverflowCheck(trim, off_5C6660[0], last);
    //       strcat(path, trim);
    //       obj = sub_497AD0(path, 0);
    //       if (!obj) obj = sub_497AD0(off_5C665C[0], 0);
    //       LinkedListNodeAppend(obj);
    //       offset += 396;
    //     } while (--remaining);
    //   }
    //   return result;
    // UNRESOLVED: The exact role of the off_5C6660 format table and the off_5C665C fallback string is not defined beyond their use as format source and load fallback
    // UNRESOLVED: sub_497AD0's full load/creation semantics (second zero argument) are not documented in this function
    // UNRESOLVED: The caller that triggers the scene list rebuild is not statically identified in this packet
}
