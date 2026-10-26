// Function: FUN_0047b850 @ 0047b850
// Size (bytes): 182


int __thiscall FUN_0047b850(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  
  if (*(int *)(param_1 + 0xf4) < 1) {
    return 0;
  }
  iVar5 = *(int *)(param_1 + 0xf8);
  iVar1 = *(int *)(param_1 + 0xc);
  iVar2 = ((param_3 - *(int *)(param_1 + 0xfc)) - *(int *)(param_1 + 4)) / *(int *)(param_1 + 0xf4);
  iVar3 = *(int *)(param_1 + 0xf0) + -1;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  else if (iVar3 < iVar2) {
    iVar2 = iVar3;
  }
  iVar2 = iVar2 + *(int *)(param_1 + 0xec);
  iVar3 = 0;
  while( true ) {
    iVar4 = FUN_0047b730(iVar3);
    if (iVar3 == iVar4) {
      return iVar3;
    }
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    iVar3 = iVar4;
  }
  if (*(int *)(param_1 + 200) != 0) {
    puVar6 = *(undefined1 **)(*(int *)(param_1 + 200) + 0x40);
    if (puVar6 == (undefined1 *)0x0) {
      puVar6 = &DAT_005ea438;
    }
    FUN_00498560(puVar6);
  }
  iVar5 = FUN_0047b910((param_2 - iVar5) - iVar1,iVar3,iVar4);
  return iVar5;
}


