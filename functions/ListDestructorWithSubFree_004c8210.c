int __thiscall ListDestructorWithSubFree(int *this)
{
  int v2; // esi
  LPVOID **v3; // ebp
  char v4; // al
  LPVOID *v5; // edi
  int result; // eax
  int i; // esi
  _DWORD *v8; // ebp
  char v9; // al
  LPVOID *v10; // edi

  v2 = *this;
  while ( v2 )
  {
    v3 = (LPVOID **)v2;
    v4 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 )
    {
      v5 = *v3;
      if ( *v3 )
      {
        if ( *v5 )
          FreeWrapper_7bcf(*v5);
        FreeWrapper_7bcf(v5);
      }
    }
    FreeWrapper_7bcf(v3);
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  result = ArithmeticComparison_8350();
  for ( i = *this; i; result = FreeWrapper_7bcf(v8) )
  {
    v8 = (_DWORD *)i;
    v9 = *(_BYTE *)(i + 8);
    i = *(_DWORD *)(i + 4);
    if ( v9 )
    {
      v10 = (LPVOID *)*v8;
      if ( *v8 )
      {
        if ( *v10 )
          FreeWrapper_7bcf(*v10);
        FreeWrapper_7bcf(v10);
      }
    }
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  return result;
}
