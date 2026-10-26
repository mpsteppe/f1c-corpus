_DWORD *__stdcall sub_4BA6B0(char *Source)
{
  _DWORD *result; // eax
  _DWORD *v2; // esi

  result = (_DWORD *)dword_7655CC;
  if ( dword_7655CC )
  {
    if ( sub_4633A0(dword_764D70) == 3 )
    {
      result = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7655CC + 28))(dword_7655CC, 12);
    }
    else
    {
      result = (_DWORD *)sub_4633A0(dword_764D70);
      if ( result != (_DWORD *)2 )
        return result;
      result = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7655CC + 28))(dword_7655CC, 11);
    }
    v2 = result;
    if ( result )
    {
      sub_49F8D0(result, Source, 0);
      sub_49FCC0(v2, v2[37], 1);
      return (_DWORD *)sub_4F0220(4, 1065353216);
    }
  }
  return result;
}
