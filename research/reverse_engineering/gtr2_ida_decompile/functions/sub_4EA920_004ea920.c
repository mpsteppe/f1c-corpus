_DWORD *__stdcall sub_4EA920(int a1)
{
  _DWORD *result; // eax
  _DWORD *v2; // esi

  if ( sub_473550() == 3 )
  {
    result = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 25);
  }
  else
  {
    result = (_DWORD *)sub_473550();
    if ( result != (_DWORD *)2 )
      return result;
    result = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 24);
  }
  v2 = result;
  if ( result )
  {
    sub_4D9550(result, a1, 0);
    sub_4D4060(v2, v2[37], 1);
    return (_DWORD *)sub_540E90(&unk_BE1D30, 4, 1065353216);
  }
  return result;
}
