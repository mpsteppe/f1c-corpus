// Function: FUN_00410980 @ 00410980
// Size (bytes): 73


void __thiscall FUN_00410980(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  
  FUN_004bdfe0();
  iVar2 = 0;
  if (0 < *param_1) {
    do {
      cVar1 = FUN_0040f1c0(param_2);
      if (cVar1 == '\0') {
        iVar2 = iVar2 + -1;
        FUN_0040f100();
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *param_1);
  }
  return;
}


