size_t sub_4E3090()
{
  size_t result; // eax
  signed int i; // esi
  bool v2; // bl
  int v3; // eax
  int v4; // edi

  result = NumOfElements;
  for ( i = 0; i < (int)NumOfElements; ++i )
  {
    if ( i == dword_75AAC8 )
    {
      v2 = *(_DWORD *)dword_7689CC == 8;
      v3 = sub_4E31D0(*(_DWORD *)(dword_75AAD0[i] + 25252));
      if ( !v2 )
      {
        if ( v3 || !dword_768228 )
          *(_DWORD *)(dword_75AAD0[i] + 2040) = v3;
        else
          *(_DWORD *)(dword_75AAD0[i] + 2040) = dword_768228;
      }
    }
    else
    {
      v4 = dword_75AAD0[i];
      *(_DWORD *)(v4 + 2040) = sub_4E31D0(*(_DWORD *)(v4 + 25252));
    }
    result = NumOfElements;
  }
  return result;
}
