int __thiscall sub_5B4CC0(int *this, _DWORD *a2, int a3)
{
  _DWORD *v3; // edi
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int result; // eax
  _DWORD *v14; // eax
  int v15; // edx
  _DWORD v16[2]; // [esp+Ch] [ebp-18h] BYREF
  int v17; // [esp+14h] [ebp-10h]
  int v18; // [esp+18h] [ebp-Ch]
  int v19; // [esp+1Ch] [ebp-8h]
  int v20; // [esp+20h] [ebp-4h]

  v3 = a2;
  if ( a2 && (v5 = a2[14], (v5 & 0x40000) != 0) )
  {
    v6 = a2[4];
    if ( v6 )
    {
      if ( (v5 & 0x200000) != 0 )
      {
        v7 = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)this[1112] + 124))(this[1112], v6, 0);
      }
      else
      {
        v8 = a2[2];
        if ( v8 && (v9 = *(_DWORD *)(v8 + 16)) != 0 )
          v7 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1112] + 124))(this[1112], v6, v9);
        else
          v7 = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)this[1112] + 124))(
                 this[1112],
                 v6,
                 *(_DWORD *)(this[2150] + 16));
      }
    }
    else
    {
      v10 = a2[6];
      if ( !v10 )
        goto LABEL_19;
      if ( (v5 & 0x200000) != 0 )
      {
        v7 = (*(int (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)this[1112] + 124))(this[1112], 0, 0);
      }
      else
      {
        *this = (*(int (__stdcall **)(int, _DWORD, _DWORD **))(*(_DWORD *)v10 + 60))(v10, 0, &a2);
        v11 = v3[2];
        if ( v11 && (v12 = *(_DWORD *)(v11 + 16)) != 0 )
        {
          *this = (*(int (__stdcall **)(int, _DWORD *, int))(*(_DWORD *)this[1112] + 124))(this[1112], a2, v12);
          v7 = (*(int (__stdcall **)(_DWORD *))(*a2 + 8))(a2);
        }
        else
        {
          *this = (*(int (__stdcall **)(int, _DWORD *, _DWORD))(*(_DWORD *)this[1112] + 124))(
                    this[1112],
                    a2,
                    *(_DWORD *)(this[2150] + 16));
          v7 = (*(int (__stdcall **)(_DWORD *))(*a2 + 8))(a2);
        }
      }
    }
  }
  else
  {
    v7 = (*(int (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)this[1112] + 124))(
           this[1112],
           *(_DWORD *)(this[2149] + 16),
           *(_DWORD *)(this[2150] + 16));
  }
  *this = v7;
LABEL_19:
  result = a3;
  if ( a3 )
  {
    v16[0] = 0;
    v16[1] = 0;
    v19 = 0;
    v20 = 1065353216;
    if ( v3 )
    {
      v15 = v3[8];
      v17 = v3[7];
      v18 = v15;
    }
    else
    {
      v14 = (_DWORD *)this[2149];
      v17 = v14[7];
      v18 = v14[8];
    }
    result = (*(int (__stdcall **)(int, _DWORD *))(*(_DWORD *)this[1112] + 160))(this[1112], v16);
    *this = result;
  }
  return result;
}
