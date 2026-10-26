void __thiscall sub_609A40(char **this)
{
  char *v2; // ecx
  char *v3; // eax
  int v4; // ebp
  int v5; // ebx
  int i; // edi
  char *v7; // edi
  int v8; // [esp+4h] [ebp-4h]

  v2 = this[207];
  if ( v2 )
  {
    if ( *((_DWORD *)v2 + 12) )
      sub_6093A0();
    v3 = this[207];
    if ( v3 != (char *)-52 )
    {
      v4 = 0;
      if ( *((int *)v3 + 1) > 0 )
      {
        v5 = 0;
        v8 = 0;
        do
        {
          for ( i = 0; i < *((_DWORD *)this[207] + 1); v5 += 292 )
          {
            sub_5970E0((int *)&this[207][v5 + 320]);
            ++i;
          }
          ++v4;
          v5 = v8 + 1168;
          v8 += 1168;
        }
        while ( v4 < *((_DWORD *)this[207] + 1) );
      }
    }
    v7 = this[207];
    if ( v7 )
    {
      sub_6092A0(this[207]);
      j__free(v7);
    }
    this[207] = 0;
  }
}
