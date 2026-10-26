void __stdcall sub_4FADA0(int a1)
{
  signed int v1; // esi
  int v2; // edi
  signed int v3; // edx
  bool v4; // cc
  int v5; // eax
  int v6; // ecx
  int v7; // eax

  if ( (dword_75CBAC & 1) != 0 && a1 >= 0 )
  {
    v1 = NumOfElements;
    v2 = dword_6310F4[6326 * a1];
    v3 = 0;
    v4 = (int)NumOfElements <= 0;
    dword_6310F4[6326 * a1] = NumOfElements;
    if ( !v4 )
    {
      do
      {
        v5 = dword_75AAD0[v3];
        v6 = *(_DWORD *)(v5 + 20876);
        v7 = v5 + 20836;
        if ( v6 > v2 && *(_DWORD *)(v7 + 4) != a1 )
        {
          *(_DWORD *)(v7 + 40) = v6 - 1;
          v1 = NumOfElements;
        }
        ++v3;
      }
      while ( v3 < v1 );
    }
  }
}
