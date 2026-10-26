int __thiscall sub_4E48E0(CHAR ****this, int a2)
{
  int v3; // ebx
  int v4; // esi
  int v5; // eax
  const char *v6; // edi
  CHAR *v7; // eax

  v3 = sub_57AE50(aRaceorder);
  if ( !v3 )
    return -1;
  if ( a2 < 0 )
    return -1;
  if ( a2 >= sub_4B15C0(this) )
    return -1;
  v4 = 0;
  if ( sub_57A6E0(v3) <= 0 )
    return -1;
  while ( 1 )
  {
    v5 = sub_57A700(v4);
    if ( v5 )
    {
      v6 = (const char *)sub_57A6C0(v5);
      v7 = sub_4E4800(this, a2);
      if ( !_strcmpi(v6, v7) )
        break;
    }
    if ( ++v4 >= sub_57A6E0(v3) )
      return -1;
  }
  return v4;
}
