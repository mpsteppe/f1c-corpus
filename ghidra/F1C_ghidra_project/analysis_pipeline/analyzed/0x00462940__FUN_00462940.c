// Function: FUN_00462940 @ 00462940
// Size (bytes): 177


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char __thiscall FUN_00462940(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  uint local_1b0 [2];
  undefined4 local_1a8;
  
  cVar3 = '\0';
  if ((*(int *)(*param_1 + 0x3fc4) == 2) || (*(int *)(*param_1 + 0x3fc4) == 1)) {
    local_1a8 = param_2;
    FUN_004b33b0(4,0x20,4,0xff,(float)_DAT_008afea0,1);
    iVar1 = FUN_0057a680();
    *(undefined1 *)(iVar1 + 4) = 1;
    iVar2 = FUN_0057a6a0(local_1b0,(local_1b0[0] >> 8 & 0x3ff) + 8,iVar1,1,1,0xffffffff,0);
    cVar3 = '\x01' - (iVar2 != 0);
    FUN_0057a690(iVar1);
  }
  return cVar3;
}


