int __cdecl sub_58E1B0(int a1)
{
  int v1; // ebp
  int v2; // edi
  int v3; // ebx
  int v4; // edx
  int v6; // [esp+Ch] [ebp-8h]
  int v7; // [esp+10h] [ebp-4h]

  v1 = a1;
  v2 = 0;
  v6 = 0;
  v3 = 0;
  if ( sub_58E190(a1) )
  {
    v7 = dword_7E484C;
    if ( dword_7E484C > 0 )
    {
      do
      {
        v4 = (unsigned __int8)byte_7E49DC[92 * v2];
        a1 = dword_7E49E0[23 * v2];
        sub_58FC70(&a1, dword_7E49D4[23 * v2], v4, &dword_7E49E0[23 * v2]);
        sub_58E2B0(&a1, dword_7E49D4[23 * v2], dword_7E49D8[23 * v2], v3);
        v6 += sub_58E3A0(dword_7E49D8[23 * v2], &a1, v3);
        v3 += *(unsigned __int8 *)(dword_7E49D8[23 * v2] + 4) >> 2;
        if ( !v2 )
        {
          if ( (_WORD)a1 == LOWORD(dword_800100[2 * v1]) )
          {
            ++dword_800104[2 * v1];
          }
          else
          {
            dword_800100[2 * v1] = a1;
            dword_800104[2 * v1] = 1;
          }
        }
        ++v2;
      }
      while ( v2 < v7 );
    }
  }
  sub_58E130();
  return v3;
}
