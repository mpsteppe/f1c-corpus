int __fastcall sub_565080(int a1, unsigned int a2, _DWORD *a3)
{
  int j; // eax
  char v6; // di
  int v7; // ecx
  int v8; // ebx
  int v9; // edx
  int k; // eax
  int v12; // [esp+10h] [ebp-8h]
  int i; // [esp+1Ch] [ebp+4h]

  a3[325] = 0;
  memset(a3, 0, 0x400u);
  for ( i = 0; i < 4; ++i )
  {
    for ( j = 0; j < 256; ++j )
      a3[j] = j + (a3[j] << 8);
    v6 = i;
    v12 = 2;
    do
    {
      v7 = 0;
      do
      {
        v8 = a3[v7];
        v9 = (unsigned __int8)(v6 + v8 + *(_BYTE *)(v7++ % a2 + a1));
        v6 = v9;
        a3[v7 - 1] = a3[v9];
        a3[v9] = v8;
      }
      while ( v7 < 256 );
      --v12;
    }
    while ( v12 );
  }
  for ( k = 0; k < 256; ++k )
    a3[k] ^= k;
  return sub_564DD0(a3, 0, 0);
}

