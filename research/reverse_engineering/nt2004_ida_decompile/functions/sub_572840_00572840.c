_DWORD *__thiscall sub_572840(_DWORD *this)
{
  _DWORD *v2; // ebp
  _DWORD *v3; // eax
  _DWORD *v4; // edi
  _DWORD *v5; // edi
  _DWORD *v6; // eax
  int v7; // ebp
  int v8; // edi
  int *v9; // eax
  int v10; // ecx
  _DWORD *v12; // [esp+10h] [ebp-18h]

  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  this[7] = 0;
  v2 = operator new(4u);
  if ( v2 )
  {
    v3 = operator new(0x544u);
    if ( v3 )
    {
      v4 = v3 + 1;
      *v3 = 16;
      `eh vector constructor iterator'(v3 + 1, 0x54u, 16, sub_576780, sub_576830);
      *v2 = v4;
    }
    else
    {
      *v2 = 0;
    }
    v5 = v2;
    v12 = v2;
  }
  else
  {
    v12 = 0;
    v5 = 0;
  }
  if ( v5 )
  {
    v6 = operator new(0xCu);
    if ( v6 )
    {
      *v6 = v5;
      v6[1] = 0;
      *((_BYTE *)v6 + 8) = 1;
    }
    else
    {
      v6 = 0;
    }
    if ( !*this )
    {
      *this = v6;
      this[2] = v6;
      this[1] = v6;
      v7 = 0;
      ++this[3];
      goto LABEL_16;
    }
    *(_DWORD *)(this[1] + 4) = v6;
    this[1] = v6;
    ++this[3];
  }
  v7 = 0;
  while ( 1 )
  {
LABEL_16:
    v8 = v7 + *v5;
    if ( v8 )
    {
      v9 = (int *)operator new(0xCu);
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
    v7 += 84;
    if ( v7 >= 1344 )
      break;
    v5 = v12;
  }
  return this;
}
