// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054FC50
// Canonical corpus name: FloatToIntMultiply
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatToIntMultiply_0054fc50.c

void UnknownObject::FloatToIntMultiply()
{
    // Converts a float a2 to an int by scaling with the 2.55 constant at 0x005B8988, rounding via CRTFtol, then replicating the resulting byte across all channels with the 16843009 multiplier and storing it as this[26]. Unconditional; returns the computed value.
    // CALCULATION: Scale the incoming float a2 by the global constant 2.55 at 0x005B8988. [global:0x005B8988, source:raw]
    // CALL: Convert the scaled float to a long via CRTFtol at 0x00587BDC. [callee:0x00587BDC, source:raw]
    // CALCULATION: Multiply the rounded value by 16843009 to replicate the byte across all four channels. [source:raw]
    // ASSIGNMENT: Store the packed result into this[26] (offset 0x68). [field:this:0x00000068, source:raw]
    // RETURN: Return the packed value as the function result. [function:0x0054FC50, source:raw]

    // Conservative worker pseudocode:
    //   int sub_54FC50(int *this, float a2) {
    //     int result = 16843009 * CRTFtol(a2 * 2.55);
    //     this[26] = result;
    //     return result;
    //   }
    // UNRESOLVED: The caller D3DTextureResourceCreation (0x00548190) supplies this object and float a2; the concrete meaning of the stored color field depends on that caller.
    // UNRESOLVED: The 0-100 to 0-255 scale implied by the 2.55 multiplier is inferred, not proven here.
}
