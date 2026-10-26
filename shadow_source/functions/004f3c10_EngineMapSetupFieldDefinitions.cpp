// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F3C10
// Canonical corpus name: EngineMapSetupFieldDefinitions
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EngineMapSetupFieldDefinitions_004f3c10.c

void UnknownObject::EngineMapSetupFieldDefinitions()
{
    // Engine map field-definition registration. For a single 'this' object a2 (the parser target) and an engine map a1, registers three range/setting pairs with CRTMathHelper_e1f0 (0x42E1F0): rev-limit range/setting at a2+5488 with scale 0.1047197551196598, engine-map range/setting at a2+5552 with scale 1.0, and engine-braking-multiplier range/setting at a2+5616 with scale 1.0. Returns the result of the last registration call. Each call pairs a range string with a setting string global.
    // CALL: CRTMathHelper_e1f0(a2 + 5488, a1, aRevlimitrange, aRevlimitsettin, 0.1047197551196598): register the rev-limit range/setting pair with an RPM-scale factor. [callee:0x0042E1F0, global:0x005D5508, global:0x005D5518, source:raw]
    // CALL: CRTMathHelper_e1f0(a2 + 5552, a1, aEnginemaprange, aEnginemapsetti, 1.0): register the engine-map range/setting pair with unit scale. [callee:0x0042E1F0, global:0x005D54E4, global:0x005D54F4, source:raw]
    // CALL: CRTMathHelper_e1f0(a2 + 5616, a1, aEnginebrakingm_0, aEnginebrakingm, 1.0): register the engine-braking-multiplier range/setting pair with unit scale. [callee:0x0042E1F0, global:0x005D54B4, global:0x005D54CC, source:raw]
    // RETURN: Return the result of the final CRTMathHelper_e1f0 call. [callee:0x0042E1F0, source:raw]
    // CALL: Invoked during HDV file parsing by EngineSectionParser (004F3C80) and TheSvmHdvVehicleFileParser (004F4270). [caller:0x004F3C80, caller:0x004F4270]

    // Conservative worker pseudocode:
    //   int sub_4F3C10(int map, char *this) {
    //     CRTMathHelper_e1f0(this + 5488, map, aRevlimitrange, aRevlimitsettin, 0.1047197551196598);
    //     CRTMathHelper_e1f0(this + 5552, map, aEnginemaprange, aEnginemapsetti, 1.0);
    //     return CRTMathHelper_e1f0(this + 5616, map, aEnginebrakingm_0, aEnginebrakingm, 1.0);
    //   }
    // UNRESOLVED: CRTMathHelper_e1f0 (0x42E1F0) semantics are not shown in this packet; the exact meaning of the scale factors (0.1047197551196598) is unverified from evidence alone.
    // UNRESOLVED: The target pointer a2 is reached via byte offsets +5488/+5552/+5616 that have no field evidence refs; the layout they index is not defined here.
}
