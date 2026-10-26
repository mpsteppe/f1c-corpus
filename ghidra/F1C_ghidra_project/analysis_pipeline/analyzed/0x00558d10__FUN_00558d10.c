// Function: FUN_00558d10 @ 00558d10
// Size (bytes): 101


void __thiscall FUN_00558d10(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  uVar1 = *(uint *)(param_1 + 0x20);
  if ((uVar1 & 0x100) == 0) {
    param_2 = param_2 * 0x40;
    *(uint *)(param_1 + 0x20) = uVar1 | 0x100;
    if ((char)uVar1 < '\0') {
      iVar2 = *(int *)(param_1 + 0x50);
      iVar4 = *(int *)(iVar2 + 8 + param_2);
      uVar3 = *(undefined4 *)(iVar2 + 0x2c + param_2);
      uVar5 = *(undefined4 *)(iVar2 + param_2 + 0x1c);
      uVar6 = 0x20;
    }
    else {
      iVar4 = *(int *)(*(int *)(param_1 + 0x50) + 8 + param_2) * *(int *)(param_1 + 0x2c);
      iVar2 = *(int *)(param_1 + 0x50) + param_2;
      uVar5 = *(undefined4 *)(iVar2 + 0x1c);
      uVar3 = *(undefined4 *)(iVar2 + 0x2c);
      uVar6 = 0x60;
    }
    uVar3 = FUN_00540f00(uVar5,uVar6,uVar3,iVar4);
    *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x20 + param_2) = uVar3;
  }
  return;
}


