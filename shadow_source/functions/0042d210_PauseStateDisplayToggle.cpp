// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042D210
// Canonical corpus name: sub_42D210
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_42D210_0042d210.c

void UnknownObject::PauseStateDisplayToggle()
{
    // Sets the object's pause-state flag at offset 0x10 to a2. When unpausing (a2 == 0), looks up the "Paused" string in the game string table and, when present, copies it into the message display buffer, then triggers a screen update via ShortComputation_bde0. On the pause branch (a2 nonzero) only the flag is stored.
    // ASSIGNMENT: Store the pause state a2 into the object flag this[16] (offset 0x10); also keep a copy of a2 as the result value. [field:this:0x00000010, source:raw]
    // GUARD: Branch on the unpause path: only when a2 is zero the Paused-string lookup and display update run. [field:this:0x00000010, source:raw]
    // CALL: Call BinarySearchInStringTable(byte_5EC4C0, aPaused, byte_5EC4CC) to look up the Paused string in the game string table. [callee:0x00423A00, global:0x005C35C8, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // GUARD: Proceed with copying only when the string-table lookup for the Paused string succeeds. [global:0x005C35C8, source:raw]
    // LOOP: Copy the aPaused string byte by byte into byte_5EC4CC (message display buffer), including the terminating NUL, until the copied byte is zero. [global:0x005C35C8, global:0x005EC4CC, source:raw]
    // RETURN: Return ShortComputation_bde0(byte_5EC4CC, 0), triggering the screen/text update for the message buffer. [callee:0x0045BDE0, global:0x005EC4CC, source:raw]
    // RETURN: Return a2 (the stored pause state) on the pause branch where no display update is performed. [field:this:0x00000010, source:raw]

    // Conservative worker pseudocode:
    //   result = a2;
    //   this[0x10] = a2;
    //   if (a2 == 0) {
    //       if (BinarySearchInStringTable(byte_5EC4C0, aPaused, byte_5EC4CC)) {
    //           v3 = 0;
    //           do { byte_5EC4CC[v3] = aPaused[v3]; } while (aPaused[v3++] != 0);
    //       }
    //       return ShortComputation_bde0(byte_5EC4CC, 0);
    //   }
    //   return result;
    // UNRESOLVED: Global dword_7CD204 (0x007CD204) is reported as referenced by this function by static facts but does not appear in the raw decompiled text; its role is unknown.
    // UNRESOLVED: Owner object type is unknown; the packet carries no object identity.
    // UNRESOLVED: The name and purpose of the target buffer byte_5EC4CC derive from the existing-analysis fill, not from raw source.
}
