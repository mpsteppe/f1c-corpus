// Function: FUN_00545340 @ 00545340
// Size (bytes): 81


void __thiscall FUN_00545340(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x100);
  iVar3 = 0;
  do {
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x108);
      for (; (iVar1 != 0 && (param_2 != iVar3)); iVar3 = iVar3 + 1) {
        iVar1 = *(int *)(iVar1 + 0x4c);
      }
      return;
    }
    for (iVar2 = *(int *)(iVar1 + 0xec); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x4c)) {
      if (param_2 == iVar3) {
        return;
      }
      iVar3 = iVar3 + 1;
    }
    iVar1 = *(int *)(iVar1 + 0x104);
  } while( true );
}


