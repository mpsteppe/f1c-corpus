// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042F1E0
// Canonical corpus name: SetupValueFormat1fS
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SetupValueFormat1fS_0042f1e0.c

void UnknownObject::SetupValueFormat1fS()
{
    // Formats one vehicle setup value into the string buffer at a2 + 30. Computes v3 = (double)*(int*)(a2 + 20) * *(double*)(a2 + 8) + *(double*)a2 from the source structure a2, then selects a format on the flag this[1] (field offset 0x4): non-zero uses the float format on v3 * 0.00571014715506705 (conversion constant global dbl_59EA10), zero uses the integer format on (int)v3. Both branches call StringFormatWithBufferOverflowCheck with the suffix string read from this + 72, writing into a2 + 30, and return its result. Called by SetupValueFormatDispatcher and VehicleSetupValueFormatter.
    // CALCULATION: Compute v3 = (double)*(int*)(a2 + 20) * *(double*)(a2 + 8) + *(double*)a2, combining fields of the source structure a2. [source:raw]
    // GUARD: Branch on the format flag this[1] (field offset 0x4): non-zero selects the float format branch, zero selects the integer format branch. [field:this:0x00000004, source:raw]
    // CALL: Float branch: StringFormatWithBufferOverflowCheck(a2 + 30, "%.1f %s", v3 * 0.00571014715506705, (const char*)(this + 72)), scaling v3 by the conversion constant global dbl_59EA10. [callee:0x0058815F, global:0x0059EA10]
    // CALL: Integer branch: StringFormatWithBufferOverflowCheck(a2 + 30, "%d %s", (int)v3, (const char*)(this + 72)), truncating v3 to int. [callee:0x0058815F]
    // RETURN: Return the result of the selected format call. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_42F1E0(int this, int a2) {
    //     double v3 = (double)*(int*)(a2 + 20) * *(double*)(a2 + 8) + *(double*)a2;
    //     if (*(_DWORD*)(this + 4))
    //       return StringFormatWithBufferOverflowCheck(a2 + 30, "%.1f %s", v3 * 0.00571014715506705, (const char*)(this + 72));
    //     return StringFormatWithBufferOverflowCheck(a2 + 30, "%d %s", (int)v3, (const char*)(this + 72));
    //   }
    // UNRESOLVED: The two format-specifier globals a1fS (0x005C36F4) and aDS (0x005C3778) are read by the two format calls; their exact pairing with the float and integer branches is inferred from global naming (DERIVED).
    // UNRESOLVED: Semantics of the source fields at a2 + 0, a2 + 8 and a2 + 20 (the integer and double components combined into v3) are caller-defined.
    // UNRESOLVED: Meaning of the suffix string at this + 72 and the purpose of the flag at this[1] (offset 0x4) selecting float versus integer display are not stated by the evidence.
}
