// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2800
// Canonical corpus name: ShortToFloatVectorUnpack
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortToFloatVectorUnpack_004b2800.c

void UnknownObject::ShortToFloatVectorUnpack()
{
    // thiscall unpack of a compact 2-component int16 vector into floats. Writes this[20] (offset 0x28) scaled by 0.001953125 (1/512) to a2 (X), zeroes the DWORD at a2+4 (Y), and writes this[21] (offset 0x2A) scaled by 0.001953125 to a2+8 (Z). Returns the output pointer a2. Used on the per-frame path by VehiclePhysicsTimeStep and AudioParameterInterpolation.
    // ASSIGNMENT: Zero the output DWORD at a2+4 (Y component) before writing the X/Z components. [source:raw]
    // CALCULATION: Scale int16 this[20] (offset 0x28) by 0.001953125 (1/512) and write the float to a2 (X component). [field:this:0x00000028, source:raw]
    // CALCULATION: Scale int16 this[21] (offset 0x2A) by 0.001953125 (1/512) and write the float to a2+8 (Z component). [field:this:0x0000002A, source:raw]
    // RETURN: Return the output pointer a2 (result = a2). [source:raw]
    // CALL: Used on the per-frame path by VehiclePhysicsTimeStep and AudioParameterInterpolation for packed-vector decoding. [caller:0x004C73F0, caller:0x004FF680]

    // Conservative worker pseudocode:
    //   *(int*)(a2 + 4) = 0;
    //   *(float*)a2    = (float)this[20] * 0.001953125;
    //   *(float*)(a2+8)= (float)this[21] * 0.001953125;
    //   return a2;
    // UNRESOLVED: flt_59E4D8 is listed as a read-only referenced global, but the raw source shows the 0.001953125 (1/512) scale as an inlined literal; the global likely supplies that scale via a constant folded by the decompiler, but no evidence ref ties them directly.
    // UNRESOLVED: The source int16 vector element types and the output buffer layout (X, zeroed pad, Z) are DERIVED from usage; the packet does not name the fields.
    // UNRESOLVED: Owner object is unknown; the ABI lead 'Short_to_Float_Vector_Unpack' is the only hint.
}
