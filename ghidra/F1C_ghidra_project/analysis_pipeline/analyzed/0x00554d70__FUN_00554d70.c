// Function: FUN_00554d70 @ 00554d70
// Size (bytes): 148


undefined4 __thiscall FUN_00554d70(undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = param_2[0x15];
  if (*(int *)(iVar1 + 0x14) != 0) {
    iVar3 = 0;
    if (0 < (int)param_1[0x4ec]) {
      do {
        uVar2 = (**(code **)(*(int *)param_1[0x440] + 0xf0))((int *)param_1[0x440],iVar3,&param_2);
        *param_1 = uVar2;
        if (param_2 != (int *)0x0) {
          if (*(int **)(iVar1 + 0x14) == param_2) {
            FUN_00554610(0);
          }
          (**(code **)(*param_2 + 8))(param_2);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)param_1[0x4ec]);
    }
    uVar2 = (**(code **)(**(int **)(iVar1 + 0x14) + 8))(*(int **)(iVar1 + 0x14));
    *param_1 = uVar2;
    *(undefined4 *)(iVar1 + 0x14) = 0;
  }
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & 0xfffffbf7;
  *(undefined4 *)(iVar1 + 0x38) = 0xbf800000;
  return 0;
}


