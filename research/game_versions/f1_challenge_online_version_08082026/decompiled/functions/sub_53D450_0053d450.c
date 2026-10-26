int __stdcall sub_53D450(int a1)
{
  int result; // eax
  int v2; // edi
  float *v3; // ebx

  result = dword_8B89A0;
  if ( dword_8B89A0 )
  {
    dword_8B8C50[13] = a1;
    result = dword_8B8C50[0];
    v2 = 0;
    if ( dword_8B8C50[0] > 0 )
    {
      v3 = (float *)&unk_8B8A58;
      do
      {
        if ( *v3 != *(float *)&dword_8B8C50[13] )
        {
          *v3 = *(float *)&dword_8B8C50[13];
          unk_8B78A0 = (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)dword_8B89A0 + 252))(
                         dword_8B89A0,
                         v2,
                         19,
                         dword_8B8C50[13]);
        }
        result = dword_8B8C50[0];
        ++v2;
        v3 += 17;
      }
      while ( v2 < dword_8B8C50[0] );
    }
  }
  return result;
}
