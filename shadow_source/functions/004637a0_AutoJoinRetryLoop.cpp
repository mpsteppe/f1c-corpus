// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004637A0
// Canonical corpus name: AutoJoinRetryLoop
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AutoJoinRetryLoop_004637a0.c

void UnknownObject::AutoJoinRetryLoop()
{
    // Multiplayer auto-join retry loop. Gated on an auto-join enabled byte at (*this + 0xC6); selects championship mode (dword_7D0410 clamped against two alternate sources), runs a QPC-timed retry loop that polls session state. On ready state (SessionStateCheck == 3) it builds a session descriptor, requests a unique ID, writes path/session config, resets every vehicle entry with SessionStateTransition(-1, 0), zeroes the vehicle count, rebuilds the active-vehicle pointer array and dispatches client team-select. On timeout or unrecoverable state it logs and aborts. Returns 1 on successful join, 0 otherwise.
    // ASSIGNMENT: Initialize the local result value to 0 (default function return). [source:raw, function:0x004637A0]
    // GUARD: Gate the whole function on the auto-join enabled byte at (*this + 0xC6) being non-zero. [field:obj:0x000000C6, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Select championship mode: default dword_7D0410 = 5, clamped down to dword_7D041C when that is below 5, or up to dword_7D0418 when that is above. [global:0x007D0410, global:0x007D0418, global:0x007D041C, source:raw]
    // CALL: Dispatch a pre-join single-call wrapper with the object pointer field at +0x3FB8. [callee:0x0057A920, field:obj:0x00003FB8, source:raw]
    // CALL: Read a constant offset from this object via ConstantOffsetAccessor, storing into v16. [callee:0x00463750, source:raw]
    // GUARD: Join eligibility: CollisionSpatialQuery over the *this + 200 region; on failure fall through to the 'could not auto-join' logging path. [callee:0x00462CE0, source:raw]
    // CALL: Dispatch the 'auto-join wait' UI message via LookupDispatch(aAutojoinWaitPa, -1); if it fails, exit with the 'could not switch' log path. [callee:0x00497940, global:0x005C65D8, source:raw]
    // CALL: Set up the high-resolution retry timer: zero-init the timer struct v20, initialize the QPC timer and reset its counter. [callee:0x00568BA0, callee:0x00568BE0, callee:0x00568C60, source:raw]
    // LOOP: Infinite retry loop polling session state and the elapsed timeout; only exits via the join, abort or return paths. [source:raw]
    // CALCULATION: Update the status buffer: when 'Joining session' (aJoiningSession) is not already present in byte_5EC4C0, copy it into byte_5EC4CC; then StringCopyWithBufferRealloc and append the separator asc_5C65C4. [callee:0x00423A00, callee:0x00566650, callee:0x005665B0, global:0x005C65C8, global:0x005EC4C0, global:0x005EC4CC, global:0x005C65C4, source:raw]
    // CALCULATION: Compute remaining timeout seconds as flt_7D0F28 minus PerformanceCounterDiffWithScaling, convert via CRTFtol and format as a %d string into v19. [callee:0x00568D90, callee:0x00587BDC, callee:0x0058815F, global:0x007D0F28, source:raw]
    // CALL: Per-frame update dispatch: sub_4537B0((int)&ppvOut, dbl_8AFE90). [callee:0x004537B0, global:0x007CA590, global:0x008AFE90, source:raw]
    // CALL: Advance the retry sub-step by calling sub_485B90(iteration counter, 0); this function is also this function's only caller, forming a retry recursion. [callee:0x00485B90, caller:0x00485B90, source:raw]
    // CALL: Update frame/timer bookkeeping: ArithmeticComparison_9ad0(&unk_8AFE18) and sub_4A1830(&unk_7CE2A4). [callee:0x004F9AD0, callee:0x004A1830, global:0x008AFE18, global:0x007CE2A4, source:raw]
    // GUARD: Abort the retry loop when the session init state dword_5CC9E8 becomes -1. [global:0x005CC9E8, source:raw]
    // CALCULATION: Sample the elapsed delta v18 from the high-resolution timer. [callee:0x00568CF0, source:raw]
    // STATE_TRANSITION: When SessionStateCheck(this) == 3 (ready to join): log an attempt (dev-only, when dword_7C569C != 5), build the session descriptor into v21 via FAILWRONGDESCRIPTION and request a unique ID via UniqueID(dword_7CD25C, v21). [callee:0x00461CD0, callee:0x00461550, callee:0x004630D0, callee:0x004D7A50, callee:0x004D7AA0, global:0x007CD25C, global:0x007C569C, global:0x005C5CE4, global:0x008AD25C, global:0x005C65A4, source:raw]
    // CALL: On a valid unique ID: write the path registry (PathPathRegistryWriter) and session config (SessionConfigWriteback), then reset every vehicle entry by calling SessionStateTransition(-1, 0) across the stride-4656 range from unk_5EC6E4 up to dword_7C54E4. [callee:0x004B1600, callee:0x00461900, callee:0x004EF5A0, global:0x007CE498, global:0x005EC6E4, global:0x007C54E4, source:raw]
    // ASSIGNMENT: After the vehicle-array reset: dword_5C329C (vehicle count) = 0, byte_7C5690 = 1 and dword_7C56A0 = 2. [global:0x005C329C, global:0x007C5690, global:0x007C56A0, source:raw]
    // CALL: Complete the join: BuildActiveVehiclePointerArray, sub_4A0AF0(&unk_7CE24C) session init, dispatch client team-select via LookupDispatch(aClientTeamSele, -1), then the EmptyStub_0170 cleanup stub on the timer struct. [callee:0x0042BC80, callee:0x004A0AF0, callee:0x00497940, callee:0x004B0170, global:0x007CE24C, global:0x005C6590, source:raw]
    // RETURN: Return 1 on successful join. [source:raw]
    // GUARD: Timeout/failure branch: PerformanceCounterDiffWithScaling exceeds flt_7D0F28, or EnumToEnumTranslator(this, 0) returns non-zero. [callee:0x00462D30, callee:0x00568D90, global:0x007D0F28, source:raw]
    // CALL: On failure, fetch the failure string via sub_462DA0(5), refresh byte_5EC4CC when the string table lookup hits, then dispatch it via CallWrapper(byte_5EC4CC). [callee:0x00462DA0, callee:0x00466080, callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // GUARD: On a non-recoverable failure (v17 != 3): dispatch the auto-join failure message via LookupDispatch(aAutojoinFailur, -1), run ShortComputation_7250(1) cleanup, then EmptyStub_0170 and return 0. [callee:0x00497940, callee:0x00497250, callee:0x004B0170, global:0x005C6578, source:raw]
    // CALCULATION: Retry pacing: when accumulated v14 exceeds 10.0, re-run the collision spatial query, increment the retry counter v15 and reset v14 to 0.0. [callee:0x00462CE0, source:raw]
    // CALCULATION: Accumulate the frame delta into the pacing value: v14 = v18 + v14. [source:raw]
    // RETURN: Return 0 on the failure paths (could not switch / could not auto-join), with dev-only logging gated on dword_7C569C != 5. [callee:0x004D7A50, callee:0x004D7AA0, global:0x007C569C, global:0x005C5CE4, global:0x005C6530, global:0x005C6508, global:0x008AD25C, source:raw]

    // Conservative worker pseudocode:
    //   char AutoJoinRetryLoop(void *this) {
    //     char result = 0;
    //     if (!*(char *)(*(DWORD *)this + 198)) return result;
    //     dword_7D0410 = 5;
    //     if (dword_7D0418 <= 5) { if (dword_7D041C < 5) dword_7D0410 = dword_7D041C; }
    //     else dword_7D0410 = dword_7D0418;
    //     SingleFunctionCallWrapper_a920(*(DWORD *)(*(DWORD *)this + 16312));
    //     v16 = ConstantOffsetAccessor(this, 0);
    //     if (CollisionSpatialQuery(v3, *(DWORD *)this + 200, v16) && LookupDispatch(aAutojoinWaitPa, -1)) {
    //       StructZeroInit_8ba0(&timer); QPCTimerInitialization(1); TimerResetUsingQueryPerformanceCounter(&timer);
    //       v14 = 0.0; v4 = 0; v15 = 1;
    //       for (;;) {
    //         if (BinarySearchInStringTable(byte_5EC4C0, aJoiningSession, byte_5EC4CC)) strcpy(byte_5EC4CC, aJoiningSession);
    //         StringCopyWithBufferRealloc(byte_5EC4CC); sub_5665B0(asc_5C65C4);
    //         v8 = CRTFtol(flt_7D0F28 - PerformanceCounterDiffWithScaling(&timer));
    //         StringFormatWithBufferOverflowCheck(buf, "%d", v8); sub_5665B0(buf);
    //         sub_4537B0((int)&ppvOut, dbl_8AFE90);
    //         sub_485B90(v4++, 0);
    //         ArithmeticComparison_9ad0(&unk_8AFE18); sub_4A1830(&unk_7CE2A4);
    //         if (dword_5CC9E8 == -1) break;
    //         v18 = HighResolutionTimerDelta(&timer);
    //         if (SessionStateCheck(this) == 3) {
    //           if (dword_7C569C != 5 && StringSplitLoop(1, aDDevF119992002_1, 7303)) DebugLogWrite(&dword_8AD25C, aAutojoinAttemp);
    //           FAILWRONGDESCRIPTION(&desc);
    //           if (UniqueID(dword_7CD25C, (int)&desc)) {
    //             PathPathRegistryWriter(&byte_7CE498); SessionConfigWriteback((int)&desc);
    //             for (p = &unk_5EC6E4; p < &dword_7C54E4; p += 4656) SessionStateTransition(-1, 0);
    //             dword_5C329C = 0; BuildActiveVehiclePointerArray();
    //             byte_7C5690 = 1; dword_7C56A0 = 2; sub_4A0AF0(&unk_7CE24C);
    //             LookupDispatch(aClientTeamSele, -1); EmptyStub_0170(&timer); return 1;
    //           }
    //         } else if (PerformanceCounterDiffWithScaling(&timer) > flt_7D0F28 || (v17 = EnumToEnumTranslator(this, 0)) != 0) {
    //           str = sub_462DA0(5);
    //           if (BinarySearchInStringTable(byte_5EC4C0, str, byte_5EC4CC)) { if (str) strcpy(byte_5EC4CC, str); else byte_5EC4CC[0] = 0; }
    //           CallWrapper(byte_5EC4CC);
    //           if (v17 != 3) { LookupDispatch(aAutojoinFailur, -1); ShortComputation_7250(1); break; }
    //         }
    //         if (v14 > 10.0) { CollisionSpatialQuery(this, *(DWORD *)this + 200, v16); ++v15; v14 = 0.0; }
    //         v14 = v18 + v14;
    //       }
    //       EmptyStub_0170(&timer); return 0;
    //     }
    //     if (dword_7C569C != 5 && StringSplitLoop(1, aDDevF119992002_1, 7381)) DebugLogWrite(&dword_8AD25C, aCouldNotSwitch);
    //     return 0;
    //   }
    // UNRESOLVED: Four packet globals do not appear in the recovered raw body and are unaccounted: flt_59E5FC, aD_1, unk_5EC6D0, dword_7CD8C0.
    // UNRESOLVED: ABI lead name 'AutoJoin_Retry_Loop' (LEGACY) is kept only as a lead; the owner object stays UNKNOWN.
    // UNRESOLVED: CollisionSpatialQuery is called with decompiler register v3 whose definition is not recovered; treated as this-pointer derived.
}
