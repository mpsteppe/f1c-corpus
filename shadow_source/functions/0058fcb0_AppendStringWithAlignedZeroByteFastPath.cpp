// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058FCB0
// Canonical corpus name: sub_58FCB0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58FCB0_0058fcb0.c

void UnknownObject::AppendStringWithAlignedZeroByteFastPath()
{
    // String-append helper. It scans the byte string at a1 for its terminating NUL using an unaligned byte walk followed by a 4-byte-aligned DWORD probe that detects any zero byte via the (dword + 2130640639) ^ ~dword mask 0x81010100 trick, then copies the NUL-terminated string at a2 into that location (byte walk to alignment, then DWORD-at-a-time copies that stop and NUL-terminate when a zero byte is found). Returns the original a1 pointer, matching strcat-like append semantics.
    // LOOP: Scan the string at a1 byte-by-byte until the address is 4-byte aligned, testing each byte for the terminating NUL. [source:raw, field:this:0x00000000]
    // LOOP: Aligned scan of a1 in DWORD steps, probing each DWORD with (dword + 2130640639) ^ ~dword masked by 0x81010100 to detect any zero byte within the DWORD. [source:raw, field:this:0x00000001]
    // CALCULATION: Locate v6 as the address of the first NUL byte of the a1 string (each early-exit case computes the exact byte position of the zero byte). [source:raw]
    // LOOP: Copy the string at a2 into the buffer starting at v6, walking the source byte-by-byte until the destination write pointer is 4-byte aligned. [source:raw, field:this:0x00000000]
    // LOOP: Aligned 4-byte-at-a-time copy from a2 with the same zero-byte probe; when a zero byte is detected, write only the significant bytes and NUL-terminate the destination. [source:raw, field:this:0x00000001]
    // RETURN: Return the original a1 pointer. [source:raw]

    // Conservative worker pseudocode:
    //   // sub_58FCB0: append the NUL-terminated string at a2 to the string at a1,
    //   // writing through a1's terminating NUL with aligned DWORD zero-byte probes,
    //   // and return the original a1 pointer.
    // UNRESOLVED: Whether a1 is a caller-owned append buffer (strcat semantics) or the byte fields at this:0x0 and this:0x1 belong to a distinct string object is unproven.
    // UNRESOLVED: The magic DWORD probe constant 2130640639 and the 0x81010100 mask implement a zero-byte detector but have no documented name; the relationship to the structural twin 0045d4e0 (StringLengthCheckDispatch) is a DERIVED cluster-copy prelabel.
    // UNRESOLVED: The caller contract for buffer alignment and capacity (callers sub_588D95, sub_588F66 BatchFunctionCallOverVarargs, sub_5932F3) is unknown.
    // UNRESOLVED: Ownership and type of the caller-supplied string objects are unknown; owner stays UnknownObject.
}
