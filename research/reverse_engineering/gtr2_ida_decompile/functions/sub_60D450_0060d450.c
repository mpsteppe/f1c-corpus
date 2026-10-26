int __thiscall sub_60D450(int this, int a2, int a3)
{
  _DWORD *v4; // ecx
  int result; // eax
  int v6; // [esp+8h] [ebp-10h] BYREF
  int v7; // [esp+Ch] [ebp-Ch] BYREF
  int v8; // [esp+10h] [ebp-8h] BYREF
  int v9; // [esp+14h] [ebp-4h] BYREF

  sub_5E5550((int *)a2, &v6, &v7, &v8, &v9, 0);
  if ( (a3 & 0x20000000) != 0 )
    goto LABEL_4;
  v4 = *(_DWORD **)(a2 + 772);
  if ( v4 )
  {
    sub_5E7540(v4, v6, v7, *(_DWORD **)(a2 + 768), v6, v7, v8, v9, 0, 0, 0);
LABEL_4:
    result = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, int, _DWORD, int, _DWORD))(**(_DWORD **)(this + 9548) + 172))(
               *(_DWORD *)(this + 9548),
               0,
               0,
               2,
               0,
               1065353216,
               0);
    *(_DWORD *)(this + 8) = result;
    return result;
  }
  if ( (*(_BYTE *)a2 & 2) == 0 )
    goto LABEL_4;
  result = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, int, _DWORD, int, _DWORD))(**(_DWORD **)(this + 9548) + 172))(
             *(_DWORD *)(this + 9548),
             0,
             0,
             3,
             *(_DWORD *)(a2 + 140),
             1065353216,
             0);
  *(_DWORD *)(this + 8) = result;
  return result;
}
