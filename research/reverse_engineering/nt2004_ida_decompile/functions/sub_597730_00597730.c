int __thiscall sub_597730(_DWORD *this, _DWORD *a2, int a3)
{
  _DWORD *v4; // edi
  int *v5; // eax
  int v6; // ecx
  _DWORD *v7; // edx
  int i; // eax
  int v9; // eax
  char *v10; // edi
  int v11; // ebx
  int v12; // edi
  _DWORD *v13; // eax
  _DWORD *v14; // ebp
  int result; // eax
  _DWORD *v16; // ebx

  switch ( a3 )
  {
    case 1:
      v4 = this + 72;
      v5 = this + 73;
      break;
    case 2:
      v4 = this + 76;
      v5 = this + 77;
      break;
    case 4:
      v4 = this + 74;
      v5 = this + 75;
      break;
    case 8:
      v4 = this + 78;
      v5 = this + 79;
      break;
    default:
      v4 = a2;
      v5 = a2;
      break;
  }
  v6 = *v5;
  if ( *v5 )
  {
    for ( i = *(_DWORD *)(v6 + 204); i; i = *(_DWORD *)(i + 204) )
      v6 = i;
    v7 = a2;
    *(_DWORD *)(v6 + 204) = a2;
    a2[50] = v6;
  }
  else
  {
    v7 = a2;
    *v5 = (int)a2;
    a2[50] = 0;
  }
  ++*v4;
  v7[51] = 0;
  v9 = this[81];
  this[25] = this[74] + this[76] + this[78];
  if ( v9 )
  {
    v10 = (char *)(v9 + 56 * *(_DWORD *)(v9 - 4));
    if ( *(_DWORD *)(v9 - 4) - 1 >= 0 )
    {
      v11 = *(_DWORD *)(v9 - 4);
      do
      {
        v10 -= 56;
        nullsub_6(v10);
        --v11;
      }
      while ( v11 );
    }
    sub_5BE8AE();
    this[81] = 0;
    this[80] = 0;
  }
  v12 = this[25];
  v13 = operator new(56 * v12 + 4);
  if ( v13 )
  {
    v14 = v13 + 1;
    *v13 = v12;
    result = v12 - 1;
    v16 = v14;
    if ( v12 - 1 >= 0 )
    {
      do
      {
        result = sub_5B58A0(v16);
        v16 += 14;
        --v12;
      }
      while ( v12 );
    }
    this[81] = v14;
  }
  else
  {
    result = 0;
    this[81] = 0;
  }
  return result;
}
