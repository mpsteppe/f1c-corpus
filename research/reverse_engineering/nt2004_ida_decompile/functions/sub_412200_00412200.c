char __stdcall sub_412200(int a1)
{
  _DWORD *v1; // eax
  _DWORD *v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int i; // ebp
  _DWORD *v9; // edi
  _DWORD *v10; // eax
  _DWORD *v11; // edi
  _DWORD *v12; // eax
  _DWORD *v13; // edi
  int v14; // eax
  int j; // ebp
  _DWORD *v16; // edi
  int v17; // eax
  int v18; // eax

  v1 = operator new(0x58u);
  v2 = v1;
  if ( v1 )
  {
    *v1 = 0;
    v1[1] = -1;
    v1[2] = 0;
    v1[3] = -1;
    v1[4] = 0;
    v1[5] = -1;
    sub_578600(a100);
    v2[6] = 0;
    v2[7] = -1;
    v2[8] = 0;
    v2[9] = -1;
    sub_414400(v2 + 10);
    sub_414400(v2 + 14);
    sub_414400(v2 + 18);
  }
  else
  {
    v2 = 0;
  }
  v3 = sub_4ED6E0(&dword_7D6B74);
  sub_578600(v3);
  v4 = sub_4ED6F0(&dword_7D6B74);
  sub_578600(v4);
  v5 = sub_4ED700(&dword_7D6B74);
  sub_578600(v5);
  v6 = sub_4ED710(&dword_7D6B74);
  sub_578600(v6);
  v7 = sub_4ED720(&dword_7D6B74);
  sub_578600(v7);
  for ( i = 0; i < sub_4ED730(&dword_7D6B74); ++i )
  {
    v9 = operator new(4u);
    if ( v9 )
    {
      *v9 = sub_4ED740(i);
      v10 = operator new(0xCu);
      if ( v10 )
      {
        *v10 = v9;
        v10[1] = 0;
        *((_BYTE *)v10 + 8) = 1;
      }
      else
      {
        v10 = 0;
      }
      if ( v2[10] )
      {
        *(_DWORD *)(v2[11] + 4) = v10;
      }
      else
      {
        v2[10] = v10;
        v2[12] = v10;
      }
      v2[11] = v10;
      ++v2[13];
    }
  }
  v11 = operator new(4u);
  if ( v11 )
    *v11 = sub_4ED760(0);
  else
    v11 = 0;
  if ( v11 )
  {
    v12 = operator new(0xCu);
    if ( v12 )
    {
      *v12 = v11;
      v12[1] = 0;
      *((_BYTE *)v12 + 8) = 1;
    }
    else
    {
      v12 = 0;
    }
    if ( v2[14] )
    {
      *(_DWORD *)(v2[15] + 4) = v12;
    }
    else
    {
      v2[14] = v12;
      v2[16] = v12;
    }
    v2[15] = v12;
    ++v2[17];
  }
  v13 = operator new(4u);
  if ( v13 )
    *v13 = sub_4ED760(2);
  else
    v13 = 0;
  if ( v13 )
  {
    if ( operator new(0xCu) )
      v14 = sub_4DB610(v13, 1);
    else
      v14 = 0;
    if ( v2[14] )
    {
      *(_DWORD *)(v2[15] + 4) = v14;
    }
    else
    {
      v2[14] = v14;
      v2[16] = v14;
    }
    v2[15] = v14;
    ++v2[17];
  }
  for ( j = 0; j < 10; ++j )
  {
    if ( sub_4ED8A0(j) )
    {
      v16 = operator new(8u);
      if ( v16 )
      {
        v17 = sub_4ED8A0(j);
        *v16 = 0;
        v16[1] = -1;
        sub_578600(v17);
      }
      else
      {
        v16 = 0;
      }
      if ( v16 )
      {
        if ( operator new(0xCu) )
          v18 = sub_4DB610(v16, 1);
        else
          v18 = 0;
        if ( v2[18] )
        {
          *(_DWORD *)(v2[19] + 4) = v18;
        }
        else
        {
          v2[18] = v18;
          v2[20] = v18;
        }
        v2[19] = v18;
        ++v2[21];
      }
    }
  }
  sub_50B320(v2);
  return 1;
}
