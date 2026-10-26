int __stdcall sub_4D34A0(int a1, int a2, signed int a3)
{
  signed int v3; // eax
  const CHAR *v4; // eax
  const CHAR *v5; // eax
  const char *v6; // eax
  const CHAR *v7; // eax
  int i; // esi
  int v9; // ecx
  int *v10; // eax
  int v11; // eax
  _BYTE v13[253]; // [esp+18h] [ebp-100h] BYREF
  __int16 v14; // [esp+115h] [ebp-3h]
  char v15; // [esp+117h] [ebp-1h]

  memset(v13, 0, sizeof(v13));
  v14 = 0;
  v15 = 0;
  v3 = 0;
  if ( a3 > 0 )
  {
    memset(v13, 0x20u, a3);
    v3 = a3;
  }
  v13[v3] = 0;
  v4 = *(const CHAR **)a1;
  if ( !*(_DWORD *)a1 )
    v4 = WindowName;
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s%s=\"%s\"\n", v13, off_711740, v4);
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s{\n", v13);
  v5 = *(const CHAR **)(a1 + 8);
  if ( !v5 )
    v5 = WindowName;
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "  %s%s=\"%s\"\n", v13, "Page", v5);
  v6 = *(const char **)(a1 + 16);
  if ( !v6 )
    v6 = WindowName;
  if ( strcmp(v6, WindowName) )
  {
    v7 = *(const CHAR **)(a1 + 16);
    if ( !v7 )
      v7 = WindowName;
    (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "  %s%s=\"%s\"\n", v13, "AutoSelectChild", v7);
  }
  for ( i = 0; i < *(_DWORD *)(a1 + 40); ++i )
  {
    v9 = i;
    if ( i >= 0 && i < *(_DWORD *)(a1 + 40) )
    {
      v10 = *(int **)(a1 + 28);
      if ( i <= 0 )
      {
LABEL_19:
        if ( v10 )
        {
          v11 = *v10;
          goto LABEL_22;
        }
      }
      else
      {
        while ( v10 )
        {
          v10 = (int *)v10[1];
          if ( --v9 <= 0 )
            goto LABEL_19;
        }
      }
    }
    v11 = 0;
LABEL_22:
    sub_4D34A0(v11, a2, a3 + 2);
  }
  return (*(int (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s}\n", v13);
}
