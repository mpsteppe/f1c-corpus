// Function: FUN_0054fa00 @ 0054fa00
// Size (bytes): 74


undefined4 __thiscall FUN_0054fa00(int param_1,uint *param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x1e0) + 8);
  if ((iVar1 != 0) && (param_3 < *(int *)(*(int *)(param_1 + 0x1e0) + 4))) {
    puVar2 = (uint *)(param_3 * 0x74 + iVar1);
    puVar2[1] = *param_2;
    puVar2[2] = param_2[1];
    puVar2[3] = param_2[2];
    puVar2[7] = param_2[3];
    puVar2[8] = param_2[4];
    puVar2[9] = param_2[5];
    *puVar2 = *puVar2 | 8;
  }
  return 0;
}


