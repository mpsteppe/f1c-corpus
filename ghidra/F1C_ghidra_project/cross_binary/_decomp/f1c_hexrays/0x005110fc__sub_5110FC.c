// f1c  0x005110fc  size=215
char __cdecl sub_5110FC(_DWORD *a1)
{
  _DWORD *v1; // eax
  unsigned __int8 **v2; // esi
  unsigned __int8 *v3; // ebx
  unsigned __int8 *v4; // edi
  int v5; // ecx
  int v6; // ecx
  int v8; // [esp+Ch] [ebp-4h]

  v1 = a1;
  v2 = (unsigned __int8 **)a1[5];
  v3 = v2[1];
  v4 = *v2;
  while ( 1 )
  {
    if ( !v3 )
    {
      if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(v1) )
        return 0;
      v1 = a1;
      v4 = *v2;
      v3 = v2[1];
    }
    v5 = *v4;
    --v3;
    ++v4;
    if ( v5 != 255 )
    {
      ++*(_DWORD *)(v1[100] + 88);
      goto LABEL_3;
    }
    do
    {
      if ( !v3 )
      {
        if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(v1) )
          return 0;
        v4 = *v2;
        v3 = v2[1];
        v1 = a1;
      }
      v6 = *v4;
      --v3;
      ++v4;
      v8 = v6;
    }
    while ( v6 == 255 );
    if ( v6 )
      break;
    *(_DWORD *)(v1[100] + 88) += 2;
LABEL_3:
    *v2 = v4;
    v2[1] = v3;
  }
  if ( *(_DWORD *)(v1[100] + 88) )
  {
    *(_DWORD *)(*v1 + 20) = 112;
    *(_DWORD *)(*v1 + 24) = *(_DWORD *)(v1[100] + 88);
    *(_DWORD *)(*v1 + 28) = v6;
    (*(void (__cdecl **)(_DWORD *, int))(*v1 + 4))(v1, -1);
    *(_DWORD *)(a1[100] + 88) = 0;
    v1 = a1;
    v6 = v8;
  }
  v1[94] = v6;
  *v2 = v4;
  v2[1] = v3;
  return 1;
}
