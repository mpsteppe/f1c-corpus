_BYTE *__thiscall sub_49DC50(_DWORD *this)
{
  _BYTE *result; // eax
  const char *v3; // eax
  char *v4; // eax

  result = (_BYTE *)this[69];
  if ( result )
  {
    if ( *(_DWORD *)dword_B72314 == 3 || *(_DWORD *)dword_B72314 == 5 )
    {
      if ( *result )
      {
        this[67] = 0;
        v3 = (const char *)sub_4CFC00(1);
      }
      else
      {
        this[67] = 1;
        v3 = (const char *)sub_4CFC00(0);
      }
    }
    else
    {
      this[67] = 4;
      v3 = (const char *)sub_4CFC00(2);
    }
    v4 = sub_41D840(&byte_91CC38, v3);
    sub_615860(v4);
    return (_BYTE *)(*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 44))(this, this[67]);
  }
  return result;
}
