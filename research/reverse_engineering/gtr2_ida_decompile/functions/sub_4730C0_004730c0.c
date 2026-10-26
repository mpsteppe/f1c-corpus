char __thiscall sub_4730C0(int **this, const char *a2, int a3, int a4, int a5)
{
  int v5; // esi
  int v6; // edi
  const char *v7; // ecx
  int v8; // eax
  int v9; // eax
  unsigned int v10; // kr00_4
  int v11; // eax
  int **v13; // [esp+0h] [ebp-54h]
  char v14[80]; // [esp+4h] [ebp-50h] BYREF

  v10 = __readeflags();
  v11 = *(_DWORD *)__ROR4__(off_16C6F1C, 255);
  __writeeflags(v10);
  v5 = a3;
  v13 = this;
  if ( a3 <= v11 )
  {
    if ( (char *)a4 == &byte_1020304 )
    {
      if ( a3 == 1 )
      {
        a4 = -65536;
      }
      else if ( a3 == 2 )
      {
        a4 = -256;
      }
      else
      {
        a4 = -88832;
      }
    }
    v6 = 0;
    if ( (int)strlen(a2) >= 80 )
    {
      v7 = a2;
      do
      {
        sub_630FE0(v14, v7, 79);
        v14[79] = 0;
        v8 = 78;
        while ( v14[v8] != 32 )
        {
          if ( v14[v8 - 1] == 32 )
          {
            --v8;
            break;
          }
          v8 -= 2;
          if ( v8 <= 40 )
            break;
        }
        if ( v8 == 40 )
          v9 = 79;
        else
          v9 = v8 + 1;
        v14[v9] = 0;
        v6 += v9;
        sub_472E90(*v13, v14, a4, a5, v5);
        v7 = &a2[v6];
        v5 = a3;
      }
      while ( (int)strlen(&a2[v6]) >= 80 );
    }
    LOBYTE(v11) = sub_472E90(*v13, &a2[v6], a4, a5, v5);
  }
  return v11;
}
