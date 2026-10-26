// Function: FUN_00565080 @ 00565080
// Size (bytes): 184


void __fastcall FUN_00565080(int param_1,uint param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int local_8;
  
  puVar1 = param_3;
  param_3[0x145] = 0;
  for (iVar2 = 0x100; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_3 = 0;
    param_3 = param_3 + 1;
  }
  param_3 = (undefined4 *)0x0;
  do {
    iVar2 = 0;
    do {
      puVar1[iVar2] = puVar1[iVar2] * 0x100 + iVar2;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x100);
    local_8 = 2;
    uVar5 = (uint)param_3;
    do {
      uVar3 = 0;
      do {
        iVar2 = puVar1[uVar3];
        uVar5 = (uint)*(byte *)(uVar3 % param_2 + param_1) + iVar2 + uVar5 & 0xff;
        uVar4 = uVar3 + 1;
        puVar1[uVar3] = puVar1[uVar5];
        puVar1[uVar5] = iVar2;
        uVar3 = uVar4;
      } while ((int)uVar4 < 0x100);
      local_8 = local_8 + -1;
    } while (local_8 != 0);
    param_3 = (undefined4 *)((int)param_3 + 1);
  } while ((int)param_3 < 4);
  uVar5 = 0;
  do {
    puVar1[uVar5] = puVar1[uVar5] ^ uVar5;
    uVar5 = uVar5 + 1;
  } while ((int)uVar5 < 0x100);
  FUN_00564dd0(0);
  return;
}


