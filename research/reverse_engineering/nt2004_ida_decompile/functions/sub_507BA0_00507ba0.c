char __fastcall sub_507BA0(const char *ArgList, int a2, int a3, int a4)
{
  const char *v5; // edi
  int v6; // eax
  FILE *v7; // ebx
  int v8; // esi
  int v9; // eax
  int v10; // eax
  int v11; // esi
  char *v12; // esi
  int i; // edi
  const char *v14; // esi
  char *v15; // edi
  const char *v16; // ecx
  const char *v17; // eax
  const char *v18; // ecx
  int v19; // ecx
  char *j; // eax
  int v21; // eax
  bool v22; // zf
  unsigned int v23; // kr08_4
  signed int k; // edi
  char *v25; // eax
  char *v26; // edx
  char v27; // cl
  int v29; // [esp+10h] [ebp-630h]
  int v30; // [esp+14h] [ebp-62Ch]
  int v31; // [esp+18h] [ebp-628h]
  int v32; // [esp+1Ch] [ebp-624h]
  const char *ArgLista; // [esp+20h] [ebp-620h]
  char *v34; // [esp+24h] [ebp-61Ch] BYREF
  char v35[256]; // [esp+28h] [ebp-618h] BYREF
  _BYTE v36[384]; // [esp+128h] [ebp-518h] BYREF
  int v37; // [esp+2A8h] [ebp-398h]
  char v38; // [esp+2ACh] [ebp-394h]
  int v39; // [esp+2B4h] [ebp-38Ch]
  int v40; // [esp+2B8h] [ebp-388h]
  int v41; // [esp+2BCh] [ebp-384h]
  char Str[384]; // [esp+2C0h] [ebp-380h] BYREF
  char Buffer[512]; // [esp+440h] [ebp-200h] BYREF

  memset(Str, 0, sizeof(Str));
  v37 = 0;
  v41 = 0;
  v39 = 0;
  v40 = 0;
  v38 = 1;
  v32 = dword_7D6A5C + 1232 * a2;
  v5 = *(const char **)(v32 + 32);
  if ( !v5 )
    v5 = &byte_629120;
  ArgLista = v5;
  v6 = sub_536110(v5, aRb);
  v31 = v6;
  if ( !v6 )
  {
    if ( dword_75CBA8 != 5 )
    {
      LOBYTE(v6) = sub_500F90(&unk_7D7920, 1, aDDevNascar2004_24, 437);
      if ( (_BYTE)v6 )
        LOBYTE(v6) = sub_500FE0((int)&unk_7D7920, "Could not open %s", v5);
    }
    return v6;
  }
  v7 = fopen(ArgList, aW);
  if ( v7 )
  {
    if ( a4 )
    {
      v8 = sub_536110(a4, aRb);
      if ( v8 )
      {
        while ( sub_5367E0(384) )
        {
          if ( sub_577B60(v36) != 3 )
            fprintf(v7, "%s\n", Str);
        }
        sub_536BE0(v8);
      }
      v29 = 0;
      v30 = 0;
    }
    else
    {
      v9 = dword_630030[6326 * a3];
      if ( !v9 || v9 == 3 )
      {
        v10 = dword_767BEC;
        v30 = 1;
      }
      else
      {
        v10 = dword_767C10;
        v30 = 0;
      }
      switch ( v10 )
      {
        case 0:
          v29 = 1;
          break;
        case 1:
          v29 = 2;
          break;
        case 2:
          v29 = 3;
          break;
        case 3:
          v29 = 4;
          break;
        default:
          break;
      }
    }
    v11 = v31;
    if ( !sub_5367E0(384) )
      goto LABEL_85;
    while ( 1 )
    {
      if ( sub_577B60(v36) == 3 )
        goto LABEL_84;
      while ( 1 )
      {
        v12 = strstr(Str, asc_6012C8);
        if ( !v12 )
          break;
        for ( i = 0; i < v12 - Str; ++i )
          fputc(Str[i], v7);
        v14 = v12 + 1;
        v15 = strstr(Str, asc_6012C4);
        v34 = v15;
        if ( !v15 && dword_75CBA8 != 5 && sub_500F90(&unk_7D7920, 1, aDDevNascar2004_24, 540) )
          sub_500FE0((int)&unk_7D7920, "< does not have matching > in %s", ArgLista);
        *v15 = 0;
        if ( !_strcmpi(v14, aId) )
        {
          fprintf(v7, "%03d", a3);
          goto LABEL_80;
        }
        if ( !_strcmpi(v14, aVehdir) )
        {
          v16 = (const char *)dword_62A0B8;
          if ( !dword_62A0B8 )
            v16 = &byte_629120;
          v17 = *(const char **)dword_62A068;
          if ( !*(_DWORD *)dword_62A068 )
            v17 = &byte_629120;
          sprintf(Buffer, "%s%s", v17, v16);
          fprintf(v7, "%s", Buffer);
          goto LABEL_80;
        }
        if ( !_strcmpi(v14, aTeamdir) )
        {
          v18 = *(const char **)v32;
          if ( !*(_DWORD *)v32 )
            v18 = &byte_629120;
          strcpy(v35, v18);
          v19 = strlen(v35);
          if ( v19 > 0 )
          {
            for ( j = &v35[v19 - 1]; j >= v35; *j-- = 0 )
            {
              if ( *j == 92 )
                break;
            }
          }
          fprintf(v7, "%s", v35);
          goto LABEL_80;
        }
        if ( !_strcmpi(v14, aNotspin) )
        {
          if ( !v29 )
            goto LABEL_73;
          goto LABEL_80;
        }
        if ( !_strcmpi(v14, aSpin) )
        {
          v21 = v29;
          goto LABEL_59;
        }
        if ( _strcmpi(v14, off_601278) )
        {
          if ( _strcmpi(v14, off_601274) )
          {
            if ( _strcmpi(v14, aHigh_0) )
            {
              if ( _strcmpi(v14, off_601268) )
              {
                if ( _strcmpi(v14, aDashlow) )
                {
                  if ( _strcmpi(v14, aDashhigh) )
                  {
                    v23 = strlen(v14) + 1;
                    for ( k = 0; k < (int)(v23 - 1); ++k )
                      fputc(*(char *)(v14[k] + v32 - 9), v7);
                    goto LABEL_80;
                  }
                  v22 = v30 == 1;
                }
                else
                {
                  v21 = v30;
LABEL_59:
                  v22 = v21 == 0;
                }
                if ( !v22 )
                  goto LABEL_73;
                goto LABEL_80;
              }
              if ( v29 != 4 )
LABEL_73:
                fprintf(v7, "//");
            }
            else if ( v29 != 3 )
            {
              goto LABEL_73;
            }
          }
          else if ( v29 != 2 )
          {
            goto LABEL_73;
          }
        }
        else if ( v29 != 1 )
        {
          goto LABEL_73;
        }
LABEL_80:
        v25 = v34 + 1;
        v26 = (char *)(Str - (v34 + 1));
        do
        {
          v27 = *v25;
          v25[(_DWORD)v26] = *v25;
          ++v25;
        }
        while ( v27 );
      }
      fprintf(v7, "%s\n", Str);
      v11 = v31;
LABEL_84:
      if ( !sub_5367E0(384) )
      {
LABEL_85:
        fprintf(v7, "\n");
        fclose(v7);
        LOBYTE(v6) = sub_536BE0(v11);
        return v6;
      }
    }
  }
  if ( dword_75CBA8 != 5 && sub_500F90(&unk_7D7920, 1, aDDevNascar2004_24, 447) )
    sub_500FE0((int)&unk_7D7920, "Could not open %s", ArgList);
  LOBYTE(v6) = sub_536BE0(v31);
  return v6;
}
