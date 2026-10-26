// positive sp value has been detected, the output may be wrong!
int __usercall sub_561B2A@<eax>(int a1@<eax>, int a2@<ecx>, int a3@<ebx>)
{
  int v3; // edi
  int i; // ecx
  int j; // ebx
  int v6; // edi
  int k; // ecx
  int m; // ebx
  int v9; // edi
  int n; // ecx
  int ii; // ebx
  char v12; // al
  int v13; // edi
  int jj; // ecx
  int kk; // ebx
  char v16; // al
  int v18; // [esp-4h] [ebp-4h]

  LOBYTE(a1) = BYTE1(a2) + a1;
  *(_DWORD *)(a3 - 22) -= a2;
  (*(void (**)(void))(a1 + 83))();
  v3 = 0;
  for ( i = 0; i < 256; ++i )
  {
    for ( j = 0; j < 32; ++j )
      byte_5DECCC[v3++] = (unsigned __int16)((unsigned __int8)i * (unsigned __int8)j) >> 8;
  }
  v6 = 0;
  for ( k = 0; k < 256; ++k )
  {
    for ( m = 0; m < 64; ++m )
      byte_5E0CCC[v6++] = (unsigned __int16)((unsigned __int8)k * (unsigned __int8)m) >> 8;
  }
  v9 = 0;
  for ( n = 0; n < 32; ++n )
  {
    for ( ii = 0; ii < 32; ++ii )
    {
      v12 = n + ii;
      if ( (char)(n + ii) >= 32 )
        v12 = 31;
      byte_5DD8CC[v9++] = v12;
    }
  }
  v13 = 0;
  for ( jj = 0; jj < 64; ++jj )
  {
    for ( kk = 0; kk < 64; ++kk )
    {
      v16 = jj + kk;
      if ( (char)(jj + kk) >= 64 )
        v16 = 63;
      byte_5DDCCC[v13++] = v16;
    }
  }
  return v18;
}

