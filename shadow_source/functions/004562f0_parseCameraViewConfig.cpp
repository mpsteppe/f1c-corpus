// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004562F0
// Canonical corpus name: sub_4562F0
// Owner: CameraViewSystem [DERIVED]
// Raw source: functions/sub_4562F0_004562f0.c

void CameraViewSystem::parseCameraViewConfig()
{
    // Parses a camera view configuration from a config-file section and writes the parsed values into the camera view object (this). When no config section is present, applies defaults from an in-memory setup block. Iterates over config tokens, parsing float pairs (clip planes, size, center, LOD multiplier, mipmap LOD bias, radius limits, orientation/position offsets), integer flags and a clear-enable string, then commits all locals into the object fields.
    // CALL: Zero the 384-byte config-section-flag buffer v40 and initialize all local accumulation variables (offset/size/center/clip/color floats to 0.0, integer color/flags to 0, lodMultiplier to 1.0, clearEnabled to 1). [source:raw]
    // GUARD: Call ConditionalDispatchBasedOnFlag(v40, 384): if it returns 0, no config section matched, so jump to the default-write path (LABEL_10); otherwise enter the token parse loop. [callee:0x00566CC0, source:raw]
    // CALL: Default path: StringCopyWithBufferRealloc(a3) copies the caller-supplied string argument into an internal buffer. [callee:0x00566650, source:raw]
    // ASSIGNMENT: Commit parsed locals into the camera view object: this+0x30/0x34/0x38/0x3C/0x40/0x44/0x48/0x4C/0x50/0x54/0x58/0x5C receive float values (offset X/Y, clip near/far, LOD multiplier, size X/Y, center X/Y, mipmap LOD bias), this+0x60 receives the clear-enable byte, this+0x64/0x68/0x6C receive color R/G/B ints, this+0x70 receives 0, this+0x74/0x78 receive flags ints. [field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, field:this:0x00000054, field:this:0x00000058, field:this:0x0000005C, field:this:0x00000060, field:this:0x00000064, field:this:0x00000068, field:this:0x0000006C, field:this:0x00000070, field:this:0x00000074, field:this:0x00000078, source:raw]
    // RETURN: Return 0 from the default-write path after committing all fields. [source:raw]
    // LOOP: Parse loop: call sub_5651B0(v34) to read the next config token; break out of the loop when it returns non-zero. sub_5651B0 returns 2 to mean 'no section / finished with defaults' and 4 to mean 'finished with explicit section'. [callee:0x005651B0, source:raw]
    // CALL: sub_565870(&off_5C57FC, &v19, &v20, ...): parse two floats from the in-memory setup block at off_5C57FC into offsetX/offsetY. [callee:0x00565870, global:0x005C57FC, source:raw]
    // CALL: sub_565760(aColor, &v23, &v25, &v27, 0): parse color R/G/B integer values. [callee:0x00565760, global:0x005C57F4, source:raw]
    // CALL: sub_565870(aClipplanes, &v33, &v32, ...): parse near/far clip plane floats. [callee:0x00565870, global:0x005C57E8, source:raw]
    // CALL: sub_565870(aLodmultiplier, &v24, ...): parse the LOD multiplier float (default 1.0). [callee:0x00565870, global:0x005C57D8, source:raw]
    // CALL: sub_565870(aSize, &v30, &v26, ...): parse size X/Y floats. [callee:0x00565870, global:0x005C57D0, source:raw]
    // CALL: sub_565870(aCenter, &v21, &v28, ...): parse center X/Y floats. [callee:0x00565870, global:0x005C57C8, source:raw]
    // CALL: sub_565870(aMipmaplodbias, &v22, ...): parse the mipmap LOD bias float. [callee:0x00565870, global:0x005C57B8, source:raw]
    // CALL: sub_565760(aFlags1, &v29, 0, 0, 0): parse the first flags integer. [callee:0x00565760, global:0x005C57B0, source:raw]
    // CALL: sub_565760(aFlags2, &v31, 0, 0, 0): parse the second flags integer. [callee:0x00565760, global:0x005C57A8, source:raw]
    // CALL: sub_565520(aClear, v41, 0): read the clear-enable string token; if it equals aFalse, clear the clearEnabled byte (v18 = 0). [callee:0x00565520, global:0x005C57A0, global:0x005C5798, source:raw]
    // CALL: sub_565870(aRadiuslimits, this+128, this+132, ...): parse radius limit floats directly into the object (offsets beyond the field evidence range). [callee:0x00565870, global:0x005C5788, source:raw]
    // CALL: sub_565870(aOrientationrat, this+136, this+140, this+144, ...): parse the orientation-rate triple directly into the object. [callee:0x00565870, global:0x005C5778, source:raw]
    // CALL: sub_565870(aPositionoffset, this+148, this+152, this+156, ...): parse the position-offset triple directly into the object. [callee:0x00565870, global:0x005C5768, source:raw]
    // CALL: sub_565870(aOrientationoff, this+160, this+164, this+168, ...): parse the orientation-offset triple directly into the object. [callee:0x00565870, global:0x005C5754, source:raw]
    // CALL: sub_565870(aRadius_0, this+172, ...): parse a single radius float directly into the object. [callee:0x00565870, global:0x005C574C, source:raw]
    // STATE_TRANSITION: Loop re-entry check (LABEL_9): re-evaluate ConditionalDispatchBasedOnFlag(v40, 384); on 0 jump to the default-write path, otherwise continue the parse loop. After the loop exits with sub_5651B0 result 2, fall through to the default-write path; with result 4, return 1 (explicit section parsed); otherwise re-enter the loop body. [callee:0x00566CC0, callee:0x005651B0, source:raw]
    // RETURN: Return 1 when the parse loop finished with an explicit config section (sub_5651B0 returned 4). [callee:0x005651B0, source:raw]

    // Conservative worker pseudocode:
    //   initAccumulators();
    //   if (!ConditionalDispatchBasedOnFlag(flags, 384)) { commitDefaults(); return 0; }
    //   while (true) {
    //     v4 = readNextConfigToken();
    //     if (v4) break;
    //     parseFloatPair(off_5C57FC, &offsetX, &offsetY);
    //     parseIntTriple(aColor, &colorR, &colorG, &colorB);
    //     parseFloatPair(aClipplanes, &clipNear, &clipFar);
    //     parseFloatSingle(aLodmultiplier, &lodMultiplier);
    //     parseFloatPair(aSize, &sizeX, &sizeY);
    //     parseFloatPair(aCenter, &centerX, &centerY);
    //     parseFloatSingle(aMipmaplodbias, &mipmapLodBias);
    //     parseIntSingle(aFlags1, &flags1);
    //     parseIntSingle(aFlags2, &flags2);
    //     readString(aClear, str); if (strcmp(str, aFalse) == 0) clearEnabled = 0;
    //     parseFloatPair(aRadiuslimits, this+0x80, this+0x84);
    //     parseFloatTriple(aOrientationrat, this+0x88, this+0x8C, this+0x90);
    //     parseFloatTriple(aPositionoffset, this+0x94, this+0x98, this+0x9C);
    //     parseFloatTriple(aOrientationoff, this+0xA0, this+0xA4, this+0xA8);
    //     parseFloatSingle(aRadius_0, this+0xAC);
    //     if (!ConditionalDispatchBasedOnFlag(flags, 384)) break;
    //   }
    //   if (v4 == 2) commitDefaults();
    //   if (v4 == 4) return 1;
    //   return 0;
    // UNRESOLVED: The writes to this+0x80..this+0xAC (radius limits, orientation rate/offset, position offset, radius) have no field evidence refs in the packet, so the exact field offsets beyond 0x78 cannot be bound to named fields.
    // UNRESOLVED: a2 is declared in the signature but never referenced in the decompiled body; its role is unknown.
    // UNRESOLVED: sub_5651B0 return semantics (2 = no section, 4 = section parsed) are inferred from the branch structure, not proven.
}
