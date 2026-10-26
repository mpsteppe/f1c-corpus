// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00411E90
// Canonical corpus name: SoundEventDispatcher
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SoundEventDispatcher_00411e90.c

void UnknownObject::SoundEventDispatcher()
{
    // Sound event dispatcher. Reads an event ID from *(a2 + 12) and switches on it, routing each ID to a dedicated handler invoked as handler(a4, a1, params[i], 0[, flag]). The params index used (a3[4], a3[5] or a3[6]) and the trailing flag vary per event ID. A random even/odd variant flag v6 is computed from two RandLCGRandomNumberGenerator calls before dispatch. Default case assigns result 0; case 0x2C returns the initialized default -1. Dispatched by FontRenderingPrep (0x00411840) and marked as on the audio subsystem.
    // ASSIGNMENT: Initialize defaultResult v4 = -1; this is the value returned when a case falls through to LABEL_26 without overwriting result, notably case 0x2C. [function:0x00411E90, source:raw]
    // CALCULATION: Compute randomEvenFlag v6 = (RandLCGRandomNumberGenerator() % 2 == 0), then call RandLCGRandomNumberGenerator() a second time with the result discarded. v6 is passed as the variant flag to SessionStringNameLookup calls. [callee:0x005884ED, source:raw]
    // GUARD: Read event ID from *(a2 + 12) and switch on it. Dispatch is compiled through jump table jpt_411ED0 (0x00412218) with case-value table byte_412280 (0x00412280). [global:0x00412218, global:0x00412280, source:raw]
    // CALL: SessionStringNameLookup(a4, a1, params[i], 0, flag): cases 4 and 0x2F with params[4] and flag v6; cases 8, 9, 0xC and 0x33 with params[5] and flag v6; cases 0xD and 0x1C with params[5] and flag 0; case 0x25 with params[4] and flag 0. [callee:0x004122C0, source:raw]
    // CALL: sub_412490(a4, a1, params[i], 0, flag): cases 5, 0xA and 0x17 with params[5] and flag 1; cases 6, 0x1B, 0x1D, 0x26, 0x35 and 0x36 with params[5] and flag 0; case 0x10 with params[4] and flag 0; cases 0x22 and 0x23 with params[4] and flag 1. [callee:0x00412490, source:raw]
    // CALL: sub_412E50(a4, a1, params[i], 0): case 0xE with params[4]; cases 0x13 and 0x29 with params[5]. [callee:0x00412E50, source:raw]
    // CALL: TextAttributeLookup(a4, a1, params[5], 0): case 0x1E. [callee:0x004133B0, source:raw]
    // CALL: TextAttributeLookup_3600(a4, a1, params[i], 0): case 1 with params[4]; cases 0x18 and 0x19 with params[5]. [callee:0x00413600, source:raw]
    // CALL: TextAttributeLookup_3710(a4, a1, params[i], 0): case 2 with params[4]; cases 0x16 and 0x1A with params[5]. [callee:0x00413710, source:raw]
    // CALL: sub_413820(a4, a1, params[i], 0): case 0x1F with params[5]; case 0x2A with params[6]. [callee:0x00413820, source:raw]
    // CALL: CollisionShapeSizeClassify(a4, a1, params[i], 0): case 0x20 with params[5]; case 0x2B with params[6]. [callee:0x004139C0, source:raw]
    // CALL: SeasonSpecificTeamIDLookup(a4, a1, params[i], 0): case 0x14 with params[4]; case 0x30 with params[5]. [callee:0x00413B60, source:raw]
    // CALL: EnumValueTranslation(a4, params[5]): cases 0x11 and 0x34. [callee:0x00414010, source:raw]
    // CALL: MapCollisionShapeToBoneIndex(a4, a1, params[5], 0): case 0x32. [callee:0x00412C30, source:raw]
    // RETURN: Return the handler result. Default case sets result = 0 then falls to LABEL_26; case 0x2C returns defaultResult v4 = -1. [source:raw]

    // Conservative worker pseudocode:
    //   v4 = -1;
    //   v6 = RandLCGRandomNumberGenerator() % 2 == 0;
    //   RandLCGRandomNumberGenerator();
    //   switch (*(a2 + 12)) {
    //     case 1:  result = TextAttributeLookup_3600(a4, a1, a3[4], 0); break;
    //     case 2:  result = TextAttributeLookup_3710(a4, a1, a3[4], 0); break;
    //     case 4: case 0x2F: result = SessionStringNameLookup(a4, a1, a3[4], 0, v6); break;
    //     case 5: case 0xA: case 0x17: result = sub_412490(a4, a1, a3[5], 0, 1); break;
    //     case 6: case 0x1B: case 0x1D: case 0x26: case 0x35: case 0x36: result = sub_412490(a4, a1, a3[5], 0, 0); break;
    //     case 8: case 9: case 0xC: case 0x33: result = SessionStringNameLookup(a4, a1, a3[5], 0, v6); break;
    //     case 0xD: case 0x1C: result = SessionStringNameLookup(a4, a1, a3[5], 0, 0); break;
    //     case 0xE: result = sub_412E50(a4, a1, a3[4], 0); break;
    //     case 0x10: result = sub_412490(a4, a1, a3[4], 0, 0); break;
    //     case 0x11: case 0x34: result = EnumValueTranslation(a4, a3[5]); break;
    //     case 0x13: case 0x29: result = sub_412E50(a4, a1, a3[5], 0); break;
    //     case 0x14: result = SeasonSpecificTeamIDLookup(a4, a1, a3[4], 0); break;
    //     case 0x16: case 0x1A: result = TextAttributeLookup_3710(a4, a1, a3[5], 0); break;
    //     case 0x18: case 0x19: result = TextAttributeLookup_3600(a4, a1, a3[5], 0); break;
    //     case 0x1E: result = TextAttributeLookup(a4, a1, a3[5], 0); break;
    //     case 0x1F: result = sub_413820(a4, a1, a3[5], 0); break;
    //     case 0x20: result = CollisionShapeSizeClassify(a4, a1, a3[5], 0); break;
    //     case 0x22: case 0x23: result = sub_412490(a4, a1, a3[4], 0, 1); break;
    //     case 0x25: result = SessionStringNameLookup(a4, a1, a3[4], 0, 0); break;
    //     case 0x2A: result = sub_413820(a4, a1, a3[6], 0); break;
    //     case 0x2B: result = CollisionShapeSizeClassify(a4, a1, a3[6], 0); break;
    //     case 0x2C: goto LABEL_26;
    //     case 0x30: result = SeasonSpecificTeamIDLookup(a4, a1, a3[5], 0); break;
    //     case 0x32: result = MapCollisionShapeToBoneIndex(a4, a1, a3[5], 0); break;
    //     default: v4 = 0; LABEL_26: result = v4; break;
    //   }
    //   return result;
    // UNRESOLVED: Owner object unknown: the type containing this dispatcher and the meanings of a1, a2 (eventBlock), a3 (params) and a4 are not established by the packet.
    // UNRESOLVED: Semantics of the event ID enum at *(a2 + 12) (values 1..0x36) are not defined by the packet.
    // UNRESOLVED: Purpose of the second discarded RandLCGRandomNumberGenerator() call and of the variant flag v6 is not established.
    // UNRESOLVED: Meaning of the differing params indices (a3[4], a3[5], a3[6]) and the trailing flag (0/1/v6) per event ID is not established.
}
