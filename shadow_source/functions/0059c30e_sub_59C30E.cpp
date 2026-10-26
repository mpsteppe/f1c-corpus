// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059C30E
// Canonical corpus name: sub_59C30E
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59C30E_0059c30e.c

void UnknownObject::sub_59C30E()
{
    // Reads one 16-bit word from a buffer described by a pointer-array descriptor (a1). Consults a flag/status byte at a1[3]: fails fast on reserved bits, forces the in-progress bit on retry, rewinds to the base buffer (a1[2]) when a continue bit is set or allocates through MemoryAllocatorInit otherwise, fills the buffer via sub_58C9B4, validates the returned size, conditionally widens the requested read size from 512 to 4096, and returns the next word while advancing the read pointer. Structural twin of sub_58C255 per cluster prelabel.
    // GUARD: if ((flag & 0x83) == 0 || (flag & 0x40) != 0) return 0xFFFF — reserved/aborted flag bits cause immediate failure [field:this:0x0000000C, source:raw]
    // GUARD: if (flag & 2) != 0: flag |= 0x20; return 0xFFFF — a pending retry is marked in-progress and the call aborts [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: flag |= 1 — mark the descriptor active [field:this:0x0000000C, source:raw]
    // GUARD: if (flag & 0x10C) != 0: a1[0] := a1[2] (rewind read pointer to base buffer); else call MemoryAllocatorInit(a1) [callee:0x005957BD, field:this:0x00000000, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // CALL: v2 := sub_58C9B4((int)a1[4], a1[2], (DWORD)a1[6]) — fetch data for index a1[4] into the base buffer [callee:0x0058C9B4, field:this:0x00000008, field:this:0x00000010, field:this:0x00000018, source:raw]
    // ASSIGNMENT: a1[1] := v2 — record the returned size [field:this:0x00000004, source:raw]
    // GUARD: if (v2 < 2 || v2 == -1): flag |= (v2 != 0 ? 32 : 16); a1[1] := 0; return 0xFFFF — undersized/failed read sets an error bit and clears the size [field:this:0x00000004, field:this:0x0000000C, source:raw]
    // GUARD: if (flag & 0x82) == 0: v4 := (a1[4] == -1) ? &unk_5E7898 : dword_8D4920[a1[4] >> 5] + 36 * (a1[4] & 0x1F); if (v4[4] & 0x82) == 0x82 then set the high-byte flag bit (0x20) — validate the source descriptor state [field:this:0x0000000C, field:this:0x00000010, global:0x005E7898, global:0x008D4920, guard:0, source:raw]
    // GUARD: if (a1[6] == 512): if (flag & 8) != 0 && (flag high byte & 4) == 0: a1[6] := 4096 — widen the read size when a size-boost bit is set and not already widened [field:this:0x0000000C, field:this:0x00000018, guard:1, source:raw]
    // ASSIGNMENT: a1[1] := v2 - 2 — store the usable content size (result minus two) [field:this:0x00000004, source:raw]
    // RETURN: result := *(unsigned __int16*)a1[0] (word at obj + 0); a1[0] := a1[0] + 1; return result — fetch and consume the next 16-bit word [field:obj:0x00000000, field:this:0x00000000, function:0x0059C30E, source:raw]

    // Conservative worker pseudocode:
    //   v1 = a1[3];
    //   if (((unsigned __int8)v1 & 0x83) == 0 || ((unsigned __int8)v1 & 0x40) != 0) return 0xFFFF;
    //   if (((unsigned __int8)v1 & 2) != 0) { a1[3] = (unsigned __int8)v1 | 0x20; return 0xFFFF; }
    //   a1[3] = (unsigned __int8)v1 | 1;
    //   if (((unsigned __int16)v1 & 0x10C) != 0) *a1 = a1[2]; else MemoryAllocatorInit(a1);
    //   v2 = sub_58C9B4((int)a1[4], a1[2], (DWORD)a1[6]);
    //   a1[1] = (unsigned __int16*)v2;
    //   if (v2 < 2 || v2 == -1) { a1[3] = ((v2 != 0 ? 32 : 16) | (unsigned int)a1[3]); a1[1] = 0; return 0xFFFF; }
    //   v3 = a1[3];
    //   if (((unsigned __int8)v3 & 0x82) == 0) {
    //       v4 = a1[4] == (unsigned __int16*)-1 ? &unk_5E7898 : (_BYTE*)(dword_8D4920[(int)a1[4] >> 5] + 36 * ((unsigned int)a1[4] & 0x1F));
    //       if ((v4[4] & 0x82) == 0x82) { BYTE1(v3) |= 0x20; a1[3] = v3; }
    //   }
    //   if (a1[6] == (unsigned __int16*)512) {
    //       v5 = a1[3];
    //       if (((unsigned __int8)v5 & 8) != 0 && (BYTE1(v5) & 4) == 0) a1[6] = (unsigned __int16*)4096;
    //   }
    //   v6 = *a1;
    //   a1[1] = (unsigned __int16*)(v2 - 2);
    //   result = *v6;
    //   *a1 = v6 + 1;
    //   return result;
    // UNRESOLVED: Semantics of the flag bits (0x83/0x40/0x2/0x20/0x1/0x10C/0x82/0x8) and of the flag high-byte bits are unknown.
    // UNRESOLVED: Purpose of sub_58C9B4, the descriptor index a1[4], and the source descriptor table dword_8D4920 is unknown.
    // UNRESOLVED: Meaning of the unk_5E7898 fallback descriptor and why its fourth byte is validated is unknown.
    // UNRESOLVED: The structural-twin relationship to sub_58C255 is DERIVED from cluster prelabel and not independently confirmed.
}
