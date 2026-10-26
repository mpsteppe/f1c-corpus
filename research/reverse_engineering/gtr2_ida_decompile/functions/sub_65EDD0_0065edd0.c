int __thiscall sub_65EDD0(_DWORD *this, int a2)
{
  char *v2; // eax
  int v4; // ecx
  bool v5; // zf
  char *i; // ecx
  char *v7; // esi
  unsigned int v8; // eax
  int v9; // edx
  unsigned int j; // edi
  int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  int v17; // edx
  int v18; // eax
  char *v19; // esi
  unsigned int v20; // ebx
  char v21; // al
  char v22; // al
  char *v23; // esi
  unsigned int v24; // ebx
  char v25; // al
  char v26; // al
  int result; // eax
  char v28; // [esp-4h] [ebp-64h]
  char v29; // [esp-4h] [ebp-64h]
  char String[16]; // [esp+Ch] [ebp-54h] BYREF
  char *v31; // [esp+1Ch] [ebp-44h]
  int v32; // [esp+20h] [ebp-40h]
  int v33; // [esp+24h] [ebp-3Ch]
  char *v34; // [esp+28h] [ebp-38h]
  int v35; // [esp+2Ch] [ebp-34h]
  int v36; // [esp+30h] [ebp-30h]
  int v37; // [esp+34h] [ebp-2Ch]
  int v38; // [esp+38h] [ebp-28h]
  int v39; // [esp+3Ch] [ebp-24h]
  int v40; // [esp+40h] [ebp-20h]
  int v41; // [esp+44h] [ebp-1Ch]
  int v42; // [esp+48h] [ebp-18h]
  char *v43; // [esp+4Ch] [ebp-14h]
  _DWORD *v44; // [esp+50h] [ebp-10h]
  int v45; // [esp+54h] [ebp-Ch]
  int v46; // [esp+58h] [ebp-8h]
  int v47; // [esp+5Ch] [ebp-4h]

  v2 = *(char **)(a2 + 8);
  v4 = 0;
  this[21] = 0;
  v5 = *v2 == 0;
  v44 = this;
  v47 = 269;
  v32 = 0;
  v46 = 0;
  v45 = 0;
  v33 = 1;
  v39 = 0;
  v37 = 0;
  v36 = 0;
  v41 = 0;
  v38 = 0;
  v40 = 0;
  v42 = 0;
  v35 = 0;
  v34 = v2;
  v43 = v2;
  if ( !v5 )
  {
    while ( 1 )
    {
      for ( i = v43; *i && *i != 95; v43 = i )
        ++i;
      v7 = v34;
      v8 = i - v34;
      if ( (unsigned int)(i - v34) > 0xF )
        return 269;
      qmemcpy(String, v34, 4 * (v8 >> 2));
      qmemcpy(&String[4 * (v8 >> 2)], &v7[4 * (v8 >> 2)], v8 & 3);
      String[v8] = 0;
      if ( *v43 )
        ++v43;
      v34 = v43;
      if ( v33 )
      {
        v9 = 0;
        for ( j = 0; j < 1428; j += 17 )
        {
          if ( !strcmp(String, (const char *)(&off_737E10)[j]) )
            break;
          ++v9;
        }
        if ( v9 == 84 )
          return 269;
        this = v44;
        v11 = v44[14];
        v12 = dword_737E18[16 * v9 + v9 + v11];
        if ( v12 > 0xFFFFFFFA )
        {
          switch ( v12 )
          {
            case 0xFFFFFFFB:
              v47 = 267;
              break;
            case 0xFFFFFFFC:
              v47 = 266;
              break;
            case 0xFFFFFFFD:
              v47 = 264;
              break;
            case 0xFFFFFFFE:
              v47 = 265;
              break;
            default:
              v44[21] = 2023;
              return 269;
          }
        }
        else if ( v12 == -6 )
        {
          v47 = 268;
        }
        else if ( v12 )
        {
          v13 = v12 - 1;
          if ( v13 )
          {
            v14 = v13 - 1;
            if ( v14 )
            {
              v15 = v14 - 1;
              if ( v15 )
              {
                v16 = v15 - 1;
                if ( v16 )
                {
                  if ( v16 == 1 )
                    v47 = 263;
                }
                else
                {
                  v47 = 262;
                }
              }
              else
              {
                v47 = 261;
              }
            }
            else
            {
              v47 = 260;
            }
          }
          else
          {
            v47 = 259;
          }
        }
        else
        {
          v47 = 258;
        }
        v17 = dword_737E14[17 * v9];
        v32 = v17;
        v33 = 0;
        if ( v11 >= 6 && v11 <= 9 && v47 >= 259 && v47 <= 263 )
          v39 = 1;
        if ( (v11 >= 4 && v11 <= 5 || v11 >= 6 && v11 <= 14) && v47 >= 259 && v47 <= 263 && v17 != 31 )
          v37 = 1;
        if ( v11 >= 10 )
        {
          if ( v11 <= 14 && v17 == 31 )
            v36 = 1;
          if ( v11 <= 14 && v47 >= 259 && v47 <= 263 )
            v35 = 1;
        }
        if ( (v11 >= 4 && v11 <= 5 || v11 >= 10 && v11 <= 14) && v17 == 31 )
          v41 = 1;
        if ( v11 >= 13 && v11 <= 14 && v17 == 31 )
          v38 = 1;
        if ( (unsigned int)v11 <= 5 && v17 == 31 )
          v40 = 1;
        if ( v17 == 40 || v17 == 44 || v17 == 94 )
          v42 = 1;
        v44[21] = 2024;
        goto LABEL_209;
      }
      if ( v37 && !strcmp(String, (const char *)&off_739F04) )
      {
        BYTE2(v46) |= 0x10u;
        v39 = 0;
        v37 = 0;
      }
      else if ( v36 && !strcmp(String, "centroid") )
      {
        BYTE2(v46) |= 0x40u;
        v36 = 0;
      }
      else
      {
        if ( v39 )
        {
          if ( !strcmp(String, "x8") )
          {
            v46 = 50331648;
          }
          else if ( !strcmp(String, "x4") )
          {
            v46 = (int)&dword_2000000;
          }
          else if ( !strcmp(String, "x2") )
          {
            v46 = (int)&dword_1000000;
          }
          else if ( !strcmp(String, "d2") )
          {
            v46 = 251658240;
          }
          else if ( !strcmp(String, "d4") )
          {
            v46 = 234881024;
          }
          else
          {
            if ( strcmp(String, "d8") )
              return 269;
            v46 = 218103808;
          }
          v39 = 0;
          goto LABEL_208;
        }
        if ( !v41 )
          goto LABEL_224;
        v18 = 0;
        if ( !strcmp(String, "2d") )
        {
          v18 = 0x10000000;
        }
        else if ( !strcmp(String, "cube") )
        {
          v18 = 402653184;
        }
        else if ( !strcmp(String, "volume") )
        {
          v18 = 0x20000000;
        }
        v45 |= v18;
        v41 = 0;
        if ( v18 )
        {
          v38 = 0;
          v40 = 0;
        }
        else
        {
LABEL_224:
          if ( !v35 || strcmp(String, "pp") )
          {
            if ( !v38 )
              goto LABEL_152;
            v19 = String;
            if ( !String[0] )
              goto LABEL_115;
            do
            {
              if ( !sub_633848() )
                break;
              ++v19;
            }
            while ( *v19 );
            if ( *v19 )
              v20 = j__atol(v19);
            else
LABEL_115:
              v20 = 0;
            if ( v20 > 0xF )
              goto LABEL_152;
            v5 = *v19 == 0;
            HIBYTE(a2) = *v19;
            v31 = v19;
            if ( !v5 )
              *v19++ = 0;
            v21 = *v19;
            if ( *v19 )
            {
              do
              {
                if ( !isdigit(v21) )
                  break;
                v21 = *++v19;
              }
              while ( *v19 );
              if ( *v19 )
                goto LABEL_151;
            }
            v22 = 0;
            if ( !strcmp(String, "position") )
            {
              if ( v20 )
                goto LABEL_125;
LABEL_151:
              *v31 = HIBYTE(a2);
LABEL_152:
              if ( !v40 )
              {
                if ( !v42 )
                  return 269;
                if ( !strcmp(String, "gt") )
                {
                  v45 = 1;
                }
                else if ( !strcmp(String, "eq") )
                {
                  v45 = 2;
                }
                else if ( !strcmp(String, "ge") )
                {
                  v45 = 3;
                }
                else if ( !strcmp(String, "lt") )
                {
                  v45 = 4;
                }
                else if ( !strcmp(String, "ne") )
                {
                  v45 = 5;
                }
                else
                {
                  if ( strcmp(String, "le") )
                    return 269;
                  v45 = 6;
                }
                v42 = 0;
                goto LABEL_208;
              }
              v23 = String;
              if ( !String[0] )
                goto LABEL_158;
              do
              {
                if ( !sub_633848() )
                  break;
                ++v23;
              }
              while ( *v23 );
              if ( *v23 )
                v24 = j__atol(v23);
              else
LABEL_158:
                v24 = 0;
              if ( v24 > 0xF )
                return 269;
              if ( *v23 )
                *v23++ = 0;
              v25 = *v23;
              if ( *v23 )
              {
                do
                {
                  if ( !isdigit(v25) )
                    break;
                  v25 = *++v23;
                }
                while ( *v23 );
                if ( *v23 )
                  return 269;
              }
              v26 = 0;
              if ( strcmp(String, "position") )
              {
                if ( !strcmp(String, "blendweight") )
                {
                  v26 = 1;
                  goto LABEL_192;
                }
                if ( !strcmp(String, "blendindices") )
                {
                  v29 = 2;
                  goto LABEL_191;
                }
                if ( !strcmp(String, "normal") )
                {
                  v29 = 3;
                  goto LABEL_191;
                }
                if ( !strcmp(String, "psize") )
                {
                  v29 = 4;
                  goto LABEL_191;
                }
                if ( !strcmp(String, "texcoord") )
                {
                  v29 = 5;
                  goto LABEL_191;
                }
                v26 = 8;
                if ( !strcmp(String, "tangent") )
                {
                  v29 = 6;
                  goto LABEL_191;
                }
                if ( !strcmp(String, "binormal") )
                {
                  v29 = 7;
                  goto LABEL_191;
                }
                if ( strcmp(String, "tessfactor") )
                {
                  v26 = 10;
                  if ( !strcmp(String, "positiont") )
                  {
                    v29 = 9;
                    goto LABEL_191;
                  }
                  if ( strcmp(String, "color") )
                  {
                    if ( !strcmp(String, off_739E58) )
                    {
                      v29 = 11;
                    }
                    else if ( !strcmp(String, "depth") )
                    {
                      v29 = 12;
                    }
                    else
                    {
                      if ( strcmp(String, "sample") )
                        return 269;
                      v29 = 13;
                    }
LABEL_191:
                    v26 = v29;
                  }
                }
              }
LABEL_192:
              v40 = 0;
              v45 = v26 & 0xF | ((v24 & 0xF) << 16);
LABEL_193:
              v41 = 0;
              goto LABEL_208;
            }
            if ( !strcmp(String, "blendweight") )
            {
              v22 = 1;
LABEL_125:
              v45 |= v22 & 0xF | ((v20 & 0xF) << 16);
              v38 = 0;
              goto LABEL_193;
            }
            if ( !strcmp(String, "blendindices") )
            {
              v28 = 2;
            }
            else if ( !strcmp(String, "normal") )
            {
              v28 = 3;
            }
            else
            {
              v22 = 6;
              if ( !strcmp(String, "psize") )
              {
                v28 = 4;
              }
              else if ( !strcmp(String, "texcoord") )
              {
                v28 = 5;
              }
              else
              {
                if ( !strcmp(String, "tangent") )
                  goto LABEL_125;
                if ( !strcmp(String, "binormal") )
                {
                  v28 = 7;
                }
                else if ( !strcmp(String, "tessfactor") )
                {
                  v28 = 8;
                }
                else
                {
                  v22 = 10;
                  if ( !strcmp(String, "positiont") )
                  {
                    v28 = 9;
                  }
                  else
                  {
                    if ( !strcmp(String, "color") )
                      goto LABEL_125;
                    if ( !strcmp(String, off_739E58) )
                    {
                      v28 = 11;
                    }
                    else if ( !strcmp(String, "depth") )
                    {
                      v28 = 12;
                    }
                    else
                    {
                      if ( strcmp(String, "sample") )
                        goto LABEL_151;
                      v28 = 13;
                    }
                  }
                }
              }
            }
            v22 = v28;
            goto LABEL_125;
          }
          BYTE2(v46) |= 0x20u;
          v35 = 0;
        }
      }
LABEL_208:
      this = v44;
LABEL_209:
      if ( !*v43 )
      {
        v4 = v32;
        if ( v32 == 40 )
        {
          if ( !v42 )
            return off_16C979C(a2);
LABEL_219:
          if ( !v40 )
            break;
          return 269;
        }
        if ( v32 == 44 )
        {
          if ( v42 )
            goto LABEL_219;
          if ( dword_7394B0[this[14]] == -1 )
            return 269;
          v4 = 45;
          v47 = 268;
        }
        if ( v4 == 94 && v42 )
          return 269;
        goto LABEL_219;
      }
    }
  }
  this[17] = v46;
  this[18] = v45;
  result = v47;
  this[16] = v4;
  this[21] = 0;
  return result;
}
