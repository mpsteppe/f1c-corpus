_DWORD *__thiscall sub_618140(_DWORD *this, size_t Size, int a3, int a4, int a5)
{
  void *v6; // edi
  _WORD *v7; // eax
  _WORD *v8; // ecx
  int v9; // edx
  int v10; // eax
  int v11; // eax

  v6 = operator new(Size);
  *this = v6;
  this[1] = Size;
  memset(v6, 0, Size);
  v7 = operator new(4 * a4);
  if ( v7 )
  {
    v8 = v7;
    if ( a4 - 1 >= 0 )
    {
      v9 = a4;
      do
      {
        v8[1] = 0;
        *v8 = 0;
        v8 += 2;
        --v9;
      }
      while ( v9 );
    }
  }
  else
  {
    v7 = 0;
  }
  this[2] = v7;
  v10 = a3;
  this[3] = a4;
  this[4] = 0;
  this[5] = 0;
  if ( !a3 )
    v10 = 1;
  this[6] = v10;
  v11 = a5;
  if ( !a5 )
    v11 = 1;
  this[7] = v11;
  return this;
}
