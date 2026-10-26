// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F9F70
// Canonical corpus name: GlobalFloatSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalFloatSetter_004f9f70.c

void UnknownObject::GlobalFloatSetter()
{
    // Selects and stores one of three constants into the global double at 0x5D6D70 based on the argument a1: a1==0 stores 1.0, a1==1 stores 30.0, a1==2 stores 0.119999997317791. Any other value leaves the global unchanged. Returns the decremented argument (a1-1, or a1-2 for the a1==2 path) as a side result.
    // ASSIGNMENT: Initialize result to a1 before the branch chain. [source:raw]
    // GUARD: Guard on a1 being zero: store 1.0 into the global double at 0x5D6D70. [global:0x005D6D70, source:raw]
    // GUARD: Guard on a1 being 1: store 30.0 into the global double at 0x5D6D70. [global:0x005D6D70, source:raw]
    // GUARD: Guard on a1 being 2: store 0.119999997317791 into the global double at 0x5D6D70. [global:0x005D6D70, source:raw]
    // RETURN: Return the argument-derived value (a1-1 for a1==1, a1-2 for a1==2, else a1). Called by sub_4A00A0, VidMan_Restart (004FA640) and sub_4FA7E0. [source:raw, caller:0x004A00A0, caller:0x004FA640, caller:0x004FA7E0]

    // Conservative worker pseudocode:
    //   int __stdcall sub_4F9F70(int a1) {
    //     if (a1 == 0) dbl_5D6D70 = 1.0;
    //     else if (a1 == 1) dbl_5D6D70 = 30.0;
    //     else if (a1 == 2) dbl_5D6D70 = 0.119999997317791;
    //     return (a1 == 1) ? a1 - 1 : (a1 == 2) ? a1 - 2 : a1;
    //   }
    // UNRESOLVED: Global flt_5AD268 is flagged read but never appears in the raw decompiled source; its role is unverifiable from this packet.
    // UNRESOLVED: Global byte_5D6D74 is flagged written but never appears in the raw decompiled source; it may overlap the double store at 0x5D6D70 but that is unproven here.
    // UNRESOLVED: Meaning of the three constant values (1.0 / 30.0 / 0.12) for the video-manager callers is not documented.
}
