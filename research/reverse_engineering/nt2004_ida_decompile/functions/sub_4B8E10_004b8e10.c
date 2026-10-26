int __thiscall sub_4B8E10(_DWORD *this, _DWORD *a2, char a3)
{
  _DWORD *v3; // esi
  _DWORD *v5; // eax
  int result; // eax
  int v7; // ebp
  int v8; // esi
  _DWORD *v9; // eax
  int v10; // ecx
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
  result = a3 != 0 ? 0 : 2;
  if ( (a3 != 0 ? 0 : 2) != 0 )
  {
    v7 = 0;
    v11 = a3 != 0 ? 0 : 2;
    while ( 1 )
    {
      v8 = v7 + *v3;
      if ( v8 )
      {
        v9 = operator new(0xCu);
        if ( v9 )
        {
          *v9 = v8;
          v9[1] = 0;
          *((_BYTE *)v9 + 8) = 0;
        }
        else
        {
          v9 = 0;
        }
        v10 = this[4];
        if ( v10 )
        {
          v9[1] = v10;
        }
        else
        {
          this[5] = v9;
          this[6] = v9;
        }
        this[4] = v9;
        ++this[7];
      }
      v7 += 16;
      result = --v11;
      if ( !v11 )
        break;
      v3 = a2;
    }
  }
  return result;
}
