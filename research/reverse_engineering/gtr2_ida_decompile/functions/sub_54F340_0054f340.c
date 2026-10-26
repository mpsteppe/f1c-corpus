int __thiscall sub_54F340(int this)
{
  int v2; // ebx
  int v3; // ebp
  _DWORD *v4; // edi
  int i; // ecx
  int v6; // eax
  int j; // edx
  int v8; // eax
  char v9; // cl
  int v10; // eax
  char v11; // cl
  char v12; // cl
  char v13; // cl
  char v14; // cl
  char v15; // cl
  int v17; // [esp+0h] [ebp-368h]
  int v18; // [esp+0h] [ebp-368h]
  _DWORD v19[212]; // [esp+18h] [ebp-350h] BYREF

  v2 = 0;
  v3 = *(_DWORD *)(this + 1672) + *(_DWORD *)(this + 836);
  if ( (unsigned __int8)sub_4735A0() )
  {
    *(float *)&v17 = dbl_FB1D18;
    sub_51B2A0(v19, 4, 33, v3, 255, v17, 3);
    v4 = v19;
  }
  else
  {
    v4 = (_DWORD *)off_9034A4;
    if ( dword_82F4A0 < 1023 )
    {
      ++dword_82F4A0;
      off_9034A4 += 848;
    }
    *(float *)&v18 = dbl_FB1D18;
    sub_51B2A0(v4, 4, 33, v3, 255, v18, 0);
  }
  for ( i = 0; i < *(_DWORD *)(this + 1672); ++i )
  {
    if ( v2 >= 104 )
      break;
    if ( i < 0 || i >= *(_DWORD *)(this + 1672) )
      v6 = -2;
    else
      v6 = *(_DWORD *)(this + 8 * i + 840);
    if ( byte_925105[22616 * v6] )
      LOBYTE(v6) = v6 | 0x40;
    *((_BYTE *)v4 + v2++ + 8) = v6;
  }
  for ( j = 0; j < *(_DWORD *)(this + 836); ++j )
  {
    if ( v2 >= 104 )
      break;
    if ( j < 0 || j >= *(_DWORD *)(this + 836) )
      v8 = -2;
    else
      v8 = *(_DWORD *)(this + 8 * j + 4);
    v9 = v8 | 0x80;
    if ( byte_925105[22616 * v8] )
      v9 = v8 | 0xC0;
    *((_BYTE *)v4 + v2++ + 8) = v9;
  }
  v10 = 0;
  if ( v3 >= 4 )
  {
    do
    {
      v11 = *((_BYTE *)v4 + v10 + 8);
      if ( v11 != *(_BYTE *)(this + v10 + 1680) )
      {
        *(_BYTE *)(this + v10 + 1680) = v11;
        *(float *)(this + 1676) = dbl_FB1D18;
      }
      v12 = *((_BYTE *)v4 + v10 + 9);
      if ( v12 != *(_BYTE *)(this + v10 + 1681) )
      {
        *(_BYTE *)(this + v10 + 1681) = v12;
        *(float *)(this + 1676) = dbl_FB1D18;
      }
      v13 = *((_BYTE *)v4 + v10 + 10);
      if ( v13 != *(_BYTE *)(this + v10 + 1682) )
      {
        *(_BYTE *)(this + v10 + 1682) = v13;
        *(float *)(this + 1676) = dbl_FB1D18;
      }
      v14 = *((_BYTE *)v4 + v10 + 11);
      if ( v14 != *(_BYTE *)(this + v10 + 1683) )
      {
        *(_BYTE *)(this + v10 + 1683) = v14;
        *(float *)(this + 1676) = dbl_FB1D18;
      }
      v10 += 4;
    }
    while ( v10 < v3 - 3 );
  }
  for ( ; v10 < v3; ++v10 )
  {
    v15 = *((_BYTE *)v4 + v10 + 8);
    if ( v15 != *(_BYTE *)(this + v10 + 1680) )
    {
      *(_BYTE *)(this + v10 + 1680) = v15;
      *(float *)(this + 1676) = dbl_FB1D18;
    }
  }
  if ( *(_DWORD *)(this + 1784) != v3 )
  {
    *(_DWORD *)(this + 1784) = v3;
    *(float *)(this + 1676) = dbl_FB1D18;
  }
  if ( (unsigned __int8)sub_4735A0() )
    sub_4745E0();
  return v2;
}
