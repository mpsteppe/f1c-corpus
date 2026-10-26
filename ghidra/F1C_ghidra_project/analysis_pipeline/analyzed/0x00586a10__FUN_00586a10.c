// Function: FUN_00586a10 @ 00586a10
// Size (bytes): 106


undefined4 FUN_00586a10(undefined4 *param_1,uint param_2,uint *param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 *local_4;
  
  iVar2 = FUN_0053d880();
  if ((int)param_2 < iVar2) {
    return 4;
  }
  cVar1 = FUN_00587580(&local_4,&param_2);
  if (cVar1 != '\0') {
    for (uVar3 = param_2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *param_1 = *local_4;
      local_4 = local_4 + 1;
      param_1 = param_1 + 1;
    }
    for (uVar3 = param_2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)param_1 = *(undefined1 *)local_4;
      local_4 = (undefined4 *)((int)local_4 + 1);
      param_1 = (undefined4 *)((int)param_1 + 1);
    }
    if (param_3 != (uint *)0x0) {
      *param_3 = param_2;
    }
    return 0;
  }
  return 1;
}


