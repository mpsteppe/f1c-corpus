// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004986D0
// Canonical corpus name: sub_4986D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4986D0_004986d0.c

void UnknownObject::ErrorCodeToMessageBox()
{
    // Converts a numeric error code a1 into a text string via sub_587DD0 (bounded to 127 characters), NUL-terminates it, and displays it in a MessageBoxA with the "Options Error" caption (aOptionsError). When a1 is non-zero it then calls UtilityFunction_9ca4(1) and returns its result; when a1 is zero it returns immediately with no side effects.
    // GUARD: Guard on a1: when a1 is zero the function returns a1 immediately and none of the error handling runs. [source:raw]
    // CALL: Format the error code a1 into the local Text buffer with a maximum length of 127 via sub_587DD0. [callee:0x00587DD0, source:raw]
    // ASSIGNMENT: Force NUL termination of the formatted text by clearing Text[127]. [source:raw]
    // CALL: Display the formatted text in a modal message box using MessageBoxA with a null owner window and the aOptionsError title string. [global:0x0059E2A4, global:0x005CCAE4, source:raw]
    // CALL: Call UtilityFunction_9ca4(1) after the message box and return its result. [callee:0x00589CA4, source:raw]
    // RETURN: Return the result of UtilityFunction_9ca4(1) on the error path, or a1 (zero) on the no-error path. [source:raw]
    // CALL: Called by sub_493C80 (0x00493C80), sub_497AD0 (0x00497AD0) and sub_497BA0 (0x00497BA0) on error paths. [caller:0x00493C80, caller:0x00497AD0, caller:0x00497BA0, source:raw]

    // Conservative worker pseudocode:
    //   int __stdcall sub_4986D0(int a1) {
    //     int result = a1;
    //     if (a1) {
    //       CHAR Text[128];
    //       sub_587DD0(Text, a1, 127);
    //       Text[127] = 0;
    //       MessageBoxA(0, Text, aOptionsError, 0);
    //       return UtilityFunction_9ca4(1);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantics of UtilityFunction_9ca4's return value and its side effects are unknown.
    // UNRESOLVED: MessageBoxA is referenced via an import thunk (global 0x0059E2A4); the ABI is Win32 USER32.
    // UNRESOLVED: Meaning of the numeric error codes passed by callers is unknown.
    // UNRESOLVED: Owner object is unknown; the function is a free __stdcall error reporter.
}
