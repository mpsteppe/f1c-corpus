int __thiscall sub_5AC040(int this, int a2, _DWORD *a3)
{
  int v4; // ebx
  unsigned int v5; // ebp
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v12; // eax
  int v13; // edx
  int v14; // eax
  int v15; // edx
  double v16; // st7
  double v17; // st7
  unsigned __int16 *v18; // edi
  __int64 v19; // rax
  unsigned __int16 v20; // bp
  int v21; // ecx
  unsigned __int16 v22; // bp
  char Buffer[256]; // [esp+34h] [ebp-700h] BYREF
  _WORD v24[768]; // [esp+134h] [ebp-600h] BYREF

  v4 = 0;
  v5 = 0;
  if ( *(_DWORD *)(this + 5148) )
  {
    v6 = *(_DWORD *)(this + 4448);
    *(_DWORD *)(this + 5148) = 0;
    *(_DWORD *)this = (*(int (__stdcall **)(int))(*(_DWORD *)v6 + 140))(v6);
  }
  v7 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(this + 4448) + 60))(
         *(_DWORD *)(this + 4448),
         0,
         0,
         0,
         0);
  *(_DWORD *)this = v7;
  if ( v7 != -2005530520
    || (v8 = (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(this + 4448) + 12))(*(_DWORD *)(this + 4448)),
        *(_DWORD *)this = v8,
        v8 != -2005530519) )
  {
    if ( *(float *)(this + 5200) != 0.0 )
    {
      v16 = sub_5AC8D0(*(_DWORD *)(this + 5196));
      if ( v16 < *(float *)(this + 5200) )
      {
        v17 = v16 / *(float *)(this + 5200);
        v18 = (unsigned __int16 *)(this + 5204);
        do
        {
          v19 = (__int64)((double)(v18[768] - *v18) * v17);
          HIDWORD(v19) = v18[1024];
          v20 = v18[256];
          v24[v4] = *v18 + v19;
          v21 = v18[1280];
          LOWORD(v19) = v20 + (__int64)((double)(HIDWORD(v19) - v20) * v17);
          v22 = v18[512];
          v24[v4 + 256] = v19;
          ++v18;
          v24[v4++ + 512] = v22 + (__int64)((double)(v21 - v22) * v17);
        }
        while ( v4 < 256 );
        (*(void (__stdcall **)(_DWORD, _DWORD, _WORD *))(**(_DWORD **)(this + 4448) + 72))(
          *(_DWORD *)(this + 4448),
          0,
          v24);
        return 0;
      }
      (*(void (__stdcall **)(_DWORD, _DWORD, int))(**(_DWORD **)(this + 4448) + 72))(
        *(_DWORD *)(this + 4448),
        0,
        this + 6740);
      sub_5AC680(*(_DWORD *)(this + 5196));
      *(_DWORD *)(this + 5200) = 0;
    }
    return 0;
  }
  *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(this + 4448) + 124))(
                      *(_DWORD *)(this + 4448),
                      0,
                      0);
  sub_5A65C0((int *)this, *(_DWORD *)(this + 8600));
  sub_5A6150((_DWORD *)this, a3);
  v9 = (*(int (__stdcall **)(_DWORD, int))(**(_DWORD **)(this + 4448) + 56))(*(_DWORD *)(this + 4448), this + 4452);
  *(_DWORD *)this = v9;
  if ( v9 )
  {
    if ( v9 == -2005530520 )
    {
      v10 = (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(this + 4448) + 12))(*(_DWORD *)(this + 4448));
      *(_DWORD *)this = v10;
      if ( v10 == -2005530519 )
        sprintf(Buffer, "%s - 0x%X", aCouldNotSetDis, -2005530519);
    }
    else
    {
      sprintf(Buffer, "%s - 0x%X", aCouldNotSetDis, v9);
    }
    sub_591C60(this, -1, Buffer);
    return -1;
  }
  else
  {
    v12 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, int))(**(_DWORD **)(this + 4448) + 64))(
            *(_DWORD *)(this + 4448),
            0,
            0,
            *(_DWORD *)(this + 8596) + 16);
    v13 = *(_DWORD *)(this + 8596);
    *(_DWORD *)this = v12;
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(v13 + 16) + 8))(*(_DWORD *)(v13 + 16));
    switch ( *(_DWORD *)(this + 4468) )
    {
      case 2:
        v5 = 32;
        break;
      case 3:
        v5 = 256;
        break;
      case 4:
        v5 = 64;
        break;
      case 0x10:
        v5 = 0x100000;
        break;
      default:
        break;
    }
    v14 = sub_5A62C0((int *)this, a2, *(_DWORD **)(this + 8596), *(_DWORD *)(this + 8600), v5);
    v15 = *(_DWORD *)(this + 8600);
    *(_DWORD *)this = v14;
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(this + 4448) + 124))(
                        *(_DWORD *)(this + 4448),
                        *(_DWORD *)(*(_DWORD *)(this + 8596) + 16),
                        *(_DWORD *)(v15 + 16));
    sub_5A5A60((char *)this, a3);
    if ( a3 )
      sub_597BA0(a3, 2u);
    return -2;
  }
}
