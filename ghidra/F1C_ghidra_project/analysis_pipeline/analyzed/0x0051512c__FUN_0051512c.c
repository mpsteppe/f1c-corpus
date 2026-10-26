// Function: FUN_0051512c @ 0051512c
// Size (bytes): 131


/* WARNING: Removing unreachable block (ram,0x00515165) */
/* WARNING: Removing unreachable block (ram,0x00515194) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0051512c(int param_1,uint *param_2)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = FUN_00514fee(param_1,param_2 + 2);
  fVar1 = _DAT_005ac108;
  if (-1 < iVar2) {
    uVar4 = *param_2;
    iVar2 = 8;
    pfVar3 = (float *)(param_1 + 0xc);
    do {
      uVar5 = uVar4 & 0xf;
      uVar4 = uVar4 >> 4;
      *pfVar3 = (float)uVar5 * fVar1;
      pfVar3 = pfVar3 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    uVar4 = param_2[1];
    iVar2 = 8;
    pfVar3 = (float *)(param_1 + 0x8c);
    do {
      uVar5 = uVar4 & 0xf;
      uVar4 = uVar4 >> 4;
      *pfVar3 = (float)uVar5 * fVar1;
      pfVar3 = pfVar3 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar2 = 0;
  }
  return iVar2;
}


