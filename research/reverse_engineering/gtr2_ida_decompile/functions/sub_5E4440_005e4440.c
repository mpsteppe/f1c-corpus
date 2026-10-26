void __thiscall sub_5E4440(_DWORD *this, int a2, int a3)
{
  int *v4; // ebp
  int v5; // esi
  int v6; // eax
  int k; // edi
  int v8; // eax
  int *v9; // eax
  int i; // ecx
  int v11; // edx
  int j; // [esp+18h] [ebp+4h]

  if ( a2 )
  {
    sub_5E9030(a2);
    v9 = (int *)this[91];
    for ( i = 0; i < this[90]; ++i )
    {
      if ( v9[1] == a2 )
      {
        v11 = *v9 | 0x100000;
        v9[23] = 0;
        *v9 = v11;
      }
      v9 += 27;
    }
  }
  else
  {
    v4 = (int *)this[91];
    for ( j = 0; j < this[90]; ++j )
    {
      v5 = a3 + sub_5E8220(99);
      v6 = sub_5E82A0(99);
      for ( k = v5 + v6; v5 < k; ++v5 )
      {
        if ( *(int *)(sub_5E80D0(v5) + 4) > 1 )
        {
          v8 = *v4 | 0x100000;
          v4[23] = 0;
          *v4 = v8;
        }
      }
      v4 += 27;
    }
  }
}
