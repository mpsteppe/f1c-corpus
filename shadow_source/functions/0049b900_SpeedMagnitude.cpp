// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049B900
// Canonical corpus name: SpeedMagnitude
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SpeedMagnitude_0049b900.c

void UnknownObject::SpeedMagnitude()
{
    // Computes the scalar speed magnitude of the object referenced by dword_7C54E0. Reads three float components at offsets 13560, 13564 and 13568 (0x34F8, 0x34FC, 0x3500, interpreted as velocity components), squares and sums them, takes the square root, multiplies by the conversion constant 3.5999999 (flt_5ACAF4, interpreted as the m/s-to-km/h factor), and returns the result truncated to int. Called by GlobalStateBranchFormat (0x0049D3F0) and UILayoutDispatchWithDataPrep (0x004DB550).
    // CALCULATION: Read three float components at dword_7C54E0 offsets 13560, 13564 and 13568, square each and sum the squares. [global:0x007C54E0, source:raw]
    // CALCULATION: Take the square root of the summed squares to obtain the vector magnitude. [source:raw]
    // CALCULATION: Multiply the magnitude by the 3.5999999 conversion constant held in flt_5ACAF4. [global:0x005ACAF4, source:raw]
    // RETURN: Return the magnitude cast to int. Consumed by GlobalStateBranchFormat (0x0049D3F0) and UILayoutDispatchWithDataPrep (0x004DB550). [caller:0x0049D3F0, caller:0x004DB550, function:0x0049B900]

    // Conservative worker pseudocode:
    //   double sum = sq(*(float *)(veh + 13560)) + sq(*(float *)(veh + 13564)) + sq(*(float *)(veh + 13568));
    //   return (int)(sqrt(sum) * 3.5999999);
    // UNRESOLVED: flt_5ACAF4 appears in packet facts as a read global, but the raw source inlines its value as the literal 3.5999999; the constant-to-global attribution and the m/s-to-km/h interpretation are DERIVED.
    // UNRESOLVED: dword_7C54E0 is a base pointer whose exact object type is not named in the packet; treating offsets 13560/13564/13568 as a velocity vector is DERIVED from the magnitude computation.
}
