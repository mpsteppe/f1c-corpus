int __thiscall sub_532E20(void *this)
{
  char *v1; // edx
  int i; // ebp
  int j; // ebx
  char *v4; // edi
  int v5; // eax
  int k; // ebp
  int m; // ebx
  char *v8; // edi
  int result; // eax

  nullsub_6(this);
  v1 = (char *)&unk_7DC48C;
  for ( i = 0; i < 32; i += 2 )
  {
    for ( j = 0; j <= 896; j += 64 )
    {
      v4 = v1;
      v5 = j - i;
      v1 += 32;
      qmemcpy(v4, (char *)&unk_5F0AE4 + v5, 0x20u);
    }
  }
  for ( k = 0; k < 32; k += 2 )
  {
    for ( m = 0; m <= 1024; m += 64 )
    {
      v8 = v1;
      result = m - k;
      v1 += 32;
      qmemcpy(v8, (char *)&unk_5F0EE4 + result, 0x20u);
    }
  }
  return result;
}
