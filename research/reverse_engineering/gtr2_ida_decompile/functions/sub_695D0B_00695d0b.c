_DWORD *__thiscall sub_695D0B(_DWORD *this, int a2, int a3, int a4, int a5)
{
  _DWORD *result; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // esi
  int v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  _DWORD *v12; // eax
  _DWORD *v13; // eax

  if ( a3 && (*(_DWORD *)(a3 + 20) * *(_DWORD *)(a3 + 24) != 1 || !sub_695154(this, *(_DWORD **)(a3 + 16))) )
  {
    sub_694B97((int)this, a3 + 48, 3019, "float expected");
    return 0;
  }
  v6 = (_DWORD *)sub_65B229(36);
  if ( v6 )
    v7 = sub_67F53B(v6);
  else
    v7 = 0;
  if ( !v7 )
    return 0;
  v8 = a2;
  v7[4] = 3;
  if ( !a4 )
  {
    if ( !a2 )
    {
      v7[4] = 4;
      goto LABEL_17;
    }
    if ( a2 == a5 )
    {
      v7[4] = 5;
      v8 = 0;
    }
  }
  if ( v8 )
  {
    v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 4))(v8);
    v7[5] = v9;
    if ( !v9 )
      return 0;
  }
LABEL_17:
  if ( a3 )
  {
    v10 = (*(int (__thiscall **)(int))(*(_DWORD *)a3 + 4))(a3);
    v7[6] = v10;
    if ( !v10 )
      return 0;
  }
  if ( a5 )
  {
    v11 = (*(int (__thiscall **)(int))(*(_DWORD *)a5 + 4))(a5);
    v7[7] = v11;
    if ( !v11 )
      return 0;
  }
  if ( a4 )
  {
    v12 = sub_695C26(a4);
    if ( v12 )
    {
      v7[7] = sub_67ECDC(v7[7], (int)v12);
      goto LABEL_24;
    }
    return 0;
  }
LABEL_24:
  v13 = (_DWORD *)sub_65B229(20);
  if ( v13 )
    result = sub_67ED1B(v13, (int)v7, 0, (int)"Stmts");
  else
    result = 0;
  if ( !result )
    return 0;
  return result;
}
