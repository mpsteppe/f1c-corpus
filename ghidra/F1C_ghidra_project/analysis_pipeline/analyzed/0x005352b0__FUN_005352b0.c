// Function: FUN_005352b0 @ 005352b0
// Size (bytes): 27


void __fastcall FUN_005352b0(undefined4 param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = 0xffffffff;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *param_2;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  FUN_00535220(~uVar2 - 1);
  return;
}


