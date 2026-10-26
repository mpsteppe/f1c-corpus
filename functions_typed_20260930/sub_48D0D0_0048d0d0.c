int __thiscall sub_48D0D0(_DWORD **this)
{
  int v2; // ebx
  int v3; // ebx
  int v4; // edi
  _DWORD *v5; // ebx
  int v6; // ecx
  int v7; // edi
  BOOL v8; // ebp
  int v9; // eax
  int v10; // ecx
  int v11; // edi
  int v13; // [esp+10h] [ebp-8h] BYREF
  int v14; // [esp+14h] [ebp-4h] BYREF

  v2 = ((int (__thiscall *)(_DWORD **))(*this)[8])(this);
  v3 = v2 - ((int (__thiscall *)(_DWORD **))(*this)[6])(this);
  if ( v3 > 0 )
  {
    v4 = v3 / 2 + ((int (__thiscall *)(_DWORD **))(*this)[6])(this);
    DualFieldRead(this[16], &v13, &v14);
    v5 = this[202];
    v6 = v13 - v4;
    v7 = (int)this[203];
    v8 = v6 > 0;
    v9 = (int)this[205] + v6;
    v10 = v7 * (_DWORD)v5;
    if ( v7 * (int)v5 > 0 )
    {
      for ( ; v9 < 0; v9 += v10 )
        ;
      for ( ; v9 > v10; v9 -= v10 )
        ;
      v11 = v9 / v7;
      if ( v11 >= 0 )
      {
        if ( v11 > (int)v5 - 1 )
          v11 = (int)v5 - 1;
      }
      else
      {
        v11 = 0;
      }
      while ( (_DWORD *)v11 != this[206] )
        ((void (__thiscall *)(_DWORD **, BOOL))(*this)[46])(this, v8);
    }
  }
  return 0;
}

