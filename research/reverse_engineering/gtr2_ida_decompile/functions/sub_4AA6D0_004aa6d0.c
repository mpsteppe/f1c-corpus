void __thiscall sub_4AA6D0(_DWORD *this)
{
  int v2; // ecx
  int v3; // eax
  const char **v4; // eax
  const char *v5; // eax
  char *v6; // eax

  v2 = this[214];
  if ( v2 >= 0 && v2 < this[213] )
  {
    v3 = this[210];
    if ( v2 <= 0 )
    {
LABEL_6:
      if ( v3 )
      {
        v4 = *(const char ***)v3;
        if ( v4 )
        {
          v5 = *v4;
          if ( !v5 )
            v5 = WindowName;
          v6 = sub_41D840(&byte_91CC38, v5);
          sub_4CE770(v6);
        }
      }
    }
    else
    {
      while ( v3 )
      {
        v3 = *(_DWORD *)(v3 + 4);
        if ( --v2 <= 0 )
          goto LABEL_6;
      }
    }
  }
}
