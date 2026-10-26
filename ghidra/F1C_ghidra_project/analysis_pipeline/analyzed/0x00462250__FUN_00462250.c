// Function: FUN_00462250 @ 00462250
// Size (bytes): 176


bool __thiscall
FUN_00462250(undefined4 param_1,uint *param_2,int param_3,int param_4,undefined4 param_5)

{
  uint *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint local_4;
  
  puVar1 = param_2;
  local_4._1_3_ = (undefined3)((uint)param_1 >> 8);
  local_4 = CONCAT31(local_4._1_3_,(byte)(*param_2 >> 0x1b)) & 0xffffff01;
  piVar2 = (int *)FUN_0057a680();
  if (param_4 == -1) {
    *(undefined1 *)(piVar2 + 1) = 1;
  }
  else {
    (**(code **)(*piVar2 + 0xc))(param_4);
  }
  if (param_3 == 1) {
    uVar3 = 1;
  }
  else {
    if (param_3 == 2) {
      uVar3 = 2;
      param_2 = (uint *)0x1;
      goto LAB_004622a0;
    }
    uVar3 = 0;
  }
  param_2 = (uint *)0x0;
LAB_004622a0:
  iVar4 = FUN_0057a6a0(puVar1,(*puVar1 >> 8 & 0x3ff) + 8,piVar2,local_4,uVar3,param_5,param_2);
  FUN_0057a690(piVar2);
  return iVar4 == 0;
}


