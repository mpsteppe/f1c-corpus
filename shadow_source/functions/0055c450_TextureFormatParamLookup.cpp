// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055C450
// Canonical corpus name: sub_55C450
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55C450_0055c450.c

void UnknownObject::TextureFormatParamLookup()
{
    // Pure lookup table for texture/surface format codes. Given an input format key a1, writes two derived parameters into caller-provided outputs *a2 and *a3 (bit depth / block size and an auxiliary parameter). Small format codes 20-25 and 40-41 map to (bit depth, aux) pairs; the five large FourCC codes 827611204, 844388420, 861165636, 877942852 and 894720068 map to (1, 9/10/11/12/13); any other value yields (0, 0).
    // CALCULATION: Dispatch on a1 through the jump table jpt_55C46F: values at or below 40 take a small-code switch; the large FourCC constants take their own comparisons; anything else falls through to the default. [global:0x0055C630]
    // ASSIGNMENT: a1 == 20: *a2 = 24, *a3 = 7. [global:0x0055C630]
    // ASSIGNMENT: a1 == 21: *a2 = 32, *a3 = 8. [global:0x0055C630]
    // ASSIGNMENT: a1 == 22: *a2 = 32, *a3 = 7. [global:0x0055C630]
    // ASSIGNMENT: a1 == 23: *a2 = 16, *a3 = 6. [global:0x0055C630]
    // ASSIGNMENT: a1 == 24 or a1 == 25: *a2 = 16, *a3 = 5. [global:0x0055C630]
    // ASSIGNMENT: a1 == 40 or a1 == 41: *a2 = 8, *a3 = 4. [global:0x0055C630]
    // ASSIGNMENT: a1 == 827611204: *a2 = 1, *a3 = 9. [global:0x0055C630]
    // ASSIGNMENT: a1 == 844388420: *a2 = 1, *a3 = 10. [global:0x0055C630]
    // ASSIGNMENT: a1 == 861165636: *a2 = 1, *a3 = 11. [global:0x0055C630]
    // ASSIGNMENT: a1 == 877942852: *a2 = 1, *a3 = 12. [global:0x0055C630]
    // ASSIGNMENT: a1 == 894720068: *a2 = 1, *a3 = 13. [global:0x0055C630]
    // ASSIGNMENT: Default (unknown a1): *a2 = 0, *a3 = 0. [global:0x0055C630]

    // Conservative worker pseudocode:
    //   switch (a1) {
    //     case 20:        *a2 = 24; *a3 = 7;  break;
    //     case 21:        *a2 = 32; *a3 = 8;  break;
    //     case 22:        *a2 = 32; *a3 = 7;  break;
    //     case 23:        *a2 = 16; *a3 = 6;  break;
    //     case 24: case 25: *a2 = 16; *a3 = 5; break;
    //     case 40: case 41: *a2 = 8;  *a3 = 4;  break;
    //     case 827611204: *a2 = 1;  *a3 = 9;  break;
    //     case 844388420: *a2 = 1;  *a3 = 10; break;
    //     case 861165636: *a2 = 1;  *a3 = 11; break;
    //     case 877942852: *a2 = 1;  *a3 = 12; break;
    //     case 894720068: *a2 = 1;  *a3 = 13; break;
    //     default:        *a2 = 0;  *a3 = 0;  break;
    //   }
    // UNRESOLVED: The semantic meaning of the two output values (bit depth vs. block size vs. format-family tag) is not established by this packet.
    // UNRESOLVED: The small format codes 20-25/40-41 and their mapping to specific pixel formats are not identified.
    // UNRESOLVED: The large FourCC constants match those handled by the texture-surface format initializer wrapper, but the relationship between the two lookup schemes is unconfirmed.
    // UNRESOLVED: No callers or callees are recorded in the packet, so the wider use context of the outputs is unknown.
}
