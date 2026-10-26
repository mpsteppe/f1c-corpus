int __thiscall sub_4B6130(_DWORD *this)
{
  int result; // eax
  int v3; // ecx
  void *v4; // ebx
  _DWORD *v5; // esi
  int v6; // ecx
  int v7; // edi

  result = this[620];
  if ( result )
  {
    v3 = *(_DWORD *)(result - 4);
    v4 = (void *)(result - 4);
    v5 = (_DWORD *)(result + 176 * v3);
    v6 = v3 - 1;
    if ( v6 >= 0 )
    {
      v7 = v6 + 1;
      do
      {
        v5 -= 44;
        QuadrupleListCleanup(v5);
        --v7;
      }
      while ( v7 );
    }
    FreeWrapper_7bcf(v4);
    result = 0;
    this[620] = 0;
    this[621] = 0;
  }
  return result;
}

