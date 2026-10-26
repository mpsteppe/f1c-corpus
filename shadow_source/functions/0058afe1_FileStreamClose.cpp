// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058AFE1
// Canonical corpus name: sub_58AFE1
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58AFE1_0058afe1.c

void UnknownObject::FileStreamClose()
{
    // CRT-style stream close (cdecl on a stream struct). Reads the OS file-handle index a1[4] (field +0x10), locks the stream, flushes buffered writes, clears control bits in the stream flags a1[3] (field +0xC), resets the per-handle buffer descriptor (the default unk_5E7898 when the handle is -1, otherwise a descriptor addressed as dword_8D4920[v1 >> 5] + 36 * (v1 & 0x1F)), clears bit 1 of that descriptor, clears the low two bits of the flags when bit 7 (0x80) is set, closes the OS handle via sub_58C724(v1, 0, 0), and releases the stream through AddressRangeCriticalSectionLeave.
    // ASSIGNMENT: Read the file-handle index v1 = a1[4] (field +0x10); -1 means no OS handle is attached. [field:this:0x00000010, source:raw]
    // CALL: Lock the stream for exclusive access via StreamBufferLockViaCriticalSection(a1). [callee:0x0058C1B1, source:raw]
    // CALL: Flush pending buffered write data via BufferFlushWrite(a1). [callee:0x0058A05A, source:raw]
    // ASSIGNMENT: Clear control bits in the stream flags: a1[3] &= 0xFFFFFFCF (field +0xC). [field:this:0x0000000C, source:raw]
    // GUARD: If v1 == -1 use the default buffer descriptor unk_5E7898; otherwise resolve the per-handle buffer descriptor from dword_8D4920[v1 >> 5] + 36 * (v1 & 0x1F). [global:0x005E7898, global:0x008D4920, source:raw]
    // ASSIGNMENT: Clear bit 1 of the buffer descriptor flags: v2[4] &= ~2u. [source:raw]
    // GUARD: If the stream flags have bit 7 set ((a1[3] & 0x80u) != 0), clear the low two bits: a1[3] = a1[3] & 0xFC (field +0xC). [field:this:0x0000000C, source:raw]
    // CALL: Close the OS file handle via sub_58C724(v1, 0, 0). [callee:0x0058C724, source:raw]
    // RETURN: Release the stream and its critical-section slot via AddressRangeCriticalSectionLeave(a1). [callee:0x0058C203, source:raw]
    // CALL: Called by sub_5354E0 (0x005354E0) as part of its stream teardown path. [caller:0x005354E0, source:raw]

    // Conservative worker pseudocode:
    //   v1 = a1[4];
    //   StreamBufferLockViaCriticalSection(a1);
    //   BufferFlushWrite(a1);
    //   a1[3] &= 0xFFFFFFCF;
    //   if (v1 == -1)
    //       v2 = &unk_5E7898;
    //   else
    //       v2 = (_BYTE*)(dword_8D4920[v1 >> 5] + 36 * (v1 & 0x1F));
    //   v2[4] &= ~2u;
    //   if ((a1[3] & 0x80u) != 0)
    //       a1[3] = a1[3] & 0xFC;
    //   sub_58C724(v1, 0, 0);
    //   return AddressRangeCriticalSectionLeave(a1);
    // UNRESOLVED: Semantic interpretation (CRT fclose behavior) is from the corpus fill; the packet does not define what unk_5E7898, the dword_8D4920 descriptor-array layout (36-byte stride, index v1 >> 5 and v1 & 0x1F), the flag bits in a1[3] and v2[4], or the constant arguments (0, 0) to sub_58C724 mean.
    // UNRESOLVED: Whether AddressRangeCriticalSectionLeave also frees the stream structure is from the corpus fill, not the packet.
    // UNRESOLVED: The 0xFFFFFFCF and 0xFC masks on a1[3] and the ~2u mask on v2[4] clear specific flag bits whose meanings are not defined by the packet.
}
