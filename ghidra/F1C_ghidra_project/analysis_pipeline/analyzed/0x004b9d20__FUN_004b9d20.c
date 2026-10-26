// Function: FUN_004b9d20 @ 004b9d20
// Size (bytes): 95


undefined4 __fastcall FUN_004b9d20(int *param_1)

{
  int iVar1;
  undefined2 extraout_var;
  int extraout_ECX;
  undefined1 extraout_DL;
  float10 fVar2;
  float10 fVar3;
  
  fVar2 = (float10)FUN_004b8790();
  fVar3 = (float10)*(float *)(extraout_ECX + 0xf3c);
  if ((fVar3 == fVar2) && (*(char *)(extraout_ECX + 0xf80) == '\0')) {
    return CONCAT31((int3)(CONCAT22(extraout_var,
                                    (ushort)(fVar3 < fVar2) << 8 |
                                    (ushort)(NAN(fVar3) || NAN(fVar2)) << 10 |
                                    (ushort)(fVar3 == fVar2) << 0xe) >> 8),extraout_DL);
  }
  FUN_004b8da0();
  fVar2 = (float10)FUN_004b9ce0();
  FUN_004b9000((float)fVar2);
  fVar2 = (float10)FUN_004b8790();
  FUN_004b9b80((float)fVar2);
  iVar1 = *param_1;
  *(undefined1 *)(iVar1 + 0xf80) = 0;
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


