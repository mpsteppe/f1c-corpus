// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00474C80
// Canonical corpus name: SwitchMaps0x1a20x1acToBitmask
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SwitchMaps0x1a20x1acToBitmask_00474c80.c

void UnknownObject::SwitchMaps0x1a20x1acToBitmask()
{
    // Reads an element/track ID from this[199] (offset 0x31C) and switches on it: values 0x1A2..0x1AC each map to a power-of-two bitmask (1 through 1024) written to the output parameter, returning 1; any other value writes -1 to the output and returns 0. Dispatch uses a jump table at 0x00474DA4.
    // GUARD: Switch dispatch reads this[199] at offset 0x31C and compares it against case values 0x1A2 through 0x1AC. [field:this:0x0000031C, source:raw]
    // STATE_TRANSITION: Switch dispatch jumps through the table at 0x00474DA4 (jpt_474C95) to select the matching case handler. [global:0x00474DA4, abi:lead, source:raw]
    // ASSIGNMENT: For a recognized case, write the corresponding bitmask to the output parameter: 0x1A2->1, 0x1A3->2, 0x1A4->4, 0x1A5->8, 0x1A6->16, 0x1A7->32, 0x1A8->64, 0x1A9->128, 0x1AA->256, 0x1AB->512, 0x1AC->1024. [source:raw]
    // RETURN: Return 1 after writing a recognized bitmask. [source:raw]
    // ASSIGNMENT: For an unrecognized ID (default case), write -1 to the output parameter. [source:raw]
    // RETURN: Return 0 when the input ID is not in the recognized range. [source:raw]

    // Conservative worker pseudocode:
    //   char SwitchMaps0x1a20x1acToBitmask(_DWORD *this, _DWORD *out) {
    //     switch (this[199]) {                       // element/track ID, offset 0x31C
    //       case 0x1A2: *out = 1;    return 1;
    //       case 0x1A3: *out = 2;    return 1;
    //       case 0x1A4: *out = 4;    return 1;
    //       case 0x1A5: *out = 8;    return 1;
    //       case 0x1A6: *out = 16;   return 1;
    //       case 0x1A7: *out = 32;   return 1;
    //       case 0x1A8: *out = 64;   return 1;
    //       case 0x1A9: *out = 128;  return 1;
    //       case 0x1AA: *out = 256;  return 1;
    //       case 0x1AB: *out = 512;  return 1;
    //       case 0x1AC: *out = 1024; return 1;
    //       default: *out = -1;      return 0;
    //     }
    //   }
    // UNRESOLVED: Owner object type is unknown; the meaning of the element ID at offset 0x31C and of the produced bitmask depends on the caller.
}
