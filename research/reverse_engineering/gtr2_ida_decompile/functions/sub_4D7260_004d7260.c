int __thiscall sub_4D7260(int this, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  int v6; // eax
  const CHAR *v7; // eax
  int *v8; // eax
  int *v9; // edi
  int v10; // edx
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // edx
  _BYTE *v17; // ecx
  char v18; // al
  _WORD *v19; // edi
  char v20; // al
  const char *v21; // ebx
  int v22; // edi
  int v23; // edi
  int i; // eax
  int v25; // ecx
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v30; // [esp-24h] [ebp-190h]
  int v31; // [esp+0h] [ebp-16Ch]
  int v32; // [esp+4h] [ebp-168h]
  _DWORD v33[2]; // [esp+10h] [ebp-15Ch] BYREF
  char v34[8]; // [esp+18h] [ebp-154h] BYREF
  int v35; // [esp+20h] [ebp-14Ch] BYREF
  int v36; // [esp+24h] [ebp-148h]
  int v37; // [esp+28h] [ebp-144h] BYREF
  int v38; // [esp+2Ch] [ebp-140h] BYREF
  _BYTE v39[253]; // [esp+30h] [ebp-13Ch] BYREF
  __int16 v40; // [esp+12Dh] [ebp-3Fh]
  char v41; // [esp+12Fh] [ebp-3Dh]

  v6 = *(_DWORD *)(this + 244);
  if ( v6 )
  {
    v7 = *(const CHAR **)(v6 + 64);
    if ( !v7 )
      v7 = WindowName;
    sub_4DF1B0(*(_DWORD *)(this + 48), v7);
  }
  sub_4E08C0(*(_DWORD *)(this + 48), "t", &v39[40], &v39[52], 1, *(_DWORD *)&v39[24]);
  if ( *(_DWORD *)(this + 244) )
  {
    v8 = (int *)sub_4E29F0(0);
    v9 = v8;
    if ( v8 )
    {
      v10 = v8[3] - v8[2];
      v11 = *(_DWORD *)(this + 4);
      v12 = *(_DWORD *)(this + 12);
      *(_DWORD *)&v39[4] = 0;
      *(_DWORD *)v39 = 0;
      v38 = v10;
      v37 = v9[1] - *v9;
      v36 = v11;
      v35 = v12;
      v13 = sub_4DDFE0(&unk_B6E2A0, v37);
      sub_4D5E10((void *)this, v9[7], *v9, v9[2], v13, v35, v36, v37);
    }
  }
  v14 = *(_DWORD *)(this + 796);
  memset(v39, 0, sizeof(v39));
  v40 = 0;
  v41 = 0;
  if ( *(_BYTE *)(this + 270) )
  {
    v15 = 0;
    v16 = v14 - (_DWORD)v39;
    do
    {
      v17 = &v39[v15];
      if ( !v39[v15 + v16] )
        break;
      ++v15;
      *v17 = 42;
    }
    while ( v15 < 256 );
  }
  else
  {
    sub_630FE0(v39, v14, 255);
  }
  v18 = *(_BYTE *)(this + 268);
  HIBYTE(v40) = 0;
  if ( v18 && *(_BYTE *)(this + 269) && (int)(unsigned __int64)(dbl_FB1D18 + dbl_FB1D18) % 2 )
  {
    v19 = (_WORD *)((char *)&v38 + 3);
    do
    {
      v20 = *((_BYTE *)v19 + 1);
      v19 = (_WORD *)((char *)v19 + 1);
    }
    while ( v20 );
    *v19 = 95;
  }
  v37 = 0;
  v35 = 0;
  v21 = v39;
  sub_4E08C0(*(_DWORD *)(this + 48), v39, &v35, &v37, 1, v33[0]);
  v22 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 12))(this);
  v23 = v22 - (*(int (__thiscall **)(int))(*(_DWORD *)this + 4))(this);
  if ( v33[0] > v23 )
  {
    for ( i = 0; i < 255; i = v32 )
    {
      v25 = *(_DWORD *)(this + 48);
      ++v21;
      v33[1] = i + 1;
      sub_4E08C0(v25, v21, v33, v34, 1, v31);
      if ( v31 <= v23 )
        break;
    }
  }
  if ( strlen(v21) )
  {
    v26 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)this + 12))(this, 0);
    v27 = (*(int (__thiscall **)(int, int))(*(_DWORD *)this + 4))(this, v26);
    v28 = (*(int (__thiscall **)(int, int))(*(_DWORD *)this + 16))(this, v27);
    v30 = (*(int (__thiscall **)(int, int))(*(_DWORD *)this + 8))(this, v28);
    sub_4E0730(*(_DWORD *)(this + 48));
    *a2 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)this + 8))(this, v21, v30);
    *a3 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 16))(this);
    *a4 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 4))(this);
    *a5 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 12))(this);
  }
  return 0;
}
