// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044F73C
// Canonical corpus name: CursorScrollPositionTracker
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CursorScrollPositionTracker_0044f73c.c

void UnknownObject::UpdateCursorScrollPosition()
{
    // Updates a cursor scroll/drag center to new input coordinates, clamps the center within viewport bounds, and writes both normalized deltas (current center minus previous center, scaled) and normalized clamped positions into the tracker's float fields. Reads viewport bounds at this+0x0/0x4/0x8/0xC and per-axis scaling factors at this+0x18/0x1C. Returns the maximum Y bound stored at this+0x4.
    // CALCULATION: Compute the raw vertical delta v9 as the new Y coordinate a3 minus the previous center Y stored at this+0x14 (dword index 5). [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Write the normalized delta X to this+0x20 (dword index 8): the difference between the incoming X coordinate a2 and the previous center X at this+0x10, multiplied by the X scale at this+0x18 (dword index 6). [field:this:0x00000010, field:this:0x00000018, field:this:0x00000020, source:raw]
    // ASSIGNMENT: Store the incoming X coordinate a2 as the new center X at this+0x10 (dword index 4). [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Write the normalized delta Y to this+0x24 (dword index 9): the raw vertical delta v9 multiplied by the Y scale at this+0x1C (dword index 7). [field:this:0x0000001C, field:this:0x00000024, source:raw]
    // GUARD: Clamp the center X at this+0x10 to the minimum bound at this+0x8 (dword index 2) when the incoming X coordinate a2 is below that bound. [field:this:0x00000008, field:this:0x00000010, source:raw]
    // GUARD: Clamp the center X at this+0x10 to the maximum bound at this+0xC (dword index 3) when it exceeds that bound. [field:this:0x0000000C, field:this:0x00000010, source:raw]
    // ASSIGNMENT: Store the incoming Y coordinate a3 as the new center Y at this+0x14 (dword index 5). [field:this:0x00000014, source:raw]
    // GUARD: Clamp the center Y at this+0x14 to the minimum bound at this+0x0 (float, truncated when compared) when the incoming Y coordinate a3 is below it. [field:this:0x00000000, field:this:0x00000014, source:raw]
    // GUARD: Clamp the center Y at this+0x14 to the maximum bound at this+0x4 (dword index 1) when it exceeds that bound; that bound value is also the function return value. [field:this:0x00000004, field:this:0x00000014, source:raw]
    // ASSIGNMENT: Write the normalized clamped X to this+0x28 (dword index 10): the clamped center X at this+0x10 multiplied by the X scale at this+0x18. [field:this:0x00000010, field:this:0x00000018, field:this:0x00000028, source:raw]
    // ASSIGNMENT: Write the normalized clamped Y to this+0x2C (dword index 11): the clamped center Y at this+0x14 multiplied by the Y scale at this+0x1C. [field:this:0x00000014, field:this:0x0000001C, field:this:0x0000002C, source:raw]
    // RETURN: Return the maximum Y bound read from this+0x4 (dword index 1). [field:this:0x00000004, source:raw]

    // Conservative worker pseudocode:
    //   float UpdateCursorScrollPosition(float* this, int a2, int a3, int a4, int a5) {
    //     int v9 = a3 - *((int*)this + 5);
    //     int v5 = *((int*)this + 2);
    //     this[8] = (float)(a2 - *((int*)this + 4)) * this[6];
    //     *((int*)this + 4) = a2;
    //     this[9] = (float)v9 * this[7];
    //     if (a2 < v5) *((int*)this + 4) = v5;
    //     if (*((int*)this + 4) > *((int*)this + 3)) *((int*)this + 4) = *((int*)this + 3);
    //     *((int*)this + 5) = a3;
    //     if (a3 < (int)this[0]) this[5] = this[0];
    //     if (*((int*)this + 5) > *((int*)this + 1)) *((int*)this + 5) = *((int*)this + 1);
    //     this[10] = (float)*((int*)this + 4) * this[6];
    //     this[11] = (float)*((int*)this + 5) * this[7];
    //     return *((int*)this + 1);
    //   }
    // UNRESOLVED: The exact meaning of the scale factors at this+0x18 and this+0x1C (interpreted as reciprocal half-width/height by the existing analysis) is DERIVED, not proven by the raw source.
    // UNRESOLVED: The owner object and its class are not evidenced in this packet; the packet lists no callers or callees.
    // UNRESOLVED: The third and fourth parameters a4/a5 are unused in the function body.
}
