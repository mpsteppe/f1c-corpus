void *__thiscall sub_5F3730(_DWORD *this, int *a2, int a3)
{
  void *v3; // ebp
  void *result; // eax
  char v6; // bl
  int v7; // eax
  int *v8; // ecx
  int v9; // edx
  void *v10; // [esp+28h] [ebp-4h] BYREF

  v3 = 0;
  v10 = 0;
  if ( !a2 || (*(_BYTE *)a2 & 0x40) == 0 )
  {
    v6 = 1;
    (*(void (__thiscall **)(_DWORD *, void *, void **, _DWORD, _DWORD, int))(*this + 12))(
      this,
      dword_FB2790,
      &v10,
      0,
      0,
      2);
    goto LABEL_16;
  }
  result = (void *)sub_5E7120(a2, 2);
  v10 = result;
  if ( result )
  {
    v6 = 0;
  }
  else
  {
    if ( (*(_BYTE *)a2 & 0x10) != 0 && a3 )
      v7 = *(_DWORD *)(a3 + 776);
    else
      v7 = 2;
    result = (void *)(*(int (__thiscall **)(_DWORD *, int *, void **, _DWORD, int, int))(*this + 12))(
                       this,
                       a2,
                       &v10,
                       0,
                       8,
                       v7);
    if ( result || !v10 )
      return result;
    v6 = 1;
    result = (void *)sub_60A820(0);
  }
  if ( (*a2 & 0x40000) == 0 )
  {
    v8 = (int *)a2[29];
    if ( v8 )
    {
      result = (void *)sub_5E7120(v8, 0);
LABEL_17:
      v3 = result;
      goto LABEL_18;
    }
LABEL_16:
    result = (void *)sub_5E7120((int *)dword_FB2794, 2);
    goto LABEL_17;
  }
LABEL_18:
  if ( (int *)this[2431] != a2 )
  {
    this[2] = (*(int (__stdcall **)(_DWORD, _DWORD, void *))(*(_DWORD *)this[2387] + 148))(this[2387], 0, v10);
    result = (void *)(*(int (__stdcall **)(_DWORD, void *))(*(_DWORD *)this[2387] + 156))(this[2387], v3);
    this[2] = result;
    if ( a2 )
    {
      this[2431] = a2;
    }
    else
    {
      result = dword_FB2790;
      this[2431] = dword_FB2790;
    }
  }
  if ( v6 )
  {
    result = v10;
    if ( v10 )
    {
      v9 = *this;
      if ( a2 )
        return (void *)(*(int (__thiscall **)(_DWORD *, int *, void *, int))(v9 + 16))(this, a2, v10, 8);
      else
        return (void *)(*(int (__thiscall **)(_DWORD *, void *, void *, int))(v9 + 16))(this, dword_FB2790, v10, 2);
    }
  }
  return result;
}
