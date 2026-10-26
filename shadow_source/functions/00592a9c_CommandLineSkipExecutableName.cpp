// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00592A9C
// Canonical corpus name: sub_592A9C
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_592A9C_00592a9c.c

void UnknownObject::CommandLineSkipExecutableName()
{
    // Lazy-initializes the CRT command-line singleton when dword_8D5A4C is zero, then skips past the leading command-line token (either a quoted or an unquoted token) and returns a pointer to the first argument after the executable name, trimmed of leading whitespace.
    // GUARD: If dword_8D5A4C (init guard flag) is zero, the command-line singleton has not been initialized yet. [source:raw, global:0x008D5A4C]
    // CALL: Call LazyInitSingletonWithFlagGuard_7218 to build the command-line singleton. [source:raw, callee:0x00597218]
    // ASSIGNMENT: v0 = (_BYTE *)dword_8D5A44 takes the current command-line cursor pointer. [source:raw, global:0x008D5A44]
    // GUARD: If *(_BYTE *)dword_8D5A44 != 34, the leading token is unquoted and is handled by the whitespace-skip loop. [source:raw]
    // LOOP: Unquoted token path: advance v0 while *v0 > 0x20 to skip past the token until a whitespace character or terminator. [source:raw]
    // LOOP: Quoted token path: advance v0 reading v1 = *v0 until v1 == 34 (closing quote) or v1 is zero; when ThreeArgCallWrapper(v1) is true the following character is escaped and skipped by an extra ++v0. [source:raw, callee:0x00596DFE]
    // GUARD: After a quoted token, if *v0 != 34 fall through to the whitespace trim; otherwise consume the closing quote with ++v0. [source:raw]
    // LOOP: Trim trailing whitespace: advance v0 while *v0 is non-zero and *v0 <= 0x20. [source:raw]
    // RETURN: Return v0, the pointer to the first argument after the executable name. [source:raw]

    // Conservative worker pseudocode:
    //   _BYTE *sub_592A9C() {
    //     if (!dword_8D5A4C) LazyInitSingletonWithFlagGuard_7218();
    //     _BYTE *v0 = (_BYTE *)dword_8D5A44;
    //     if (*(_BYTE *)dword_8D5A44 != 34) {
    //       if (*(_BYTE *)dword_8D5A44 > 0x20) { do ++v0; while (*v0 > 0x20); }
    //     } else {
    //       unsigned __int8 v1;
    //       do { v1 = *++v0; } while (v1 != 34 && v1 && !(ThreeArgCallWrapper(v1) && (++v0, 1)));
    //       if (*v0 == 34) ++v0;
    //     }
    //     while (*v0 && *v0 <= 0x20) ++v0;
    //     return v0;
    //   }
    // UNRESOLVED: Exact behavior of ThreeArgCallWrapper on a single character (likely escape or quote handling) is unknown.
    // UNRESOLVED: Whether dword_8D5A44 points into a static buffer or a heap-allocated command-line copy is unresolved.
    // UNRESOLVED: The caller sub_58A19E's use of the returned argument pointer is not established from this packet.
}
