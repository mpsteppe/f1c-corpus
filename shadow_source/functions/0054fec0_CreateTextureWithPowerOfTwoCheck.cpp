// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054FEC0
// Canonical corpus name: sub_54FEC0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_54FEC0_0054fec0.c

void UnknownObject::CreateTextureWithPowerOfTwoCheck()
{
    // Texture creation with power-of-two validation. Validates that the width (a3) and height (a4) arguments are powers of two within the accepted set 1..4096 (1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096) using two switch dispatches backed by jump tables jpt_54FEE7 (0x54FFE4) and jpt_54FF3A (0x55002C). If either dimension fails, formats the error 'Texture %s size not power of 2' via StringFormatWithBufferOverflowCheck (format string aTextureSSizeNo at 0x5DBFEC), reports it through sub_53C590(-1, message), and returns -1. Otherwise associates the texture name via sub_54FE50 and initializes the texture through UtilityFunction_2950 with the pointer stored at this+0x54 plus the validated dimensions; a zero return from initialization reports success (0), a non-zero return triggers DestructorWithConditionalFreeFlagClear and returns -1.
    // CALCULATION: Validate width argument a3 is a power of two (accepted values 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096) via the switch dispatch at jpt_54FEE7 with the byte table byte_54FFEC; if a3 is not accepted set the invalid flag v7. [global:0x0054FFE4, global:0x0054FFEC, source:raw]
    // CALCULATION: Validate height argument a4 with the same power-of-two acceptance set via the switch dispatch at jpt_54FF3A with the byte table byte_550034; failure leaves the invalid flag v7 set. [global:0x0055002C, global:0x00550034, source:raw]
    // GUARD: If either dimension failed validation (v7 set), format the error buffer via StringFormatWithBufferOverflowCheck with format string 'Texture %s size not power of 2' (aTextureSSizeNo at 0x5DBFEC) and texture name a2, then report it via sub_53C590(-1, buffer) and return -1. [callee:0x0058815F, global:0x005DBFEC, callee:0x0053C590, source:raw]
    // CALL: Associate the texture name (a2) with this object via sub_54FE50((const CHAR*)this, a2). [callee:0x0054FE50, source:raw]
    // CALL: Initialize the texture via UtilityFunction_2950(*(_DWORD**)(this + 0x54), a3, a4, a5, a6); return 0 when the initialization reports success. [callee:0x00542950, field:this:0x00000054, source:raw]
    // CALL: On non-zero initialization return, clean up the object via DestructorWithConditionalFreeFlagClear(this) and return -1. [callee:0x005502C0, source:raw]

    // Conservative worker pseudocode:
    //   int CreateTextureWithPowerOfTwoCheck(int this, const char* name, int w, int h, int a5, int a6) {
    //     int invalid = 0;
    //     if (!isPowerOfTwo(w)) invalid = 1;   // set {1,2,4,8,16,32,64,128,256,512,1024,2048,4096}
    //     if (!isPowerOfTwo(h)) invalid = 1;
    //     if (invalid) {
    //       char msg[64];
    //       StringFormatWithBufferOverflowCheck(msg, "Texture %s size not power of 2", name);
    //       sub_53C590(-1, msg);
    //       return -1;
    //     }
    //     sub_54FE50((const CHAR*)this, name);
    //     if (!UtilityFunction_2950(*(_DWORD**)(this + 84), w, h, a5, a6)) return 0;
    //     DestructorWithConditionalFreeFlagClear(this);
    //     return -1;
    //   }
    // UNRESOLVED: The object type at this+0x54 (described as an emitter/owner pointer by existing analysis) is not confirmed; it is only passed through to UtilityFunction_2950.
    // UNRESOLVED: The semantics of the UtilityFunction_2950 success/failure return (0 = success vs non-zero = failure) is inferred from the control flow and not independently confirmed.
    // UNRESOLVED: The exact role of sub_54FE50 (filename association vs emitter setup) is unresolved.
}
