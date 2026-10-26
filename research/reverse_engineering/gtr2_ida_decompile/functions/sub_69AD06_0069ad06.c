_DWORD *__thiscall sub_69AD06(_DWORD *this, int a2, int a3, int a4)
{
  int v5; // eax
  _DWORD *result; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // esi
  int v9; // eax
  int v10; // eax
  int v11; // eax
  _DWORD *v12; // eax
  double v13[2]; // [esp+8h] [ebp-18h] BYREF
  double v14; // [esp+18h] [ebp-8h] BYREF

  if ( !a2 )
    return 0;
  if ( *(_DWORD *)(a2 + 20) * *(_DWORD *)(a2 + 24) != 1 || !sub_695154(this, *(_DWORD **)(a2 + 16)) )
  {
    sub_694B97((int)this, a2 + 48, 3019, "float expected");
    return 0;
  }
  if ( sub_695AC0((_DWORD *)a2) && sub_69A4A9(this, a2, v13) >= 0 && sub_6959E6(&v14, v13, a2 + 48) >= 0 )
  {
    v5 = a3;
    if ( 0.0 == v14 )
      v5 = a4;
    return (_DWORD *)sub_67ECC3(v5);
  }
  v7 = (_DWORD *)sub_65B229(36);
  if ( v7 )
    v8 = sub_67F53B(v7);
  else
    v8 = 0;
  if ( !v8 )
    return 0;
  v8[4] = 2;
  v9 = (*(int (__thiscall **)(int))(*(_DWORD *)a2 + 4))(a2);
  v8[6] = v9;
  if ( !v9 )
    return 0;
  if ( a3 )
  {
    v10 = (*(int (__thiscall **)(int))(*(_DWORD *)a3 + 4))(a3);
    v8[7] = v10;
    if ( !v10 )
      return 0;
  }
  if ( a4 )
  {
    v11 = (*(int (__thiscall **)(int))(*(_DWORD *)a4 + 4))(a4);
    v8[8] = v11;
    if ( !v11 )
      return 0;
  }
  v12 = (_DWORD *)sub_65B229(20);
  result = v12 ? sub_67ED1B(v12, (int)v8, 0, (int)"Stmts") : 0;
  if ( !result )
    return 0;
  return result;
}
