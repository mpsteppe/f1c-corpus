// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00552FF0
// Canonical corpus name: SwitchBasedParameterFieldSetWithFlags
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SwitchBasedParameterFieldSetWithFlags_00552ff0.c

void UnknownObject::SetAlphaBlendParam()
{
    // Sets two render/state fields. Unconditionally writes a2 into this[21] (offset 0x54, texture/scale parameter). Then maps a3 in range 0-4 to an alpha-blend value written to this[22] (offset 0x58): 0->191, 1->127, 2->63, 3->0, 4->255. A default case (a3 outside 0-4) returns immediately, leaving this[22] unchanged. Always returns a3. The 0x58 selection uses a jump table (jpt_553000 at 0x0055303C).
    // ASSIGNMENT: Unconditionally write a2 (texture/scale parameter) into this[21] at offset 0x54. [field:this:0x00000054, function:0x00552FF0, source:raw]
    // STATE_TRANSITION: Switch on a3 selecting an alpha-blend value written to this[22] at offset 0x58 via jump table: 0->191, 1->127, 2->63, 3->0, 4->255. [field:this:0x00000058, global:0x0055303C, function:0x00552FF0, source:raw]
    // GUARD: Default case: a3 outside 0-4 returns immediately without writing this[22], preserving the previous blend value. [field:this:0x00000058, function:0x00552FF0, source:raw]
    // RETURN: Return a3 in all paths. [function:0x00552FF0, source:raw]

    // Conservative worker pseudocode:
    //   this[21] (this+0x54) = a2;
    //   switch (a3):
    //       case 0: this[22] (this+0x58) = 191; break;
    //       case 1: this[22] = 127; break;
    //       case 2: this[22] = 63; break;
    //       case 3: this[22] = 0; break;
    //       case 4: this[22] = 255; break;
    //       default: return a3;
    //   return a3;
    // UNRESOLVED: Exact meaning of the five blend constants (191, 127, 63, 0, 255) is not independently proven; existing analysis labels this[22] an alpha-blend value but the caller (FontSurfaceLookupDispatch) semantics are not confirmed.
    // UNRESOLVED: The jump table symbol jpt_553000 comes from existing analysis; the raw source does not name it.
}
