// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049F6A0
// Canonical corpus name: StringFormatAndRender
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringFormatAndRender_0049f6a0.c

void UnknownObject::StringFormatAndRender()
{
    // render-subsystem helper that formats and renders a text string. Nested guards require a1, a4 and a5 to be nonzero; a5 is copied to v6. Depending on a6, one of two alignment modifiers runs in place on a2: SubtractionWithGuard(a1, a2, &a2, a4) when a6 == 1, or CenterCalc(a1, a2, &a2, a4) when a6 == 2. The tail call sub_553070(a1, a2, a3, v6) commits the render and its result is returned. When any guard fails the function returns an uninitialized value. Subsystem is flagged render; callers are HUD/text display helpers (TimestampedRenderStringUpdate, BrakeWaterTemperatureHUDDisplay, DualTextDisplay).
    // GUARD: Outer guard: a1 must be nonzero, otherwise the whole body is skipped [source:raw]
    // GUARD: Guard: a4 must be nonzero, otherwise the modifier path is skipped [source:raw]
    // GUARD: Guard: a5 must be nonzero; only then is the modifier path entered [source:raw]
    // ASSIGNMENT: v6 = a5: a5 is preserved in ebx for the final render call [source:raw]
    // CALL: Conditional branch a6 == 1: SubtractionWithGuard(a1, a2, &a2, a4) modifies a2 in place (left-align style adjustment) [callee:0x0049F710, source:raw]
    // CALL: Conditional branch a6 == 2: CenterCalc(a1, a2, &a2, a4) modifies a2 in place (centering adjustment) [callee:0x0049F750, source:raw]
    // CALL: Final stage: sub_553070(a1, a2, a3, v6) commits the formatted/render result and is executed after either modifier branch [callee:0x00553070, source:raw]
    // RETURN: Returns the result of sub_553070; on any failing guard path the function returns the uninitialized register value [function:0x0049F6A0, source:raw]

    // Conservative worker pseudocode:
    //   if (a1 && a4 && a5) {
    //     v6 = a5;
    //     if (a6 == 1) SubtractionWithGuard(a1, a2, &a2, a4);
    //     else if (a6 == 2) CenterCalc(a1, a2, &a2, a4);
    //     return sub_553070(a1, a2, a3, v6);
    //   }
    //   return result; // uninitialized on guard failure
    // UNRESOLVED: In the decompiler output result is uninitialized: when any guard fails the function returns whatever EAX happened to hold, so the failing-guard behavior is unresolved
    // UNRESOLVED: The exact math of SubtractionWithGuard (0x0049F710) and CenterCalc (0x0049F750), and what the a6 mode values 1 and 2 mean semantically beyond the code selector, are unresolved; both names are generic
    // UNRESOLVED: The semantic roles of a2/a3/a4/a5 with respect to the final sub_553070 render (0x00553070) are unresolved
}
