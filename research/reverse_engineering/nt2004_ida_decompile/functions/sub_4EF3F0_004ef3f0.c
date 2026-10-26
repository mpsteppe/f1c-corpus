LPVOID __thiscall sub_4EF3F0(CHAR ****this)
{
  CHAR ***v2; // esi
  CHAR ****v3; // ebx
  LPVOID **v4; // ecx
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  LPVOID result; // eax
  bool v9; // zf
  CHAR ***v10; // eax
  CHAR **v11; // esi
  CHAR *v12; // eax
  CHAR ***v13; // eax
  CHAR ***v14; // eax
  CHAR *v15; // eax
  CHAR ***v16; // ecx
  CHAR ***v17; // eax
  CHAR ***v18; // edx
  int v19; // eax
  double v20; // st7
  int v21; // ecx
  int v22; // esi
  _DWORD *v23; // edi
  int v24; // ecx
  CHAR ***v25; // eax
  CHAR **v26; // eax
  CHAR *v27; // eax
  _DWORD *v28; // eax
  _DWORD *v29; // eax
  int v30; // ecx
  CHAR ***v31; // eax
  CHAR **v32; // eax
  CHAR ***v33; // ecx
  CHAR ***v34; // edx
  CHAR ***v35; // eax
  int v36; // eax
  int v37; // esi
  int v38; // eax
  CHAR *v39; // esi
  _DWORD *v40; // esi
  CHAR *v41; // eax
  _DWORD *v42; // eax
  float v44; // [esp+14h] [ebp-20h]
  CHAR *v45[2]; // [esp+1Ch] [ebp-18h] BYREF
  _DWORD *v46; // [esp+24h] [ebp-10h] BYREF
  _DWORD *v47; // [esp+28h] [ebp-Ch]
  _DWORD *v48; // [esp+2Ch] [ebp-8h]
  int v49; // [esp+30h] [ebp-4h]

  v2 = this[1];
  v3 = this + 1;
  while ( v2 )
  {
    v4 = (LPVOID **)v2;
    v2 = (CHAR ***)v2[1];
    sub_414480(v4, 1);
  }
  *v3 = 0;
  v3[1] = 0;
  v3[2] = 0;
  v3[3] = 0;
  v5 = sub_410E00((CHAR **)&unk_62A0D8);
  sub_4EF7E0(aWav, v5);
  v6 = sub_410E00((CHAR **)&unk_62A0D8);
  sub_4EF7E0(aMp3, v6);
  v7 = sub_410E00((CHAR **)&unk_62A0D8);
  result = (LPVOID)sub_4EF7E0(aDjs_0, v7);
  v9 = this[4] == 0;
  if ( (int)this[4] <= 0 )
    goto LABEL_84;
  v10 = *v3;
  v9 = *v3 == 0;
  v3[2] = *v3;
  if ( v9 )
    v11 = 0;
  else
    v11 = *v10;
  v45[0] = 0;
  v45[1] = (CHAR *)-1;
  if ( v11 )
  {
    while ( 1 )
    {
      v12 = *v11;
      if ( !*v11 )
        v12 = &byte_629120;
      if ( sub_579060(v12, aMagicCarpetRid) )
        break;
      v13 = v3[2];
      if ( v13 )
        v3[2] = (CHAR ***)v13[1];
      v14 = v3[2];
      if ( v14 )
      {
        v11 = *v14;
        if ( *v14 )
          continue;
      }
      goto LABEL_28;
    }
    v15 = sub_410E00(v11);
    sub_578600(v15);
    v16 = *v3;
    v17 = 0;
    if ( *v3 )
    {
      while ( *v16 != v11 )
      {
        v17 = v16;
        v16 = (CHAR ***)v16[1];
        if ( !v16 )
          goto LABEL_28;
      }
      if ( v16 == v3[2] )
        v3[2] = (CHAR ***)v16[1];
      v18 = (CHAR ***)v16[1];
      if ( v17 )
        v17[1] = (CHAR **)v18;
      else
        *v3 = v18;
      if ( v3[1] == v16 )
        v3[1] = v17;
      v3[3] = (CHAR ***)((char *)v3[3] - 1);
      sub_414480((LPVOID **)v16, 1);
    }
  }
LABEL_28:
  v19 = (int)this[4];
  v46 = 0;
  v47 = 0;
  v48 = 0;
  v49 = 0;
  if ( v19 <= 0 )
    goto LABEL_76;
  do
  {
    v20 = flt_7D3C54[(unsigned __int8)dword_7D3C50++];
    v44 = (double)v19 * v20;
    v21 = (int)v44;
    v22 = v21;
    if ( v21 >= 0 )
    {
      if ( v21 > (int)this[4] - 1 )
        v22 = (int)this[4] - 1;
    }
    else
    {
      v22 = 0;
    }
    v23 = operator new(8u);
    if ( v23 )
    {
      v24 = v22;
      if ( v22 >= 0 && v22 < (int)v3[3] )
      {
        v25 = *v3;
        if ( v22 <= 0 )
        {
LABEL_39:
          if ( v25 )
          {
            v26 = *v25;
            goto LABEL_42;
          }
        }
        else
        {
          while ( v25 )
          {
            v25 = (CHAR ***)v25[1];
            if ( --v24 <= 0 )
              goto LABEL_39;
          }
        }
      }
      v26 = 0;
LABEL_42:
      *v23 = 0;
      v23[1] = -1;
      v27 = sub_410E00(v26);
      sub_578600(v27);
      v28 = operator new(0xCu);
      if ( v28 )
        v29 = sub_4DB610(v28, (int)v23, 1);
      else
        v29 = 0;
      if ( v46 )
      {
        v47[1] = v29;
      }
      else
      {
        v46 = v29;
        v48 = v29;
      }
      v47 = v29;
      ++v49;
    }
    v30 = v22;
    if ( v22 >= 0 && v22 < (int)v3[3] )
    {
      v31 = *v3;
      if ( v22 <= 0 )
      {
LABEL_54:
        if ( v31 )
        {
          v32 = *v31;
          goto LABEL_57;
        }
      }
      else
      {
        while ( v31 )
        {
          v31 = (CHAR ***)v31[1];
          if ( --v30 <= 0 )
            goto LABEL_54;
        }
      }
    }
    v32 = 0;
LABEL_57:
    if ( v32 )
    {
      v33 = *v3;
      v34 = 0;
      if ( *v3 )
      {
        while ( *v33 != v32 )
        {
          v34 = v33;
          v33 = (CHAR ***)v33[1];
          if ( !v33 )
            goto LABEL_70;
        }
        if ( v33 == v3[2] )
          v3[2] = (CHAR ***)v33[1];
        v35 = (CHAR ***)v33[1];
        if ( v34 )
          v34[1] = (CHAR **)v35;
        else
          *v3 = v35;
        if ( v3[1] == v33 )
          v3[1] = v34;
        v3[3] = (CHAR ***)((char *)v3[3] - 1);
        sub_414480((LPVOID **)v33, 1);
      }
    }
LABEL_70:
    v19 = (int)this[4];
  }
  while ( v19 > 0 );
  while ( v49 > 0 )
  {
    if ( operator new(8u) )
    {
      v36 = sub_414470((int *)&v46);
      v37 = sub_4EF7B0(v36);
    }
    else
    {
      v37 = 0;
    }
    v38 = sub_414470((int *)&v46);
    sub_4192A0(&v46, v38, 1);
    sub_414410(v3, v37, 1);
  }
LABEL_76:
  v39 = v45[0];
  if ( !v45[0] )
    v39 = &byte_629120;
  if ( memcmp(v39, &byte_629120, 1u) )
  {
    v40 = operator new(8u);
    if ( v40 )
    {
      v41 = sub_410E00(v45);
      v42 = sub_410DE0(v40, (int)v41);
    }
    else
    {
      v42 = 0;
    }
    sub_4DBCF0(v3, (int)v42, 1);
  }
  sub_4F03B0(0);
  sub_4667A0(&v46);
  result = sub_40D5B0((LPVOID *)v45);
  v9 = this[4] == 0;
LABEL_84:
  if ( v9 )
  {
    if ( dword_7D6BB0 )
    {
      off_61113C[0] = sub_410E00((CHAR **)&unk_62A0D8);
      return (LPVOID)(*(int (__thiscall **)(int, char **, int))(*(_DWORD *)dword_7D6BB0 + 76))(
                       dword_7D6BB0,
                       off_61113C,
                       dword_611130);
    }
  }
  return result;
}
