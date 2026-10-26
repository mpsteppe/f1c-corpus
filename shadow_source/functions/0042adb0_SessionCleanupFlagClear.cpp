// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042ADB0
// Canonical corpus name: SessionCleanupFlagClear
// Owner: F1CVehicle [CONFIRMED]
// Raw source: functions/SessionCleanupFlagClear_0042adb0.c

void F1CVehicle::SessionCleanupFlagClear()
{
    // Per-frame session-active flag setter on an F1CVehicle. Reads the RetiredFlag byte at +0x4410; if the vehicle is not retired, clears the cleanup/disqualification flag at +0x4424 to 0 and sets +0x45F4 to 1 to mark the session active. Returns the original retired byte regardless of path.
    // GUARD: Read the RetiredFlag byte at +0x4410 into result. [field:this:0x00004410, source:raw]
    // ASSIGNMENT: If result is zero (not retired), write 0 to +0x4424 (cleanup/disqualification flag). [field:this:0x00004410, field:this:0x00004424, source:raw]
    // ASSIGNMENT: If result is zero, write byte 1 to +0x45F4 (AIControlFlag), marking the session active. [field:this:0x00004410, field:this:0x000045F4, source:raw]
    // RETURN: Return the saved retired byte (nonzero when the writes were skipped). [source:raw]

    // Conservative worker pseudocode:
    //   result = *(byte*)(this + 0x4410);
    //   if (!result) {
    //       *(dword*)(this + 0x4424) = 0;
    //       *(byte*)(this + 0x45F4) = 1;
    //   }
    //   return result;
    // UNRESOLVED: The packet field list names +0x45F4 'AIControlFlag' (CONFIRMED) while the existing analysis calls it 'ActiveFlag' [FACT]; the two names are not reconciled within the packet.
    // UNRESOLVED: The semantics of +0x4424 (cleanup/disqualification flag) come from existing-analysis prose; packet evidence only shows the literal zeroing and the 1.0-byte write pattern.
}
