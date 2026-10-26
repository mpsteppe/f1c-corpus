// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046C820
// Canonical corpus name: QOrder0000BmpQualifyingOrderReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QOrder0000BmpQualifyingOrderReset_0046c820.c

void UnknownObject::QualifyingOrderReset()
{
    // Resets the qualifying-order arrays. When the selector byte at this+0x174 is non-zero it copies the qualifying score field (+18580) of every live vehicle (dword_7C54F0, count dword_5C329C) into dword_7CD2B8 and fills the remainder of the 104-slot array with -1. Otherwise it calls sub_497AD0 with the scene object at this+0x40 and off_5C6674, then fills dword_7CD470 (104 dwords) with -1. Every path ends by setting this+0x178 to -1 and returning -1.
    // GUARD: If the byte at this+0x174 is zero, take the scene-object path; if non-zero, take the vehicle-score path. [field:this:0x00000174, source:raw]
    // CALCULATION: Load the vehicle count v2 from dword_5C329C and start the loop counter result at 0. [global:0x005C329C, source:raw]
    // LOOP: For each index result below dword_5C329C, copy the value at dword_7C54F0[result] + 18580 into dword_7CD2B8[result]. [global:0x007C54F0, global:0x007CD2B8, source:raw]
    // GUARD: If result is below 104 after the copy loop, fill dword_7CD2B8[result] through [103] with 0xFF (4 * (104 - result) bytes, i.e. -1 per dword); if result reached 104 no remainder exists and the fill is skipped. [global:0x007CD2B8, source:raw]
    // ASSIGNMENT: Set this+0x178 to -1 at the end of the vehicle-score path. [field:this:0x00000178, source:raw]
    // CALL: Scene-object path: call sub_497AD0 with the object pointer at this+0x40, the function/vtable table off_5C6674, and argument 0. [callee:0x00497AD0, field:this:0x00000040, global:0x005C6674, source:raw]
    // ASSIGNMENT: Scene-object path: fill dword_7CD470 with 0xFF over 0x1A0 bytes (104 dwords of -1). [global:0x007CD470, source:raw]
    // ASSIGNMENT: Scene-object path: set this+0x178 to -1. [field:this:0x00000178, source:raw]
    // RETURN: Return -1 from both paths. [source:raw]

    // Conservative worker pseudocode:
    //   if (this->selectByte /* this+0x174 * /) {
    //     count = dword_5C329C;
    //     for (i = 0; i < count; i++)
    //       dword_7CD2B8[i] = *(dword_7C54F0[i] + 18580);
    //     if (i < 104)
    //       memset(&dword_7CD2B8[i], 0xFF, 4 * (104 - i));
    //   } else {
    //     sub_497AD0(*(this + 0x40), off_5C6674, 0);
    //     memset(&dword_7CD470, 0xFF, 0x1A0);
    //   }
    //   this->field178 = -1;
    //   return -1;
    // UNRESOLVED: The per-vehicle qualifying-score field at +18580 has no vehicle field evidence reference in this packet (only this-base fields are listed), so it is described from the raw source text only.
    // UNRESOLVED: The constant 104 (slot count) matches the vehicle-grid capacity in the skeleton fill but is not independently evidenced here.
    // UNRESOLVED: sub_497AD0's role (scene-object load/create) and the distinction between dword_7CD2B8 and dword_7CD470 are DERIVED from the skeleton fill; owner object type remains unknown.
}
