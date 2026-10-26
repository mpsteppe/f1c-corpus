// Function: FUN_004b9a10 @ 004b9a10
// Size (bytes): 161


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_004b9a10(int *param_1)

{
  int iVar1;
  float10 fVar2;
  float local_c;
  float local_8;
  float local_4;
  
  iVar1 = *param_1;
  local_c = 0.0;
  local_4 = 0.0;
  FUN_004b87a0(&local_c,&local_4);
  if (*(char *)(iVar1 + 0xf81) == '\0') {
    local_4 = local_4 - local_c;
    local_8 = local_c;
  }
  else {
    local_8 = (float)_DAT_008afea0 - *(float *)(iVar1 + 0xf84);
    if (local_8 < local_c) {
      local_8 = local_c;
    }
    local_4 = (float)_DAT_008afea0 - local_8;
  }
  if (DAT_0059e440 < local_4) {
    fVar2 = (float10)FUN_004b9ce0();
    return (fVar2 - (float10)local_8) / (float10)local_4;
  }
  return (float10)DAT_0059e440;
}


