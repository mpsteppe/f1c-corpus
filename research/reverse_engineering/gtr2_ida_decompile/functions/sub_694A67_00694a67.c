int sub_694A67(int a1, char *Format, ...)
{
  int result; // eax
  int v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  _DWORD *v7; // [esp-24h] [ebp-12Ch]
  char Buffer[256]; // [esp+8h] [ebp-100h] BYREF
  va_list va; // [esp+118h] [ebp+10h] BYREF

  va_start(va, Format);
  result = 0;
  if ( !strcmp(Format, "syntax error") )
  {
    v3 = a1;
    if ( *(_DWORD *)(a1 + 64) )
      goto LABEL_23;
    v4 = *(_DWORD *)(a1 + 32);
    if ( v4 <= 9 )
    {
      if ( v4 == 9 )
      {
        sub_632041((int)Buffer, 256, "token '%s'", *(const char **)(a1 + 40));
      }
      else if ( v4 )
      {
        if ( v4 != 1 )
        {
          if ( v4 > 1 )
          {
            if ( v4 <= 4 )
              sub_632041((int)Buffer, 256, "integer constant");
            else
              sub_632041((int)Buffer, 256, "float constant");
            goto LABEL_22;
          }
LABEL_18:
          sub_632041((int)Buffer, 256, "token");
          goto LABEL_22;
        }
        sub_632041((int)Buffer, 256, "token '%s'", (const char *)(a1 + 40));
      }
      else
      {
        sub_632041((int)Buffer, 256, "version token");
      }
LABEL_22:
      result = sub_65DD1F((_DWORD *)(*(_DWORD *)(a1 + 4) + 24), a1 + 32, 3000, "syntax error: unexpected %s", Buffer);
      goto LABEL_23;
    }
    v5 = v4 - 10;
    if ( !v5 )
    {
      sub_632041((int)Buffer, 256, "string constant");
      goto LABEL_22;
    }
    v6 = v5 - 2;
    if ( !v6 )
    {
      sub_632041((int)Buffer, 256, "end of line");
      goto LABEL_22;
    }
    if ( v6 == 1 )
    {
      sub_632041((int)Buffer, 256, "end of file");
      goto LABEL_22;
    }
    goto LABEL_18;
  }
  _vsnprintf(Buffer, 0x100u, Format, va);
  v3 = a1;
  v7 = (_DWORD *)(*(_DWORD *)(a1 + 4) + 24);
  Buffer[255] = 0;
  result = sub_65DD1F(v7, a1 + 32, 0, "%s", Buffer);
LABEL_23:
  *(_DWORD *)(v3 + 64) = 1;
  return result;
}
