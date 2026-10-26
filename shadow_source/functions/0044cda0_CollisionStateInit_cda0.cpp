// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CDA0
// Canonical corpus name: CollisionStateInit_cda0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionStateInit_cda0_0044cda0.c

void UnknownObject::CollisionStateInit_cda0()
{
    // Collision state initializer: seeds global dword_7CD0F8 with 34 and global flt_7CD0FC with 0.0, then delegates to CollisionScaleInit to set collision-scale globals. No arguments, guards, or other calls in this packet's evidence.
    // ASSIGNMENT: Store the integer literal 34 into global dword_7CD0F8. [global:0x007CD0F8, source:raw]
    // ASSIGNMENT: Store 0.0 into global flt_7CD0FC. [global:0x007CD0FC, source:raw]
    // CALL: Call CollisionScaleInit() (named in the raw source; address not evidenced in this packet's allowed refs) to initialize collision-scale state. [source:raw]

    // Conservative worker pseudocode:
    //   void CollisionStateInit_cda0() {
    //     dword_7CD0F8 = 34;
    //     flt_7CD0FC = 0.0;
    //     CollisionScaleInit();
    //   }
    // UNRESOLVED: Role of the value 34 in dword_7CD0F8 (possible count or mode; not grounded).
    // UNRESOLVED: Target address of the CollisionScaleInit call is not in the packet's callee evidence; identity rests on the raw-source name only.
    // UNRESOLVED: Consumers of globals 0x7CD0F8 and 0x7CD0FC not established from this packet.
}
