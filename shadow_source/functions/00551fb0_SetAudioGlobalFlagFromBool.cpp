// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00551FB0
// Canonical corpus name: SetAudioGlobalFlagFromBool
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SetAudioGlobalFlagFromBool_00551fb0.c

void UnknownObject::SetAudioGlobalFlagFromBool()
{
    // Normalizes integer argument a1 to a BOOL (nonzero becomes 1), writes that BOOL into the global audio flag dword_8B6AC4, and returns the BOOL. No guards or callees.
    // CALCULATION: Compute result = (a1 != 0), normalizing the input to a 0/1 BOOL. [source:raw]
    // ASSIGNMENT: Store the normalized BOOL into global dword_8B6AC4 (audio subsystem global flag). [global:0x008B6AC4]
    // RETURN: Return the stored BOOL result. [source:raw]

    // Conservative worker pseudocode:
    //   BOOL __stdcall sub_551FB0(int a1) {
    //     BOOL result = a1 != 0;
    //     dword_8B6AC4 = result;
    //     return result;
    //   }
    // UNRESOLVED: The semantics of dword_8B6AC4 beyond 'audio global flag' are not established by this packet.
    // UNRESOLVED: The single caller VidMan_Init passes the boolean value that drives the flag; the flag's consumer is unknown here.
}
