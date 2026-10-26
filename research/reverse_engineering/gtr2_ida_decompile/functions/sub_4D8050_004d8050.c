int __fastcall sub_4D8050(int *a1, int a2, int a3, int a4)
{
  int v5; // edi
  int v6; // ecx
  int v7; // eax
  int v8; // eax
  const CHAR *v9; // eax
  const CHAR *v10; // ecx
  int v11; // ebx
  int v12; // ebx
  int v13; // eax
  int v14; // eax
  int v15; // kr04_4
  int v16; // edx
  int v17; // edi
  int v18; // eax
  int v19; // ecx
  const char *v20; // ecx
  const CHAR *v21; // eax
  int *v22; // edi
  const CHAR *v23; // eax
  const CHAR *v24; // eax
  int v26; // [esp+0h] [ebp-278h]
  int v27; // [esp+Ch] [ebp-26Ch]
  _DWORD v28[2]; // [esp+14h] [ebp-264h] BYREF
  char v29[8]; // [esp+1Ch] [ebp-25Ch] BYREF
  int v30; // [esp+24h] [ebp-254h]
  int v31; // [esp+28h] [ebp-250h] BYREF
  int v32; // [esp+2Ch] [ebp-24Ch]
  _DWORD v33[2]; // [esp+30h] [ebp-248h] BYREF
  int v34; // [esp+38h] [ebp-240h] BYREF
  _BYTE v35[509]; // [esp+3Ch] [ebp-23Ch] BYREF
  __int16 v36; // [esp+239h] [ebp-3Fh]
  char v37; // [esp+23Bh] [ebp-3Dh]

  v5 = a1[15];
  if ( v5 )
  {
    v6 = *(_DWORD *)(v5 + 24);
    v7 = *(_DWORD *)(v5 + 20);
    *(_DWORD *)&v35[16] = 0;
    *(_DWORD *)&v35[12] = 0;
    *(_DWORD *)&v35[8] = v6;
    *(_DWORD *)&v35[4] = v7;
    v8 = sub_4DDFE0(&unk_B6E2A0, a2);
    sub_4D5E10((void *)a1[12], v5, 0, 0, v8, a3, a4, *(int *)&v35[4]);
  }
  v9 = (const CHAR *)a1[16];
  *(_DWORD *)&v35[12] = 0;
  v34 = 0;
  *(_DWORD *)&v35[4] = 0;
  if ( !v9 )
    v9 = WindowName;
  v10 = (const CHAR *)a1[18];
  if ( !v10 )
    v10 = WindowName;
  v30 = 1;
  sub_4DF1D0(v10, v9, &v34, &v35[4]);
  if ( a1[20] == 1 )
  {
    if ( (*(int (__thiscall **)(int *))(*a1 + 4))(a1) <= v30 )
      v14 = v30 - (*(int (__thiscall **)(int *))(*a1 + 4))(a1);
    else
      v14 = (*(int (__thiscall **)(int *))(*a1 + 4))(a1) - v30;
    v15 = v14;
    v13 = a3;
    v12 = v15 / 2;
  }
  else
  {
    if ( a1[20] != 2 )
    {
      v11 = a3 + 10;
      goto LABEL_18;
    }
    if ( (*(int (__thiscall **)(int *))(*a1 + 4))(a1) <= v30 )
    {
      v11 = v30 + a3 - (*(int (__thiscall **)(int *))(*a1 + 4))(a1);
      goto LABEL_18;
    }
    v12 = (*(int (__thiscall **)(int *))(*a1 + 4))(a1);
    v13 = a3 - v30;
  }
  v11 = v13 + v12;
LABEL_18:
  if ( (*(int (__thiscall **)(int *))(*a1 + 8))(a1) > v32 )
    v33[1] = a4 + ((*(int (__thiscall **)(int *))(*a1 + 8))(a1) - v32) / 2;
  v16 = *a1;
  memset(v35, 0, sizeof(v35));
  v36 = 0;
  v37 = 0;
  v17 = (*(int (__thiscall **)(int *))(v16 + 4))(a1);
  v18 = a1[3];
  v34 = v17;
  if ( v11 <= v18 )
    v19 = v18 - v11;
  else
    v19 = v11 - v18;
  if ( v17 > v19 )
  {
    v17 -= v19;
    v34 = v17;
  }
  v20 = (const char *)a1[16];
  if ( !v20 )
    v20 = WindowName;
  strcpy(v35, v20);
  v21 = (const CHAR *)a1[18];
  v31 = 0;
  v33[0] = 0;
  if ( !v21 )
    v21 = WindowName;
  sub_4DF1D0(v21, v35, &v31, v33);
  if ( v28[0] > v17 )
  {
    v22 = (int *)((char *)&v31 + strlen((const char *)&v31) + 1);
    do
    {
      if ( &v31 == v22 )
        break;
      v23 = (const CHAR *)a1[18];
      v22 = (int *)((char *)v22 - 1);
      *(_BYTE *)v22 = 0;
      if ( !v23 )
        v23 = WindowName;
      sub_4DF1D0(v23, &v31, v28, v29);
    }
    while ( v26 > 1 );
  }
  v24 = (const CHAR *)a1[18];
  if ( !v24 )
    v24 = WindowName;
  return sub_4DF290(v24, v28, v11, v27, 0, 1);
}
