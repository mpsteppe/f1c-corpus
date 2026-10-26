// Function: FUN_004b5e30 @ 004b5e30
// Size (bytes): 25


int __fastcall FUN_004b5e30(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = 0;
  piVar2 = (int *)(param_1 + 0x4c);
  iVar3 = 0x68;
  do {
    iVar1 = iVar1 + *piVar2;
    piVar2 = piVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return iVar1;
}


