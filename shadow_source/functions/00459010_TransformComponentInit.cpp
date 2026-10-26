// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00459010
// Canonical corpus name: ComponentTransformInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ComponentTransformInitializer_00459010.c

void UnknownObject::TransformComponentInit()
{
    // Initializes a transform/physics component to a default state. Zeroes a local 3-dword vector and copies it into the object's base fields via StructFieldCopy, sets the dword counter/state at this+0xBC to 0, clears the byte at this+0xCC, sets the scale factor dword at this+0xAC to 1065353216 (1.0f), copies the base position/transform into the saved slot at this+144 via VectorCopy, sets the active flag byte at this+0xA0 to 1, and returns the VectorCopy result (this).
    // CALL: Zero-initializes the local 3-dword vector v3 via memset [source:raw]
    // CALL: Copies the zero vector v3 into the object's base fields via StructFieldCopy, zeroing the position/transform region [callee:0x00456150, source:raw]
    // ASSIGNMENT: Sets the dword at this+0xBC to 0 (counter or state field) [field:this:0x000000BC, source:raw]
    // ASSIGNMENT: Clears the byte at this+0xCC to 0 [field:this:0x000000CC, source:raw]
    // ASSIGNMENT: Sets the dword at this+0xAC to 1065353216, which is the IEEE-754 single-precision pattern for 1.0f (default scale factor) [field:this:0x000000AC, source:raw]
    // CALL: Copies the base position/transform (this+0x0) into the saved slot at this+144 via VectorCopy [callee:0x00456130, source:raw]
    // ASSIGNMENT: Sets the active/initialized flag byte at this+0xA0 to 1 [field:this:0x000000A0, source:raw]
    // RETURN: Returns the VectorCopy result pointer (this) [source:raw]

    // Conservative worker pseudocode:
    //   memset(v3, 0, 12);
    //   StructFieldCopy(this, v3);
    //   this[0xBC] = 0;
    //   this[0xCC] = 0;
    //   this[0xAC] = 1065353216;
    //   result = VectorCopy(this, this + 144);
    //   this[0xA0] = 1;
    //   return result;
    // UNRESOLVED: The semantic meaning of the saved slot at this+144 and of the 1.0f scale at this+0xAC is not confirmed by this packet alone; both are inferred from the initialization pattern
    // UNRESOLVED: The concrete component type owning this initializer is unknown; the function has no static callers in this packet
    // UNRESOLVED: The base-field region written by StructFieldCopy is described only by the copy destination; its individual members are not enumerated here
}
