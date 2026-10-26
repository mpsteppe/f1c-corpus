// Function: FUN_004ebc60 @ 004ebc60
// Size (bytes): 957


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004ebc60(int param_1,int param_2,char param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 local_3c;
  float local_38;
  float local_34;
  float local_24;
  float local_20;
  float local_1c;
  double local_18;
  double local_10;
  double local_8;
  
  pfVar6 = (float *)FUN_004ea930();
  fVar1 = *pfVar6;
  fVar2 = pfVar6[1];
  fVar3 = pfVar6[2];
  pfVar6 = (float *)(param_2 + 0x20);
  fVar4 = fVar1 * *(float *)(param_1 + 0x34b0) +
          fVar2 * *(float *)(param_1 + 0x34bc) + fVar3 * *(float *)(param_1 + 0x34c8);
  fVar5 = fVar1 * *(float *)(param_1 + 0x34b4) +
          fVar2 * *(float *)(param_1 + 0x34c0) + fVar3 * *(float *)(param_1 + 0x34cc);
  fVar2 = fVar1 * *(float *)(param_1 + 0x34b8) +
          fVar2 * *(float *)(param_1 + 0x34c4) + fVar3 * *(float *)(param_1 + 0x34d0);
  local_1c = *(float *)(param_2 + 4);
  local_24 = local_1c *
             (*pfVar6 * *(float *)(param_1 + 0x34b0) +
             *(float *)(param_1 + 0x34bc) * *(float *)(param_2 + 0x24) +
             *(float *)(param_1 + 0x34c8) * *(float *)(param_2 + 0x28));
  local_20 = (*(float *)(param_1 + 0x34c0) * *(float *)(param_2 + 0x24) +
             *(float *)(param_1 + 0x34cc) * *(float *)(param_2 + 0x28) +
             *(float *)(param_1 + 0x34b4) * *pfVar6) * local_1c;
  local_1c = (*(float *)(param_1 + 0x34c4) * *(float *)(param_2 + 0x24) +
             *(float *)(param_1 + 0x34d0) * *(float *)(param_2 + 0x28) +
             *(float *)(param_1 + 0x34b8) * *pfVar6) * local_1c;
  fVar1 = *(float *)(param_1 + 0x3518);
  local_38 = local_20 * fVar1;
  *(float *)(param_1 + 0x34f8) = local_24 * fVar1 + *(float *)(param_1 + 0x34f8);
  *(float *)(param_1 + 0x34fc) = local_38 + *(float *)(param_1 + 0x34fc);
  *(float *)(param_1 + 0x3500) = local_1c * fVar1 + *(float *)(param_1 + 0x3500);
  *(float *)(param_1 + 0x34ec) =
       *(float *)(param_1 + 0x34b0) * *(float *)(param_1 + 0x34f8) +
       *(float *)(param_1 + 0x34b4) * *(float *)(param_1 + 0x34fc) +
       *(float *)(param_1 + 0x34b8) * *(float *)(param_1 + 0x3500);
  *(float *)(param_1 + 0x34f0) =
       *(float *)(param_1 + 0x34bc) * *(float *)(param_1 + 0x34f8) +
       *(float *)(param_1 + 0x34c0) * *(float *)(param_1 + 0x34fc) +
       *(float *)(param_1 + 0x34c4) * *(float *)(param_1 + 0x3500);
  *(float *)(param_1 + 0x34f4) =
       *(float *)(param_1 + 0x34c8) * *(float *)(param_1 + 0x34f8) +
       *(float *)(param_1 + 0x34cc) * *(float *)(param_1 + 0x34fc) +
       *(float *)(param_1 + 0x34d0) * *(float *)(param_1 + 0x3500);
  local_34 = local_20 * fVar4 - fVar5 * local_24;
  *(float *)(param_1 + 0x3504) =
       (fVar5 * local_1c - fVar2 * local_20) * *(float *)(param_1 + 0x3528) +
       *(float *)(param_1 + 0x3504);
  *(float *)(param_1 + 0x3508) =
       (fVar2 * local_24 - local_1c * fVar4) * *(float *)(param_1 + 0x352c) +
       *(float *)(param_1 + 0x3508);
  *(float *)(param_1 + 0x350c) =
       local_34 * *(float *)(param_1 + 0x3530) + *(float *)(param_1 + 0x350c);
  if (*(int *)(param_1 + 0x32bc) == 0) {
    local_18 = (double)*(float *)(param_2 + 0x14);
    local_10 = (double)*(float *)(param_2 + 0x18);
    local_8 = (double)*(float *)(param_2 + 0x1c);
    fVar1 = *(float *)(param_2 + 4) * _DAT_0059e86c;
    FUN_004ec050((double)(fVar1 * *pfVar6),(double)(fVar1 * *(float *)(param_2 + 0x24)),
                 (double)(fVar1 * *(float *)(param_2 + 0x28)));
    FUN_0043e5d0(&local_18,&local_3c);
  }
  iVar7 = *(int *)(param_1 + 0x32bc);
  if (-1 < iVar7) {
    if (iVar7 < 2) {
      if (param_3 != '\0') {
        FUN_004ec1a0();
      }
    }
    else if (iVar7 == 2) {
      iVar7 = FUN_00463dc0();
      if (iVar7 != 0) {
        FUN_004b2580();
        puVar8 = (undefined4 *)
                 FUN_0045eb00(&local_18,*(float *)(param_2 + 4) * *(float *)(param_1 + 0x3518));
        local_3c = *puVar8;
        local_38 = (float)puVar8[1];
        local_34 = (float)puVar8[2];
        FUN_004ec020();
        FUN_004b2480();
        return;
      }
    }
  }
  return;
}


