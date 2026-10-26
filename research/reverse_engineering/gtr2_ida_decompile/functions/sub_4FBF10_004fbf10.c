int __thiscall sub_4FBF10(_DWORD *this, int a2)
{
  int result; // eax
  int v3; // edi
  int *v4; // esi
  int v5; // ebx

  result = this[169] - 1;
  v3 = 255;
  if ( result >= 0 )
  {
    v4 = &this[2 * result + 171];
    v5 = this[169];
    do
    {
      result = abs32(a2 - *(v4 - 1));
      if ( result < v3 )
      {
        v3 = result;
        result = *v4;
        this[43] = *v4;
      }
      v4 -= 2;
      --v5;
    }
    while ( v5 );
  }
  return result;
}
