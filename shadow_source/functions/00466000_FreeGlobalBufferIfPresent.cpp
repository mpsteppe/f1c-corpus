// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00466000
// Canonical corpus name: sub_466000
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_466000_00466000.c

void UnknownObject::FreeGlobalBufferIfPresent()
{
    // Reads the global buffer pointer dword_7CD460. When non-null, frees it through the FreeWrapper_7bcf allocation wrapper and returns the wrapper's result; when null, returns the loaded value (zero). Acts as a guarded cleanup of a single global allocation.
    // ASSIGNMENT: Load the global pointer dword_7CD460 into a local result value. [global:0x007CD460, source:raw]
    // GUARD: If dword_7CD460 is non-zero, take the free path; otherwise return the loaded value. [global:0x007CD460, source:raw]
    // CALL: Free the global buffer via FreeWrapper_7bcf((LPVOID)dword_7CD460). [callee:0x00587BCF, global:0x007CD460, source:raw]
    // RETURN: Return the FreeWrapper_7bcf result on the free path, and the loaded (zero) value on the null path. [callee:0x00587BCF, global:0x007CD460, source:raw]

    // Conservative worker pseudocode:
    //   int FreeGlobalBufferIfPresent(void) {
    //     result = dword_7CD460;
    //     if (dword_7CD460)
    //       return FreeWrapper_7bcf((LPVOID)dword_7CD460);
    //     return result;
    //   }
    // UNRESOLVED: What dword_7CD460 points to and which subsystem allocated it is unknown; only the guarded free pattern is evidenced.
}
