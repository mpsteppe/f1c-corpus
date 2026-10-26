int __thiscall sub_451E80(int this)
{
  int v2; // eax
  int v4; // eax
  unsigned int v5; // eax
  int v6; // ebx
  int i; // edi
  int v8; // [esp+18h] [ebp-54h]
  _BYTE v9[80]; // [esp+1Ch] [ebp-50h] BYREF

  v2 = *(_DWORD *)(this + 128);
  *(_DWORD *)(this + 1016) = 0;
  if ( !v2 )
    return -1;
  (*(void (__stdcall **)(int))(*(_DWORD *)v2 + 100))(v2);
  if ( (*(int (__stdcall **)(_DWORD, int, _BYTE *))(**(_DWORD **)(this + 128) + 36))(*(_DWORD *)(this + 128), 80, v9) )
    return -1;
  v4 = *(_DWORD *)(this + 128);
  *(_DWORD *)(this + 1016) = 6271;
  if ( (*(int (__stdcall **)(int, int))(*(_DWORD *)v4 + 12))(v4, this + 712) )
    return -1;
  v5 = *(_DWORD *)(this + 732);
  if ( v5 > 3 )
    *(_DWORD *)(this + 1016) |= 0x400u;
  if ( v5 > 2 )
    *(_DWORD *)(this + 1016) |= 0x200u;
  if ( v5 > 1 )
    *(_DWORD *)(this + 1016) |= 0x100u;
  if ( v5 )
    *(_DWORD *)(this + 1016) |= 0x80u;
  if ( (*(_BYTE *)(this + 716) & 1) != 0 )
  {
    v6 = v8;
    for ( i = 0; i < 8; ++i )
    {
      switch ( i )
      {
        case 0:
          v6 = 0;
          break;
        case 1:
          v6 = 4;
          break;
        case 2:
          v6 = 8;
          break;
        case 3:
          v6 = 12;
          break;
        case 4:
          v6 = 16;
          break;
        case 5:
          v6 = 20;
          break;
        case 6:
          v6 = 24;
          break;
        case 7:
          v6 = 28;
          break;
        default:
          break;
      }
      sub_451D80(
        (_DWORD *)this,
        v6,
        (float *)(this + 4 * i + 824),
        (float *)(this + 4 * i + 856),
        (float *)(this + 4 * i + 888),
        (float *)(this + 4 * i + 64),
        (float *)(this + 4 * i + 96),
        (float *)(this + 4 * i + 792),
        *(float *)(this + 4 * i + 32),
        *(float *)(this + 4 * i));
    }
  }
  return 0;
}
