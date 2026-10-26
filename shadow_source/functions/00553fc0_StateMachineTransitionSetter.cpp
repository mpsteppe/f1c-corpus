// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00553FC0
// Canonical corpus name: sub_553FC0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_553FC0_00553fc0.c

void UnknownObject::StateMachineTransitionSetter()
{
    // State-machine transition setter for a mode/state object. Skips entirely when the requested state a2 is -1 or equals the previously stored state this[9] (this+0x24). Per a2 case (0..12) it conditionally writes the three mode fields this[1] (this+0x4), this[2] (this+0x8) and this[3] (this+0xC), skipping a field that already holds its target value, and notifies the GameDeviceObject (dword_8B89A0) through vtable slot +252 with (object, *this id, field index, value). Cases 2/8 and 7/12 route through EnumToFieldOffsetSetter to map (field, value) pairs before the same vtable notify. On the shared exit path the last state this[9] is updated to a2.
    // GUARD: Skip the whole transition when a2 == -1 or a2 equals the previously stored state this[9] (this+0x24). [field:this:0x00000024, source:raw]
    // STATE_TRANSITION: Dispatch on a2 through the switch jump table jpt_553FE4. [global:0x0055422C, source:raw]
    // STATE_TRANSITION: case 0: set mode field this[1] (this+0x4) to 1 unless it already holds 1 (packet guard this+0x4 != 1), then notify the device with (this, 1, 1). [field:this:0x00000004, guard:0, global:0x008B89A0, source:raw]
    // STATE_TRANSITION: case 1: set this[1] (this+0x4) to 2 unless already 2 (guard 1); set this[2] (this+0x8) to 2 unless already 2 (guard 3); set this[3] (this+0xC) to 1 unless already 1 (guard 5); notify the device with (1, 2), (2, 2), (3, 1). [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, guard:1, guard:3, guard:5, global:0x008B89A0, source:raw]
    // STATE_TRANSITION: cases 2 and 8: probe (field, value) pairs via EnumToFieldOffsetSetter(1, 7), then (2, 2), then (3, 1); each nonzero probe triggers the vtable notify. [callee:0x00554260, global:0x008B89A0, source:raw]
    // STATE_TRANSITION: case 4: set this[1] (this+0x4) to 4 unless already 4 (guard 2); set this[2] (this+0x8) to 2 unless already 2 (guard 3); set this[3] (this+0xC) to 1 unless it already holds 1 (guard 6); notify the device with (1, 4), (2, 2), (3, 1). [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, guard:2, guard:3, guard:6, global:0x008B89A0, source:raw]
    // STATE_TRANSITION: case 5: set this[1] (this+0x4) to 2 unless already 2 (guard 1); set this[2] (this+0x8) to 3 unless already 3 (guard 4). [field:this:0x00000004, field:this:0x00000008, guard:1, guard:4, source:raw]
    // STATE_TRANSITION: case 6: set this[1] (this+0x4) to 4 unless already 4 (guard 2); set this[2] (this+0x8) to 2 unless already 2 (guard 3); set this[3] (this+0xC) to 3 unless it already holds 3 (guard 7); notify the device with (1, 4), (2, 2), (3, 3). [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, guard:2, guard:3, guard:7, global:0x008B89A0, source:raw]
    // STATE_TRANSITION: cases 7 and 12: probe (field, value) pairs via EnumToFieldOffsetSetter(1, 4), then (2, 2), then (3, 1); each nonzero probe triggers the vtable notify. [callee:0x00554260, global:0x008B89A0, source:raw]
    // CALL: Virtual notify: call vtable slot +252 on the GameDeviceObject dword_8B89A0 with arguments (object, *this id, field index, value). [field:this:0x00000000, global:0x008B89A0, source:raw]
    // ASSIGNMENT: Store the transitioned state on the shared exit path: this[9] (this+0x24) = a2. [field:this:0x00000024, source:raw]

    // Conservative worker pseudocode:
    //   void sub_553FC0(_DWORD *this, int a2) {
    //     if (a2 == -1 || a2 == this[9]) return;
    //     switch (a2) {
    //     case 0:  if (this[1] != 1) { this[1] = 1; notify(this, 1, 1); } break;
    //     case 1:  if (this[1] != 2) { this[1] = 2; notify(this, 1, 2); }
    //              if (this[2] != 2) { this[2] = 2; notify(this, 2, 2); }
    //              if (this[3] != 1) { this[3] = 1; notify(this, 3, 1); } break;
    //     case 2: case 8:
    //              if (EnumToFieldOffsetSetter(1, 7)) notify(this, 1, 7);
    //              if (EnumToFieldOffsetSetter(2, 2)) notify(this, 2, 2);
    //              if (EnumToFieldOffsetSetter(3, 1)) notify(this, 3, 1); break;
    //     case 4:  if (this[1] != 4) { this[1] = 4; notify(this, 1, 4); }
    //              if (this[2] != 2) { this[2] = 2; notify(this, 2, 2); }
    //              if (this[3] != 1) { this[3] = 1; notify(this, 3, 1); } break;
    //     case 5:  if (this[1] != 2) { this[1] = 2; notify(this, 1, 2); }
    //              if (this[2] != 3) { this[2] = 3; notify(this, 2, 3); } break;
    //     case 6:  if (this[1] != 4) { this[1] = 4; notify(this, 1, 4); }
    //              if (this[2] != 2) { this[2] = 2; notify(this, 2, 2); }
    //              if (this[3] != 3) { this[3] = 3; notify(this, 3, 3); } break;
    //     case 7: case 12:
    //              if (EnumToFieldOffsetSetter(1, 4)) notify(this, 1, 4);
    //              if (EnumToFieldOffsetSetter(2, 2)) notify(this, 2, 2);
    //              if (EnumToFieldOffsetSetter(3, 1)) notify(this, 3, 1); break;
    //     }
    //     this[9] = a2;
    //   }
    // UNRESOLVED: Meaning of the three mode fields this+0x4 / +0x8 / +0xC and of the state enum a2 (0..12) is not established from evidence; the prose label StateMachineTransitionSetter is DERIVED.
    // UNRESOLVED: The vtable+252 notify on dword_8B89A0 (GameDeviceObject): the argument encoding (object id, field index, value) is not confirmed.
    // UNRESOLVED: EnumToFieldOffsetSetter semantics — the (field, value) to offset mapping and the meaning of its nonzero return — are unresolved.
    // UNRESOLVED: The a2 == this[9] check implies a cached-state optimization; on the skip path this[9] is left unchanged.
}
