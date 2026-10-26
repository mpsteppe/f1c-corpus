// Function: FUN_00587120 @ 00587120
// Size (bytes): 147


undefined4 FUN_00587120(undefined4 *param_1,uint *param_2)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *local_4;
  
  puVar1 = param_2;
  uVar4 = *param_2;
  iVar3 = FUN_0053d880();
  if (iVar3 <= (int)uVar4) {
    local_4 = (undefined4 *)0x0;
    param_2 = (uint *)uVar4;
    cVar2 = FUN_00587580(&local_4,&param_2);
    if (cVar2 != '\0') {
      uVar4 = *puVar1;
      if ((int)param_2 < (int)*puVar1) {
        uVar4 = (uint)param_2;
      }
      if ((0 < (int)uVar4) && ((undefined4 *)*param_1 != (undefined4 *)0x0)) {
        puVar6 = (undefined4 *)*param_1;
        for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar6 = *local_4;
          local_4 = local_4 + 1;
          puVar6 = puVar6 + 1;
        }
        for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined1 *)puVar6 = *(undefined1 *)local_4;
          local_4 = (undefined4 *)((int)local_4 + 1);
          puVar6 = (undefined4 *)((int)puVar6 + 1);
        }
        *puVar1 = uVar4;
        return 0;
      }
    }
  }
  *param_1 = 0;
  *puVar1 = 0;
  return 1;
}


