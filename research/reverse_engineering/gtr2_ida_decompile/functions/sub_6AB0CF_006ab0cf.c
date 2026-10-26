int __thiscall sub_6AB0CF(_DWORD *this, int a2, unsigned int *a3, int *a4)
{
  int v4; // eax
  unsigned int v5; // edx
  int v6; // esi
  bool v7; // cf

  v4 = *(_DWORD *)(a2 + 108);
  v5 = *(unsigned __int8 *)(a2 + 109);
  *a3 = v5;
  v6 = 1;
  if ( (unsigned __int8)v4 == 1 )
  {
    v7 = v5 < this[10];
  }
  else
  {
    v6 = 3;
    if ( (unsigned __int8)v4 != 3 )
      return -2147467259;
    v7 = v5 < this[15];
  }
  if ( v7 )
  {
    *a4 = v6;
    return 0;
  }
  return -2147467259;
}
