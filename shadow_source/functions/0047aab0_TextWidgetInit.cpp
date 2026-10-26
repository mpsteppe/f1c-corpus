// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047AAB0
// Canonical corpus name: TextWidgetInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextWidgetInit_0047aab0.c

void UnknownObject::TextWidgetInit()
{
    // Initializes a text widget: stores the score-db pointer dword_7C5728 into this+0xE0, zeroes this+0xE4/0xE8/0xEC/0x110, optionally processes a path string (falling back to byte_5EA438) through sub_498560, renders text key aTtgjz via TextRenderToSurface, sets this+0xF8/0xFC to 5, and returns AIOvertakeGapCalc().
    // ASSIGNMENT: Set defaults: this+0xE0 = &dword_7C5728 (score-db pointer); this+0xE4, this+0xE8, this+0xEC, this+0x110 = 0. [field:this:0x000000E0, field:this:0x000000E4, field:this:0x000000E8, field:this:0x000000EC, field:this:0x00000110, global:0x007C5728]
    // GUARD: If the source object pointer at this+0xC8 is nonzero, read the path string at v2+64; when it is null use the default byte_5EA438, then process it with sub_498560. [field:this:0x000000C8, global:0x005EA438, callee:0x00498560]
    // CALL: TextRenderToSurface(aTtgjz, local buffer v5, this+61, 1): render the text identified by key aTtgjz. [callee:0x004983B0, global:0x005C71CC]
    // ASSIGNMENT: Set padding/margin fields: this+0xF8 = 5, this+0xFC = 5. [field:this:0x000000F8, field:this:0x000000FC]
    // RETURN: Return AIOvertakeGapCalc() as the initializer result. [function:0x0047AAB0, source:raw]

    // Conservative worker pseudocode:
    //   v2 = this[0xC8];
    //   this[0xE0] = &dword_7C5728;
    //   this[0xE4] = 0; this[0xE8] = 0; this[0xEC] = 0; this[0x110] = 0;
    //   if (v2) {
    //     v3 = *(char**)(v2 + 64);
    //     if (!v3) v3 = byte_5EA438;
    //     sub_498560(v3);
    //   }
    //   TextRenderToSurface(aTtgjz, v5, this + 61, 1);
    //   this[0xF8] = 5; this[0xFC] = 5;
    //   return AIOvertakeGapCalc();
    // UNRESOLVED: The optional object read at v2+64 is a field of the external object referenced by this+0xC8, not of this; its structure is unknown
    // UNRESOLVED: AIOvertakeGapCalc is used as the return value but is not listed among the packet callees; its relation to the text widget is unresolved
}
