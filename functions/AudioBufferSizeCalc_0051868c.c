char *__cdecl sub_51868C(int a1)
{
  unsigned int v1; // eax
  int v2; // edi
  unsigned int v3; // eax
  unsigned int v4; // ecx
  int v5; // eax
  int v6; // eax
  int v7; // ebx
  char v8; // cl
  char v9; // cl
  int v10; // ecx
  char *v11; // eax
  char *result; // eax
  unsigned int v13; // [esp-14h] [ebp-1Ch]

  *(_DWORD *)(a1 + 104) = 0;
  TextureImageColorTransform(a1);
  v1 = *(_DWORD *)(a1 + 188);
  if ( *(_BYTE *)(a1 + 275) )
  {
    if ( (*(_BYTE *)(a1 + 96) & 2) == 0 )
      v1 = (v1 + 7) >> 3;
    v2 = *(_DWORD *)(a1 + 184);
    *(_DWORD *)(a1 + 192) = v1;
    v3 = (v2 - dword_5AFAA0[*(unsigned __int8 *)(a1 + 276)] + dword_5AFABC[*(unsigned __int8 *)(a1 + 276)] - 1)
       / (unsigned int)dword_5AFABC[*(unsigned __int8 *)(a1 + 276)];
    v4 = ((v3 * *(unsigned __int8 *)(a1 + 281) + 7) >> 3) + 1;
    *(_DWORD *)(a1 + 208) = v3;
    *(_DWORD *)(a1 + 204) = v4;
  }
  else
  {
    v2 = *(_DWORD *)(a1 + 184);
    *(_DWORD *)(a1 + 192) = v1;
    v5 = *(_DWORD *)(a1 + 200) + 1;
    *(_DWORD *)(a1 + 208) = v2;
    *(_DWORD *)(a1 + 204) = v5;
  }
  v6 = *(unsigned __int8 *)(a1 + 281);
  v7 = *(_DWORD *)(a1 + 96);
  if ( (v7 & 4) != 0 && *(_BYTE *)(a1 + 279) < 8u )
    v6 = 8;
  if ( (v7 & 0x1000) != 0 )
  {
    v8 = *(_BYTE *)(a1 + 278);
    if ( v8 == 3 )
    {
      v6 = 8 * (*(_WORD *)(a1 + 266) != 0) + 24;
    }
    else if ( v8 )
    {
      if ( v8 == 2 && *(_WORD *)(a1 + 266) )
        v6 = 4 * v6 / 3;
    }
    else
    {
      if ( v6 < 8 )
        v6 = 8;
      if ( *(_WORD *)(a1 + 266) )
        v6 *= 2;
    }
  }
  if ( (v7 & 0x8000) != 0 )
  {
    v9 = *(_BYTE *)(a1 + 278);
    if ( v9 != 3 )
    {
      if ( v9 )
      {
        if ( v9 != 2 )
          goto LABEL_28;
        v10 = v6 > 32 ? 64 : 32;
      }
      else
      {
        v10 = v6 > 8 ? 32 : 16;
      }
      v6 = v10;
      goto LABEL_28;
    }
    v6 = 32;
  }
LABEL_28:
  *(_DWORD *)(a1 + 220) = sub_517E92(a1, ((v6 * ((v2 + 7) & 0xFFFFFFF8) + 7) >> 3) + ((v6 + 7) >> 3) + 1);
  v11 = (char *)sub_517E92(a1, *(_DWORD *)(a1 + 200) + 1);
  v13 = *(_DWORD *)(a1 + 200) + 1;
  *(_DWORD *)(a1 + 216) = v11;
  result = MemsetWithByteFill(v7, a1, v11, 0, v13);
  *(_DWORD *)(a1 + 92) |= 0x40u;
  return result;
}
