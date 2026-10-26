int __thiscall sub_69BE8D(void *this, int a2, int a3)
{
  int *v3; // edi
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // ebx
  int v8; // eax
  _DWORD *v9; // edi
  _DWORD *v10; // eax
  int v11; // eax
  _DWORD *v12; // ecx
  _DWORD *v13; // esi
  int v14; // eax
  int v15; // edi
  int v17; // [esp+Ch] [ebp-14h]
  int v18; // [esp+10h] [ebp-10h] BYREF
  int v19; // [esp+14h] [ebp-Ch]
  unsigned int v20; // [esp+18h] [ebp-8h]
  int v21; // [esp+1Ch] [ebp-4h]

  v21 = (int)this;
  v18 = 0;
  v3 = &v18;
  if ( a3 )
  {
    while ( 1 )
    {
      if ( !*(_DWORD *)(a3 + 8) )
        return 0;
      v4 = (_DWORD *)sub_65B229(20);
      v5 = v4 ? sub_67ED1B(v4, 0, 0, (int)"Stmts") : 0;
      *v3 = (int)v5;
      if ( !v5 )
        return 0;
      v6 = (_DWORD *)sub_65B229(48);
      v7 = v6 ? sub_67F0EF(v6, 0, 0, 0, 0) : 0;
      if ( !v7 )
        return 0;
      *(_DWORD *)(*v3 + 8) = v7;
      v17 = *v3 + 12;
      v20 = 1;
      v19 = 0;
      if ( a2 )
      {
        v8 = sub_67ECC3(a2);
        v7[6] = v8;
        if ( !v8 )
          return 0;
      }
      v9 = *(_DWORD **)(a3 + 8);
      while ( v9[1] != 3 )
      {
        v10 = (_DWORD *)sub_65B229(24);
        if ( v10 )
          v11 = sub_67F23A(v10);
        else
          v11 = 0;
        if ( !v11 )
          return 0;
        *(_DWORD *)(v11 + 16) = v7[6];
        v7[6] = v11;
        v12 = (_DWORD *)v9[3];
        v13 = (_DWORD *)(v11 + 20);
        if ( v12 )
        {
          if ( sub_69BE34((_DWORD *)v21, v12, (_DWORD *)(v11 + 20)) >= 0 )
            goto LABEL_25;
          v19 = 3058;
        }
        else
        {
          v19 = 3072;
        }
        *v13 = 1;
LABEL_25:
        v9 = (_DWORD *)v9[2];
        v20 *= *v13;
      }
      v14 = sub_67ECC3((int)v9);
      v7[5] = v14;
      if ( !v14 )
        return 0;
      v15 = (int)(v9 + 4);
      if ( v19 == 3058 )
      {
        sub_694B97(v21, v15, 3058, "'%s': array dimensions must be literal scalar expressions", *(_DWORD *)(v15 + 8));
        return 0;
      }
      if ( v19 == 3072 )
      {
        sub_694B97(v21, v15, 3072, "'%s': array dimensions of type must be explicit", *(_DWORD *)(v15 + 8));
        return 0;
      }
      if ( !v20 || v20 > 0x10000 )
      {
        sub_694B97(v21, v15, 3059, "'%s': array dimension must be between 1 and 65536", *(_DWORD *)(v15 + 8));
        return 0;
      }
      if ( sub_6961D0((_DWORD *)v21, (int)v7, 1) < 0 )
        return 0;
      a3 = *(_DWORD *)(a3 + 12);
      if ( !a3 )
        return v18;
      v3 = (int *)v17;
    }
  }
  return 0;
}
