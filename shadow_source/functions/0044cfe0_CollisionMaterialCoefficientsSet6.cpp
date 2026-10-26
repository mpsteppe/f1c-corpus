// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CFE0
// Canonical corpus name: CollisionMaterialCoefficientsSet6
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionMaterialCoefficientsSet6_0044cfe0.c

void UnknownObject::CollisionMaterialCoefficientsSet6()
{
    // Straight-line initializer that writes two fixed collision-material coefficient literals into globals (dword_7CC9EC = 40, flt_7CC9F0 = 0.0) then calls a helper named FloatFloatInitTo in the raw decompilation.
    // ASSIGNMENT: Write literal 40 into global dword_7CC9EC. [global:0x007CC9EC, source:raw]
    // ASSIGNMENT: Write float literal 0.0 into global flt_7CC9F0. [global:0x007CC9F0, source:raw]
    // CALL: Call helper function FloatFloatInitTo() with no arguments. [source:raw, function:0x0044CFE0]

    // Conservative worker pseudocode:
    //   void CollisionMaterialCoefficientsSet6(void) {
    //     dword_7CC9EC = 40;
    //     flt_7CC9F0 = 0.0f;
    //     FloatFloatInitTo();
    //   }
    // UNRESOLVED: Callee FloatFloatInitTo is absent from the packet callees list; its target address is unknown and no evidence_ref exists for it.
    // UNRESOLVED: Semantic role of globals dword_7CC9EC / flt_7CC9F0 within collision-material configuration is not established by this packet.
}
