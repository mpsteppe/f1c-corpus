// Function: FUN_00517f72 @ 00517f72
// Size (bytes): 94


bool FUN_00517f72(int param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar1 = param_1;
  bVar3 = true;
  if ((*(byte *)(param_1 + 0x10c) & 0x20) == 0) {
    if ((*(byte *)(param_1 + 0x5d) & 8) == 0) goto LAB_00517f9e;
  }
  else if ((*(uint *)(param_1 + 0x5c) & 0x300) != 0x300) goto LAB_00517f9e;
  bVar3 = false;
LAB_00517f9e:
  FUN_00513bd1(param_1,&param_1,4);
  if (bVar3) {
    iVar2 = FUN_00517f35(&param_1);
    bVar3 = iVar2 != *(int *)(iVar1 + 0x100);
  }
  else {
    bVar3 = false;
  }
  return bVar3;
}


