// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00542400
// Canonical corpus name: StructFieldArrayCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructFieldArrayCopy_00542400.c

void UnknownObject::StructFieldArrayCopy()
{
    // Copies the 64-byte field block at this+348 into the caller-provided destination a2 when a2 is non-null. A small __thiscall field-array copy helper; its caller RaySphereIntersectionTest uses the copy to snapshot a struct/transform field array for a pick test.
    // GUARD: Guard on a2: perform the copy only when the destination pointer a2 is non-null. [source:raw]
    // ASSIGNMENT: Copy 64 bytes (0x40) from this+348 into a2 via qmemcpy. [source:raw]
    // RETURN: Implicit void return; no value is produced. [source:raw]

    // Conservative worker pseudocode:
    //   void StructFieldArrayCopy(int this, void *a2) {
    //     if (a2) qmemcpy(a2, (const void *)(this + 348), 0x40);
    //   }
    // UNRESOLVED: Meaning and layout of the 64-byte field array at this+348 are unknown; the caller consumes it as a snapshot buffer.
    // UNRESOLVED: The object owning this method is unknown.
}
