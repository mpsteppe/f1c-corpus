// Function: FUN_0057a0f0 @ 0057a0f0
// Size (bytes): 55


void __thiscall FUN_0057a0f0(undefined1 *param_1,int param_2)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = 0x10;
  puVar1 = param_1;
  do {
    *puVar1 = puVar1[param_2 - (int)param_1];
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = param_1 + 0x10;
  do {
    *puVar1 = puVar1[param_2 - (int)param_1];
    puVar1 = puVar1 + 1;
  } while ((int)(puVar1 + (-0x10 - (int)param_1)) < 0x20);
  return;
}


