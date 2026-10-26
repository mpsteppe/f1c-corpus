// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059C156
// Canonical corpus name: FileSeekWithModeFlagValidation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileSeekWithModeFlagValidation_0059c156.c

void UnknownObject::FileSeekWithModeFlagValidation()
{
    // File stream seek with mode-flag validation. Reads the mode flags at this+0xC; if (flags & 0x83) is zero or the seek origin a3 exceeds 2 it sets the TLS error slot to 22 (EINVAL) via TLSOffsetGetter and returns -1. Otherwise it clears bit 0x10 of the flags, optionally (a3==1) adds sub_58C824(a1) to the requested offset for a relative seek, flushes buffered writes with BufferFlushWrite, conditionally resets the +0x18 field to 512 or clears the low two flag bits, performs the seek via sub_595F11(this+0x10 handle, offset), and returns 0 on success / -1 on failure. Called by ThreadSafeWrapper.
    // ASSIGNMENT: Load mode flags: v3 = a1[3] (this+0xC). [field:this:0x0000000C, source:raw]
    // GUARD: Proceed only if (flags & 0x83) != 0 and a3 <= 2; otherwise the error path writes 22 into the TLS slot returned by TLSOffsetGetter() and returns -1. [field:this:0x0000000C, callee:0x0058AFCF, source:raw]
    // ASSIGNMENT: Clear bit 0x10 of the flags (mask 0xEF) and store back to a1[3]. [field:this:0x0000000C, source:raw]
    // CALL: When a3 == 1, call sub_58C824(a1) and add its returned value to the requested offset a2 (relative-seek position query); force v4 = 0. [callee:0x0058C824, source:raw]
    // CALL: Flush pending buffered writes before seeking: BufferFlushWrite(a1). [callee:0x0058A05A, source:raw]
    // CALCULATION: Re-read flags at +0xC: if (flags & 0x80) == 0 and (flags & 1) and (flags & 8) and (flags & 0x400) == 0, set a1[6] (+0x18) = 512; otherwise (bit 0x80 set) clear the low two bits (mask 0xFC) and store back. [field:this:0x0000000C, field:this:0x00000018, source:raw]
    // CALL: Perform the seek: v7 = sub_595F11(a1[4] handle at +0x10, a2, SHIDWORD(a2), v4). [callee:0x00595F11, field:this:0x00000010, source:raw]
    // RETURN: If (v8 & v7) != 0xFFFFFFFF return 0 (success); otherwise fall through to the failure return. [function:0x0059C156, source:raw]
    // RETURN: Failure paths return -1 (including the TLS-22 guard failure path). [callee:0x0058AFCF, source:raw]

    // Conservative worker pseudocode:
    //   int sub_59C156(int a1, __int64 a2, unsigned int a3) {
    //     int flags = a1[3];
    //     if ((flags & 0x83) == 0 || a3 > 2) { *(int*)TLSOffsetGetter() = 22; return -1; }
    //     int v4 = a3;
    //     flags &= 0xEF; a1[3] = flags;
    //     if (a3 == 1) { a2 += sub_58C824(a1); v4 = 0; }
    //     BufferFlushWrite(a1);
    //     flags = a1[3];
    //     if ((flags & 0x80) == 0) {
    //       if ((flags & 1) && (flags & 8) && (flags & 0x400) == 0) a1[6] = 512;
    //     } else {
    //       flags &= 0xFC; a1[3] = flags;
    //     }
    //     int v7 = sub_595F11(a1[4], a2, SHIDWORD(a2), v4);
    //     if ((v8 & v7) != 0xFFFFFFFF) return 0;
    //     return -1;
    //   }
    // UNRESOLVED: v8 is read in the success test before any assignment in the decompiled body; the true success/error discriminator is likely the return of sub_595F11, so the exact success condition is not settled.
    // UNRESOLVED: Exact meanings of the flag bits (0x83 mask, 0x10, 0x80, 0x400, 0xFC) and of the seek-origin selector a3 (0..2) are unverified.
    // UNRESOLVED: Meaning of the +0x18 field reset to 512 (likely a buffer size) is inferred, not verified.
    // UNRESOLVED: Role of sub_58C824 as the position query backing the a3==1 relative seek is inferred.
}
