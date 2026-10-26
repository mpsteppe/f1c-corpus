// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052A5D7
// Canonical corpus name: sub_52A5D7
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_52A5D7_0052a5d7.c

void UnknownObject::InflateCopyWindowToOutput()
{
    // Copies up to the available output space from a circular output window into a destination buffer, advancing window and output cursors and firing an optional callout before each copied segment. Handles circular wrap: when the write cursor reaches the window boundary it resets to the window base and repeats the copy for the wrapped remainder. A third argument of -5 marks a flush/termination marker that is cleared to 0 when data is actually copied.
    // GUARD: Wrap guard: if current window position this+0x30 exceeds the window end this+0x34, reset the end limit to the window boundary this+0x2C for length computation. [source:raw, field:this:0x00000030, field:this:0x00000034, field:this:0x0000002C]
    // CALCULATION: Compute first segment length as end minus position (this+0x34 minus this+0x30), then clamp it to the remaining output capacity a2[4]. [source:raw, field:this:0x00000034, field:this:0x00000030]
    // GUARD: Flush guard: if the segment is non-empty and a3 == -5, clear a3 to 0 so a flush marker on real data is not reported as an error. [source:raw]
    // ASSIGNMENT: Advance output accounting: a2[5] += segment length and a2[4] = remaining - segment length. [source:raw]
    // CALL: Callout: if the callout pointer this+0x38 is non-null, invoke it as (int __cdecl)(int, char*, unsigned int) with opaque arg this+0x3C, source and segment length; store its return into this+0x3C and a2[12]. [source:raw, field:this:0x00000038, field:this:0x0000003C]
    // CALCULATION: Copy the segment: qmemcpy full dwords (4 * (len >> 2)) then a tail copy of len & 3 remaining bytes. [source:raw]
    // GUARD: Boundary guard: when the destination cursor reaches the window boundary this+0x2C, wrap to the window base this+0x28; if the end marker this+0x34 equals the boundary, reset it to the base as well. [source:raw, field:this:0x0000002C, field:this:0x00000028, field:this:0x00000034]
    // CALCULATION: Compute and clamp the wrapped second segment: length from this+0x34 minus base this+0x28, clamped to remaining capacity a2[4]. [source:raw, field:this:0x00000034, field:this:0x00000028]
    // GUARD: Flush guard repeated for the wrapped segment: if non-empty and a3 == -5, clear a3 to 0. [source:raw]
    // ASSIGNMENT: Advance output accounting for the wrapped segment: a2[5] += length and a2[4] -= length. [source:raw]
    // CALL: Callout repeated for the wrapped segment: invoke this+0x38(this+0x3C, source, length) when present and store its return into this+0x3C and a2[12]. [source:raw, field:this:0x00000038, field:this:0x0000003C]
    // CALCULATION: Copy the wrapped segment as full dwords plus len & 3 tail bytes. [source:raw]
    // ASSIGNMENT: Persist cursors: store the advanced destination into a2[3] and the advanced window position into this+0x30. [source:raw, field:this:0x00000030]
    // RETURN: Return a3, which is the original flush marker unless data was copied (in which case it is 0). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_52A5D7(int* a1, int* a2, int a3) {
    //     char* pos = (char*)a1[12];  /* this+0x30 current position * /
    //     char* end = (char*)a1[13];  /* this+0x34 end limit * /
    //     char* out = (char*)a2[3];   /* destination * /
    //     unsigned rem = a2[4];
    //     if ((unsigned)pos > (unsigned)end) end = (char*)a1[11];  /* this+0x2C boundary * /
    //     unsigned n = (unsigned)(end - pos); if (n > rem) n = rem;
    //     if (n && a3 == -5) a3 = 0;
    //     a2[5] += n; a2[4] = rem - n;
    //     if (a1[14]) { int r = ((int(__cdecl*)(int,char*,unsigned))a1[14])(a1[15], pos, n); a1[15] = r; a2[12] = r; }
    //     copy(pos, out, n); out += n;
    //     if (out == (char*)a1[11]) { /* wrap * /
    //       char* base = (char*)a1[10]; /* this+0x28 window base * /
    //       if ((char*)a1[13] == (char*)a1[11]) a1[13] = base;
    //       rem = a2[4];
    //       unsigned m = (unsigned)((char*)a1[13] - base); if (m > rem) m = rem;
    //       if (m && a3 == -5) a3 = 0;
    //       a2[5] += m; a2[4] = rem - m;
    //       if (a1[14]) { int r = ((int(__cdecl*)(int,char*,unsigned))a1[14])(a1[15], base, m); a1[15] = r; a2[12] = r; }
    //       copy(base, out, m); out += m;
    //     }
    //     a2[3] = out; a1[12] = pos + n; /* cursor stored back to this+0x30 * /
    //     return a3;
    //   }
    // UNRESOLVED: Struct identities of a1 (ring-buffer state) and a2 (output stream) are not evidenced; offsets are known only through the this-relative field set.
    // UNRESOLVED: Callout contract at this+0x38 is limited to the (int, char*, unsigned int) signature; its meaning (progress, transform, validation) is unknown.
}
