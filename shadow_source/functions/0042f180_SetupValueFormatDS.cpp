// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042F180
// Canonical corpus name: SetupValueFormatDS
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SetupValueFormatDS_0042f180.c

void UnknownObject::SetupValueFormatDS()
{
    // Formats a scaled setup value as "%d %s" into a caller-supplied buffer. Builds the value as (a2[5]*a2[2] + a2[0]) * 0.001, optionally applies a ~5.710147155067049 degree-conversion factor when the format flag at this+4 equals 1, then calls StringFormatWithBufferOverflowCheck with the value and the unit string at this+56.
    // CALCULATION: Compute scaled value v3 = ((int)(a2+20) * (double)(a2+8) + (double)a2[0]) * 0.001 from the base, multiplier, and index operands. [global:0x0059EA00, global:0x0059EA08, source:raw]
    // GUARD: Guard on format flag at this+4 == 1; only then is the degree-conversion factor applied. [field:this:0x00000004, guard:0]
    // CALCULATION: When the flag passes, multiply v3 by 5.710147155067049 to convert to the degree-based unit. [source:raw]
    // CALL: Format the truncated integer value and the unit string at this+56 into the output buffer a2+30 via StringFormatWithBufferOverflowCheck using the "%d %s" format. [callee:0x0058815F, global:0x005C3778, source:raw]
    // RETURN: Return the result of the StringFormatWithBufferOverflowCheck call. [source:raw]

    // Conservative worker pseudocode:
    //   int SetupValueFormatDS(int this, int a2) {
    //     double v3 = ((double)*(int*)(a2 + 20) * *(double*)(a2 + 8) + *(double*)a2) * 0.001;
    //     if (*(int*)(this + 4) == 1) v3 = v3 * 5.710147155067049;
    //     return StringFormatWithBufferOverflowCheck(a2 + 30, "%d %s", (int)v3, (char*)(this + 56));
    //   }
    // UNRESOLVED: Identity of the receiver object (this) is unknown; the caller SetupValueFormatDispatcher or VehicleSetupValueFormatter supplies it.
    // UNRESOLVED: Meaning of the 5.710147155067049 factor (radian-to-degree ratio or similar) is inferred, not grounded.
    // UNRESOLVED: Purpose of the unit string at this+56 and the exact field layout of the output buffer a2+30 is unknown.
}
