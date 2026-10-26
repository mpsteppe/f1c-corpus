char __thiscall LinkedListNodeSearchByIDOperation(_DWORD *this, int a2, _DWORD *a3, _DWORD *a4)
{
  char result; // al
  _DWORD **v6; // ecx
  _DWORD *v7; // ecx
  int v8; // ecx
  _DWORD **v9; // ecx

  result = 0;
  if ( a2 != -1 )
  {
    v6 = (_DWORD **)this[6];
    this[8] = v6;
    if ( v6 )
    {
      v7 = *v6;
      if ( v7 )
      {
        while ( v7[23] != a2 )
        {
          v8 = this[8];
          if ( v8 )
            this[8] = *(_DWORD *)(v8 + 4);
          v9 = (_DWORD **)this[8];
          if ( v9 )
          {
            v7 = *v9;
            if ( v7 )
              continue;
          }
          return result;
        }
        ShortComputation_6a90(v7, a3, a4);
        return 1;
      }
    }
  }
  return result;
}
