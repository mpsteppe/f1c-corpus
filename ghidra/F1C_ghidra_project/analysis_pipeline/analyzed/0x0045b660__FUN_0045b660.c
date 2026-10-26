// Function: FUN_0045b660 @ 0045b660
// Size (bytes): 474


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0045b660(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float10 fVar7;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  iVar6 = FUN_0045bb00();
  if ((iVar6 == 0) && (*(float *)(param_1 + 0x328) == DAT_0059e440)) {
    *(undefined4 *)(param_1 + 0x324) = 0;
    return;
  }
  fVar7 = (float10)FUN_0045b5c0();
  fVar2 = (float)(fVar7 + (float10)_DAT_0059e448);
  fVar3 = (float)iVar6 * _DAT_0059f078;
  if (*(float *)(param_1 + 0x324) != fVar2) {
    fVar4 = fVar2 - *(float *)(param_1 + 0x324);
    fVar5 = ABS(fVar4);
    if (fVar5 < (float)_DAT_0059f088 == (fVar5 == (float)_DAT_0059f088)) {
      *(float *)(param_1 + 0x324) = fVar4 * _DAT_0059e8c8 + *(float *)(param_1 + 0x324);
    }
    else {
      *(float *)(param_1 + 0x324) = fVar2;
    }
  }
  if (*(float *)(param_1 + 0x328) != fVar3) {
    fVar2 = fVar3 - *(float *)(param_1 + 0x328);
    fVar4 = ABS(fVar2);
    if (fVar4 < (float)_DAT_0059f088 == (fVar4 == (float)_DAT_0059f088)) {
      *(float *)(param_1 + 0x328) = fVar2 * _DAT_0059e8c8 + *(float *)(param_1 + 0x328);
    }
    else {
      *(float *)(param_1 + 0x328) = fVar3;
    }
  }
  FUN_004dcda0(*(undefined4 *)(param_1 + 0x324),*(undefined4 *)(param_1 + 0x328));
  FUN_004dcee0(0x3f000000,0,0x3f800000,2);
  FUN_004dcd60(0);
  FUN_004dcf30(&local_8,&local_4);
  FUN_004dcf50(&local_c,&local_10,0);
  iVar6 = local_c + local_8;
  iVar1 = local_10 + local_4;
  FUN_00494c20(local_c,local_10,local_c,iVar1,0xff999999,DAT_008b8dc8);
  FUN_00494c20(local_c,iVar1,iVar6,iVar1,0xff999999,DAT_008b8dc8);
  FUN_00494c20(iVar6,iVar1,iVar6,local_10,0xff999999,DAT_008b8dc8);
  FUN_00494c20(iVar6,local_10,local_c,local_10,0xff999999,DAT_008b8dc8);
  return;
}


