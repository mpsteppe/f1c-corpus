// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B0B10
// Canonical corpus name: ShortComputation_0b10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_0b10_004b0b10.c

void UnknownObject::GetMemberPtr20()
{
    // Trivial accessor: returns the pointer this + 20 (byte offset 20 into the owning object). No side effects, no reads beyond computing the address. Callers live in the PhysicsFilePathBuild module area, but the object type and the member at byte offset 20 are not established by the packet.
    // RETURN: Return this + 20: the address of the member (or embedded sub-object) located 20 bytes into the object pointed to by this. [function:0x004B0B10, source:raw]

    // Conservative worker pseudocode:
    //   void* GetMemberPtr20(void* this) {
    //       return this + 20;
    //   }
    // UNRESOLVED: Which member lives at byte offset 20 of this is unknown; the packet carries no field or writer evidence for it.
    // UNRESOLVED: The caller names suggest a physics-file-path object, but that connection is not evidenced, so the owner stays UNKNOWN.
}
