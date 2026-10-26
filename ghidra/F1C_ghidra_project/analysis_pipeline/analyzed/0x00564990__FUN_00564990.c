// Function: FUN_00564990 @ 00564990
// Size (bytes): 58


void __fastcall FUN_00564990(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < *param_1 + -1) {
    uVar1 = FUN_005648b0(((*param_1 - param_2) + -1) * param_1[2]);
    uVar1 = FUN_005648b0(uVar1);
    FUN_0058b130(uVar1);
  }
  *param_1 = *param_1 + -1;
  return;
}


