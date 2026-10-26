int __thiscall sub_69AE2D(_DWORD *this)
{
  _DWORD *v1; // ebx
  _DWORD *v2; // esi
  int result; // eax
  char v4; // cl
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  char v12; // al
  int v13; // eax
  int v14; // eax
  int v15; // eax
  const char *v16; // eax
  const char *v17; // edi
  int v18; // eax
  unsigned int v19; // [esp-4h] [ebp-18h]

  v1 = this;
  v2 = this + 8;
  while ( 2 )
  {
    if ( sub_65D1E3((_DWORD *)v1[1], v2) >= 0 )
    {
      switch ( *v2 )
      {
        case 0:
          goto LABEL_198;
        case 1:
          v4 = *((_BYTE *)v1 + 41);
          if ( !v4 )
            return *((char *)v1 + 40);
          if ( *((_BYTE *)v1 + 42) )
            goto LABEL_198;
          if ( v4 == 61 )
          {
            v5 = *((char *)v1 + 40);
            if ( v5 > 45 )
            {
              v9 = v5 - 47;
              if ( !v9 )
                return 323;
              v10 = v9 - 13;
              if ( !v10 )
                return 316;
              v11 = v10 - 1;
              if ( !v11 )
                return 318;
              if ( v11 == 1 )
                return 317;
            }
            else
            {
              if ( v5 == 45 )
                return 326;
              v6 = v5 - 33;
              if ( !v6 )
                return 319;
              v7 = v6 - 4;
              if ( !v7 )
                return 324;
              v8 = v7 - 5;
              if ( !v8 )
                return 322;
              if ( v8 == 1 )
                return 325;
            }
          }
          else
          {
            v12 = *((_BYTE *)v1 + 40);
            if ( v12 == v4 )
            {
              v13 = v12 - 38;
              if ( !v13 )
                return 320;
              v14 = v13 - 5;
              if ( !v14 )
                return 314;
              v15 = v14 - 2;
              if ( !v15 )
                return 315;
              if ( v15 == 79 )
                return 321;
            }
          }
LABEL_198:
          result = 337;
          break;
        case 2:
          return 327;
        case 3:
          return 328;
        case 4:
          return 329;
        case 5:
          return 330;
        case 6:
          return 331;
        case 7:
          return 332;
        case 8:
          return 333;
        case 9:
          v16 = (const char *)v1[10];
          switch ( *v16 )
          {
            case 'a':
              if ( !strcmp((const char *)v1[10], "auto") )
                goto LABEL_198;
              if ( strcmp((const char *)v1[10], "asm_fragment") )
                goto LABEL_80;
              return 258;
            case 'b':
              if ( strcmp((const char *)v1[10], "bool") )
              {
                v17 = "break";
                goto LABEL_53;
              }
              return 259;
            case 'c':
              if ( !strcmp((const char *)v1[10], "case")
                || !strcmp((const char *)v1[10], "catch")
                || !strcmp((const char *)v1[10], "char")
                || !strcmp((const char *)v1[10], (const char *)&dword_6FF740) )
              {
                goto LABEL_198;
              }
              if ( !strcmp((const char *)v1[10], "column_major") )
                return 260;
              if ( !strcmp((const char *)v1[10], "compile") )
                return 261;
              if ( !strcmp((const char *)v1[10], "compile_fragment") )
                return 262;
              if ( strcmp((const char *)v1[10], "const") )
              {
                if ( !strcmp((const char *)v1[10], "const_cast") )
                  goto LABEL_198;
                v17 = "continue";
                goto LABEL_122;
              }
              return 263;
            case 'd':
              if ( !strcmp((const char *)v1[10], "default") || !strcmp((const char *)v1[10], "delete") )
                goto LABEL_198;
              if ( !strcmp((const char *)v1[10], "discard") )
                return 265;
              if ( !strcmp((const char *)v1[10], "do") )
                return 267;
              if ( strcmp((const char *)v1[10], "double") )
              {
                if ( !strcmp((const char *)v1[10], "dynamic_cast") )
                  goto LABEL_198;
                v1 = this;
                goto LABEL_80;
              }
              return 266;
            case 'e':
              if ( !strcmp((const char *)v1[10], "else") )
                return 268;
              if ( !strcmp((const char *)v1[10], "enum") || !strcmp((const char *)v1[10], "explicit") )
                goto LABEL_198;
              if ( strcmp((const char *)v1[10], "extern") )
                goto LABEL_80;
              return 269;
            case 'f':
              if ( !strcmp((const char *)v1[10], "false") )
                return 270;
              if ( !strcmp((const char *)v1[10], "float") )
                return 271;
              if ( strcmp((const char *)v1[10], (const char *)&off_741AFC) )
              {
                v17 = "friend";
                v19 = 7;
                goto LABEL_54;
              }
              return 272;
            case 'g':
              v17 = "goto";
              goto LABEL_113;
            case 'h':
              if ( strcmp((const char *)v1[10], "half") )
                goto LABEL_80;
              return 273;
            case 'i':
              if ( !strcmp((const char *)v1[10], "if") )
                return 274;
              if ( !strcmp((const char *)v1[10], "in") )
                return 275;
              if ( !strcmp((const char *)v1[10], "inline") )
                return 276;
              if ( !strcmp((const char *)v1[10], "inout") )
                return 277;
              if ( strcmp((const char *)v1[10], (const char *)&off_7413EC) )
                goto LABEL_80;
              return 278;
            case 'l':
              v17 = "long";
LABEL_113:
              v19 = 5;
              goto LABEL_54;
            case 'm':
              if ( !strcmp((const char *)v1[10], "matrix") )
                return 279;
              v17 = "mutable";
              v19 = 8;
              goto LABEL_54;
            case 'n':
              if ( !strcmp((const char *)v1[10], "namespace") )
                goto LABEL_198;
              v17 = (const char *)&off_741AC4;
              v19 = 4;
              goto LABEL_54;
            case 'o':
              if ( !strcmp((const char *)v1[10], (const char *)&off_741AC0) )
                return 280;
              v17 = "operator";
LABEL_122:
              v19 = 9;
              goto LABEL_54;
            case 'p':
              if ( !strcmp((const char *)v1[10], "pixelfragment") )
                return 282;
              if ( !strcmp((const char *)v1[10], "private")
                || !strcmp((const char *)v1[10], "protected")
                || !strcmp((const char *)v1[10], "public") )
              {
                goto LABEL_198;
              }
              if ( !v1[18] || strcmp((const char *)v1[10], "pixelshader") )
                goto LABEL_80;
              return 283;
            case 'r':
              if ( !strcmp((const char *)v1[10], "register") )
                return 284;
              if ( !strcmp((const char *)v1[10], "reinterpret_cast") )
                goto LABEL_198;
              if ( !strcmp((const char *)v1[10], "row_major") )
                return 286;
              if ( strcmp((const char *)v1[10], "return") )
                goto LABEL_80;
              return 285;
            case 's':
              if ( !strcmp((const char *)v1[10], "sampler1D") )
                return 288;
              if ( !strcmp((const char *)v1[10], "sampler2D") )
                return 289;
              if ( !strcmp((const char *)v1[10], "sampler3D") )
                return 290;
              if ( !strcmp((const char *)v1[10], "samplerCUBE") )
                return 291;
              if ( !strcmp((const char *)v1[10], "sampler_state") )
                return 292;
              if ( !strcmp((const char *)v1[10], "shared") )
                return 293;
              if ( !strcmp((const char *)v1[10], "short")
                || !strcmp((const char *)v1[10], "signed")
                || !strcmp((const char *)v1[10], "sizeof") )
              {
                goto LABEL_198;
              }
              if ( !strcmp((const char *)v1[10], "stateblock_state") )
                return 295;
              if ( !strcmp((const char *)v1[10], "static") )
                return 296;
              if ( !strcmp((const char *)v1[10], "static_cast") )
                goto LABEL_198;
              if ( !strcmp((const char *)v1[10], "string") )
                return 297;
              if ( !strcmp((const char *)v1[10], "struct") )
                return 298;
              if ( !strcmp((const char *)v1[10], "switch") )
                goto LABEL_198;
              v1 = this;
              if ( !this[18] )
                goto LABEL_80;
              if ( !strcmp(v16, "sampler") )
                return 287;
              if ( strcmp(v16, "stateblock") )
                goto LABEL_80;
              return 294;
            case 't':
              if ( !strcmp((const char *)v1[10], "template") )
                goto LABEL_198;
              if ( !strcmp((const char *)v1[10], "texture1D") )
                return 301;
              if ( !strcmp((const char *)v1[10], "texture2D") )
                return 302;
              if ( !strcmp((const char *)v1[10], "texture3D") )
                return 303;
              if ( !strcmp((const char *)v1[10], "textureCUBE") )
                return 304;
              if ( !strcmp((const char *)v1[10], "this") || !strcmp((const char *)v1[10], "throw") )
                goto LABEL_198;
              if ( !strcmp((const char *)v1[10], "true") )
                return 305;
              if ( !strcmp((const char *)v1[10], (const char *)&off_7419E8) )
                goto LABEL_198;
              if ( !strcmp((const char *)v1[10], "typedef") )
                return 306;
              if ( !strcmp((const char *)v1[10], "typename") )
                goto LABEL_198;
              if ( !v1[18] || strcmp((const char *)v1[10], "texture") )
                goto LABEL_80;
              return 300;
            case 'u':
              if ( !strcmp((const char *)v1[10], "uniform") )
                return 307;
              if ( !strcmp((const char *)v1[10], "union") || !strcmp((const char *)v1[10], "unsigned") )
                goto LABEL_198;
              v17 = "using";
LABEL_53:
              v19 = 6;
LABEL_54:
              if ( !memcmp((const void *)v1[10], v17, v19) )
                goto LABEL_198;
              goto LABEL_80;
            case 'v':
              if ( !strcmp((const char *)v1[10], "vector") )
                return 308;
              if ( !strcmp((const char *)v1[10], "vertexfragment") )
                return 309;
              if ( !strcmp((const char *)v1[10], "virtual") )
                goto LABEL_198;
              if ( !strcmp((const char *)v1[10], "void") )
                return 311;
              if ( !strcmp((const char *)v1[10], "volatile") )
                return 312;
              if ( v1[18] && !strcmp((const char *)v1[10], "vertexshader") )
                return 310;
LABEL_80:
              v18 = sub_635155(*v16);
              switch ( v18 )
              {
                case 'a':
                  if ( !_stricmp((const char *)v1[10], off_72D0FC) )
                    return 257;
                  break;
                case 'd':
                  if ( !_stricmp((const char *)v1[10], "decl") )
                    return 264;
                  break;
                case 'p':
                  if ( !_stricmp((const char *)v1[10], "pass") )
                    return 281;
                  break;
                default:
                  if ( v18 == 116 && !_stricmp((const char *)v1[10], "technique") )
                    return 299;
                  break;
              }
              result = (sub_69974C(v1, 0, (const char **)v1 + 8, 0, 0, v1[4], 0, 0, 0) != 0) + 335;
              break;
            case 'w':
              if ( strcmp((const char *)v1[10], "while") )
                goto LABEL_80;
              return 313;
            default:
              goto LABEL_80;
          }
          return result;
        case 0xA:
          return 334;
        case 0xD:
          return -1;
        default:
          continue;
      }
    }
    else
    {
      v1[16] = 1;
      return -1;
    }
    return result;
  }
}
