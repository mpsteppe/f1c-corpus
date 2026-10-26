// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00423250
// Canonical corpus name: WindowsAdminCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WindowsAdminCheck_00423250.c

void UnknownObject::WindowsAdminCheck()
{
    // Determines whether the current process has administrator privilege. Impersonates a self security context, opens the thread token (falling back to the process token when no thread token exists, ERROR_NO_TOKEN 1008), builds a LOCAL SYSTEM SID ACL in a security descriptor, and calls AccessCheck with a GENERIC_MAPPING. Returns the AccessStatus BOOL (and RevertToSelf on success). On AccessCheck failure, formats an error message with GetLastError and logs it through FileOpWithGlobalBuffer. Invoked by ConfigIniParser (00421cd0).
    // ASSIGNMENT: Initialize locals: PrivilegeSetLength = 20, zero the ACL/SD/SID handles, AccessStatus = 0, and seed the SID identifier authority with value 5 (LOCAL SYSTEM authority). [source:raw]
    // CALL: ImpersonateSelf(SecurityImpersonation) so the token opened next reflects the calling thread's security context. [global:0x0059E01C, source:raw]
    // CALL: GetCurrentThread then OpenThreadToken(thread, TOKEN_QUERY=8, 0, &TokenHandle) attempts to open the impersonation token. [global:0x0059E0F0, global:0x0059E020, source:raw]
    // GUARD: Fallback when OpenThreadToken fails with GetLastError() == 1008 (ERROR_NO_TOKEN): GetCurrentProcess then OpenProcessToken(process, 8, &TokenHandle) opens the process token instead. [global:0x0059E188, global:0x0059E18C, global:0x0059E024, source:raw]
    // CALL: AllocateAndInitializeSid(&pIdentifierAuthority, 2, 0x20, 0x220, ...) builds the LOCAL SYSTEM SID with two sub-authorities; the whole check proceeds only if the SID allocates. [global:0x0059E028, source:raw]
    // CALL: LocalAlloc(0x40, 0x14) allocates the security descriptor and InitializeSecurityDescriptor initializes it as a self-relative descriptor. [global:0x0059E190, global:0x0059E02C, source:raw]
    // CALL: Compute ACL size as GetLengthSid(pSid) + 16, then LocalAlloc(0x40, size) for the ACL buffer. [global:0x0059E030, global:0x0059E190, source:raw]
    // CALL: InitializeAcl(acl, size, 2) then AddAccessAllowedAce(acl, 2, 3, pSid) adds a GENERIC_READ (3) access-allowed ACE for the LOCAL SYSTEM SID. [global:0x0059E034, global:0x0059E038, source:raw]
    // CALL: Attach the ACL and SID to the descriptor: SetSecurityDescriptorDacl, SetSecurityDescriptorGroup and SetSecurityDescriptorOwner, then validate with IsValidSecurityDescriptor. [global:0x0059E03C, global:0x0059E040, global:0x0059E000, global:0x0059E018, source:raw]
    // CALL: AccessCheck(descriptor, TokenHandle, 1, &GenericMapping, &PrivilegeSet, &PrivilegeSetLength, &GrantedAccess, &AccessStatus) with GENERIC_MAPPING GenericRead=1, GenericWrite=2, GenericExecute=0, GenericAll=3; the resulting admin verdict is stored in AccessStatus. [global:0x0059E014, source:raw]
    // CALL: On AccessCheck success RevertToSelf() undoes the impersonation; on failure GetLastError() is captured and FileOpWithGlobalBuffer('AccessCheck() failed with error %lu\n', LastError) logs it (via the ScriptFrameProcessor file-I/O path). [global:0x0059E010, global:0x0059E188, global:0x005C3084, global:0x0058895C, callee:0x00588821, source:raw]
    // CALL: Cleanup: LocalFree the ACL buffer, LocalFree the security descriptor, and FreeSid the allocated SID before returning. [global:0x0059E194, global:0x0059E00C, source:raw]
    // RETURN: Return AccessStatus as the admin check verdict; the function is invoked by ConfigIniParser (00421cd0). [function:0x00423250, caller:0x00421CD0, source:raw]

    // Conservative worker pseudocode:
    //   bool WindowsAdminCheck() {
    //     PrivilegeSetLength = 20; acl = sd = sid = NULL; AccessStatus = FALSE;
    //     authority.Value[5] = 5; /* LOCAL SYSTEM * /
    //     ImpersonateSelf(SecurityImpersonation);
    //     if (!OpenThreadToken(GetCurrentThread(), 8, 0, &token) &&
    //         GetLastError() == 1008) OpenProcessToken(GetCurrentProcess(), 8, &token);
    //     if (AllocateAndInitializeSid(&authority, 2, 0x20, 0x220, 0,0,0,0,0,0, &sid)) {
    //       if ((sd = LocalAlloc(0x40, 0x14)) && InitializeSecurityDescriptor(sd, 1) &&
    //           (acl = LocalAlloc(0x40, GetLengthSid(sid)+16)) && InitializeAcl(acl, GetLengthSid(sid)+16, 2) &&
    //           AddAccessAllowedAce(acl, 2, 3, sid) && SetSecurityDescriptorDacl(sd, 1, acl, 0) &&
    //           (SetSecurityDescriptorGroup(sd, sid, 0), SetSecurityDescriptorOwner(sd, sid, 0)) &&
    //           IsValidSecurityDescriptor(sd)) {
    //         memset map = {1,2,0,3};
    //         if (AccessCheck(sd, token, 1, &map, &priv, &privLen, &granted, &ok)) RevertToSelf();
    //         else FileOpWithGlobalBuffer("AccessCheck() failed with error %lu\n", GetLastError());
    //       }
    //     }
    //     if (acl) LocalFree(acl); if (sd) LocalFree(sd); if (sid) FreeSid(sid);
    //     return AccessStatus;
    //   }
    // UNRESOLVED: stru_59E840 (read-only global) is flagged by packet facts but does not appear in the decompiled body; its role is unknown.
    // UNRESOLVED: The byte_FF0000000000xxxx read/write globals are outside the process image (TEB-region style addresses) and appear nowhere in the decompiled source; likely SEH/thread-context artifacts of the raw disassembly, not program data.
}
