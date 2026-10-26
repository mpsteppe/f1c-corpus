char __usercall sub_50FF84@<al>(int a1@<esi>)
{
  _BYTE *v1; // eax
  int v2; // ecx
  int v3; // eax

  *(_DWORD *)(*(_DWORD *)a1 + 20) = 101;
  (*(void (__cdecl **)(int, int))(*(_DWORD *)a1 + 4))(a1, 1);
  if ( *(_BYTE *)(*(_DWORD *)(a1 + 400) + 80) )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 60;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  v1 = (_BYTE *)(a1 + 218);
  v2 = 16;
  do
  {
    *(v1 - 16) = 0;
    *v1 = 1;
    v1[16] = 5;
    ++v1;
    --v2;
  }
  while ( v2 );
  v3 = *(_DWORD *)(a1 + 400);
  *(_DWORD *)(a1 + 252) = 0;
  *(_DWORD *)(a1 + 36) = 0;
  *(_BYTE *)(a1 + 264) = 0;
  *(_BYTE *)(a1 + 256) = 0;
  *(_BYTE *)(a1 + 257) = 0;
  *(_BYTE *)(a1 + 262) = 0;
  *(_BYTE *)(a1 + 263) = 0;
  *(_WORD *)(a1 + 258) = 1;
  *(_WORD *)(a1 + 260) = 1;
  *(_BYTE *)(v3 + 80) = 1;
  return 1;
}
