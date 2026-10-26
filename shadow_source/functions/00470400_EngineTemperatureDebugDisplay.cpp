// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00470400
// Canonical corpus name: EngineTemperatureDebugDisplay
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EngineTemperatureDebugDisplay_00470400.c

void UnknownObject::EngineTemperatureDebugDisplay()
{
    // Conditional debug display updater: when the type selector at this+0x304 equals 435 and the session-state check passes, it seeds a local path buffer with the application-directory path (byte_5EA438), composes a debug string, and calls BoundedFieldSetter with (159 - strlen) to update a bounded field.
    // GUARD: Require this[193] (offset 0x304) to equal 435 (0x1B3); otherwise the debug display update is skipped. [field:this:0x00000304, guard:0]
    // GUARD: Require SessionStateCheckWrapper(dword_7CD25C) to pass so the update only runs in the expected session state. [callee:0x00461DB0, global:0x007CD25C]
    // ASSIGNMENT: Seed the local path buffer: first byte copied from byte_5EA438, remaining 60 bytes zeroed via memset, then a null terminator appended. [global:0x005EA438, source:raw]
    // CALL: sub_4B0B20(pathBuffer, 64) composes the target file path into the 64-byte buffer. [callee:0x004B0B20, source:raw]
    // CALL: StringFormatWrapper(pathBuffer, formatBuffer, 128) formats the debug string into the 128-byte output buffer. [callee:0x0045BC10, source:raw]
    // CALL: BoundedFieldSetter(159 - strlen(formatBuffer)) updates a bounded field scaled by the formatted string length. [callee:0x0048B8F0, source:raw]

    // Conservative worker pseudocode:
    //   if (this->displayType == 435 && SessionStateCheckWrapper(g_session)) {
    //     buildPath(pathBuffer, g_appDir);
    //     StringFormatWrapper(pathBuffer, formatBuffer, 128);
    //     BoundedFieldSetter(159 - strlen(formatBuffer));
    //   }
    // UNRESOLVED: dword_7CD204 and byte_7CE498 are listed as referenced globals in the packet but do not appear in the raw decompiled source text; their role is unknown.
    // UNRESOLVED: The meaning of the type-selector value 435 (0x1B3) and the semantics of BoundedFieldSetter's argument are not documented in this packet.
}
