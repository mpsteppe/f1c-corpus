int __thiscall sub_555E50(int this, int a2, _DWORD *a3)
{
  unsigned int v3; // ebx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v11; // eax
  int v12; // edx
  int v13; // eax
  int v14; // edx
  int v15; // [esp+20h] [ebp-110h]
  char v16[256]; // [esp+30h] [ebp-100h] BYREF

  v3 = 0;
  v5 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(this + 4352) + 60))(
         *(_DWORD *)(this + 4352),
         0,
         0,
         0,
         0);
  *(_DWORD *)this = v5;
  if ( v5 != -2005530520 )
    return 0;
  v6 = (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(this + 4352) + 12))(*(_DWORD *)(this + 4352));
  *(_DWORD *)this = v6;
  if ( v6 != -2005530519 )
    return 0;
  v7 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(this + 4352) + 124))(*(_DWORD *)(this + 4352), 0, 0);
  v15 = *(_DWORD *)(this + 5420);
  *(_DWORD *)this = v7;
  sub_53F6E0((int *)this, v15);
  RenderTargetCleanup(this, (int)a3);
  v8 = (*(int (__stdcall **)(_DWORD, int))(**(_DWORD **)(this + 4352) + 56))(*(_DWORD *)(this + 4352), this + 4356);
  *(_DWORD *)this = v8;
  if ( v8 )
  {
    if ( v8 == -2005530520 )
    {
      v9 = (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(this + 4352) + 12))(*(_DWORD *)(this + 4352));
      *(_DWORD *)this = v9;
      if ( v9 == -2005530519 )
        StringFormatWithBufferOverflowCheck(v16, "%s - 0x%X", aCouldNotSetDis, -2005530519);
    }
    else
    {
      StringFormatWithBufferOverflowCheck(v16, "%s - 0x%X", aCouldNotSetDis, v8);
    }
    sub_53C590(-1, v16);
    return -1;
  }
  else
  {
    v11 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, int))(**(_DWORD **)(this + 4352) + 64))(
            *(_DWORD *)(this + 4352),
            0,
            0,
            *(_DWORD *)(this + 5416) + 12);
    v12 = *(_DWORD *)(this + 5416);
    *(_DWORD *)this = v11;
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(v12 + 12) + 8))(*(_DWORD *)(v12 + 12));
    switch ( *(_DWORD *)(this + 4372) )
    {
      case 2:
        v3 = 32;
        break;
      case 3:
        v3 = 256;
        break;
      case 4:
        v3 = 64;
        break;
      case 0x10:
        v3 = 0x100000;
        break;
      default:
        break;
    }
    v13 = sub_53F3F0((int *)this, a2, *(_DWORD **)(this + 5416), *(_DWORD *)(this + 5420), v3);
    v14 = *(_DWORD *)(this + 5420);
    *(_DWORD *)this = v13;
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(this + 4352) + 124))(
                        *(_DWORD *)(this + 4352),
                        *(_DWORD *)(*(_DWORD *)(this + 5416) + 12),
                        *(_DWORD *)(v14 + 12));
    sub_53EB70((char *)this, (int)a3);
    if ( a3 )
      FlagBitSetter(a3, 2u);
    return -2;
  }
}
