const char ***__usercall sub_4A6FE0@<eax>(int a1@<ecx>, int a2@<edi>)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  const char ***result; // eax
  const char **v7; // edi
  const char *v8; // eax
  int v9; // eax
  const CHAR ***v10; // eax
  const CHAR **v11; // eax
  const CHAR *v12; // eax
  char *v13; // edx
  const char *v14; // eax
  int v15; // eax
  const CHAR ***v16; // eax
  const CHAR **v17; // edi
  const CHAR *v18; // eax
  const CHAR *v19; // eax
  int v20; // eax
  int v21; // [esp-Ch] [ebp-74h]
  _DWORD v22[2]; // [esp+0h] [ebp-68h] BYREF
  char v23[21]; // [esp+8h] [ebp-60h] BYREF
  _DWORD v24[2]; // [esp+1Dh] [ebp-4Bh] BYREF
  __int16 v25; // [esp+25h] [ebp-43h]
  char v26; // [esp+27h] [ebp-41h]
  _BYTE v27[29]; // [esp+28h] [ebp-40h] BYREF
  __int16 v28; // [esp+45h] [ebp-23h]
  char v29; // [esp+47h] [ebp-21h]
  _WORD v30[15]; // [esp+48h] [ebp-20h] BYREF
  __int16 v31; // [esp+66h] [ebp-2h]

  strcpy(v27, "FT_Standard_TEXT");
  strcpy(v23, "FT_LISTBOX_HIGHLIGHT");
  memset(&v27[17], 0, 12);
  v24[0] = 0;
  v24[1] = 0;
  v25 = 0;
  v28 = 0;
  v26 = 0;
  v29 = 0;
  memset(&v30[9], 0, 12);
  strcpy((char *)v30, "FT_Standard_VALUE");
  v31 = 0;
  v3 = sub_4CF8C0(a1);
  sub_630FE0(v27, v3, 31);
  v29 = 0;
  v4 = sub_4CF8E0(a1, v22[1]);
  sub_630FE0(v23, v4, 31);
  v26 = 0;
  v5 = sub_4CF900(a1);
  sub_630FE0(v30, v5, 31);
  result = *(const char ****)(a1 + 596);
  HIBYTE(v31) = 0;
  *(_DWORD *)(a1 + 604) = result;
  if ( result )
  {
    v22[0] = a2;
    v7 = *result;
    if ( *result )
    {
      while ( 1 )
      {
        sub_4CF8C0(a1);
        sub_4CE460(a1);
        v8 = *v7;
        if ( !*v7 )
          v8 = WindowName;
        if ( !_stricmp(v8, "<HEADER>") )
        {
          v9 = *(_DWORD *)(a1 + 604);
          if ( v9 )
            *(_DWORD *)(a1 + 604) = *(_DWORD *)(v9 + 4);
          v10 = *(const CHAR ****)(a1 + 604);
          if ( !v10 )
            goto LABEL_30;
          v11 = *v10;
          if ( !v11 )
            goto LABEL_30;
          v12 = *v11;
          if ( !v12 )
            v12 = WindowName;
          v13 = (char *)v22;
        }
        else
        {
          v14 = *v7;
          if ( !*v7 )
            v14 = WindowName;
          if ( !_stricmp(v14, "<HEADER2>") )
          {
            v15 = *(_DWORD *)(a1 + 604);
            if ( v15 )
              *(_DWORD *)(a1 + 604) = *(_DWORD *)(v15 + 4);
            v16 = *(const CHAR ****)(a1 + 604);
            if ( v16 )
            {
              v17 = *v16;
              if ( *v16 )
              {
                v21 = sub_4CF8E0(a1, 0);
                sub_4CE460(a1);
                v18 = *v17;
                if ( !*v17 )
                  v18 = WindowName;
                sub_4D93B0(v18, 0, 0, 0, -1, -1, -1, -1, 0, v21);
              }
            }
            goto LABEL_30;
          }
          v19 = *v7;
          if ( !*v7 )
            v19 = WindowName;
          if ( sub_616480(v19, &unk_6FE91C) )
            goto LABEL_30;
          v12 = *v7;
          if ( !*v7 )
            v12 = WindowName;
          v13 = (char *)v24 + 3;
        }
        sub_4D93B0(v12, 0, v13, 0, 0, 0, -1, -1, -1, -1);
LABEL_30:
        v20 = *(_DWORD *)(a1 + 604);
        if ( v20 )
          *(_DWORD *)(a1 + 604) = *(_DWORD *)(v20 + 4);
        result = *(const char ****)(a1 + 604);
        if ( result )
        {
          v7 = *result;
          if ( *result )
            continue;
        }
        return result;
      }
    }
  }
  return result;
}
