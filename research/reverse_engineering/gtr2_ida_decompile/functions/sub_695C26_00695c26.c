_DWORD *__stdcall sub_695C26(int a1)
{
  _DWORD *v1; // eax
  _DWORD *v2; // esi
  int v3; // eax
  _DWORD *v4; // eax
  _DWORD *result; // eax

  v1 = (_DWORD *)sub_65B229(36);
  if ( v1 )
    v2 = sub_67F53B(v1);
  else
    v2 = 0;
  if ( !v2 )
    return 0;
  v2[4] = 0;
  if ( a1 )
  {
    v3 = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 4))(a1);
    v2[5] = v3;
    if ( !v3 )
      return 0;
  }
  v4 = (_DWORD *)sub_65B229(20);
  result = v4 ? sub_67ED1B(v4, (int)v2, 0, (int)"Stmts") : 0;
  if ( !result )
    return 0;
  return result;
}
