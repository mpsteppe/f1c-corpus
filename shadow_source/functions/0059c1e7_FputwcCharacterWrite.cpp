// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059C1E7
// Canonical corpus name: sub_59C1E7
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59C1E7_0059c1e7.c

void UnknownObject::FputwcCharacterWrite()
{
    // 16-bit twin of the CRT character-output helper sub_58CF35 (FputcCharacterWrite): writes one 16-bit value a1 through the stream object a2, switching read-mode streams to write mode, lazily allocating a stream buffer (skipping the sentinel streams unk_5E6768 / unk_5E6788 when sub_596007 reports them), advancing the write cursor by two, flushing the existing buffer via sub_58E22B when full, and falling back to a direct two-byte write for unbuffered streams. Returns a1 on success and 0xFFFF with error bit 0x20 set on failure.
    // ASSIGNMENT: v2 = a2; v3 = a2[3] (flag word); v4 = a2[4] (handle/index); v11 = v4. [source:raw]
    // GUARD: If write-capable bits 0x82 of the flag word are clear or the EOF bit 0x40 is set, jump to the error path. [source:raw]
    // GUARD: If the read-mode flag (bit 0) of a2[3] is set, handle the read-to-write transition. [source:raw]
    // ASSIGNMENT: Clear a2[1] (position/space field). [source:raw]
    // GUARD: If the own-buffer flag (bit 0x10) is set, clear read mode with mask 0xFE, reset the write cursor *v2 = v2[2], and rebuild flags; otherwise fall through to the error path. [source:raw]
    // STATE_TRANSITION: Error path: set bit 0x20 in a2[3], store it, and return 0xFFFF. [source:raw]
    // CALCULATION: Rebuild flags: v5 = a2[3]; a2[1] = 0; v5 = (v5 & 0xED) | 2; a2[3] = v5 — clears bits 0x10/0x2, sets bit 0x1, marking write mode. [source:raw]
    // GUARD: If bits 0x10C of the flags are clear, the buffer allocator has not been initialized yet. [source:raw]
    // GUARD: Skip allocator init when the stream is one of the sentinels unk_5E6768 / unk_5E6788 and sub_596007(v4) returns non-zero. [global:0x005E6768, global:0x005E6788, callee:0x00596007]
    // CALL: MemoryAllocatorInit(v2) lazily initializes the stream buffer allocator. [callee:0x005957BD]
    // GUARD: Branch on the buffered flag bit 0x108 of a2[3]: buffered write path vs direct two-byte write path. [source:raw]
    // CALCULATION: Buffer-space accounting: v6 = v2[2] (buffer base); v7 = *v2 - v6 (bytes free); advance *v2 = v6 + 2; set a2[1] = v2[6] - 2. [source:raw]
    // GUARD: Buffer full (v7 <= 0): select the per-handle descriptor — unk_5E7898 when v4 is -1, else dword_8D4920[v4 >> 5] + 36 * (v4 & 0x1F). [global:0x005E7898, global:0x008D4920]
    // GUARD: If the descriptor's flag byte at offset 4 has bit 0x20 set, notify/reposition the handle. [source:raw]
    // CALL: sub_58C724(v4, 0, 2) notifies the per-handle descriptor when its text-mode bit 0x20 is set. [callee:0x0058C724]
    // CALL: Else flush the previously buffered bytes via sub_58E22B(v4, v6, v7). [callee:0x0058E22B]
    // ASSIGNMENT: Store the output value: *(WORD*)v2[2] = a1 into the stream buffer slot; v9 = a1. [source:raw]
    // CALL: Unbuffered path: write the single 16-bit value a1 directly via sub_58E22B(v4, &a1, 2). [callee:0x0058E22B]
    // RETURN: On success return v9 (a1); otherwise set error bit 0x20 in a2[3] and return 0xFFFF. [function:0x0059C1E7, source:raw]

    // Conservative worker pseudocode:
    //   v2 = a2; v3 = a2[3]; v4 = a2[4];
    //   if ((v3 & 0x82) == 0 || (v3 & 0x40) != 0) goto fail;
    //   if (v3 & 1) {
    //       a2[1] = 0;
    //       if (v3 & 0x10) { v2[3] = v3 & 0xFE; *v2 = v2[2]; }
    //       else goto fail;
    //   }
    //   v5 = v2[3]; v2[1] = 0; v2[3] = (v5 & 0xED) | 2;
    //   if ((v5 & 0x10C) == 0) {
    //       if (v2 != &unk_5E6768 && v2 != &unk_5E6788 || !sub_596007(v4))
    //           MemoryAllocatorInit(v2);
    //   }
    //   if (v2[3] & 0x108) {
    //       v6 = (char*)v2[2]; v7 = *v2 - v6;
    //       *v2 = v6 + 2; v2[1] = v2[6] - 2;
    //       if (v7 <= 0) {
    //           v8 = (v4 == -1) ? &unk_5E7898 : (BYTE*)(dword_8D4920[v4 >> 5] + 36 * (v4 & 0x1F));
    //           if (v8[4] & 0x20) sub_58C724(v4, 0, 2);
    //       } else {
    //           a2 = sub_58E22B(v4, v6, v7);
    //       }
    //       *(WORD*)v2[2] = a1;
    //   } else {
    //       a2 = sub_58E22B(v4, &a1, 2);
    //   }
    //   if (a2 == v7) return a1;
    //   fail:
    //   v2[3] |= 0x20;
    //   return 0xFFFF;
    // UNRESOLVED: a2[3] flag-bit meanings (0x82, 0x40, 0x10, 0x10C, 0x108) and the roles of fields a2[1], a2[2], a2[6] are inferred from the raw source; a2 is an opaque stream object not in the packet field list.
    // UNRESOLVED: Pre-label identifies this as a structural twin of sub_58CF35 (0058cf35, DERIVED); naming follows the twin's FputcCharacterWrite pattern, not independently confirmed.
    // UNRESOLVED: dword_8D4920 descriptor layout (36-byte stride, flag byte at +4) and the role of sub_58C724's arguments (handle, 0, 2) are inferred from the index arithmetic, not grounded in this packet.
    // UNRESOLVED: The caller sub_59BBD9 (0x0059BBD9) is not analyzed.
}
