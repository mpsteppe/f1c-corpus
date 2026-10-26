// Function: FUN_00558e10 @ 00558e10
// Size (bytes): 91


void __thiscall
FUN_00558e10(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((*(int *)(param_1 + 0x4c) == 1) && (*(char *)(param_1 + 0x20) < '\0')) {
    FUN_00558d10(0);
    iVar1 = *(int *)(*(int *)(param_1 + 0x50) + 0x20);
    if (iVar1 != 0) {
      puVar2 = (undefined4 *)
               ((*(int *)(param_2 * 0x80 + 4 + *(int *)(param_1 + 0x34)) * *(int *)(param_1 + 0x24)
                + param_3) * 0x40 + iVar1);
      *puVar2 = param_4;
      puVar2[1] = param_5;
      puVar2[2] = param_6;
      puVar2[6] = param_7;
    }
  }
  return;
}


