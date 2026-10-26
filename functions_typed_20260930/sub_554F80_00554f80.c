int __thiscall sub_554F80(int this, _DWORD *a2, int a3)
{
  _DWORD *v3; // esi
  int v5; // eax
  _DWORD *v6; // edx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  unsigned int v11; // eax
  int v12; // ecx
  int v13; // eax

  v3 = *(_DWORD **)(a3 + 84);
  if ( (v3[6] & 0x400) == 0 )
  {
    v5 = sub_554E90((int *)this, a3);
    *(_DWORD *)this = v5;
    if ( v5 == -1 )
    {
      if ( a2 && (v6 = *(_DWORD **)(ValueGetter(a2) + 40)) != 0 )
      {
        while ( 1 )
        {
          v7 = v6[21];
          v8 = *(_DWORD *)(v7 + 24);
          if ( (v8 & 0x80000) == 0
            && (v8 & 0x400) != 0
            && *(float *)(v7 + 56) > 0.0
            && v6[20] == *(_DWORD *)(a3 + 80)
            && *(_DWORD *)(v7 + 48) == v3[12]
            && *(_DWORD *)(v7 + 28) == v3[7]
            && *(_DWORD *)(v7 + 32) == v3[8] )
          {
            break;
          }
          v6 = (_DWORD *)v6[23];
          if ( !v6 )
            goto LABEL_13;
        }
        v3[6] |= 8u;
        v3[5] = *(_DWORD *)(v7 + 20);
        v11 = *(_DWORD *)(v7 + 24) & 0xFFFFFBF7;
        *(_DWORD *)(v7 + 20) = 0;
        *(_DWORD *)(v7 + 56) = -1082130432;
        *(_DWORD *)(v7 + 24) = v11;
      }
      else
      {
LABEL_13:
        if ( StructFieldGetter(this) )
          return 0;
        D3DResourceListCleanup(this, (int)a2);
        v9 = sub_554E90((int *)this, a3);
        *(_DWORD *)this = v9;
        if ( v9 )
          return 0;
      }
    }
    v12 = v3[4];
    if ( v12 )
    {
      v13 = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**(_DWORD **)(this + 4352) + 116))(
              *(_DWORD *)(this + 4352),
              v12,
              v3[5]);
      *(_DWORD *)this = v13;
      if ( v13 )
        return 0;
      v3[6] |= 0x400u;
    }
  }
  v3[14] = 0;
  return 1;
}

