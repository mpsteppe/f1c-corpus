// Function: FUN_005504d0 @ 005504d0
// Size (bytes): 205


int __thiscall FUN_005504d0(int param_1,uint param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  if (param_3 < *(int *)(param_1 + 0xa4)) {
    iVar2 = param_3 * 0x94 + *(int *)(param_1 + 0xa8);
    if (1 < *(int *)(param_3 * 0x94 + 0x48 + *(int *)(param_1 + 0xa8))) {
      if (param_2 == 0xffffffff) {
        return *(int *)(iVar2 + 0x8c);
      }
      uVar3 = (int)param_2 >> 0x1f;
      if (*(int *)(iVar2 + 0x50) <= (int)param_2) {
        return *(int *)(*(int *)(iVar2 + 0x4c) +
                       (((param_2 ^ uVar3) - uVar3) - *(int *)(iVar2 + 0x50)) * 4) * 0x60 +
               *(int *)(iVar2 + 0x8c);
      }
      return *(int *)(*(int *)(iVar2 + 0x4c) + ((param_2 ^ uVar3) - uVar3) * 4) * 0x60 +
             *(int *)(iVar2 + 0x8c);
    }
    if ((*(int *)(iVar2 + 0x90) != 0) && (DAT_008b6ac4 != 0)) {
      FUN_00551dd0(*(undefined4 *)(*(int *)(iVar2 + 0x8c) + 0x54),0,0,0x20);
      puVar1 = (uint *)(*(int *)(*(int *)(iVar2 + 0x8c) + 0x54) + 0x18);
      *puVar1 = *puVar1 & 0xfffffbff;
    }
    iVar2 = *(int *)(iVar2 + 0x8c);
  }
  return iVar2;
}


