int __thiscall sub_4F87B0(int this)
{
  int v1; // edi
  _DWORD *v3; // ebx
  int v4; // ebp
  int v5; // eax
  int i; // edx
  int v7; // eax
  int v8; // edx
  char v9; // cl
  _BYTE *v10; // eax
  _BYTE *v11; // ecx
  int result; // eax
  int v13; // [esp+0h] [ebp-1Ch]

  v1 = 0;
  v3 = (_DWORD *)dword_7D3C44;
  if ( dword_79FC40 < 1023 )
  {
    ++dword_79FC40;
    dword_7D3C44 += 208;
  }
  v4 = *(_DWORD *)(this + 388) + *(_DWORD *)(this + 776);
  *(float *)&v13 = dbl_7DA9D0;
  sub_4D0D00(v3, 4, 37, v4, 63, v13, 0);
  if ( *(int *)(this + 776) > 0 )
  {
    do
    {
      if ( v1 >= 48 )
        break;
      v5 = sub_4F7CF0((_DWORD *)(this + 392), v1);
      if ( byte_6311E9[25304 * v5] )
        LOBYTE(v5) = v5 | 0x40;
      *((_BYTE *)v3 + v1++ + 8) = v5;
    }
    while ( v1 < *(_DWORD *)(this + 776) );
  }
  for ( i = 0; i < *(_DWORD *)(this + 388); i = v8 + 1 )
  {
    if ( v1 >= 48 )
      break;
    v7 = sub_4F7CF0((_DWORD *)(this + 4), i);
    v9 = v7 | 0x80;
    if ( byte_6311E9[25304 * v7] )
      v9 = v7 | 0xC0;
    *((_BYTE *)v3 + v1++ + 8) = v9;
  }
  if ( v4 > 0 )
  {
    v10 = (_BYTE *)(this + 784);
    v11 = v3 + 2;
    do
    {
      if ( *v11 != *v10 )
      {
        *v10 = *v11;
        *(float *)(this + 780) = dbl_7DA9D0;
      }
      ++v11;
      ++v10;
    }
    while ( (int)&v11[-8 - (_DWORD)v3] < v4 );
  }
  result = v1;
  if ( *(_DWORD *)(this + 832) != v4 )
  {
    *(_DWORD *)(this + 832) = v4;
    *(float *)(this + 780) = dbl_7DA9D0;
  }
  return result;
}
