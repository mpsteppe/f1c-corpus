_BYTE *__fastcall sub_5642B0(int a1, const char *a2)
{
  _BYTE *result; // eax
  _BYTE *v5; // esi

  result = (_BYTE *)sub_589DB0(a2, 58);
  v5 = result;
  if ( result )
  {
    *result = 0;
    *(_DWORD *)a1 = inet_addr(a2);
    result = (_BYTE *)SingleFunctionCallWrapper_7f59(v5 + 1);
    *(_WORD *)(a1 + 4) = (_WORD)result;
  }
  return result;
}

