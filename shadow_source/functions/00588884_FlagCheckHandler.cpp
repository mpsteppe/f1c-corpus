// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00588884
// Canonical corpus name: FlagCheckHandler
// Owner: FlagCheckHandler [DERIVED]
// Raw source: functions/FlagCheckHandler_00588884.c

void FlagCheckHandler::FlagCheckHandler()
{
    // Flag-gated handler: reads the DWORD at this+0x4, tests bitmask 6 (bits 1 and 2); when any of those bits is set, stores a2 into the out-pointer *a4 and returns 3, otherwise returns 1. The prelabel's 'getter, returns field 0x4' summary does not match the raw body, which checks the field but returns 1/3 and writes *a4 instead.
    // CALCULATION: Reads the DWORD at this+0x4 (field:this:0x00000004) and applies bitmask 6 (bits 1 and 2 set). [field:this:0x00000004, source:raw]
    // GUARD: Branches when (*(uint*)(this + 4) & 6) != 0; on that path stores a2 into *a4 and returns 3. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Writes a2 to the DWORD pointed to by the fourth argument a4 (the flag branch only). [source:raw]
    // RETURN: Returns 3 on the flag-set branch; otherwise returns the default value 1. [source:raw, function:0x00588884]

    // Conservative worker pseudocode:
    //   if ((*(uint*)(this + 4) & 6) != 0) {
    //       *a4 = a2;
    //       return 3;
    //   }
    //   return 1;
    // UNRESOLVED: Third argument a3 is unused in the raw body; purpose unknown.
    // UNRESOLVED: Meaning of the two flag bits masked by 6 in this+0x4 is unknown.
}
