int __thiscall sub_6A6CEE(_DWORD *this)
{
  unsigned int v2; // ecx
  unsigned int v3; // edi
  unsigned int v5; // eax
  int v6; // ecx
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  int v10; // [esp+8h] [ebp-4h]

  v2 = this[3];
  v3 = 0;
  v10 = 0;
  if ( v2 <= 0x40 )
  {
    v5 = 0;
    if ( v2 )
    {
      do
      {
        v6 = *(_DWORD *)(this[6] + 4 * v5++);
        *(_DWORD *)(v6 + 40) = 0;
      }
      while ( v5 < this[3] );
    }
    v7 = 0;
    if ( this[3] )
    {
      while ( 1 )
      {
        v8 = *(_DWORD *)(this[6] + 4 * v7);
        this[64] = v8;
        if ( *(_DWORD *)(v8 + 36) && *(_DWORD *)(v8 + 4) )
        {
          do
          {
            v9 = this[64];
            if ( *(_BYTE *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(v9 + 8) + 4 * v3)) + 108) == 1 )
            {
              sub_686791(
                (int)this,
                *(_DWORD *)(v9 + 60),
                4500,
                "cannot perform texture load that is in anyway dependent on COLOR registers");
              v10 = 1;
            }
            ++v3;
          }
          while ( v3 < *(_DWORD *)(this[64] + 4) );
        }
        v3 = 0;
        if ( !sub_6A6C77(this, (_DWORD *)this[64], 0) )
          break;
        if ( (unsigned int)++v7 >= this[3] )
          return v10;
      }
      return 1;
    }
    return v10;
  }
  else
  {
    sub_686791((int)this, 0, 4500, "program is order of magnitude too large to compile to ps_1_4");
    return 1;
  }
}
