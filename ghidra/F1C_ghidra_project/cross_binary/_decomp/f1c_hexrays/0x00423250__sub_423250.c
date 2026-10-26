// f1c  0x00423250  size=558
bool sub_423250()
{
  ACL *v0; // ebx
  void *v1; // edi
  HANDLE CurrentThread; // eax
  HANDLE CurrentProcess; // eax
  HLOCAL v4; // eax
  SIZE_T v5; // esi
  ACL *v6; // eax
  DWORD LastError; // eax
  _PRIVILEGE_SET PrivilegeSet; // [esp+Ch] [ebp-6Ch] BYREF
  DWORD GrantedAccess; // [esp+20h] [ebp-58h] BYREF
  GENERIC_MAPPING GenericMapping; // [esp+24h] [ebp-54h] BYREF
  int v12; // [esp+34h] [ebp-44h]
  int v13; // [esp+38h] [ebp-40h]
  SIZE_T v14; // [esp+3Ch] [ebp-3Ch]
  HANDLE TokenHandle; // [esp+40h] [ebp-38h] BYREF
  _SID_IDENTIFIER_AUTHORITY pIdentifierAuthority; // [esp+44h] [ebp-34h] BYREF
  HLOCAL v17; // [esp+4Ch] [ebp-2Ch]
  BOOL AccessStatus; // [esp+50h] [ebp-28h] BYREF
  PSID pSid; // [esp+54h] [ebp-24h] BYREF
  ACL *v20; // [esp+58h] [ebp-20h]
  DWORD PrivilegeSetLength; // [esp+5Ch] [ebp-1Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+60h] [ebp-18h]

  PrivilegeSetLength = 20;
  v0 = 0;
  v20 = 0;
  pSid = 0;
  AccessStatus = 0;
  v1 = 0;
  v17 = 0;
  pIdentifierAuthority.Value[0] = 0;
  pIdentifierAuthority.Value[1] = 0;
  pIdentifierAuthority.Value[2] = 0;
  pIdentifierAuthority.Value[3] = 0;
  pIdentifierAuthority.Value[4] = 0;
  pIdentifierAuthority.Value[5] = 5;
  ms_exc.registration.TryLevel = 0;
  ImpersonateSelf(SecurityImpersonation);
  CurrentThread = GetCurrentThread();
  if ( OpenThreadToken(CurrentThread, 8u, 0, &TokenHandle)
    || GetLastError() == 1008
    && (CurrentProcess = GetCurrentProcess(), OpenProcessToken(CurrentProcess, 8u, &TokenHandle)) )
  {
    if ( AllocateAndInitializeSid(&pIdentifierAuthority, 2u, 0x20u, 0x220u, 0, 0, 0, 0, 0, 0, &pSid) )
    {
      v4 = LocalAlloc(0x40u, 0x14u);
      v1 = v4;
      v17 = v4;
      if ( v4 )
      {
        if ( InitializeSecurityDescriptor(v4, 1u) )
        {
          v5 = GetLengthSid(pSid) + 16;
          v14 = v5;
          v6 = (ACL *)LocalAlloc(0x40u, v5);
          v0 = v6;
          v20 = v6;
          if ( v6 )
          {
            if ( InitializeAcl(v6, v5, 2u) )
            {
              v13 = 3;
              if ( AddAccessAllowedAce(v0, 2u, 3u, pSid) )
              {
                if ( SetSecurityDescriptorDacl(v1, 1, v0, 0) )
                {
                  SetSecurityDescriptorGroup(v1, pSid, 0);
                  SetSecurityDescriptorOwner(v1, pSid, 0);
                  if ( IsValidSecurityDescriptor(v1) )
                  {
                    v12 = 1;
                    GenericMapping.GenericRead = 1;
                    GenericMapping.GenericWrite = 2;
                    GenericMapping.GenericExecute = 0;
                    GenericMapping.GenericAll = 3;
                    if ( AccessCheck(
                           v1,
                           TokenHandle,
                           1u,
                           &GenericMapping,
                           &PrivilegeSet,
                           &PrivilegeSetLength,
                           &GrantedAccess,
                           &AccessStatus) )
                    {
                      RevertToSelf();
                    }
                    else
                    {
                      LastError = GetLastError();
                      sub_588821("AccessCheck() failed with error %lu\n", LastError);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  ms_exc.registration.TryLevel = -1;
  if ( v0 )
    LocalFree(v0);
  if ( v1 )
    LocalFree(v1);
  if ( pSid )
    FreeSid(pSid);
  return AccessStatus;
}
