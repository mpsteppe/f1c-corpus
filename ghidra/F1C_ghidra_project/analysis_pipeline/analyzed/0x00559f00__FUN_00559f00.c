// Function: FUN_00559f00 @ 00559f00
// Size (bytes): 172


undefined4 __thiscall
FUN_00559f00(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5,
            undefined4 *param_6)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  iVar2 = FUN_00559d80(param_2);
  puVar1 = param_3;
  if (iVar2 != 0) {
    iVar2 = *(int *)(param_1 + 0x30c) + 1;
    uVar4 = 1;
    param_2 = iVar2;
    if (param_3 != (undefined4 *)0x0) {
      uVar3 = FUN_00589278(iVar2,&param_2,10);
      *puVar1 = uVar3;
      iVar2 = param_2 + 1;
    }
    puVar1 = param_4;
    if (param_4 != (undefined4 *)0x0) {
      uVar3 = FUN_00589278(iVar2,&param_2,10);
      *puVar1 = uVar3;
      iVar2 = param_2 + 1;
    }
    puVar1 = param_5;
    if (param_5 != (undefined4 *)0x0) {
      uVar3 = FUN_00589278(iVar2,&param_2,10);
      *puVar1 = uVar3;
      iVar2 = param_2 + 1;
    }
    puVar1 = param_6;
    if (param_6 != (undefined4 *)0x0) {
      uVar3 = FUN_00589278(iVar2,&param_2,10);
      *puVar1 = uVar3;
    }
  }
  return uVar4;
}


