// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004216F0
// Canonical corpus name: ConfigDirectoryPathRegistration
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConfigDirectoryPathRegistration_004216f0.c

void UnknownObject::ConfigDirectoryPathRegistration()
{
    // Registers a fixed list of configuration directory path constants into the config path table by calling StringCopyWithBufferRealloc for each global path string, then initializes config structure fields on `this` with preset literals, including a path count of 22 and a sentinel literal -1082130432.
    // CALL: Registers path constant ExistingFileName (0x005C2AA0) into the config path table. [callee:0x00566650, global:0x005C2AA0]
    // CALL: Registers path constant aSeasondata (0x005C2A94). [callee:0x00566650, global:0x005C2A94]
    // CALL: Registers path constant aAudio (0x005C2A8C). [callee:0x00566650, global:0x005C2A8C]
    // CALL: Registers path constant aAudioVehicle (0x005C2A7C). [callee:0x00566650, global:0x005C2A7C]
    // CALL: Registers path constant aOptionsAnim (0x005C2A6C). [callee:0x00566650, global:0x005C2A6C]
    // CALL: Registers path constant aOptionsFlags (0x005C2A5C). [callee:0x00566650, global:0x005C2A5C]
    // CALL: Registers path constant aAudioOptions (0x005C2A4C). [callee:0x00566650, global:0x005C2A4C]
    // CALL: Registers path constant aOptions (0x005C2A40). [callee:0x00566650, global:0x005C2A40]
    // CALL: Registers path constant aReplays (0x005C2A34). [callee:0x00566650, global:0x005C2A34]
    // CALL: Registers path constant aMovies (0x005C2A2C). [callee:0x00566650, global:0x005C2A2C]
    // CALL: Registers path constant aCircuits (0x005C2A20). [callee:0x00566650, global:0x005C2A20]
    // CALL: Registers path constant aVehicles (0x005C2A14). [callee:0x00566650, global:0x005C2A14]
    // CALL: Registers path constant aDrivers (0x005C2A08). [callee:0x00566650, global:0x005C2A08]
    // CALL: Registers path constant aLog (0x005C2A00). [callee:0x00566650, global:0x005C2A00]
    // CALL: Registers path constant aSave (0x005C29F8). [callee:0x00566650, global:0x005C29F8]
    // CALL: Registers path constant aAudioMusic (0x005C29E8). [callee:0x00566650, global:0x005C29E8]
    // CALL: Registers the default/empty path global byte_5EA438. [callee:0x00566650, global:0x005EA438]
    // CALL: Registers the default/empty path global byte_5EA438 again. [callee:0x00566650, global:0x005EA438]
    // CALL: Registers path constant aDevfilesCamed (0x005C29D8). [callee:0x00566650, global:0x005C29D8]
    // CALL: Registers path constant aSchool (0x005C29D0). [callee:0x00566650, global:0x005C29D0]
    // CALL: Registers path constant aAudioCommentar_1 (0x005C29BC). [callee:0x00566650, global:0x005C29BC]
    // CALL: Registers the default/empty path global byte_5EA438 a third time, completing 22 registered path entries. [callee:0x00566650, global:0x005EA438]
    // ASSIGNMENT: Zero-initializes this+0xB8 (dword). [field:this:0x000000B8]
    // ASSIGNMENT: Zero-initializes this+0xBC (dword). [field:this:0x000000BC]
    // ASSIGNMENT: Zero-initializes this+0xC0 (dword). [field:this:0x000000C0]
    // ASSIGNMENT: Sets this+0xC4 (dword) to 22, the count of registered directory paths. [field:this:0x000000C4]
    // ASSIGNMENT: Sets this+0xC8 (dword) to 1 (enabled flag). [field:this:0x000000C8]
    // ASSIGNMENT: Sets this+0xCC (dword) to 0. [field:this:0x000000CC]
    // ASSIGNMENT: Zero-initializes this+0xD0 (dword). [field:this:0x000000D0]
    // ASSIGNMENT: Sets byte at this+0xD4 to 0. [field:this:0x000000D4]
    // ASSIGNMENT: Sets byte at this+0xD5 to 1. [field:this:0x000000D5]
    // ASSIGNMENT: Sets byte at this+0xD6 to 0. [field:this:0x000000D6]
    // ASSIGNMENT: Sets this+0xD8 (dword) to 1 (enabled flag). [field:this:0x000000D8]
    // ASSIGNMENT: Sets this+0xDC (dword) to 1 (enabled flag). [field:this:0x000000DC]
    // ASSIGNMENT: Zero-initializes this+0xE0 (dword). [field:this:0x000000E0]
    // ASSIGNMENT: Sets this+0xE4 (dword) to 1 (enabled flag). [field:this:0x000000E4]
    // ASSIGNMENT: Sets this+0xE8 (dword) to literal -1082130432. [field:this:0x000000E8]
    // RETURN: Returns 0. [function:0x004216F0]

    // Conservative worker pseudocode:
    //   register all 22 path globals via StringCopyWithBufferRealloc
    //   this->count = 22; this->flags initialized; this+0xE8 = -1082130432
    //   return 0
    // UNRESOLVED: Meaning of the literal -1082130432 written to this+0xE8 is not established by packet evidence.
    // UNRESOLVED: Default-path global byte_5EA438 is registered three times; whether this is intended or dead repetition is unresolved.
    // UNRESOLVED: Caller FunctionCallWrapper_1470 (0x00421470) and the LEGACY ABI name are not analyzed here.
}
