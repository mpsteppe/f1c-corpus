// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005542F0
// Canonical corpus name: sub_5542F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5542F0_005542f0.c

void UnknownObject::SecondaryStateMachineTransitionSetter()
{
    // Secondary state-machine transition handler. Guards on the new state a2 being valid and different from the last state stored at this[10]. Dispatches a2 (0-4) via a jump table to set the mode sub-fields this[6]/this[7]/this[8] (offsets 0x18/0x1C/0x20) to small integer modes, skipping a write when the field already holds the target value, and notifying the device object at dword_8B89A0 through vtable offset +252. Stores a2 back into this[10] at the end.
    // GUARD: Guard on the transition: skip entirely when a2 == -1 or a2 equals the last stored state this[10]. [field:this:0x00000028, source:raw]
    // GUARD: Dispatch on a2 through the jump table jpt_554314 over cases 0-4. [global:0x005544A8, source:raw]
    // STATE_TRANSITION: Cases 0 and 1 set this[6] (offset 0x18) to 2, guarded by guard:0; case 2 sets it to 4, guarded by guard:1. [field:this:0x00000018, guard:0, guard:1, source:raw]
    // CALL: Notify the device object dword_8B89A0 via vtable offset +252 with mode 4 when this[6] changes. [field:this:0x00000000, global:0x008B89A0, source:raw]
    // STATE_TRANSITION: Case 0 sets this[7] (offset 0x1C) to 2 (guard:2); case 1 sets it to 1 (guard:3); case 2 sets it to 2 (guard:2); when it changes, the value flows to the vtable +252 notification as the payload. [field:this:0x0000001C, guard:2, guard:3, source:raw]
    // STATE_TRANSITION: Case 2 sets this[8] (offset 0x20) to 1, guarded by guard:4, and notifies with mode 6. [field:this:0x00000020, guard:4, source:raw]
    // CALL: Cases 3 and 4 route through EnumToFieldOffsetSetter on this+1 instead of direct field writes, then notify through vtable +252 when it reports a change. [callee:0x00554260, source:raw]
    // ASSIGNMENT: Persist the accepted transition: this[10] (offset 0x28) = a2. [field:this:0x00000028, source:raw]
    // CALL: Invoked by MultiFieldSetterDispatchingTo7SubSetters (0x005546A0) as one of several sub-state setters. [caller:0x005546A0, source:raw]

    // Conservative worker pseudocode:
    //   void sub_5542F0(int *this, int a2) {
    //     if (a2 == -1 || a2 == this[10]) return;
    //     switch (a2) {
    //       case 0: case 1:
    //         if (this[6] != 2) { this[6] = 2; notify(dword_8B89A0, *this, 4, 2); }
    //         if (this[7] != 2) { this[7] = 2; notify(dword_8B89A0, *this, 5, 2); }
    //         break;
    //       case 2:
    //         if (this[6] != 4) { this[6] = 4; notify(dword_8B89A0, *this, 4, 4); }
    //         if (this[7] != 2) { this[7] = 2; notify(dword_8B89A0, *this, 5, 2); }
    //         if (this[8] != 1) { this[8] = 1; notify(dword_8B89A0, *this, 6, 1); }
    //         break;
    //       case 3:
    //         if (EnumToFieldOffsetSetter(this+1, 4, 2)) notify(dword_8B89A0, *this, 4, 2);
    //         if (EnumToFieldOffsetSetter(this+1, 5, 2)) notify(dword_8B89A0, *this, 5, 2);
    //         break;
    //       case 4:
    //         if (EnumToFieldOffsetSetter(this+1, 4, 2)) notify(dword_8B89A0, *this, 4, 2);
    //         if (EnumToFieldOffsetSetter(this+1, 5, 3)) notify(dword_8B89A0, *this, 5, 3);
    //         break;
    //     }
    //     this[10] = a2;
    //   }
    // UNRESOLVED: Enum values written to this[6]/this[7]/this[8] (2, 4, 1) and the notify modes (4, 5, 6) have no packet-grounded meaning; the state-machine role is inferred from the field-change guard pattern.
    // UNRESOLVED: The _DWORD*-24 / -28 / -32 self-pointer comparisons are decompiler artifacts and their runtime meaning is unknown.
}
