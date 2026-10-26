// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040E710
// Canonical corpus name: ShortComputation_e710
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_e710_0040e710.c

void UnknownObject::ShortComputation_e710()
{
    // Switch on a mode value read from this+0x1C. For modes 0-5, writes parameter a2 into the destination field of a sub-struct addressed through this+0x20; the default case returns immediately without writing. Return value is the original mode value except on the case 1/4 path where it is a2.
    // CALCULATION: Read the switch dispatch value from this+0x1C (this[7]). [field:this:0x0000001C, source:raw]
    // CALCULATION: Read the destination sub-struct pointer from this+0x20 (this[8]); the written field lies inside that sub-struct. [field:this:0x00000020, source:raw]
    // GUARD: Dispatch on the mode value through the jump table jpt_40E718 at 0x0040E750. Modes 0, 3, 1, 4, 2, 5 select write paths; any other value takes the default path. [field:this:0x0000001C, global:0x0040E750, source:raw]
    // ASSIGNMENT: Write a2 into the destination field of the sub-struct pointed to by this+0x20 (represented in the packet as this+0xF0). Executed for modes 0, 1, 2, 3, 4, 5. [field:this:0x000000F0, field:this:0x00000020, source:raw]
    // RETURN: Return the stored value: the original mode from this+0x1C for modes 0/2/3/5 and the default path, or a2 for modes 1/4. [field:this:0x0000001C, function:0x0040E710, source:raw]

    // Conservative worker pseudocode:
    //   mode = this[7];
    //   switch (mode) {
    //     case 0: case 1: case 2: case 3: case 4: case 5:
    //       this[8]->dest_field = a2;
    //       break;
    //     default:
    //       return mode;
    //   }
    //   return (mode == 1 || mode == 4) ? a2 : mode;
    // UNRESOLVED: Meaning of the mode values 0-5 and why modes 1/4 return a2 instead of the mode value is unknown.
    // UNRESOLVED: Destination sub-struct type, field meaning, and owner class are unidentified.
    // UNRESOLVED: Packet represents the written destination as field this+0xF0 while raw source accesses it via this[8]+208; the structural identity of these two views is assumed, not proven.
}
