// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00414900
// Canonical corpus name: FilePathExtensionCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FilePathExtensionCheck_00414900.c

void UnknownObject::FilePathExtensionCheck()
{
    // Builds a candidate path by copying the caller-supplied path into a local buffer and appending a fixed 5-byte extension read from globals dword_5BE868 + byte_5BE86C, then probes file existence with ToggleFileReadOnlyAttributeViaWin32API using FILE_ATTRIBUTE_NORMAL (128). If the attribute query fails (-1) it returns 1; on success it reallocates a copy of the path via StringCopyWithBufferRealloc and clears the caller struct fields this+0x8 and this+0xC to -1 and this+0x10 to 0, returning 0. Returns 1 immediately when the input path a1 is null.
    // GUARD: If input path a1 is null, return 1 immediately without probing [source:raw]
    // CALL: Copy a1 into the local FileName buffer with a 250-character cap via sub_587DD0, then null-terminate at index 250 [callee:0x00587DD0, source:raw]
    // CALCULATION: Append the 5-byte file extension at the end of the copied path: first 4 bytes from dword_5BE868, 1 trailing byte from byte_5BE86C [global:0x005BE868, global:0x005BE86C, source:raw]
    // CALL: Probe the built path with ToggleFileReadOnlyAttributeViaWin32API using attribute flag 128 (FILE_ATTRIBUTE_NORMAL); -1 signals the file does not exist [callee:0x0058BA36, source:raw]
    // GUARD: If the attribute probe returned -1 (file missing), return 1 [source:raw]
    // CALL: On success, copy the validated FileName into a reallocated buffer via StringCopyWithBufferRealloc [callee:0x00566650, source:raw]
    // ASSIGNMENT: Reset caller struct outputs: write -1 to this+0x8 and this+0xC, and 0 to this+0x10 [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // RETURN: Return 0 when the file exists and the struct fields were reset; all failure paths return 1 [source:raw]
    // CALL: Invoked during path setup by sub_414600, sub_414A90 and CommentaryTVPWSPathBuilder [caller:0x00414600, caller:0x00414A90, caller:0x00414E60, source:raw]

    // Conservative worker pseudocode:
    //   if (!a1) return 1;
    //   sub_587DD0(FileName, a1, 250); FileName[250] = 0;
    //   end = FileName + strlen(FileName);
    //   *(DWORD*)end = dword_5BE868; end[4] = byte_5BE86C;
    //   if (ToggleFileReadOnlyAttributeViaWin32API(FileName, 128) == -1) return 1;
    //   StringCopyWithBufferRealloc(FileName);
    //   *(DWORD*)(a2+8) = -1; *(DWORD*)(a2+12) = -1; *(BYTE*)(a2+16) = 0;
    //   return 0;
    // UNRESOLVED: The caller struct pointed to by a2 is not identified; this+0x8/+0xC/-1 pair and this+0x10 flag are written but never read inside this function
    // UNRESOLVED: StringCopyWithBufferRealloc is called for its side effect on the buffer; its return value is not used here
    // UNRESOLVED: The exact extension bytes stored in dword_5BE868/byte_5BE86C are runtime data, not visible in this packet
}
