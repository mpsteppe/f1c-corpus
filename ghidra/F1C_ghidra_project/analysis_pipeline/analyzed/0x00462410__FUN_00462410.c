// Function: FUN_00462410 @ 00462410
// Size (bytes): 74


undefined4 __thiscall FUN_00462410(int *param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  uVar1 = 0;
  if ((-1 < param_2) && (param_2 < *(int *)(*param_1 + 0x3e14))) {
    puVar3 = (undefined4 *)(param_2 * 0x8c + 0x394 + *param_1);
    for (iVar2 = 0x23; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_3 = *puVar3;
      puVar3 = puVar3 + 1;
      param_3 = param_3 + 1;
    }
    *param_4 = *(undefined4 *)(*param_1 + 0x3c74 + param_2 * 4);
    uVar1 = 1;
  }
  return uVar1;
}


