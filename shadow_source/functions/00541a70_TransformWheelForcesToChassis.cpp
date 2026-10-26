// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00541A70
// Canonical corpus name: TransformWheelForcesToChassis
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TransformWheelForcesToChassis_00541a70.c

void UnknownObject::TransformWheelForcesToChassis()
{
    // Transforms per-wheel suspension forces from the wheel frame into the chassis frame. First copies a 4x4 matrix (16 dwords) from this+0x15C into a local buffer. Then iterates over 6 wheel entries (16 bytes each, starting at this+0x104); for each wheel it calls a device-wrapper vtable method through global dword_8B8F24 that transforms the wheel force using the local matrix, and combines the transformed components (including a per-wheel pivot term at the two floats preceding each entry) into the wheel's output force slot. For wheel indices 4 and 5 an additional device-wrapper method (second vtable slot, same global) transforms an auxiliary vector, then the chassis position offset components this+0x24/+0x28/+0x2C are accumulated into the result. Returns the last call's result.
    // LOOP: Copy 16 dwords (a 4x4 matrix) from this+0x15C into a local 4x4 matrix buffer (v17). [field:this:0x0000015C, source:raw]
    // LOOP: Iterate over 6 wheel entries, each 16 bytes, starting at this+0x104, advancing the pointer by 16 bytes per wheel. [field:this:0x00000104, source:raw]
    // CALL: For every wheel, call the device-wrapper vtable slot 0 method through global dword_8B8F24, passing the wrapper instance, the wheel data pointer, the two pre-wheel pivot floats, and the local matrix buffer; it transforms the wheel suspension force into the chassis frame. [global:0x008B8F24, source:raw]
    // CALL: For wheel indices 4 and 5 only, call the device-wrapper vtable slot 4 method through global dword_8B8F24 with an auxiliary 3-float vector (v16) and an output vector (v13), feeding it the same local matrix buffer. [global:0x008B8F24, source:raw]
    // CALCULATION: Accumulate the chassis position offset components this+0x24, this+0x28 and this+0x2C into the transformed output vector components. [field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, source:raw]
    // CALCULATION: Combine transformed force components (sum of two cross terms plus the pivot term scaled by the first local pivot float) and store the result into the wheel's output force slot at the three floats preceding the wheel entry. [source:raw]
    // RETURN: Return the result of the last device-wrapper call. [source:raw]

    // Conservative worker pseudocode:
    //   int TransformWheelForcesToChassis(float* this) {
    //     float local[16]; copy16(local, this + 87);  /* this+0x15C * /
    //     for (int w = 0; w < 6; ++w) {
    //       float* wheel = this + 65 + 4 * w;  /* this+0x104 + 16*w * /
    //       result = d3dWrapper_vtable0(d3dWrapper, wheel - 26, wheel - 2, local);
    //       if (w >= 4) {
    //         vec3 aux = { 0, 0, wheel[-23] };
    //         result = d3dWrapper_vtable4(d3dWrapper, &aux, &out, local);
    //         out += (this[9], this[10], this[11]);  /* this+0x24/+0x28/+0x2C * /
    //         v11 = out.y * wheel[-1] + out.z * wheel[0];
    //         v12 = out.x;
    //       } else {
    //         v11 = wheel[-1] * this[10] + wheel[0] * this[11];
    //         v12 = this[9];
    //       }
    //       wheel[-3] = v11 + v12 * wheel[-2];
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The two indirect calls go through vtable slots of the device wrapper referenced by global dword_8B8F24; the packet does not identify the wrapper class or the exact math performed inside.
    // UNRESOLVED: The local 16-dword buffer is described as a rotation matrix only from the existing analysis (DERIVED); the packet itself shows only a raw 16-dword copy.
    // UNRESOLVED: The wheel stride (16 bytes) and the interpretation of this+0x104 as per-wheel suspension data are DERIVED from the indexing arithmetic, not named by the packet.
    // UNRESOLVED: The precise meaning of the pivot floats preceding each wheel entry and the auxiliary vector for wheels 4-5 is not resolved.
}
