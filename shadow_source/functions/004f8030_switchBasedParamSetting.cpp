// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F8030
// Canonical corpus name: SwitchBasedParamSetting
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SwitchBasedParamSetting_004f8030.c

void UnknownObject::switchBasedParamSetting()
{
    // Switch dispatch on the unsigned value of a1: maps each input case group to a (write to *a2, write to *a3) combination and to one of a1/a2/a3 as the returned pointer. The dispatch uses the jump table jpt_4F803D (0x004F8114). Case group {1,4,7,0x16,0x2B}, {0xA,0x19} and default write (*a2=1, *a3=0) and return a3 or a2 respectively; the remaining case groups write (*a2=0, *a3=0) and return a3, a2, or the unchanged a1 depending on the group. Called from sub_4F70C0 (004F70C0).
    // GUARD: Switch on the unsigned value of a1, dispatched through the jump table jpt_4F803D (0x004F8114); each case group selects a write/return outcome, with the default group handling unmatched values [global:0x004F8114, source:raw]
    // ASSIGNMENT: Write (*a2 = 1, *a3 = 0) for case groups {1,4,7,0x16,0x2B}, {2,5,8,0x17,0x2C}, {0xA,0x19}, {0xB,0x1A} and the default group [source:raw]
    // ASSIGNMENT: Write (*a2 = 0, *a3 = 0) for case groups {0xC,0xF,0x12,0x1B,0x1E,0x21,0x24}, {0xD,0x10,0x13,0x1C,0x1F,0x22,0x25,0x28}, {0xE,0x11,0x1D,0x20,0x23} and {0x14,0x27,0x29} [source:raw]
    // RETURN: Return a3 for case groups {1,4,7,0x16,0x2B}, {0xA,0x19} and {0xD,0x10,0x13,0x1C,0x1F,0x22,0x25,0x28}; return a2 for case group {0xC,0xF,0x12,0x1B,0x1E,0x21,0x24} and the default group; otherwise return the unchanged a1 [source:raw]
    // CALL: Invoked by sub_4F70C0 (004F70C0) to set the two output parameters according to the input selector [caller:0x004F70C0]

    // Conservative worker pseudocode:
    //   dword *switchBasedParamSetting(unsigned a1, dword *a2, dword *a3) {
    //     dword *result = a1;
    //     switch (a1) {
    //       case 1: case 4: case 7: case 0x16: case 0x2B:
    //       case 0xA: case 0x19:
    //         result = a3; *a2 = 1; *a3 = 0; break;
    //       case 2: case 5: case 8: case 0x17: case 0x2C:
    //       case 0xB: case 0x1A:
    //         *a2 = 1; *a3 = 0; break;
    //       case 0xC: case 0xF: case 0x12: case 0x1B: case 0x1E: case 0x21: case 0x24:
    //         result = a2; *a2 = 0; *a3 = 0; break;
    //       case 0xD: case 0x10: case 0x13: case 0x1C: case 0x1F: case 0x22: case 0x25: case 0x28:
    //         result = a3; *a2 = 0; *a3 = 0; break;
    //       case 0xE: case 0x11: case 0x1D: case 0x20: case 0x23:
    //       case 0x14: case 0x27: case 0x29:
    //         *a2 = 0; *a3 = 0; break;
    //       default:
    //         result = a2; *a2 = 1; *a3 = 0; break;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The domain meaning of the selector a1 and of the two boolean outputs *a2/*a3 is unknown; the pattern resembles a mode/index to flag-pair mapping but the concrete semantic is not documented.
    // UNRESOLVED: The jump table jpt_4F803D (0x004F8114) is referenced but the individual case-to-target mapping is not enumerated in the packet.
}
