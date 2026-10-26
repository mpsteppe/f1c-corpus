int __stdcall sub_592F40(int a1)
{
  int result; // eax
  int v2; // edi
  float *v3; // ebx

  result = dword_7E7CA8;
  if ( dword_7E7CA8 )
  {
    dword_7E7F58[14] = a1;
    result = dword_7E7F58[0];
    v2 = 0;
    if ( dword_7E7F58[0] > 0 )
    {
      v3 = (float *)&unk_7E7D60;
      do
      {
        if ( *v3 != *(float *)&dword_7E7F58[14] )
        {
          *v3 = *(float *)&dword_7E7F58[14];
          unk_7E6B48 = (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)dword_7E7CA8 + 252))(
                         dword_7E7CA8,
                         v2,
                         19,
                         dword_7E7F58[14]);
        }
        result = dword_7E7F58[0];
        ++v2;
        v3 += 17;
      }
      while ( v2 < dword_7E7F58[0] );
    }
  }
  return result;
}
