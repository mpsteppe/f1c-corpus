// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053C160
// Canonical corpus name: sub_53C160
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53C160_0053c160.c

void UnknownObject::initializeOnce()
{
    // One-time initialization helper guarded by the flag byte_8B8EE4: when bit 0 is clear it sets that bit and calls EmptyStub_7470 with the address of unk_8B6BD0, so the underlying setup runs at most once. The referenced function's own address is taken by sub_53C150 and passed to BooleanToIntConversion, hinting this is a lazily-installed handler or callback, though that coupling is not evidenced in this packet.
    // GUARD: Check bit 0 of byte_8B8EE4; when it is already set the function does nothing [global:0x008B8EE4, source:raw]
    // ASSIGNMENT: Set bit 0 of byte_8B8EE4 to record that the one-time initialization has been performed [global:0x008B8EE4, source:raw]
    // CALL: Call EmptyStub_7470 passing the address of unk_8B6BD0 to perform the guarded one-time setup [global:0x008B6BD0, source:raw]

    // Conservative worker pseudocode:
    //   if ((byte_8B8EE4 & 1) == 0) {
    //     byte_8B8EE4 |= 1;
    //     EmptyStub_7470(&unk_8B6BD0);
    //   }
    // UNRESOLVED: The purpose of unk_8B6BD0 and the body of EmptyStub_7470 are not defined in this packet; EmptyStub_7470 itself is not listed in the packet's callee evidence
    // UNRESOLVED: The coupling with sub_53C150 (which takes this function's address) is inferred from the sibling packet and is not evidenced here
    // UNRESOLVED: Why the guard is a bit-flag on a byte rather than a dedicated boolean is unresolved
}
