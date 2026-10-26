// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042CE30
// Canonical corpus name: SessionTypeNameLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SessionTypeNameLookup_0042ce30.c

void UnknownObject::SessionTypeNameLookup()
{
    // Maps a session type id a1 (0-7) to a display string. When a2 is non-zero the short-name string table is used; when a2 is zero the long-name table is used. Session type 5/6/7 map to the same strings in both tables (Qualify, Warmup, Race). Out-of-range ids fall through to the "Unknown" string.
    // GUARD: Branch on flag a2 selects the short-name switch table (a2 non-zero) or the long-name switch table (a2 zero); both switch bodies are compiled in the function. [source:raw]
    // GUARD: Switch on session type id a1; the long-name cases dispatch through jump table jpt_42CE39 and the short-name cases through jump table jpt_42CE63. [source:raw, global:0x0042CEA0, global:0x0042CEC0]
    // ASSIGNMENT: a1 == 0: return aTestday (long) or aTestDay (short). [global:0x005C3510, global:0x005C3548]
    // ASSIGNMENT: a1 == 1: return aPractice1_0 (long) or aPractice1 (short). [global:0x005C3504, global:0x005C353C]
    // ASSIGNMENT: a1 == 2: return aPractice2_0 (long) or aPractice2 (short). [global:0x005C34F8, global:0x005C3530]
    // ASSIGNMENT: a1 == 3: return aPractice3_0 (long) or aPractice3 (short). [global:0x005C34EC, global:0x005C3524]
    // ASSIGNMENT: a1 == 4: return aPractice4_0 (long) or aPractice4 (short). [global:0x005C34E0, global:0x005C3518]
    // ASSIGNMENT: a1 == 5: return aQualify from the shared label reached by both tables. [global:0x005C34D8]
    // ASSIGNMENT: a1 == 6: return aWarmup from the shared label reached by both tables. [global:0x005C34D0]
    // ASSIGNMENT: a1 == 7: return aRace_0 from the shared label reached by both tables. [global:0x005C34C8]
    // ASSIGNMENT: Default case: return aUnknown for out-of-range session type ids. [global:0x005C307C]
    // RETURN: Return the selected session type name string to the caller. [source:raw]
    // UNKNOWN: Consumed by Steward_Restart, sub_4FE350, and WeatherConditionsFileWriter for session type name display; the exact roles of the callers are outside this function's scope. [caller:0x004D3CF0, caller:0x004FE350, caller:0x004FE820]

    // Conservative worker pseudocode:
    //   char *SessionTypeNameLookup(int typeId, char shortNames) {
    //     if (shortNames) {
    //       switch (typeId) {
    //         case 0: return aTestDay; case 1: return aPractice1; case 2: return aPractice2;
    //         case 3: return aPractice3; case 4: return aPractice4; case 5: return aQualify;
    //         case 6: return aWarmup; case 7: return aRace_0; default: return aUnknown;
    //       }
    //     } else {
    //       switch (typeId) {
    //         case 0: return aTestday; case 1: return aPractice1_0; case 2: return aPractice2_0;
    //         case 3: return aPractice3_0; case 4: return aPractice4_0; case 5: return aQualify;
    //         case 6: return aWarmup; case 7: return aRace_0; default: return aUnknown;
    //       }
    //     }
    //   }
    // UNRESOLVED: Mapping of a1 values to named session types (test day, practice, qualify, warmup, race) is inferred from string names; not proven by the packet.
    // UNRESOLVED: Why the short and long tables overlap for ids 5-7 is unexplained by the raw code.
}
