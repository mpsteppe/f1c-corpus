// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DAC30
// Canonical corpus name: SizeOffsetTableByMode
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SizeOffsetTableByMode_004dac30.c

void UnknownObject::SizeOffsetTableByMode()
{
    // Mode-driven table lookup: given a mode selector a1 (1..5, default for anything else) and three output dword pointers a2, a3, a4, fills the outputs with a fixed per-mode size/offset tuple. Returns the first output pointer a2 as an eax convenience value. The switch dispatches through the jump table jpt_4DAC3D.
    // GUARD: Dispatch on mode selector a1 across cases 1, 2, 3, 4, 5 with a default fallback; the compiled switch uses jump table jpt_4DAC3D at 0x004DAD0C. [source:raw, global:0x004DAD0C, abi:lead]
    // ASSIGNMENT: Case 1: set *a2 = 50, *a3 = 590, *a4 = 858. [source:raw]
    // ASSIGNMENT: Case 2: set *a2 = 50, *a3 = 590, *a4 = 898. [source:raw]
    // ASSIGNMENT: Case 3: set *a2 = 640, *a3 = 1230, *a4 = 818. [source:raw]
    // ASSIGNMENT: Case 4: set *a2 = 640, *a3 = 1230, *a4 = 858. [source:raw]
    // ASSIGNMENT: Case 5: set *a2 = 640, *a3 = 1230, *a4 = 898. [source:raw]
    // ASSIGNMENT: Default (unknown mode): set *a2 = 50, *a3 = 590, *a4 = 818. [source:raw]
    // RETURN: Return a2; the sole known caller sub_4DA9E0 receives the first output pointer. [source:raw, function:0x004DAC30, caller:0x004DA9E0]

    // Conservative worker pseudocode:
    //   _DWORD *SizeOffsetTableByMode(int mode, _DWORD *outA, _DWORD *outB, _DWORD *outC) {
    //     switch (mode) {
    //       case 1: *outA = 50; *outB = 590; *outC = 858; break;
    //       case 2: *outA = 50; *outB = 590; *outC = 898; break;
    //       case 3: *outA = 640; *outB = 1230; *outC = 818; break;
    //       case 4: *outA = 640; *outB = 1230; *outC = 858; break;
    //       case 5: *outA = 640; *outB = 1230; *outC = 898; break;
    //       default: *outA = 50; *outB = 590; *outC = 818; break;
    //     }
    //     return outA;
    //   }
    // UNRESOLVED: Meaning of the three output values (e.g. x/y sizes and an offset) is not recoverable from this function alone; the consuming caller sub_4DA9E0 would clarify semantics.
}
