// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051249F
// Canonical corpus name: CameraRotationStateSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CameraRotationStateSetter_0051249f.c

void UnknownObject::StoreCameraRotationState()
{
    // Stores two double-precision camera rotation parameters as floats into the target object (a3 into this+0x130, a2 into this+0x134) and conditionally raises bit 5 of the flags byte at this+0x61 when the product of the two values deviates from 1.0 by more than 0.05. The two float writes are unconditional; only the flag modification is guarded. Returns the target pointer.
    // ASSIGNMENT: Copy the target pointer a1 into result for later return [source:raw]
    // GUARD: Guard: when fabs(a2 * a3 - 1.0) is greater than 0.05, set bit 5 of the flags byte at this+0x61; the constant 1.0 comes from dbl_59E420 and the threshold 0.05 from dbl_5AF428 [field:this:0x00000061, global:0x0059E420, global:0x005AF428, source:raw]
    // ASSIGNMENT: Bitwise OR of 0x20 into the byte at this+0x61, executed only when the product-deviation guard passes [field:this:0x00000061, source:raw]
    // ASSIGNMENT: Write a3 as a float to this+0x130, unconditionally [field:this:0x00000130, source:raw]
    // ASSIGNMENT: Write a2 as a float to this+0x134, unconditionally [field:this:0x00000134, source:raw]
    // RETURN: Return the target pointer result [source:raw]
    // CALL: Invoked by sub_50210E (0050210E) to apply camera rotation state [caller:0x0050210E]

    // Conservative worker pseudocode:
    //   result = a1;
    //   if (fabs(a2 * a3 - 1.0) > 0.05) *(BYTE*)(a1 + 97) |= 0x20;
    //   *(float*)(a1 + 304) = (float)a3;
    //   *(float*)(a1 + 308) = (float)a2;
    //   return result;
    // UNRESOLVED: The meaning of the guarded 1.0-product invariant (dbl_59E420, dbl_5AF428) and what bit 5 of this+0x61 gates downstream is not established from this packet alone
    // UNRESOLVED: Offsets 97, 304, 308 in the raw source correspond to the packet field offsets 0x61, 0x130, 0x134; the exact role of the two stored rotation values is not documented here
}
