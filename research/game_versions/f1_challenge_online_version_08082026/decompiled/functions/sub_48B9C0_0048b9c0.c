int __thiscall sub_48B9C0(int this, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  int v6; // eax
  int v7; // ebx
  char *v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // edi
  int v11; // eax
  int v12; // edx
  int v13; // eax
  int v14; // edx
  char *v15; // ecx
  char v16; // al
  const char *v17; // ebp
  int v18; // edi
  int v19; // edi
  int v20; // eax
  int v22; // [esp-18h] [ebp-134h]
  int v23; // [esp-14h] [ebp-130h]
  int v24; // [esp-10h] [ebp-12Ch]
  int v25; // [esp-10h] [ebp-12Ch]
  int v26; // [esp-Ch] [ebp-128h]
  int v27; // [esp-Ch] [ebp-128h]
  int v28; // [esp-8h] [ebp-124h]
  int v29; // [esp+10h] [ebp-10Ch] BYREF
  int v30; // [esp+14h] [ebp-108h] BYREF
  char v31[4]; // [esp+18h] [ebp-104h] BYREF
  char v32[253]; // [esp+1Ch] [ebp-100h] BYREF
  __int16 v33; // [esp+119h] [ebp-3h]
  char v34; // [esp+11Bh] [ebp-1h]

  v6 = *(_DWORD *)(this + 200);
  v7 = 0;
  if ( v6 )
  {
    v8 = *(char **)(v6 + 64);
    if ( !v8 )
      v8 = byte_5EA438;
    sub_498560(v8);
  }
  sub_4983B0(&unk_5CC218, &v29, v31, 1);
  v9 = (_DWORD *)sub_486460((_DWORD *)this, 0);
  v10 = v9;
  if ( v9 )
  {
    v26 = v9[3] - v9[2];
    v24 = v9[1] - *v9;
    v23 = *(_DWORD *)(this + 4);
    v22 = *(_DWORD *)(this + 12);
    v11 = sub_495150(&unk_7CDE00);
    sub_494A30(*(_DWORD *)(v10[8] + 12), *v10, v10[2], v11, v22, v23, v24, v26, 0, 0);
  }
  v12 = *(_DWORD *)(this + 752);
  v32[0] = byte_5EA438[0];
  memset(&v32[1], 0, 0xFCu);
  v33 = 0;
  v34 = 0;
  if ( *(_BYTE *)(this + 226) )
  {
    v13 = 0;
    v14 = v12 - (_DWORD)v32;
    do
    {
      v15 = &v32[v13];
      if ( !v32[v13 + v14] )
        break;
      ++v13;
      *v15 = 42;
    }
    while ( v13 < 256 );
  }
  else
  {
    sub_587DD0(v32, v12, 255);
  }
  v16 = *(_BYTE *)(this + 224);
  HIBYTE(v33) = 0;
  if ( v16 && *(_BYTE *)(this + 225) )
    *(_WORD *)&v32[strlen(v32)] = word_5CC214;
  v30 = 0;
  v29 = 0;
  v17 = v32;
  sub_4983B0(v32, &v29, &v30, 1);
  v18 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 32))(this);
  v19 = v18 - (*(int (__thiscall **)(int))(*(_DWORD *)this + 24))(this);
  while ( v29 > v19 )
  {
    if ( v7 >= 255 )
      break;
    ++v17;
    ++v7;
    sub_4983B0(v17, &v29, &v30, 1);
  }
  if ( strlen(v17) )
  {
    v28 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 32))(this);
    v27 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 24))(this);
    v25 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 36))(this);
    v20 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 28))(this);
    sub_4981F0(v17, v20, v25, v27, v28, 1);
    *a2 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 28))(this);
    *a3 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 36))(this);
    *a4 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 24))(this);
    *a5 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 32))(this);
  }
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)this + 44))(this, 0);
  return 0;
}
