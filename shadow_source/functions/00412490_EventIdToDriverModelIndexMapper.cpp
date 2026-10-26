// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00412490
// Canonical corpus name: sub_412490
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_412490_00412490.c

void UnknownObject::EventIdToDriverModelIndexMapper()
{
    // Dispatcher-style mapper: given mode a2 (0 or 1), flag a4, and event parameter a3 (1-24), selects one of four switch tables (jpt_4124C4, jpt_4125BB, jpt_4126A4, jpt_4128B8) and computes a mapped value v6 in the 236-387 range. The two a2==0 tables further branch on flag a5 to pick between a high and a low value. On a recognized (a2, a4, a3) combination the mapped value is written to the output buffer at a1+8, the value returned by sub_414180(a2) is written at a1+12, and 1 is returned; any unrecognized input returns -1. The event-to-driver-model-index naming is carried from the packet's existing analysis.
    // ASSIGNMENT: Initialize result to -1 as the failure sentinel before any dispatch. [source:raw]
    // GUARD: Dispatch on a2: only a2 == 1 and a2 == 0 are handled; any other a2 leaves result at -1. [source:raw]
    // GUARD: Within each a2 branch, flag a4 selects one of two switch tables. [source:raw]
    // CALCULATION: a2==1, a4==1: switch table at jpt_4124C4 maps a3 1-24 to values 275-297 and 299; case 8 jumps to the shared 282 label of the sibling table. [global:0x00412AB0]
    // CALCULATION: a2==1, a4==0: switch table at jpt_4125BB maps a3 1-24 to values 282, 298 and 300-322; case 8 is the shared 282 label reached by the sibling table. [global:0x00412B10]
    // CALCULATION: a2==0, a4==1: switch table at jpt_4126A4 maps a3 1-22 to a5-dependent values (340-361 when a5 is set, 294-315 otherwise), a3 23 to 236 and a3 24 to 237. [global:0x00412B70]
    // CALCULATION: a2==0, a4==0: switch table at jpt_4128B8 maps a3 1-22 to a5-dependent values (366-387 when a5 is set, 316-337 otherwise), and a3 23/24 both to 262. [global:0x00412BD0]
    // ASSIGNMENT: Shared success label: write the mapped value v6 to the output buffer at a1+8. [field:this:0x00000008]
    // CALL: Call sub_414180(a2) to compute the secondary value. [callee:0x00414180]
    // ASSIGNMENT: Write the result of sub_414180(a2) to the output buffer at a1+12. [field:this:0x0000000C, callee:0x00414180]
    // STATE_TRANSITION: Set result to 1 to signal a successful mapping. [source:raw]
    // RETURN: Return -1 on an unrecognized a3 (default switch cases) or an out-of-range a2; otherwise return 1. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_412490(int a1, int a2, int a3, char a4, char a5) {
    //     if (a2 != 0 && a2 != 1) return -1;
    //     int v6 = (a2 == 1) ? (a4 ? jpt_4124C4(a3) : jpt_4125BB(a3))
    //                        : (a4 ? jpt_4126A4(a3, a5) : jpt_4128B8(a3, a5));
    //     if (v6 == -1) return -1;
    //     *(int *)(a1 + 8) = v6;
    //     *(int *)(a1 + 12) = sub_414180(a2);
    //     return 1;
    //   }
    // UNRESOLVED: The semantic meaning of the mapped values (236-387) and the a5 branch is carried from the packet's existing analysis as DERIVED prose (driver model indices); it is not confirmed by this packet.
    // UNRESOLVED: Why case 8 of the a2==1/a4==1 table falls through to the shared 282 label inside the sibling switch is a layout artifact of the compiled switch; the intended source structure is unknown.
    // UNRESOLVED: Purpose of the secondary value computed by sub_414180(a2) and written to a1+12 is unknown.
}
