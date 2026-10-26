// Function: FUN_004d38f0
// Address:  004d38f0
// Trigger:  "Entered Steward"


void __fastcall FUN_004d38f0(int param_1)

{
  int iVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  int extraout_EDX;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  cVar3 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_stewa_005d3b6c,0x929);
  if (cVar3 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Entered_Steward__Init___005d42f4);
  }
  FUN_004d0e20(s_STLITE_005d42e4,s_STGLOW_005d42ec);
  FUN_004d0e20(s_PTLIT02_005d42d0,s_PTGLOW02_005d42d8);
  FUN_004d0e20(s_PTLIT01_005d42bc,s_PTGLOW01_005d42c4);
  *(undefined4 *)(param_1 + 0x100) = 0;
  if (*(int *)(param_1 + 0xf8) != 0) {
    FUN_0054b950(local_c,local_8,local_4);
    iVar4 = FUN_004038e0(local_c,0);
    if (iVar4 != 0) {
      *(undefined4 *)(param_1 + 0x100) = *(undefined4 *)(iVar4 + 0x48);
    }
  }
  iVar4 = __ftol();
  *(int *)(param_1 + 0x10c) = iVar4;
  pvVar5 = operator_new(iVar4 * 8);
  *(void **)(param_1 + 0x110) = pvVar5;
  pvVar5 = operator_new(*(int *)(param_1 + 0x10c) << 2);
  *(void **)(param_1 + 0x114) = pvVar5;
  fVar2 = DAT_005ea3fc / (float)*(int *)(param_1 + 0x10c);
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x10c)) {
    do {
      iVar1 = iVar4 + 1;
      *(float *)(*(int *)(param_1 + 0x110) + 4 + iVar4 * 8) = (float)iVar1 * fVar2;
      FUN_004d0f00(0);
      *(undefined4 *)(*(int *)(param_1 + 0x114) + extraout_EDX * 4) = 0;
      iVar4 = iVar1;
    } while (iVar1 < *(int *)(param_1 + 0x10c));
  }
  *(float *)(*(int *)(param_1 + 0x110) + -4 + *(int *)(param_1 + 0x10c) * 8) = DAT_005ea3fc;
  if (DAT_005ea3fc <= DAT_0059e440) {
    *(undefined4 *)(param_1 + 0x108) = 0;
  }
  else {
    *(float *)(param_1 + 0x108) = (float)*(int *)(param_1 + 0x10c) / DAT_005ea3fc;
  }
  iVar4 = FUN_005453a0(s_XPITIN_005d42b4,0);
  *(int *)(param_1 + 0x194) = iVar4;
  if (iVar4 == 0) {
    cVar3 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_stewa_005d3b6c,0x96d);
    if (cVar3 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_No_pit_in_poly_found_005d429c);
    }
  }
  else {
    FUN_0054c110(0xfffffff5,0x800);
  }
  iVar4 = FUN_005453a0(s_XPITOUT_005d4294,0);
  *(int *)(param_1 + 0x198) = iVar4;
  if (iVar4 == 0) {
    cVar3 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_stewa_005d3b6c,0x973);
    if (cVar3 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_No_pit_out_poly_found_005d427c);
    }
  }
  else {
    FUN_0054c110(0xffffffe7,0x800);
  }
  iVar4 = FUN_005453a0(s_XFINISH_005d4274,0);
  *(int *)(param_1 + 0x19c) = iVar4;
  if (iVar4 == 0) {
    cVar3 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_stewa_005d3b6c,0x979);
    if (cVar3 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_No_finish_poly_found_005d425c);
    }
  }
  else {
    FUN_0054c110(0,0x800);
  }
  iVar4 = FUN_005453a0(s_XSECTOR1_005d4250,0);
  *(int *)(param_1 + 0x1a0) = iVar4;
  if (iVar4 == 0) {
    cVar3 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_stewa_005d3b6c,0x97f);
    if (cVar3 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_No_sector_1_poly_found_005d4238);
    }
  }
  else {
    FUN_0054c110(1,0x800);
  }
  iVar4 = FUN_005453a0(s_XSECTOR2_005d422c,0);
  *(int *)(param_1 + 0x1a4) = iVar4;
  if (iVar4 == 0) {
    cVar3 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_stewa_005d3b6c,0x985);
    if (cVar3 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_No_sector_2_poly_found_005d4214);
    }
  }
  else {
    FUN_0054c110(2,0x800);
  }
  switch(DAT_007d0410) {
  case 1:
    uVar6 = 0;
    break;
  case 2:
    uVar6 = 7;
    break;
  case 3:
  case 5:
    uVar6 = 1;
    break;
  default:
    goto switchD_004d3c62_caseD_4;
  }
  FUN_0042cf10(uVar6);
switchD_004d3c62_caseD_4:
  iVar4 = FUN_005453a0(s_HELICOPTER_005d4208,0);
  if (iVar4 != 0) {
    pvVar5 = operator_new(0x1c);
    if (pvVar5 != (void *)0x0) {
      uVar6 = FUN_00448120();
      *(undefined4 *)(param_1 + 0xa8) = uVar6;
      FUN_00448140(iVar4);
      return;
    }
    *(undefined4 *)(param_1 + 0xa8) = 0;
    FUN_00448140(iVar4);
  }
  return;
}


