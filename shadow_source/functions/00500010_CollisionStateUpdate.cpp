// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00500010
// Canonical corpus name: CollisionStateUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionStateUpdate_00500010.c

void UnknownObject::CollisionStateUpdate()
{
    // Updates stored collision surface contact state: skips redundant writes when the incoming value lies in the tolerance band [current - 5.0, current], passes FloatComparisonCheck, and carries the same 3-bit contact type; otherwise stores the new value and type and, depending on the 0xFC0000 flag bits of the incoming descriptor, either converts Euler angles to a vehicle orientation (VehicleOrientationFromEulerAngles or sub_4B32A0) or stores comparison data via ArithmeticComparison_3a90.
    // GUARD: Early return 0 when incoming value v13 is within [current - 5.0, current], FloatComparisonCheck(this) passes, and the 3-bit type v7 equals the stored type at this+0x4. [field:this:0x00000000, field:this:0x00000004, callee:0x005001F0, source:raw]
    // ASSIGNMENT: Store incoming collision value v13 to this+0x0 (current contact value). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store the 3-bit contact type v7 (v5 & 7) to this+0x4. [field:this:0x00000004, source:raw]
    // GUARD: Branch on descriptor flag bits (a3 & 0xFC0000) != 0 to select the orientation path versus the arithmetic comparison path. [source:raw]
    // CALL: FloatComparisonCheck(this) decides which orientation routine to run on the flag path. [callee:0x005001F0, source:raw]
    // CALL: VehicleOrientationFromEulerAngles(a3+8, this+2, a3+4) converts Euler angles to a vehicle orientation when the check passes. [callee:0x004B2DD0, source:raw]
    // CALL: sub_4B32A0(a3+8, this+2, a3+4) performs the alternative orientation/state update when the check fails. [callee:0x004B32A0, source:raw]
    // RETURN: Return 1 after the orientation-path update. [source:raw]
    // CALL: ArithmeticComparison_3a90(this+2, a3) stores comparison data on the non-orientation path. [callee:0x004B3A90, source:raw]
    // RETURN: Return 1 after the arithmetic-path update. [source:raw]

    // Conservative worker pseudocode:
    //   char CollisionStateUpdate(float *this, int a2, int a3, int a4) {
    //     float incoming = *(float*)(a3 + 4);
    //     int type_bits = (*(BYTE*)(a3 + 3)) & 7;
    //     if (incoming <= *this && *this - 5.0 <= incoming &&
    //         FloatComparisonCheck(this) && type_bits == *((DWORD*)this + 1)) return 0;
    //     *this = incoming; *((DWORD*)this + 1) = type_bits;
    //     if ((*(DWORD*)a3 & 0xFC0000) != 0) {
    //       if (FloatComparisonCheck(this))
    //         VehicleOrientationFromEulerAngles((char*)(a3 + 8), this + 2, *(int*)(a3 + 4));
    //       else sub_4B32A0((char*)(a3 + 8), this + 2, *(int*)(a3 + 4));
    //       return 1;
    //     }
    //     ArithmeticComparison_3a90((DWORD*)this + 2, (DWORD*)a3);
    //     return 1;
    //   }
    // UNRESOLVED: flt_5AD358 is listed as read but is not referenced directly in the raw body; it is likely consumed inside FloatComparisonCheck (0x005001F0) or an earlier caller.
    // UNRESOLVED: Semantics of the incoming descriptor layout at a3+0, a3+3, a3+4 and the a2/a4 arguments are not grounded by the packet.
}
