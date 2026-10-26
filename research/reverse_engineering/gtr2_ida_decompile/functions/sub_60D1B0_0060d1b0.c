int __thiscall sub_60D1B0(_DWORD *this, int a2, int a3, _DWORD *a4, _DWORD *a5, int a6)
{
  _DWORD *v6; // ebx
  int v7; // ebp
  _DWORD *v9; // edi
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int result; // eax
  int v15; // ecx
  int v16; // eax
  int *v17; // edx
  int v18; // ebp
  int v19; // eax
  int v20; // eax
  _DWORD *v21; // eax
  int v22; // eax
  int v23; // [esp+20h] [ebp-8h]
  int v24; // [esp+24h] [ebp-4h]

  v6 = a5;
  v7 = 0;
  v23 = 0;
  v24 = 0;
  if ( a2 )
  {
    v9 = *(_DWORD **)(a2 + 44);
    if ( !a5 )
      v6 = *(_DWORD **)(a2 + 88);
  }
  else
  {
    v9 = a4;
  }
  if ( !v9 || !v6 )
  {
    v22 = this[2387];
    this[2411] = 0;
    this[2] = (*(int (__stdcall **)(int, _DWORD))(*(_DWORD *)v22 + 368))(v22, 0);
    this[2412] = 0;
    result = (*(int (__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)this[2387] + 428))(this[2387], 0);
    goto LABEL_46;
  }
  if ( sub_5F7B60(v6, 0, 0) )
  {
    v7 = *(_DWORD *)(sub_5F7B60(v6, 0, 0) + 356);
    v23 = v7;
  }
  if ( sub_5F7BF0(v6, 0) )
    v24 = *(_DWORD *)(sub_5F7BF0(v6, 0) + 380);
  v10 = v9[6];
  if ( (v10 & 0xFF000) != 0 )
  {
    if ( (v10 & 0x2000) != 0 )
    {
      v11 = this[2387];
      v7 = 0;
      this[2413] = 0;
      v23 = 0;
      v24 = 0;
      this[2] = (*(int (__stdcall **)(int, int))(*(_DWORD *)v11 + 356))(v11, 324);
      v12 = v9[8];
    }
    else if ( (v10 & 0x1000) != 0 )
    {
      v12 = v9[8];
    }
    else if ( (v10 & 0x8000) == 0 )
    {
      if ( (v10 & 0x4000) != 0 )
      {
        v12 = v9[8];
      }
      else
      {
        if ( (v10 & 0x20000) == 0 )
          goto LABEL_33;
        v12 = v9[8];
      }
    }
    else
    {
      v12 = v9[8];
    }
    goto LABEL_32;
  }
  if ( (v10 & 1) != 0 )
    (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 32))(this, v9[9]);
  if ( (v9[6] & 2) != 0 )
    (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 32))(this, v9[10]);
  if ( (v9[6] & 4) != 0 )
    (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 32))(this, v9[11]);
  if ( (v9[6] & 0x10) != 0 )
    (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 32))(this, v9[12]);
  if ( (v9[6] & 0x20) != 0 )
  {
    v12 = v9[13];
LABEL_32:
    (*(void (__thiscall **)(_DWORD *, int))(*this + 32))(this, v12);
  }
LABEL_33:
  ++v9[4];
  if ( v7 )
  {
    v13 = sub_5F7B60(v6, 0, 0);
    sub_5FA770(v13, a3, a2, 0);
    result = *(_DWORD *)(sub_5F7B60(v6, 0, 0) + 352);
    if ( result == this[2413] )
      goto LABEL_39;
    v15 = this[2387];
    this[2414] = 0;
    this[2413] = result;
    result = (*(int (__stdcall **)(int, int))(*(_DWORD *)v15 + 348))(v15, result);
  }
  else
  {
    result = *(_DWORD *)(sub_5F7B60(v6, 0, 0) + 360);
    if ( result == this[2414] )
      goto LABEL_39;
    this[2413] = 0;
    v16 = sub_5F7B60(v6, 0, 0);
    v17 = (int *)this[2387];
    this[2414] = *(_DWORD *)(v16 + 360);
    v18 = *v17;
    v19 = sub_5F7B60(v6, 0, 0);
    result = (*(int (__stdcall **)(_DWORD, _DWORD))(v18 + 356))(this[2387], *(_DWORD *)(v19 + 360));
    v7 = v23;
  }
  this[2] = result;
LABEL_39:
  if ( v7 != this[2411] )
  {
    v20 = this[2387];
    this[2411] = v7;
    result = (*(int (__stdcall **)(int, int))(*(_DWORD *)v20 + 368))(v20, v7);
    this[2] = result;
  }
  if ( v24 )
  {
    v21 = (_DWORD *)sub_5F7BF0(v6, 0);
    result = sub_5F77D0(v21, a3, a2);
  }
  if ( v24 != this[2412] )
  {
    this[2412] = v24;
    result = (*(int (__stdcall **)(_DWORD, int))(*(_DWORD *)this[2387] + 428))(this[2387], v24);
LABEL_46:
    this[2] = result;
  }
  return result;
}
