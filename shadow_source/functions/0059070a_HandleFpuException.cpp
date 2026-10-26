// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059070A
// Canonical corpus name: sub_59070A
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59070A_0059070a.c

void UnknownObject::HandleFpuException()
{
    // CRT floating-point exception handler. When the global math-error flag dword_8D3E40 is non-zero the handler is disabled and the input double is returned unchanged. Otherwise it classifies the FP status byte (underflow -1, overflow -2, or general status), rescales the result with __FSCALE__ using the 1536.0 / -1536.0 constants, clamps against the denormal and max-double thresholds, records a status code, forwards the exception argument DWORDs from the a1[+2..+5] slots into the output frame, and dispatches sub_596175 as the math error callback before returning the adjusted result.
    // GUARD: If the global math-error-handling flag dword_8D3E40 is non-zero, return the incoming result unchanged (handler disabled). [global:0x008D3E40]
    // ASSIGNMENT: Store the incoming FP result double into the scratch/output frame slot a1 - 90. [source:raw]
    // GUARD: Read the FP status byte v6 from a1 - 144; a status of zero falls through to the precision-flag branch. [source:raw]
    // CALCULATION: For underflow (status -1) or overflow (status -2), mask the result's exponent word with 0x7FF0 to classify the exponent. [source:raw]
    // CALCULATION: Underflow branch: when the exponent mask is zero, record status code 4, scale the result up with __FSCALE__(result, 1536.0) using the FP constant globals, and clamp the result to zero when its absolute value drops below the denormal threshold (2.225073858507201e-308). [global:0x005B94E0, global:0x005B94E8, global:0x005B9500, global:0x005B9508]
    // CALCULATION: Overflow branch: when the exponent mask is 32752 (0x7FF0), record status code 3, scale the result down with __FSCALE__(result, -1536.0) using the FP constant globals, and clamp the result to infinity when its absolute value exceeds the max-double threshold (1.797693134862316e308). [global:0x005B94F0, global:0x005B94F8]
    // GUARD: Precision branch: when the result's exception/precision bit mask (0x20) is not set on either the result word or the status flags, return the result unchanged; otherwise record status code 8. [source:raw]
    // ASSIGNMENT: For any other status byte value, record it directly as the status code field at a1 - 142. [source:raw]
    // CALCULATION: Increment the frame counter v8 = (DWORD at a1 - 37) + 1 and store it at a1 - 138. [source:raw]
    // GUARD: When the flag byte at a1 - 89 has bit 0 clear, forward the exception arguments from the a1[+2]/a1[+3] DWORD slots into the output frame slots a1 - 134 / a1 - 130. [field:this:0x00000008, field:this:0x0000000C]
    // GUARD: When the referenced byte at v8 + 12 is not 1, additionally forward the a1[+4]/a1[+5] DWORD slots into the output frame slots a1 - 126 / a1 - 122. [field:this:0x00000010, field:this:0x00000014]
    // ASSIGNMENT: Store the adjusted result double into the output slot at a1 - 118. [source:raw]
    // CALL: Dispatch the math error callback sub_596175 with the error code byte, the status-code field at a1 - 142, and the output frame address at a1 - 164. [callee:0x00596175]
    // RETURN: Return the adjusted result double read back from the output slot at a1 - 118. [source:raw]

    // Conservative worker pseudocode:
    //   double sub_59070A(void* frame, double result) {
    //     if (dword_8D3E40) return result;
    //     *(double*)(frame - 90) = result;
    //     char st = *(char*)(frame - 144);
    //     if (st == -1 || st == -2) {
    //       int exp = *(WORD*)(frame - 357) & 0x7FF0;
    //       if (!exp) { code = 4; result = fscale(result, +1536.0);
    //                    if (fabs(result) < 2.225073858507201e-308) result = 0.0; }
    //       else if (exp == 0x7FF0) { code = 3; result = fscale(result, -1536.0);
    //                    if (fabs(result) > 1.797693134862316e308) result = INFINITY; }
    //       else if (!(*(WORD*)(frame - 82) & 0x20) || !(fps & 0x20)) return result;
    //       else code = 8;
    //     } else code = st;
    //     int n = *(DWORD*)(frame - 37) + 1; *(DWORD*)(frame - 138) = n;
    //     if (!(*(BYTE*)(frame - 89) & 1)) {
    //       *(DWORD*)(frame - 134) = *(DWORD*)(frame + 8);
    //       *(DWORD*)(frame - 130) = *(DWORD*)(frame + 12);
    //       if (*(BYTE*)(n + 12) != 1) {
    //         *(DWORD*)(frame - 126) = *(DWORD*)(frame + 16);
    //         *(DWORD*)(frame - 122) = *(DWORD*)(frame + 20);
    //       }
    //     }
    //     *(double*)(frame - 118) = result;
    //     sub_596175(*(char*)(n + 14), frame - 142, frame - 164);
    //     return *(double*)(frame - 118);
    //   }
    // UNRESOLVED: The __usercall frame pointer a1 makes this a stack-convention helper rather than a method on an object; exact caller contract is defined by Cintrindisp1/Cintrindisp2.
    // UNRESOLVED: Which of the six FP constant globals (0x005B94E0..0x005B9508) holds each literal (1536.0, -1536.0, thresholds) is DERIVED, not individually proven.
    // UNRESOLVED: The identity of the math error callback sub_596175 and the meaning of the forwarded exception argument DWORDs are not established here.
}
