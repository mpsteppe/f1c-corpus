int __thiscall sub_44B7E0(char **this, _DWORD *a2, int a3, int a4, int a5, int a6)
{
  char **v6; // ebp
  char *v7; // eax
  char *v8; // esi
  char **v9; // eax
  char *v10; // ebp
  int v11; // edi
  char **v12; // esi
  int v13; // ebx
  int v14; // eax
  char *v15; // ecx
  char *v16; // ecx
  char *v17; // eax
  char *v18; // eax
  char *v19; // eax
  char **v20; // esi
  char *v21; // eax
  int v22; // edx
  char *v23; // ebp
  int v24; // eax
  char *v25; // edi
  int v26; // eax
  char *v27; // ecx
  int v28; // esi
  int v29; // eax
  _DWORD *v30; // ebx
  int i; // eax
  int v32; // edx
  int v33; // ecx
  int v34; // edx
  bool v35; // zf
  char *v36; // eax
  int v37; // esi
  int v38; // eax
  int j; // edx
  int result; // eax
  unsigned int v41; // ecx
  int *v42; // ecx
  int v43; // esi
  int v44; // edi
  char **v46; // [esp+14h] [ebp-44h]
  _DWORD v47[4]; // [esp+18h] [ebp-40h] BYREF
  _DWORD v48[4]; // [esp+28h] [ebp-30h] BYREF
  char v49[16]; // [esp+38h] [ebp-20h] BYREF
  char v50[16]; // [esp+48h] [ebp-10h] BYREF
  int v51; // [esp+5Ch] [ebp+4h]
  int *v52; // [esp+60h] [ebp+8h]
  int v53; // [esp+64h] [ebp+Ch]
  int v54; // [esp+68h] [ebp+10h]

  v6 = this;
  v7 = this[1];
  if ( (int)*this >= (int)v7 )
  {
    v8 = v7 + 0x2000;
    this[1] = v7 + 0x2000;
    v9 = (char **)operator new(32 * (_DWORD)(v7 + 0x2000) + 4);
    if ( v9 )
    {
      v10 = (char *)(v9 + 1);
      *v9 = v8;
      v11 = (int)(v9 + 1);
      if ( (int)(v8 - 1) >= 0 )
      {
        do
        {
          sub_44B2D0(v11);
          v11 += 32;
          --v8;
        }
        while ( v8 );
      }
    }
    else
    {
      v10 = 0;
    }
    v12 = this;
    v13 = 0;
    if ( (int)*this > 0 )
    {
      v14 = 0;
      do
      {
        qmemcpy(&v10[v14], &v12[2][v14], 0x20u);
        *(_DWORD *)&this[2][v14 + 28] = &v10[v14];
        ++v13;
        v14 += 32;
        v12 = this;
      }
      while ( v13 < (int)*this );
    }
    v15 = v12[3];
    if ( v15 )
      sub_44B290(v15);
    v16 = v12[4];
    if ( v16 )
      sub_44B290(v16);
    v17 = v12[2];
    if ( v17 )
      sub_5BE8AE(v17 - 4);
    v12[2] = v10;
    v6 = this;
  }
  v46 = (char **)&v6[2][32 * (_DWORD)(*v6)++];
  sub_44B300((int)v46, a5);
  sub_44A8C0((char *)v48, (int)a2, a3);
  sub_44A8C0(v49, a3, a4);
  sub_44A8C0(v50, a4, (int)a2);
  if ( !v6[3] )
  {
    v18 = (char *)operator new(0x60u);
    v6[3] = v18;
    sub_44A950(v18, a2);
  }
  if ( !v6[4] )
  {
    v19 = (char *)operator new(0x60u);
    v6[4] = v19;
    sub_44A950(v19, v48);
  }
  v20 = v46;
  *v46 = sub_44AA10(v6[3], (int)a2);
  v46[2] = sub_44AA10(v6[3], a3);
  v21 = sub_44AA10(v6[3], a4);
  v22 = 1;
  v46[4] = v21;
  v54 = 1;
  while ( 2 )
  {
    v23 = v20[v22 - 1];
    if ( v22 == 5 )
      v24 = 0;
    else
      v24 = v22 + 1;
    v25 = v46[v24];
    v26 = *((_DWORD *)v23 + 6);
    v27 = 0;
    if ( (unsigned int)v26 < 0xB )
    {
      if ( v26 <= 0 )
        goto LABEL_54;
    }
    else
    {
      v26 = 11;
    }
    v52 = (int *)(v23 + 28);
    v53 = v26;
    do
    {
      v28 = *v52;
      v29 = *((_DWORD *)v25 + 6);
      if ( (unsigned int)v29 < 0xB )
      {
        if ( v29 <= 0 )
          goto LABEL_53;
      }
      else
      {
        v29 = 11;
      }
      v30 = v25 + 28;
      v51 = v29;
      do
      {
        if ( v28 != *v30 )
          goto LABEL_52;
        for ( i = 0; i < 6; i += 2 )
        {
          if ( *(char **)(v28 + 4 * i) != v23 )
            continue;
          v32 = 4;
          if ( i )
            v32 = i - 2;
          if ( *(char **)(v28 + 4 * v32) == v25 )
          {
            v33 = 5;
            if ( i )
              v33 = i - 1;
            goto LABEL_49;
          }
          if ( i == 4 )
            v34 = 0;
          else
            v34 = i + 2;
          if ( *(char **)(v28 + 4 * v34) == v25 )
          {
            if ( i == 5 )
              v33 = 0;
            else
              v33 = i + 1;
LABEL_49:
            v27 = *(char **)(v28 + 4 * v33);
            continue;
          }
        }
        v22 = v54;
LABEL_52:
        ++v30;
        --v51;
      }
      while ( v51 );
LABEL_53:
      v35 = v53 == 1;
      ++v52;
      --v53;
    }
    while ( !v35 );
LABEL_54:
    if ( v22 == 1 )
    {
      v36 = (char *)v48;
    }
    else
    {
      v36 = v49;
      if ( v22 != 3 )
        v36 = v50;
    }
    v47[0] = *(_DWORD *)v36;
    v47[1] = *((_DWORD *)v36 + 1);
    v37 = *((_DWORD *)v36 + 2);
    v38 = *((_DWORD *)v36 + 3);
    v47[2] = v37;
    v47[3] = v38;
    if ( v27 )
      v46[v22] = v27;
    else
      v46[v54] = sub_44AA10(this[4], (int)v47);
    v22 = v54 + 2;
    v54 += 2;
    if ( v54 < 6 )
    {
      v20 = v46;
      continue;
    }
    break;
  }
  for ( j = 0; j < 6; ++j )
  {
    result = (int)v46[j];
    v41 = *(_DWORD *)(result + 24);
    if ( v41 < 0xB )
      *(_DWORD *)(result + 4 * v41 + 28) = v46;
    ++*(_DWORD *)(result + 24);
  }
  if ( a6 )
  {
    result = 0;
    v42 = (int *)(v46 + 1);
    do
    {
      v43 = *v42;
      *(_DWORD *)(v43 + 16) = *(_DWORD *)(a6 + 8 * result);
      v44 = *(_DWORD *)(a6 + 8 * result++ + 4);
      v42 += 2;
      *(_DWORD *)(v43 + 20) = v44;
    }
    while ( result < 3 );
  }
  return result;
}
