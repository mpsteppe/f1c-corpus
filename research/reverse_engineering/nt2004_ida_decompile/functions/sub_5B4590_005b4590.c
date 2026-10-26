int *__thiscall sub_5B4590(_DWORD **this, int a2)
{
  int *v2; // edx
  int *v3; // ecx
  int v5; // [esp+0h] [ebp-8h] BYREF
  int v6; // [esp+4h] [ebp-4h] BYREF

  sub_5B43F0(&v5, this[2156], 0);
  sub_5B41C0(v5, &v5, &v6);
  if ( a2 != 0x200000 )
    return (int *)-1;
  if ( v5 == 32 )
    return sub_5B4570(v3);
  if ( v5 == 16 )
    return sub_5B4550(v2);
  else
    return (int *)-1;
}
