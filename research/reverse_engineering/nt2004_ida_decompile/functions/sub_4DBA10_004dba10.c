int __thiscall sub_4DBA10(_DWORD *this, _DWORD *a2, char a3)
{
  _DWORD *v3; // esi
  _DWORD *v5; // eax
  int v6; // ebp
  int v7; // esi
  _DWORD *v8; // eax
  int v9; // ecx
  int result; // eax
  int v11; // [esp+14h] [ebp+8h]

  v3 = a2;
  if ( a2 )
  {
    v5 = operator new(0xCu);
    if ( v5 )
    {
      *v5 = a2;
      v5[1] = 0;
      *((_BYTE *)v5 + 8) = 1;
    }
    else
    {
      v5 = 0;
    }
    if ( *this )
    {
      *(_DWORD *)(this[1] + 4) = v5;
    }
    else
    {
      *this = v5;
      this[2] = v5;
    }
    this[1] = v5;
    ++this[3];
  }
  v6 = 0;
  v11 = a3 != 0 ? 64 : 32;
  while ( 1 )
  {
    v7 = v6 + *v3;
    if ( v7 )
    {
      v8 = operator new(0xCu);
      if ( v8 )
      {
        *v8 = v7;
        v8[1] = 0;
        *((_BYTE *)v8 + 8) = 0;
      }
      else
      {
        v8 = 0;
      }
      v9 = this[4];
      if ( v9 )
      {
        v8[1] = v9;
      }
      else
      {
        this[5] = v8;
        this[6] = v8;
      }
      this[4] = v8;
      ++this[7];
    }
    v6 += 12;
    result = --v11;
    if ( !v11 )
      break;
    v3 = a2;
  }
  return result;
}
