int __thiscall sub_4D68D0(int *this, int *a2, int *a3, const CHAR **a4, char **a5)
{
  int v6; // eax
  int v7; // ebx
  int v8; // ecx
  int v9; // ecx
  int v10; // eax
  const CHAR *v11; // eax
  const char *v12; // eax
  const CHAR *v13; // eax
  const CHAR *v14; // eax
  int v15; // eax
  int v16; // edi
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  char *v20; // eax
  _DWORD *v21; // eax
  int v22; // edi
  int v23; // eax
  int v24; // ecx
  int v25; // eax
  int v26; // ebx
  int v27; // ecx
  const CHAR *v28; // ecx
  char *v29; // eax
  int v30; // eax
  int v31; // ebx
  int v32; // eax
  int v33; // edi
  int v34; // ebx
  int v35; // eax
  int v37; // [esp+0h] [ebp-6A8h]
  int v38; // [esp+4h] [ebp-6A4h]
  _BYTE *Block; // [esp+1Ch] [ebp-68Ch]
  int v40; // [esp+24h] [ebp-684h]
  int v41; // [esp+28h] [ebp-680h]
  int v42; // [esp+30h] [ebp-678h]
  char *v43; // [esp+38h] [ebp-670h]
  const CHAR *v44; // [esp+3Ch] [ebp-66Ch]
  int v45; // [esp+40h] [ebp-668h]
  int v46; // [esp+44h] [ebp-664h]
  int v47; // [esp+48h] [ebp-660h]
  char *v48; // [esp+4Ch] [ebp-65Ch]
  int v49; // [esp+50h] [ebp-658h]
  char *v50; // [esp+54h] [ebp-654h]
  int v51; // [esp+54h] [ebp-654h]
  int v52; // [esp+58h] [ebp-650h]
  int v53; // [esp+5Ch] [ebp-64Ch]
  int v54; // [esp+64h] [ebp-644h] BYREF
  char v55[4]; // [esp+68h] [ebp-640h] BYREF
  int v56; // [esp+6Ch] [ebp-63Ch] BYREF
  _DWORD v57[3]; // [esp+70h] [ebp-638h] BYREF
  char v59[512]; // [esp+84h] [ebp-624h] BYREF
  int v60; // [esp+284h] [ebp-424h]
  char v61; // [esp+288h] [ebp-420h]
  int v62; // [esp+290h] [ebp-418h]
  int v63; // [esp+294h] [ebp-414h]
  int v64; // [esp+298h] [ebp-410h]
  _BYTE v65[512]; // [esp+29Ch] [ebp-40Ch] BYREF
  char ArgList; // [esp+49Ch] [ebp-20Ch] BYREF
  _BYTE v67[509]; // [esp+4A4h] [ebp-204h] BYREF
  __int16 v68; // [esp+6A1h] [ebp-7h]
  char v69; // [esp+6A3h] [ebp-5h]

  v6 = this[139];
  v7 = this[36];
  v8 = 0;
  v53 = 0;
  if ( v6 > 0 )
  {
    do
    {
      if ( !v7 )
        break;
      v7 = *(_DWORD *)(v7 + 140);
      --v6;
      ++v8;
    }
    while ( v6 > 0 );
    v53 = v8;
  }
  sub_4D0B20(this);
  v9 = this[142];
  v56 = 0;
  if ( v9 < 1 || this[147] < 1 )
    return -1;
  v57[0] = this[145];
  while ( v7 )
  {
    if ( v57[0] <= 0 )
      return 0;
    if ( (*(int (__thiscall **)(int *))(*this + 4))(this) <= 0 )
      v49 = this[4];
    else
      v49 = (*(int (__thiscall **)(int *))(*this + 4))(this);
    if ( sub_4CFCC0(this, 3) > 0 )
      v49 = sub_4CFCC0(this, 3);
    if ( sub_4CFD30(this, 2) > 0 )
      sub_4CFD30(this, 2);
    if ( v53 == this[146] )
    {
      v10 = this[61];
      if ( v10 )
      {
        v11 = *(const CHAR **)(v10 + 72);
LABEL_30:
        if ( !v11 )
          v11 = WindowName;
        sub_4DF1B0(this[12], v11);
      }
    }
    else
    {
      v12 = *(const char **)(v7 + 276);
      if ( !v12 )
        v12 = WindowName;
      if ( strlen(v12) )
      {
        v13 = *(const CHAR **)(v7 + 276);
        if ( !v13 )
          v13 = WindowName;
        sub_4E0520(v13);
        v14 = *(const CHAR **)(v7 + 276);
        if ( !v14 )
          v14 = WindowName;
        v44 = v14;
        if ( (unsigned __int8)sub_4DF170(this[12]) )
        {
          v11 = *(const CHAR **)(v7 + 276);
          goto LABEL_30;
        }
      }
      v15 = this[61];
      if ( v15 )
      {
        v11 = *(const CHAR **)(v15 + 64);
        goto LABEL_30;
      }
    }
    v16 = v49 + this[142];
    v54 = this[136] + this[3];
    v17 = *(const char **)(v7 + 160);
    v57[0] = v16;
    if ( !v17 )
      v17 = WindowName;
    v50 = strstr(v17, "<LOGO>");
    v18 = *(const char **)(v7 + 160);
    if ( !v18 )
      v18 = WindowName;
    v48 = strstr(v18, "<LOGO_RIGHT>");
    v19 = *(const char **)(v7 + 160);
    if ( !v19 )
      v19 = WindowName;
    v20 = strstr(v19, "<LOGO_CENTER>");
    v57[2] = v20;
    if ( v50 || v48 || v20 )
    {
      memset(v67, 0, sizeof(v67));
      v68 = 0;
      v69 = 0;
      v30 = *this;
      v31 = 0;
      v57[1] = 0;
      (*(void (__thiscall **)(int *))(v30 + 180))(this);
      sub_5EE940((int)&v56, (char)&ArgList, 0);
      memset(v65, 0, sizeof(v65));
      v60 = 0;
      v64 = 0;
      v62 = 0;
      v63 = 0;
      v61 = 1;
      if ( v48 )
      {
        sub_630FE0(v65, v48, 511);
        v65[511] = 0;
        sub_612EB0(v59);
        v42 = 0;
        v41 = 0;
        v40 = 0;
        v32 = sub_4E0240(this[12]);
        this[132] = v32;
        if ( v32 )
        {
          v33 = *(_DWORD *)(v32 + 20);
          v46 = *(_DWORD *)(v32 + 24);
          if ( v46 > sub_4CFD30(this, 3) - (int)v67 )
          {
            Block = &v67[v46 - sub_4CFD30(this, 3)];
            this[132] = sub_4E0240(this[12]);
          }
          if ( Block )
          {
            v45 = this[3];
            v31 = sub_4CFCC0(this, 3) - v45 - v33;
          }
          else if ( v47 )
          {
            v34 = this[3];
            v31 = (sub_4CFCC0(this, 3) - v34) / 2 - v33 / 2;
          }
          v38 = 0;
          v37 = 0;
          v35 = sub_4DDFE0(&unk_B6E2A0, v65);
          sub_4D5E10(this, this[132], 0, (int)v65, v35, (int)&v67[v31], (int)v65, v33);
        }
      }
      if ( Block )
        sub_5EEA30(dword_FB1CE0, Block, 0);
      v38 = *(_DWORD *)(v38 + 140);
      ++v37;
      v7 = v38;
    }
    else
    {
      if ( v52 == this[146] )
      {
        if ( this[61] )
        {
          v21 = (_DWORD *)sub_4E29F0(4);
          if ( v21 )
          {
            v51 = v21[1] - *v21;
            v22 = v21[3] - v21[2];
            v23 = sub_4CFCC0(this, 2);
            v24 = this[142];
            v48 = (char *)v23;
            if ( v22 <= v24 )
              v25 = v24 - v22;
            else
              v25 = v22 - v24;
            v26 = v25 / 2;
            sub_4CFD30(this, 2);
            v43 = &v48[v51];
            v42 = v49 - v26 + v22;
            v41 = 0;
            v40 = 4;
            sub_4CFB20();
            v7 = v46;
            v16 = v52;
          }
        }
      }
      *(_BYTE *)(v7 + 272) = *((_BYTE *)this + 524);
      sub_4E2A80(v43, v16, v48, v47);
      (*(void (__thiscall **)(int, char *, _DWORD *, int *, int *, int))(*(_DWORD *)v7 + 24))(
        v7,
        v55,
        v57,
        &v54,
        &v56,
        v40);
      if ( v45 )
      {
        v27 = *a2;
        if ( v41 < *a2 )
          v27 = v41;
      }
      else
      {
        v27 = v41;
      }
      *a2 = v27;
      if ( v45 && v16 <= *a3 )
        v16 = *a3;
      *a3 = v16;
      if ( v45 )
      {
        v28 = *a4;
        if ( (int)v44 < (int)*a4 )
          v28 = v44;
      }
      else
      {
        v28 = v44;
      }
      *a4 = v28;
      if ( v45 )
      {
        v29 = *a5;
        if ( (int)v43 > (int)*a5 )
          v29 = v43;
      }
      else
      {
        v29 = v43;
      }
      *a5 = v29;
      v7 = *(_DWORD *)(v7 + 140);
      --v46;
      ++v42;
      ++v45;
    }
  }
  return 0;
}
