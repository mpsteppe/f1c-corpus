// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049E410
// Canonical corpus name: DualTextDisplay
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualTextDisplay_0049e410.c

void UnknownObject::DualTextDisplay()
{
    // Formats and renders a label/value pair at the same Y position. Formats the label into the local buffer with sub_49BB40 and renders it at the first X (a2); then formats the value with sub_49BBB0 and renders it at the second X (a3). Both renders go through StringFormatAndRender with the render surface from this[2], the display context read at this[5]+84, and the shared Y position a4; the two calls differ only in the trailing render flag (1 for the label, 0 for the value).
    // CALL: sub_49BB40 formats the label text into the local buffer with size argument 15 [callee:0x0049BB40, source:raw]
    // CALL: StringFormatAndRender renders the label at X a2 with shared Y a4, using the render surface from this[2] and the display context read at this[5]+84, with trailing render flag 1 [callee:0x0049F6A0, field:this:0x00000008, field:this:0x00000014, source:raw]
    // CALL: sub_49BBB0 formats the value text into the same local buffer with size argument 15 [callee:0x0049BBB0, source:raw]
    // RETURN: StringFormatAndRender renders the value at X a3 with shared Y a4 and the same render surface and display context, using trailing render flag 0; its return value is returned directly [callee:0x0049F6A0, field:this:0x00000008, field:this:0x00000014, function:0x0049E410, source:raw]
    // CALL: Invoked by sub_49D700, UtilityFunction_d8b0 and TimestampedRenderStringUpdate as their label/value renderer [caller:0x0049D700, caller:0x0049D8B0, caller:0x0049DA60, source:raw]

    // Conservative worker pseudocode:
    //   sub_49BB40(buffer, 15);
    //   StringFormatAndRender(buffer, a2, a4, this[2], *(this[5] + 84), 1);
    //   sub_49BBB0(buffer, 15);
    //   return StringFormatAndRender(buffer, a3, a4, this[2], *(this[5] + 84), 0);
    // UNRESOLVED: Field this+0x68 is flagged by packet facts but never referenced by the raw decompiled source; the skeleton fill labels it a sub-struct pointer, unverifiable from this packet
    // UNRESOLVED: The globals dword_7CE048 and unk_7CE234 are flagged by packet facts but never referenced by the raw decompiled source; the skeleton fill labels them RaceSessionState and DriverAppearanceFlag, both unverifiable from this packet
}
