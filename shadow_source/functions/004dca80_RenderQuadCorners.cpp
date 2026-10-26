// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DCA80
// Canonical corpus name: sub_4DCA80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4DCA80_004dca80.c

void UnknownObject::RenderQuadCorners()
{
    // Renders a four-corner quad by calling sub_553650 four times, once per corner/segment with mode 0-3. Corner base position comes from this+8 and this+12, the width/height extents from this+20 and this+24, and per-corner X/Y deltas from the floats at this+32 and this+36. The last argument passed to every call is the parameter id at this+28. Entire render is skipped when the dword at this+0 is zero.
    // GUARD: Reads the dword at this+0 (enable flag); when it is zero the function returns immediately without rendering, leaving the return value uninitialized [field:this:0x00000000, source:raw]
    // CALL: Calls sub_553650 with mode 0, X from this+8, Y from this+12, Z from this+16, zero X/Y deltas, and the parameter id from this+28 [callee:0x00553650, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x0000001C, source:raw]
    // CALL: Calls sub_553650 with mode 1, X from this+8, Y as this+12 plus the height offset at this+24, Z from this+16, X delta zero, Y delta from this+36, and the parameter id from this+28 [callee:0x00553650, field:this:0x00000018, field:this:0x00000024, field:this:0x0000001C, source:raw]
    // CALL: Calls sub_553650 with mode 2, X as this+8 plus the width offset at this+20, Y as this+12 plus the height offset at this+24, Z from this+16, X delta from this+32, Y delta from this+36, and the parameter id from this+28 [callee:0x00553650, field:this:0x00000014, field:this:0x00000018, field:this:0x00000020, field:this:0x00000024, field:this:0x0000001C, source:raw]
    // CALL: Calls sub_553650 with mode 3, X as this+8 plus the width offset at this+20, Y from this+12, Z from this+16, X delta from this+32, Y delta zero, and the parameter id from this+28; returns that call's result [callee:0x00553650, field:this:0x00000014, field:this:0x00000020, field:this:0x0000001C, source:raw]

    // Conservative worker pseudocode:
    //   if (!*(this)) return result;
    //   sub_553650(0, *(this + 8), *(this + 12), *(this + 16), 0.0, 0.0, *(this + 28));
    //   sub_553650(1, *(this + 8), *(this + 12) + *(this + 24), *(this + 16), 0.0, *(float*)(this + 36), *(this + 28));
    //   sub_553650(2, *(this + 8) + *(this + 20), *(this + 12) + *(this + 24), *(this + 16), *(float*)(this + 32), *(float*)(this + 36), *(this + 28));
    //   return sub_553650(3, *(this + 8) + *(this + 20), *(this + 12), *(this + 16), *(float*)(this + 32), 0.0, *(this + 28));
    // UNRESOLVED: The rendering semantics of sub_553650 (mode meaning, draw primitive) are defined in that function, not in this packet
    // UNRESOLVED: The return value when the this+0 guard fails is an uninitialized register; its use by callers is unknown
    // UNRESOLVED: The exact meaning of the parameter id passed as the last argument from this+28 is not defined in this packet
    // UNRESOLVED: Callers on the frame path are TwoFieldSetterUpdate, PositionComputationWithAlignment and FieldSetterCall, but whether this descriptor is UI or world-space geometry is not established
}
