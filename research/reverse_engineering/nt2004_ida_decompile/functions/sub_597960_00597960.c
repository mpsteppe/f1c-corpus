int __thiscall sub_597960(_DWORD *this, const char *a2)
{
  int v2; // ebp
  int v3; // edi
  int v4; // ebp
  int v5; // ebp
  int v6; // ebp

  v2 = this[72];
  v3 = this[73];
  if ( v2 )
  {
    while ( strcmp(a2, (const char *)(v3 + 184)) )
    {
      --v2;
      v3 = *(_DWORD *)(v3 + 204);
      if ( !v2 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v4 = this[74];
    v3 = this[75];
    if ( v4 )
    {
      while ( strcmp(a2, (const char *)(v3 + 184)) )
      {
        --v4;
        v3 = *(_DWORD *)(v3 + 204);
        if ( !v4 )
          goto LABEL_7;
      }
    }
    else
    {
LABEL_7:
      v5 = this[76];
      v3 = this[77];
      if ( v5 )
      {
        while ( strcmp(a2, (const char *)(v3 + 184)) )
        {
          --v5;
          v3 = *(_DWORD *)(v3 + 204);
          if ( !v5 )
            goto LABEL_10;
        }
      }
      else
      {
LABEL_10:
        v6 = this[78];
        v3 = this[79];
        if ( !v6 )
          return 0;
        while ( strcmp(a2, (const char *)(v3 + 184)) )
        {
          --v6;
          v3 = *(_DWORD *)(v3 + 204);
          if ( !v6 )
            return 0;
        }
      }
    }
  }
  return v3;
}
