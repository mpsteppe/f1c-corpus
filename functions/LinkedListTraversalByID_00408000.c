void __thiscall LinkedListTraversalByID(_DWORD *this, int a2)
{
  _DWORD **v2; // eax
  _DWORD *v3; // eax
  int v4; // eax
  _DWORD **v5; // eax

  if ( a2 != -1 )
  {
    v2 = (_DWORD **)this[6];
    this[8] = v2;
    if ( v2 )
    {
      v3 = *v2;
      if ( v3 )
      {
        while ( v3[23] != a2 )
        {
          v4 = this[8];
          if ( v4 )
            this[8] = *(_DWORD *)(v4 + 4);
          v5 = (_DWORD **)this[8];
          if ( v5 )
          {
            v3 = *v5;
            if ( v3 )
              continue;
          }
          return;
        }
        sub_406A70(v3);
      }
    }
  }
}
