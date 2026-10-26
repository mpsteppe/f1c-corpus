int __thiscall sub_5AC380(int *this, int a2)
{
  int v3; // edx
  int v4; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  bool v10; // sf
  int v11; // eax
  int v13; // [esp+20h] [ebp-Ch]

  if ( (*(_DWORD *)(a2 + 428) & 0xE0000) == 0 )
  {
    this[2135] = 0;
    v9 = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)this[1112] + 200))(this[1112], 28, 0);
    goto LABEL_25;
  }
  this[2135] = 1;
  v3 = *(__int16 *)(a2 + 408);
  v4 = v3 | ((*(__int16 *)(a2 + 410) | (*(__int16 *)(a2 + 412) << 8)) << 8);
  if ( v4 != this[2136] )
  {
    v5 = this[1112];
    v13 = v3 | ((*(__int16 *)(a2 + 410) | (*(__int16 *)(a2 + 412) << 8)) << 8);
    this[2136] = v4;
    *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v5 + 200))(v5, 34, v13);
  }
  if ( *((float *)this + 2138) != *(float *)(a2 + 420) )
  {
    this[2138] = *(_DWORD *)(a2 + 420);
    *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1112] + 200))(this[1112], 36, this[2138]);
  }
  if ( *((float *)this + 2139) != *(float *)(a2 + 424) )
  {
    this[2139] = *(_DWORD *)(a2 + 424);
    *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1112] + 200))(this[1112], 37, this[2139]);
  }
  if ( *((float *)this + 2137) != *(float *)(a2 + 416) )
  {
    this[2137] = *(_DWORD *)(a2 + 416);
    *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1112] + 200))(this[1112], 38, this[2137]);
  }
  v6 = *(_DWORD *)(a2 + 428);
  if ( this[2140] == v6 )
    return 0;
  this[2140] = v6;
  switch ( v6 )
  {
    case 0x20000:
      v7 = 3;
      break;
    case 0x40000:
      v7 = 1;
      break;
    case 0x80000:
      v7 = 2;
      break;
    default:
      v7 = a2;
      break;
  }
  v8 = this[1282];
  if ( (v8 & 0x4000) != 0 )
  {
    v9 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1112] + 200))(this[1112], 35, v7);
LABEL_25:
    *this = v9;
    return 0;
  }
  v10 = (v8 & 0x8000) != 0;
  v11 = this[1112];
  if ( v10 )
  {
    *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v11 + 200))(v11, 140, v7);
  }
  else
  {
    this[2135] = 0;
    *this = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v11 + 200))(v11, 28, 0);
  }
  return 0;
}
