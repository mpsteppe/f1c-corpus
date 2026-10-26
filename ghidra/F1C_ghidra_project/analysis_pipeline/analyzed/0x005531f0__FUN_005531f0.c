// Function: FUN_005531f0 @ 005531f0
// Size (bytes): 167


void __thiscall FUN_005531f0(int param_1,char *param_2,int *param_3,undefined4 *param_4)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  
  if (param_4 != (undefined4 *)0x0) {
    uVar3 = __ftol();
    *param_4 = uVar3;
  }
  if (param_3 != (int *)0x0) {
    iVar4 = -1;
    uVar6 = 0;
    *param_3 = 0;
    pcVar7 = param_2;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    if (iVar4 != -2) {
      do {
        bVar2 = param_2[uVar6];
        if ((0x1f < bVar2) && ((int)(uint)bVar2 < *(int *)(param_1 + 0x44))) {
          *param_3 = *param_3 + (uint)*(byte *)(param_1 + -0x94 + (uint)bVar2 * 8);
        }
        uVar5 = 0xffffffff;
        uVar6 = uVar6 + 1;
        pcVar7 = param_2;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
      } while (uVar6 < ~uVar5 - 1);
    }
    iVar4 = __ftol();
    *param_3 = iVar4;
  }
  return;
}


