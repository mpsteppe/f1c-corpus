// Function: FUN_004bc390 @ 004bc390
// Size (bytes): 323


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004bc390(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  float10 fVar5;
  float local_8;
  
  iVar2 = param_2;
  if ((float)_DAT_0059eb48 < (float)param_1[0x2c]) {
    return;
  }
  FUN_0054c150(&param_2,0x800);
  if (param_2 == 0) {
    bVar4 = param_1[3] == 2;
  }
  else if (param_2 == 1) {
    bVar4 = param_1[3] == 0;
  }
  else {
    if (param_2 != 2) goto LAB_004bc3ef;
    bVar4 = param_1[3] == 1;
  }
  if (!bVar4) {
    return;
  }
LAB_004bc3ef:
  cVar3 = FUN_004bc340();
  if (cVar3 != '\0') {
    fVar5 = (float10)FUN_004efbd0(iVar2);
    fVar1 = (float)fVar5;
    if (param_1[0x18] == 2) {
      local_8 = fVar1 - (float)param_1[0x19];
    }
    else {
      local_8 = -1.0;
    }
    if ((*(int *)(*param_1 + 13000) == 0) && (DAT_008ad238 != 0)) {
      FUN_004d5900(param_2,fVar1);
    }
    iVar2 = DAT_008aae64;
    if (DAT_0083ee60 < 0x3ff) {
      DAT_0083ee60 = DAT_0083ee60 + 1;
      DAT_008aae64 = DAT_008aae64 + 0x1b0;
    }
    FUN_004b33b0(4,8,8,param_1[1],fVar1,param_2 == 0);
    *(float *)(iVar2 + 8) = local_8;
    *(undefined2 *)(iVar2 + 0xc) = (undefined2)param_2;
    *(short *)(iVar2 + 0xe) = (short)param_1[2];
    FUN_004bc4e0(local_8,fVar1,param_2,param_1[2]);
  }
  return;
}


