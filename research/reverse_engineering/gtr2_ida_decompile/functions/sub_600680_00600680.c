char *__thiscall sub_600680(_DWORD *this, unsigned int a2, int a3)
{
  char *result; // eax

  if ( a2 <= 5 )
  {
    result = (char *)&this[4 * a2];
    *((_DWORD *)result + 26) = *(_DWORD *)a3;
    *((_DWORD *)result + 27) = *(_DWORD *)(a3 + 4);
    this[4 * a2 + 28] = *(_DWORD *)(a3 + 8);
    *((float *)result + 29) = -*(float *)(a3 + 12);
  }
  return result;
}
