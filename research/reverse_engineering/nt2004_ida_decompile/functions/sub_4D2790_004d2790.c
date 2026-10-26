char __thiscall sub_4D2790(int ***this)
{
  int v1; // ebx
  int ***v2; // ebp
  int **v3; // eax
  int *v4; // edi
  _DWORD *v5; // esi
  int v6; // eax
  int v7; // edi
  _DWORD *v8; // eax
  int **v9; // eax
  int *v10; // eax
  int i; // ecx
  int v12; // ebp
  double v13; // st7
  char *v14; // edx
  int *v15; // esi
  int *v16; // edi
  LPVOID *v18; // esi
  LPVOID *v19; // edi
  char v20; // al
  double v21; // [esp+0h] [ebp-50h]
  int v22; // [esp+18h] [ebp-38h]
  float v23; // [esp+18h] [ebp-38h]
  char *ArgList; // [esp+1Ch] [ebp-34h]
  float v25; // [esp+20h] [ebp-30h]
  _DWORD *v26; // [esp+24h] [ebp-2Ch]
  int *v27; // [esp+24h] [ebp-2Ch]
  _DWORD *v28; // [esp+28h] [ebp-28h]
  int *v29; // [esp+2Ch] [ebp-24h]
  int v30; // [esp+30h] [ebp-20h]
  int v31[7]; // [esp+34h] [ebp-1Ch] BYREF

  v22 = 0;
  ArgList = (char *)this[1602];
  if ( !ArgList )
    ArgList = &byte_629120;
  v26 = 0;
  v28 = 0;
  v30 = 0;
  v1 = 0;
  v2 = this + 578;
  do
  {
    v3 = *(v2 - 2);
    *v2 = v3;
    if ( v3 )
    {
      v4 = *v3;
      if ( *v3 )
      {
        do
        {
          v5 = operator new(0xCu);
          if ( v5 )
          {
            v6 = *v4;
            v7 = v4[1];
            *v5 = v6;
            v5[1] = v7;
            v5[2] = v1;
            v8 = operator new(0xCu);
            if ( v8 )
            {
              *v8 = v5;
              v8[1] = 0;
              *((_BYTE *)v8 + 8) = 1;
            }
            else
            {
              v8 = 0;
            }
            if ( v26 )
              v28[1] = v8;
            else
              v26 = v8;
            v28 = v8;
            ++v30;
          }
          ++v22;
          if ( *v2 )
            *v2 = (int **)(*v2)[1];
          v9 = *v2;
          if ( !*v2 )
            break;
          v4 = *v9;
        }
        while ( *v9 );
      }
    }
    ++v1;
    v2 += 4;
  }
  while ( v1 < 256 );
  v10 = (int *)sub_4DB260(v26);
  v27 = v10;
  if ( v10 )
  {
    for ( i = v10[1]; i; i = *(_DWORD *)(i + 4) )
      ;
  }
  v25 = sub_4D9DF0(&unk_7D5DAC);
  if ( v22 )
  {
    sub_57A080(v31);
    if ( (unsigned __int8)sub_57A110(ArgList, 0, 1, 1) )
    {
      v23 = -9.9999996e35;
      v29 = v27;
      if ( v27 )
      {
        v12 = *v27;
        if ( *v27 )
        {
          do
          {
            if ( *(float *)v12 != v23 )
            {
              v13 = *(float *)v12 - v25;
              v23 = v13;
              v21 = v13;
              sub_57A400((int)v31, aEt84f, SLOBYTE(v21));
            }
            v14 = sub_451960(*(_DWORD *)(v12 + 8));
            if ( strlen(v14) && strcmp(v14, aEmpty) )
              sub_57A400((int)v31, aSS_7, (char)v14);
            if ( !v29 )
              break;
            v29 = (int *)v29[1];
            if ( !v29 )
              break;
            v12 = *v29;
          }
          while ( *v29 );
        }
      }
      sub_57A360(v31);
      sub_57A0A0(v31);
      v15 = v27;
      while ( v15 )
      {
        v16 = v15;
        v15 = (int *)v15[1];
        sub_4A82F0((int)v16);
        sub_5BE8AE(v16);
      }
      return 1;
    }
    if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_15, 611) )
      sub_500FE0((int)&unk_7D7920, aCouldnTOpenFil, (char)ArgList);
    sub_57A0A0(v31);
  }
  v18 = (LPVOID *)v27;
  if ( v27 )
  {
    do
    {
      v19 = v18;
      v20 = *((_BYTE *)v18 + 8);
      v18 = (LPVOID *)v18[1];
      if ( v20 )
        sub_5BE8AE(*v19);
      sub_5BE8AE(v19);
    }
    while ( v18 );
  }
  return 0;
}
