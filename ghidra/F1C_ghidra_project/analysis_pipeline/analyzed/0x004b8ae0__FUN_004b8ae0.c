// Function: FUN_004b8ae0 @ 004b8ae0
// Size (bytes): 228


undefined1 __thiscall FUN_004b8ae0(int param_1,undefined4 *param_2)

{
  float fVar1;
  char cVar2;
  float10 fVar3;
  
  fVar1 = *(float *)(param_1 + 0xf34) - *(float *)(param_1 + 0xf30);
  if (fVar1 < DAT_0059e440 != (fVar1 == DAT_0059e440)) {
    return 0;
  }
  FUN_004b8c40(*param_2,0);
  FUN_004ba180();
  FUN_004cfcc0();
  FUN_00404460();
  FUN_004d4580();
  FUN_00455e50();
  FUN_0042c690();
  FUN_0040ca30();
  FUN_004c8b70();
  FUN_004b40a0();
  FUN_0049f070();
  FUN_004fa7e0();
  FUN_004a1830();
  if (((DAT_007cc4c8 == 0) && (cVar2 = FUN_0044f460(1), cVar2 == '\0')) &&
     (fVar3 = (float10)FUN_004b8790(), fVar3 < (float10)*(float *)(param_1 + 0xf34))) {
    return 1;
  }
  return 0;
}


