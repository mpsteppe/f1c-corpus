int __thiscall sub_5A8C40(_DWORD *this, int a2, int a3, int a4, char a5)
{
  int v6; // edi
  char v7; // cl
  unsigned int v8; // esi
  int v9; // esi
  int v10; // esi
  int v11; // eax
  int v13; // [esp+14h] [ebp-1Ch]
  int v14; // [esp+14h] [ebp-1Ch]
  _DWORD v15[2]; // [esp+18h] [ebp-18h] BYREF
  _DWORD v16[4]; // [esp+20h] [ebp-10h] BYREF
  int i; // [esp+40h] [ebp+10h]

  v6 = 0;
  v13 = 0;
  if ( !BinkWait(*this) )
  {
    BinkDoFrame(*this);
    BinkNextFrame(*this);
    v7 = a5;
    this[1] = (unsigned int)(this[1] + 1) % *(_DWORD *)(*this + 8);
    goto LABEL_4;
  }
  v7 = a5;
  if ( (a5 & 0x40) == 0 )
  {
LABEL_4:
    switch ( *(_DWORD *)(a2 + 48) )
    {
      case 5:
        v13 = 9;
        break;
      case 6:
        v13 = 10;
        break;
      case 7:
        v13 = 1;
        break;
      case 8:
        v13 = 3;
        break;
      default:
        break;
    }
    v8 = v13;
    if ( (v7 & 0x20) != 0 )
      v8 = v13 | 0x80000000;
    if ( (v7 & 0x10) != 0 )
      v8 |= 0x60000000u;
    v9 = v8 | 0x80000;
    v14 = v9;
    if ( v7 < 0 )
    {
      v11 = sub_59FD80((void *)a2, 4, 0);
      if ( v11 )
      {
        BinkCopyToBuffer(*this, v11, *(_DWORD *)(a2 + 40), *(_DWORD *)(a2 + 32), a3, a4, v9);
        sub_59FDA0((void *)a2, 4, 0);
LABEL_22:
        *(_DWORD *)(a2 + 56) &= ~0x400u;
      }
    }
    else if ( (*(_BYTE *)(a2 + 56) & 4) != 0 )
    {
      BinkGetRects(*this, 0);
      v10 = *this;
      for ( i = 0; i < *(_DWORD *)(*this + 180); ++i )
      {
        v16[0] = *(_DWORD *)(v6 + v10 + 52);
        v16[1] = *(_DWORD *)(v6 + v10 + 56);
        v16[2] = *(_DWORD *)(v6 + v10 + 52) + *(_DWORD *)(v6 + v10 + 60);
        v16[3] = *(_DWORD *)(v6 + v10 + 64) + *(_DWORD *)(v6 + v10 + 56);
        if ( !(*(int (__stdcall **)(_DWORD, _DWORD, _DWORD *, _DWORD *, _DWORD))(**(_DWORD **)(a2 + 20) + 64))(
                *(_DWORD *)(a2 + 20),
                0,
                v15,
                v16,
                0) )
        {
          BinkCopyToBufferRect(
            *this,
            v15[1],
            v15[0],
            *(_DWORD *)(a2 + 32),
            a3,
            a4,
            *(_DWORD *)(v6 + v10 + 52),
            *(_DWORD *)(v6 + v10 + 56),
            *(_DWORD *)(v6 + v10 + 60),
            *(_DWORD *)(v6 + v10 + 64),
            v14);
          (*(void (__stdcall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 20) + 68))(*(_DWORD *)(a2 + 20), 0);
        }
        v10 = *this;
        v6 += 16;
      }
      goto LABEL_22;
    }
    return 1;
  }
  return 0;
}
