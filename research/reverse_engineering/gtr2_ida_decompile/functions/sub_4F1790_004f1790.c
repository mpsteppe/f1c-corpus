void __thiscall sub_4F1790(int this)
{
  void *v2; // eax
  char *v3; // eax
  char *v4; // edi
  void *v5; // eax

  *(_BYTE *)(this + 8) = 0;
  *(_BYTE *)(this + 9) = 0;
  *(_BYTE *)(this + 10) = 1;
  *(_BYTE *)(this + 11) = 0;
  *(_BYTE *)(this + 12) = 0;
  *(_BYTE *)(this + 13) = 0;
  *(_BYTE *)(this + 14) = 0;
  *(_BYTE *)(this + 15) = 0;
  *(_DWORD *)(this + 80) = -1;
  *(_DWORD *)(this + 84) = 0;
  *(_DWORD *)(this + 88) = 0;
  *(_DWORD *)(this + 92) = 0;
  *(_DWORD *)(this + 96) = 0;
  *(_DWORD *)(this + 100) = 0;
  *(_DWORD *)(this + 104) = 0;
  *(_DWORD *)(this + 108) = 0;
  *(_DWORD *)(this + 112) = 0;
  *(_DWORD *)(this + 116) = 0;
  if ( *(_DWORD *)(this + 140) )
    sub_408A90((_DWORD *)(this + 140));
  if ( dword_FB1D04 && *(_DWORD *)(this + 136) )
    sub_5DC6F0(*(_DWORD *)(this + 136));
  v2 = *(void **)(this + 148);
  *(_DWORD *)(this + 136) = 0;
  *(_DWORD *)(this + 144) = 0;
  if ( v2 )
    j_j__free(v2);
  v3 = *(char **)(this + 156);
  *(_DWORD *)(this + 148) = 0;
  *(_DWORD *)(this + 152) = 0;
  if ( v3 )
  {
    v4 = v3 - 4;
    `eh vector destructor iterator'(v3, 0x78u, *((_DWORD *)v3 - 1), (void (__thiscall *)(void *))sub_4F09B0);
    j_j__free(v4);
  }
  v5 = *(void **)(this + 232);
  *(_DWORD *)(this + 156) = 0;
  if ( v5 )
    j_j__free(v5);
  *(_DWORD *)(this + 232) = 0;
  *(_DWORD *)(this + 228) = 0;
  *(_DWORD *)(this + 160) = 0;
  *(_DWORD *)(this + 168) = 0;
  *(_DWORD *)(this + 184) = 0;
  *(_DWORD *)(this + 188) = 0;
  *(_DWORD *)(this + 192) = 0;
  *(_DWORD *)(this + 196) = 0;
  *(_DWORD *)(this + 200) = 0;
  *(_DWORD *)(this + 204) = 0;
  *(_DWORD *)(this + 208) = 0;
  *(_DWORD *)(this + 212) = 0;
  *(_DWORD *)(this + 216) = 0;
  *(_DWORD *)(this + 220) = 0;
  *(_DWORD *)(this + 224) = 0;
  *(_BYTE *)(this + 240) = 0;
  *(_DWORD *)(this + 268) = 0;
  *(_DWORD *)(this + 164) = 99;
}
