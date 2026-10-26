int __thiscall sub_5029E5(int *this, int a2, unsigned int a3)
{
  if ( a3 >= 0xE && *(_WORD *)a2 == 19778 && *(_DWORD *)(a2 + 2) <= a3 )
    return DDSTextureFormatValidationDecoding(this, a2 + 14, a3 - 14);
  else
    return -2147467259;
}
