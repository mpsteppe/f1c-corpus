// Function: FUN_00565ed0 @ 00565ed0
// Size (bytes): 22


int __fastcall FUN_00565ed0(int *param_1)

{
  int iVar1;
  
  if ((*(int **)(*param_1 + 8) != (int *)0x0) && (iVar1 = **(int **)(*param_1 + 8), iVar1 != 0)) {
    return iVar1 + 4;
  }
  return 0;
}


