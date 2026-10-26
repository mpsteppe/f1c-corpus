int __thiscall sub_5EDC50(int this)
{
  int v2; // eax
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // ecx
  int v6; // ecx
  unsigned int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // ecx
  int v12; // [esp-14h] [ebp-20h]
  int v13; // [esp-14h] [ebp-20h]
  int v14; // [esp-4h] [ebp-10h]

  v2 = *(_DWORD *)(this + 4);
  if ( v2 == 2 )
  {
    if ( *(int *)(this + 24) <= 0 )
      return 0;
    v3 = *(_DWORD *)(this + 32);
    v4 = (_DWORD *)(this + 32);
    if ( v3 )
    {
      v5 = *(_DWORD *)(v3 + 12);
      if ( v5 <= 0 || (v6 = v5 - 1, (*(_DWORD *)(v3 + 12) = v6) == 0) )
        (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)dword_FB27A4 + 408))(dword_FB27A4, *v4, 0);
    }
    v12 = *(_DWORD *)(this + 24);
    *v4 = 0;
    if ( (*(int (__thiscall **)(int, _DWORD, int, int, int, int, int, _DWORD))(*(_DWORD *)dword_FB27A4 + 368))(
           dword_FB27A4,
           0,
           2048,
           v12,
           4096,
           this + 32,
           this + 28,
           0) )
    {
      (*(void (__thiscall **)(int, _DWORD, int))(*(_DWORD *)dword_FB27A4 + 416))(dword_FB27A4, *v4, 4096);
      return -1;
    }
    if ( !*v4 )
      return 0;
    ++*(_DWORD *)(*v4 + 12);
    v8 = *(_DWORD *)(this + 24) << 6;
    v14 = 4096;
    goto LABEL_21;
  }
  if ( v2 == 1 && *(int *)(this + 24) > 0 )
  {
    v9 = *(_DWORD *)(this + 32);
    v4 = (_DWORD *)(this + 32);
    if ( v9 )
    {
      v10 = *(_DWORD *)(v9 + 12);
      if ( v10 <= 0 || (v11 = v10 - 1, (*(_DWORD *)(v9 + 12) = v11) == 0) )
        (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)dword_FB27A4 + 408))(dword_FB27A4, *v4, 0);
    }
    v13 = *(_DWORD *)(this + 24);
    *v4 = 0;
    if ( (*(int (__thiscall **)(int, _DWORD, int, int, int, int, int, _DWORD))(*(_DWORD *)dword_FB27A4 + 368))(
           dword_FB27A4,
           0,
           2048,
           v13,
           0x2000,
           this + 32,
           this + 28,
           0) )
    {
      (*(void (__thiscall **)(int, _DWORD, int))(*(_DWORD *)dword_FB27A4 + 416))(dword_FB27A4, *v4, 0x2000);
      return -1;
    }
    if ( *v4 )
    {
      ++*(_DWORD *)(*v4 + 12);
      v8 = 28 * *(_DWORD *)(this + 24);
      v14 = 0x2000;
LABEL_21:
      qmemcpy(*(void **)(*v4 + 76), *(const void **)(this + 44), v8);
      (*(void (__thiscall **)(int, _DWORD, int))(*(_DWORD *)dword_FB27A4 + 416))(dword_FB27A4, *v4, v14);
    }
  }
  return 0;
}
