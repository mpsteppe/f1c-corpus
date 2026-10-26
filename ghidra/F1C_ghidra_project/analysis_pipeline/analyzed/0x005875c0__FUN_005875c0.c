// Function: FUN_005875c0 @ 005875c0
// Size (bytes): 89


uint __thiscall FUN_005875c0(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *local_4;
  
  local_4 = (undefined4 *)0x0;
  uVar2 = FUN_005874d0(param_1[1] + param_2,&local_4);
  puVar1 = local_4;
  if ((char)uVar2 != '\0') {
    uVar2 = param_1[2];
    puVar4 = (undefined4 *)*param_1;
    puVar5 = local_4;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    uVar2 = FUN_00587bcf(*param_1);
    *param_1 = puVar1;
  }
  return uVar2 & 0xffffff00;
}


