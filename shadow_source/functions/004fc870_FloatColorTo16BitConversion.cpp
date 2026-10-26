// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FC870
// Canonical corpus name: sub_4FC870
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4FC870_004fc870.c

void UnknownObject::FloatColorTo16BitConversion()
{
    // Converts six normalized floats from `this` into 16-bit output words written through the a2 pointer. The first four floats (this[0..3], e.g. RGBA channels) are scaled by 65535.0 and converted with CRTFtol; the last two floats (this[4], this[5], e.g. intensity/extra channels) are scaled by 128.0. The truncated value of this[4]*128.0 is also the function return value. Called by sub_4FCEE0.
    // ASSIGNMENT: Write CRTFtol(this[0] * 65535.0) into output word a2[0]. [field:this:0x00000000, callee:0x00587BDC, global:0x0059E6FC, source:raw]
    // ASSIGNMENT: Write CRTFtol(this[1] * 65535.0) into output word a2[1]. [field:this:0x00000004, callee:0x00587BDC, global:0x0059E6FC, source:raw]
    // ASSIGNMENT: Write CRTFtol(this[2] * 65535.0) into output word a2[2]. [field:this:0x00000008, callee:0x00587BDC, global:0x0059E6FC, source:raw]
    // ASSIGNMENT: Write CRTFtol(this[3] * 65535.0) into output word a2[3]. [field:this:0x0000000C, callee:0x00587BDC, global:0x0059E6FC, source:raw]
    // CALCULATION: Scale this[4] by 128.0, truncate to an integer, save it as the return value, and write it into output word a2[4]. [field:this:0x00000010, global:0x0059F120, source:raw]
    // CALCULATION: Scale this[5] by 128.0, truncate to an integer, and write it into output word a2[5]. [field:this:0x00000014, global:0x0059F120, source:raw]
    // RETURN: Return the truncated this[4]*128.0 value as the 16-bit signed result. [function:0x004FC870, source:raw]
    // CALL: Invoked by sub_4FCEE0 (004fcee0) to convert float color data to packed 16-bit words. [caller:0x004FCEE0, source:raw]

    // Conservative worker pseudocode:
    //   a2[0] = CRTFtol(this[0] * 65535.0);
    //   a2[1] = CRTFtol(this[1] * 65535.0);
    //   a2[2] = CRTFtol(this[2] * 65535.0);
    //   a2[3] = CRTFtol(this[3] * 65535.0);
    //   result = (int)(this[4] * 128.0);
    //   a2[4] = result;
    //   a2[5] = (int)(this[5] * 128.0);
    //   return result;
    // UNRESOLVED: The read-only floats flt_59E6FC and flt_59F120 are flagged as globals while the raw source renders 65535.0 and 128.0 as inlined literals; their exact compiled constant mapping is not independently established by this packet.
    // UNRESOLVED: The semantic role of the six floats (RGBA channels versus intensity/extra channels) is not proven by this packet; the existing-analysis labels are DERIVED.
}
