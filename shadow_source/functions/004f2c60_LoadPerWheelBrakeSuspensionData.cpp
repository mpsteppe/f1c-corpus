// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F2C60
// Canonical corpus name: PerWheelBrakeSuspensionDataLoader
// Owner: PerWheelBrakeSuspensionDataLoader [DERIVED]
// Raw source: functions/PerWheelBrakeSuspensionDataLoader_004f2c60.c

void PerWheelBrakeSuspensionDataLoader::LoadPerWheelBrakeSuspensionData()
{
    // Parses per-wheel brake and suspension configuration data from a vehicle setup file stream (handle 384). Loops reading tokens with LineInputReader(384); a per-line delimiter check via sub_5651B0(a4) breaks on end-of-section and skips the parse on other non-data results. On a data line it populates a double array (this) with bump/rebound travel, bump-stop spring/rising/damper, stage-2 bump/rebound, friction torque, brake torque, wear rate, failure, optimum temperature, fade range, disc inertia, heating, cooling, duct cooling, spin inertia, CG offset X and pushrod spindle/body values via sub_565AA0, converting brake optimum temperature from Celsius to Kelvin (+273.16). It then normalizes 11 per-wheel range/setting pairs (camber, pressure, ride height, packer, spring, slow/fast bump, slow/fast rebound, brake disc, brake pad) into the corner block (stride 704 from a5, wheel index a2) via CRTMathHelper_e1f0 with a deg->rad multiplier for camber.
    // LOOP: Outer token loop: read the next token/line with LineInputReader(384); a zero return ends the loop. [callee:0x005351D0, source:raw]
    // GUARD: Per-line delimiter check via sub_5651B0(a4): return 1 breaks the loop (end-of-section); a non-zero non-1 result continues the outer loop without parsing; 0 means a valid data line to process. [callee:0x005651B0, source:raw]
    // CALL: On a data line, parse 12 scalar brake/suspension doubles into the this double-array via sub_565AA0: bump travel (this[0]), rebound travel (this[1]), bump-stop spring (this[2]), bump-stop rising (this[3]), bump-stop damper (this[4]), bump-stop rising_0 (this[5]), bump stage2 (this[6]), rebound stage2 (this[7]), friction torque (this[21]), brake torque (this[22]), brake wear rate (this[30]), spin inertia (this[18]), CG offset X (this[8]). [callee:0x00565AA0, global:0x005D52F0, global:0x005D52E0, global:0x005D52D0, global:0x005D52B8, global:0x005D52A8, global:0x005D5290, global:0x005D5284, global:0x005D5274, global:0x005D5264, global:0x005D5258, global:0x005D5248, global:0x005D51C0, global:0x005D51B4, source:raw]
    // CALL: Parse brake failure into two destinations this[31] and this[32] via sub_565AA0. [callee:0x00565AA0, global:0x005D5238, source:raw]
    // CALCULATION: Parse brake optimum temperature (Celsius) into this[23] (field this+0xB8); when the parse succeeds, convert Celsius to Kelvin by adding 273.16. [callee:0x00565AA0, global:0x005D5224, field:this:0x000000B8, global:0x0059EAC8, source:raw]
    // CALL: Parse brake fade range (this[24]), brake disc inertia (this[29]), brake heating (this[25]) and brake duct cooling (this[28]) via sub_565AA0. [callee:0x00565AA0, global:0x005D5214, global:0x005D5200, global:0x005D51F0, global:0x005D51CC, source:raw]
    // CALL: Parse brake cooling into two destinations this[26] and this[27] via sub_565AA0. [callee:0x00565AA0, global:0x005D51E0, source:raw]
    // CALL: Parse pushrod spindle into this[9..11] and pushrod body into this[12..14] (three destinations each) via sub_565AA0. [callee:0x00565AA0, global:0x005D51A4, global:0x005D5198, source:raw]
    // CALCULATION: Normalize 11 per-wheel range/setting string pairs into the corner block (v7 = 704 * a2 + a5) via CRTMathHelper_e1f0, with the conversion multiplier 0.0174532925199433 (deg->rad) for camber and 1.0 for the rest: camber(+176), pressure(+240), ride height(+304), packer(+368), spring(+432), slow bump(+496), fast bump(+560), slow rebound(+624), fast rebound(+688), brake disc(+752), brake pad(+816). [callee:0x0042E1F0, global:0x005D517C, global:0x005D5188, global:0x005D515C, global:0x005D516C, global:0x005D5138, global:0x005D5148, global:0x005D511C, global:0x005D5128, global:0x005D5100, global:0x005D510C, global:0x005D50E0, global:0x005D50F0, global:0x005D50C0, global:0x005D50D0, global:0x005D5098, global:0x005D50AC, global:0x005D5070, global:0x005D5084, global:0x005D504C, global:0x005D505C, global:0x005D502C, global:0x005D503C, source:raw]
    // RETURN: Return the last line token status (1 on end-of-section break, else the final LineInputReader/sub_5651B0 result). [function:0x004F2C60, source:raw]

    // Conservative worker pseudocode:
    //   while ((result = LineInputReader(384)) != 0) {
    //       result = sub_5651B0(a4);
    //       if (result == 1) break;
    //       if (result != 0) continue;
    //       /* scalar doubles * /
    //       parse_double(aBumptravel,     this[0]);
    //       parse_double(aReboundtravel,  this[1]);
    //       parse_double(aBumpstopspring, this[2]);
    //       parse_double(aBumpstoprising, this[3]);
    //       parse_double(aBumpstopdamper, this[4]);
    //       parse_double(aBumpstoprising_0, this[5]);
    //       parse_double(aBumpstage2,     this[6]);
    //       parse_double(aReboundstage2,  this[7]);
    //       parse_double(aFrictiontorque, this[21]);
    //       parse_double(aBraketorque,    this[22]);
    //       parse_double(aBrakewearrate,  this[30]);
    //       parse_double(aBrakefailure,   this[31], this[32]);
    //       if (parse_double(aBrakeoptimumte, this[23]))
    //           this[23] += 273.16;
    //       parse_double(aBrakefaderange, this[24]);
    //       parse_double(aBrakediscinert, this[29]);
    //       parse_double(aBrakeheating,   this[25]);
    //       parse_double(aBrakecooling,   this[26], this[27]);
    //       parse_double(aBrakeductcooli, this[28]);
    //       parse_double(aSpininertia,    this[18]);
    //       parse_double(aCgoffsetx,      this[8]);
    //       parse_double(aPushrodspindle, this[9], this[10], this[11]);
    //       parse_double(aPushrodbody,    this[12], this[13], this[14]);
    //       v7 = 704 * a2 + a5;
    //       range_setting(v7+176, camber,  0.0174532925199433);
    //       range_setting(v7+240, pressure, 1.0);
    //       range_setting(v7+304, rideheight, 1.0);
    //       range_setting(v7+368, packer,   1.0);
    //       range_setting(v7+432, spring,   1.0);
    //       range_setting(v7+496, slowbump, 1.0);
    //       range_setting(v7+560, fastbump, 1.0);
    //       range_setting(v7+624, slowrebound, 1.0);
    //       range_setting(v7+688, fastrebound, 1.0);
    //       range_setting(v7+752, brakedisc, 1.0);
    //       range_setting(v7+816, brakepad,  1.0);
    //   }
    //   return result;
    // UNRESOLVED: The this double-array element-to-physical-parameter mapping is DERIVED from the token name prefixes; only this+0xB8 (brake optimum temperature) has a packet field record.
    // UNRESOLVED: The 704-byte corner-block stride and the offsets 176..816 within it are observed from the decompiled body but are not evidenced by packet field records.
    // UNRESOLVED: Argument roles are partially inferred: a4 is the shared token stream, a5 the corner block base and a2 the wheel/corner index; a3 is unused in the visible body.
    // UNRESOLVED: dbl_59EAC8 is listed as a read global; it is carried here as the source of the 273.16 Celsius-to-Kelvin offset (the decompiled body shows the literal inline).
}
