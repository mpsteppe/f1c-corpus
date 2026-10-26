// f1c  0x005456b0  size=261
int __thiscall sub_5456B0(_DWORD *this, const char *a2)
{
  int v2; // ebp
  int v3; // edi
  int v4; // ebp
  int v5; // ebp

  v2 = this[71];
  v3 = this[72];
  if ( v2 )
  {
    while ( strcmp(a2, (const char *)(v3 + 88)) )
    {
      --v2;
      v3 = *(_DWORD *)(v3 + 108);
      if ( !v2 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v4 = this[73];
    v3 = this[74];
    if ( v4 )
    {
      while ( strcmp(a2, (const char *)(v3 + 88)) )
      {
        --v4;
        v3 = *(_DWORD *)(v3 + 108);
        if ( !v4 )
          goto LABEL_7;
      }
    }
    else
    {
LABEL_7:
      v5 = this[75];
      v3 = this[76];
      if ( !v5 )
        return 0;
      while ( strcmp(a2, (const char *)(v3 + 88)) )
      {
        --v5;
        v3 = *(_DWORD *)(v3 + 108);
        if ( !v5 )
          return 0;
      }
    }
  }
  return v3;
}
