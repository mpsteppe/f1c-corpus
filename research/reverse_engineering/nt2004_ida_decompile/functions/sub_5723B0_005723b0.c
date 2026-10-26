void __thiscall sub_5723B0(_DWORD *this)
{
  _DWORD *v2; // ebp
  _DWORD *v3; // esi
  _DWORD *v4; // eax
  int v5; // ebp
  _DWORD *v6; // eax
  int v7; // esi
  int *v8; // eax
  int v9; // ecx
  _DWORD *v10; // [esp+Ch] [ebp-14h]

  v2 = operator new(4u);
  v3 = 0;
  if ( v2 )
  {
    v4 = operator new(0xA4u);
    if ( v4 )
    {
      v3 = v4 + 1;
      *v4 = 4;
      `eh vector constructor iterator'(
        v4 + 1,
        0x28u,
        4,
        (void (__thiscall *)(void *))((char *)&loc_56ABED + 3),
        (void (__thiscall *)(void *))sub_56AC20);
    }
    *v2 = v3;
    v3 = v2;
    v10 = v2;
  }
  else
  {
    v10 = 0;
  }
  v5 = 0;
  if ( v3 )
  {
    v6 = operator new(0xCu);
    if ( v6 )
    {
      *v6 = v3;
      v6[1] = 0;
      *((_BYTE *)v6 + 8) = 1;
    }
    else
    {
      v6 = 0;
    }
    if ( *this )
    {
      *(_DWORD *)(this[1] + 4) = v6;
    }
    else
    {
      *this = v6;
      this[2] = v6;
    }
    this[1] = v6;
    ++this[3];
  }
  while ( 1 )
  {
    v7 = v5 + *v3;
    if ( v7 )
    {
      v8 = (int *)operator new(0xCu);
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
    v5 += 40;
    if ( v5 >= 160 )
      break;
    v3 = v10;
  }
}
