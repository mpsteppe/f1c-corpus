int __thiscall sub_65BD88(int this)
{
  _DWORD *v2; // ecx
  _DWORD *v3; // ecx
  void *v4; // ecx
  _DWORD **v5; // esi
  int v6; // edi

  v2 = *(_DWORD **)(this + 60);
  if ( v2 )
    sub_659FE3(v2, 1);
  v3 = *(_DWORD **)(this + 104);
  if ( v3 )
    sub_659FA8(v3, 1);
  v4 = *(void **)(this + 616);
  if ( v4 )
    sub_659D66(v4, 1);
  v5 = (_DWORD **)(this + 108);
  v6 = 127;
  do
  {
    if ( *v5 )
      sub_65B2FE(*v5, 1);
    ++v5;
    --v6;
  }
  while ( v6 );
  if ( *(_DWORD *)(this + 668) && strcmp(*(const char **)(this + 668), "C") )
    setlocale(4, *(const char **)(this + 668));
  if ( *(_DWORD *)(this + 668) )
    free(*(void **)(this + 668));
  _controlfp(*(_DWORD *)(this + 672), 0xB001Fu);
  if ( *(_DWORD *)(this + 676) )
    sub_65B346((_DWORD *)this);
  sub_65D5A5(this + 24);
  return sub_67EB5C(this);
}
