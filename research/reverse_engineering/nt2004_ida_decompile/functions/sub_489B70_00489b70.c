int __thiscall sub_489B70(_DWORD *this)
{
  int v2; // edi
  int result; // eax
  int v4; // esi
  const char *v5; // ebx
  const char *v6; // eax

  v2 = sub_4ED610(&dword_7D6B74);
  result = sub_4ED6F0(&dword_7D6B74);
  v4 = 0;
  v5 = (const char *)result;
  if ( v2 > 0 )
  {
    while ( 1 )
    {
      v6 = (const char *)sub_4ED620(v4);
      result = _strcmpi(v5, v6);
      if ( !result )
        break;
      if ( ++v4 >= v2 )
        return result;
    }
    this[218] = v4;
  }
  return result;
}
