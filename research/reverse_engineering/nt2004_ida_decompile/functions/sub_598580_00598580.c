int __thiscall sub_598580(_DWORD *this)
{
  int v2; // ebx
  int v3; // edi
  int v4; // ecx
  int v5; // ecx
  int v6; // eax
  char *v7; // edi
  int v8; // eax
  int v9; // ebx

  if ( this[44] )
  {
    v2 = 0;
    if ( (int)this[43] > 0 )
    {
      v3 = 0;
      do
      {
        if ( *(_DWORD *)(v3 + this[44] + 76) )
          sub_5BE8AE();
        v4 = this[44];
        if ( *(_DWORD *)(v3 + v4 + 144) )
          sub_5A9130(*(_DWORD *)(v3 + v4 + 144));
        ++v2;
        v3 += 148;
      }
      while ( v2 < this[43] );
    }
    v5 = this[44];
    if ( v5 )
    {
      v6 = *(_DWORD *)(v5 - 4);
      v7 = (char *)(v5 + 148 * v6);
      v8 = v6 - 1;
      if ( v8 >= 0 )
      {
        v9 = v8 + 1;
        do
        {
          v7 -= 148;
          j_nullsub_6(v7);
          --v9;
        }
        while ( v9 );
      }
      sub_5BE8AE();
    }
    this[44] = 0;
  }
  return 0;
}
