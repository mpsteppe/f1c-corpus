// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004119B0
// Canonical corpus name: sub_4119B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4119B0_004119b0.c

void UnknownObject::freeGlobalTrackedBuffer()
{
    // Frees the globally tracked buffer pointer dword_5EA5D0 when it is non-null, returning the FreeWrapper_7bcf result; otherwise returns the null global value.
    // GUARD: Proceed to free only when global dword_5EA5D0 is non-zero. [global:0x005EA5D0, source:raw]
    // CALL: Call FreeWrapper_7bcf passing dword_5EA5D0 as the buffer pointer to release. [callee:0x00587BCF, global:0x005EA5D0, source:raw]
    // RETURN: Return the FreeWrapper_7bcf result when the global was non-null, otherwise return the null global value read at entry. [global:0x005EA5D0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4119B0(void) {
    //     if (dword_5EA5D0 != 0) {
    //       return FreeWrapper_7bcf((LPVOID)dword_5EA5D0);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Which object dword_5EA5D0 points to and which allocation path set it is not evident in this packet.
}
