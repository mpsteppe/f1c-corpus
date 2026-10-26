_DWORD *__thiscall sub_699F10(int *this, int a2, _DWORD *a3, int a4, int a5)
{
  int *v5; // edi
  _DWORD *v7; // ebx
  _DWORD *v8; // eax
  _DWORD *v9; // esi
  int v10; // eax
  int v11; // eax
  int i; // edi
  int v13; // eax
  int v14; // edi
  int v15; // ebx
  int v16; // eax
  int v18; // [esp-8h] [ebp-1Ch]
  char *v19; // [esp-4h] [ebp-18h]
  int v20; // [esp+Ch] [ebp-8h] BYREF
  int v21; // [esp+10h] [ebp-4h]
  const void *v22; // [esp+1Ch] [ebp+8h]
  int v23; // [esp+20h] [ebp+Ch]
  int v24; // [esp+20h] [ebp+Ch]

  v5 = (int *)a2;
  v21 = (int)this;
  v20 = 0;
  if ( a2 && *(_DWORD *)(a2 + 4) == 3 )
  {
    sub_69974C(this, 0, (const char **)(a2 + 16), 0, 0, this[4], 1, &v20, 0);
    v5 = (int *)v20;
  }
  v22 = this + 8;
  if ( a4 )
  {
    if ( !v5 || v5[1] != 9 || !sub_695154(this, v5) )
    {
      sub_694B97((int)this, (int)v22, 3037, "constructors only defined for numeric base types");
      return 0;
    }
    v7 = a3;
    if ( a3 && a3[1] != 1 )
      return 0;
    v23 = sub_6950BD(this, v5);
  }
  else
  {
    v20 = 0;
    v7 = a3;
    if ( a3 )
    {
      if ( a3[1] != 13 )
        return 0;
      v20 = a3[4];
      v22 = a3 + 12;
    }
    if ( !sub_696CB7(this, v5, (int *)v20, a5) )
    {
      sub_696FEF(this, (int)v22, 0, v5, (int *)v20, a5);
      return 0;
    }
    v23 = sub_6950BD(this, v5) || sub_6950BD(this, (_DWORD *)v20);
  }
  v24 = sub_695A44(v7) | v23;
  v8 = (_DWORD *)sub_65B229(80);
  v9 = 0;
  if ( v8 )
    v9 = sub_67F5FE(v8, 0, 0, 0, 0, 1, v22);
  if ( v9 )
  {
    if ( !v5 || (v10 = (*(int (__thiscall **)(int *))(*v5 + 4))(v5), (v9[4] = v10) != 0) )
    {
      if ( !v7 || (v11 = (*(int (__thiscall **)(_DWORD *))(*v7 + 4))(v7), (v9[8] = v11) != 0) )
      {
        if ( a4 )
        {
          for ( i = v9[8]; i; i = *(_DWORD *)(i + 12) )
          {
            v13 = *(_DWORD *)(i + 8);
            if ( v13 && *(_DWORD *)(v13 + 4) == 13 )
            {
              if ( !sub_695154((_DWORD *)v21, *(_DWORD **)(v13 + 16)) )
              {
                v19 = "cannot convert from 'object type' to 'numeric type'";
                v18 = 3017;
                goto LABEL_49;
              }
              if ( !v24 )
                v24 = sub_6950BD((_DWORD *)v21, *(_DWORD **)(*(_DWORD *)(i + 8) + 16));
            }
          }
        }
        if ( v24 )
          sub_694F9B((_DWORD *)v21, v9[4], 1);
        if ( !a4 )
          goto LABEL_51;
        v14 = v9[8];
        v15 = 0;
        while ( v14 )
        {
          v16 = *(_DWORD *)(v14 + 8);
          if ( v16 && *(_DWORD *)(v16 + 4) == 13 )
            v15 += sub_6951CB((_DWORD *)v21, *(_DWORD **)(v16 + 16));
          v14 = *(_DWORD *)(v14 + 12);
        }
        if ( v15 == sub_6951CB((_DWORD *)v21, (_DWORD *)v9[4]) )
        {
LABEL_51:
          sub_695BDE((_DWORD *)v21, v9);
          return v9;
        }
        v19 = "incorrect number of arguments to numeric-type constructor";
        v18 = 3014;
LABEL_49:
        sub_694B97(v21, (int)v22, v18, v19);
      }
    }
  }
  return 0;
}
