// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00432E50
// Canonical corpus name: IterationCountMap
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IterationCountMap_00432e50.c

void UnknownObject::IterationCountMap()
{
    // Pure decision function mapping an integer argument to an AI iteration count of 5 or 7: returns 7 when a1 < 3, returns 5 when 3 <= a1 <= 5, and returns 7 when a1 > 5. No side effects, no callees, no fields. All four callers (AISettingsFileLoader, AISettingsFileResolver, LookUpVehicleConfigEntry, AddVehicleConfigEntryToLinkedList) use the result to discriminate qualifying vs race AI config entries: they compare it to 5 (or store it as the entry discriminator) to select the qualifying ('qual' file suffix / qualifying vehicle-config entry) instead of the race default.
    // GUARD: When a1 is less than 3 the function returns 7 immediately. [source:raw, function:0x00432E50]
    // ASSIGNMENT: Initialize the default result to 5, which is only kept for the middle range 3 <= a1 <= 5. [source:raw]
    // GUARD: When a1 is greater than 5 the function returns 7, overriding the default of 5. [source:raw]
    // RETURN: Returns 5 when a1 is in [3,5] and 7 otherwise; callers compare the result to 5 (AISettingsFileLoader, AISettingsFileResolver, LookUpVehicleConfigEntry) or store it as the vehicle-config entry discriminator (AddVehicleConfigEntryToLinkedList) to select qualifying vs race AI config entries. [source:raw, caller:0x004333E0, caller:0x00433890, caller:0x004339E0, caller:0x00433B60]

    // Conservative worker pseudocode:
    //   if (a1 < 3) return 7;
    //   if (a1 > 5) return 7;
    //   return 5;
    // UNRESOLVED: The meaning of the input a1 is unresolved: callers pass a shared module global (dword_7C56A4 in the caller functions), which is not part of this packet, so the value range [3,5] cannot be interpreted without it.
    // UNRESOLVED: Interpreting the returned 5 as the qualifying AI iteration count and 7 as the race default is DERIVED from caller usage, not provable from this function's own source.
    // UNRESOLVED: The function reads no this pointer and touches no fields, so no owning object can be identified from this packet.
    // UNRESOLVED: The ABI lead name IterationCountMap carries LEGACY trust only; its meaning as a count of iterations is not independently evidenced.
}
