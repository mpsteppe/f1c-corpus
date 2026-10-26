// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D820
// Canonical corpus name: InitKeyboardAxis0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InitKeyboardAxis0_0044d820.c

void UnknownObject::InitKeyboardAxis0()
{
    // Initializes a six-dword keyboard-axis configuration block at 0x7CCC50: writes 25 to the first field and zeroes the following five fields. Unconditional straight-line write with no calls, guards, or parameters; returns 0.
    // ASSIGNMENT: dword_7CCC50[0] = 25; set first keyboard-axis config field (index 0) to the literal 25 [global:0x007CCC50, source:raw]
    // ASSIGNMENT: dword_7CCC54 = 0; zero the second keyboard-axis config field [global:0x007CCC54]
    // ASSIGNMENT: dword_7CCC58 = 0; zero the third keyboard-axis config field [global:0x007CCC58]
    // ASSIGNMENT: dword_7CCC5C = 0; zero the fourth keyboard-axis config field [global:0x007CCC5C]
    // ASSIGNMENT: dword_7CCC60 = 0; zero the fifth keyboard-axis config field [global:0x007CCC60]
    // ASSIGNMENT: dword_7CCC64 = 0; zero the sixth keyboard-axis config field [global:0x007CCC64]
    // RETURN: return 0; fixed zero return value, no data dependency [function:0x0044D820, source:raw]

    // Conservative worker pseudocode:
    //   dword_7CCC50[0] = 25;
    //   dword_7CCC54 = 0;
    //   dword_7CCC58 = 0;
    //   dword_7CCC5C = 0;
    //   dword_7CCC60 = 0;
    //   dword_7CCC64 = 0;
    //   return 0;
    // UNRESOLVED: The exact meaning of the literal 25 (count, axis code, or other config value) and the roles of the five zeroed fields are not documented; only the write pattern is evidenced
    // UNRESOLVED: No static callers or callees exist in the packet, so the context in which the keyboard-axis config is consumed is unknown
}
