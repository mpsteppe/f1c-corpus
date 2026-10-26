int __userpurge sub_51056C@<eax>(int a1@<eax>, char a2@<cl>, int a3@<esi>, int a4, char *a5, int a6)
{
  unsigned int v6; // kr00_4
  __int32 v7; // eax
  unsigned int v9; // [esp+8h] [ebp-10h]
  __int32 v10; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int v11; // [esp+10h] [ebp-8h] BYREF
  int v12; // [esp+14h] [ebp-4h]

  *(_BYTE *)(a3 - 117) ^= a2;
  if ( a1 )
  {
    v12 = a1;
    v6 = __readeflags();
    v11 = v6;
    v7 = sub_FF8DD0(&byte_16C5803, &v11);
    __writeeflags(v9);
    _InterlockedExchange(&v10, v7);
    return sub_5DAC60(a4, a5);
  }
  else if ( dword_B640C0 == 5 )
  {
    return sub_5DAC60(a4, a5);
  }
  else
  {
    v12 = 695;
    return sub_5612D0((int)byte_FAE910, a4, a5, a6);
  }
}
