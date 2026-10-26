// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005174CB
// Canonical corpus name: Vec2AffineTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Vec2AffineTransform_005174cb.c

void UnknownObject::Vec2AffineTransform()
{
    // Transforms a 2D vector with a 4x4 affine matrix and writes the 4-component result. a2 is the 2-element input vector (x=a2[0], y=a2[1]); a3 is a 16-float matrix treated as row-major (row i = a3[4*i..4*i+3], translation column = a3[12..15]); a1 receives the 4 output components out[i] = x*a3[i] + y*a3[4+i] + a3[12+i]. Returns a1. Straight-line, branch-free, no callees.
    // CALCULATION: Per __stdcall prototype, treat a1 as the output buffer, a2 as a 2-element input vector, and a3 as a 16-element matrix. Load the two input components and all matrix rows for the dot-product-with-translation per output component. [abi:lead, function:0x005174CB, source:raw]
    // ASSIGNMENT: a1[0] = a2[0]*a3[0] + a2[1]*a3[4] + a3[12] (output X: first matrix row dot input vector plus X translation). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: a1[1] = a2[0]*a3[1] + a2[1]*a3[5] + a3[13] (output Y: second matrix row dot input vector plus Y translation). [field:this:0x00000004, source:raw]
    // ASSIGNMENT: a1[2] = a2[0]*a3[2] + a2[1]*a3[6] + a3[14] (output Z: third matrix row dot input vector plus Z translation). [field:this:0x00000008, source:raw]
    // ASSIGNMENT: a1[3] = a2[0]*a3[3] + a2[1]*a3[7] + a3[15] (output W: fourth matrix row dot input vector plus W translation). [field:this:0x0000000C, source:raw]
    // RETURN: Return a1 (pointer to the 4-component transformed result). [function:0x005174CB]

    // Conservative worker pseudocode:
    //   out[0] = x*m[0]  + y*m[4]  + m[12];
    //   out[1] = x*m[1]  + y*m[5]  + m[13];
    //   out[2] = x*m[2]  + y*m[6]  + m[14];
    //   out[3] = x*m[3]  + y*m[7]  + m[15];
    //   return out;
    // UNRESOLVED: a3 is assumed to be a row-major 4x4 float matrix based on the index pattern (out[i] uses a3[i], a3[4+i], a3[12+i]); column-major or other layouts were not proven by evidence.
    // UNRESOLVED: a2 is assumed to be a 2-element float vector; only a2[0] and a2[1] are read.
    // UNRESOLVED: a1/a2/a3 are raw pointer arguments, not member fields of a single object; the packet fields describe only the a1 (output) buffer. The fourth output component's semantic role (homogeneous W vs raw Z data) is unproven.
    // UNRESOLVED: No callers are recorded in the packet, so the meaning of the resulting 4-component vector in the game's coordinate systems cannot be confirmed.
}
