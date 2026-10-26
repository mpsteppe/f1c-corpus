// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A0D50
// Canonical corpus name: sub_4A0D50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A0D50_004a0d50.c

void UnknownObject::parseCommandLineOptions()
{
    // Parses an input string (likely command-line or config text) for two known keywords and sets session flags. If the string contains the "altosc" keyword, sets byte_7CE268 to 1. If it contains the "skipoptions" keyword, sets dword_7CE264 to 2. The two checks are independent and both can trigger; the function returns the result of the second keyword check.
    // CALL: Call sub_587C20 with the input string and the "altosc" keyword string constant. [callee:0x00587C20, global:0x005CD040]
    // GUARD: If the first keyword check ("altosc") is non-zero, set byte_7CE268 to 1. [global:0x007CE268, global:0x005CD040]
    // CALL: Call sub_587C20 with the input string and the "skipoptions" keyword string constant. [callee:0x00587C20, global:0x005CD034]
    // GUARD: If the second keyword check ("skipoptions") is non-zero, set dword_7CE264 to 2. [global:0x007CE264, global:0x005CD034]
    // RETURN: Return the result of the "skipoptions" keyword check. [function:0x004A0D50, source:raw]

    // Conservative worker pseudocode:
    //   int parseCommandLineOptions(const char* input) {
    //     if (sub_587C20(input, aAltosc))
    //       byte_7CE268 = 1;
    //     int result = sub_587C20(input, aSkipoptions);
    //     if (result)
    //       dword_7CE264 = 2;
    //     return result;
    //   }
    // UNRESOLVED: Semantics of callee sub_587C20 (assumed substring/keyword match from fill prose, not packet evidence).
    // UNRESOLVED: Meaning of the value 2 written to dword_7CE264 (observed literal only).
    // UNRESOLVED: Meaning of byte_7CE268 boolean (observed literal 1 only).
    // UNRESOLVED: Why the first check's result is discarded while the second check's result is returned.
}
