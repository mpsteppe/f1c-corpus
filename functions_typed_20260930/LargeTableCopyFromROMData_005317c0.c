int sub_5317C0()
{
  char *v0; // edx
  int i; // ebp
  int j; // ebx
  char *v3; // edi
  int v4; // eax
  int k; // ebp
  int m; // ebx
  char *v7; // edi
  int result; // eax

  EmptyStub_0170();
  v0 = (char *)&unk_8B1924;
  for ( i = 0; i < 32; i += 2 )
  {
    for ( j = 0; j <= 896; j += 64 )
    {
      v3 = v0;
      v4 = j - i;
      v0 += 32;
      qmemcpy(v3, (char *)&unk_5B6F0C + v4, 0x20u);
    }
  }
  for ( k = 0; k < 32; k += 2 )
  {
    for ( m = 0; m <= 1024; m += 64 )
    {
      v7 = v0;
      result = m - k;
      v0 += 32;
      qmemcpy(v7, (char *)&unk_5B730C + result, 0x20u);
    }
  }
  return result;
}

