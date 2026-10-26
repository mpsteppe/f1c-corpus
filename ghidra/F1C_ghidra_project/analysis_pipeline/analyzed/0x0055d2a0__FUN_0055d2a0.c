// Function: FUN_0055d2a0 @ 0055d2a0
// Size (bytes): 54


undefined4 __thiscall FUN_0055d2a0(uint *param_1,char *param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  *param_1 = *param_1 | param_3;
  iVar2 = 0x58 - (int)param_2;
  do {
    cVar1 = *param_2;
    param_2[(int)param_1 + iVar2] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  uVar3 = FUN_00541500(param_3);
  param_1[1] = uVar3;
  return 0;
}


