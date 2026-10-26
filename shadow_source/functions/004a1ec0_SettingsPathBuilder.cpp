// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A1EC0
// Canonical corpus name: SettingsPathBuilder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SettingsPathBuilder_004a1ec0.c

void UnknownObject::SettingsPathBuilder()
{
    // Constructs a settings file path by copying the application directory string into a path buffer, then appending a base file path (asc_5CD148), a caller-supplied player-specific identifier (a2), and a file suffix (asc_5CD144). The completed path is passed to ShortComputation_1b70 for further processing, and its result returned.
    // CALL: Copy the application directory string (byte_5EA438) into the path buffer via StringCopyWithBufferRealloc. [source:raw, callee:0x00566650, global:0x005EA438]
    // CALL: Append the base file path string asc_5CD148 to the buffer via sub_5665B0. [source:raw, callee:0x005665B0, global:0x005CD148]
    // CALL: Append the caller-supplied player-specific identifier a2 to the buffer via sub_5665B0. [source:raw, callee:0x005665B0]
    // CALL: Append the file suffix string asc_5CD144 to the buffer via sub_5665B0. [source:raw, callee:0x005665B0, global:0x005CD144]
    // CALL: Pass the built path buffer to ShortComputation_1b70 for processing. [source:raw, callee:0x004A1B70]
    // RETURN: Return the result of ShortComputation_1b70. [source:raw]

    // Conservative worker pseudocode:
    //   void* SettingsPathBuilder(void* this, int playerId) {
    //     StringCopyWithBufferRealloc(byte_5EA438);
    //     sub_5665B0(asc_5CD148);
    //     sub_5665B0(playerId);
    //     sub_5665B0(asc_5CD144);
    //     return ShortComputation_1b70(this);
    //   }
    // UNRESOLVED: Identity of the player-specific identifier a2 and the exact meanings of the asc_5CD148 / asc_5CD144 path components.
    // UNRESOLVED: What ShortComputation_1b70 does with the built path is outside this function's scope.
}
