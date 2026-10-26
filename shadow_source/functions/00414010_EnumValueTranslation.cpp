// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00414010
// Canonical corpus name: EnumValueTranslation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EnumValueTranslation_00414010.c

void UnknownObject::EnumValueTranslation()
{
    // stdcall mapper that translates an input enum value a2 in the range 1..22 into a translated literal 113..134 (a2 + 112) via a jump-table switch, writes the translated value to the record at a1+8 and the result of sub_414180(0) to a1+12, then returns 1. For any other a2 the record is left untouched and -1 is returned. Called from FontCharacterRenderDispatcher (00411DB0) and SoundEventDispatcher (00411E90); existing analysis suggests a sound-event mapping role but that is prose, not packet evidence.
    // ASSIGNMENT: Initializes result to -1 as the default return status before the switch [source:raw]
    // GUARD: Switch dispatch on a2 through the jump table jpt_414021: cases 1..22 reach the translation path, the default case returns result (-1) immediately without writing the record [global:0x004140E4, source:raw]
    // CALCULATION: Maps the case value to a translated literal: case 1..22 yields v3 = 113..134 (a2 + 112) [source:raw]
    // ASSIGNMENT: Writes the translated literal v3 to the dword at a1+8 [field:this:0x00000008, source:raw]
    // CALL: Calls sub_414180(0) to compute a secondary value stored alongside the translation [callee:0x00414180, source:raw]
    // ASSIGNMENT: Writes the sub_414180(0) result to the dword at a1+12 [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Sets result to 1 to mark a successful translation on the matched path [source:raw]
    // RETURN: Returns result: 1 after a matched translation, -1 on the default path [source:raw]

    // Conservative worker pseudocode:
    //   int EnumValueTranslation(int a1, int a2) {
    //     int result = -1;
    //     switch (a2) {
    //       case 1: case 2: /* ... * / case 22:
    //         *(int*)(a1 + 8) = a2 + 112;
    //         *(int*)(a1 + 12) = sub_414180(0);
    //         result = 1;
    //         break;
    //       default:
    //         return result;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The semantic meaning of the translated range 113..134 and of the secondary value from sub_414180(0) is not evidenced by this packet (existing analysis suggests sound-event mapping, unverified)
    // UNRESOLVED: Why sub_414180(0) is always called with the constant argument 0
    // UNRESOLVED: The identity and type of the output record at a1 is unknown
}
