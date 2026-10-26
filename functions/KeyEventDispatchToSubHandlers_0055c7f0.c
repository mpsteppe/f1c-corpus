int *__thiscall sub_55C7F0(_DWORD **this, int a2)
{
  int *v2; // ecx
  int v4; // [esp+0h] [ebp-8h] BYREF
  int v5; // [esp+4h] [ebp-4h] BYREF

  sub_55C650(&v4, this[1361], 0);
  sub_55C450(v4, &v4, &v5);
  if ( a2 != 0x200000 )
    return (int *)-1;
  if ( v4 == 32 )
    return InputStateQueryWrapper(v2);
  if ( v4 == 16 )
    return sub_55C7B0(v2);
  else
    return (int *)-1;
}
