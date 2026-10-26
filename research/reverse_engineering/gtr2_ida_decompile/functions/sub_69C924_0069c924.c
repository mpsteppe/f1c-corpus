_DWORD *__thiscall sub_69C924(_DWORD *this, int a2, int a3, int a4, _DWORD *a5)
{
  int v5; // eax
  int v6; // ecx
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  _DWORD *v10; // eax
  _DWORD *v11; // esi
  int v12; // eax
  int v13; // ebx
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  _DWORD *v18; // eax
  int v19; // ebx
  _DWORD *v20; // eax
  _DWORD *v21; // edi
  int v22; // eax
  unsigned int v23; // ebx
  const void *v24; // edi
  int v25; // eax
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned int v28; // et2
  int v29; // eax
  int v30; // ecx
  int v31; // ecx
  _DWORD *v32; // eax
  int v33; // eax
  _DWORD *v34; // eax
  _DWORD *v35; // eax
  int *v36; // ecx
  _DWORD *v37; // eax
  _DWORD *v38; // eax
  _DWORD v40[6]; // [esp+18h] [ebp-48h]
  _DWORD v41[6]; // [esp+30h] [ebp-30h]
  int v42; // [esp+48h] [ebp-18h]
  int v43; // [esp+4Ch] [ebp-14h]
  int v44; // [esp+50h] [ebp-10h]
  _DWORD *v45; // [esp+54h] [ebp-Ch]
  int v46; // [esp+58h] [ebp-8h]
  int v47; // [esp+5Ch] [ebp-4h]
  unsigned int *v48; // [esp+6Ch] [ebp+Ch]
  _DWORD *v49; // [esp+6Ch] [ebp+Ch]
  int v50; // [esp+6Ch] [ebp+Ch]
  unsigned int v51; // [esp+70h] [ebp+10h]
  int v52; // [esp+70h] [ebp+10h]
  int v53; // [esp+70h] [ebp+10h]
  int *v54; // [esp+74h] [ebp+14h]
  int v55; // [esp+74h] [ebp+14h]
  _DWORD *v56; // [esp+74h] [ebp+14h]

  v47 = (int)this;
  v41[0] = "global variables";
  v41[1] = "structure members";
  v41[2] = "function parameters";
  v41[3] = "local variables";
  v41[4] = "loop control variables";
  v41[5] = "annotation members";
  v40[0] = "initial value";
  v40[1] = "initializer";
  v40[2] = "default value";
  v40[3] = "initial value";
  v40[4] = "initial value";
  v40[5] = "value";
  v5 = sub_694F8F(this);
  v42 = v5;
  if ( v5 && *(_DWORD *)(v6 + 16) && a2 )
  {
    v43 = *(_DWORD *)(v5 + 24);
    v7 = (_DWORD *)sub_65B229(20);
    v45 = v7 ? sub_67ED1B(v7, 0, 0, (int)"Stmts") : 0;
    if ( v45 )
    {
      v8 = (_DWORD *)sub_65B229(48);
      v9 = v8 ? sub_67F0EF(v8, 1, 0, 0, 0) : 0;
      v46 = (int)v9;
      if ( v9 )
      {
        v45[2] = v9;
        v10 = (_DWORD *)sub_65B229(64);
        v11 = v10 ? sub_67F449(v10) : 0;
        if ( v11 )
        {
          v9[6] = v11;
          if ( !a4 || (v12 = sub_67ECC3(a4), (v9[7] = v12) != 0) )
          {
            v13 = a3;
            if ( a3 )
            {
              v14 = sub_67ECC3(a3);
              v11[12] = v14;
              if ( v14 )
              {
                while ( 1 )
                {
                  v15 = *(_DWORD *)(v13 + 8);
                  if ( v15 )
                  {
                    if ( *(_DWORD *)(v15 + 4) == 3 )
                    {
                      v16 = sub_67ECC3(*(_DWORD *)(v13 + 8));
                      v11[11] = v16;
                      if ( !v16 )
                        break;
                    }
                  }
                  v13 = *(_DWORD *)(v13 + 12);
                  if ( !v13 )
                    goto LABEL_24;
                }
              }
              return 0;
            }
LABEL_24:
            if ( a5 && a5[1] != 13 )
              v11[9] = sub_6976A0((_DWORD *)v47, (_DWORD *)a2, (int)a5);
            v51 = 1;
            v48 = 0;
            v44 = 0;
            if ( !v43 || (v17 = sub_67ECC3(v43), (v11[8] = v17) != 0) )
            {
              if ( *(_DWORD *)(a2 + 4) != 3 )
              {
                while ( 1 )
                {
                  v18 = (_DWORD *)sub_65B229(24);
                  if ( v18 )
                    v19 = sub_67F23A(v18);
                  else
                    v19 = 0;
                  if ( !v19 )
                    return 0;
                  if ( v48 )
                    v44 = 3073;
                  *(_DWORD *)(v19 + 16) = v11[8];
                  v20 = *(_DWORD **)(a2 + 12);
                  v21 = (_DWORD *)(v19 + 20);
                  if ( !v20 )
                    break;
                  if ( sub_69BE34((_DWORD *)v47, v20, (_DWORD *)(v19 + 20)) < 0 )
                  {
                    v44 = 3058;
LABEL_40:
                    *v21 = 1;
                  }
                  v51 *= *v21;
                  v11[8] = v19;
                  a2 = *(_DWORD *)(a2 + 8);
                  if ( *(_DWORD *)(a2 + 4) == 3 )
                  {
                    v9 = (_DWORD *)v46;
                    goto LABEL_43;
                  }
                }
                v48 = (unsigned int *)(v19 + 20);
                goto LABEL_40;
              }
LABEL_43:
              v22 = sub_67ECC3(a2);
              v9[5] = v22;
              if ( v22 )
              {
                v23 = *(_DWORD *)(*(_DWORD *)(v47 + 16) + 16);
                v24 = (const void *)(a2 + 16);
                if ( v44 == 3058 )
                {
                  sub_694B97(
                    v47,
                    (int)v24,
                    3058,
                    "'%s': array dimensions must be literal scalar expressions",
                    *(_DWORD *)(a2 + 24));
                  return 0;
                }
                if ( v44 == 3073 )
                {
                  sub_694B97(
                    v47,
                    (int)v24,
                    3073,
                    "'%s': secondary array dimensions must be explicit",
                    *(_DWORD *)(a2 + 24));
                  return 0;
                }
                if ( v48 )
                {
                  if ( v23 && v23 != 3 && v23 != 4 && v23 != 5 )
                  {
                    sub_694B97(
                      v47,
                      (int)v24,
                      3072,
                      "'%s': array dimensions of %s must be explicit",
                      *(_DWORD *)(a2 + 24),
                      v41[v23]);
                    return 0;
                  }
                  v43 = v51 * sub_6951CB((_DWORD *)v47, (_DWORD *)v43);
                  if ( v43 )
                  {
                    v25 = v11[9];
                    if ( !v25 || *(_DWORD *)(v25 + 4) != 13 )
                    {
                      sub_694B97(v47, a2 + 16, 3074, "'%s': implicit array missing %s", *(_DWORD *)(a2 + 24), v40[v23]);
                      return 0;
                    }
                    v26 = sub_6951CB((_DWORD *)v47, *(_DWORD **)(v25 + 16));
                    v28 = v26 % v43;
                    v27 = v26 / v43;
                    if ( v28 )
                    {
                      sub_694B97(
                        v47,
                        a2 + 16,
                        3075,
                        "'%s': implicit array type does not match %s",
                        *(_DWORD *)(a2 + 24),
                        v40[v23]);
                      return 0;
                    }
                    *v48 = v27;
                    v51 *= v27;
                  }
                  else
                  {
                    *v48 = 0;
                    v51 = 0;
                  }
                }
                if ( !v51 || v51 > 0x10000 )
                {
                  sub_694B97(
                    v47,
                    a2 + 16,
                    3059,
                    "'%s': array dimension must be between 1 and 65536",
                    *(_DWORD *)(a2 + 24));
                  return 0;
                }
                v29 = sub_6951CB((_DWORD *)v47, (_DWORD *)v11[8]);
                v30 = v47;
                v11[5] = v29;
                v11[6] = *(_DWORD *)(*(_DWORD *)(v30 + 16) + 16);
                if ( *(_DWORD *)(*(_DWORD *)(v30 + 16) + 16) == 1 )
                {
                  v11[4] = -1;
                }
                else
                {
                  v31 = v47;
                  v11[4] = *(_DWORD *)(v47 + 88);
                  *(_DWORD *)(v31 + 88) += v29;
                }
                v52 = *(_DWORD *)(v42 + 16);
                if ( *(_DWORD *)(v42 + 20) )
                  sub_694B97(
                    v47,
                    a2 + 16,
                    3039,
                    "'%s': %s cannot be target specific",
                    *(const char **)(a2 + 24),
                    (const char *)v41[v23]);
                if ( (v52 & 0x100) != 0 )
                  sub_694B97(
                    v47,
                    a2 + 16,
                    3055,
                    "'%s': %s cannot be declared 'inline'",
                    *(const char **)(a2 + 24),
                    (const char *)v41[v23]);
                if ( v23 == 1 )
                {
                  if ( !sub_6950BD((_DWORD *)v47, (_DWORD *)v11[8]) )
                    goto LABEL_89;
                  sub_694B97(
                    v47,
                    a2 + 16,
                    3035,
                    "'%s': %s cannot be declared 'const'",
                    *(const char **)(a2 + 24),
                    "structure members");
                }
                if ( v23 == 2 )
                {
                  if ( (v52 & 0x10) != 0 || !sub_6950BD((_DWORD *)v47, (_DWORD *)v11[8]) )
                    goto LABEL_89;
                  sub_694B97(
                    v47,
                    a2 + 16,
                    3046,
                    "'%s': output paramaters cannot be declared 'const'",
                    *(const char **)(a2 + 24));
                }
                if ( (v23 == 3 || v23 == 4) && !sub_695154((_DWORD *)v47, (_DWORD *)v11[8]) )
                  sub_694B97(
                    v47,
                    a2 + 16,
                    3038,
                    "'%s': %s must be numeric",
                    *(const char **)(a2 + 24),
                    (const char *)v41[v23]);
                if ( !v23 )
                {
                  if ( (v52 & 2) == 0 )
                    goto LABEL_88;
                  if ( (v52 & 1) != 0 )
                  {
                    sub_694B97(
                      v47,
                      a2 + 16,
                      3007,
                      "'%s': extern %s cannot be declared 'static'",
                      *(const char **)(a2 + 24),
                      "global variables");
                    v52 &= ~2u;
                  }
                  if ( (v52 & 2) == 0 )
                    goto LABEL_88;
                  if ( (v52 & 0x40) != 0 )
                  {
                    sub_694B97(
                      v47,
                      a2 + 16,
                      3007,
                      "'%s': uniform %s cannot be declared 'static'",
                      *(const char **)(a2 + 24),
                      "global variables");
                    v52 &= ~2u;
                  }
                  if ( (v52 & 2) == 0 )
LABEL_88:
                    v52 |= 0x41u;
                  goto LABEL_103;
                }
LABEL_89:
                if ( (v52 & 2) != 0 && v23 != 3 && v23 != 4 )
                {
                  sub_694B97(
                    v47,
                    a2 + 16,
                    3007,
                    "'%s': %s cannot be declared 'static'",
                    *(const char **)(a2 + 24),
                    (const char *)v41[v23]);
                  v52 &= ~2u;
                }
                if ( (v52 & 0x40) != 0 )
                {
                  if ( v23 != 2 )
                  {
                    sub_694B97(
                      v47,
                      a2 + 16,
                      3047,
                      "'%s': %s cannot be declared 'uniform'",
                      *(const char **)(a2 + 24),
                      (const char *)v41[v23]);
                    v52 &= ~0x40u;
                  }
                  if ( (v52 & 0x40) != 0 && (v52 & 0x20) != 0 )
                  {
                    sub_694B97(
                      v47,
                      a2 + 16,
                      3062,
                      "'%s': %s cannot be declared 'uniform out'",
                      *(const char **)(a2 + 24),
                      (const char *)v41[v23]);
                    v52 &= ~0x40u;
                  }
                }
                if ( (v52 & 1) != 0 )
                {
                  sub_694B97(
                    v47,
                    a2 + 16,
                    3006,
                    "'%s': %s cannot be declared 'extern'",
                    *(const char **)(a2 + 24),
                    (const char *)v41[v23]);
                  v52 &= ~1u;
                }
                if ( (v52 & 8) != 0 )
                {
                  sub_694B97(
                    v47,
                    a2 + 16,
                    3054,
                    "'%s': %s cannot be declared 'shared'",
                    *(const char **)(a2 + 24),
                    (const char *)v41[v23]);
                  v52 &= ~8u;
                }
LABEL_103:
                if ( (v52 & 4) != 0 && v23 != 3 && v23 != 4 && v23 != 2 )
                {
                  sub_694B97(
                    v47,
                    a2 + 16,
                    3008,
                    "'%s': %s cannot be declared 'volatile'",
                    *(const char **)(a2 + 24),
                    (const char *)v41[v23]);
                  v52 &= ~4u;
                }
                if ( v23 == 5 )
                {
                  sub_694F9B((_DWORD *)v47, v11[8], 1);
                  v52 |= 0x40u;
                }
                v43 = 0;
                v11[7] = v52;
                if ( a5 )
                {
                  if ( a5[1] == 13 )
                  {
                    v32 = sub_699F10((int *)v47, v11[8], a5, 0, 0);
                  }
                  else
                  {
                    v33 = v11[9];
                    v49 = (_DWORD *)v33;
                    if ( v33 )
                      v54 = *(int **)(v33 + 16);
                    else
                      v54 = 0;
                    if ( v11[5] != sub_6951CB((_DWORD *)v47, v54) )
                    {
                      sub_696FEF((void *)v47, a2 + 16, *(const char **)(a2 + 24), (int *)v11[8], v54, 1);
                      v11[9] = 0;
                      goto LABEL_125;
                    }
                    v32 = sub_699F10((int *)v47, v11[8], v49, 0, 1);
                  }
                }
                else
                {
                  if ( v23 && v23 != 3 && v23 != 4 || (v52 & 2) == 0 )
                  {
LABEL_125:
                    if ( v11[9] )
                    {
                      if ( v23 == 1 )
                      {
                        sub_694B97(
                          v47,
                          a2 + 16,
                          3009,
                          "'%s': %s cannot have %ss",
                          *(_DWORD *)(a2 + 24),
                          "structure members",
                          "initializer");
LABEL_160:
                        v11[9] = 0;
                        goto LABEL_161;
                      }
                      if ( v23 == 2 && !sub_695154((_DWORD *)v47, (_DWORD *)v11[8]) )
                      {
                        sub_694B97(
                          v47,
                          a2 + 16,
                          3009,
                          "'%s': non-numeric uniform %s cannot have %ss",
                          *(_DWORD *)(a2 + 24),
                          "function parameters",
                          "default value");
                        goto LABEL_160;
                      }
                      v50 = v52 & 0x10;
                      if ( (v52 & 0x10) == 0 && (v52 & 0x20) != 0 )
                      {
                        sub_694B97(
                          v47,
                          a2 + 16,
                          3045,
                          "'%s': output only %s cannot have %ss",
                          *(const char **)(a2 + 24),
                          (const char *)v41[v23],
                          (const char *)v40[v23]);
LABEL_139:
                        v11[9] = 0;
                        goto LABEL_157;
                      }
                      v55 = v52 & 0x50;
                      if ( (v52 & 0x50) != 0 && !sub_695AC0((_DWORD *)v11[9]) )
                      {
                        sub_694B97(
                          v47,
                          a2 + 16,
                          3011,
                          "'%s': %s must be a literal expression",
                          *(const char **)(a2 + 24),
                          (const char *)v40[v23]);
                        goto LABEL_139;
                      }
                      if ( !sub_696CB7((void *)v47, (int *)v11[8], *(int **)(v11[9] + 16), 0) )
                      {
                        sub_696FEF(
                          (void *)v47,
                          a2 + 16,
                          *(const char **)(a2 + 24),
                          (int *)v11[8],
                          *(int **)(v11[9] + 16),
                          0);
                        goto LABEL_139;
                      }
                      v53 = v52 & 0x40;
                      if ( v53 )
                        v11[10] = sub_69BD09((_DWORD *)v47, (_DWORD *)v11[9]);
                      if ( v55 || !sub_6950BD((_DWORD *)v47, (_DWORD *)v11[8]) )
                      {
                        v34 = 0;
                        if ( v50 || !v53 )
                        {
                          v35 = (_DWORD *)v11[9];
                          v36 = (int *)v47;
                          v11[9] = 0;
                          v56 = v35;
                          v37 = sub_699E09(v36, a2, (int)v11);
                          v43 = (int)sub_69C457((char *)v47, 20, v37, v56, 1);
                          goto LABEL_157;
                        }
                      }
                      else
                      {
                        v34 = sub_69BD09((_DWORD *)v47, (_DWORD *)v11[9]);
                      }
                      v11[9] = v34;
                    }
                    else
                    {
                      if ( !v23 )
                      {
                        if ( !sub_6950BD((_DWORD *)v47, (_DWORD *)v11[8]) )
                          goto LABEL_161;
                        if ( (v52 & 2) != 0 )
                          goto LABEL_156;
                      }
                      if ( (v23 == 3 || v23 == 4) && sub_6950BD((_DWORD *)v47, (_DWORD *)v11[8]) || v23 == 5 )
LABEL_156:
                        sub_694B97(
                          v47,
                          a2 + 16,
                          3012,
                          "'%s': missing %s",
                          *(const char **)(a2 + 24),
                          (const char *)v40[v23]);
                    }
LABEL_157:
                    if ( v23 > 2 && v11[11] )
                    {
                      sub_694B97(
                        v47,
                        a2 + 16,
                        3043,
                        "'%s': %s cannot have semantics",
                        *(const char **)(a2 + 24),
                        (const char *)v41[v23]);
                      goto LABEL_160;
                    }
LABEL_161:
                    if ( *(_DWORD *)(v46 + 28) && v23 && v23 != 2 )
                    {
                      sub_694B97(
                        v47,
                        a2 + 16,
                        3040,
                        "'%s': %s cannot have annotations",
                        *(const char **)(a2 + 24),
                        (const char *)v41[v23]);
                      *(_DWORD *)(v46 + 28) = 0;
                    }
                    if ( sub_6961D0((_DWORD *)v47, v46, 0) >= 0 )
                    {
                      if ( !v43 )
                        return v45;
                      v38 = sub_695C26(v43);
                      v45[3] = v38;
                      if ( v38 )
                        return v45;
                    }
                    return 0;
                  }
                  v32 = sub_69741E((_DWORD *)v47, 5, 0, 0.0, v24);
                }
                v11[9] = v32;
                goto LABEL_125;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
