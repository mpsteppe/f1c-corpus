// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005904C1
// Canonical corpus name: WindowsNTCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WindowsNTCheck_005904c1.c

void UnknownObject::WindowsNTCheck()
{
    // Windows platform check: fills an OSVERSIONINFOA struct (dwOSVersionInfoSize = 148 = sizeof(OSVERSIONINFOA)), calls the GetVersionExA import, and returns TRUE only when the call succeeds and dwPlatformId equals 2 (Windows NT family). Called by sub_58FD90, likely as a startup capability/OS gate.
    // ASSIGNMENT: Initialize VersionInformation.dwOSVersionInfoSize to 148, writing the version-info struct field at stack slot global:0xFF00000000005370. [global:0xFF00000000005370, source:raw]
    // CALL: Call the GetVersionExA import (0x0059E198) with a pointer to the VersionInformation struct. [global:0x0059E198, source:raw]
    // GUARD: Return TRUE only if GetVersionExA succeeded AND the dwPlatformId field read at stack slot global:0xFF00000000005374 equals 2. [global:0xFF00000000005374, source:raw]
    // RETURN: Return the combined boolean result of the success and platform checks. [source:raw]

    // Conservative worker pseudocode:
    //   struct _OSVERSIONINFOA VersionInformation;
    //   VersionInformation.dwOSVersionInfoSize = 148;
    //   return GetVersionExA(&VersionInformation) && VersionInformation.dwPlatformId == 2;
    // UNRESOLVED: Globals global:0xFF00000000005370 / global:0xFF00000000005374 carry sign-extended stack-frame addresses (the long leading run of F digits indicates 32-bit sign extension into a 64-bit IDA name); they are treated as the version-info struct stack slots (write dwOSVersionInfoSize, read dwPlatformId) rather than true data globals.
}
