size_t sub_4FAEF0()
{
  size_t result; // eax
  signed int i; // esi
  int v2; // eax

  result = NumOfElements;
  for ( i = 0; i < (int)NumOfElements; ++i )
  {
    v2 = dword_75AAD0[i];
    if ( *(_DWORD *)(v2 + 16584) <= 1u )
      sub_4DD970((float **)(v2 + 20836), COERCE_FLOAT(1));
    result = NumOfElements;
  }
  return result;
}
