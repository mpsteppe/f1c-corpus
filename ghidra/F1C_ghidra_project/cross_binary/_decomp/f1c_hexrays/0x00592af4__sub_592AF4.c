// f1c  0x00592af4  size=185
void sub_592AF4()
{
  char *v0; // esi
  int v1; // edi
  int *v2; // esi
  _DWORD *v3; // edi
  char *v4; // eax
  char *v5; // ebp
  int v6; // eax

  if ( !dword_8D5A4C )
    sub_597218();
  v0 = (char *)dword_8D3EB4;
  v1 = 0;
  while ( *v0 )
  {
    if ( *v0 != 61 )
      ++v1;
    v0 = &sub_58E1B0(v0)[(_DWORD)v0 + 1];
  }
  v2 = (int *)sub_58A935(4 * v1 + 4);
  dword_8D3E90 = v2;
  if ( !v2 )
    sub_58A2A6(9u);
  v3 = dword_8D3EB4;
  if ( *(_BYTE *)dword_8D3EB4 )
  {
    do
    {
      v4 = sub_58E1B0(v3);
      v5 = v4 + 1;
      if ( *(_BYTE *)v3 != 61 )
      {
        v6 = sub_58A935((int)(v4 + 1));
        *v2 = v6;
        if ( !v6 )
          sub_58A2A6(9u);
        sub_58FCA0();
        ++v2;
      }
      v3 = (_DWORD *)((char *)v3 + (_DWORD)v5);
    }
    while ( *(_BYTE *)v3 );
  }
  sub_58AA6F(dword_8D3EB4);
  dword_8D3EB4 = 0;
  *v2 = 0;
  dword_8D5A48 = 1;
}
