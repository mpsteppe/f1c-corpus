int __thiscall sub_4FCB90(int this)
{
  int v2; // eax
  signed int i; // edi
  int result; // eax
  char v5; // [esp+0h] [ebp-8h]

  if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_21, 3664) )
    sub_500FE0((int)&unk_7D7920, aEnteredSteward_2, v5);
  sub_4FCC70(this);
  sub_414BB0((char *)this);
  v2 = *(_DWORD *)(this + 268);
  *(_DWORD *)(this + 264) = 0;
  if ( v2 )
  {
    sub_5BE8AE();
    *(_DWORD *)(this + 268) = 0;
  }
  if ( *(_DWORD *)(this + 272) )
  {
    sub_5BE8AE();
    *(_DWORD *)(this + 272) = 0;
  }
  if ( *(_DWORD *)dword_7689CC != 4 && (*(_DWORD *)dword_7689CC != 5 || !byte_766188) )
    sub_4E6000((int)&unk_76BB28);
  for ( i = 0; i < (int)NumOfElements; ++i )
    sub_4DC3F0(dword_75AAD0[i] + 20836);
  result = *(_DWORD *)(this + 268);
  if ( result )
  {
    result = sub_5BE8AE();
    *(_DWORD *)(this + 268) = 0;
  }
  return result;
}
