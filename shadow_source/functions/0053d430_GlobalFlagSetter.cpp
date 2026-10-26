// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053D430
// Canonical corpus name: ShortComputation_d430
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_d430_0053d430.c

void UnknownObject::GlobalFlagSetter()
{
    // Trivial global flag setter, structurally identical to the adjacent setter at the neighboring address but writing a different global. Computes the truthiness of the integer argument (a1 != 0), stores the BOOL into dword_8B8E24 (0x008B8E24), and returns it. Called from VidMan_Init; the flag's consumers are not in this packet.
    // ASSIGNMENT: Compute (a1 != 0) and store the resulting BOOL into the global flag dword_8B8E24 (0x008B8E24). [global:0x008B8E24, source:raw]
    // RETURN: Return the computed BOOL, identical to the value just stored in dword_8B8E24. [function:0x0053D430, source:raw]

    // Conservative worker pseudocode:
    //   BOOL GlobalFlagSetter(int a1) {
    //     BOOL result = (a1 != 0);
    //     dword_8B8E24 = result;
    //     return result;
    //   }
    // UNRESOLVED: The meaning of dword_8B8E24 and which code reads it is not in this packet; only the single caller VidMan_Init and the write are visible.
    // UNRESOLVED: Whether a1 is a plain integer, an enum or a pointer is not determinable from the packet; it is only compared for truthiness.
    // UNRESOLVED: The relationship, if any, between this setter's global dword_8B8E24 and the sibling setter at the adjacent address that writes its own nearby dword_8B8E2C global is not established by this packet.
}
