// Function: FUN_00463e20 @ 00463e20
// Strings:  [%s %.3f, F1 Challenge 99-02]


void __fastcall FUN_00463e20(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 local_20 [32];
  
  FUN_0057a3f0();
  FUN_0058815f(local_20,s__s___3f_005c6618,s_F1_Challenge_99_02_005c6620,0,0x3ff06a7f);
  cVar1 = FUN_0057aaf0();
  if (cVar1 != '\0') {
    *(undefined4 *)(*param_1 + 0x1d0) = 1;
    *(int *)(*param_1 + 0x3fc0) = *param_1;
    uVar2 = FUN_0057a880();
    *(undefined4 *)(*param_1 + 0x417c) = uVar2;
    FUN_0045d260();
    return;
  }
  *(undefined4 *)(*param_1 + 0x1d0) = 0;
  FUN_0045d260();
  return;
}


