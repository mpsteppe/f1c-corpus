float *__userpurge sub_50A7E1@<eax>(int a1@<ebp>, int a2)
{
  float *v2; // ecx
  float *v3; // esi
  unsigned int v4; // ecx
  int v5; // ebx
  int v6; // eax
  int v7; // eax
  float *v9; // [esp-20h] [ebp-20h]

  SEHHandlerInit();
  v9 = *(float **)(a1 + 8);
  v3 = v2;
  *(_DWORD *)(a1 - 20) = v2;
  DirectXTextureCreationWithMipmapChain(v2, v9, 0, 1);
  v4 = (_DWORD)v3[1036] & 0xFFFFFFFE;
  v5 = ((*((_DWORD *)v3 + 1038) + 1) & 0xFFFFFFFE) - v4;
  *((_DWORD *)v3 + 1054) = (*((_DWORD *)v3 + 1038) + 1) & 0xFFFFFFFE;
  *(_DWORD *)(a1 - 4) = 0;
  *(_DWORD *)v3 = &off_5ADBB8;
  *((_DWORD *)v3 + 1052) = v4;
  v3[1053] = 0.0;
  v3[1056] = 0.0;
  v3[1055] = 0.0;
  v3[1057] = 0.0;
  *((_DWORD *)v3 + 1058) = v5;
  v3[1059] = 0.0;
  *((_DWORD *)v3 + 1060) = 1;
  v6 = OperatorNewNhMallocWrapper(16 * v5);
  *(_DWORD *)(a1 - 16) = v6;
  *(_BYTE *)(a1 - 4) = 1;
  if ( v6 )
  {
    sub_5008C2(v6, 16, v5, (int (__thiscall *)(int))sub_5007EC);
    v7 = *(_DWORD *)(a1 - 16);
  }
  else
  {
    v7 = 0;
  }
  *((_DWORD *)v3 + 1051) = v7;
  if ( !v7 )
    v3[1060] = 0.0;
  if ( *(_DWORD *)(*(_DWORD *)(a1 + 8) + 4) == 1498831189 )
  {
    *((_DWORD *)v3 + 1061) = 8;
    v3[1062] = 0.0;
  }
  else
  {
    v3[1061] = 0.0;
    *((_DWORD *)v3 + 1062) = 8;
  }
  return v3;
}
