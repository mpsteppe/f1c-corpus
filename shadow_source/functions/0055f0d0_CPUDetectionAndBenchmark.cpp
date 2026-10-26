// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055F0D0
// Canonical corpus name: sub_55F0D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55F0D0_0055f0d0.c

void UnknownObject::CPUDetectionAndBenchmark()
{
    // CPU/system capability detection and benchmark. Clears the output struct, copies a default 'unknown' string into the name buffer, queries GetSystemInfo, and on legacy Pentium-class processors (486/586) runs an RDTSC timing loop to estimate the clock speed in MHz. It then decodes CPUID vendor/model bits to build a human-readable CPU name and sets a performance tier (0-4) and feature flags (MMX/SSE/3DNow). Finally it queries GlobalMemoryStatus and stores physical/page memory sizes in the output struct; if a caller-supplied secondary object a2 has a positive field, it hands the name buffer and two output fields to sub_55BE20. Part of the render/UI global initialization.
    // ASSIGNMENT: Zero the output struct headers: *(_DWORD *)this = 0 and *((_DWORD *)this + 39) = 0 (tier and feature flags). [field:this:0x00000000, field:this:0x0000009C, source:raw]
    // LOOP: Copy the default aUnknown string into the name buffer v3 (this + 4 bytes), NUL-terminated byte copy. [global:0x005C307C, source:raw]
    // CALL: GetSystemInfo(&SystemInfo): query processor type and vendor/system info. [global:0x0059E218, source:raw]
    // GUARD: If SystemInfo.dwProcessorType is neither 486 nor 586, jump to the tail (LABEL_74) and skip CPU timing/detection entirely. [source:raw]
    // CALL: CPUID probe via sub_5567F5; when it reports CPUID availability, run the benchmark block. [callee:0x005567F5, source:raw]
    // CALL: Benchmark setup: Sleep(0), GetCurrentProcess/GetPriorityClass to save the class, SetPriorityClass(current, 0x80) to raise to high priority, then reset the calibration counter v35. [global:0x0059E0DC, global:0x0059E18C, global:0x0059E24C, global:0x0059E248, source:raw]
    // CALL: Timer setup: sub_5567F5 again, sub_556220(v39), sub_556260(v39, 1), HighResolutionTimerReset(v39), then RDTSCTimestampRead(&v36, &v37) as the start timestamp. [callee:0x005567F5, callee:0x00556220, callee:0x00556260, callee:0x00556440, callee:0x0055687B, source:raw]
    // LOOP: Busy-wait loop while HighResolutionTimerDeltaCalculation(v39) < 0.25 (spin roughly a quarter second). [callee:0x00556650, source:raw]
    // CALL: RDTSCTimestampRead(&v35 + 4, &v35) as the end timestamp, then SetPriorityClass(current, dwPriorityClassa) to restore the original priority, followed by EmptyStubWithFlagCheck(2, 0). [callee:0x0055687B, global:0x0059E18C, global:0x0059E248, callee:0x0053AC70, source:raw]
    // CALCULATION: dwPriorityClassb = CRTFtol((((HIDWORD(v35) - v36) * 4294967296.0 * 0.000001 + ((unsigned int)v35 - v37) * 0.000001)) * 4.0): derive the raw clock estimate in MHz from the RDTSC delta; then EmptyStubWithFlagCheck(1, 0). [callee:0x00587BDC, callee:0x0053AC70, source:raw]
    // CALCULATION: Round the MHz estimate: v14 = 50 * ((4 * dwPriorityClassb + 25) / 50); v15 = ((v14 & 3) + v14) / 4 - dwPriorityClassb; choose the smaller-abs-error of v15 + dwPriorityClassb versus 200 * ((3 * dwPriorityClassb + 100) / 200) / 3, producing the final dwPriorityClass. [source:raw]
    // CALL: v17 = sub_5567F5(...): second CPUID read carrying vendor and model bits in v18; v19 = v17 & 0x3000 selects the family class, and (v18 & 0xF00) selects the model family. [callee:0x005567F5, source:raw]
    // GUARD: Intel path: when sub_588410(v3, aGenuineintel_0) reports the vendor is not 'GenuineIntel', apply the Intel naming branch. [callee:0x00588410, global:0x005DC5C0, source:raw]
    // ASSIGNMENT: Intel prefix: strcpy(v3, aDual) when family bits are 0x2000, else strcpy(v3, byte_5EA438); then switch on model bits to strcat the exact name (Pentium Pro/II/Celeron/III/4/MMX/Pentium). [global:0x005DC5B8, global:0x005EA438, source:raw]
    // ASSIGNMENT: Intel tier/flags: set this+0x9C feature bits (1 for MMX-only, 3 for SSE) and this+0x0 tier (0/1/2/3; Pentium II/III tier demoted to 1 when dwPriorityClass <= 400); Pentium 4 sets tier 3. [field:this:0x00000000, field:this:0x0000009C, source:raw]
    // ASSIGNMENT: Fallback mark on the unsupported path: *((_DWORD *)this + 9) = 1 (this+0x24), then EmptyStub_7470(v39). [field:this:0x00000024, callee:0x00557470, source:raw]
    // GUARD: AMD path: when sub_588410(v3, aAuthenticamd_0) reports the vendor is not 'AuthenticAMD', apply the AMD naming branch. [callee:0x00588410, global:0x005DC528, source:raw]
    // ASSIGNMENT: AMD naming: strcpy aDual/byte_5EA438 prefix, then switch model bits to strcat K5/K6 MMX/K6-2/K6-III/Athlon/Duron/Athlon 4; sets feature bits (1 or 5) and tier (1/2/3; Athlon 4 demoted to 2 when dwPriorityClass <= 1200). [global:0x005DC5B8, global:0x005EA438, field:this:0x00000000, field:this:0x0000009C, source:raw]
    // GUARD: Cyrix path: when sub_588410(v3, aCyrixinstead) reports the vendor is not 'CyrixInstead', apply the Cyrix naming branch. [callee:0x00588410, global:0x005DC4BC, source:raw]
    // ASSIGNMENT: Cyrix naming: strcpy aDual/byte_5EA438 prefix, then switch on model bits to strcat MediaGX/6x86/MediaGX MMX/6x86MX; MediaGX MMX also sets feature bit 1. [global:0x005DC5B8, global:0x005EA438, field:this:0x0000009C, source:raw]
    // ASSIGNMENT: Non-compatible fallback: v7 = aNonCompatibleC; this+0x0 = 0, this+0x24 = 0, and the aNonCompatibleC string is copied into the name buffer. [global:0x005DC5D0, field:this:0x00000000, field:this:0x00000024, source:raw]
    // CALL: LABEL_75: Buffer.dwLength = 32; GlobalMemoryStatus(&Buffer): fetch physical/page memory totals. [global:0x0059E244, source:raw]
    // GUARD: If the measured dwPriorityClass is >= 1500, upgrade the tier: this+0x0 = 4. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store memory stats: this+0x7C = dwTotalPhys, this+0x8C = dwTotalPhys (duplicate), this+0x80 = dwAvailPhys, this+0x90 = dwAvailPhys (duplicate), this+0x84 = dwTotalPageFile, this+0x88 = dwAvailPageFile, and this+0x28 = dwPriorityClass (MHz). [field:this:0x0000007C, field:this:0x0000008C, field:this:0x00000080, field:this:0x00000090, field:this:0x00000084, field:this:0x00000088, field:this:0x00000028, source:raw]
    // GUARD: Tail: if a2 is non-null and SimpleFieldGetter_bfc0(a2) > 0, fetch v31 = BoundedArrayAccessor_bfd0(a2, 0) and return sub_55BE20(v31, this + 84, this + 37, this + 38). [callee:0x0055BFC0, callee:0x0055BFD0, callee:0x0055BE20, source:raw]
    // RETURN: Return result (the buffer or allocation pointer) when the a2 tail path is not taken. [source:raw]
    // CALL: Invoked by RenderUISystemGlobalInit. [caller:0x0053C360, source:raw]

    // Conservative worker pseudocode:
    //   *(DWORD*)this = 0; *((DWORD*)this + 39) = 0;
    //   copyString(v3 = this + 4, aUnknown);
    //   GetSystemInfo(&SystemInfo);
    //   if (SystemInfo.dwProcessorType == 486 || SystemInfo.dwProcessorType == 586) {
    //       if (sub_5567F5(...)) {
    //           Sleep(0); savedClass = GetPriorityClass(GetCurrentProcess());
    //           SetPriorityClass(GetCurrentProcess(), 0x80);
    //           sub_5567F5(...); sub_556220(v39); sub_556260(v39, 1);
    //           HighResolutionTimerReset(v39); RDTSCTimestampRead(&v36, &v37);
    //           while (HighResolutionTimerDeltaCalculation(v39) < 0.25) ;
    //           RDTSCTimestampRead(&v35 + 4, &v35);
    //           SetPriorityClass(GetCurrentProcess(), savedClass);
    //           EmptyStubWithFlagCheck(2, 0);
    //           dwPriorityClassb = CRTFtol((elapsed_us) * 4.0);
    //           EmptyStubWithFlagCheck(1, 0);
    //           dwPriorityClass = roundMHz(dwPriorityClassb);
    //           v17 = sub_5567F5(...);
    //           if (!sub_588410(v3, aGenuineintel_0)) { strcpy(v3, aDual/byte_5EA438); switch(model){...Intel names...}; setTierAndFlags(); }
    //           else if (!sub_588410(v3, aAuthenticamd_0)) { strcpy(v3, aDual/byte_5EA438); switch(model){...AMD names...}; setTierAndFlags(); }
    //           else if (!sub_588410(v3, aCyrixinstead)) { strcpy(v3, aDual/byte_5EA438); switch(model){...Cyrix names...}; }
    //           else { v3 = aNonCompatibleC; this+0x0 = 0; this+0x24 = 0; }
    //           *((DWORD*)this + 9) = 1; EmptyStub_7470(v39);
    //       }
    //   }
    //   Buffer.dwLength = 32; GlobalMemoryStatus(&Buffer);
    //   if (dwPriorityClass >= 1500) *(DWORD*)this = 4;
    //   storeMemStats(this, Buffer);
    //   if (a2 && SimpleFieldGetter_bfc0(a2) > 0)
    //       return sub_55BE20(BoundedArrayAccessor_bfd0(a2, 0), this + 84, this + 37, this + 38);
    //   return result;
    // UNRESOLVED: A large block of read-only globals (jump tables jpt_55F413/55F663/55F73F and their byte neighbors, the dword/word/byte tables dword_5DC47C..byte_5DC590, doubles dbl_59E7D8/dbl_59EB50/dbl_5ADB68/dbl_5AF448, dword_8B8F24, and the MMX-style byte_FF0000000000541x/5429 registers) are packet-marked read but do not appear by name in the raw listing; Hex-Rays folded them into switch dispatch and inline constants.
    // UNRESOLVED: The byte_FF0000000000541x/5429 addresses are rendered as fixed memory addresses by Hex-Rays and are likely MMX/3DNow register-file accesses from inline asm, not ordinary globals.
    // UNRESOLVED: Exact semantics of this+0x24 (set to 1 on unsupported paths) and this+0x94/0x98 (dword indices 37/38 handed to sub_55BE20) are not confirmed in this packet.
    // UNRESOLVED: The tier/feature semantics (0-4, bits 1/3/5) are DERIVED from the fill's existing analysis, not stated in the raw source.
    // UNRESOLVED: Vendor string literals are rendered inline in the raw listing; the numeric global tables they alias are unknown.
}
