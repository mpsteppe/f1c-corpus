// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053C360
// Canonical corpus name: RenderUISystemGlobalInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RenderUISystemGlobalInit_0053c360.c

void UnknownObject::RenderUISystemGlobalInit()
{
    // Global render/audio system initializer. Zeroes the entry-array region from byte_8B5A3C to byte_8B6ABC in 132-byte strides, resets a batch of global flags (counts, handles, thresholds), then branches on the a5 init-flag bits: bit 1 skips audio configuration, bit 2 applies the '2' quality preset (audio-quality=2, 0.5/0.5 scale factors) and bit 3 the '3' preset (0.33340001/0.33340001) before starting the audio subsystem (sub_53D750) and calling sub_55BE80(a4, a5&1). Then runs ArithmeticComparison_b0d0, initializes audio channels, allocates and zero-initializes a 160-byte network-config object into dword_8B8F04, runs sub_55F0D0 and GlobalMemoryStatusWrapper, and allocates a 12-byte object into dword_8B8F2C. Always returns 0. Called by SystemInitAllocatorWrapper.
    // ASSIGNMENT: Reset entry count: dword_8B8E30 = 0 [global:0x008B8E30, source:raw]
    // LOOP: Zero the entry-array region: walk v6 from &byte_8B5A3C toward byte_8B6ABC, writing 0 at each 132-byte step [global:0x008B5A3C, global:0x008B6ABC, source:raw]
    // ASSIGNMENT: Reset counters/handles: dword_8B6AC0 = 0, dword_8B8F14 = 0, dword_8B8EE0 = -1, dword_8B8E34 = -1 [global:0x008B6AC0, global:0x008B8F14, global:0x008B8EE0, global:0x008B8E34, source:raw]
    // ASSIGNMENT: Set default enable flags: dword_8B6AC4 = 1, dword_8B8E24 = 1, dword_8B8E2C = 1, dword_8B8E28 = 1 [global:0x008B6AC4, global:0x008B8E24, global:0x008B8E2C, global:0x008B8E28, source:raw]
    // ASSIGNMENT: Zero the render/audio state block: dword_8B8DC4, dword_8B8DC8, dword_8B8DCC, dword_8B8DD0, dword_8B8F18, dword_8B8F1C, dword_8B8F20 all = 0 [global:0x008B8DC4, global:0x008B8DC8, global:0x008B8DCC, global:0x008B8DD0, global:0x008B8F18, global:0x008B8F1C, global:0x008B8F20, source:raw]
    // GUARD: If (a5 & 2) != 0 skip the audio-configuration/startup block entirely and jump to LABEL_10 [source:raw]
    // GUARD: Medium preset: if (a5 & 4) != 0 set dword_8B8CEC=2, flt_8B8CF0=0.5, flt_8B8CF4=0.5, then StateIntSetter4(-1, -1, 16000, 12000) [global:0x008B8CEC, global:0x008B8CF0, global:0x008B8CF4, callee:0x0053D930, source:raw]
    // GUARD: High preset: if (a5 & 8) != 0 set dword_8B8CEC=3, flt_8B8CF0=0.33340001, flt_8B8CF4=0.33340001, then StateIntSetter4(-1, -1, 16000, 12000) [global:0x008B8CEC, global:0x008B8CF0, global:0x008B8CF4, callee:0x0053D930, source:raw]
    // CALL: Start audio subsystem: sub_53D750(&dword_8B78A0) [callee:0x0053D750, global:0x008B78A0, source:raw]
    // CALL: Forward init: sub_55BE80(a4, a5 & 1) [callee:0x0055BE80, source:raw]
    // CALL: LABEL_10: run ArithmeticComparison_b0d0() [callee:0x0053B0D0, source:raw]
    // CALL: InitializeAudioSystemChannels(this) [callee:0x005566D0, source:raw]
    // CALL: Allocate network-config object: v7 = OperatorNewNhMallocWrapper(160); if non-null v8 = StructZeroInitConstructor_f080(v7) else v8 = 0; dword_8B8F04 = v8 [callee:0x00587C03, callee:0x0055F080, global:0x008B8F04, source:raw]
    // CALL: sub_55F0D0(this) [callee:0x0055F0D0, source:raw]
    // CALL: GlobalMemoryStatusWrapper(this) [callee:0x0055F060, source:raw]
    // CALL: Allocate render-resource object: v9 = OperatorNewNhMallocWrapper(12); if non-null dword_8B8F2C = StructZeroInit_93b0(v9) else dword_8B8F2C = 0 [callee:0x00587C03, callee:0x005593B0, global:0x008B8F2C, source:raw]
    // RETURN: Return 0 unconditionally [function:0x0053C360, source:raw]
    // CALL: Invoked by SystemInitAllocatorWrapper (0053D470) [caller:0x0053D470, source:raw]

    // Conservative worker pseudocode:
    //   dword_8B8E30 = 0;
    //   for (p = &byte_8B5A3C; p < &byte_8B6ABC; p += 132) *p = 0;
    //   dword_8B6AC0 = 0; dword_8B8F14 = 0;
    //   dword_8B8EE0 = -1; dword_8B8E34 = -1;
    //   dword_8B6AC4 = 1; dword_8B8E24 = 1; dword_8B8E2C = 1; dword_8B8E28 = 1;
    //   dword_8B8DC4 = 0; dword_8B8DC8 = 0; dword_8B8DCC = 0; dword_8B8DD0 = 0;
    //   dword_8B8F18 = 0; dword_8B8F1C = 0; dword_8B8F20 = 0;
    //   if (a5 & 2) goto L10;
    //   if (a5 & 4) { dword_8B8CEC = 2; flt_8B8CF0 = 0.5; flt_8B8CF4 = 0.5; goto L8; }
    //   if (a5 & 8) { dword_8B8CEC = 3; flt_8B8CF0 = 0.33340001; flt_8B8CF4 = 0.33340001; goto L8; }
    //   L8: StateIntSetter4(-1, -1, 16000, 12000);
    //   sub_53D750(&dword_8B78A0);
    //   sub_55BE80(a4, a5 & 1);
    //   L10: ArithmeticComparison_b0d0();
    //   InitializeAudioSystemChannels(this);
    //   v7 = OperatorNewNhMallocWrapper(160);
    //   dword_8B8F04 = v7 ? StructZeroInitConstructor_f080(v7) : 0;
    //   sub_55F0D0(this);
    //   GlobalMemoryStatusWrapper(this);
    //   v9 = OperatorNewNhMallocWrapper(12);
    //   dword_8B8F2C = v9 ? StructZeroInit_93b0(v9) : 0;
    //   return 0;
    // UNRESOLVED: The names of most touched globals (entry-array region, preset scale factors) come from the fill's DERIVED layer, not from the raw source
    // UNRESOLVED: The entry-array stride of 132 and the exact semantics of the two allocated object sizes (160 and 12 bytes) are observed from the loop and allocation literals only
    // UNRESOLVED: The a5 bitmask semantics (bit0 forwarded to sub_55BE80, bit1 skip, bit2/bit3 quality presets) are inferred from the branch structure
    // UNRESOLVED: Parameters a2 and a3 are declared but never referenced in the decompiled body
}
