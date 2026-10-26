int __thiscall sub_502A15(int this, unsigned __int8 *a2, unsigned int a3, _DWORD *a4, int a5)
{
  int v5; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  unsigned int v13; // eax
  void *v14; // ecx
  void *v15; // ecx
  bool v16; // cf
  _DWORD *i; // eax
  _DWORD *v19; // eax
  int v20; // ecx
  _DWORD v21[7]; // [esp+Ch] [ebp-20h]
  int v22; // [esp+28h] [ebp-4h]

  v5 = a3;
  v21[0] = 0;
  v21[1] = 5;
  v21[2] = 4;
  v21[3] = 1;
  v21[4] = 3;
  v21[5] = 2;
  v21[6] = 6;
  v22 = 0;
  do
  {
    *(_DWORD *)(this + 64) = a5;
    v7 = v21[v22];
    *(_DWORD *)(this + 72) = v7;
    *(_DWORD *)(this + 68) = 3;
    if ( !v7 )
    {
      v13 = BMPHeaderValidation((int *)this, (int)a2, a3);
      goto LABEL_16;
    }
    v8 = v7 - 1;
    if ( !v8 )
    {
      v13 = ImageTextureDecompressor((_DWORD *)this, (int)a2, a3);
      goto LABEL_16;
    }
    v9 = v8 - 1;
    if ( !v9 )
    {
      v13 = DDSHeaderParsing((int *)this, a2, a3);
      goto LABEL_16;
    }
    v10 = v9 - 1;
    if ( !v10 )
    {
      v13 = sub_50210E((int *)this, (int)a2, a3);
      goto LABEL_16;
    }
    v11 = v10 - 1;
    if ( !v11 )
    {
      v13 = DDSTextureSurfaceCreation((_DWORD *)this, (int)a2, a3);
      goto LABEL_16;
    }
    v12 = v11 - 1;
    if ( !v12 )
    {
      v13 = PPMP6ImageDecoder((_DWORD *)this, a2, a3);
      goto LABEL_16;
    }
    if ( v12 == 1 )
    {
      v13 = DDSTextureFormatValidationDecoding((int *)this, (int)a2, a3);
LABEL_16:
      v5 = v13;
    }
    if ( v5 >= 0 )
      break;
    if ( *(_DWORD *)(this + 4) && *(_DWORD *)(this + 56) )
      FreeWrapper_7bcf(*(LPVOID *)(this + 4));
    if ( *(_DWORD *)(this + 8) && *(_DWORD *)(this + 60) )
      FreeWrapper_7bcf(*(LPVOID *)(this + 8));
    v14 = *(void **)(this + 76);
    if ( v14 )
      ShortComputation_0fae(v14, 1);
    v15 = *(void **)(this + 80);
    if ( v15 )
      ShortComputation_0fae(v15, 1);
    v16 = (unsigned int)++v22 < 7;
    *(_DWORD *)(this + 4) = 0;
    *(_DWORD *)(this + 8) = 0;
    *(_DWORD *)(this + 56) = 0;
    *(_DWORD *)(this + 60) = 0;
    *(_DWORD *)(this + 76) = 0;
    *(_DWORD *)(this + 80) = 0;
  }
  while ( v16 );
  if ( v22 == 7 )
    return -2005529767;
  if ( a4 )
  {
    memset(a4, 0, 0x1Cu);
    *a4 = *(_DWORD *)(this + 12);
    a4[1] = *(_DWORD *)(this + 16);
    a4[2] = *(_DWORD *)(this + 20);
    a4[3] = 1;
    a4[4] = FourCCDecoder(*(_DWORD *)this);
    a4[5] = *(_DWORD *)(this + 68);
    a4[6] = *(_DWORD *)(this + 72);
    for ( i = (_DWORD *)(this + 76); *i; i = (_DWORD *)(*i + 76) )
      ++a4[3];
  }
  do
  {
    v19 = (_DWORD *)this;
    if ( this )
    {
      do
      {
        v19[8] = v19[3];
        v19[9] = v19[4];
        v20 = v19[5];
        v19[6] = 0;
        v19[7] = 0;
        v19[10] = 0;
        v19[11] = v20;
        v19 = (_DWORD *)v19[19];
      }
      while ( v19 );
    }
    this = *(_DWORD *)(this + 80);
  }
  while ( this );
  return 0;
}

