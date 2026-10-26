int __thiscall sub_4A4DB0(int this)
{
  int result; // eax
  _DWORD *v3; // ecx
  _DWORD *v4; // ecx
  _BYTE *v5; // ecx
  void *v6; // edi

  *(_BYTE *)(this + 53) = 1;
  *(_BYTE *)(this + 117) = 1;
  *(_BYTE *)(this + 181) = 1;
  *(_BYTE *)(this + 245) = 1;
  *(_BYTE *)(this + 309) = 1;
  *(_DWORD *)(this + 344) = 0;
  *(_DWORD *)(this + 388) = 0;
  *(_DWORD *)(this + 392) = 0;
  *(_DWORD *)(this + 396) = 0;
  *(_BYTE *)(this + 400) = 0;
  *(_DWORD *)(this + 348) = -1;
  *(_DWORD *)(this + 352) = -1;
  *(_DWORD *)(this + 404) = 0;
  *(_DWORD *)(this + 408) = 0;
  *(_DWORD *)(this + 412) = 0;
  result = 0;
  *(_DWORD *)(this + 416) = 0;
  *(_DWORD *)(this + 420) = 0;
  *(_DWORD *)(this + 424) = 0;
  *(_DWORD *)(this + 432) = 0;
  *(_DWORD *)(this + 440) = 0;
  *(_DWORD *)(this + 444) = 0;
  *(_DWORD *)(this + 448) = 0;
  *(_DWORD *)(this + 452) = 0;
  *(_DWORD *)(this + 456) = 0;
  *(_DWORD *)(this + 460) = 0;
  v3 = *(_DWORD **)(this + 12);
  *(_BYTE *)(this + 428) = 0;
  *(_DWORD *)(this + 8) = 0;
  if ( v3 )
  {
    ArrayResourceCleanup(v3);
    result = *(_DWORD *)(this + 12);
    if ( result )
      result = FreeWrapper_7bcf(*(LPVOID *)(this + 12));
    *(_DWORD *)(this + 12) = 0;
  }
  v4 = *(_DWORD **)(this + 16);
  if ( v4 )
  {
    ArrayResourceCleanup(v4);
    result = *(_DWORD *)(this + 16);
    if ( result )
      result = FreeWrapper_7bcf(*(LPVOID *)(this + 16));
    *(_DWORD *)(this + 16) = 0;
  }
  v5 = *(_BYTE **)(this + 20);
  if ( v5 )
  {
    result = sub_4A3B30(v5);
    v6 = *(void **)(this + 20);
    if ( v6 )
    {
      sub_4A2220(*(_BYTE **)(this + 20));
      result = FreeWrapper_7bcf(v6);
    }
    *(_DWORD *)(this + 20) = 0;
  }
  return result;
}

