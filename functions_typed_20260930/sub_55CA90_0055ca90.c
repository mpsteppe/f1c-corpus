int __thiscall sub_55CA90(int *this, _DWORD *a2, int a3)
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
  int v14; // eax
  _DWORD *v15; // eax
  _DWORD v16[6]; // [esp+Ch] [ebp-18h] BYREF

  v3 = a2;
  if ( a2 && (v5 = a2[6], (v5 & 0x40000) != 0) )
  {
    v6 = a2[3];
    if ( v6 )
    {
      if ( (v5 & 0x200000) != 0 )
      {
        v7 = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)this[1088] + 124))(this[1088], v6, 0);
      }
      else
      {
        v8 = a2[1];
        if ( v8 && (v9 = *(_DWORD *)(v8 + 12)) != 0 )
          v7 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 124))(this[1088], v6, v9);
        else
          v7 = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)this[1088] + 124))(
                 this[1088],
                 v6,
                 *(_DWORD *)(this[1355] + 12));
      }
    }
    else
    {
      v10 = a2[5];
      if ( !v10 )
        goto LABEL_19;
      if ( (v5 & 0x200000) != 0 )
      {
        v7 = (*(int (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)this[1088] + 124))(this[1088], 0, 0);
      }
      else
      {
        *this = (*(int (__stdcall **)(int, _DWORD, _DWORD **))(*(_DWORD *)v10 + 60))(v10, 0, &a2);
        v11 = v3[1];
        if ( v11 && (v12 = *(_DWORD *)(v11 + 12)) != 0 )
        {
          *this = (*(int (__stdcall **)(int, _DWORD *, int))(*(_DWORD *)this[1088] + 124))(this[1088], a2, v12);
          v7 = (*(int (__stdcall **)(_DWORD *))(*a2 + 8))(a2);
        }
        else
        {
          *this = (*(int (__stdcall **)(int, _DWORD *, _DWORD))(*(_DWORD *)this[1088] + 124))(
                    this[1088],
                    a2,
                    *(_DWORD *)(this[1355] + 12));
          v7 = (*(int (__stdcall **)(_DWORD *))(*a2 + 8))(a2);
        }
      }
    }
  }
  else
  {
    v7 = (*(int (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)this[1088] + 124))(
           this[1088],
           *(_DWORD *)(this[1354] + 12),
           *(_DWORD *)(this[1355] + 12));
  }
  *this = v7;
LABEL_19:
  result = a3;
  if ( a3 )
  {
    v14 = v3[8];
    v16[2] = v3[7];
    v16[3] = v14;
    v15 = (_DWORD *)this[1088];
    v16[0] = 0;
    v16[1] = 0;
    v16[4] = 0;
    v16[5] = 1065353216;
    result = (*(int (__stdcall **)(_DWORD *, _DWORD *))(*v15 + 160))(v15, v16);
    *this = result;
  }
  return result;
}

