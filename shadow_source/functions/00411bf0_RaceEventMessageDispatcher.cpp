// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00411BF0
// Canonical corpus name: RaceEventMessageDispatcher
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RaceEventMessageDispatcher_00411bf0.c

void UnknownObject::RaceEventMessageDispatcher()
{
    // Dispatches a race/event message to a name- or attribute-lookup handler based on the event ID read from the state block at a2+12. A random flag v4 (RandLCGRandomNumberGenerator() % 2) is computed up front and selects the random-string variant of SessionStringNameLookup for the first case group. Each case group routes to one of: SessionStringNameLookup (several groups, differing only in the final flag argument), sub_412490, sub_412E50, TextAttributeLookup, TextAttributeLookup_3710, or MapCollisionShapeToBoneIndex, always passing a4, a1, the value at a3+16, and 1 as fixed arguments. Unrecognized event IDs fall through to the default and return 0. Called by FontRenderingPrep.
    // CALCULATION: Computes v4 = RandLCGRandomNumberGenerator() % 2, the random flag used by the first case group's SessionStringNameLookup variant [callee:0x005884ED, source:raw]
    // STATE_TRANSITION: Switch on the event ID read from *(a2 + 12), compiled through jump table jpt_411C29 and case table byte_411D6C; unrecognized IDs hit the default and return 0 [global:0x00411D44, global:0x00411D6C, source:raw]
    // CALL: Case group 3, 5, 6, 9, 0xA, 0xD, 0x13, 0x16, 0x17, 0x18, 0x26, 0x29, 0x2D, 0x30, 0x32, 0x35, 0x36, 0x37: SessionStringNameLookup(a4, a1, *(a3+16), 1, v4 == 0) [callee:0x004122C0, source:raw]
    // CALL: Case group 8, 0xF, 0x21: sub_412490(a4, a1, *(a3+16), 1, 0) [callee:0x00412490, source:raw]
    // CALL: Case group 0xB, 0xC, 0x33: sub_412E50(a4, a1, *(a3+16), 1) [callee:0x00412E50, source:raw]
    // CALL: Case group 0x11, 0x1F, 0x20, 0x2A, 0x2B, 0x34: SessionStringNameLookup(a4, a1, *(a3+16), 1, 0) [callee:0x004122C0, source:raw]
    // CALL: Case group 0x12, 0x19, 0x1A, 0x1B, 0x1D, 0x1E, 0x2E: TextAttributeLookup(a4, a1, *(a3+16), 1) [callee:0x004133B0, source:raw]
    // CALL: Case group 0x15, 0x1C: SessionStringNameLookup(a4, a1, *(a3+16), 1, 1) [callee:0x004122C0, source:raw]
    // CALL: Case group 0x27, 0x28: TextAttributeLookup_3710(a4, a1, *(a3+16), 1) [callee:0x00413710, source:raw]
    // CALL: Case 0x31: MapCollisionShapeToBoneIndex(a4, a1, *(a3+16), 1) [callee:0x00412C30, source:raw]
    // RETURN: Returns the result of whichever handler ran, or 0 for the default/unrecognized-ID path [source:raw]
    // CALL: Invoked by FontRenderingPrep (00411840) as part of the rendering/UI message pass [caller:0x00411840, source:raw]

    // Conservative worker pseudocode:
    //   v4 = RandLCGRandomNumberGenerator() % 2;
    //   switch (*(a2 + 12)) {
    //     case 3: case 5: case 6: case 9: case 0xA: case 0xD: case 0x13:
    //     case 0x16: case 0x17: case 0x18: case 0x26: case 0x29: case 0x2D:
    //     case 0x30: case 0x32: case 0x35: case 0x36: case 0x37:
    //       return SessionStringNameLookup(a4, a1, *(a3+16), 1, v4 == 0);
    //     case 8: case 0xF: case 0x21: return sub_412490(a4, a1, *(a3+16), 1, 0);
    //     case 0xB: case 0xC: case 0x33: return sub_412E50(a4, a1, *(a3+16), 1);
    //     case 0x11: case 0x1F: case 0x20: case 0x2A: case 0x2B: case 0x34:
    //       return SessionStringNameLookup(a4, a1, *(a3+16), 1, 0);
    //     case 0x12: case 0x19: case 0x1A: case 0x1B: case 0x1D: case 0x1E: case 0x2E:
    //       return TextAttributeLookup(a4, a1, *(a3+16), 1);
    //     case 0x15: case 0x1C: return SessionStringNameLookup(a4, a1, *(a3+16), 1, 1);
    //     case 0x27: case 0x28: return TextAttributeLookup_3710(a4, a1, *(a3+16), 1);
    //     case 0x31: return MapCollisionShapeToBoneIndex(a4, a1, *(a3+16), 1);
    //     default: return 0;
    //   }
    // UNRESOLVED: The object types behind a1, a2, a3 and a4 and the meaning of the event ID at a2+12 (which event codes map to which message text) are not established
    // UNRESOLVED: The passed-through value at a3+16 and the constant argument 1 are uninterpreted without the handler definitions
    // UNRESOLVED: Why the random flag v4 applies only to the first case group while later groups hard-code the flag is not determinable from this packet
}
