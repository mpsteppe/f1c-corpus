_DWORD *__stdcall sub_679D60(int a1)
{
  int v1; // ecx
  int v2; // eax
  _BYTE *v3; // eax
  int v4; // ecx
  bool v5; // cc

  v1 = *(_DWORD *)(a1 + 20);
  if ( v1 != 100 )
  {
    v2 = *(_DWORD *)a1;
    *(_DWORD *)(v2 + 20) = 20;
    *(_DWORD *)(v2 + 24) = v1;
    (*(void (__stdcall **)(int))v2)(a1);
  }
  if ( !*(_DWORD *)(a1 + 68) )
    *(_DWORD *)(a1 + 68) = (**(int (__stdcall ***)(int, _DWORD, int))(a1 + 4))(a1, 0, 840);
  *(_DWORD *)(a1 + 56) = 8;
  sub_679600((int *)a1, 0, (int)&unk_73C4C8, 50, 1);
  sub_679600((int *)a1, 1u, (int)&unk_73C3C8, 50, 1);
  sub_679870((int *)a1);
  v3 = (_BYTE *)(a1 + 136);
  v4 = 16;
  do
  {
    *(v3 - 16) = 0;
    *v3 = 1;
    v3[16] = 5;
    ++v3;
    --v4;
  }
  while ( v4 );
  v5 = *(_DWORD *)(a1 + 56) <= 8;
  *(_DWORD *)(a1 + 172) = 0;
  *(_DWORD *)(a1 + 168) = 0;
  *(_DWORD *)(a1 + 176) = 0;
  *(_DWORD *)(a1 + 180) = 0;
  *(_DWORD *)(a1 + 184) = 0;
  if ( !v5 )
    *(_DWORD *)(a1 + 184) = 1;
  *(_DWORD *)(a1 + 188) = 0;
  *(_DWORD *)(a1 + 192) = 0;
  *(_DWORD *)(a1 + 196) = 0;
  *(_DWORD *)(a1 + 200) = 0;
  *(_DWORD *)(a1 + 204) = 0;
  *(_BYTE *)(a1 + 212) = 1;
  *(_BYTE *)(a1 + 213) = 1;
  *(_BYTE *)(a1 + 214) = 0;
  *(_WORD *)(a1 + 216) = 1;
  *(_WORD *)(a1 + 218) = 1;
  return sub_679BC0((int *)a1);
}
