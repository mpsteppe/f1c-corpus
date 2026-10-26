// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055D460
// Canonical corpus name: sub_55D460
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55D460_0055d460.c

void UnknownObject::NormalizeAndStoreVectorWithDXUpdate()
{
    // Stores a 3-component vector (a2, a3, a4) as floats at this+0x44/+0x48/+0x4C, normalizes all three components to unit length when the vector length is non-zero, then calls DirectXVertexBufferTextureCoordinateSetup with the global dword_8B78A0, this and its handle at this+0x4 under mode 5, and finally ORs dirty flag 0x800 into dword_8B8F28+236.
    // ASSIGNMENT: Store the incoming vector verbatim: this+0x44 = a2, this+0x48 = a3, this+0x4C = a4 [field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, source:raw]
    // CALCULATION: v4 = sqrt(a2*a2 + a3*a3 + a4*a4) computes the vector length [source:raw]
    // GUARD: Normalization only proceeds when the computed length v4 is non-zero; otherwise the original un-normalized values are kept [source:raw]
    // ASSIGNMENT: Reciprocal 1.0/v4 scales each component back into this+0x44/+0x48/+0x4C, producing a unit-length vector [field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, source:raw]
    // CALL: DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, this, *(this+4), 5) pushes the updated vector into the vertex buffer using the buffer handle at this+0x4 [callee:0x005416A0, field:this:0x00000004, global:0x008B78A0, source:raw]
    // ASSIGNMENT: OR 0x800 into dword_8B8F28+236 to flag the buffer state as dirty [global:0x008B8F28, source:raw]
    // RETURN: Return dword_8B8F28 as the function result [global:0x008B8F28, function:0x0055D460, source:raw]
    // CALL: Invoked by sub_55A500 (0055A500) as part of a DirectX vertex-buffer normal/vector update path [caller:0x0055A500, source:raw]

    // Conservative worker pseudocode:
    //   *(this+0x44) = a2; *(this+0x48) = a3; *(this+0x4C) = a4;
    //   len = sqrt(a2*a2 + a3*a3 + a4*a4);
    //   if (len != 0.0) {
    //     inv = 1.0 / len;
    //     *(this+0x44) = a2 * inv;
    //     *(this+0x48) = a3 * inv;
    //     *(this+0x4C) = inv * a4;
    //   }
    //   DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, this, *(this+4), 5);
    //   *(dword_8B8F28 + 236) |= 0x800;
    //   return dword_8B8F28;
    // UNRESOLVED: Globals dbl_59E430 and flt_59E43C are flagged by packet facts but appear nowhere in the raw decompiled source; the skeleton fill labels them a zero sentinel and a zero-length threshold, unverifiable from this packet
    // UNRESOLVED: The meaning of DirectXVertexBufferTextureCoordinateSetup mode argument 5 and of the dirty flag 0x800 at dword_8B8F28+236 is not documented in this function
}
