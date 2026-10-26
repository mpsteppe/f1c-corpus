int __thiscall sub_556040(int *this, int a2)
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

  if ( (*(_DWORD *)(a2 + 412) & 0xE0000) == 0 )
  {
    this[1340] = 0;
    v9 = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)this[1088] + 200))(this[1088], 28, 0);
    goto LABEL_25;
  }
  this[1340] = 1;
  v3 = *(__int16 *)(a2 + 392);
  v4 = v3 | ((*(__int16 *)(a2 + 394) | (*(__int16 *)(a2 + 396) << 8)) << 8);
  if ( v4 != this[1341] )
  {
    v5 = this[1088];
    v13 = v3 | ((*(__int16 *)(a2 + 394) | (*(__int16 *)(a2 + 396) << 8)) << 8);
    this[1341] = v4;
    *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v5 + 200))(v5, 34, v13);
  }
  if ( *((float *)this + 1343) != *(float *)(a2 + 404) )
  {
    this[1343] = *(_DWORD *)(a2 + 404);
    *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 200))(this[1088], 36, this[1343]);
  }
  if ( *((float *)this + 1344) != *(float *)(a2 + 408) )
  {
    this[1344] = *(_DWORD *)(a2 + 408);
    *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 200))(this[1088], 37, this[1344]);
  }
  if ( *((float *)this + 1342) != *(float *)(a2 + 400) )
  {
    this[1342] = *(_DWORD *)(a2 + 400);
    *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 200))(this[1088], 38, this[1342]);
  }
  v6 = *(_DWORD *)(a2 + 412);
  if ( this[1345] == v6 )
    return 0;
  this[1345] = v6;
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
  v8 = this[1258];
  if ( (v8 & 0x4000) != 0 )
  {
    v9 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 200))(this[1088], 35, v7);
LABEL_25:
    *this = v9;
    return 0;
  }
  v10 = (v8 & 0x8000) != 0;
  v11 = this[1088];
  if ( v10 )
  {
    *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v11 + 200))(v11, 140, v7);
  }
  else
  {
    this[1340] = 0;
    *this = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v11 + 200))(v11, 28, 0);
  }
  return 0;
}
