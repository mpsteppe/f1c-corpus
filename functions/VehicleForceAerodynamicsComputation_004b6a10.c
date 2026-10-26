char __thiscall sub_4B6A10(int this, int a2, float a3, float a4)
{
  unsigned __int8 v4; // si
  const char *v6; // ebx
  const char *v7; // ebx
  int v8; // ebx
  const char ***v9; // edi
  const char **v10; // eax
  const char *v11; // ecx
  const char **v12; // eax
  _DWORD **v13; // eax
  _DWORD *i; // eax
  int v15; // eax
  _DWORD **v16; // eax
  char v17; // bl
  int *v18; // eax
  int v19; // edx
  int v20; // edi
  int v21; // ecx
  double v22; // st7
  int v23; // eax
  int *v24; // eax
  char v26; // [esp+11h] [ebp-17h] BYREF
  char v27; // [esp+12h] [ebp-16h] BYREF
  char v28; // [esp+13h] [ebp-15h]
  int v29; // [esp+14h] [ebp-14h] BYREF
  int v30; // [esp+18h] [ebp-10h] BYREF
  int v31; // [esp+1Ch] [ebp-Ch] BYREF
  int v32; // [esp+20h] [ebp-8h]
  float v33; // [esp+24h] [ebp-4h] BYREF

  v4 = a2;
  v28 = 1;
  ConditionalAllocInitDispatch(a2);
  ConditionalDispatch_6bd0(off_5D2434, 4);
  ConditionalDispatch_6bd0(&flt_5D2438, 4);
  v6 = *(const char **)(this + 1828);
  if ( !v6 )
    v6 = byte_5EA438;
  v29 = strlen(v6);
  ConditionalDispatch_6bd0(&v29, 4);
  ConditionalDispatch_6bd0(v6, v29);
  v7 = *(const char **)(this + 1836);
  if ( !v7 )
    v7 = byte_5EA438;
  v29 = strlen(v7);
  ConditionalDispatch_6bd0(&v29, 4);
  ConditionalDispatch_6bd0(v7, v29);
  LOBYTE(a2) = *(_BYTE *)(this + 3868);
  ConditionalDispatch_6bd0(&a2, 1);
  v26 = *(_BYTE *)(this + 3872);
  ConditionalDispatch_6bd0(&v26, 1);
  v29 = sub_4B5E30((_DWORD *)this);
  ConditionalDispatch_6bd0(&v29, 4);
  v8 = 0;
  v9 = (const char ***)(this + 72);
  v32 = 104;
  do
  {
    v10 = *(v9 - 2);
    *v9 = v10;
    if ( v10 )
    {
      v11 = *v10;
      if ( *v10 )
      {
        do
        {
          sub_4B4FB0(v11, v4);
          ++v8;
          if ( *v9 )
            *v9 = (const char **)(*v9)[1];
          v12 = *v9;
          if ( !*v9 )
            break;
          v11 = *v12;
        }
        while ( *v12 );
      }
    }
    v9 += 4;
    --v32;
  }
  while ( v32 );
  v27 = *(_BYTE *)(this + 1740);
  ConditionalDispatch_6bd0(&v27, 1);
  v13 = *(_DWORD ***)(this + 1728);
  *(_DWORD *)(this + 1736) = v13;
  if ( v13 )
  {
    for ( i = *v13; i; i = *v16 )
    {
      FileStreamWriter(i, v4);
      v15 = *(_DWORD *)(this + 1736);
      if ( !v15 )
        break;
      v16 = *(_DWORD ***)(v15 + 4);
      *(_DWORD *)(this + 1736) = v16;
      if ( !v16 )
        break;
    }
  }
  if ( v29 == v8 )
    v17 = v28;
  else
    v17 = 0;
  v18 = *(int **)(this + 1812);
  v19 = 0;
  v20 = 0;
  v30 = 0;
  v31 = 0;
  *(_DWORD *)(this + 1820) = v18;
  if ( !v18 )
    return 0;
  v21 = *v18;
  if ( !*v18 )
    return 0;
  do
  {
    v22 = *(float *)v21;
    if ( v22 > a4 )
      break;
    if ( v22 >= a3 )
    {
      if ( !v20 )
        v20 = v21;
      ++v30;
      v19 = v21;
      v31 += *(unsigned __int16 *)(v21 + 8);
    }
    v23 = *(_DWORD *)(this + 1820);
    if ( v23 )
      *(_DWORD *)(this + 1820) = *(_DWORD *)(v23 + 4);
    v24 = *(int **)(this + 1820);
    if ( !v24 )
      break;
    v21 = *v24;
  }
  while ( *v24 );
  if ( !v20 || !v19 )
    return 0;
  ConditionalDispatch_6bd0(&v30, 4);
  ConditionalDispatch_6bd0(&v31, 4);
  v33 = a4 - a3;
  ConditionalDispatch_6bd0(&v33, 4);
  return v17;
}
