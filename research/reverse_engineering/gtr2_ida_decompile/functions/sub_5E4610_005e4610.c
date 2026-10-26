void __thiscall sub_5E4610(_DWORD *this, int a2, int a3)
{
  _DWORD *v4; // ebp
  int v5; // esi
  int v6; // eax
  int k; // edi
  int *v8; // eax
  int i; // ecx
  int v10; // edx
  int j; // [esp+18h] [ebp+4h]

  if ( a2 )
  {
    sub_5E9030(a2);
    v8 = (int *)this[91];
    for ( i = 0; i < this[90]; ++i )
    {
      if ( v8[1] == a2 )
      {
        v10 = *v8 | 0x200000;
        v8[23] = 0;
        *v8 = v10;
      }
      v8 += 27;
    }
  }
  else
  {
    v4 = (_DWORD *)this[91];
    for ( j = 0; j < this[90]; ++j )
    {
      v5 = a3 + sub_5E8220(99);
      v6 = sub_5E82A0(99);
      for ( k = v5 + v6; v5 < k; ++v5 )
      {
        if ( *(int *)(sub_5E80D0(v5) + 4) > 1 )
          *v4 |= 0x200000u;
      }
      v4 += 27;
    }
  }
}
