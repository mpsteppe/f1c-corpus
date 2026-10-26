## WindowsAdminCheck_00423250 — WindowsAdminCheck

**Summary:** Checks whether the current process runs with administrator privileges by impersonating the security context, building a LOCAL system SID ACL, and calling AccessCheck. Returns true if the token has the required access rights.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConfigIniParser (00421cd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0058895c | ScriptFrameProcessor | R | function pointer table for file I/O (used by FileOpWithGlobalBuffer) |
| 0059e000 | SetSecurityDescriptorOwner | R | imported Win32 API: SetSecurityDescriptorOwner |
| 0059e00c | FreeSid | R | imported Win32 API: FreeSid |
| 0059e010 | RevertToSelf | R | imported Win32 API: RevertToSelf |
| 0059e014 | AccessCheck | R | imported Win32 API: AccessCheck |
| 0059e018 | IsValidSecurityDescriptor | R | imported Win32 API: IsValidSecurityDescriptor |
| 0059e01c | ImpersonateSelf | R | imported Win32 API: ImpersonateSelf |
| 0059e020 | OpenThreadToken | R | imported Win32 API: OpenThreadToken |
| 0059e024 | OpenProcessToken | R | imported Win32 API: OpenProcessToken |
| 0059e028 | AllocateAndInitializeSid | R | imported Win32 API: AllocateAndInitializeSid |
| 0059e02c | InitializeSecurityDescriptor | R | imported Win32 API: InitializeSecurityDescriptor |
| 0059e030 | GetLengthSid | R | imported Win32 API: GetLengthSid |
| 0059e034 | InitializeAcl | R | imported Win32 API: InitializeAcl |
| 0059e038 | AddAccessAllowedAce | R | imported Win32 API: AddAccessAllowedAce |
| 0059e03c | SetSecurityDescriptorDacl | R | imported Win32 API: SetSecurityDescriptorDacl |
| 0059e040 | SetSecurityDescriptorGroup | R | imported Win32 API: SetSecurityDescriptorGroup |
| 0059e0f0 | GetCurrentThread | R | imported Win32 API: GetCurrentThread |
| 0059e188 | GetLastError | R | imported Win32 API: GetLastError |
| 0059e18c | GetCurrentProcess | R | imported Win32 API: GetCurrentProcess |
| 0059e190 | LocalAlloc | R | imported Win32 API: LocalAlloc |
| 0059e194 | LocalFree | R | imported Win32 API: LocalFree |
| 0059e840 | stru_59E840 | R | SecurityDescriptorBase [DERIVED] |
| 005c3084 | aAccesscheckFai | R | AccessCheckFailed [DERIVED] |
| ff00000000001692 | byte_FF00000000001692 | R | PE header field (read during image validation) |
| ff00000000001695 | byte_FF00000000001695 | W | PE header field (written during initialization) |
| ff0000000000169b | byte_FF0000000000169B | RW | PE header field (read/write during config parsing) |
| ff00000000005379 | byte_FF00000000005379 | W | data section field (written during security check) |
| ff0000000000537e | byte_FF0000000000537E | W | data section field (written during security check) |
| ff0000000000537f | byte_FF0000000000537F | W | data section field (written during security check) |
| ff00000000005380 | byte_FF00000000005380 | W | data section field (written during security check) |
| ff00000000005381 | byte_FF00000000005381 | W | data section field (written during security check) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588821 | FileOpWithGlobalBuffer | writes error message string to log/file on AccessCheck failure |

**Guard conditions:** OpenThreadToken must succeed OR (GetLastError == 1008 (ERROR_NO_TOKEN) AND OpenProcessToken succeeds) — if neither works, entire check is skipped. AllocateAndInitializeSid must succeed. LocalAlloc for security descriptor (0x14 bytes) must succeed. LocalAlloc for ACL must succeed. InitializeAcl must succeed. AddAccessAllowedAce must succeed. SetSecurityDescriptorDacl must succeed. IsValidSecurityDescriptor must pass. AccessCheck must return TRUE. Function returns AccessStatus (BOOL) — defaults to FALSE if any step fails.
