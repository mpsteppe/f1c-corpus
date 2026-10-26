// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049B950
// Canonical corpus name: SpeedMagnitude_b950
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SpeedMagnitude_b950_0049b950.c

void UnknownObject::SpeedMagnitude_b950()
{
    // Computes the scalar speed magnitude of the object referenced by dword_7C54E0. Reads three float components at offsets 13560, 13564 and 13568 (0x34F8, 0x34FC, 0x3500, interpreted as velocity components), squares and sums them, takes the square root, multiplies by the conversion constant 2.2369363 (flt_59F128, interpreted as the m/s-to-mph factor), and returns the result truncated to int. Sibling of SpeedMagnitude; selected by the calling formatter based on an encoding flag. Called by GlobalStateBranchFormat (0x0049D3F0) and UILayoutDispatchWithDataPrep (0x004DB550).
    // CALCULATION: Read three float components at dword_7C54E0 offsets 13560, 13564 and 13568, square each and sum the squares. [global:0x007C54E0, source:raw]
    // CALCULATION: Take the square root of the summed squares to obtain the vector magnitude. [source:raw]
    // CALCULATION: Multiply the magnitude by the 2.2369363 conversion constant held in flt_59F128. [global:0x0059F128, source:raw]
    // RETURN: Return the magnitude cast to int. Consumed by GlobalStateBranchFormat (0x0049D3F0) and UILayoutDispatchWithDataPrep (0x004DB550). [caller:0x0049D3F0, caller:0x004DB550, function:0x0049B950]

    // Conservative worker pseudocode:
    //   double sum = sq(*(float *)(veh + 13560)) + sq(*(float *)(veh + 13564)) + sq(*(float *)(veh + 13568));
    //   return (int)(sqrt(sum) * 2.2369363);
    // UNRESOLVED: flt_59F128 appears in packet facts as a read global, but the raw source inlines its value as the literal 2.2369363; the constant-to-global attribution and the m/s-to-mph interpretation are DERIVED.
    // UNRESOLVED: dword_7C54E0 is a base pointer whose exact object type is not named in the packet; treating offsets 13560/13564/13568 as a velocity vector is DERIVED from the magnitude computation.
}
