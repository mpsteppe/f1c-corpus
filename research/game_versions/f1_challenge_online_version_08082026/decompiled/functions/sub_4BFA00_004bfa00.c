int __thiscall sub_4BFA00(_DWORD *this, int a2, int a3)
{
  _DWORD *v3; // edi
  unsigned int v4; // ebp
  int v5; // esi
  char ***v6; // ecx
  unsigned int v7; // ebx
  int v8; // edi
  char *v9; // eax
  _DWORD *v10; // eax
  _DWORD *v11; // esi
  int v12; // eax
  int v13; // ebx
  char **v14; // eax
  char *v15; // eax
  int v16; // ecx
  float *v17; // eax
  float *v18; // esi
  int v19; // eax
  int v20; // esi
  _DWORD *v21; // eax
  int v22; // esi
  _DWORD *v23; // eax
  char ***v24; // eax
  bool v25; // cc
  int v26; // eax
  int v27; // ecx
  int i; // edx
  int v30; // [esp+Ch] [ebp-20h]
  int v32; // [esp+14h] [ebp-18h]
  int v33; // [esp+18h] [ebp-14h]
  char ***v34; // [esp+1Ch] [ebp-10h] BYREF
  char ***v35; // [esp+20h] [ebp-Ch]
  char ***v36; // [esp+24h] [ebp-8h]
  int v37; // [esp+28h] [ebp-4h]
  int v38; // [esp+34h] [ebp+8h]

  v3 = this;
  v4 = 0;
  v5 = 0;
  v30 = 0;
  v33 = 0;
  v32 = sub_5871F0(&unk_8AC36C);
  if ( v32 <= 0 )
    return 0;
  v7 = dword_8AC390;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  if ( dword_8AC390 )
  {
    while ( 1 )
    {
      v8 = v5 + dword_8AC394;
      v9 = *(char **)(v5 + dword_8AC394);
      if ( !v9 )
        v9 = byte_5EA438;
      if ( !sub_588410(v9, a3) )
        break;
      ++v4;
      v5 += 1060;
      if ( v4 >= v7 )
        goto LABEL_16;
    }
    v10 = (_DWORD *)sub_587C03(8);
    v11 = v10;
    if ( v10 )
    {
      *v10 = 0;
      v10[1] = -1;
      sub_566650(v8 + 124);
      v12 = sub_587C03(12);
      if ( v12 )
      {
        *(_DWORD *)v12 = v11;
        *(_DWORD *)(v12 + 4) = 0;
        *(_BYTE *)(v12 + 8) = 1;
      }
      else
      {
        v12 = 0;
      }
      v6 = v34;
      if ( v34 )
      {
        v35[1] = (char **)v12;
      }
      else
      {
        v34 = (char ***)v12;
        v36 = (char ***)v12;
      }
      v35 = (char ***)v12;
      ++v37;
    }
LABEL_16:
    v3 = this;
  }
  v38 = 2 * sub_5884ED(v6) % v32;
  if ( a2 > 0 )
  {
    do
    {
      v13 = sub_4C5070(v38);
      v36 = v34;
      if ( v34 && (v14 = *v34) != 0 )
      {
        while ( 1 )
        {
          v15 = *v14;
          if ( !v15 )
            v15 = byte_5EA438;
          if ( !sub_588410(v13 + 124, v15) )
            break;
          if ( v36 )
          {
            v36 = (char ***)v36[1];
            if ( v36 )
            {
              v14 = *v36;
              if ( *v36 )
                continue;
            }
          }
          goto LABEL_26;
        }
      }
      else
      {
LABEL_26:
        v17 = (float *)sub_587C03(8);
        if ( v17 )
        {
          *v17 = NAN;
          v17[1] = 0.0;
          v18 = v17;
        }
        else
        {
          v18 = 0;
        }
        *(_DWORD *)v18 = sub_4C50E0(v38);
        v18[1] = sub_4BF6A0((const char *)(v13 + 188));
        v19 = sub_587C03(12);
        if ( v19 )
        {
          *(_DWORD *)v19 = v18;
          *(_DWORD *)(v19 + 4) = 0;
          *(_BYTE *)(v19 + 8) = 1;
        }
        else
        {
          v19 = 0;
        }
        if ( *v3 )
        {
          *(_DWORD *)(v3[1] + 4) = v19;
        }
        else
        {
          *v3 = v19;
          v3[2] = v19;
        }
        v20 = v3[3] + 1;
        v3[1] = v19;
        v3[3] = v20;
        v21 = (_DWORD *)sub_587C03(8);
        v22 = (int)v21;
        if ( v21 )
        {
          *v21 = 0;
          v21[1] = -1;
          sub_566650(v13 + 124);
          v23 = (_DWORD *)sub_587C03(12);
          if ( v23 )
            v24 = (char ***)sub_4BAC20(v23, v22, 1);
          else
            v24 = 0;
          if ( v34 )
          {
            v35[1] = (char **)v24;
          }
          else
          {
            v34 = v24;
            v36 = v24;
          }
          v35 = v24;
          ++v37;
        }
        ++v30;
      }
      v25 = ++v33 <= 200;
      v38 = (sub_5884ED(v16) % 2 + v38 + 1) % v32;
    }
    while ( v25 && v30 < a2 );
  }
  v26 = sub_4C2E20(*v3);
  v27 = v26;
  *v3 = v26;
  if ( v26 )
  {
    for ( i = *(_DWORD *)(v26 + 4); i; i = *(_DWORD *)(i + 4) )
      v27 = i;
  }
  v3[1] = v27;
  v3[2] = v26;
  sub_4C2F20(&v34);
  return v30;
}
