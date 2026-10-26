int __thiscall sub_65F931(char *Format, _DWORD *a2)
{
  unsigned int v2; // kr00_4
  __int32 v3; // esi
  char *v4; // esi
  int v6; // eax
  int v7; // eax
  int result; // eax
  _DWORD *v9; // ebx
  int v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  _DWORD *v14; // ebx
  int v15; // eax
  int *v16; // ebx
  int v17; // ecx
  int v18; // eax
  int v19; // eax
  int v20; // ebx
  int v21; // eax
  int v22; // eax
  int *v23; // ecx
  int v24; // edx
  bool v25; // zf
  int v26; // eax
  int v27; // eax
  int v28; // eax
  _DWORD *v29; // ecx
  int v30; // eax
  unsigned int v31; // eax
  _DWORD *v32; // ecx
  _DWORD *v33; // ecx
  int v34; // ecx
  int *v35; // ebx
  int v36; // ecx
  int v37; // edx
  double v38; // st7
  int v39; // ecx
  int *v40; // ebx
  int v41; // ecx
  _DWORD *v42; // eax
  int v43; // ecx
  unsigned int v44; // ecx
  _DWORD *v45; // eax
  char *v46; // [esp+0h] [ebp-1Ch] BYREF
  int v47; // [esp+10h] [ebp-Ch]
  int v48; // [esp+14h] [ebp-8h]
  int v49; // [esp+18h] [ebp-4h]
  unsigned int v50; // [esp+24h] [ebp+8h]
  unsigned int v51; // [esp+24h] [ebp+8h]
  unsigned int v52; // [esp+24h] [ebp+8h]
  unsigned int v53; // [esp+24h] [ebp+8h]

  v4 = Format;
  a2[22] = 4 * *((_DWORD *)Format + 23);
  v6 = a2[12];
  v49 = 1;
  v48 = 0;
  if ( v6 == 31 )
    v49 = 2;
  if ( *((_DWORD *)Format + 30) )
  {
    if ( v6 == 26 || v6 == 25 || v6 == 28 || v6 == 30 )
    {
      sub_65DD1F(
        *(_DWORD **)Format,
        (int)(a2 + 4),
        2025,
        "call, callnz, label, and ret instructions are not allowed in assembly fragments");
      return -2147467259;
    }
    if ( v6 == 20 || v6 == 21 || v6 == 22 || v6 == 23 || v6 == 24 )
    {
      v7 = a2[18];
      if ( v7 )
      {
        if ( !*(_DWORD *)(v7 + 16) )
        {
          sub_65DD1F(
            *(_DWORD **)Format,
            (int)(a2 + 4),
            2026,
            "Matrices cannot be specified in temp registers with the fragment linker");
          return -2147467259;
        }
      }
    }
  }
  v9 = (_DWORD *)a2[15];
  if ( v9 && v9[1] == 19 )
  {
    ++v49;
    if ( v9[4] == -1 )
      v48 = 1;
    if ( v9[5] )
    {
      sub_65DD1F(*(_DWORD **)Format, (int)(a2 + 4), 2014, "source modifiers are not allowed on destination parameters");
      *((_DWORD *)v4 + 19) = 1;
    }
    v10 = v9[10];
    if ( v10 )
    {
      v11 = *((_DWORD *)v4 + 14);
      if ( v11 < 4 || v11 > 5 )
      {
        sub_65DD1F(
          *(_DWORD **)v4,
          (int)(a2 + 4),
          2008,
          "relative addressing of destination parameters is not supported in this shader version");
        *((_DWORD *)v4 + 19) = 1;
      }
      else
      {
        if ( *(_DWORD *)(v10 + 16) == -1 )
          v48 = 1;
        if ( *(_DWORD *)(v10 + 40) )
        {
          sub_65DD1F(
            *(_DWORD **)v4,
            (int)(a2 + 4),
            2009,
            "only one address register reference is allowed in a relative address expression");
          *((_DWORD *)v4 + 19) = 1;
        }
        ++v49;
      }
    }
  }
  v12 = a2[16];
  if ( v12 && *(_DWORD *)(v12 + 4) == 19 )
  {
    v13 = *((_DWORD *)v4 + 14);
    if ( (unsigned int)v13 < 2 || v13 >= 6 && v13 <= 10 )
    {
      sub_65DD1F(*(_DWORD **)v4, (int)(a2 + 4), 2021, "predicates are not supported in this shader version");
      *((_DWORD *)v4 + 19) = 1;
    }
    v14 = (_DWORD *)a2[16];
    ++v49;
    if ( v14[4] == -1 )
      v48 = 1;
    v15 = v14[5];
    if ( v15 && v15 != 218103808 )
    {
      sub_65DD1F(*(_DWORD **)v4, (int)(a2 + 4), 2019, "source modifiers are not allowed on predicates");
      *((_DWORD *)v4 + 19) = 1;
    }
    if ( v14[10] )
    {
      sub_65DD1F(
        *(_DWORD **)v4,
        (int)(a2 + 4),
        2020,
        "relative addressing of predicates is not supported in this shader version");
      *((_DWORD *)v4 + 19) = 1;
    }
  }
  v50 = 0;
  v16 = a2 + 17;
  do
  {
    v17 = *v16;
    if ( !*v16 )
      break;
    v18 = a2[12];
    ++v49;
    if ( v18 != 81 && v18 != 48 && v18 != 47 )
    {
      if ( *(_DWORD *)(v17 + 16) == -1 )
        v48 = 1;
      v19 = *(_DWORD *)(v17 + 40);
      if ( v19 )
      {
        if ( *(_DWORD *)(v19 + 16) == -1 )
          v48 = 1;
        if ( *(_DWORD *)(v19 + 40) )
        {
          sub_65DD1F(
            *(_DWORD **)v4,
            (int)(a2 + 4),
            2009,
            "only one address register reference is allowed in a relative address expression");
          *((_DWORD *)v4 + 19) = 1;
        }
        if ( *((_DWORD *)v4 + 14) )
          ++v49;
      }
    }
    ++v50;
    ++v16;
  }
  while ( v50 < 4 );
  result = sub_65F877((int)v4, v49);
  if ( result >= 0 )
  {
    v20 = a2[12];
    v47 = v49 + *((_DWORD *)v4 + 23);
    if ( v20 != 3 )
      goto LABEL_90;
    v21 = *((_DWORD *)v4 + 14);
    if ( (unsigned int)v21 >= 6 && (v21 < 10 || v21 > 14) )
      goto LABEL_90;
    v22 = a2[18];
    v23 = *(int **)(v22 + 20);
    v24 = 117440512;
    v20 = 2;
    if ( (unsigned int)v23 > 0x7000000 )
    {
      if ( v23 != (int *)0x8000000 )
      {
        if ( v23 == (int *)150994944 || v23 == (int *)167772160 )
          goto LABEL_76;
        v24 = 184549376;
        if ( v23 == (int *)184549376 )
        {
          *(_DWORD *)(v22 + 20) = 201326592;
          goto LABEL_90;
        }
        if ( v23 != (int *)201326592 )
        {
          v25 = v23 == (int *)218103808;
LABEL_75:
          if ( !v25 )
          {
LABEL_90:
            if ( a2[21] )
              v20 |= 0x40000000u;
            if ( a2[16] )
              v20 |= 0x10000000u;
            v26 = *((_DWORD *)v4 + 14);
            if ( v26 >= 1 && v26 <= 5 || v26 >= 10 && v26 <= 14 )
              v20 |= (v49 - 1) << 24;
            v27 = a2[12];
            if ( v27 == 41 || v27 == 45 || v27 == 94 )
              v20 |= (a2[14] & 7) << 16;
            *(_DWORD *)(*((_DWORD *)v4 + 22) + 4 * (*((_DWORD *)v4 + 23))++) = v20;
            v28 = *((_DWORD *)v4 + 23);
            if ( a2[12] == 31 )
            {
              *(_DWORD *)(*((_DWORD *)v4 + 22) + 4 * v28) = a2[14] | 0x80000000;
              v28 = ++*((_DWORD *)v4 + 23);
            }
            v29 = (_DWORD *)a2[15];
            if ( v29 && v29[1] == 19 )
            {
              if ( !*((_DWORD *)v4 + 14) && v29[8] == 983040 )
              {
                v30 = a2[12];
                if ( v30 == 21 || v30 == 23 )
                {
                  v29[8] = 458752;
                }
                else if ( v30 == 24 )
                {
                  v29[8] = 196608;
                }
              }
              v31 = v29[8] & 0xF0000
                  | v29[6] & 0x7FF
                  | a2[13] & 0xFF00000
                  | ((v29[4] & 0x18 | ((v29[4] | 0xFFFFFFF8) << 20)) << 8);
              if ( v29[10] )
                v31 |= 0x2000u;
              *(_DWORD *)(*((_DWORD *)v4 + 22) + 4 * (*((_DWORD *)v4 + 23))++) = v31;
              v32 = (_DWORD *)v29[10];
              v28 = *((_DWORD *)v4 + 23);
              if ( v32 )
              {
                *(_DWORD *)(*((_DWORD *)v4 + 22) + 4 * v28) = (unsigned int)dword_FF0000 & v32[9]
                                                            | v32[6] & 0x7FF
                                                            | v32[5] & 0xF000000
                                                            | ((v32[4] & 0x18 | ((v32[4] | 0xFFFFFFF8) << 20)) << 8);
                v28 = ++*((_DWORD *)v4 + 23);
              }
            }
            v33 = (_DWORD *)a2[16];
            if ( v33 && v33[1] == 19 )
            {
              *(_DWORD *)(*((_DWORD *)v4 + 22) + 4 * v28) = (unsigned int)dword_FF0000 & v33[9]
                                                          | v33[6] & 0x7FF
                                                          | v33[5] & 0xF000000
                                                          | ((v33[4] & 0x18 | ((v33[4] | 0xFFFFFFF8) << 20)) << 8);
              v28 = ++*((_DWORD *)v4 + 23);
            }
            v34 = a2[12];
            switch ( v34 )
            {
              case 'Q':
                v51 = 0;
                v35 = a2 + 17;
                do
                {
                  v36 = *v35;
                  if ( !*v35 )
                    break;
                  v37 = *(_DWORD *)(v36 + 16);
                  if ( v37 >= 5 && v37 <= 8 )
                  {
                    v38 = *(double *)(v36 + 24);
                    v39 = *((_DWORD *)v4 + 22);
                    *(float *)&v49 = v38;
                    *(float *)(v39 + 4 * v28) = *(float *)&v49;
                  }
                  ++*((_DWORD *)v4 + 23);
                  ++v51;
                  v28 = *((_DWORD *)v4 + 23);
                  ++v35;
                }
                while ( v51 < 4 );
                break;
              case '0':
                v52 = 0;
                v40 = a2 + 17;
                do
                {
                  v41 = *v40;
                  if ( !*v40 )
                    break;
                  if ( *(_DWORD *)(v41 + 16) == 2 || *(_DWORD *)(v41 + 16) == 4 )
                    *(_DWORD *)(*((_DWORD *)v4 + 22) + 4 * v28) = *(_DWORD *)(v41 + 24);
                  ++*((_DWORD *)v4 + 23);
                  ++v52;
                  v28 = *((_DWORD *)v4 + 23);
                  ++v40;
                }
                while ( v52 < 4 );
                break;
              case '/':
                *(_DWORD *)(*((_DWORD *)v4 + 22) + 4 * v28) = *(_DWORD *)(a2[17] + 24) != 0;
                ++*((_DWORD *)v4 + 23);
                break;
              default:
                v53 = 0;
                v49 = (int)(a2 + 17);
                do
                {
                  v42 = *(_DWORD **)v49;
                  if ( !*(_DWORD *)v49 )
                    break;
                  if ( !*((_DWORD *)v4 + 14) && (_UNKNOWN *)v42[9] == &unk_E40000 )
                  {
                    v43 = a2[12];
                    if ( v43 == 6 || v43 == 7 || v43 == 14 || v43 == 78 || v43 == 15 || v43 == 79 )
                      v42[9] = dword_FF0000;
                  }
                  v44 = (unsigned int)dword_FF0000 & v42[9]
                      | v42[6] & 0x7FF
                      | v42[5] & 0xF000000
                      | ((v42[4] & 0x18 | ((v42[4] | 0xFFFFFFF8) << 20)) << 8);
                  if ( v42[10] )
                    v44 |= 0x2000u;
                  *(_DWORD *)(*((_DWORD *)v4 + 22) + 4 * (*((_DWORD *)v4 + 23))++) = v44;
                  v45 = (_DWORD *)v42[10];
                  if ( v45 )
                  {
                    if ( *((_DWORD *)v4 + 14) )
                    {
                      *(_DWORD *)(*((_DWORD *)v4 + 22) + 4 * (*((_DWORD *)v4 + 23))++) = (unsigned int)dword_FF0000
                                                                                       & v45[9]
                                                                                       | v45[6] & 0x7FF
                                                                                       | v45[5] & 0xF000000
                                                                                       | ((v45[4] & 0x18
                                                                                         | ((v45[4] | 0xFFFFFFF8) << 20)) << 8);
                    }
                    else if ( v45[4] != 3 || v45[5] || v45[6] || v45[9] )
                    {
                      sub_65DD1F(
                        *(_DWORD **)v4,
                        (int)(a2 + 4),
                        2007,
                        "only a0.x is allowed as a relative address register in vs_1_1");
                      *((_DWORD *)v4 + 19) = 1;
                    }
                  }
                  ++v53;
                  v49 += 4;
                }
                while ( v53 < 4 );
                break;
            }
            if ( *((_DWORD *)v4 + 23) != v47 )
            {
              v46 = v4;
              v2 = __readeflags();
              v3 = dword_16C6D20 - 1333723501;
              __writeeflags(v2);
              v4 = (char *)_InterlockedExchange((volatile __int32 *)&v46, v3);
              sub_65DD1F(*(_DWORD **)v4, (int)(a2 + 4), 0, v46);
              *((_DWORD *)v4 + 19) = 1;
            }
            if ( v48 )
            {
              *((_DWORD *)v4 + 25) = *((_DWORD *)v4 + 23);
            }
            else if ( sub_65F822(v4, (int)(a2 + 4)) < 0 )
            {
              *((_DWORD *)v4 + 20) = 1;
            }
            return 0;
          }
LABEL_76:
          sub_65DD1F(*(_DWORD **)v4, (int)(a2 + 4), 2013, "source modifiers incompatible with SUB instruction");
          *((_DWORD *)v4 + 19) = 1;
          goto LABEL_90;
        }
      }
    }
    else
    {
      if ( v23 == (int *)117440512 )
      {
        *(_DWORD *)(v22 + 20) = 0x8000000;
        goto LABEL_90;
      }
      if ( !v23 )
      {
        *(_DWORD *)(v22 + 20) = &dword_1000000;
        goto LABEL_90;
      }
      if ( v23 == &dword_1000000 )
      {
        *(_DWORD *)(v22 + 20) = 0;
        goto LABEL_90;
      }
      v24 = (int)&dword_2000000;
      if ( v23 == &dword_2000000 )
      {
        *(_DWORD *)(v22 + 20) = 50331648;
        goto LABEL_90;
      }
      if ( v23 != (int *)50331648 )
      {
        v24 = 0x4000000;
        if ( v23 == (int *)0x4000000 )
        {
          *(_DWORD *)(v22 + 20) = 83886080;
          goto LABEL_90;
        }
        if ( v23 != (int *)83886080 )
        {
          v25 = v23 == (int *)100663296;
          goto LABEL_75;
        }
      }
    }
    *(_DWORD *)(v22 + 20) = v24;
    goto LABEL_90;
  }
  return result;
}
