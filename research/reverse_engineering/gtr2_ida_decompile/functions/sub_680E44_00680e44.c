int __thiscall sub_680E44(_DWORD *this)
{
  unsigned int v1; // eax

  v1 = *this & 0xFFF00000;
  if ( v1 > 0x70700000 )
  {
    if ( v1 == 1890582528 || v1 == 1891631104 || v1 == 1892679680 )
      return 1;
    return v1 == 1895825408;
  }
  else
  {
    if ( v1 == 1886388224 || v1 == 1345323008 || v1 == 1880096768 || v1 == 1881145344 || v1 == 1884291072 )
      return 1;
    return v1 == 1885339648;
  }
}
