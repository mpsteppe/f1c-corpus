// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049E4E0
// Canonical corpus name: AudioEffectTrigger
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioEffectTrigger_0049e4e0.c

void UnknownObject::AudioEffectTrigger()
{
    // Conditionally forwards an audio-effect request (a1, a2) to sub_5506A0(a1, a2, 0) based on two effect-flag dwords on the base object dword_7C54E0. If the flag at offset 3984 (0xF90) is non-zero the call result becomes the return candidate; if the flag at offset 3964 (0xF7C) is non-zero the function returns the call result immediately. When neither flag is set it returns the base object pointer dword_7C54E0. Called from steering-wheel, wheel-rotation, and random-collision feedback paths.
    // ASSIGNMENT: Seed result with the base object pointer dword_7C54E0. [global:0x007C54E0, source:raw]
    // GUARD: When the dword at offset 3984 (0xF90) of the base object is non-zero, call sub_5506A0(a1, a2, 0) and store its result. [global:0x007C54E0, callee:0x005506A0, source:raw]
    // GUARD: When the dword at offset 3964 (0xF7C) of the base object is non-zero, return the result of sub_5506A0(a1, a2, 0) immediately. [global:0x007C54E0, callee:0x005506A0, source:raw]
    // RETURN: Return the last computed result: the base pointer dword_7C54E0 when no flag was set, otherwise the audio-trigger call result. [global:0x007C54E0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_49E4E0(int a1, int a2) {
    //     int result = dword_7C54E0;
    //     if (*(int*)(dword_7C54E0 + 3984))
    //       result = sub_5506A0(a1, a2, 0);
    //     if (*(int*)(dword_7C54E0 + 3964))
    //       return sub_5506A0(a1, a2, 0);
    //     return result;
    //   }
    // UNRESOLVED: The object behind dword_7C54E0 and the semantics of its flag dwords at offsets 3964 and 3984 are unconfirmed.
    // UNRESOLVED: The sound/effect behavior of sub_5506A0(a1, a2, 0) and the meanings of a1 and a2 are unknown.
    // UNRESOLVED: The odd fallback of returning the base pointer dword_7C54E0 when neither flag is set is unexplained.
}
