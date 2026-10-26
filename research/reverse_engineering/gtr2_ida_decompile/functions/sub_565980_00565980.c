char __thiscall sub_565980(int this)
{
  char *v2; // eax
  char *v3; // edi
  char *v4; // esi
  unsigned int v5; // eax
  int v6; // eax
  char *v7; // edx
  char v8; // cl
  int v9; // ebp
  unsigned int v10; // eax
  char *v11; // edi
  unsigned int v13; // eax
  int v14; // eax
  char *v15; // edx
  char v16; // cl
  int v17; // ebp
  unsigned int v18; // eax
  char *v19; // edi
  char *v22; // [esp+1Ch] [ebp-8Ch]
  char v23[7]; // [esp+20h] [ebp-88h] BYREF
  char v24; // [esp+27h] [ebp-81h] BYREF
  char Buffer[128]; // [esp+28h] [ebp-80h] BYREF

  LOBYTE(v2) = *(_BYTE *)(this + 24);
  if ( (_BYTE)v2 )
  {
    v3 = dword_91E07C;
    v4 = *(char **)(this + 28);
    v22 = dword_91E07C;
  }
  else
  {
    v2 = *(char **)(this + 28);
    v4 = dword_91E07C;
    v22 = v2;
    v3 = v2;
  }
  if ( v4 && v3 )
  {
    v5 = *((_DWORD *)v4 + 4831) - 1;
    if ( v5 <= 0x18 )
    {
      sprintf(Buffer, "%c", (char)(v5 + byte_903BA0));
      sub_562B70((int)Buffer, 100, 50, (int)byte_FFFFFF, 0, 7, 3.0, 3.0);
    }
    v6 = (int)&v4[108 * *((_DWORD *)v4 + 5447) + 21656];
    v7 = &Buffer[-v6];
    do
    {
      v8 = *(_BYTE *)v6;
      v7[v6] = *(_BYTE *)v6;
      ++v6;
    }
    while ( v8 );
    _strupr(Buffer);
    sub_562B70((int)Buffer, 210, 50, (int)byte_FFFFFF, 0, 0, 1.0, 1.0);
    v9 = 0;
    Buffer[0] = 0;
    if ( dword_903BAC > 0 )
    {
      do
      {
        sprintf(v23, "%c", v9 + byte_903BA7);
        v10 = strlen(v23) + 1;
        v11 = &v24;
        while ( *++v11 )
          ;
        qmemcpy(v11, v23, v10);
        ++v9;
      }
      while ( v9 < dword_903BAC );
      v3 = v22;
    }
    sub_562B70((int)Buffer, 210, 100, (int)byte_FFFFFF, 0, 7, 1.0, 1.0);
    sprintf(Buffer, "%6.3f", (double)fabs(*(float *)(this + 20)));
    sub_562B70((int)Buffer, 640, 90, (int)dword_FFFF00, 2, 0, 1.0, 1.0);
    v13 = *((_DWORD *)v3 + 4831) - 1;
    if ( v13 <= 0x18 )
    {
      sprintf(Buffer, "%c", (char)(v13 + byte_903BA0));
      sub_562B70((int)Buffer, 1180, 50, (int)byte_FFFFFF, 1, 7, 3.0, 3.0);
    }
    v14 = (int)&v3[108 * *((_DWORD *)v3 + 5447) + 21656];
    v15 = &Buffer[-v14];
    do
    {
      v16 = *(_BYTE *)v14;
      v15[v14] = *(_BYTE *)v14;
      ++v14;
    }
    while ( v16 );
    _strupr(Buffer);
    sub_562B70((int)Buffer, 1070, 50, (int)byte_FFFFFF, 1, 0, 1.0, 1.0);
    v17 = 0;
    for ( Buffer[0] = 0; v17 < dword_903BAC; ++v17 )
    {
      sprintf(v23, "%c", v17 + byte_903BA8);
      v18 = strlen(v23) + 1;
      v19 = &v24;
      while ( *++v19 )
        ;
      qmemcpy(v19, v23, v18);
    }
    LOBYTE(v2) = sub_562B70((int)Buffer, 1070, 100, (int)byte_FFFFFF, 1, 7, 1.0, 1.0);
  }
  return (char)v2;
}
