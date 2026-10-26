// Function: FUN_00462380 @ 00462380
// Size (bytes): 46


int __fastcall FUN_00462380(int *param_1)

{
  char cVar1;
  int extraout_EDX;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(*param_1 + 0x3e14)) {
    do {
      cVar1 = FUN_00461530(2);
      if (cVar1 != '\0') {
        iVar2 = iVar2 + 1;
      }
    } while (extraout_EDX != 1);
  }
  return iVar2;
}


