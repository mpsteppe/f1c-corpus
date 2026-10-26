// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00560A82
// Canonical corpus name: sub_560A82
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_560A82_00560a82.c

void UnknownObject::MaskedAudioRowCopy()
{
    // Mode-dependent row-wise data copy on the audio playback path (called by AudioPlaybackDispatcher): when a7 == -1 it performs a straight block copy of a5 dwords per row across a6 rows, advancing source by row pitch a2 and destination by row pitch a4; otherwise it copies only dwords that differ from the mask value (a7 & 0xFFFFFF), leaving destination cells equal to the mask untouched. Also records the mode flag, mask and per-row dword count into shared globals consumed elsewhere in the audio subsystem.
    // ASSIGNMENT: Store the full-copy mode flag: dword_5DD844 = (a7 == -1). [global:0x005DD844, source:raw]
    // ASSIGNMENT: Store the mask value: dword_5DD804 = a7 & 0xFFFFFF. [global:0x005DD804, source:raw]
    // ASSIGNMENT: Store the per-row dword count: dword_5DD814 = a5. [global:0x005DD814, source:raw]
    // GUARD: Branch on the stored mode flag: take the full block-copy path when dword_5DD844 == 1 (a7 == -1), otherwise take the masked path. [global:0x005DD844, source:raw]
    // LOOP: Outer do-while over a6 rows in full-copy mode, countdown counter v10 seeded from a6. [source:raw]
    // ASSIGNMENT: Copy 4 * v9 bytes (v9 = a5 dwords) from source a1 to destination a3 per row via qmemcpy. [source:raw]
    // CALCULATION: Advance source by row pitch a2 and destination by row pitch a4: a1 = a1 + a2, a3 = a3 + a4. [source:raw]
    // LOOP: Outer do-while over a6 rows in masked mode, countdown counter seeded from a6. [source:raw]
    // LOOP: Inner do-while over a5 dwords per row, countdown counter v16 seeded from a5. [source:raw]
    // GUARD: Copy the loaded dword v17 only when it differs from the stored mask v14 = dword_5DD804; dwords equal to the mask are skipped, leaving the destination cell unchanged. [global:0x005DD804, source:raw]
    // CALCULATION: Advance source by row pitch a2 and destination by row pitch a4 after each masked row (a1 += a2, a3 += a4). [source:raw]
    // CALL: Invoked by AudioPlaybackDispatcher (0x005401A0) on the audio playback path. [caller:0x005401A0]

    // Conservative worker pseudocode:
    //   void sub_560A82(char *src, int srcPitch, char *dst, int dstPitch, int dwords, int rows, int a7) {
    //     g_modeFlag = (a7 == -1);
    //     g_mask = a7 & 0xFFFFFF;
    //     g_dwords = dwords;
    //     if (g_modeFlag) {
    //       int n = rows;
    //       do { qmemcpy(dst, src, 4 * dwords); src += srcPitch; dst += dstPitch; } while (--n > 0);
    //     } else {
    //       int mask = g_mask;
    //       int n = rows;
    //       do {
    //         int m = dwords;
    //         do { int v = *(DWORD *)src; if (v != mask) *(DWORD *)dst = v; src += 4; dst += 4; } while (--m > 0);
    //         src += srcPitch - 4 * dwords;
    //         dst += dstPitch - 4 * dwords;
    //       } while (--n > 0);
    //     }
    //   }
    // UNRESOLVED: Shared globals dword_5DD804 / dword_5DD814 / dword_5DD844 written here are read elsewhere in the audio subsystem; their cross-function meaning is not established.
    // UNRESOLVED: a7 semantics: -1 selects plain copy while other values act as a fill/mask value; the exact audio meaning depends on the AudioPlaybackDispatcher call context.
    // UNRESOLVED: The mask branch leaves cells equal to the mask untouched, implying the destination was pre-initialized to the mask value by the caller.
}
