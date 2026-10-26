// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F24F0
// Canonical corpus name: VehicleDamageModel
// Owner: Vehicle_Damage_Model [DERIVED]
// Raw source: functions/VehicleDamageModel_004f24f0.c

void Vehicle_Damage_Model::ParseVehicleDamageConfig()
{
    // Parses a vehicle damage configuration stream: opens it in binary-read mode, locates the Physical subsection, and reads collision/detach/aero/random-damage parameters into a flat struct (this) covering general physics, front wing, rear wing, four wheels and eight detachable body parts. Wheel and part blocks are iterated with generated keys. Ends with stream cleanup; returns 0 on success, -1 when the stream cannot be opened.
    // GUARD: Initialize local state: zero-init v11 via ZeroInitSmallStruct, clear the 384-byte token buffer, zero counters and set a running flag. Open the damage stream with AudioStreamOpen(a2, 0); on failure free v11 via SubCallWithConditionalFieldFree and return -1. [callee:0x005668B0, callee:0x00566B20, callee:0x005668D0, source:raw]
    // LOOP: Outer loop gated by ConditionalDispatchBasedOnFlag on the 384-byte buffer. Inside, if the current line is a data line (sub_5651B0 returns 0), matches the Physical header (sub_587C20 on aPhysical), and the buffer is still dispatchable, enter the inner do/while loop that decodes each Physical line with sub_5651B0 (1 = end-of-section break). [callee:0x00566CC0, callee:0x005651B0, callee:0x00587C20, global:0x005D5020, source:raw]
    // CALL: Parse the physical scalar block via sub_565870 into sequential this-relative slots: RadiusAdd -> this+0, RadiusMult -> this+4, RadiusMax -> this+8, Engine -> this+12, AeroDiv -> this+16, AeroMin -> this+20, VertMult -> this+24, FrontWingDetach -> this+28, FrontWingRandom -> this+32, FrontWingPos triple -> this+36/40/44, FrontWingMassInertia quad -> this+48/52/56/60, FrontWingCollParams triple -> this+64/68/72, RearWingDetach -> this+76, RearWingRandom -> this+80, RearWingPos triple -> this+84/88/92, RearWingMassInertia quad -> this+96/100/104/108, RearWingCollParams triple -> this+112/116/120, WheelBend -> this+124, WheelDetach -> this+128, WheelRandom -> this+132. [callee:0x00565870, global:0x005D5014, global:0x005D5008, global:0x005D4FFC, global:0x005C316C, global:0x005D4FF4, global:0x005D4FEC, global:0x005D4FE0, global:0x005D4FD0, global:0x005D4FC0, global:0x005D4FB0, global:0x005D4F98, global:0x005D4F84, global:0x005D4F74, global:0x005D4F64, global:0x005D4F58, global:0x005D4F44, global:0x005D4F30, global:0x005D4F24, global:0x005D4F18, global:0x005D4F0C, source:raw]
    // LOOP: Wheel block loop (4 iterations, cursor v6 advancing 28 bytes from this+144): build "Wheel%dMassInertia" and "Wheel%dCollParams" keys with StringFormatWithBufferOverflowCheck, then parse each key with sub_565870 into four then three consecutive floats (v6-8..v6+4 and v6+8..v6+16). [callee:0x0058815F, callee:0x00565870, source:raw]
    // LOOP: Detachable part loop (8 iterations): build "Part%dDetach" (v10-32), "Part%dRandom" (v10), "Part%dPos" (v9-4, v9, v9+4), "Part%dMassInertia" (v8-8..v8+4) and "Part%dCollParams" (v8+8..v8+16) keys with StringFormatWithBufferOverflowCheck, parsing each via sub_565870; cursors step +4 (v10, from this+280), +12 (v9, from this+316) and +28 (v8, from this+416). [callee:0x0058815F, callee:0x00565870, source:raw]
    // RETURN: After parsing: close the stream with ConditionalFileHandleCloseWithFlagDispatch, free v11 via SubCallWithConditionalFieldFree, and return 0. Invoked by TheSvmHdvVehicleFileParser to parse the vehicle's damage .ini. [callee:0x00566B90, callee:0x005668D0, caller:0x004F4270, function:0x004F24F0, source:raw]

    // Conservative worker pseudocode:
    //   init(); if (!AudioStreamOpen(a2, 0)) { free(v11); return -1; }
    //   while (ConditionalDispatchBasedOnFlag(buf, 384)) {
    //       if (sub_5651B0(line) == 0 && sub_587C20(buf, "Physical") && ConditionalDispatchBasedOnFlag(buf, 384)) {
    //           while ((t = sub_5651B0(line)) != 1) {
    //               if (t == 0) {
    //                   parse_physical_scalars(this);
    //                   for (i = 0; i < 4; i++) parse_wheel_block(this + 144 + 28*i);
    //                   for (j = 0; j < 8; j++) parse_part_block(this + 280 + 4*j, this + 316 + 12*j, this + 416 + 28*j);
    //               }
    //           }
    //       }
    //   }
    //   close(v11); free(v11); return 0;
    // UNRESOLVED: Seven key-template globals (aPartDcollparam, aPartDmassinert, aPartDpos, aPartDrandom, aPartDdetach, aWheelDcollpara, aWheelDmassiner) are listed as referenced but do not appear directly in the decompiled body; they are likely the Wheel%d/Part%d key templates built with StringFormatWithBufferOverflowCheck, but that mapping is unconfirmed.
    // UNRESOLVED: Owner identity is DERIVED from the LEGACY ABI lead Vehicle_Damage_Model; no confirmed class symbol is present in the packet.
}
