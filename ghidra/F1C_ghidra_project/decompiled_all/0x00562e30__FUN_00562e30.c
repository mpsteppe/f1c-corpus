// Function: FUN_00562e30 @ 00562e30
// Strings:  [\list\%s\gamename\%s\final\, \list\%s\gamename\%s\where\%s\final\, info2, info2, groups, groups, groups, \gamename\%s\gamever\%s\location\0\validate\%s\enctype\2\final\\queryid\1.1\]


undefined4 __fastcall FUN_00562e30(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  char local_140 [256];
  undefined1 local_40 [64];
  
  iVar2 = recv(*(SOCKET *)(param_1 + 0x88),local_140,0xff,0);
  if (iVar2 != -1) {
    local_140[iVar2] = '\0';
    iVar2 = FUN_00587c20(local_140,s__secure__005e503c);
    if (iVar2 == 0) {
      return 5;
    }
    iVar2 = iVar2 + 8;
    FUN_00564c70(iVar2,6);
    iVar3 = 0;
    do {
      *(byte *)(iVar2 + iVar3) = *(byte *)(iVar2 + iVar3) ^ *(byte *)(param_1 + 0x2c + iVar3);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 6);
    FUN_00564b80(local_40);
    FUN_0058815f(local_140,s__gamename__s_gamever__s_location_005e4fe8,param_1 + 0x4c,&DAT_005e5038,
                 local_40);
    uVar5 = 0xffffffff;
    pcVar4 = local_140;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    iVar2 = send(*(SOCKET *)(param_1 + 0x88),local_140,~uVar5 - 1,0);
    if ((iVar2 != -1) && (iVar2 != 0)) {
      if (*(int *)(param_1 + 0x90) == 6) {
        pcVar4 = s_groups_005e4fe0;
        *(undefined4 *)(param_1 + 0x5b4) = 0;
      }
      else if (*(int *)(param_1 + 0x90) == 7) {
        pcVar4 = s_info2_005e4fd8;
        *(undefined4 *)(param_1 + 0x5b4) = 0;
      }
      else {
        pcVar4 = (char *)&PTR_DAT_005e4fd4;
      }
      if (param_2 == 0) {
        FUN_0058815f(local_140,s__list__s_gamename__s_final__005e4f90,pcVar4,param_1 + 0xc);
      }
      else {
        FUN_0058815f(local_140,s__list__s_gamename__s_where__s_fi_005e4fac,pcVar4,param_1 + 0xc,
                     param_2);
      }
      uVar5 = 0xffffffff;
      pcVar4 = local_140;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      iVar2 = send(*(SOCKET *)(param_1 + 0x88),local_140,~uVar5 - 1,0);
      if ((iVar2 != -1) && (iVar2 != 0)) {
        FUN_00562fe0();
        return 0;
      }
    }
  }
  return 3;
}


