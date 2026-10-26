wint_t __cdecl btowc(int Ch)
{
  wint_t result; // ax
  bool v2; // sf
  mbstate_t v3; // [esp+0h] [ebp-8h] BYREF

  if ( Ch == -1 )
    return -1;
  HIBYTE(Ch) = Ch;
  v3._Wchar = 0;
  v2 = _Mbrtowc(&v3._State, (const char *)&Ch + 3, 1u, &v3, 0) < 0;
  result = -1;
  if ( !v2 )
    return v3._State;
  return result;
}
