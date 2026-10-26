int __stdcall sub_6A326C(int a1, _DWORD *a2, unsigned int a3)
{
  _DWORD *v3; // ecx
  _DWORD *v4; // eax
  int v5; // esi
  int v6; // edx
  int v8; // [esp+Ch] [ebp-4h]

  v8 = 0;
  if ( !a3 )
    return 0;
  v3 = &unk_91A460;
  while ( 1 )
  {
    v4 = a2;
    v5 = 1;
    v6 = 4;
    do
    {
      if ( *(_DWORD *)((char *)v4 + a1 - (_DWORD)a2) != *v3 && *v4 != -1 )
        v5 = 0;
      ++v3;
      ++v4;
      --v6;
    }
    while ( v6 );
    if ( v5 )
      break;
    if ( ++v8 >= a3 )
      return 0;
  }
  return 1;
}
