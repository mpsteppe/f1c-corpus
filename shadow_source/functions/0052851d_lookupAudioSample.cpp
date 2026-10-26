// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052851D
// Canonical corpus name: AudioSampleLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioSampleLookup_0052851d.c

void UnknownObject::lookupAudioSample()
{
    // Computes an index into a 1024-entry wave table from a 16-bit input sample scaled by the coefficient at **a2+80, plus 4, >>3 and masked & 0x3FF; the table base is *(a1+284) (field 0x11C) with a +128 offset. Reads the table byte, writes it to a5 + *a4, and returns it.
    // CALCULATION: Compute the table index: ((*a3 * **(short**)(a2 + 80) + 4) >> 3) & 0x3FF, a 10-bit masked index derived from the input sample times the coefficient. [abi:lead, source:raw]
    // ASSIGNMENT: Load result = the byte at (index + *(a1 + 284) + 128), i.e. a lookup into the wave table rooted at field 0x11C. [field:this:0x0000011C, source:raw]
    // ASSIGNMENT: Write the looked-up byte to the output buffer: *(_BYTE *)(a5 + *a4) = result. [source:raw]
    // RETURN: Return result (the byte read from the wave table). [function:0x0052851D, source:raw]

    // Conservative worker pseudocode:
    //   char lookupAudioSample(int a1, int a2, short *a3, int *a4, int a5) {
    //     idx = ((*a3 * **(short **)(a2 + 80) + 4) >> 3) & 0x3FF;
    //     result = *(_BYTE *)(idx + *(int *)(a1 + 284) + 128);
    //     *(_BYTE *)(a5 + *a4) = result;
    //     return result;
    //   }
    // UNRESOLVED: The owners of a1/a2/a4/a5 and the meaning of the +4 / >>3 / &0x3FF index transform are not grounded in packet evidence.
    // UNRESOLVED: field:this:0x0000011C is read at a1+284; the exact wave-table semantics of the +128 offset are unknown.
}
