// Function: FUN_00541810 @ 00541810
// Size (bytes): 147


void __thiscall FUN_00541810(undefined4 *param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_1[0x4f6] != 0) {
    iVar3 = 0;
    if (0 < (int)param_1[0x557]) {
      puVar2 = param_1 + 0x558;
      do {
        uVar1 = (**(code **)(*(int *)param_1[0x440] + 0xb8))((int *)param_1[0x440],*puVar2,0);
        *param_1 = uVar1;
        iVar3 = iVar3 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar3 < (int)param_1[0x557]);
    }
    iVar3 = 0;
    param_1[0x557] = param_2;
    if (0 < param_2) {
      puVar2 = param_1 + 0x558;
      do {
        uVar1 = *(undefined4 *)(*param_3 + 4);
        *puVar2 = uVar1;
        uVar1 = (**(code **)(*(int *)param_1[0x440] + 0xb8))((int *)param_1[0x440],uVar1,1);
        *param_1 = uVar1;
        iVar3 = iVar3 + 1;
        puVar2 = puVar2 + 1;
        param_3 = param_3 + 0xe;
      } while (iVar3 < (int)param_1[0x557]);
    }
  }
  return;
}


