// positive sp value has been detected, the output may be wrong!
int __usercall sub_498D03@<eax>(int a1@<esi>)
{
  int result; // eax
  float v3; // [esp-28h] [ebp-28h]
  float v5; // [esp-1Ch] [ebp-1Ch]
  float v6; // [esp-18h] [ebp-18h]
  int v7; // [esp-14h] [ebp-14h]
  int v8; // [esp-10h] [ebp-10h]
  int v9; // [esp-Ch] [ebp-Ch]
  int v10; // [esp-8h] [ebp-8h]
  int v11; // [esp-4h] [ebp-4h]

  __asm
  {
    fadd    [esp+arg_8]
    fadd    [esp+arg_0]
    fstp    [esp+arg_0]
  }
  sub_5DB2B0(v9, v8, v7, v6, v3, v5);
  result = v10;
  dword_B6E078 = LODWORD(v3);
  *(_DWORD *)(a1 + 288) = v10;
  *(_DWORD *)(a1 + 292) = v11;
  return result;
}
