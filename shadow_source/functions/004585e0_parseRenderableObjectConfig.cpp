// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004585E0
// Canonical corpus name: sub_4585E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4585E0_004585e0.c

void UnknownObject::parseRenderableObjectConfig()
{
    // Parses a named configuration block for a renderable scene object or environment effect from a tokenised data source. When the tokenizer gate ConditionalDispatchBasedOnFlag(v60, 384) fails it applies hardcoded defaults; otherwise it loops over tokens via sub_5651B0 and reads the known keys (Position, Orientation, Color, Clipplanes, Lodmultiplier, Size, Center, Mipmaplodbias, Flags1, Flags2, Clear, Activationlocation, Activationradius, Trackingrate, Movementrate, Movementpath) into locals, then copies the assembled values into the target struct fields this+0x30..this+0x98, applying a 100.0 default radius, 1.0 defaults and a 'false' check on Clear. Called from MainView.
    // ASSIGNMENT: Initializes the parse buffers and local config defaults: zeroes the 384-byte v60 section buffer, zeroes the position/orientation/color locals, sets the v28 and v56 flags to 1, v44 (LOD multiplier) default 1.0 and v29 (activation radius) default 100.0. [source:raw]
    // GUARD: ConditionalDispatchBasedOnFlag(v60, 384) decides whether to run the token-parse loop or jump straight to the defaults-copy path; the function is invoked from MainView. [callee:0x00566CC0, caller:0x0040B850, source:raw]
    // LOOP: Token loop: sub_5651B0(v54) advances the tokenizer (non-zero return ends the loop). Named tokens are read with sub_565870 (float/vector: aPosition, aOrientation, off_5C57FC, aClipplanes, aLodmultiplier, aSize, aCenter, aMipmaplodbias, aActivationloca, aActivationradi, aTrackingrate, aMovementrate) or sub_565760 (integer: aColor, aFlags1, aFlags2); aClear is parsed as a string via sub_565520 and clears the render flag v28 when it equals aFalse. [callee:0x005651B0, callee:0x00565870, callee:0x00565760, callee:0x00565520, global:0x005C59D4, global:0x005C59C8, global:0x005C57FC, global:0x005C57E8, global:0x005C57D8, global:0x005C57D0, global:0x005C57C8, global:0x005C57B8, global:0x005C59B4, global:0x005C59A0, global:0x005C5AD8, global:0x005C5AC8, global:0x005C57F4, global:0x005C57B0, global:0x005C57A8, global:0x005C57A0, global:0x005C5798, source:raw]
    // CALL: Movement path: if sub_588410(v60, aMovementpath_0) is zero, parses the movement path into this+176 with sub_458050((void*)(this+176), a2). [callee:0x00588410, global:0x005C5AB8, callee:0x00458050, source:raw]
    // CALL: Defaults/finalize path: StringCopyWithBufferRealloc(a3) carries the config name, F_3VectorCopyToStruct copies the position vector into this and VectorCopy copies the orientation vector. [callee:0x00566650, callee:0x00456110, callee:0x00456130, source:raw]
    // ASSIGNMENT: Writes the assembled configuration into the target struct: orientation/clip-plane floats at this+0x30..this+0x3C, near/far plus LOD/size/center floats at this+0x40..this+0x5C, the clear-enable byte at this+0x60, color integers at this+0x64..this+0x6C, flags and counters through this+0x70..this+0x84 with this+0x70 fixed to 2, the radius 100.0 at this+0x88 and its square at this+0x8C, and the position integers at this+0x90/0x94/0x98. [field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, field:this:0x00000054, field:this:0x00000058, field:this:0x0000005C, field:this:0x00000060, field:this:0x00000064, field:this:0x00000068, field:this:0x0000006C, field:this:0x00000070, field:this:0x00000074, field:this:0x00000078, field:this:0x0000007C, field:this:0x00000080, field:this:0x00000084, field:this:0x00000088, field:this:0x0000008C, field:this:0x00000090, field:this:0x00000094, field:this:0x00000098, source:raw]
    // RETURN: Returns 0 on the completed/defaults path and 1 when the tokenizer reports the end-of-stream result 4. [function:0x004585E0, source:raw]

    // Conservative worker pseudocode:
    //   memset(v60, 0, 384);
    //   pos = ori = color = flags = {0}; v28 = v56 = 1; v44 = 1.0; v29 = 100.0;
    //   if (!ConditionalDispatchBasedOnFlag(v60, 384))
    //     goto finalize;
    //   while (!(rc = sub_5651B0(v54))) {
    //     sub_565870(aPosition,      &v51, &v52, &v53, 0,0,0,0,0);
    //     sub_565870(aOrientation,   &v32, &v33, &v34, 0,0,0,0,0);
    //     sub_565870(&off_5C57FC,    &v30, &v31, 0,0,0,0,0,0);
    //     sub_565760(aColor,         &v50, &v36, &v37, 0);
    //     sub_565870(aClipplanes,    &v48, &v43, 0,0,0,0,0,0);
    //     sub_565870(aLodmultiplier, &v44, 0,0,0,0,0,0,0);
    //     sub_565870(aSize,          &v38, &v49, 0,0,0,0,0,0);
    //     sub_565870(aCenter,        &v40, &v35, 0,0,0,0,0,0);
    //     sub_565870(aMipmaplodbias, &v42, 0,0,0,0,0,0,0);
    //     sub_565760(aFlags1, &v39, 0, 0, 0);
    //     sub_565760(aFlags2, &v41, 0, 0, 0);
    //     if (sub_565520(aClear, v61, 0) && strcmp(v61, aFalse) == 0) v28 = 0;
    //     sub_565870(aActivationloca, &v45, &v46, &v47, 0,0,0,0,0);
    //     sub_565870(aActivationradi, &v29, 0,0,0,0,0,0,0);
    //     sub_565870(aTrackingrate, this + 164, 0,0,0,0,0,0,0);
    //     sub_565870(aMovementrate, this + 168, 0,0,0,0,0,0,0);
    //     if (!sub_588410(v60, aMovementpath_0)) sub_458050(this + 176, a2);
    //     if (!ConditionalDispatchBasedOnFlag(v60, 384)) goto finalize;
    //   }
    //   if (rc == 2) goto finalize;
    //   if (rc != 4) goto parse_again;
    //   return 1;
    //   finalize:
    //     StringCopyWithBufferRealloc(a3);
    //     F_3VectorCopyToStruct(this, &v51); VectorCopy(this, &v32);
    //     copy_floats(this+0x30..0x5C); *(uint8*)(this+0x60) = v28;
    //     copy_ints(this+0x64..0x6C); *(uint32*)(this+0x70) = 2;
    //     copy_ints(this+0x74..0x84); *(float*)(this+0x88) = v29; *(float*)(this+0x8C) = v29*v29;
    //     copy_ints(this+0x90, this+0x94, this+0x98);
    //     return 0;
    // UNRESOLVED: The tokenizer semantics (sub_5651B0 return codes: 0 = more tokens, 2 = stop, 4 = end-of-stream) are inferred from control flow, not from a packet-visible callee body.
    // UNRESOLVED: The exact object class owning this parser is unknown; the target struct spans at least 0x30..0xA8 with an additional movement path stored at +0xB0.
    // UNRESOLVED: sub_458050's body is not in the packet, so the movement-path storage format at this+176 is unverified.
}
