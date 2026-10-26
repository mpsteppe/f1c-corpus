// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052E090
// Canonical corpus name: CMpegBase_Open
// Owner: CMpegBase [GUESS]
// Raw source: functions/CMpegBase_Open_0052e090.c

void CMpegBase::Open()
{
    // Opens the MPEG audio decoder base. Handles a pending deferred-deactivation request, clears the bitstream buffer pointer, stores the sync word, validates the audio device via an arithmetic comparison and asserts with the file/line/function message if it fails, otherwise initializes decoder internals, computes network buffer timing, resets performance state, and computes frames-per-buffer plus total buffer size with a 64-bit division.
    // GUARD: If the deferred-deactivation flag byte at this+0x24EC is set, run DeferredDeactivation() before re-opening. [field:this:0x000024EC, callee:0x0052E320]
    // ASSIGNMENT: Set the deferred-deactivation flag byte at this+0x24EC to 1. [field:this:0x000024EC]
    // ASSIGNMENT: Clear the bitstream buffer pointer field this+0x24A4 to 0. [field:this:0x000024A4]
    // ASSIGNMENT: Store the sync-word parameter a2 into this+0x24F0. [field:this:0x000024F0]
    // GUARD: Validate the audio device by calling ArithmeticComparison_de40(this, a2); a nonzero result takes the failure path. [callee:0x0052DE40]
    // CALL: Assert/log path: call off_5DA714(aAudioAssert), then off_5DA714(format, aDDevAudiodevSh, 1698, aCmpegbaseOpenG), then off_5DA718(); the audio-device path string, line 1698 and the 'CMpegBase::Open' function string identify the source location. [global:0x005DA5E0, global:0x005DA714, global:0x005DA574, global:0x005DA674, global:0x005DA718]
    // RETURN: Early return -1 when the audio device validation fails. [source:raw]
    // CALL: Initialize decoder internals via sub_52DA10(this). [callee:0x0052DA10]
    // CALL: AudioNetworkBufferTimingCalc(this) computes the network buffer timing quotient and remainder fields. [callee:0x0052DE60]
    // CALL: LapPerformanceStateReset(this) resets the per-performance sync state. [callee:0x0052E2F0]
    // CALCULATION: F_64BitIntegerDivision computes frames-per-buffer v5 from (a3 + this+0x24D4) over (this+0x24E0), with numerator scaled by this+0x24D4 * (this+0x24DC + this+0x24E0 * this+0x24D8); a3 is the additional byte offset. [callee:0x0052E080, field:this:0x000024D4, field:this:0x000024E0, field:this:0x000024DC, field:this:0x000024D8]
    // CALCULATION: v6 = v5 * this+0x248C computes the total buffer byte size; v5 is stored to this+0x24A0 and v6 to this+0x24B0. [field:this:0x0000248C, field:this:0x000024A0, field:this:0x000024B0]
    // RETURN: Return 0 on successful open. [source:raw]

    // Conservative worker pseudocode:
    //   // CMpegBase::Open(a2 syncWord, a3 extraBytes)
    //   if (this->m_bDeferredDeactivation) DeferredDeactivation();
    //   this->m_bDeferredDeactivation = 1;
    //   this->m_pBitstreamBuffer = 0;         // this+0x24A4
    //   this->m_dwSyncWord = a2;              // this+0x24F0
    //   if (ArithmeticComparison_de40(this, a2)) {
    //       off_5DA714(aAudioAssert);
    //       off_5DA714("%s(%d) : %s\n", aDDevAudiodevSh, 1698, aCmpegbaseOpenG);
    //       off_5DA718();
    //       return -1;
    //   }
    //   sub_52DA10(this);
    //   AudioNetworkBufferTimingCalc(this);
    //   LapPerformanceStateReset(this);
    //   v5 = F_64BitIntegerDivision(a3 + this->m_dwX24D4,
    //           this->m_dwX24E0,
    //           this->m_dwX24D4 * (this->m_dwX24DC + this->m_dwX24E0 * this->m_dwX24D8));
    //   this->m_dwFramesPerBuffer = v5;      // this+0x24A0
    //   this->m_dwBufferBytes = v5 * this->m_dwX248C; // this+0x24B0
    //   return 0;
    // UNRESOLVED: The exact enclosing class is inferred from the aCmpegbaseOpenG function-name string; 'CMpegBase' is a GUESS, not confirmed by vtable or RTTI evidence.
    // UNRESOLVED: off_5DA714 and off_5DA718 are function-pointer table entries; the concrete assert/abort targets behind them are not visible in the raw decompile (sub_52E4E0 and HaltAssertHandler are graph neighbors).
    // UNRESOLVED: Global aSDS_0 is part of the function's extraction but does not appear in the raw decompiled text (possibly an inlined or __FILE__ reference).
    // UNRESOLVED: Semantics of fields 0x24D4/0x24D8/0x24DC/0x24E0 and 0x248C are inferred from their arithmetic roles (byte counts and sample-rate-derived quotients).
    // UNRESOLVED: Read of this+0x24D4, +0x24D8, +0x24DC, +0x24E0 and +0x248C is not cross-checked against a writer function.
}
