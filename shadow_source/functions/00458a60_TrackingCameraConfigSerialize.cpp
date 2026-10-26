// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00458A60
// Canonical corpus name: sub_458A60
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_458A60_00458a60.c

void UnknownObject::TrackingCameraConfigSerialize()
{
    // Serializes tracking-camera / shader configuration parameters into the string buffer a2: builds a space-padded scratch buffer of length a3, collects camera configuration fields from this into a value array, pulls further parameters through a chain of getter helpers, then emits a series of key-value format strings via BufferWriteWithStringLengthCheck and a nested sub_458190 block, returning 0.
    // ASSIGNMENT: Zero-initialize the local out-param registers v11 through v20 and v21[0] before collecting values. [source:raw]
    // CALCULATION: When a3 > 0, pad the 256-byte scratch buffer v22 with 0x20 (space) for a3 bytes and then NUL-terminate it at v22[a3]. [source:raw]
    // ASSIGNMENT: Assemble the configuration value array v21 from this: v21[2] = this[3] (this+0xC), v21[3] = this[4] (this+0x10), v21[4] = this[5] (this+0x14), v21[5] = this[36] (this+0x90), v21[6] = this[37] (this+0x94), v21[7] = this[38] (this+0x98), v21[1] = this[18] (this+0x48), v21[8] = this[23] (this+0x5C). [field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000048, field:this:0x0000005C, field:this:0x00000090, field:this:0x00000094, field:this:0x00000098, source:raw]
    // CALL: Pull two values via DoubleFieldGetterAt0x300x34(this, &v13, &v20). [callee:0x00456040, source:raw]
    // CALL: Pull three values via MultiFieldGetter(this, &v19, &v15, &v18). [callee:0x004560E0, source:raw]
    // CALL: Compute one value via ShortComputation_6080(this, v21, &v17) using the assembled v21 array. [callee:0x00456080, source:raw]
    // CALL: Pull two values via DualFieldGetter_60a0(this, &v12, &v11). [callee:0x004560A0, source:raw]
    // CALL: Pull two viewport dimension values via RectViewportDimensionGetter(this, &v16, &v14). [callee:0x004560C0, source:raw]
    // CALL: Emit the camera/shader configuration header and parameter lines into a2 via BufferWriteWithStringLengthCheck using the format strings aStrackingcamS, aS_0, aSPositionFFF, aSOrientationFF, aSFovFF, aSClearS, aSColorDDD, aSClipplanesFF, aSLodmultiplier, aSSizeFF, aSCenterFF, aSMipmaplodbias, aSFlags1D, aSFlags2D, aSActivationloc, aSActivationrad, aSTrackingrateF, aSMovementrateF and the closing aS_1. [callee:0x00566C30, global:0x005C5800, global:0x005C58A4, global:0x005C58B8, global:0x005C58CC, global:0x005C58E4, global:0x005C58FC, global:0x005C5910, global:0x005C5928, global:0x005C5944, global:0x005C595C, global:0x005C5974, global:0x005C5988, global:0x005C59E0, global:0x005C59FC, global:0x005C5A24, global:0x005C5A44, global:0x005C5AE8, global:0x005C5B00, global:0x005C5B18, source:raw]
    // CALL: Emit the nested configuration block via sub_458190(this + 44, a2, a3 + 2), writing the block length into the buffer as part of the sequence. [callee:0x00458190, source:raw]
    // RETURN: Return 0 on completion. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_458A60(_DWORD *this, int a2, signed int a3) {
    //     int v11, v12, v13, v14, v15, v16, v17, v18, v19, v20;
    //     int v21[9] = {0};
    //     char v22[256];
    //     if (a3 > 0) { memset(v22, 0x20, a3); }
    //     v22[a3] = 0;
    //     v21[1] = this[18];  v21[2] = this[3];  v21[3] = this[4];  v21[4] = this[5];
    //     v21[5] = this[36];  v21[6] = this[37]; v21[7] = this[38]; v21[8] = this[23];
    //     DoubleFieldGetterAt0x300x34(this, &v13, &v20);
    //     MultiFieldGetter(this, &v19, &v15, &v18);
    //     ShortComputation_6080(this, v21, &v17);
    //     DualFieldGetter_60a0(this, &v12, &v11);
    //     RectViewportDimensionGetter(this, &v16, &v14);
    //     BufferWriteWithStringLengthCheck(a2, aStrackingcamS);
    //     /* ... 18 more BufferWriteWithStringLengthCheck format-line emits ... * /
    //     BufferWriteWithStringLengthCheck(a2, aS_1);
    //     sub_458190(this + 44, a2, a3 + 2);
    //     return 0;
    //   }
    // UNRESOLVED: The exact meaning of the individual format strings and the values placed into them is not documented by this function; the existing analysis names the behavior tracking-camera config serialization but that mapping is DERIVED only.
    // UNRESOLVED: Globals aFalse (0x005C5798), aTrue (0x005C596C) and byte_5EA438 (0x005EA438) are listed as packet globals but are not referenced directly in this function's body, so their role here is unresolved.
    // UNRESOLVED: The getter helpers (DoubleFieldGetterAt0x300x34, MultiFieldGetter, ShortComputation_6080, DualFieldGetter_60a0, RectViewportDimensionGetter) are only evidenced as callees, not by their own bodies.
}
