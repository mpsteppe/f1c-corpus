char __thiscall sub_4D63D0(int this, int a2, float a3, float a4, char a5)
{
  int v5; // esi
  char *v7; // ebx
  char *v8; // ebx
  int v9; // ebx
  char ***v10; // edi
  char **v11; // eax
  char *v12; // ecx
  char **v13; // eax
  const char ***v14; // eax
  const char **i; // eax
  int v16; // eax
  const char ***v17; // eax
  char v18; // bl
  int *v19; // eax
  int v20; // edx
  int v21; // edi
  int v22; // ecx
  double v23; // st7
  int v24; // eax
  int *v25; // eax
  char v27; // [esp+11h] [ebp-17h] BYREF
  char v28; // [esp+12h] [ebp-16h] BYREF
  char v29; // [esp+13h] [ebp-15h]
  size_t Buffer; // [esp+14h] [ebp-14h] BYREF
  int v31; // [esp+18h] [ebp-10h] BYREF
  int v32; // [esp+1Ch] [ebp-Ch] BYREF
  int v33; // [esp+20h] [ebp-8h]
  float v34; // [esp+24h] [ebp-4h] BYREF

  v5 = a2;
  v29 = 1;
  sub_57A530(a2);
  sub_57A3A0(off_60FE44, 4u);
  sub_57A3A0(&flt_60FE48, 4u);
  v7 = *(char **)(this + 948);
  if ( !v7 )
    v7 = &byte_629120;
  Buffer = strlen(v7);
  sub_57A3A0(&Buffer, 4u);
  sub_57A3A0(v7, Buffer);
  v8 = *(char **)(this + 956);
  if ( !v8 )
    v8 = &byte_629120;
  Buffer = strlen(v8);
  sub_57A3A0(&Buffer, 4u);
  sub_57A3A0(v8, Buffer);
  v27 = *(_BYTE *)(this + 2040);
  sub_57A3A0(&v27, 1u);
  v28 = *(_BYTE *)(this + 2044);
  sub_57A3A0(&v28, 1u);
  Buffer = sub_4D56F0((_DWORD *)this);
  sub_57A3A0(&Buffer, 4u);
  v9 = 0;
  v10 = (char ***)(this + 72);
  v33 = 49;
  do
  {
    v11 = *(v10 - 2);
    *v10 = v11;
    if ( v11 )
    {
      v12 = *v11;
      if ( *v11 )
      {
        do
        {
          sub_4D4070(v12, v5);
          ++v9;
          if ( *v10 )
            *v10 = (char **)(*v10)[1];
          v13 = *v10;
          if ( !*v10 )
            break;
          v12 = *v13;
        }
        while ( *v13 );
      }
    }
    v10 += 4;
    --v33;
  }
  while ( v33 );
  if ( a5 )
    LOBYTE(a2) = *(_BYTE *)(this + 860);
  else
    LOBYTE(a2) = 0;
  sub_57A3A0(&a2, 1u);
  if ( (_BYTE)a2 )
  {
    v14 = *(const char ****)(this + 848);
    *(_DWORD *)(this + 856) = v14;
    if ( v14 )
    {
      for ( i = *v14; i; i = *v17 )
      {
        sub_4D3130(i, v5);
        v16 = *(_DWORD *)(this + 856);
        if ( !v16 )
          break;
        v17 = *(const char ****)(v16 + 4);
        *(_DWORD *)(this + 856) = v17;
        if ( !v17 )
          break;
      }
    }
  }
  if ( Buffer == v9 )
    v18 = v29;
  else
    v18 = 0;
  v19 = *(int **)(this + 932);
  v20 = 0;
  v21 = 0;
  v31 = 0;
  v32 = 0;
  *(_DWORD *)(this + 940) = v19;
  if ( !v19 )
    return 0;
  v22 = *v19;
  if ( !*v19 )
    return 0;
  do
  {
    v23 = *(float *)v22;
    if ( v23 > a4 )
      break;
    if ( v23 >= a3 )
    {
      if ( !v21 )
        v21 = v22;
      ++v31;
      v20 = v22;
      v32 += *(unsigned __int16 *)(v22 + 8);
    }
    v24 = *(_DWORD *)(this + 940);
    if ( v24 )
      *(_DWORD *)(this + 940) = *(_DWORD *)(v24 + 4);
    v25 = *(int **)(this + 940);
    if ( !v25 )
      break;
    v22 = *v25;
  }
  while ( *v25 );
  if ( !v21 || !v20 )
    return 0;
  sub_57A3A0(&v31, 4u);
  sub_57A3A0(&v32, 4u);
  v34 = a4 - a3;
  sub_57A3A0(&v34, 4u);
  return v18;
}
