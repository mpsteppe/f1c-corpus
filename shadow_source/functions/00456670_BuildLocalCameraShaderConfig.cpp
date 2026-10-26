// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00456670
// Canonical corpus name: sub_456670
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_456670_00456670.c

void UnknownObject::BuildLocalCameraShaderConfig()
{
    // Serializes the local-camera shader state of `this` into a formatted key-value string block written to the output buffer a2. Reads camera fields through the getter helper group (DualFieldGetter, MultiFieldGetter, ShortComputation_6080, DualFieldGetter_60a0, RectViewportDimensionGetter) plus two direct field copies, then emits the parameter names/format strings with BufferWriteWithStringLengthCheck. Returns 0.
    // GUARD: Guard on a3 > 0: when positive, fill the local scratch buffer v17 with 0x20 (space) for a3 bytes via memset so the emitted lines are space-padded to the requested length. [source:raw]
    // ASSIGNMENT: Terminate the scratch buffer v17 at index v3 (0 when a3 was not positive) with a null byte, keeping the format strings valid C strings. [source:raw]
    // CALL: DualFieldGetter(this, &v8, &v15): reads two fields of the camera object into local outputs. [callee:0x00456060]
    // CALL: MultiFieldGetter(this, v16, &v10, &v14): reads multiple fields into the parameter array and local outputs. [callee:0x004560E0]
    // CALL: ShortComputation_6080(this, &v6, &v12): computes derived shader parameters written into local outputs. [callee:0x00456080]
    // ASSIGNMENT: Direct field copies into the parameter array: v16[1] = this[18] (0x48) and v16[2] = this[23] (0x5C). [field:this:0x00000048, field:this:0x0000005C]
    // CALL: DualFieldGetter_60a0(this, &v9, &v7): reads another pair of fields into local outputs. [callee:0x004560A0]
    // CALL: RectViewportDimensionGetter(this, &v13, &v11): reads the viewport dimensions into local outputs. [callee:0x004560C0]
    // CALL: Emit the local-camera shader config block: a series of BufferWriteWithStringLengthCheck(a2, str) calls writing the parameter names and format strings slocalcam, _s, sFov=%f,%f, sClear=%s, sColor=%d,%d,%d, sClipPlanes=%f,%f, sLODMultiplier, sSize=%f,%f, sCenter=%f,%f, sMipmapLodBias, sFlags1D, sFlags2D, sRadiusLimits=%f, sOrientationRa, sPositionOffse, sOrientationOf, sRadius=%f and a trailing _s. [callee:0x00566C30, global:0x005C5990, global:0x005C5988, global:0x005C5974, global:0x005C595C, global:0x005C5944, global:0x005C5928, global:0x005C5910, global:0x005C58FC, global:0x005C58E4, global:0x005C58CC, global:0x005C58B8, global:0x005C58A4, global:0x005C5888, global:0x005C5864, global:0x005C5840, global:0x005C581C, global:0x005C5808, global:0x005C5800]
    // RETURN: Return 0 as the completion status after the buffer writes. [source:raw]

    // Conservative worker pseudocode:
    //   int BuildLocalCameraShaderConfig(int* self, char* out, int len) {
    //     char scratch[256];
    //     int params[3] = {0};
    //     int d0, d1, d2, d3, d4, d5, d6, d7, d8, d9;
    //     int n = 0;
    //     if (len > 0) { memset(scratch, 0x20, len); n = len; }
    //     scratch[n] = 0;
    //     DualFieldGetter(self, &d0, &d1);
    //     MultiFieldGetter(self, params, &d2, &d3);
    //     ShortComputation_6080(self, &d4, &d5);
    //     params[1] = self[18];
    //     DualFieldGetter_60a0(self, &d6, &d7);
    //     RectViewportDimensionGetter(self, &d8, &d9);
    //     params[2] = self[23];
    //     /* 19 BufferWriteWithStringLengthCheck(out, name/format) calls for the local camera block * /
    //     return 0;
    //   }
    // UNRESOLVED: aFalse and aTrue string globals are data-xref listed but not referenced by this function's own emitted format strings; likely consumed elsewhere (for example selecting the sClear=%s value).
    // UNRESOLVED: byte_5EA438 global is data-xref listed but not referenced in the decompiled body.
    // UNRESOLVED: The getter group (DualFieldGetter, MultiFieldGetter, ShortComputation_6080, DualFieldGetter_60a0, RectViewportDimensionGetter) writes concrete shader parameter values whose field offsets are not visible in this function's raw source.
}
