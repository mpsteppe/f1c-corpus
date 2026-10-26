// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A0DA0
// Canonical corpus name: GlobalFlagSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalFlagSetter_004a0da0.c

void UnknownObject::SetGlobalFlag()
{
    // Unconditional global flag setter: writes 1 to byte_7CE25D and returns void. No guards, no arguments, no other side effects. Invoked by SessionSynchronizer (0x0045F950), sub_4A0250 (0x004A0250) and sub_4D4580 (0x004D4580).
    // ASSIGNMENT: Write 1 to byte_7CE25D to raise the global flag. [global:0x007CE25D, source:raw]
    // CALL: Flag setter invoked by SessionSynchronizer (0x0045F950), sub_4A0250 (0x004A0250) and sub_4D4580 (0x004D4580). [source:raw, caller:0x0045F950, caller:0x004A0250, caller:0x004D4580]

    // Conservative worker pseudocode:
    //   void sub_4A0DA0() {
    //     byte_7CE25D = 1;
    //   }
    // UNRESOLVED: The meaning of the byte_7CE25D flag (session synchronization state?) and why only a set-to-1 path exists are not documented in this function.
    // UNRESOLVED: There is no clearing or reading counterpart in this function; consumers of the flag are not visible here.
}
