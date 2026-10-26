// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00464A40
// Canonical corpus name: CollisionSensorInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionSensorInit_00464a40.c

void UnknownObject::CollisionSensorInit()
{
    // Collision sensor initializer on a this object: writes near -FLT_MAX to the float at this+0x71, clears the byte at this+0x6C, zeros the dword at this+0x68, and returns 0. Linear, no guards, no calls.
    // ASSIGNMENT: Initialize the return value result to 0. [source:raw]
    // ASSIGNMENT: Write -9.9999997e37 (near -FLT_MAX, the sensor detection-value sentinel per existing analysis) to the float field at this+0x71. [field:this:0x00000071, source:raw]
    // ASSIGNMENT: Clear the byte at this+0x6C to 0 (collision detection flag per existing analysis). [field:this:0x0000006C, source:raw]
    // ASSIGNMENT: Zero the dword at this+0x68 (contact counter per existing analysis). [field:this:0x00000068, source:raw]
    // RETURN: Return result, which was set to 0 at entry. [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionSensorInit(int this) {
    //       *(float *)(this + 113) = -9.9999997e37f;
    //       *(_BYTE *)(this + 108) = 0;
    //       *(_DWORD *)(this + 104) = 0;
    //       return 0;
    //   }
    // UNRESOLVED: flt_59F130 is flagged as read (R) in the packet globals but does not appear in the raw source; existing analysis names it DefaultSensorValue. Whether this function reads it — possibly the default the literal -9.9999997e37 approximates — is unresolved.
    // UNRESOLVED: Field roles at this+0x68 (contact count), this+0x6C (collision flag byte) and this+0x71 (sensor detection value) come from existing analysis and are DERIVED; equal offsets on unrelated this pointers are not proof of a shared class.
    // UNRESOLVED: The owner class is unknown; thiscall suggests a member of the large object initialized by LargeStructInitialization (0x00464C10), but no owning class is evidenced.
}
