// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C2700
// Canonical corpus name: CareerSectionReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CareerSectionReader_004c2700.c

void UnknownObject::ReadCareerSection()
{
    // Reads the "Career" section from a settings-file handle a2 into a stack structure, then writes the parsed career stats into this via CareerStatsWriter. Returns 1 on a successful read+parse, otherwise 0. Guarded on the file handle being non-null.
    // GUARD: If the file handle a2 is null, skip all work and return the default failure flag 0. [source:raw]
    // CALL: Zero-initialize the stack structure v5 via ZeroInitSmallStruct. [callee:0x005668B0, source:raw]
    // CALL: Open/read the section from the file handle a2 with flags (0, 1, 1) via sub_566940. [callee:0x00566940, source:raw]
    // GUARD: Only parse when sub_566940 returns non-zero (section read succeeded). [callee:0x00566940, source:raw]
    // CALL: Write the parsed career stats from v5 into this via CareerStatsWriter, using the aCareer string as the section key; the return value becomes the function result flag. [callee:0x004C2420, global:0x005D2E88, source:raw]
    // CALL: Close the file handle (if needed) via ConditionalFileHandleCloseWithFlagDispatch, dispatching on v5's flag. [callee:0x00566B90, source:raw]
    // CALL: Conditionally free v5's allocated fields via SubCallWithConditionalFieldFree. [callee:0x005668D0, source:raw]
    // RETURN: Return the success/failure flag: 1 when the section was parsed and stats written, else 0. [function:0x004C2700, source:raw]

    // Conservative worker pseudocode:
    //   char read_career_section(_DWORD* this, int handle) {
    //     char ok = 0;
    //     if (!handle) return ok;
    //     _DWORD scratch[7];
    //     ZeroInitSmallStruct(scratch);
    //     if (sub_566940(handle, 0, 1, 1)) {
    //       ok = CareerStatsWriter(this, scratch, (int)aCareer);
    //       ConditionalFileHandleCloseWithFlagDispatch(scratch);
    //     }
    //     SubCallWithConditionalFieldFree(scratch);
    //     return ok;
    //   }
    // UNRESOLVED: The exact layout of the stack structure v5 and which of its fields drive the close/free dispatch are not visible in this function.
    // UNRESOLVED: The flags (0, 1, 1) passed to sub_566940 encode the section read mode; their meaning is not resolved here.
}
