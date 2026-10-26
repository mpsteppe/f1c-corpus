// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004963C0
// Canonical corpus name: FieldSetter_63c0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldSetter_63c0_004963c0.c

void UnknownObject::FieldSetter_63c0()
{
    // Flag setter (__thiscall): unconditionally writes constant 1 to the dword at this+0x28 (this[10]) and returns 0. No guards, no callees, no globals. Its only known caller is sub_485B90 (0x00485B90). The write persists until explicitly cleared by some other code path.
    // ASSIGNMENT: Write the constant 1 to the dword at this+0x28 (this[10]); unconditional boolean-flag/state enable [field:this:0x00000028, function:0x004963C0, source:raw]
    // RETURN: Return integer 0 (success-style or void-mimicking return) [function:0x004963C0, source:raw]

    // Conservative worker pseudocode:
    //   int FieldSetter_63c0(_DWORD *this)
    //   {
    //     this[10] = 1;
    //     return 0;
    //   }
    // UNRESOLVED: Owning class of 'this' is unidentified; whether field +0x28 is a boolean flag, enable bit, or state selector is not evidenced
    // UNRESOLVED: What clears the flag set here, and what behavior the caller sub_485B90 (0x00485B90) triggers with it, is outside this packet
}
