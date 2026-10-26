// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049BAB0
// Canonical corpus name: DisqualificationCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DisqualificationCheck_0049bab0.c

void UnknownObject::DisqualificationCheck()
{
    // Trivial boolean query: dereferences the global pointer dword_7C54E0, reads the dword at offset 16484 of the target object, and returns whether it equals 3. The packet labels the function DisqualificationCheck and places it in the session subsystem; the three callers (sub_49D4C0, HUDFlagRendererMain, HUDFlagRendererSecondary) query it, consistent with a session-state/flag query. Returns a bool, no side effects.
    // CALCULATION: Read the dword at (dword_7C54E0 + 16484): dereference the global pointer and load the dword 16484 bytes into its target. [global:0x007C54E0, source:raw]
    // RETURN: Return whether the loaded dword equals 3; no other writes or side effects. [source:raw]
    // CALL: Queried by three callers (sub_49D4C0, HUDFlagRendererMain at 004D82D0, HUDFlagRendererSecondary at 004DBAC3), consistent with a shared disqualification/session-state query used by the HUD flag renderers. [caller:0x0049D4C0, caller:0x004D82D0, caller:0x004DBAC3, source:raw]

    // Conservative worker pseudocode:
    //   bool sub_49BAB0() {
    //     return *(DWORD*)(dword_7C54E0 + 16484) == 3;
    //   }
    // UNRESOLVED: The object pointed to by dword_7C54E0 is unknown; only the relative offset 16484 is evidenced.
    // UNRESOLVED: Meaning of the compared value 3 (the semantic state it encodes) is not evidenced in this packet.
    // UNRESOLVED: Byte at dword_7C54E0+16484 is read as a dword but the field type/meaning is unspecified.
}
