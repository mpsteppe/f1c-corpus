// Function: FUN_004b3c60 @ 004b3c60
// Size (bytes): 124


int __fastcall FUN_004b3c60(uint *param_1)

{
  uint uVar1;
  DWORD DVar2;
  int iVar3;
  int iVar4;
  int local_c;
  uint local_8;
  undefined1 local_4 [4];
  
  FUN_0055687b(local_4,&local_c);
  uVar1 = (param_1[0x201] + 2) * 0x35abd;
  local_c = local_c + uVar1;
  param_1[0x201] = uVar1;
  local_8 = param_1[(*param_1 & 0xff) + 1];
  *param_1 = *param_1 + 1;
  DVar2 = GetTickCount();
  iVar3 = __ftol();
  iVar4 = _rand();
  return local_c + (DVar2 - iVar3) * (iVar4 * 2 + 1);
}


