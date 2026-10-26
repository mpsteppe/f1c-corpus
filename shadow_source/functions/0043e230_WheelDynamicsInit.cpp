// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0043E230
// Canonical corpus name: WheelDynamicsInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WheelDynamicsInit_0043e230.c

void UnknownObject::WheelDynamicsInit()
{
    // Wheel dynamics initialization for the physics object: writes one global value into a settable parameter (SimpleSetterWithFlag on byte_7C56C0), then for 4 wheels pushes contact constraints, a parameter value and a 3-slot physics grid into global storage; destroys a global resource, clears a physics buffer, zeroes a config field, runs sub_56E970, frees two optional heap pointers (FreeWrapper_7bcf on this+0x1CFC / this+0x162C), memsets the whole object (0x1F38 bytes), and finally fills 4 strided wheel-struct blocks (1124-byte stride, wheel 0 at this+0x5D8) with a fixed default bit-pattern pair (-1889785610 / 1081507266).
    // CALL: Read the double at this+0x1D4C, truncate to float, and push it into the global setter buffer via SimpleSetterWithFlag(&byte_7C56C0, value). [field:this:0x00001D4C, callee:0x00431A50, global:0x007C56C0, source:raw]
    // LOOP: For wheel index v2 = 0..3 over the strided wheel block anchored at this+0x6B8 (stride 1124 bytes): read the value at the anchor minus 5 doubles and call SetContactConstraint(&byte_7C56C0, v2, value); read the value at the anchor and call ParameterArraySetterWithDirtyFlag(&byte_7C56C0, v2, value); then for slot v4 = 0..2 read the value at the anchor minus 28 doubles plus slot and call PhysicsGridValueSet(&byte_7C56C0, v2, v4, value). [field:this:0x000006B8, callee:0x00431930, callee:0x004319C0, callee:0x00431A70, global:0x007C56C0, source:raw]
    // CALL: Destroy the global resource object dword_8AD238 via ResourceDestroy. [callee:0x004D5840, global:0x008AD238, source:raw]
    // CALL: Clear the 40-dword physics buffer at this+492 via PhysicsBufferClear. [callee:0x004358F0, source:raw]
    // ASSIGNMENT: Zero the dword at this+0x1F00. [field:this:0x00001F00, source:raw]
    // CALL: Call sub_56E970 on the sub-object at this+5548. [callee:0x0056E970, source:raw]
    // GUARD: If the pointer at this+0x1CFC is non-null, free it via FreeWrapper_7bcf. [field:this:0x00001CFC, callee:0x00587BCF, source:raw]
    // GUARD: If the pointer at this+0x162C is non-null, free it via FreeWrapper_7bcf. [field:this:0x0000162C, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the whole object: memset(this, 0, 0x1F38). [source:raw]
    // LOOP: For wheel struct v6 = 0..3 at strided base starting this+0x5D8 (1124-byte stride): tag the dword at base minus 181 dwords with the wheel index; write default pattern -1889785610 to this+0x5D8 and 1081507266 (3.8514f) to this+0x5DC; propagate the pattern so this+0x5E0 = value of this+0x5D8, this+0x5E4 = value of this+0x5DC, this+0x5E8 = value of this+0x5E0, and this+0x5EC = value of this+0x5E4. [field:this:0x000005D8, field:this:0x000005DC, field:this:0x000005E0, field:this:0x000005E4, field:this:0x000005E8, field:this:0x000005EC, source:raw]
    // RETURN: Return the dword pointer one past the last filled wheel-struct block. [function:0x0043E230, source:raw]

    // Conservative worker pseudocode:
    //   SimpleSetterWithFlag(&byte_7C56C0, (float)*(double*)(this+0x1D4C));
    //   for (wheel = 0; wheel < 4; wheel++) {
    //     base = this + 0x6B8 + wheel * 1124;
    //     SetContactConstraint(&byte_7C56C0, wheel, *(base - 20));
    //     ParameterArraySetterWithDirtyFlag(&byte_7C56C0, wheel, *base);
    //     for (slot = 0; slot < 3; slot++) PhysicsGridValueSet(&byte_7C56C0, wheel, slot, *(base - 112 + slot));
    //   }
    //   ResourceDestroy(&dword_8AD238);
    //   PhysicsBufferClear(this + 492);
    //   *(this + 0x1F00) = 0;
    //   sub_56E970(this + 5548);
    //   if (*(this + 0x1CFC)) FreeWrapper_7bcf(*(this + 0x1CFC));
    //   if (*(this + 0x162C)) FreeWrapper_7bcf(*(this + 0x162C));
    //   memset(this, 0, 0x1F38);
    //   for (i = 0; i < 4; i++) { /* strided wheel struct default pattern * / }
    // UNRESOLVED: sub_56E970 (this+0x15AC) purpose unknown; it is invoked between buffer clear and the heap-pointer frees.
    // UNRESOLVED: The wheel-struct tag write at base minus 181 dwords lands on an offset that is not enumerated among the packet fields.
    // UNRESOLVED: The 1124-byte wheel stride and the sub-offsets consumed by the setters are not individually enumerated in the packet field list (covered via source:raw only).
    // UNRESOLVED: Semantic role of the 0x1F38-byte object-level memset (resets the entire physics object after sub-resource teardown).
}
