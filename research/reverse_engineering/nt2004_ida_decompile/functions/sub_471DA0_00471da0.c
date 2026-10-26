int __fastcall sub_471DA0(const char *ArgList, int a2, const char *a3)
{
  const char *v5; // ecx
  const char *v6; // eax
  int result; // eax
  FILE *v8; // ebx
  const char *v9; // eax
  int v10; // esi
  int v11; // eax
  int v12; // esi
  char *v13; // eax
  char *v14; // ebp
  int v15; // edi
  int i; // esi
  const char *v17; // ebp
  char *v18; // esi
  char *v19; // eax
  char v20; // cl
  int v21; // ecx
  char *k; // eax
  unsigned int v23; // kr08_4
  signed int j; // esi
  char *v25; // eax
  char *v26; // edx
  char v27; // cl
  int v28; // [esp+10h] [ebp-830h]
  int v29; // [esp+14h] [ebp-82Ch]
  int v30; // [esp+18h] [ebp-828h]
  int v31; // [esp+1Ch] [ebp-824h]
  char *v33; // [esp+24h] [ebp-81Ch] BYREF
  char v34[256]; // [esp+28h] [ebp-818h] BYREF
  _BYTE v35[384]; // [esp+128h] [ebp-718h] BYREF
  int v36; // [esp+2A8h] [ebp-598h]
  char v37; // [esp+2ACh] [ebp-594h]
  int v38; // [esp+2B4h] [ebp-58Ch]
  int v39; // [esp+2B8h] [ebp-588h]
  int v40; // [esp+2BCh] [ebp-584h]
  char Str[384]; // [esp+2C0h] [ebp-580h] BYREF
  char Buffer[512]; // [esp+440h] [ebp-400h] BYREF
  char v43[512]; // [esp+640h] [ebp-200h] BYREF

  memset(Str, 0, sizeof(Str));
  v29 = dword_7D6B58 + 400 * dword_7D6B54;
  v36 = 0;
  v40 = 0;
  v38 = 0;
  v39 = 0;
  v37 = 1;
  v5 = (const char *)dword_62A0B0;
  if ( !dword_62A0B0 )
    v5 = &byte_629120;
  v6 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v6 = &byte_629120;
  sprintf(Buffer, "%s%s%s", v6, v5, aTrackdisplayGe);
  result = sub_536110(Buffer, aRb);
  v30 = result;
  if ( !result )
  {
    if ( dword_75CBA8 != 5 )
    {
      result = sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_28, 3204);
      if ( (_BYTE)result )
        return sub_500FE0((int)&unk_7D7920, aCouldNotOpenS, (char)Buffer);
    }
    return result;
  }
  v8 = fopen(ArgList, aW);
  if ( v8 )
  {
    if ( a3 )
    {
      v9 = *(const char **)dword_62A068;
      if ( !*(_DWORD *)dword_62A068 )
        v9 = &byte_629120;
      sprintf(v43, "%s%s", v9, a3);
      v10 = sub_536110(v43, aRb);
      if ( v10 )
      {
        while ( sub_5367E0(384) )
        {
          if ( sub_577B60(v35) != 3 )
            fprintf(v8, "%s\n", Str);
        }
        sub_536BE0(v10);
      }
      v28 = 0;
    }
    else
    {
      v11 = dword_767BEC;
      if ( dword_630030[6326 * a2] )
        v11 = dword_767C10;
      switch ( v11 )
      {
        case 0:
          v28 = 1;
          break;
        case 1:
          v28 = 2;
          break;
        case 2:
          v28 = 3;
          break;
        case 3:
          v28 = 4;
          break;
        default:
          break;
      }
    }
    v12 = v30;
    if ( !sub_5367E0(384) )
      goto LABEL_77;
    while ( 1 )
    {
      if ( sub_577B60(v35) == 3 )
        goto LABEL_76;
      while ( 1 )
      {
        v13 = strstr(Str, asc_6012C8);
        v14 = v13;
        if ( !v13 )
          break;
        v15 = v13 - Str;
        for ( i = 0; i < v15; ++i )
          fputc(Str[i], v8);
        v17 = v14 + 1;
        v18 = strstr(Str, asc_6012C4);
        v33 = v18;
        if ( !v18
          && dword_75CBA8 != 5
          && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_28, 3304) )
        {
          sub_500FE0((int)&unk_7D7920, aDoesNotHaveMat, (char)Buffer);
        }
        *v18 = 0;
        if ( _strcmpi(v17, aId) )
        {
          if ( _strcmpi(v17, aTeamdir) )
          {
            if ( _strcmpi(v17, aNotspin) )
            {
              if ( _strcmpi(v17, aSpin) )
              {
                if ( _strcmpi(v17, off_601278) )
                {
                  if ( _strcmpi(v17, off_601274) )
                  {
                    if ( _strcmpi(v17, aHigh_0) )
                    {
                      if ( _strcmpi(v17, off_601268) )
                      {
                        if ( _strcmpi(v17, aTrackname_1) )
                        {
                          v23 = strlen((const char *)(v29 + 260)) + 1;
                          for ( j = 0; j < (int)(v23 - 1); ++j )
                            fputc(*(char *)(v17[j] + v31 - 49), v8);
                        }
                        else
                        {
                          v31 = v29 + 260;
                          fprintf(v8, "%s", (const char *)(v29 + 260));
                        }
                      }
                      else if ( v28 != 4 )
                      {
LABEL_67:
                        fprintf(v8, "//");
                      }
                    }
                    else if ( v28 != 3 )
                    {
                      goto LABEL_67;
                    }
                  }
                  else if ( v28 != 2 )
                  {
                    goto LABEL_67;
                  }
                }
                else if ( v28 != 1 )
                {
                  goto LABEL_67;
                }
              }
              else if ( v28 )
              {
                goto LABEL_67;
              }
            }
            else if ( !v28 )
            {
              goto LABEL_67;
            }
          }
          else
          {
            v19 = (char *)(v29 + 4);
            v31 = v29 + 260;
            do
            {
              v20 = *v19;
              v34[(_DWORD)v19 - 4 - v29] = *v19;
              ++v19;
            }
            while ( v20 );
            v21 = strlen(v34);
            if ( v21 > 0 )
            {
              for ( k = &v34[v21 - 1]; k >= v34; *k-- = 0 )
              {
                if ( *k == 92 )
                  break;
              }
            }
            fprintf(v8, "%s", v34);
          }
        }
        else
        {
          fprintf(v8, "%03d", a2);
        }
        v25 = v33 + 1;
        v26 = (char *)(Str - (v33 + 1));
        do
        {
          v27 = *v25;
          v25[(_DWORD)v26] = *v25;
          ++v25;
        }
        while ( v27 );
      }
      fprintf(v8, "%s\n", Str);
      v12 = v30;
LABEL_76:
      if ( !sub_5367E0(384) )
      {
LABEL_77:
        fprintf(v8, "\n");
        fclose(v8);
        return sub_536BE0(v12);
      }
    }
  }
  if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_28, 3214) )
    sub_500FE0((int)&unk_7D7920, aCouldNotOpenS, (char)ArgList);
  return sub_536BE0(v30);
}
