// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044ED10
// Canonical corpus name: sub_44ED10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_44ED10_0044ed10.c

void UnknownObject::CollisionDataSetupDispatch()
{
    // Dispatch for incoming collision setup messages. Interprets payload a1 according to message type a2 (18/19/20). Type 18 is acknowledged without any copy. Type 19 copies the payload into the global collision struct byte_7CA594 via CollisionStructCopy_efc0. Type 20 copies the payload into one of two device data buffers (unk_7CB318 or unk_7CB714) via CollisionDataCopy, selecting the destination by the device-create counter dword_7CB310 and incrementing it after the copy. Returns 1 for accepted types and 0 for any other type.
    // GUARD: Message type dispatch: a2 == 18 returns success immediately without copying any payload data. [source:raw]
    // GUARD: Message type dispatch: a2 == 19 selects the global struct copy path; a2 == 20 selects the device data copy path; any other value returns 0 (rejected message). [source:raw]
    // ASSIGNMENT: qmemcpy copies the full incoming payload (145 dwords) from a1 into the local stack buffer v4 before either copy path. [source:raw]
    // CALL: CollisionStructCopy_efc0 writes type ID 19 and the first 61 dwords of v4 into the global collision struct byte_7CA594. [callee:0x0044EFC0, global:0x007CA594]
    // GUARD: Destination selection for type 20: dword_7CB310 == 0 selects unk_7CB318, dword_7CB310 == 1 selects unk_7CB714, and any other value returns 1 without copying. [global:0x007CB310, source:raw]
    // CALL: CollisionDataCopy writes type ID 20 and the first 61 dwords of v4 into the selected destination buffer (unk_7CB318 or unk_7CB714). [callee:0x0044FBB0, global:0x007CB318, global:0x007CB714]
    // STATE_TRANSITION: Increment the device-create counter dword_7CB310 after a type-20 copy so the next type-20 message selects the alternate buffer. [global:0x007CB310]
    // RETURN: Return 1 for accepted types (18/19/20) and 0 for all other types. [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionDataSetupDispatch(const void* payload, int type) {
    //     if (type == 18) return 1;
    //     if (type == 19) {
    //       int buf[145]; memcpy(buf, payload, sizeof(buf));
    //       CollisionStructCopy_efc0(byte_7CA594, 19, buf[0..60]);
    //       return 1;
    //     }
    //     if (type != 20) return 0;
    //     int* dest;
    //     if (dword_7CB310 == 0) dest = unk_7CB318;
    //     else if (dword_7CB310 == 1) dest = unk_7CB714;
    //     else return 1;
    //     int buf[145]; memcpy(buf, payload, sizeof(buf));
    //     CollisionDataCopy(dest, 20, buf[0..60]);
    //     ++dword_7CB310;
    //     return 1;
    //   }
    // UNRESOLVED: Semantic meaning of message types 18/19/20 (collision setup message kinds) is not documented inside this function.
    // UNRESOLVED: byte_7CA594 global collision struct layout and the exact role of dword_7CB310 as a device-create counter are DERIVED from usage only.
    // UNRESOLVED: No static callers are recorded; the dispatch entry path is unknown.
}
