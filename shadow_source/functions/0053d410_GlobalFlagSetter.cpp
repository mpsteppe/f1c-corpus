// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053D410
// Canonical corpus name: GlobalFlagSetter_d410
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalFlagSetter_d410_0053d410.c

void UnknownObject::GlobalFlagSetter()
{
    // Trivial global flag setter. Computes the truthiness of the single integer argument (a1 != 0), stores the resulting BOOL into the global dword_8B8E2C (0x008B8E2C), and returns the same value. Called from VidMan_Init, so the flag likely records a video-manager enable/disable state, but the flag's consumers are not in this packet.
    // ASSIGNMENT: Compute (a1 != 0) and store the resulting BOOL into the global flag dword_8B8E2C (0x008B8E2C). [global:0x008B8E2C, source:raw]
    // RETURN: Return the computed BOOL, identical to the value just stored in dword_8B8E2C. [function:0x0053D410, source:raw]

    // Conservative worker pseudocode:
    //   BOOL GlobalFlagSetter(int a1) {
    //     BOOL result = (a1 != 0);
    //     dword_8B8E2C = result;
    //     return result;
    //   }
    // UNRESOLVED: The meaning of dword_8B8E2C and which code reads it is not in this packet; only the single caller VidMan_Init and the write are visible.
    // UNRESOLVED: Whether a1 is a plain integer, an enum or a pointer is not determinable from the packet; it is only compared for truthiness.
    // UNRESOLVED: The legacy ABI name suggests a setter that returns the new state, which matches the raw source, but the flag's domain semantics remain unknown.
}
