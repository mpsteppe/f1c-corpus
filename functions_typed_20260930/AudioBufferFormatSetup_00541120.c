int __thiscall sub_541120(int *this, int a2, int a3, int a4, int a5, int a6, char a7, __int16 a8, int a9, int a10)
{
  int result; // eax
  int v12; // ebp
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // [esp+8h] [ebp-50h]
  _BYTE v18[32]; // [esp+18h] [ebp-40h] BYREF
  int v19; // [esp+38h] [ebp-20h]
  int v20; // [esp+3Ch] [ebp-1Ch]
  int v21; // [esp+44h] [ebp-14h]
  int v22; // [esp+4Ch] [ebp-Ch]
  int v23; // [esp+50h] [ebp-8h]

  StructInitWithDefaultValues(v18);
  result = a3;
  v12 = 65538;
  if ( a3 && *(_DWORD *)(a3 + 32) )
  {
    if ( this[1267] )
    {
      v13 = this[1088];
      this[1267] = 0;
      *this = (*(int (__stdcall **)(int, int, int *))(*(_DWORD *)v13 + 148))(v13, 256, this + 1283);
    }
    *this = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)this[1088] + 200))(this[1088], 7, 0);
    if ( a6 )
    {
      result = sub_554F80(a2, a6);
      if ( !result )
        return result;
      v14 = a8 & 0x1400;
      this[1116] = 256;
      v19 = 4;
      v21 = a6;
      if ( v14 == 1024 )
      {
        v22 = 1;
      }
      else if ( v14 == 4096 )
      {
        v22 = 2;
      }
      v15 = a8 & 0x2800;
      if ( v15 == 2048 )
      {
        v23 = 1;
      }
      else if ( v15 == 0x2000 )
      {
        v23 = 2;
      }
      if ( (a7 & 0x40) != 0 )
        this[1116] = 1280;
      if ( (a8 & 0x80u) != 0 )
      {
        this[1116] |= 1u;
        v20 = 3;
      }
      if ( (a7 & 0x20) != 0 )
      {
        this[1116] |= 0x800u;
        v20 = 2;
        v12 = 393221;
      }
    }
    else
    {
      this[1116] = 256;
      v19 = 0;
      if ( (a7 & 0x20) != 0 )
      {
        this[1116] = 2304;
        v20 = 2;
        v12 = 327686;
      }
    }
    sub_554790(this[1116], v12, a9);
    MultiFieldSetterDispatchingTo7SubSetters(v18, 0);
    StateFieldSetWithChainedInit(1);
    PropertyValueSetterWithRefreshOnChange(a3);
    if ( a10 )
      v16 = (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)this[1088] + 280))(this[1088], 6, a4, a10);
    else
      v16 = (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)this[1088] + 280))(this[1088], 4, a4, a5 / 3);
    v17 = this[1262];
    *this = v16;
    result = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 200))(this[1088], 7, v17);
    *this = result;
  }
  return result;
}

