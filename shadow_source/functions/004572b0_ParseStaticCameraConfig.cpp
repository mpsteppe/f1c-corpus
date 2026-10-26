// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004572B0
// Canonical corpus name: sub_4572B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4572B0_004572b0.c

void UnknownObject::ParseStaticCameraConfig()
{
    // __thiscall config parser for a static camera/scene descriptor. It accumulates key-value pairs (position, orientation, a positional size pair, color, clip planes, LOD multiplier, size, center, mipmap LOD bias, flags, clear flag, activation location and radius) into local accumulators, gated by ConditionalDispatchBasedOnFlag on a per-iteration flag buffer, and on flush writes every value into the camera descriptor at this: near/far clip, screen/position values, LOD, center, size, color, flags, enabled flag and the position vector. Returns 0 on flush, 1 when the scanner reports a stop code.
    // ASSIGNMENT: Zero-initialize all locals: memset the v49 flag buffer (384 bytes), zero int accumulators v40..v42/v24..v26/v28/v30/v32/v34/v35/v44/v46/v47/v48, zero float accumulators v22/v23/v27/v31/v33/v36/v37/v38/v39, set v29 = 1.0, and set flags v45 = 1 and v21 = 1 (clear flag default). [source:raw]
    // GUARD: Evaluate ConditionalDispatchBasedOnFlag(v49, 384): when false, skip the parse loop entirely and go straight to the flush path (LABEL_10). [callee:0x00566CC0, source:raw]
    // LOOP: Token read loop: sub_5651B0(v43) reads the next config line/token; a non-zero result terminates the loop and selects the flush or return path by its code. [callee:0x005651B0, source:raw]
    // CALL: Parse key-value tokens into local accumulators via sub_565870/sub_565760: aPosition -> v40/v41/v42, aOrientation -> v24/v25/v26, off_5C57FC -> v22/v23, aColor -> v35/v28/v30, aClipplanes -> v33/v36, aLodmultiplier -> v29, aSize -> v38/v31, aCenter -> v37/v27, aMipmaplodbias -> v39, aFlags1 -> v32, aFlags2 -> v34. [callee:0x00565870, callee:0x00565760, global:0x005C59D4, global:0x005C59C8, global:0x005C57FC, global:0x005C57F4, global:0x005C57E8, global:0x005C57D8, global:0x005C57D0, global:0x005C57C8, global:0x005C57B8, global:0x005C57B0, global:0x005C57A8, source:raw]
    // CALL: Parse the aClear token: sub_565520 reads a string into v50 and, when it equals aFalse, clears the v21 clear-flag. [callee:0x00565520, global:0x005C57A0, global:0x005C5798, source:raw]
    // CALL: Parse the activation tokens directly into this: aActivationloca -> this+124/this+128/this+132 and aActivationradi -> this+136. [callee:0x00565870, global:0x005C59B4, global:0x005C59A0, source:raw]
    // GUARD: Per-iteration re-check of ConditionalDispatchBasedOnFlag(v49, 384); when it turns false, fall through to the flush path (LABEL_10). [callee:0x00566CC0, source:raw]
    // STATE_TRANSITION: Scanner exit codes: result 2 -> flush path (LABEL_10); result 4 -> return 1 (stop); any other code -> continue scanning from LABEL_9. [callee:0x005651B0, source:raw]
    // CALL: Flush accumulated values into the camera descriptor: StringCopyWithBufferRealloc(a3) records the last token string; F_3VectorCopyToStruct(this, &v40) writes the position vector (this+0x90/0x94/0x98); VectorCopy(this, &v24) copies the orientation; then copy the parsed floats/ints: near/far clip to this+0x30/0x34 and again to this+0x40/0x44, off_5C57FC pair to this+0x38/0x3C and this+0x48/0x4C, clip LOD to this+0x50, size to this+0x54/0x58, center to this+0x5C/0x60, mipmap LOD bias to this+0x64, clear flag byte to this+0x68, color to this+0x70/0x74/0x78, flags to this+0x7C/0x80, and the enabled flag this+0x84 = 1. [callee:0x00566650, callee:0x00456110, callee:0x00456130, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, field:this:0x00000054, field:this:0x00000058, field:this:0x0000005C, field:this:0x00000060, field:this:0x00000064, field:this:0x00000068, field:this:0x0000006C, field:this:0x00000070, field:this:0x00000074, field:this:0x00000078, field:this:0x00000090, field:this:0x00000094, field:this:0x00000098, source:raw]
    // RETURN: Return 0 after a flush, or 1 when the scanner reports the stop code 4. [source:raw]
    // CALL: Invoked by StaticCameraSceneLoader (0x0040B030) to parse a static camera scene configuration. [caller:0x0040B030, source:raw]

    // Conservative worker pseudocode:
    //   int ParseStaticCameraConfig(int this, int a2, int a3) {
    //     zero(locals); flag_clear = 1; v29 = 1.0;
    //     if (!ConditionalDispatchBasedOnFlag(v49, 384)) goto FLUSH;
    //     for (;;) {
    //       int rc = sub_5651B0(v43);
    //       if (rc) break;
    //       sub_565870(aPosition,     &v40,&v41,&v42);
    //       sub_565870(aOrientation,  &v24,&v25,&v26);
    //       sub_565870(&off_5C57FC,   &v22,&v23);
    //       sub_565760(aColor,        &v35,&v28,&v30);
    //       sub_565870(aClipplanes,   &v33,&v36);
    //       sub_565870(aLodmultiplier,&v29);
    //       sub_565870(aSize,         &v38,&v31);
    //       sub_565870(aCenter,       &v37,&v27);
    //       sub_565870(aMipmaplodbias,&v39);
    //       sub_565760(aFlags1,       &v32);
    //       sub_565760(aFlags2,       &v34);
    //       if (sub_565520(aClear, v50)) if (!strcmp(v50, aFalse)) flag_clear = 0;
    //       sub_565870(aActivationloca, this+124, this+128, this+132);
    //       sub_565870(aActivationradi, this+136);
    //   FLUSHCHECK:
    //       if (!ConditionalDispatchBasedOnFlag(v49, 384)) goto FLUSH;
    //     }
    //     if (rc == 2) goto FLUSH;
    //     if (rc != 4) goto FLUSHCHECK;
    //     return 1;
    //   FLUSH:
    //     StringCopyWithBufferRealloc(a3);
    //     F_3VectorCopyToStruct(this, &v40);
    //     VectorCopy(this, &v24);
    //     *(float*)(this+48)=v22;  *(float*)(this+52)=v23;  *(float*)(this+56)=v22;  *(float*)(this+60)=v23;
    //     *(float*)(this+64)=v33;  *(float*)(this+68)=v36;  *(float*)(this+72)=v29;  *(float*)(this+76)=v38;
    //     *(float*)(this+80)=v31;  *(float*)(this+84)=v37;  *(float*)(this+88)=v27;  *(float*)(this+92)=v39;
    //     *(this+96)=v21;
    //     *(this+144)=v24; *(this+148)=v25; *(this+152)=v26;
    //     *(this+104)=v28; *(this+100)=v35; *(this+120)=v34; *(this+116)=v32;
    //     *(this+108)=v30; *(this+112)=1;
    //     return 0;
    //   }
    // UNRESOLVED: Exact split of the color aggregate (v35/v28/v30) and the two flag words (v32/v34) across this+0x64..0x78 is inferred from the flush sequence, not independently verified.
    // UNRESOLVED: Meaning of the off_5C57FC positional-size token and the duplicated near/far clip writes to this+0x30/0x34 and this+0x40/0x44.
    // UNRESOLVED: Interpretation of the sub_5651B0 return codes 2 and 4 and of the ConditionalDispatchBasedOnFlag gating buffer v49.
}
