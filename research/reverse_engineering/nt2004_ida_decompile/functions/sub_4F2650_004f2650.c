int __thiscall sub_4F2650(char *this, char a2)
{
  double v3; // st7
  char v4; // cl
  int result; // eax
  _DWORD *v6; // ebx
  int v7; // edi
  _DWORD *v8; // eax
  _DWORD *v9; // ebp
  _DWORD *v10; // edx
  int v11; // edx
  double v12; // st7
  double v13; // st7
  int v14; // edi
  int v15; // ebp
  int v16; // esi
  float *v17; // esi
  double v18; // st7
  double v19; // st7
  int v20; // edx
  float *v21; // ecx
  double v22; // st7
  double v23; // st6
  int v24; // edx
  int v25; // edx
  long double v26; // st6
  long double v27; // st6
  double v28; // st7
  float v29; // [esp+Ch] [ebp-10Ch]
  float v30; // [esp+Ch] [ebp-10Ch]
  float v31; // [esp+10h] [ebp-108h]
  char ArgList[256]; // [esp+18h] [ebp-100h] BYREF

  dword_611390 = dword_767D90;
  flt_611394 = flt_767D6C * flt_767D6C;
  v3 = flt_767D6C + *(float *)&dword_767D90;
  flt_611398 = v3;
  flt_61139C = v3 * 1.4142135;
  if ( a2 )
  {
    v4 = 4 - dword_767CA0;
    *((_DWORD *)this + 2) = 4 - dword_767CA0;
    if ( dword_767CA0 )
    {
      *((int *)this + 24) >>= v4;
    }
    else
    {
      *((_DWORD *)this + 24) = 0;
      *((_DWORD *)this + 27) = 0;
    }
  }
  else if ( !dword_767FD0 )
  {
    *((_DWORD *)this + 24) = 0;
  }
  result = *((_DWORD *)this + 24);
  if ( result > 0 )
  {
    sprintf(*((char *const *)this + 22), "Reaction%02d", *(_DWORD *)this);
    *(_DWORD *)(*((_DWORD *)this + 22) + 36) = *((_DWORD *)this + 24);
    *(_DWORD *)(*((_DWORD *)this + 22) + 40) = *((_DWORD *)this + 3);
    *(_DWORD *)(*((_DWORD *)this + 22) + 44) = *((_DWORD *)this + 4);
    *(_DWORD *)(*((_DWORD *)this + 22) + 48) = *((_DWORD *)this + 5);
    v6 = this + 92;
    if ( sub_5B1190(this + 92, *((_DWORD *)this + 22)) )
    {
      sub_591C90(0, ArgList);
      if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_20, 914) )
        sub_500FE0((int)&unk_7D7920, aCouldNotCreate_0, *(_DWORD *)(*((_DWORD *)this + 22) + 36));
      result = sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_20, 917);
      if ( (_BYTE)result )
        return sub_500FE0((int)&unk_7D7920, aCubeErrorS, (char)ArgList);
    }
    else
    {
      v7 = *((_DWORD *)this + 24);
      v8 = operator new(108 * v7 + 4);
      if ( v8 )
      {
        v9 = v8 + 1;
        *v8 = v7;
        v10 = v8 + 1;
        if ( v7 - 1 >= 0 )
        {
          do
          {
            sub_4F1160(v10);
            v10 = (_DWORD *)(v11 + 108);
            --v7;
          }
          while ( v7 );
        }
      }
      else
      {
        v9 = 0;
      }
      v12 = *((float *)this + 12);
      *((_DWORD *)this + 25) = v9;
      *((_DWORD *)this + 26) = 0;
      if ( v12 <= 0.0 )
        v13 = 0.0;
      else
        v13 = 1.0 / *((float *)this + 12);
      *((_DWORD *)this + 27) = 0;
      *((float *)this + 18) = v13;
      *((_DWORD *)this + 28) = operator new(4 * *((_DWORD *)this + 24));
      result = *((_DWORD *)this + 24);
      v14 = 0;
      if ( result > 0 )
      {
        v15 = 0;
        do
        {
          *(_DWORD *)(*((_DWORD *)this + 25) + v15) = v14;
          *(_DWORD *)(*((_DWORD *)this + 25) + v15 + 4) = -1;
          sub_4F1170(
            v15 + *((_DWORD *)this + 25),
            *((float *)this + 12),
            *((float *)this + 13),
            *((float *)this + 14),
            *((float *)this + 15),
            *((float *)this + 16),
            *((float *)this + 17));
          *(_DWORD *)(*((_DWORD *)this + 28) + 4 * v14) = 0;
          result = *((_DWORD *)this + 24);
          ++v14;
          v15 += 108;
        }
        while ( v14 < result );
        v6 = this + 92;
      }
      v16 = *((_DWORD *)this + 1);
      if ( v16 == 16 )
      {
        dword_7D7420 = 0;
        v17 = &flt_7D6FD4;
        do
        {
          do
          {
            v18 = flt_7D4054[(unsigned __int8)dword_7D3C50++] * 20.0;
            v29 = v18;
            v19 = ((double)(sub_4D1A80(&dword_7D3C50) & 0x1FFFF) * 0.000015258789 - 1.0) * 20.0;
          }
          while ( v19 * v19 + v29 * v29 >= 400.0 );
          *v17 = v19;
          *(v17 - 1) = v29;
          v17 += 2;
        }
        while ( (int)v17 < (int)&flt_7D73D4 );
        v20 = dword_7D3C50;
        v21 = (float *)&unk_7D6D58;
        do
        {
          v22 = flt_7D4054[(unsigned __int8)v20];
          dword_7D3C50 = v20 + 1;
          v23 = flt_7D4054[(unsigned __int8)(v20 + 1)];
          v24 = v20 + 2;
          dword_7D3C50 = v24;
          v30 = v23;
          v31 = flt_7D4054[(unsigned __int8)v24];
          *v21 = v22;
          *(v21 - 2) = v31;
          *(v21 - 1) = v30;
          v25 = v24 + 1;
          dword_7D3C50 = v25;
          v26 = v31 * v31 + v30 * v30 + v22 * v22;
          if ( v26 == 0.0 )
          {
            *(v21 - 2) = 0.0;
            *(v21 - 1) = 1.0;
            *v21 = 0.0;
          }
          else
          {
            v27 = 1.0 / sqrt(v26);
            *(v21 - 2) = v31 * v27;
            *(v21 - 1) = v30 * v27;
            *v21 = v27 * v22;
          }
          result = (unsigned __int8)v25;
          v28 = flt_7D3C54[(unsigned __int8)v25];
          v20 = v25 + 1;
          v21 += 10;
          dword_7D3C50 = v20;
          *(v21 - 9) = -24.0 - v28 * 3.0;
        }
        while ( (int)v21 < (int)flt_7D6FD8 );
      }
      else if ( v16 == 9 )
      {
        if ( *v6 )
          return sub_5B0BD0(2);
      }
      else if ( v16 == 17 && *v6 )
      {
        return sub_5B0BD0(1);
      }
    }
  }
  return result;
}
