char *__thiscall sub_4AE980(_DWORD *this, char *String1)
{
  char *result; // eax
  int v4; // esi
  _DWORD *v5; // edi
  const char *v6; // eax

  result = String1;
  if ( String1 )
  {
    v4 = 0;
    v5 = this + 127;
    do
    {
      if ( !(unsigned __int8)sub_4AFCD0(v5) )
        break;
      v6 = (const char *)sub_4AFCF0(v5);
      result = (char *)_strcmpi(String1, v6);
      if ( !result )
        return result;
      ++v4;
      v5 += 3;
    }
    while ( v4 < 4 );
    if ( v4 == 3 )
    {
      sub_4AFCB0(&byte_629120, 0);
      sub_4AC390((int)this);
    }
    return (char *)sub_4AFCB0(String1, this[73]);
  }
  return result;
}
