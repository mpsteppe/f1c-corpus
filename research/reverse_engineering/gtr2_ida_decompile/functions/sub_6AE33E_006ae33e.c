int __thiscall sub_6AE33E(int this)
{
  unsigned int v2; // edi
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  unsigned int v5; // eax
  int v6; // edi
  int v7; // eax
  int *v8; // eax
  int v9; // eax
  unsigned int v10; // ecx
  unsigned int j; // ecx
  int v12; // eax
  int v14; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  *(_DWORD *)(this + 544) = -1;
  *(_DWORD *)(this + 548) = -1;
  v2 = 0;
  for ( i = 0; v2 < *(_DWORD *)(this + 12); ++v2 )
  {
    v3 = (_DWORD *)(*(_DWORD *)(this + 24) + 4 * v2);
    *(_DWORD *)(this + 252) = v2;
    *(_DWORD *)(this + 256) = *v3;
    *(_DWORD *)(this + 252) = v2;
    v4 = (_DWORD *)*v3;
    *(_DWORD *)(this + 256) = v4;
    v5 = *v4 & 0xFFF00000;
    if ( (v5 == 540016640 || v5 == 538968064) && *(_DWORD *)(this + 544) == -1 )
    {
      v14 = sub_681A51((void *)this, (int)"c", 785, 1, 4);
      *(_DWORD *)(this + 544) = sub_681AAA((void *)this, v14, 0, 0, 0.0);
      *(_DWORD *)(this + 548) = sub_681AAA((void *)this, v14, 0, 1, 1.0);
    }
  }
  sub_6BC1A9(this);
  if ( (*(_BYTE *)(this + 204) & 4) == 0 )
  {
    v6 = 0;
    if ( *(_DWORD *)(this + 12) )
    {
      while ( 1 )
      {
        v7 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = v6;
        v8 = *(int **)(v7 + 4 * v6);
        *(_DWORD *)(this + 256) = v8;
        v9 = *v8;
        v10 = v9 & 0xFFF00000;
        if ( (v9 & 0xFFF00000) == 0x10300000 || v10 == 273678336 || v10 == 274726912 || v10 == 275775488 )
          goto LABEL_16;
        if ( v10 == 1342177280 )
          break;
        i = 1;
LABEL_18:
        if ( (unsigned int)++v6 >= *(_DWORD *)(this + 12) )
          goto LABEL_19;
      }
      if ( (v9 & 0xFFFFFu) > 2 )
LABEL_16:
        i = sub_6BFAB9(this);
      if ( i < 0 )
        return i;
      goto LABEL_18;
    }
  }
LABEL_19:
  sub_6BC1A9(this);
  for ( j = 0; j < *(_DWORD *)(this + 8); ++j )
  {
    v12 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * j);
    if ( *(_DWORD *)(v12 + 84) == -1
      && (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * *(_DWORD *)(v12 + 4)) + 5) & 1) != 0
      && *(_DWORD *)(this + 548) != j
      && *(_DWORD *)(this + 544) != j )
    {
      *(_DWORD *)(v12 + 4) = *(_DWORD *)(this + 116);
    }
  }
  return 0;
}
