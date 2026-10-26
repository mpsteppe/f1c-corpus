// Function: FUN_00499da0 @ 00499da0
// Size (bytes): 79


void __thiscall FUN_00499da0(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    param_2 = (int *)(param_1 + 8);
  }
  iVar1 = *param_2;
  if (iVar1 != 0) {
    FUN_00499da0(iVar1 + 0x28);
    FUN_00499da0(iVar1 + 0x24);
    FUN_00499b50();
    FUN_00587bcf(iVar1);
  }
  *param_2 = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}


