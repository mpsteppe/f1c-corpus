int __thiscall sub_69974C(void *this, int a2, const char **a3, int a4, int a5, int a6, int a7, int *a8, int **a9)
{
  int *v9; // esi
  int v10; // eax
  bool i; // zf
  _DWORD *v12; // esi
  unsigned int v13; // ebx
  bool v14; // zf
  unsigned int v15; // eax
  int v16; // eax
  int j; // eax
  int v18; // eax
  int v19; // edi
  int v20; // esi
  unsigned int v21; // ebx
  int v22; // edx
  int v24; // eax
  int v25; // edi
  int **v26; // esi
  _DWORD *v27; // eax
  int *v28; // eax
  _DWORD *v29; // eax
  _DWORD *v30; // eax
  int v31; // edi
  _DWORD *v32; // eax
  _DWORD *v33; // eax
  bool v34; // zf
  _DWORD *v35; // eax
  _DWORD *v36; // eax
  int *v37; // edi
  int v38; // esi
  _DWORD *v39; // eax
  const char *v40; // ebx
  unsigned int v41; // eax
  int v42; // esi
  char *v43; // ebx
  unsigned int v44; // eax
  int v45; // ecx
  const char *v46; // edi
  const char *v47; // esi
  bool v48; // zf
  _DWORD *v49; // eax
  _DWORD *v50; // eax
  char v51; // al
  _DWORD *v52; // eax
  _DWORD *v53; // eax
  _DWORD *v54; // esi
  _DWORD *v55; // eax
  _DWORD *v56; // eax
  _DWORD *v57; // eax
  _DWORD *v58; // eax
  int v59; // [esp-4h] [ebp-120h]
  int v60; // [esp-4h] [ebp-120h]
  int v61; // [esp-4h] [ebp-120h]
  _DWORD v62[64]; // [esp+Ch] [ebp-110h]
  int v63; // [esp+10Ch] [ebp-10h]
  unsigned int v64; // [esp+110h] [ebp-Ch]
  unsigned int v65; // [esp+114h] [ebp-8h]
  int v66; // [esp+118h] [ebp-4h]

  v9 = a8;
  v66 = (int)this;
  if ( a8 )
    *a8 = 0;
  if ( a9 )
    *a9 = 0;
  v64 = -1;
  v65 = 0;
  if ( a6 )
  {
    while ( 2 )
    {
      if ( v64 )
      {
        v10 = sub_694E5E((int)a3, a6);
        for ( i = v10 == 0; ; i = v10 == 0 )
        {
          v63 = v10;
          if ( i || !v64 )
            break;
          v12 = *(_DWORD **)(v63 + 8);
          if ( a2 != v12[4] )
          {
            if ( (a7 & 5) != 0 )
              sub_694B97(
                v66,
                (int)a3,
                3005,
                "'%s': identifier represents a %s, not a %s",
                a3[2],
                off_7417A8[v12[4]],
                off_7417A8[a2]);
            if ( a8 )
              *a8 = 0;
            return -2147467259;
          }
          v13 = 0;
          if ( (a7 & 4) != 0 )
            v13 = sub_698115((void *)v66, v12[6], a4, a5, a7);
          if ( (a7 & 8) != 0 )
            v13 += sub_6969D2((void *)v66, v12[6], a4, a5, a7);
          if ( v13 != -1 )
          {
            v14 = v13 == v64;
            if ( v13 < v64 )
            {
              v65 = 0;
              v64 = v13;
              v14 = 1;
            }
            if ( v14 && v65 < 0x40 )
            {
              v15 = v65++;
              v62[v15] = v12;
            }
            if ( !v64 && v12[11] && !v12[10] )
            {
              v16 = *(_DWORD *)(a6 + 32);
              if ( v16 && *(_DWORD *)(v16 + 16) == 4 )
              {
                for ( j = sub_694E5E((int)a3, *(_DWORD *)(a6 + 32)); j; j = *(_DWORD *)(j + 12) )
                {
                  if ( !*(_DWORD *)(*(_DWORD *)(j + 8) + 44) )
                  {
                    sub_694BED(
                      v66,
                      (int)a3,
                      (const char *)0xC06,
                      "'%s': loop control variable used outside for-loop scope conflicts with a previous declaration in t"
                      "he outer scope; most recent definition used",
                      a3[2]);
                    v12[10] = 1;
                    break;
                  }
                }
              }
              v18 = v63;
              while ( 1 )
              {
                v18 = *(_DWORD *)(v18 + 12);
                if ( !v18 )
                  break;
                if ( !*(_DWORD *)(*(_DWORD *)(v18 + 8) + 44) )
                {
                  sub_694BED(
                    v66,
                    (int)a3,
                    (const char *)0xC06,
                    "'%s': loop control variable used outside for-loop scope conflicts with a previous declaration in the"
                    " outer scope; most recent definition used",
                    a3[2]);
                  v12[10] = 1;
                  break;
                }
              }
            }
          }
          v10 = *(_DWORD *)(v63 + 12);
        }
        a6 = *(_DWORD *)(a6 + 32);
        if ( a6 )
          continue;
      }
      break;
    }
    if ( v64 != -1 )
    {
      v19 = v62[0];
      if ( (a7 & 4) != 0 )
      {
        v20 = *(_DWORD *)(v62[0] + 24);
        v21 = 1;
        if ( v65 > 1 )
        {
          do
          {
            if ( !sub_695259(*(_DWORD **)(v20 + 32), *(_DWORD **)(*(_DWORD *)(v62[v21] + 24) + 32)) )
              break;
            if ( sub_6969D2((void *)v66, v20, *(_DWORD *)(v20 + 28), *(_DWORD *)(v22 + 36), 0) == -1 )
              break;
            ++v21;
          }
          while ( v21 < v65 );
          if ( v21 < v65 )
            sub_694B97(v66, (int)a3, 3067, "'%s': ambiguous function call", a3[2]);
        }
      }
      if ( !a8 )
        goto LABEL_57;
      if ( (a7 & 2) != 0 )
      {
        *a8 = *(_DWORD *)(v19 + 24);
        goto LABEL_57;
      }
      if ( !*(_DWORD *)(v19 + 24) || (v24 = sub_67ECC3(*(_DWORD *)(v19 + 24)), (*a8 = v24) != 0) )
      {
LABEL_57:
        v25 = 0;
        if ( a9 )
        {
          a8 = 0;
          v26 = &a8;
          if ( v65 )
          {
            do
            {
              v27 = (_DWORD *)sub_65B229(20);
              v28 = v27 ? sub_67ED1B(v27, 0, 0, (int)"Values") : 0;
              *v26 = v28;
              if ( !v28 )
                return -2147024882;
              v29 = (_DWORD *)sub_65B229(64);
              v30 = v29 ? sub_67F780(v29, 2, *(_DWORD *)(v62[v25] + 36), a3) : 0;
              (*v26)[2] = (int)v30;
              if ( !v30 )
                return -2147024882;
              v26 = (int **)(*v26 + 3);
            }
            while ( ++v25 < v65 );
          }
          *a9 = a8;
        }
        return 0;
      }
      return -2147024882;
    }
    v9 = a8;
  }
  if ( (a7 & 2) == 0 && !a9 )
  {
    if ( a2 )
    {
      if ( a2 == 1 && !strcmp(a3[2], (const char *)&dword_72D144) )
      {
        if ( a8 )
        {
          v53 = (_DWORD *)sub_65B229(64);
          if ( v53 )
            v54 = sub_67F449(v53);
          else
            v54 = 0;
          if ( !v54 )
            return -2147024882;
          v54[5] = 1;
          v54[6] = 0;
          v54[7] = 514;
          v55 = (_DWORD *)sub_65B229(36);
          v56 = v55 ? sub_67F2D4(v55, 3, 13, 1, 1, 512) : 0;
          v54[8] = v56;
          if ( !v56 )
            return -2147024882;
          v57 = (_DWORD *)sub_65B229(64);
          v58 = v57 ? sub_67F7B5(v57, 5, 0, 0, a3) : 0;
          v54[9] = v58;
          if ( !v58 )
            return -2147024882;
          *a8 = (int)v54;
        }
        return 0;
      }
    }
    else
    {
      if ( !_stricmp(a3[2], "dword") )
      {
        v59 = 4;
        goto LABEL_77;
      }
      if ( !_stricmp(a3[2], "float") )
      {
        v59 = 11;
LABEL_77:
        v31 = v59;
        if ( !v9 )
          return 0;
        v32 = (_DWORD *)sub_65B229(36);
        if ( v32 )
        {
          v33 = sub_67F2D4(v32, 0, v31, 1, 1, 0);
LABEL_81:
          *v9 = (int)v33;
LABEL_82:
          v34 = v33 == 0;
          goto LABEL_83;
        }
LABEL_80:
        v33 = 0;
        goto LABEL_81;
      }
      if ( !_stricmp(a3[2], "vector") )
      {
        if ( !v9 )
          return 0;
        v35 = (_DWORD *)sub_65B229(36);
        if ( v35 )
        {
          v33 = sub_67F2D4(v35, 1, 11, 1, 4, 0);
          goto LABEL_81;
        }
        goto LABEL_80;
      }
      if ( !_stricmp(a3[2], "matrix") )
      {
        if ( !v9 )
          return 0;
        v36 = (_DWORD *)sub_65B229(36);
        if ( v36 )
        {
          v33 = sub_67F2D4(v36, 2, 11, 4, 4, 0);
          goto LABEL_81;
        }
        goto LABEL_80;
      }
      if ( !_stricmp(a3[2], "string") )
      {
        v60 = 14;
LABEL_101:
        v37 = a8;
        v38 = v60;
        if ( !a8 )
          return 0;
        v39 = (_DWORD *)sub_65B229(36);
        if ( v39 )
          v33 = sub_67F2D4(v39, 3, v38, 1, 1, 0);
        else
          v33 = 0;
        *v37 = (int)v33;
        goto LABEL_82;
      }
      if ( !_stricmp(a3[2], "texture") )
      {
        v60 = 15;
        goto LABEL_101;
      }
      if ( !_stricmp(a3[2], "pixelshader") )
      {
        v60 = 25;
        goto LABEL_101;
      }
      if ( !_stricmp(a3[2], "vertexshader") )
      {
        v60 = 26;
        goto LABEL_101;
      }
      v40 = a3[2];
      v41 = strlen(v40);
      if ( v41 >= 4 && *(_DWORD *)v40 == *(_DWORD *)"bool" )
      {
        v42 = 0;
        v43 = (char *)(v40 + 4);
        v44 = v41 - 4;
      }
      else
      {
        if ( v41 >= 3 && !memcmp(a3[2], &off_7413EC, 3u) )
        {
          v43 = (char *)(v40 + 3);
          v61 = 4;
          v44 = v41 - 3;
        }
        else if ( v41 >= 4 && *(_DWORD *)v40 == *(_DWORD *)"half" )
        {
          v43 = (char *)(v40 + 4);
          v61 = 10;
          v44 = v41 - 4;
        }
        else if ( v41 >= 5 && !memcmp(a3[2], "float", 5u) )
        {
          v43 = (char *)(v40 + 5);
          v61 = 11;
          v44 = v41 - 5;
        }
        else
        {
          if ( v41 < 6 )
            goto LABEL_160;
          v45 = 3;
          v46 = "double";
          v47 = a3[2];
          v48 = 1;
          do
          {
            if ( !v45 )
              break;
            v48 = *(_WORD *)v47 == *(_WORD *)v46;
            v47 += 2;
            v46 += 2;
            --v45;
          }
          while ( v48 );
          if ( !v48 )
            goto LABEL_160;
          v43 = (char *)(v40 + 6);
          v61 = 12;
          v44 = v41 - 6;
        }
        v42 = v61;
      }
      if ( v44 == 1 )
      {
        if ( *v43 >= 49 && *v43 < 53 )
        {
          if ( !a8 )
            return 0;
          v49 = (_DWORD *)sub_65B229(36);
          if ( v49 )
          {
            v50 = sub_67F2D4(v49, 1, v42, 1, *v43 - 48, 0);
LABEL_141:
            *a8 = (int)v50;
            v34 = v50 == 0;
LABEL_83:
            if ( v34 )
              return -2147024882;
            return 0;
          }
          goto LABEL_140;
        }
      }
      else if ( v44 == 3 && *v43 >= 49 && *v43 < 53 && v43[1] == 120 )
      {
        v51 = v43[2];
        if ( v51 >= 49 && v51 < 53 )
        {
          if ( !a8 )
            return 0;
          v52 = (_DWORD *)sub_65B229(36);
          if ( v52 )
          {
            v50 = sub_67F2D4(v52, 2, v42, *v43 - 48, v43[2] - 48, 0);
            goto LABEL_141;
          }
LABEL_140:
          v50 = 0;
          goto LABEL_141;
        }
      }
    }
  }
LABEL_160:
  if ( (a7 & 1) != 0 )
    sub_694B97(v66, (int)a3, 3004, "undeclared identifier '%s'", a3[2]);
  return 1;
}
