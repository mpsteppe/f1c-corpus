// Function: FUN_00462010 @ 00462010
// Strings:  [openplaying, openplaying, gamemode, maxplayers, numplayers, mapname, hostport, hostname]


undefined4
FUN_00462010(undefined4 param_1,char *param_2,char *param_3,int param_4,undefined4 param_5)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  iVar3 = FUN_00563e80();
  if (iVar3 != 0) {
    uVar4 = FUN_005644b0(s_openplaying_005c5bf0);
    iVar3 = FUN_00588410(uVar4,s_openstaging_005c61e0);
    if (iVar3 != 0) {
      iVar3 = FUN_00588410(uVar4,s_openplaying_005c5bf0);
      *(bool *)param_5 = iVar3 != 0;
      iVar3 = FUN_00564530(0);
      FUN_004615c0(2,iVar3 != 0);
      pcVar5 = (char *)FUN_005644b0(s__NONAME__005c61d4);
      _strncpy(param_2,pcVar5,0x1f);
      param_2[0x1f] = '\0';
      uVar2 = FUN_00564480();
      *(undefined2 *)(param_2 + 0x70) = uVar2;
      uVar2 = FUN_00564530(0);
      *(undefined2 *)(param_2 + 0x72) = uVar2;
      cVar1 = FUN_00564530(0);
      param_2[0x65] = cVar1;
      cVar1 = FUN_00564530(0);
      param_2[0x66] = cVar1;
      if (((param_3 != (char *)0x0) && (0 < param_4)) &&
         (pcVar5 = (char *)FUN_005644b0(s__NO_MAP__005c61c8), pcVar5 != (char *)0x0)) {
        _strncpy(param_3,pcVar5,param_4 - 1U);
        param_3[param_4 - 1U] = '\0';
      }
      return 1;
    }
  }
  return 0;
}


