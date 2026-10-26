// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B9FB0
// Canonical corpus name: ArithmeticComparison_9fb0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_9fb0_004b9fb0.c

void UnknownObject::VehicleTypeRangeValidator()
{
    // __thiscall validator: defaults to passing (returns 1). When the type identifier at this[0] equals 2, retrieves a vehicle data value via VehicleDataAccessor(this + 2) and returns 0 (fail) if that value is below 6 or above 8; otherwise returns 1.
    // ASSIGNMENT: Seed result to 1 (default pass). [source:raw]
    // GUARD: Guard on this[0] == 2 (vehicle type identifier); when it is not 2 the function returns 1 without checking. [guard:0, field:this:0x00000000, source:raw]
    // CALL: Retrieve the vehicle data value via VehicleDataAccessor(this + 2). [callee:0x004B9E30, source:raw]
    // GUARD: Range check on the accessor result: return 0 when the value is below 6 or above 8. [callee:0x004B9E30, source:raw]
    // RETURN: Return 1 when the type is not 2, or when the accessor value lies within [6, 8]. [source:raw]

    // Conservative worker pseudocode:
    //   bool sub_4B9FB0(DWORD *this) {
    //     bool result = true;
    //     if (*this == 2) {
    //       int v = VehicleDataAccessor(this + 2);
    //       if (v < 6 || v > 8) return false;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantics of type identifier 2 and of the accessor value range [6, 8] are caller-domain and not derivable here.
    // UNRESOLVED: VehicleDataAccessor contract and what this + 2 indexes are unresolved.
    // UNRESOLVED: Legacy ABI label Arithmetic_Comparison_4b9fb0 is not an owner name.
}
