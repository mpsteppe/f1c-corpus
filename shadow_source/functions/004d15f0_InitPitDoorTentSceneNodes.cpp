// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D15F0
// Canonical corpus name: sub_4D15F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D15F0_004d15f0.c

void UnknownObject::InitPitDoorTentSceneNodes()
{
    // Scene-node setup for the pit area. First calls sub_4D1450 (logo texture loading) on this, then, gated on the global dword_8AFE88 being non-zero, loops 52 times building a "PDOOR%02d" name and a "PTENT%02d" name with StringFormatWithBufferOverflowCheck, resolves each via EvaluateSceneNodeProperty, and stores the pit-door handles in the slot 52 entries ahead of the tent base (this+0x1B0) and the pit-tent handles at this+0x280. Returns the last property result.
    // CALL: Invoke sub_4D1450(this) first, which loads the logo textures for the 52 slots before the scene-node lookup runs [callee:0x004D1450, function:0x004D15F0, source:raw]
    // GUARD: The entire 52-slot pit door/tent lookup only runs when global dword_8AFE88 is non-zero; when zero the function returns early with the prior result [global:0x008AFE88, source:raw]
    // LOOP: Loop v3 from 0 to 51 (52 iterations); v4 starts at this+160 int slots (this+0x280) and marches forward one slot per iteration [field:this:0x00000280, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck formats "PDOOR%02d" into the v5 buffer using the loop index v3 [callee:0x0058815F, global:0x005D3C54, source:raw]
    // ASSIGNMENT: EvaluateSceneNodeProperty on the PDOOR name stores the pit-door scene node handle into the slot at v4-52, i.e. the handle array 52 entries before the tent array base [callee:0x005453A0, global:0x005D3C54, field:this:0x00000280, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck formats "PTENT%02d" into the v6 buffer using the loop index v3 [callee:0x0058815F, global:0x005D3C48, source:raw]
    // ASSIGNMENT: EvaluateSceneNodeProperty on the PTENT name stores the pit-tent scene node handle into *v4, the current this+0x280 slot [callee:0x005453A0, global:0x005D3C48, field:this:0x00000280, source:raw]
    // LOOP: Increment v3 and advance v4 one slot each iteration, continuing while v3 < 52 [field:this:0x00000280, source:raw]
    // RETURN: Return the last stored result value; the function is invoked by VidMan_Init (004FA320) [function:0x004D15F0, caller:0x004FA320, source:raw]

    // Conservative worker pseudocode:
    //   result = sub_4D1450(this);
    //   if (dword_8AFE88) {
    //     for (i = 0; i < 52; ++i) {
    //       StringFormatWithBufferOverflowCheck(v5, "PDOOR%02d", i);
    //       *(tentBase - 52 + i) = EvaluateSceneNodeProperty(v5, 0);
    //       StringFormatWithBufferOverflowCheck(v6, "PTENT%02d", i);
    //       tentBase[i] = EvaluateSceneNodeProperty(v6, 0);
    //     }
    //   }
    //   return result;
    // UNRESOLVED: The pit-door handle array base (v4-52, this+0x1B0) is written by the loop but only this+0x280 appears in the packet field facts; the 0x1B0 offset is read from the raw source's pointer arithmetic (v4-52) and the skeleton summary, not from a dedicated field evidence ref
    // UNRESOLVED: The exact role of global dword_8AFE88 (skeleton labels it collision-geometry presence) is not verifiable from this packet beyond acting as a non-zero gate
    // UNRESOLVED: The count 52 is a literal loop bound with no structural meaning documented in the packet
}
