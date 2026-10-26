// Function: FUN_00461cd0 @ 00461cd0
// Size (bytes): 72


undefined4 __fastcall FUN_00461cd0(int *param_1)

{
  int iVar1;
  
  if (*(int *)(*param_1 + 0x3fc4) != 4) {
    return *(undefined4 *)(*param_1 + 0x3fc4);
  }
  iVar1 = FUN_0057a900();
  if (iVar1 == 3) {
    *(undefined4 *)(*param_1 + 0x3fc4) = 3;
    return *(undefined4 *)(*param_1 + 0x3fc4);
  }
  return *(undefined4 *)(*param_1 + 0x3fc4);
}


