// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DD3A0
// Canonical corpus name: TwoOutputPassthrough
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwoOutputPassthrough_004dd3a0.c

void UnknownObject::TwoOutputPassthrough()
{
    // Resolves a font/device string (a7, else this+0x28, else the global fallback byte_5EA438), then calls SurfaceSizeQuery to obtain surface dimensions. Writes the two output values through a5 and a6 only when the respective output pointer is non-null, and returns a6.
    // ASSIGNMENT: Seed the resolved font pointer from argument a7. [source:raw]
    // GUARD: If a7 is null, substitute this+0x28; if that is also null, fall back to the global byte_5EA438. [source:raw, field:this:0x00000028, global:0x005EA438]
    // CALL: Call SurfaceSizeQuery with the resolved font, a2, a3, a4 and the two output slots a7 and a4. [callee:0x004DC600]
    // ASSIGNMENT: Write the width result to *a5 only when a5 is non-null. [source:raw]
    // ASSIGNMENT: Write the height result to *a6 only when a6 is non-null. [source:raw]
    // RETURN: Return the a6 output pointer. [source:raw]

    // Conservative worker pseudocode:
    //   float *TwoOutputPassthrough(DWORD *this, int a2, float a3, float a4, char **a5, float *a6, char *a7) {
    //     char *font = a7 ? a7 : (this[10] ? (char*)this[10] : byte_5EA438);
    //     SurfaceSizeQuery(font, a2, &a7, &a4, a3, a4);
    //     if (a5) *a5 = a7;
    //     if (a6) *a6 = a4;
    //     return a6;
    //   }
    // UNRESOLVED: Identity of the owner object exposing the this+0x28 font pointer is unknown.
    // UNRESOLVED: The same variable a4 is used both as a float input and as the height output slot; this is a decompiler artifact of the call's argument aliasing.
    // UNRESOLVED: Meaning of arguments a2 and a3 to SurfaceSizeQuery depends on the callee's contract.
}
