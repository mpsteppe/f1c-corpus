int __thiscall sub_5F7D00(_DWORD *this, int a2, int a3)
{
  char *v4; // eax
  char *v5; // ebx
  int v6; // ebx
  _DWORD *v7; // eax
  _DWORD *v8; // ebp
  int result; // eax

  this[a2 + 2265] = a3;
  v4 = (char *)this[a2 + 2277];
  if ( v4 )
  {
    v5 = v4 - 4;
    `eh vector destructor iterator'(v4, 4u, *((_DWORD *)v4 - 1), j_nullsub_7);
    j__free(v5);
  }
  v6 = this[a2 + 2265];
  v7 = operator new(4 * v6 + 4);
  if ( v7 )
  {
    v8 = v7 + 1;
    *v7 = v6;
    result = sub_630A11(v7 + 1, 4, v6, sub_5FC740, j_nullsub_7);
    this[a2 + 2277] = v8;
  }
  else
  {
    result = 0;
    this[a2 + 2277] = 0;
  }
  return result;
}
