// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051BFA6
// Canonical corpus name: VehicleStructFieldCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleStructFieldCopy_0051bfa6.c

void UnknownObject::CopyDimensionsToTarget()
{
    // Unconditional field-level copy: loads the target sub-struct pointer from this+0x19C, then copies two values (from this+0x110 and this+0x60) into the target sub-struct fields at this+0x1F8 (target+0x5C) and this+0x1FC (target+0x60). Returns the value read from this+0x60.
    // ASSIGNMENT: Load target sub-struct pointer from field at this+0x19C into a local register. [field:this:0x0000019C, abi:lead]
    // ASSIGNMENT: Write value read from this+0x110 into the target sub-struct field at this+0x1F8 (target offset 0x5C). [field:this:0x00000110, field:this:0x000001F8]
    // ASSIGNMENT: Read value from this+0x60 and write it into the target sub-struct field at this+0x1FC (target offset 0x60). [field:this:0x00000060, field:this:0x000001FC]
    // RETURN: Return the value read from this+0x60 as the function result. [function:0x0051BFA6, source:raw, field:this:0x00000060]

    // Conservative worker pseudocode:
    //   target = *(uint32_t*)((uint8_t*)this + 0x19C);
    //   *(uint32_t*)((uint8_t*)target + 0x5C) = *(uint32_t*)((uint8_t*)this + 0x110);
    //   result = *(uint32_t*)((uint8_t*)this + 0x60);
    //   *(uint32_t*)((uint8_t*)target + 0x60) = result;
    //   return result;
    // UNRESOLVED: Purpose and type of the target sub-struct reached through this+0x19C are unknown; no static callers were identified for this function.
}
