int __cdecl sub_58E4D2(int a1, unsigned __int8 *a2, int a3)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 v4; // al
  int v5; // edi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int i; // eax
  int v10; // eax
  int v11; // edi
  int v12; // ebx
  int v13; // eax
  int v14; // esi
  int v15; // eax
  int v16; // ebx
  int v17; // ebx
  char *v18; // esi
  int v19; // edi
  int v26; // eax
  char *v30; // edi
  int v31; // eax
  unsigned int v32; // edx
  unsigned __int8 v33; // al
  unsigned __int8 v34; // cl
  unsigned __int8 v35; // al
  int v36; // esi
  _WORD *v37; // esi
  int v39; // eax
  int v40; // eax
  int v41; // eax
  unsigned __int64 v42; // rax
  int v43; // eax
  int v44; // edi
  int v45; // eax
  int v46; // ebx
  int v47; // eax
  int v48; // eax
  int v49; // ecx
  int result; // eax
  int v51; // [esp-4h] [ebp-1D4h]
  char v52; // [esp+Ch] [ebp-1C4h] BYREF
  char v53; // [esp+Dh] [ebp-1C3h] BYREF
  unsigned __int8 v54[32]; // [esp+16Ch] [ebp-64h] BYREF
  int v55; // [esp+18Ch] [ebp-44h]
  WCHAR v56; // [esp+192h] [ebp-3Eh] BYREF
  int v57; // [esp+194h] [ebp-3Ch]
  CHAR v58[3]; // [esp+198h] [ebp-38h] BYREF
  char v59; // [esp+19Bh] [ebp-35h]
  int v60; // [esp+19Ch] [ebp-34h]
  _WORD *v61; // [esp+1A0h] [ebp-30h]
  _WORD *v62; // [esp+1A4h] [ebp-2Ch]
  unsigned __int64 v63; // [esp+1A8h] [ebp-28h]
  int v64; // [esp+1B0h] [ebp-20h]
  int v65; // [esp+1B4h] [ebp-1Ch]
  char v66; // [esp+1B8h] [ebp-18h]
  char v67; // [esp+1B9h] [ebp-17h]
  char v68; // [esp+1BAh] [ebp-16h]
  char v69; // [esp+1BBh] [ebp-15h]
  WORD CharType[2]; // [esp+1BCh] [ebp-14h]
  char v71; // [esp+1C1h] [ebp-Fh]
  char v72; // [esp+1C2h] [ebp-Eh]
  char v73; // [esp+1C3h] [ebp-Dh]
  int v74; // [esp+1C4h] [ebp-Ch]
  char v75; // [esp+1CBh] [ebp-5h]
  int v76; // [esp+1CCh] [ebp-4h] BYREF
  char *v77; // [esp+1DCh] [ebp+Ch]
  unsigned __int8 *v78; // [esp+1DCh] [ebp+Ch]

  v69 = 0;
  v3 = a2;
  v4 = *a2;
  v76 = 0;
  v60 = 0;
  if ( !v4 )
    goto LABEL_256;
  v5 = a1;
  while ( 2 )
  {
    if ( cbMultiByte <= 1 )
      v6 = off_5E69C8[0][v4] & 8;
    else
      v6 = CharacterEncodingConvertViaLookupTableFallback(v4, 8);
    if ( v6 )
    {
      --v76;
      v7 = IncrementWrapperAroundCallLoop(&v76, v5);
      ConditionalFreeIfHandleNot1(v7, v5);
      v8 = *++v3;
      for ( i = sub_589BF3(v8); i; i = sub_589BF3(v10) )
        v10 = *++v3;
    }
    if ( *v3 != 37 )
    {
      ++v76;
      v46 = BufferedByteReader(v5);
      v47 = *v3++;
      *(_DWORD *)CharType = v46;
      v78 = v3;
      if ( v47 == v46 )
      {
        if ( off_5E69C8[0][(unsigned __int8)v46] >= 0 )
          goto LABEL_247;
        ++v76;
        v48 = BufferedByteReader(v5);
        v49 = *v3++;
        v78 = v3;
        if ( v49 == v48 )
        {
          --v76;
          goto LABEL_247;
        }
        --v76;
        ConditionalFreeIfHandleNot1(v48, v5);
        --v76;
        ConditionalFreeIfHandleNot1(v46, v5);
      }
      else
      {
        --v76;
        ConditionalFreeIfHandleNot1(v46, v5);
      }
      break;
    }
    v59 = 0;
    v66 = 0;
    v67 = 0;
    v72 = 0;
    v71 = 0;
    v68 = 0;
    v11 = 0;
    v75 = 0;
    v65 = 0;
    v64 = 0;
    v74 = 0;
    v73 = 1;
    v61 = 0;
    do
    {
      v12 = *++v3;
      if ( cbMultiByte <= 1 )
        v13 = off_5E69C8[0][(unsigned __int8)v12] & 4;
      else
        v13 = CharacterEncodingConvertViaLookupTableFallback((unsigned __int8)v12, 4);
      if ( v13 )
      {
        ++v64;
        v74 = v12 + 10 * v74 - 48;
        continue;
      }
      if ( v12 <= 78 )
      {
        switch ( v12 )
        {
          case 'N':
            continue;
          case '*':
            ++v72;
            continue;
          case 'F':
            continue;
          case 'I':
            if ( v3[1] == 54 && v3[2] == 52 )
            {
              v61 = (_WORD *)((char *)v61 + 1);
              v63 = 0;
              v3 += 2;
              continue;
            }
            break;
          case 'L':
            ++v73;
            continue;
        }
LABEL_32:
        ++v71;
        continue;
      }
      if ( v12 == 104 )
      {
        --v73;
        --v75;
      }
      else
      {
        if ( v12 == 108 )
        {
          ++v73;
        }
        else if ( v12 != 119 )
        {
          goto LABEL_32;
        }
        ++v75;
      }
    }
    while ( !v71 );
    v77 = (char *)v3;
    if ( !v72 )
    {
      v55 = a3;
      a3 += 4;
      v62 = *(_WORD **)(a3 - 4);
    }
    v71 = 0;
    if ( !v75 )
    {
      if ( *v3 == 83 || *v3 == 67 )
        v75 = 1;
      else
        v75 = -1;
    }
    v57 = *v3 | 0x20;
    v14 = v57;
    if ( v57 != 110 )
    {
      if ( v57 == 99 || v57 == 123 )
      {
        ++v76;
        v15 = BufferedByteReader(a1);
      }
      else
      {
        v15 = IncrementWrapperAroundCallLoop(&v76, a1);
      }
      *(_DWORD *)CharType = v15;
    }
    if ( v64 && !v74 )
    {
LABEL_253:
      --v76;
      ConditionalFreeIfHandleNot1(*(_DWORD *)CharType, a1);
      break;
    }
    if ( v14 > 111 )
    {
      switch ( v14 )
      {
        case 'p':
          v73 = 1;
          goto LABEL_181;
        case 's':
          if ( v75 > 0 )
            v68 = 1;
          v30 = asc_5E6D50;
          break;
        case 'u':
          goto LABEL_181;
        case 'x':
LABEL_63:
          v16 = *(_DWORD *)CharType;
          if ( *(_DWORD *)CharType == 45 )
          {
            v67 = 1;
          }
          else if ( *(_DWORD *)CharType != 43 )
          {
LABEL_129:
            if ( v16 != 48 )
              goto LABEL_189;
            ++v76;
            v31 = BufferedByteReader(a1);
            v16 = v31;
            *(_DWORD *)CharType = v31;
            if ( (_BYTE)v31 == 120 || (_BYTE)v31 == 88 )
            {
              ++v76;
              v16 = BufferedByteReader(a1);
              *(_DWORD *)CharType = v16;
              v51 = 120;
              goto LABEL_134;
            }
            v65 = 1;
            if ( v14 != 120 )
            {
              v51 = 111;
LABEL_134:
              v14 = v51;
              goto LABEL_189;
            }
            --v76;
            ConditionalFreeIfHandleNot1(v31, a1);
            v16 = 48;
            goto LABEL_188;
          }
          if ( --v74 || !v64 )
          {
            ++v76;
            v16 = BufferedByteReader(a1);
            *(_DWORD *)CharType = v16;
          }
          else
          {
            v71 = 1;
          }
          goto LABEL_129;
        case '{':
          if ( v75 > 0 )
            v68 = 1;
          v30 = v77 + 1;
          v77 = v30;
          if ( *v30 != 94 )
          {
LABEL_141:
            sub_58BB10(v54, 0, 0x20u);
            if ( v57 == 123 && *v30 == 93 )
            {
              LOBYTE(v32) = 93;
              ++v30;
              v54[11] = 32;
            }
            else
            {
              LOBYTE(v32) = v59;
            }
            while ( 1 )
            {
              v33 = *v30;
              if ( *v30 == 93 )
                break;
              ++v30;
              if ( v33 == 45 && (_BYTE)v32 && (v34 = *v30, *v30 != 93) )
              {
                ++v30;
                if ( (unsigned __int8)v32 >= v34 )
                {
                  v35 = v32;
                  LOBYTE(v32) = v34;
                }
                else
                {
                  v35 = v34;
                }
                if ( (unsigned __int8)v32 <= v35 )
                {
                  v32 = (unsigned __int8)v32;
                  v36 = v35 - (unsigned __int8)v32 + 1;
                  do
                  {
                    v54[v32 >> 3] |= 1 << (v32 & 7);
                    ++v32;
                    --v36;
                  }
                  while ( v36 );
                }
                LOBYTE(v32) = 0;
              }
              else
              {
                LOBYTE(v32) = v33;
                v54[v33 >> 3] |= 1 << (v33 & 7);
              }
            }
            if ( *v30 )
            {
              if ( v57 == 123 )
                v77 = v30;
              v37 = v62;
              --v76;
              v61 = v62;
              ConditionalFreeIfHandleNot1(*(_DWORD *)CharType, a1);
              while ( 1 )
              {
                if ( v64 )
                {
                  if ( !v74-- )
                    break;
                }
                ++v76;
                v39 = BufferedByteReader(a1);
                *(_DWORD *)CharType = v39;
                if ( v39 == -1 || ((1 << (v39 & 7)) & (v66 ^ (char)v54[v39 >> 3])) == 0 )
                {
                  --v76;
                  ConditionalFreeIfHandleNot1(v39, a1);
                  break;
                }
                if ( v72 )
                {
                  v61 = (_WORD *)((char *)v61 + 1);
                }
                else
                {
                  if ( v68 )
                  {
                    v58[0] = v39;
                    if ( off_5E69C8[0][(unsigned __int8)v39] < 0 )
                    {
                      ++v76;
                      v58[1] = BufferedByteReader(a1);
                    }
                    sub_596716(&v56, v58, cbMultiByte);
                    *v37++ = v56;
                  }
                  else
                  {
                    *(_BYTE *)v37 = v39;
                    v37 = (_WORD *)((char *)v37 + 1);
                  }
                  v62 = v37;
                }
              }
              if ( v61 != v37 )
              {
                if ( !v72 )
                {
                  ++v60;
                  if ( v57 != 99 )
                  {
                    if ( v68 )
                      *v62 = 0;
                    else
                      *(_BYTE *)v62 = 0;
                  }
                }
                goto LABEL_242;
              }
            }
            goto LABEL_256;
          }
          ++v30;
          break;
        default:
LABEL_117:
          if ( (unsigned __int8)*v77 == *(_DWORD *)CharType )
          {
            --v69;
            if ( !v72 )
              a3 = v55;
            goto LABEL_242;
          }
          goto LABEL_253;
      }
LABEL_140:
      v66 = -1;
      goto LABEL_141;
    }
    switch ( v14 )
    {
      case 'o':
LABEL_181:
        v16 = *(_DWORD *)CharType;
        if ( *(_DWORD *)CharType == 45 )
        {
          v67 = 1;
        }
        else if ( *(_DWORD *)CharType != 43 )
        {
          goto LABEL_189;
        }
        if ( !--v74 && v64 )
        {
          v71 = 1;
          goto LABEL_189;
        }
        ++v76;
        v16 = BufferedByteReader(a1);
LABEL_188:
        *(_DWORD *)CharType = v16;
LABEL_189:
        if ( v61 )
        {
          if ( !v71 )
          {
            while ( 1 )
            {
              if ( v14 == 120 )
              {
                if ( cbMultiByte <= 1 )
                  v40 = off_5E69C8[0][v16] & 0x80;
                else
                  v40 = CharacterEncodingConvertViaLookupTableFallback(v16, 128);
                if ( !v40 )
                  goto LABEL_209;
                v63 = CRTAllshl(4, HIDWORD(v63));
                v16 = sub_58EEF7(v16);
                *(_DWORD *)CharType = v16;
              }
              else
              {
                if ( cbMultiByte <= 1 )
                  v41 = off_5E69C8[0][v16] & 4;
                else
                  v41 = CharacterEncodingConvertViaLookupTableFallback(v16, 4);
                if ( !v41 )
                {
LABEL_209:
                  --v76;
                  ConditionalFreeIfHandleNot1(v16, a1);
                  break;
                }
                if ( v14 == 111 )
                {
                  if ( v16 >= 56 )
                    goto LABEL_209;
                  LODWORD(v42) = CRTAllshl(3, HIDWORD(v63));
                }
                else
                {
                  v42 = Allmul(v63, 10);
                }
                v63 = v42;
              }
              ++v65;
              v63 += v16 - 48;
              if ( v64 )
              {
                if ( !--v74 )
                  break;
              }
              ++v76;
              v16 = BufferedByteReader(a1);
              *(_DWORD *)CharType = v16;
            }
          }
          if ( v67 )
            v63 = -(__int64)v63;
        }
        else
        {
          if ( !v71 )
          {
            while ( 1 )
            {
              if ( v14 == 120 || v14 == 112 )
              {
                if ( cbMultiByte <= 1 )
                  v45 = off_5E69C8[0][v16] & 0x80;
                else
                  v45 = CharacterEncodingConvertViaLookupTableFallback(v16, 128);
                if ( !v45 )
                {
LABEL_231:
                  --v76;
                  ConditionalFreeIfHandleNot1(v16, a1);
                  break;
                }
                v44 = 16 * v11;
                v16 = sub_58EEF7(v16);
                *(_DWORD *)CharType = v16;
              }
              else
              {
                if ( cbMultiByte <= 1 )
                  v43 = off_5E69C8[0][v16] & 4;
                else
                  v43 = CharacterEncodingConvertViaLookupTableFallback(v16, 4);
                if ( !v43 )
                  goto LABEL_231;
                if ( v14 == 111 )
                {
                  if ( v16 >= 56 )
                    goto LABEL_231;
                  v44 = 8 * v11;
                }
                else
                {
                  v44 = 10 * v11;
                }
              }
              ++v65;
              v11 = v44 + v16 - 48;
              if ( v64 )
              {
                if ( !--v74 )
                  break;
              }
              ++v76;
              v16 = BufferedByteReader(a1);
              *(_DWORD *)CharType = v16;
            }
          }
          if ( v67 )
            v11 = -v11;
        }
        if ( v65 )
        {
          if ( v72 )
            goto LABEL_242;
          ++v60;
          goto LABEL_237;
        }
        goto LABEL_256;
      case 'c':
        if ( !v64 )
        {
          ++v74;
          v64 = 1;
        }
        if ( v75 > 0 )
          v68 = 1;
        v30 = asc_5E6D58;
        goto LABEL_140;
      case 'd':
        goto LABEL_181;
    }
    if ( v14 <= 100 )
      goto LABEL_117;
    if ( v14 <= 103 )
    {
      v17 = *(_DWORD *)CharType;
      v18 = &v52;
      if ( *(_DWORD *)CharType == 45 )
      {
        v52 = 45;
        v18 = &v53;
      }
      else if ( *(_DWORD *)CharType != 43 )
      {
        v19 = a1;
        goto LABEL_70;
      }
      v19 = a1;
      --v74;
      ++v76;
      v17 = BufferedByteReader(a1);
      *(_DWORD *)CharType = v17;
LABEL_70:
      if ( !v64 || v74 > 349 )
        v74 = 349;
      while ( cbMultiByte <= 1 ? off_5E69C8[0][v17] & 4 : CharacterEncodingConvertViaLookupTableFallback(v17, 4) )
      {
        if ( !v74-- )
          break;
        ++v65;
        *v18++ = v17;
        ++v76;
        v17 = BufferedByteReader(v19);
        *(_DWORD *)CharType = v17;
      }
      if ( byte_5E6BD8 == (_BYTE)v17 )
      {
        if ( v74-- )
        {
          ++v76;
          v17 = BufferedByteReader(v19);
          *v18 = byte_5E6BD8;
          *(_DWORD *)CharType = v17;
          ++v18;
          while ( cbMultiByte <= 1 ? off_5E69C8[0][v17] & 4 : CharacterEncodingConvertViaLookupTableFallback(v17, 4) )
          {
            if ( !v74-- )
              break;
            ++v65;
            *v18++ = v17;
            ++v76;
            v17 = BufferedByteReader(v19);
            *(_DWORD *)CharType = v17;
          }
        }
      }
      if ( v65 && (v17 == 101 || v17 == 69) )
      {
        if ( v74-- )
        {
          *v18++ = 101;
          ++v76;
          v26 = BufferedByteReader(v19);
          v17 = v26;
          *(_DWORD *)CharType = v26;
          if ( v26 == 45 )
          {
            *v18++ = 45;
            goto LABEL_95;
          }
          if ( v26 == 43 )
          {
LABEL_95:
            if ( !v74-- )
            {
              v74 = 0;
              goto LABEL_98;
            }
            goto LABEL_97;
          }
LABEL_98:
          while ( cbMultiByte <= 1 ? off_5E69C8[0][v17] & 4 : CharacterEncodingConvertViaLookupTableFallback(v17, 4) )
          {
            if ( !v74-- )
              break;
            ++v65;
            *v18++ = v17;
LABEL_97:
            ++v76;
            v17 = BufferedByteReader(v19);
            *(_DWORD *)CharType = v17;
          }
        }
      }
      --v76;
      ConditionalFreeIfHandleNot1(v17, v19);
      if ( v65 )
      {
        if ( !v72 )
        {
          ++v60;
          *v18 = 0;
          off_5E6738();
        }
        goto LABEL_242;
      }
      break;
    }
    if ( v14 == 105 )
    {
      v14 = 100;
      goto LABEL_63;
    }
    if ( v14 != 110 )
      goto LABEL_117;
    v11 = v76;
    if ( v72 )
      goto LABEL_242;
LABEL_237:
    if ( v61 )
    {
      *(_QWORD *)v62 = v63;
    }
    else if ( v73 )
    {
      *(_DWORD *)v62 = v11;
    }
    else
    {
      *v62 = v11;
    }
LABEL_242:
    ++v69;
    v78 = (unsigned __int8 *)(v77 + 1);
    v3 = v78;
LABEL_247:
    if ( *(_DWORD *)CharType == -1 )
    {
      if ( *v3 == 37 && v78[1] == 110 )
      {
        v3 = v78;
        goto LABEL_251;
      }
LABEL_257:
      result = v60;
      if ( !v60 && !v69 )
        return -1;
      return result;
    }
LABEL_251:
    v4 = *v3;
    if ( *v3 )
    {
      v5 = a1;
      continue;
    }
    break;
  }
LABEL_256:
  if ( *(_DWORD *)CharType == -1 )
    goto LABEL_257;
  return v60;
}

