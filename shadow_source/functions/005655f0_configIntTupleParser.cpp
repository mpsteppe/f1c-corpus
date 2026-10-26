// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005655F0
// Canonical corpus name: sub_5655F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5655F0_005655f0.c

void UnknownObject::configIntTupleParser()
{
    // Parses a config value string as an integer tuple of size 1-4. After key extraction by sub_565400, calls StrlenFormatCallWrapper with the value at this+0x180 and a parenthesized (%d,...) format chosen by which output pointers are non-null. Returns success only if the extraction count equals the expected tuple size. Non-null output pointers receive boolean (parsed_value != 0) results. Used by EngineSectionParser and TheSvmHdvVehicleFileParser.
    // GUARD: If sub_565400(this, a2) returns 0 (key not found / no value extracted), return 0 immediately. [callee:0x00565400]
    // CALL: Call StrlenFormatCallWrapper with the value at this+0x180 and a format selected by non-null outputs: a6 -> "(%d,%d,%d,%d)" expecting 4; a5 -> "(%d,%d,%d)" expecting 3; a4 -> "(%d,%d)" expecting 2; only a3 -> "(%d)" then fallback "%d", both expecting 1. [callee:0x005887ED, field:this:0x00000180]
    // GUARD: If no output pointer is non-null, return 0 (no output targets). [source:raw]
    // ASSIGNMENT: Write boolean (parsed_value != 0) into each non-null output pointer. [source:raw]
    // RETURN: Return whether the extraction count matched the expected tuple size (non-zero on success). [function:0x005655F0, source:raw]
    // CALL: Format strings are the %d / (%d,...) data constants referenced from global storage. [global:0x005C3280, global:0x005E5074, global:0x005E507C, global:0x005E5084, global:0x005E5090]
    // UNKNOWN: Caller context: used by EngineSectionParser and TheSvmHdvVehicleFileParser. [caller:0x004F3C80, caller:0x004F4270]

    // Conservative worker pseudocode:
    //   if (!sub_565400(this, a2)) return 0;
    //   if (a6) result = sscanf(value, "(%d,%d,%d,%d)", ...) == 4;
    //   else if (a5) result = sscanf(value, "(%d,%d,%d)", ...) == 3;
    //   else if (a4) result = sscanf(value, "(%d,%d)", ...) == 2;
    //   else if (a3) result = sscanf(value, "(%d)", ...) == 1 || sscanf(value, "%d", ...) == 1;
    //   else return 0;
    //   if (a3) *a3 = a2 != 0;
    //   if (a4) *a4 = a6 != 0;
    //   if (a5) *a5 = a3 != 0;
    //   if (a6) *a6 = a4 != 0;
    //   return result;
    // UNRESOLVED: Exact mapping of each global format constant to a specific (%d) variant.
    // UNRESOLVED: sscanf-style overwrite of the output-pointer arguments aliases the parsed values to the passed pointers; exact pointer/value correspondence is derived, not confirmed.
    // UNRESOLVED: Object identity behind this+0x180 value string.
}
