// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F3240
// Canonical corpus name: VehicleDampingDirectionValidation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleDampingDirectionValidation_004f3240.c

void UnknownObject::VehicleDampingDirectionValidation()
{
    // Damping-direction sign validation during .hdv loading. Parses three damping doubles from a text token a4 via sub_565AA0 into a 24-byte triple selected by direction index a3 (0-5), then for each axis direction warns through the debug log when the damping sign opposes expected motion, suppressed when session type dword_7C569C is 5 (server).
    // CALCULATION: Pointer setup: v4 = this + 24*a3 (direction index a3 selects a 24-byte triple of doubles); v6 = v4+1 and v5 = v4+2 address the second and third double under the thiscall ABI lead. [abi:lead, source:raw]
    // CALL: Parse the damping text a4 into three doubles (v4, v6, v5) via sub_565AA0(a4, v4, v6, v5, 0); a non-zero return gates the whole switch. [callee:0x00565AA0, source:raw]
    // STATE_TRANSITION: Dispatch on direction index a3 (0-5) through jump table jpt_4F327C; the default case falls out of the function. [global:0x004F3474, source:raw]
    // GUARD: case 0: log when parsed X+ value (v4) > 0.0 (zero sentinel dbl_59E430) and session type dword_7C569C != 5. [global:0x0059E430, global:0x007C569C, source:raw]
    // CALL: case 0: StringSplitLoop(dword_8AD25C, 1, aDDevF119992002_7, 351) then DebugLogWrite(dword_8AD25C, aXForceAppliedW). [callee:0x004D7A50, callee:0x004D7AA0, global:0x008AD25C, global:0x005D548C, global:0x005D545C, source:raw]
    // GUARD: case 1: log when parsed X- value (v4) < 0.0 and session type dword_7C569C != 5. [global:0x0059E430, global:0x007C569C, source:raw]
    // CALL: case 1: StringSplitLoop(dword_8AD25C, 1, aDDevF119992002_7, 356) then DebugLogWrite(dword_8AD25C, aXForceAppliedW_0). [callee:0x004D7A50, callee:0x004D7AA0, global:0x008AD25C, global:0x005D548C, global:0x005D542C, source:raw]
    // GUARD: case 2: log when parsed Y+ value (v6) > 0.0 and session type dword_7C569C != 5. [global:0x0059E430, global:0x007C569C, source:raw]
    // CALL: case 2: StringSplitLoop(dword_8AD25C, 1, aDDevF119992002_7, 361) then DebugLogWrite(dword_8AD25C, aYForceAppliedW). [callee:0x004D7A50, callee:0x004D7AA0, global:0x008AD25C, global:0x005D548C, global:0x005D53FC, source:raw]
    // GUARD: case 3: log when parsed Y- value (v6) < 0.0 and session type dword_7C569C != 5. [global:0x0059E430, global:0x007C569C, source:raw]
    // CALL: case 3: StringSplitLoop(dword_8AD25C, 1, aDDevF119992002_7, 366) then DebugLogWrite(dword_8AD25C, aYForceAppliedW_0). [callee:0x004D7A50, callee:0x004D7AA0, global:0x008AD25C, global:0x005D548C, global:0x005D53CC, source:raw]
    // GUARD: case 4: log when parsed Z+ value (v5) > 0.0 and session type dword_7C569C != 5. [global:0x0059E430, global:0x007C569C, source:raw]
    // CALL: case 4: StringSplitLoop(dword_8AD25C, 1, aDDevF119992002_7, 371) then DebugLogWrite(dword_8AD25C, aZForceAppliedW). [callee:0x004D7A50, callee:0x004D7AA0, global:0x008AD25C, global:0x005D548C, global:0x005D539C, source:raw]
    // GUARD: case 5: log when parsed Z- value (v5) < 0.0 and session type dword_7C569C != 5. [global:0x0059E430, global:0x007C569C, source:raw]
    // CALL: case 5: StringSplitLoop(dword_8AD25C, 1, aDDevF119992002_7, 376) then DebugLogWrite(dword_8AD25C, aZForceAppliedW_0). [callee:0x004D7A50, callee:0x004D7AA0, global:0x008AD25C, global:0x005D548C, global:0x005D536C, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4F3240(char* this, int a2, int a3, int a4) {
    //     double* v4 = (double*)&this[24 * a3];
    //     double* v6 = v4 + 1;
    //     double* v5 = v4 + 2;
    //     if (sub_565AA0(a4, v4, v6, v5, 0)) {
    //       switch (a3) {
    //         case 0: if (*v4 > 0.0 && dword_7C569C != 5) logLine(aXForceAppliedW, 351); break;
    //         case 1: if (*v4 < 0.0 && dword_7C569C != 5) logLine(aXForceAppliedW_0, 356); break;
    //         case 2: if (*v6 > 0.0 && dword_7C569C != 5) logLine(aYForceAppliedW, 361); break;
    //         case 3: if (*v6 < 0.0 && dword_7C569C != 5) logLine(aYForceAppliedW_0, 366); break;
    //         case 4: if (*v5 > 0.0 && dword_7C569C != 5) logLine(aZForceAppliedW, 371); break;
    //         case 5: if (*v5 < 0.0 && dword_7C569C != 5) logLine(aZForceAppliedW_0, 376); break;
    //         default: return;
    //       }
    //     }
    //   }
    //   // logLine(msg, line): if (StringSplitLoop(dword_8AD25C, 1, aDDevF119992002_7, line))
    //   //                      DebugLogWrite(dword_8AD25C, msg);
    // UNRESOLVED: Parameter a2 is unused in the function body.
    // UNRESOLVED: The six force-apply log strings (aXForceAppliedW, aYForceAppliedW, aZForceAppliedW and their _0 variants) and section token aDDevF119992002_7 are referenced by address only; their text content is not recovered.
    // UNRESOLVED: dbl_59E430 is assumed to be the 0.0 zero sentinel and jpt_4F327C the switch jump table - both DERIVED from raw reads rather than the decompiled text.
    // UNRESOLVED: Line-number literals 351/356/361/366/371/376 passed to StringSplitLoop are log-line markers; their mapping to source lines is unproven.
}
