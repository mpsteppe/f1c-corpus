// Function: FUN_00423250 @ 00423250
// Size (bytes): 515


bool FUN_00423250(void)

{
  HANDLE pvVar1;
  HLOCAL pSecurityDescriptor;
  PACL pAcl;
  SIZE_T uBytes;
  DWORD DVar2;
  BOOL BVar3;
  HANDLE *ppvVar4;
  _PRIVILEGE_SET local_70;
  DWORD local_5c;
  GENERIC_MAPPING local_58;
  undefined4 local_48;
  undefined4 local_44;
  SIZE_T local_40;
  HANDLE local_3c;
  _SID_IDENTIFIER_AUTHORITY local_38;
  HLOCAL local_30;
  BOOL local_2c;
  PSID local_28;
  PACL local_24;
  DWORD local_20 [3];
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0059e840;
  puStack_10 = &LAB_0058895c;
  local_14 = ExceptionList;
  local_20[0] = 0x14;
  local_24 = (PACL)0x0;
  local_28 = (PSID)0x0;
  local_2c = 0;
  local_30 = (HLOCAL)0x0;
  local_38.Value[0] = '\0';
  local_38.Value[1] = '\0';
  local_38.Value[2] = '\0';
  local_38.Value[3] = '\0';
  local_38.Value[4] = '\0';
  local_38.Value[5] = '\x05';
  local_8 = 0;
  ExceptionList = &local_14;
  ImpersonateSelf(SecurityImpersonation);
  ppvVar4 = &local_3c;
  BVar3 = 0;
  DVar2 = 8;
  pvVar1 = GetCurrentThread();
  BVar3 = OpenThreadToken(pvVar1,DVar2,BVar3,ppvVar4);
  if (BVar3 == 0) {
    DVar2 = GetLastError();
    if (DVar2 != 0x3f0) goto LAB_0042342e;
    ppvVar4 = &local_3c;
    DVar2 = 8;
    pvVar1 = GetCurrentProcess();
    BVar3 = OpenProcessToken(pvVar1,DVar2,ppvVar4);
    if (BVar3 == 0) goto LAB_0042342e;
  }
  BVar3 = AllocateAndInitializeSid(&local_38,'\x02',0x20,0x220,0,0,0,0,0,0,&local_28);
  if (BVar3 != 0) {
    pSecurityDescriptor = LocalAlloc(0x40,0x14);
    local_30 = pSecurityDescriptor;
    if (pSecurityDescriptor != (HLOCAL)0x0) {
      BVar3 = InitializeSecurityDescriptor(pSecurityDescriptor,1);
      if (BVar3 != 0) {
        DVar2 = GetLengthSid(local_28);
        uBytes = DVar2 + 0x10;
        local_40 = uBytes;
        pAcl = LocalAlloc(0x40,uBytes);
        local_24 = pAcl;
        if (pAcl != (PACL)0x0) {
          BVar3 = InitializeAcl(pAcl,uBytes,2);
          if (BVar3 != 0) {
            local_44 = 3;
            BVar3 = AddAccessAllowedAce(pAcl,2,3,local_28);
            if (BVar3 != 0) {
              BVar3 = SetSecurityDescriptorDacl(pSecurityDescriptor,1,pAcl,0);
              if (BVar3 != 0) {
                SetSecurityDescriptorGroup(pSecurityDescriptor,local_28,0);
                SetSecurityDescriptorOwner(pSecurityDescriptor,local_28,0);
                BVar3 = IsValidSecurityDescriptor(pSecurityDescriptor);
                if (BVar3 != 0) {
                  local_48 = 1;
                  local_58.GenericRead = 1;
                  local_58.GenericWrite = 2;
                  local_58.GenericExecute = 0;
                  local_58.GenericAll = 3;
                  BVar3 = AccessCheck(pSecurityDescriptor,local_3c,1,&local_58,&local_70,local_20,
                                      &local_5c,&local_2c);
                  if (BVar3 == 0) {
                    DVar2 = GetLastError();
                    FUN_00588821(s_AccessCheck___failed_with_error___005c3084,DVar2);
                  }
                  else {
                    RevertToSelf();
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0042342e:
  local_8 = 0xffffffff;
  FUN_00423459();
  ExceptionList = local_14;
  return local_2c != 0;
}


