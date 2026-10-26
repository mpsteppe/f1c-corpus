int __stdcall sub_6B7588(int a1)
{
  size_t v1; // ebx
  _BYTE *v2; // eax
  _BYTE *v3; // eax
  void *v4; // eax
  _BYTE *v5; // eax
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  int v8; // eax
  unsigned int v9; // eax
  int result; // eax

  v1 = ((*(_DWORD *)(a1 + 184) * *(unsigned __int8 *)(a1 + 280) * (unsigned int)*(unsigned __int8 *)(a1 + 283) + 7) >> 3)
     + 1;
  v2 = sub_6B7269(a1, v1);
  *(_DWORD *)(a1 + 220) = v2;
  *v2 = 0;
  if ( (*(_BYTE *)(a1 + 277) & 0x10) != 0 )
  {
    v3 = sub_6B7269(a1, *(_DWORD *)(a1 + 200) + 1);
    *(_DWORD *)(a1 + 224) = v3;
    *v3 = 1;
  }
  if ( (*(_BYTE *)(a1 + 277) & 0xE0) != 0 )
  {
    v4 = sub_6B7269(a1, v1);
    *(_DWORD *)(a1 + 216) = v4;
    memset(v4, 0, v1);
    if ( (*(_BYTE *)(a1 + 277) & 0x20) != 0 )
    {
      v5 = sub_6B7269(a1, *(_DWORD *)(a1 + 200) + 1);
      *(_DWORD *)(a1 + 228) = v5;
      *v5 = 2;
    }
    if ( (*(_BYTE *)(a1 + 277) & 0x40) != 0 )
    {
      v6 = sub_6B7269(a1, *(_DWORD *)(a1 + 200) + 1);
      *(_DWORD *)(a1 + 232) = v6;
      *v6 = 3;
    }
    if ( *(char *)(a1 + 277) < 0 )
    {
      v7 = sub_6B7269(a1, *(_DWORD *)(a1 + 200) + 1);
      *(_DWORD *)(a1 + 236) = v7;
      *v7 = 4;
    }
  }
  v8 = *(_DWORD *)(a1 + 188);
  if ( !*(_BYTE *)(a1 + 275) || (*(_BYTE *)(a1 + 96) & 2) != 0 )
  {
    *(_DWORD *)(a1 + 192) = v8;
    v9 = *(_DWORD *)(a1 + 184);
  }
  else
  {
    *(_DWORD *)(a1 + 192) = (unsigned int)(v8 + 7) >> 3;
    v9 = (unsigned int)(*(_DWORD *)(a1 + 184) + 7) >> 3;
  }
  *(_DWORD *)(a1 + 196) = v9;
  *(_DWORD *)(a1 + 116) = *(_DWORD *)(a1 + 160);
  result = *(_DWORD *)(a1 + 156);
  *(_DWORD *)(a1 + 112) = result;
  return result;
}
