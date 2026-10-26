// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049B1C0
// Canonical corpus name: StaticArrayCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StaticArrayCleanup_0049b1c0.c

void UnknownObject::StaticArrayCleanup()
{
    // Iterates the dword array starting at dword_7CE23C up to the unk_7CE24C sentinel. For each non-null slot it runs resource cleanup twice (ResourceCleanup_cd10), frees the saved pointer via FreeWrapper_7bcf, then zeroes the slot. Returns the last cleanup result. Used during UI/static teardown.
    // ASSIGNMENT: Initialize slot pointer v0 to the array base dword_7CE23C. [global:0x007CE23C, function:0x0049B1C0]
    // LOOP: Iterate the array from dword_7CE23C while the slot pointer is below the unk_7CE24C end sentinel. [global:0x007CE23C, global:0x007CE24C]
    // GUARD: If the current slot value *v0 is non-null, process it. [global:0x007CE23C]
    // CALL: Run resource cleanup on *v0 via ResourceCleanup_cd10. [callee:0x004DCD10, global:0x007CE23C]
    // ASSIGNMENT: Save the current slot value into v2 for a later free. [global:0x007CE23C]
    // GUARD: If *v0 is still non-null after the first cleanup. [global:0x007CE23C]
    // CALL: Run a second resource cleanup on *v0 via ResourceCleanup_cd10. [callee:0x004DCD10, global:0x007CE23C]
    // CALL: Free the saved pointer v2 via FreeWrapper_7bcf. [callee:0x00587BCF]
    // ASSIGNMENT: Zero the array slot *v0 after cleanup. [global:0x007CE23C]
    // RETURN: Return the last cleanup result. [source:raw]

    // Conservative worker pseudocode:
    //   v0 = dword_7CE23C;
    //   do {
    //     if (*v0) {
    //       result = ResourceCleanup_cd10(*v0);
    //       v2 = (void *)*v0;
    //       if (*v0) {
    //         ResourceCleanup_cd10(*v0);
    //         result = FreeWrapper_7bcf(v2);
    //       }
    //       *v0 = 0;
    //     }
    //     ++v0;
    //   } while (v0 < &unk_7CE24C);
    //   return result;
    // UNRESOLVED: The array element type and the concrete object type behind ResourceCleanup_cd10 are unverified; the double-cleanup of the same slot is taken from raw source verbatim and may reflect a deliberate or buggy original pattern.
}
