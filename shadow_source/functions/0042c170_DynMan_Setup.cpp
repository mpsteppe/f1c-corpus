// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042C170
// Canonical corpus name: DynMan_Setup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DynMan_Setup_0042c170.c

void UnknownObject::DynMan_Setup()
{
    // Dynamic manager setup handler. Calls StringSplitLoop(2, aDDevF119992002_12, 519) and stores the status result. If the low byte of the result is non-zero it writes the debug message aEnteredDynmanS to the debug buffer dword_8AD25C and returns that call's value; otherwise it returns the stored StringSplitLoop result. Invoked from the Game_Setup path (0x0042D5D0).
    // CALL: Call StringSplitLoop(2, aDDevF119992002_12, 519) and store the returned status in result. [source:raw, callee:0x004D7A50, global:0x005C3334]
    // GUARD: Guard on the low byte of result being non-zero: only then is the debug entry message written. [source:raw]
    // CALL: Call DebugLogWrite(&dword_8AD25C, aEnteredDynmanS) when the guard passes and return its value directly. [source:raw, callee:0x004D7AA0, global:0x008AD25C, global:0x005C335C]
    // RETURN: When the guard fails, return the stored StringSplitLoop result unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int DynMan_Setup() {
    //     int result = StringSplitLoop(2, aDDevF119992002_12, 519);
    //     if ((char)result != 0)
    //       return DebugLogWrite(&dword_8AD25C, aEnteredDynmanS);
    //     return result;
    //   }
    // UNRESOLVED: Meaning of the leading split parameter 2 and the maximum-length parameter 519 passed to StringSplitLoop.
    // UNRESOLVED: Literal content of aDDevF119992002_12 is not present in the packet.
    // UNRESOLVED: Role of the caller Game_Setup (0x0042D5D0) with respect to this setup is caller-side and not evidenced here.
}
