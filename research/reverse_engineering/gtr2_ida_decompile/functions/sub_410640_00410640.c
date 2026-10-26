int __thiscall sub_410640(_DWORD *this)
{
  _DWORD *v2; // eax
  int v3; // eax
  const char *v4; // esi
  char *v5; // eax
  char v6; // cl
  int v7; // kr00_4
  char *i; // eax
  const char *v9; // eax
  char *v10; // edx
  char v11; // cl
  char *v12; // eax
  unsigned int v13; // eax
  char *v14; // edi
  unsigned int v16; // eax
  char *v17; // edi
  char v20; // [esp+7h] [ebp-241h] BYREF
  char v21[63]; // [esp+8h] [ebp-240h] BYREF
  char v22; // [esp+47h] [ebp-201h] BYREF
  char v23[512]; // [esp+48h] [ebp-200h] BYREF

  if ( !this[10] )
  {
    v2 = operator new(0x18u);
    if ( v2 )
    {
      v2[1] = 0;
      *v2 = &off_6F2014;
      v2[2] = 0;
      v2[3] = 0;
      v2[4] = 0;
      v2[5] = 0;
    }
    else
    {
      v2 = 0;
    }
    this[10] = v2;
  }
  v3 = dword_BE1CD8 + 396 * dword_BE1CD4;
  if ( v3 )
  {
    v4 = (const char *)(v3 + 4);
    v5 = (char *)(v3 + 4);
    do
    {
      v6 = *v5;
      v5[v23 - v4] = *v5;
      ++v5;
    }
    while ( v6 );
    v7 = strlen(v23);
    if ( v7 > 0 )
    {
      for ( i = &v23[v7 - 1]; i >= v23; *i-- = 0 )
      {
        if ( *i == 92 )
          break;
      }
    }
    v9 = &v4[strlen(v4)];
    if ( v9 > v4 )
    {
      while ( *v9 != 92 )
      {
        if ( --v9 <= v4 )
          goto LABEL_18;
      }
      ++v9;
    }
LABEL_18:
    v10 = (char *)(v21 - v9);
    do
    {
      v11 = *v9;
      v9[(_DWORD)v10] = *v9;
      ++v9;
    }
    while ( v11 );
    v12 = &v21[strlen(v21)];
    if ( v12 > v21 )
    {
      while ( *v12 != 46 )
      {
        if ( --v12 <= v21 )
          goto LABEL_25;
      }
      *v12 = 0;
    }
LABEL_25:
    v13 = strlen(aCam) + 1;
    v14 = &v20;
    while ( *++v14 )
      ;
    qmemcpy(v14, aCam, v13);
    v16 = strlen(v21) + 1;
    v17 = &v22;
    while ( *++v17 )
      ;
    qmemcpy(v17, v21, v16);
    (*(void (__thiscall **)(_DWORD, char *))(*(_DWORD *)this[10] + 4))(this[10], v23);
  }
  return 0;
}
