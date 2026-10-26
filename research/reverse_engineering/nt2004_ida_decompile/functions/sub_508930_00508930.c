int __thiscall sub_508930(_DWORD *this)
{
  int v2; // ecx
  int result; // eax
  int v4; // eax
  int v5; // edx
  int v6; // eax
  Concurrency::details::TaskStack *v7; // edi
  int v8; // ebx
  int v9; // ecx
  int v10; // eax
  int v11; // edx
  int v12; // eax
  _DWORD *v13; // edi
  int v14; // ebx

  v2 = this[3];
  result = 0;
  this[1] = 0;
  this[2] = 0;
  if ( v2 )
  {
    v4 = *(_DWORD *)(v2 - 4);
    v5 = 3 * v4;
    v6 = v4 - 1;
    v7 = (Concurrency::details::TaskStack *)(v2 + 4 * v5);
    if ( v6 >= 0 )
    {
      v8 = v6 + 1;
      do
      {
        v7 = (Concurrency::details::TaskStack *)((char *)v7 - 12);
        Concurrency::details::TaskStack::~TaskStack(v7);
        --v8;
      }
      while ( v8 );
    }
    sub_5BE8AE();
    result = 0;
  }
  v9 = this[5];
  this[3] = 0;
  this[4] = 0;
  if ( v9 )
  {
    v10 = *(_DWORD *)(v9 - 4);
    v11 = 3 * v10;
    v12 = v10 - 1;
    v13 = (_DWORD *)(v9 + 8 * v11);
    if ( v12 >= 0 )
    {
      v14 = v12 + 1;
      do
      {
        v13 -= 6;
        sub_5075A0(v13);
        --v14;
      }
      while ( v14 );
    }
    sub_5BE8AE();
    result = 0;
  }
  this[5] = 0;
  this[6] = 0;
  return result;
}
