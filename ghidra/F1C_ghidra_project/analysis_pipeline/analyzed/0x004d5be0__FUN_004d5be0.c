// Function: FUN_004d5be0 @ 004d5be0
// Size (bytes): 78


void __thiscall FUN_004d5be0(undefined4 *param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_3) {
    do {
      bVar1 = *(byte *)(iVar3 + param_2);
      iVar2 = param_1[3];
      param_1[3] = param_1[4];
      iVar3 = iVar3 + 1;
      param_1[6] = param_1[6] + (uint)bVar1 * iVar2;
      param_1[4] = param_1[5];
      param_1[5] = iVar2;
    } while (iVar3 < param_3);
  }
  FUN_00588678(param_2,param_3,1,*param_1);
  return;
}


