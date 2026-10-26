_DWORD *__stdcall sub_4A0DF0(int a1)
{
  _DWORD *result; // eax
  _DWORD *v2; // esi

  if ( sub_461CD0(dword_7CD25C) == 3 )
  {
    result = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 36);
  }
  else
  {
    result = (_DWORD *)sub_461CD0(dword_7CD25C);
    if ( result != (_DWORD *)2 )
      return result;
    result = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 35);
  }
  v2 = result;
  if ( result )
  {
    sub_4896C0(result, a1, 0);
    sub_489AB0(v2, v2[37], 1);
    return (_DWORD *)sub_4C8DE0(4, 1065353216);
  }
  return result;
}
