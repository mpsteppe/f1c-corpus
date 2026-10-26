int __thiscall sub_5E9C00(int this, int a2, const char *a3)
{
  int v3; // esi
  int v4; // edi
  int v5; // esi
  char *v6; // ebp
  int v7; // esi
  char *v8; // ebx
  char *v9; // eax
  char v10; // dl
  char *v11; // eax
  int v12; // ebx
  char v13; // cl
  int v16; // edi
  char *v17; // ebx
  _BYTE v18[64]; // [esp+10h] [ebp-40h] BYREF

  switch ( *(_DWORD *)(this + 252) )
  {
    case 1:
      v3 = *(_DWORD *)(this + 264);
      break;
    case 2:
      v3 = *(_DWORD *)(this + 532);
      break;
    case 3:
      v3 = *(_DWORD *)(this + 800);
      break;
    default:
      v3 = 0;
      break;
  }
  v4 = *(_DWORD *)(this + 260);
  v5 = 484 * (a2 + v3);
  v6 = *(char **)(v5 + v4 + 220);
  v7 = v4 + v5;
  v8 = (char *)(v7 + 12);
  v9 = (char *)(v7 + 12);
  do
  {
    v10 = *v9;
    v18[(_DWORD)v9 - 12 - v7] = *v9;
    ++v9;
  }
  while ( v10 );
  strcpy(v8, a3);
  if ( sub_5E3AA0((char *)v7, COERCE_FLOAT(this + 4), (const char *)(this + 68), *(float *)(this + 244), 0) )
  {
    v11 = v18;
    v12 = v8 - v18;
    do
    {
      v13 = *v11;
      v11[v12] = *v11;
      ++v11;
    }
    while ( v13 );
    *(_DWORD *)(v7 + 220) = v6;
    return -1;
  }
  else
  {
    if ( v6 )
    {
      if ( (*((_DWORD *)v6 + 27))-- == 1 )
      {
        v16 = 0;
        if ( *(int *)(v7 + 4) > 0 )
        {
          v17 = v6;
          do
          {
            sub_5E2B10(v17);
            ++v16;
            v17 += 216;
          }
          while ( v16 < *(_DWORD *)(v7 + 4) );
        }
        sub_5D9A40((int *)&dword_FB2D78, (int)v6, 1);
        `eh vector destructor iterator'(v6, 0xD8u, *((_DWORD *)v6 - 1), j_j_nullsub_7);
        j__free(v6 - 4);
      }
    }
    return 0;
  }
}
