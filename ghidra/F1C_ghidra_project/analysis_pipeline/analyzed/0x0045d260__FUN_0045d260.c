// Function: FUN_0045d260 @ 0045d260
// Size (bytes): 109


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0045d260(undefined1 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  *(uint *)(param_1 + 4) = (uint)DAT_007d0fe8;
  *(uint *)(param_1 + 8) = (uint)DAT_007d0fe8;
  *param_1 = 0;
  _DAT_008d4680 = 0;
  _DAT_008d4684 = 0;
  _DAT_008d4688 = 0;
  _DAT_008d468c = 0;
  iVar1 = 0;
  do {
    (&DAT_008d4680)[iVar1] = (&DAT_0059f0c4)[iVar1] ^ 0x3e;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  uVar2 = FUN_00562b50(&DAT_008d4680,8,&LAB_0045d2d0,1,0);
  *(undefined4 *)(param_1 + 0xc) = uVar2;
  return;
}


