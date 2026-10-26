int __thiscall sub_5F30A0(_DWORD *this, int a2, int a3, int a4, char a5)
{
  int v6; // edx
  int v7; // eax
  int v8; // ebp
  int v9; // edx
  int v10; // ebx
  int v11; // esi
  int v12; // ebp
  int result; // eax
  int v14; // [esp+4Ch] [ebp-20h]
  int v15; // [esp+68h] [ebp-4h]

  (*(void (__thiscall **)(_DWORD *, _DWORD, int, _DWORD, _DWORD))(*this + 40))(this, 0, a4, 0, 0);
  if ( !this[2412] )
  {
    sub_609BF0(5);
    v6 = *this;
    this[1212] = -16777216;
    (*(void (__thiscall **)(_DWORD *, int, int))(v6 + 44))(this, 60, -16777216);
    if ( !a5 )
    {
      sub_60A000(4);
      goto LABEL_7;
    }
    sub_60A000(3);
  }
  if ( !a5 )
  {
LABEL_7:
    (*(void (__thiscall **)(_DWORD *, int, _DWORD, _DWORD))(*this + 20))(this, 256, 0, 0);
    goto LABEL_8;
  }
  (*(void (__thiscall **)(_DWORD *, int, int, int))(*this + 20))(this, 2308, 131074, 127);
LABEL_8:
  sub_60A500(0);
  v7 = (*(int (__stdcall **)(_DWORD, int, _DWORD))(*(_DWORD *)this[2387] + 228))(this[2387], 7, 0);
  v8 = a3;
  v9 = *this;
  this[2] = v7;
  if ( (*(int (__thiscall **)(_DWORD *, int))(v9 + 396))(this, a3) )
  {
    if ( !*((_BYTE *)this + 4815) )
    {
      v10 = 0;
      if ( *(int *)(a3 + 360) > 0 )
      {
        v15 = 0;
        do
        {
          v11 = v15 + *(_DWORD *)(v8 + 364);
          if ( *(_DWORD *)(v11 + 44) && *(_DWORD *)(v11 + 48) )
          {
            if ( a5 )
            {
              v12 = sub_5E3450(*(_DWORD **)(v11 + 4), (_DWORD *)v11, 0);
              if ( (*(int (__thiscall **)(_DWORD *, int))(*this + 328))(this, v12) )
                sub_60A820(v12);
              v8 = a3;
            }
            (*(void (__thiscall **)(_DWORD *, int, _DWORD))(*this + 28))(this, v11, 0);
            v14 = *(_DWORD *)(a2 + 272);
            sub_5F7B60(0, 0);
            sub_5FA770(v14, v11, 0);
            this[2] = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this[2387] + 328))(
                        this[2387],
                        *(_DWORD *)(v11 + 80),
                        *(_DWORD *)(v11 + 52),
                        0,
                        *(_DWORD *)(v11 + 8),
                        *(_DWORD *)(v11 + 56),
                        *(_DWORD *)(v11 + 84));
          }
          ++v10;
          v15 += 108;
        }
        while ( v10 < *(_DWORD *)(v8 + 360) );
      }
    }
  }
  result = (*(int (__stdcall **)(_DWORD, int, int))(*(_DWORD *)this[2387] + 228))(this[2387], 7, 1);
  this[2] = result;
  return result;
}
