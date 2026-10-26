// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E2370
// Canonical corpus name: MultiplayerSessionType
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiplayerSessionType_004e2370.c

void UnknownObject::MultiplayerSessionType()
{
    // Configures a multiplayer session mode: maps the session-type argument a2 onto a mode value stored at this+0xB6C, then initializes four session-slot entries starting at this+0x1EC (stride 0x128) to -1 (invalid). Session-type cases 4, 5 and 6 map to mode values 1, 2 and 3; cases 1, 2 and 3 all map to mode 0; the default case stores a2 itself as the mode. Called from sub_4F18C0 on the frame path.
    // ASSIGNMENT: Clear the session mode field at this+0xB6C to 0 before the switch. [field:this:0x00000B6C, source:raw]
    // STATE_TRANSITION: Session-type cases 4, 5 and 6 set the mode field at this+0xB6C to 1, 2 and 3 respectively. [field:this:0x00000B6C, source:raw]
    // STATE_TRANSITION: Session-type cases 1, 2 and 3 all reset the mode field at this+0xB6C back to 0. [field:this:0x00000B6C, source:raw]
    // ASSIGNMENT: Default case: store the session-type argument a2 itself as the mode value at this+0xB6C. [field:this:0x00000B6C, source:raw]
    // LOOP: Initialize 4 session-slot entries starting at this+0x1EC with a 74-dword (0x128 byte) stride, writing -1 into each. [field:this:0x000001EC, source:raw]
    // RETURN: Return the cursor register after the loop (points at this+0x1EC, one stride past the last slot). [field:this:0x000001EC, source:raw]

    // Conservative worker pseudocode:
    //   void MultiplayerSessionType(char* this, int sessionType) {
    //     *(int*)(this + 0xB6C) = 0;
    //     switch (sessionType) {
    //       case 4: *(int*)(this + 0xB6C) = 1; break;
    //       case 5: *(int*)(this + 0xB6C) = 2; break;
    //       case 6: *(int*)(this + 0xB6C) = 3; break;
    //       case 1: case 2: case 3: *(int*)(this + 0xB6C) = 0; break;
    //       default: *(int*)(this + 0xB6C) = sessionType; break;
    //     }
    //     for (int i = 0; i < 4; i++)
    //       *(int*)(this + 0x1EC + i * 0x128) = -1;
    //   }
    // UNRESOLVED: The exact session-type enum semantics (which game session types map to modes 1, 2 and 3 versus mode 0) are unknown; the numeric mapping is locked but its meaning is not.
    // UNRESOLVED: What the four -1-initialized slot entries at this+0x1EC represent (stride 0x128) is unknown.
    // UNRESOLVED: Why the default case stores a2 raw while the enumerated cases normalize it is unresolved.
    // UNRESOLVED: The owner of this object is unknown; no class or subsystem evidence is available in the packet.
}
