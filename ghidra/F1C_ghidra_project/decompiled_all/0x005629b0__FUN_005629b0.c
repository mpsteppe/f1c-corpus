// Function: FUN_005629b0 @ 005629b0
// Strings:  [\final\, \validate\%s]


void __thiscall FUN_005629b0(int param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  char local_248 [128];
  undefined1 local_1c8 [256];
  undefined1 local_c8 [200];
  
  if (*param_3 != '\0') {
    uVar2 = 0xffffffff;
    pcVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (0x80 < (int)(~uVar2 - 1)) {
      return;
    }
    iVar3 = -(int)param_3;
    do {
      cVar1 = *param_3;
      param_3[(int)(local_248 + iVar3)] = cVar1;
      param_3 = param_3 + 1;
    } while (cVar1 != '\0');
    iVar3 = -1;
    pcVar4 = (char *)(param_1 + 0x48);
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00562150(local_248,~uVar2 - 1);
    FUN_00562090(local_c8);
    FUN_0058815f(local_1c8,s__validate__s_005e4eb4,local_c8);
    FUN_00562710(param_2,local_1c8);
  }
  FUN_0058815f(local_1c8,s__final__005e4eac);
  FUN_00562710(param_2,local_1c8);
  FUN_00562610(param_2);
  return;
}


