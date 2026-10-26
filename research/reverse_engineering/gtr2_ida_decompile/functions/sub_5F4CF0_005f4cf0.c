int __thiscall sub_5F4CF0(_DWORD *this, int *a2, int a3, int a4, int a5)
{
  int result; // eax
  char v7; // cl
  int v9; // ebx
  int v10; // ecx
  _DWORD *v11; // esi
  int v12; // eax
  int v13; // eax
  _DWORD v14[2]; // [esp+14h] [ebp-18h] BYREF
  _DWORD v15[4]; // [esp+1Ch] [ebp-10h] BYREF
  int v16; // [esp+30h] [ebp+4h]
  int v17; // [esp+3Ch] [ebp+10h]

  result = BinkWait(this[1]);
  if ( result )
  {
    v7 = a5;
    if ( (a5 & 0x40) != 0 )
      return result;
  }
  else
  {
    BinkDoFrame(this[1]);
    BinkNextFrame(this[1]);
    v7 = a5;
    this[2] = (unsigned int)(this[2] + 1) % *(_DWORD *)(this[1] + 8);
  }
  result = a2[6] - 5;
  switch ( a2[6] )
  {
    case 5:
      v9 = 9;
      break;
    case 6:
      v9 = 10;
      break;
    case 7:
      v9 = 1;
      break;
    case 8:
      v9 = 5;
      break;
    case 14:
      v9 = 3;
      break;
    default:
      v9 = a5;
      break;
  }
  if ( (v7 & 0x20) != 0 )
    v9 |= 0x80000000;
  if ( (v7 & 0x10) != 0 )
    v9 |= 0x60000000u;
  if ( v7 < 0 )
  {
    result = sub_5E6E70(a2, 4, 0, 2);
    if ( result )
    {
      BinkCopyToBuffer(this[1], result, a2[4], a2[2], a3, a4, v9);
      result = sub_5E6EA0(a2, 4, 0, 2);
      *a2 &= ~0x100u;
    }
  }
  else if ( (*(_BYTE *)a2 & 4) != 0 )
  {
    BinkGetRects(this[1], 0);
    v16 = 0;
    if ( *(int *)(this[1] + 180) > 0 )
    {
      v17 = 0;
      do
      {
        v10 = this[1];
        v11 = (_DWORD *)(v17 + v10 + 52);
        v15[0] = *v11;
        v15[1] = *(_DWORD *)(v17 + v10 + 56);
        v15[2] = *(_DWORD *)(v17 + v10 + 60) + *v11;
        v15[3] = *(_DWORD *)(v17 + v10 + 64) + *(_DWORD *)(v17 + v10 + 56);
        v12 = sub_5E7150(a2, 4);
        if ( !(*(int (__stdcall **)(int, _DWORD, _DWORD *, _DWORD *, _DWORD))(*(_DWORD *)v12 + 76))(v12, 0, v14, v15, 0) )
        {
          BinkCopyToBufferRect(this[1], v14[1], v14[0], a2[2], a3, a4, *v11, v11[1], v11[2], v11[3], v9);
          v13 = sub_5E7150(a2, 4);
          (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)v13 + 80))(v13, 0);
        }
        v17 += 16;
        ++v16;
      }
      while ( v16 < *(_DWORD *)(this[1] + 180) );
    }
    result = *a2 & 0xFFFFFEFF;
    *a2 = result;
  }
  return result;
}
