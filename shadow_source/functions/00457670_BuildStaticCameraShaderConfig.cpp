// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00457670
// Canonical corpus name: sub_457670
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_457670_00457670.c

void UnknownObject::BuildStaticCameraShaderConfig()
{
    // Serializes the static-camera shader state of `this` into a formatted key-value string block written to the output buffer a2. Reads camera and viewport fields directly from `this` and through the getter helper group (DualFieldGetter, MultiFieldGetter, ShortComputation_6080, DualFieldGetter_60a0, RectViewportDimensionGetter), then emits the parameter names/format strings with BufferWriteWithStringLengthCheck. Returns 0.
    // GUARD: Guard on a3 > 0: when positive, fill the local scratch buffer v22 with 0x20 (space) for a3 bytes via memset so the emitted lines are space-padded to the requested length. [source:raw]
    // ASSIGNMENT: Terminate the scratch buffer v22 at index v3 (0 when a3 was not positive) with a null byte, keeping the format strings valid C strings. [source:raw]
    // ASSIGNMENT: Copy camera fields into the local parameter array v21[2..7]: this[3] (0xC), this[4] (0x10), this[5] (0x14), this[36] (0x90), this[37] (0x94) and this[38] (0x98). [field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000090, field:this:0x00000094, field:this:0x00000098]
    // CALL: DualFieldGetter(this, &v13, &v20): reads two fields of the camera object into local outputs. [callee:0x00456060]
    // CALL: MultiFieldGetter(this, &v19, &v15, &v18): reads multiple fields of the camera object into local outputs. [callee:0x004560E0]
    // CALL: ShortComputation_6080(this, v21, &v17): computes derived shader parameters written into the parameter array and v17. [callee:0x00456080]
    // ASSIGNMENT: Direct field copies into the parameter array: v21[1] = this[18] (0x48) and v21[8] = this[23] (0x5C). [field:this:0x00000048, field:this:0x0000005C]
    // CALL: DualFieldGetter_60a0(this, &v12, &v11): reads another pair of fields into local outputs. [callee:0x004560A0]
    // CALL: RectViewportDimensionGetter(this, &v16, &v14): reads the viewport dimensions into local outputs. [callee:0x004560C0]
    // CALL: Emit the static-camera shader config block: a series of BufferWriteWithStringLengthCheck(a2, str) calls writing the parameter names and format strings sstaticcam, _s, sPosition=%f,%f,%f, sOrientation=%f,%f, sFov=%f,%f, sClear=%s, sColor=%d,%d,%d, sClipPlanes=%f,%f, sLODMultiplier, sSize=%f,%f, sCenter=%f,%f, sMipmapLodBias, sFlags1D, sFlags2D, sActivationLoc, sActivationRad and a trailing _s. [callee:0x00566C30, global:0x005C5A60, global:0x005C5988, global:0x005C5A44, global:0x005C5A24, global:0x005C5974, global:0x005C595C, global:0x005C5944, global:0x005C5928, global:0x005C5910, global:0x005C58FC, global:0x005C58E4, global:0x005C58CC, global:0x005C58B8, global:0x005C58A4, global:0x005C59FC, global:0x005C59E0, global:0x005C5800]
    // RETURN: Return 0 as the completion status after the buffer writes. [source:raw]

    // Conservative worker pseudocode:
    //   int BuildStaticCameraShaderConfig(int* self, char* out, int len) {
    //     char scratch[256];
    //     int params[9] = {0};
    //     int d0, d1, d2, d3, d4, d5, d6, d7, d8, d9;
    //     int n = 0;
    //     if (len > 0) { memset(scratch, 0x20, len); n = len; }
    //     scratch[n] = 0;
    //     params[2] = self[3]; params[3] = self[4]; params[4] = self[5];
    //     params[5] = self[36]; params[6] = self[37]; params[7] = self[38];
    //     DualFieldGetter(self, &d0, &d1);
    //     MultiFieldGetter(self, &d2, &d3, &d4);
    //     ShortComputation_6080(self, params, &d5);
    //     params[1] = self[18];
    //     DualFieldGetter_60a0(self, &d6, &d7);
    //     RectViewportDimensionGetter(self, &d8, &d9);
    //     params[8] = self[23];
    //     /* 17 BufferWriteWithStringLengthCheck(out, name/format) calls for the static camera block * /
    //     return 0;
    //   }
    // UNRESOLVED: aFalse and aTrue string globals are data-xref listed but not referenced by this function's own emitted format strings; likely consumed elsewhere (for example selecting the sClear=%s value).
    // UNRESOLVED: byte_5EA438 global is data-xref listed but not referenced in the decompiled body.
    // UNRESOLVED: The getter group (DualFieldGetter, MultiFieldGetter, ShortComputation_6080, DualFieldGetter_60a0, RectViewportDimensionGetter) writes concrete shader parameter values whose field offsets are not visible in this function's raw source.
}
