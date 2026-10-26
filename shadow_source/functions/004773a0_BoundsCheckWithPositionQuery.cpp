// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004773A0
// Canonical corpus name: BoundsCheckWithPositionQuery
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BoundsCheckWithPositionQuery_004773a0.c

void UnknownObject::BoundsCheckWithPositionQuery()
{
    // Reads the current position components into two out parameters via DualFieldRead, then validates a2 (non-null), the X component against the bounding rectangle X range (this+0x120 minimum, this+0x124 maximum) and the Y component against the Y range (this+0x140 minimum, this+0x144 maximum), finishing with a RectangleBoundsCheck. Returns true only when every condition holds.
    // CALL: DualFieldRead writes the current X and Y position components into v4 and v5 respectively. [callee:0x00498880, source:raw]
    // GUARD: Guard on a2 being non-null; the whole position check short-circuits when a2 is zero. [source:raw]
    // GUARD: Guard v4 (current X) must be strictly greater than this[72] (minimum X at this+0x120). [field:this:0x00000120, source:raw]
    // GUARD: Guard v4 (current X) must be strictly less than this[73] (maximum X at this+0x124). [field:this:0x00000124, source:raw]
    // GUARD: Guard v5 (current Y) must be strictly greater than this[80] (minimum Y at this+0x140). [field:this:0x00000140, source:raw]
    // GUARD: Guard v5 (current Y) must be strictly less than this[81] (maximum Y at this+0x144). [field:this:0x00000144, source:raw]
    // CALL: RectangleBoundsCheck(v4, v5) performs the final rectangle containment validation. [callee:0x0048EA60, source:raw]
    // RETURN: Return the logical AND of the a2 guard, the four range guards and the RectangleBoundsCheck result; invoked by LinkedListTraversalVirtualCall (00477160). [source:raw, function:0x004773A0, caller:0x00477160]

    // Conservative worker pseudocode:
    //   bool sub_4773A0(int *this, int a2) {
    //     int v4, v5;
    //     DualFieldRead(&v4, &v5);
    //     return a2 != 0
    //         && v4 > this[72] && v4 < this[73]
    //         && v5 > this[80] && v5 < this[81]
    //         && RectangleBoundsCheck(v4, v5);
    //   }
    // UNRESOLVED: The object type owning the bounding rectangle fields at this+0x120/0x124/0x140/0x144 is unknown; the coordinate frame and units of the positions written by DualFieldRead (00498880) are not established in this packet.
    // UNRESOLVED: The exact containment semantics of RectangleBoundsCheck (0048EA60) beyond a boolean pass/fail are not documented in this packet.
}
