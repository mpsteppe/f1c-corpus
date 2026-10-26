// Function: FUN_00414900 @ 00414900
// Size (bytes): 149


undefined4 __fastcall FUN_00414900(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char local_100 [250];
  undefined1 local_6;
  
  if (param_1 != (char *)0x0) {
    _strncpy(local_100,param_1,0xfa);
    iVar2 = -1;
    local_6 = 0;
    pcVar3 = local_100;
    do {
      pcVar4 = pcVar3;
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      pcVar4 = pcVar3 + 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar4;
    } while (cVar1 != '\0');
    *(undefined4 *)(pcVar4 + -1) = DAT_005be868;
    pcVar4[3] = DAT_005be86c;
    iVar2 = FUN_0058ba36(local_100,0x180);
    if (iVar2 != -1) {
      FUN_00566650(local_100);
      *(undefined4 *)(param_2 + 8) = 0xffffffff;
      *(undefined4 *)(param_2 + 0xc) = 0xffffffff;
      *(undefined1 *)(param_2 + 0x10) = 0;
      return 0;
    }
  }
  return 1;
}


