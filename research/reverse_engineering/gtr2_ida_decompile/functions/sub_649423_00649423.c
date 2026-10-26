int __stdcall sub_649423(_BYTE *a1, int a2, _BYTE *a3)
{
  if ( (unsigned int)a2 <= 0x7FFFFFFF )
    return sub_649337(a1, a2, a3);
  else
    return -2147024809;
}
