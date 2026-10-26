int __stdcall sub_6AF0F0(int a1, _DWORD *a2)
{
  int v2; // edx
  _DWORD *v3; // ecx
  _DWORD *v4; // eax
  int v5; // edi
  int v6; // esi
  unsigned int v8; // [esp+14h] [ebp+8h]

  v2 = a1 - (_DWORD)a2;
  v8 = 0;
  v3 = &unk_91A658;
  while ( 1 )
  {
    v4 = a2;
    v5 = 1;
    v6 = 4;
    do
    {
      if ( *(_DWORD *)((char *)v4 + v2) != *v3 && *v4 != -1 )
        v5 = 0;
      ++v3;
      ++v4;
      --v6;
    }
    while ( v6 );
    if ( v5 )
      break;
    v8 += 16;
    if ( v8 >= 0x80 )
      return 0;
  }
  return 1;
}
