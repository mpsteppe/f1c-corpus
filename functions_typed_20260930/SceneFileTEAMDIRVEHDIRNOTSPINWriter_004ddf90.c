char __fastcall sub_4DDF90(const char *a1, int a2, int a3, int a4)
{
  const char *v5; // edi
  int v6; // eax
  int v7; // ebx
  int v8; // esi
  int v9; // eax
  int v10; // eax
  int v11; // esi
  int v12; // esi
  int i; // edi
  const char *v14; // esi
  _BYTE *v15; // edi
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
  int v26; // edx
  char v27; // cl
  int v29; // [esp+10h] [ebp-630h]
  int v30; // [esp+14h] [ebp-62Ch]
  int v31; // [esp+18h] [ebp-628h]
  int v32; // [esp+1Ch] [ebp-624h]
  const char *v33; // [esp+20h] [ebp-620h]
  _BYTE *v34; // [esp+24h] [ebp-61Ch] BYREF
  char v35[256]; // [esp+28h] [ebp-618h] BYREF
  _BYTE v36[384]; // [esp+128h] [ebp-518h] BYREF
  int v37; // [esp+2A8h] [ebp-398h]
  char v38; // [esp+2ACh] [ebp-394h]
  int v39; // [esp+2B4h] [ebp-38Ch]
  int v40; // [esp+2B8h] [ebp-388h]
  int v41; // [esp+2BCh] [ebp-384h]
  _BYTE v42[384]; // [esp+2C0h] [ebp-380h] BYREF
  char v43[512]; // [esp+440h] [ebp-200h] BYREF

  memset(v42, 0, sizeof(v42));
  v37 = 0;
  v41 = 0;
  v39 = 0;
  v40 = 0;
  v38 = 1;
  v32 = dword_8AC394 + 1060 * a2;
  v5 = *(const char **)(v32 + 32);
  if ( !v5 )
    v5 = byte_5EA438;
  v33 = v5;
  v6 = sub_534B00(v5, aRb);
  v31 = v6;
  if ( !v6 )
  {
    if ( dword_7C569C != 5 )
    {
      LOBYTE(v6) = StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_6, 587);
      if ( (_BYTE)v6 )
        LOBYTE(v6) = DebugLogWrite((int)dword_8AD25C, (int)"Could not open %s", v5);
    }
    return v6;
  }
  v7 = sub_587DB0(a1, aW);
  if ( v7 )
  {
    if ( a4 )
    {
      v8 = sub_534B00(a4, aRb);
      if ( v8 )
      {
        while ( LineInputReader(384) )
        {
          if ( sub_5651B0(v36) != 3 )
            StringFormatWithNestedIO(v7, aS_7);
        }
        StreamFileTypeCheckWithDispatch(v8);
      }
      v29 = 0;
      v30 = 0;
    }
    else
    {
      v9 = MEMORY[0x5EF9A0][4656 * a3];
      if ( !v9 || v9 == 3 )
      {
        v10 = dword_7CF7F4;
        v30 = 1;
      }
      else
      {
        v10 = dword_7CF818;
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
    if ( !LineInputReader(384) )
      goto LABEL_85;
    while ( 1 )
    {
      if ( sub_5651B0(v36) == 3 )
        goto LABEL_84;
      while ( 1 )
      {
        v12 = sub_587C20(v42, asc_5C6808);
        if ( !v12 )
          break;
        for ( i = 0; i < v12 - (int)v42; ++i )
          BufferedCharacterWriteWithOverflowHandling((char)v42[i], v7);
        v14 = (const char *)(v12 + 1);
        v15 = (_BYTE *)sub_587C20(v42, asc_5C6804);
        v34 = v15;
        if ( !v15 && dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_6, 690) )
          DebugLogWrite((int)dword_8AD25C, (int)"< does not have matching > in %s", v33);
        *v15 = 0;
        if ( !sub_588410(v14, aId) )
        {
          StringFormatWithNestedIO(v7, a03d);
          goto LABEL_80;
        }
        if ( !sub_588410(v14, aVehdir) )
        {
          v16 = (const char *)dword_5EC428;
          if ( !dword_5EC428 )
            v16 = byte_5EA438;
          v17 = (const char *)dword_5EC3D8;
          if ( !dword_5EC3D8 )
            v17 = byte_5EA438;
          StringFormatWithBufferOverflowCheck(v43, "%s%s", v17, v16);
          StringFormatWithNestedIO(v7, aS_4);
          goto LABEL_80;
        }
        if ( !sub_588410(v14, aTeamdir) )
        {
          v18 = *(const char **)v32;
          if ( !*(_DWORD *)v32 )
            v18 = byte_5EA438;
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
          StringFormatWithNestedIO(v7, aS_4);
          goto LABEL_80;
        }
        if ( !sub_588410(v14, aNotspin) )
        {
          if ( !v29 )
            goto LABEL_73;
          goto LABEL_80;
        }
        if ( !sub_588410(v14, aSpin) )
        {
          v21 = v29;
          goto LABEL_59;
        }
        if ( sub_588410(v14, &off_5C67B8) )
        {
          if ( sub_588410(v14, aMed) )
          {
            if ( sub_588410(v14, aHigh_0) )
            {
              if ( sub_588410(v14, &off_5C67A8) )
              {
                if ( sub_588410(v14, aDashlow) )
                {
                  if ( sub_588410(v14, aDashhigh) )
                  {
                    v23 = strlen(v14) + 1;
                    for ( k = 0; k < (int)(v23 - 1); ++k )
                      BufferedCharacterWriteWithOverflowHandling(*(char *)(v14[k] + v32 - 9), v7);
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
                StringFormatWithNestedIO(v7, &unk_5C30B8);
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
        v26 = v42 - (v34 + 1);
        do
        {
          v27 = *v25;
          v25[v26] = *v25;
          ++v25;
        }
        while ( v27 );
      }
      StringFormatWithNestedIO(v7, aS_7);
      v11 = v31;
LABEL_84:
      if ( !LineInputReader(384) )
      {
LABEL_85:
        StringFormatWithNestedIO(v7, &word_5C30B4);
        FileCloseWithLock(v7);
        LOBYTE(v6) = StreamFileTypeCheckWithDispatch(v11);
        return v6;
      }
    }
  }
  if ( dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_6, 597) )
    DebugLogWrite((int)dword_8AD25C, (int)"Could not open %s", a1);
  LOBYTE(v6) = StreamFileTypeCheckWithDispatch(v31);
  return v6;
}

