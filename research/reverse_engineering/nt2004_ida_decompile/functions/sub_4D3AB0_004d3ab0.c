int __thiscall sub_4D3AB0(_BYTE *this, int a2, float *Buffer)
{
  _DWORD *v4; // esi
  int v5; // edi
  int v6; // eax
  int v7; // ecx
  int i; // edx
  int v9; // eax
  int *v10; // ecx
  _BYTE *v12; // edi
  _BYTE *v13; // ecx
  int v14; // esi
  int *v15; // eax
  bool v16; // zf
  int v17; // edx
  int *v18; // eax
  int v19; // ebp
  double v20; // st7
  _DWORD *v21; // esi
  _DWORD *v22; // eax
  float **v23; // eax
  int *v24; // eax
  __int16 v25; // ax
  float **v26; // ecx
  float *v27; // esi
  float **v28; // eax
  float v29; // [esp+10h] [ebp-1Ch]
  int v30; // [esp+14h] [ebp-18h]
  int v31; // [esp+18h] [ebp-14h]
  float **v32; // [esp+1Ch] [ebp-10h] BYREF
  float **v33; // [esp+20h] [ebp-Ch]
  float **v34; // [esp+24h] [ebp-8h]
  int v35; // [esp+28h] [ebp-4h]

  v30 = 0;
  if ( *this )
  {
    v4 = this + 64;
    v5 = 4;
    do
    {
      v6 = sub_4DB380(*v4);
      v7 = v6;
      *v4 = v6;
      if ( v6 )
      {
        for ( i = *(_DWORD *)(v6 + 4); i; i = *(_DWORD *)(i + 4) )
          v7 = i;
      }
      v4[1] = v7;
      v4[2] = v6;
      v4 += 4;
      --v5;
    }
    while ( v5 );
    *this = 0;
  }
  v9 = 0;
  v10 = (int *)(this + 76);
  do
  {
    if ( *v10 > 0 )
      break;
    ++v9;
    v10 += 4;
  }
  while ( v9 < 4 );
  if ( v9 == 4 )
    return 0;
  v12 = this + 64;
  v29 = 9.9999997e37;
  v13 = this + 64;
  v14 = 4;
  do
  {
    v15 = *(int **)v13;
    v16 = *(_DWORD *)v13 == 0;
    *((_DWORD *)v13 + 2) = *(_DWORD *)v13;
    if ( !v16 )
    {
      v17 = *v15;
      if ( *v15 )
      {
        if ( *(float *)(v17 + 4) < (double)v29 )
          v29 = *(float *)(v17 + 4);
      }
    }
    v13 += 16;
    --v14;
  }
  while ( v14 );
  v32 = 0;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v31 = 4;
  do
  {
    v18 = *(int **)v12;
    v16 = *(_DWORD *)v12 == 0;
    *((_DWORD *)v12 + 2) = *(_DWORD *)v12;
    if ( !v16 )
    {
      v19 = *v18;
      if ( *v18 )
      {
        do
        {
          v20 = v29 - *(float *)(v19 + 4);
          if ( v20 <= -0.02 || v20 >= 0.02 )
            break;
          v21 = *(_DWORD **)v12;
          v22 = 0;
          if ( *(_DWORD *)v12 )
          {
            while ( *v21 != v19 )
            {
              v22 = v21;
              v21 = (_DWORD *)v21[1];
              if ( !v21 )
                goto LABEL_36;
            }
            if ( v21 == *((_DWORD **)v12 + 2) )
              *((_DWORD *)v12 + 2) = v21[1];
            if ( v22 )
              v22[1] = v21[1];
            else
              *(_DWORD *)v12 = v21[1];
            if ( *((_DWORD **)v12 + 1) == v21 )
              *((_DWORD *)v12 + 1) = v22;
            --*((_DWORD *)v12 + 3);
            sub_4A82F0((int)v21);
            sub_5BE8AE(v21);
          }
LABEL_36:
          v23 = operator new(0xCu) ? (float **)sub_4DB610(v19, 0) : 0;
          if ( v32 )
          {
            v33[1] = (float *)v23;
          }
          else
          {
            v32 = v23;
            v34 = v23;
          }
          v33 = v23;
          v24 = *(int **)v12;
          v16 = *(_DWORD *)v12 == 0;
          ++v35;
          *((_DWORD *)v12 + 2) = v24;
          if ( v16 )
            break;
          v19 = *v24;
        }
        while ( *v24 );
      }
    }
    v12 += 16;
    --v31;
  }
  while ( v31 );
  v25 = v35;
  *Buffer = v29;
  *((_WORD *)Buffer + 4) = v25;
  sub_4D33D0(Buffer, a2);
  v26 = v32;
  v34 = v32;
  if ( v32 )
  {
    v27 = *v32;
    if ( *v32 )
    {
      while ( 1 )
      {
        if ( v27 )
        {
          v28 = 0;
          if ( v26 )
          {
            while ( *v26 != v27 )
            {
              v28 = v26;
              v26 = (float **)v26[1];
              if ( !v26 )
                goto LABEL_62;
            }
            if ( v26 == v34 )
              v34 = (float **)v26[1];
            if ( v28 )
              v28[1] = v26[1];
            else
              v32 = (float **)v26[1];
            if ( v33 == v26 )
              v33 = v28;
            --v35;
            sub_466750((int)v26, 1);
          }
        }
LABEL_62:
        sub_4D3230(a2, *Buffer, v27);
        ++v30;
        sub_4DBCF0(v27, 0);
        v27 = (float *)sub_4DAD90(&v32);
        if ( !v27 )
          break;
        v26 = v32;
      }
    }
  }
  sub_4DB110(&v32);
  return v30;
}
