// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A0D10
// Canonical corpus name: GlobalStateOneTimeInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalStateOneTimeInitializer_004a0d10.c

void UnknownObject::GlobalStateOneTimeInitializer()
{
    // One-time global state initializer: reads flag byte byte_7CE269; if it is zero, sets it to one and writes the constant 1084227584 into dword_7CE26C. Returns the previous flag value (0 on the first run, 1 on later runs). Called from SessionMenuModeSwitch (0x004A0C60).
    // GUARD: Read byte_7CE269; proceed with initialization only while it is zero. [global:0x007CE269, source:raw]
    // ASSIGNMENT: Set flag byte_7CE269 to 1 to mark the state as initialized. [global:0x007CE269, source:raw]
    // ASSIGNMENT: Write the literal 1084227584 into dword_7CE26C. [global:0x007CE26C, source:raw]
    // RETURN: Return the prior value of byte_7CE269 (0 if this call performed the initialization, 1 otherwise). [source:raw, function:0x004A0D10]

    // Conservative worker pseudocode:
    //   char sub_4A0D10(void) {
    //     char result = byte_7CE269;
    //     if (!byte_7CE269) {
    //       byte_7CE269 = 1;
    //       dword_7CE26C = 1084227584;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantics of the constant 1084227584 stored in dword_7CE26C are unknown (no float interpretation is claimed without packet evidence).
    // UNRESOLVED: Relationship of byte_7CE269/dword_7CE26C to the session-menu state machine is not established beyond the reported caller SessionMenuModeSwitch (0x004A0C60).
    // UNRESOLVED: Why the caller needs the pre-initialization flag value as a return is unknown.
}
