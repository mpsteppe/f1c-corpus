// f1c  0x00554b20  size=189
int __thiscall sub_554B20(int *this, int a2, int a3)
{
  _DWORD *v4; // ecx
  int result; // eax
  int *v6; // eax
  int v7; // edx
  int v8; // [esp+8h] [ebp-10h] BYREF
  int v9; // [esp+Ch] [ebp-Ch] BYREF
  int v10; // [esp+10h] [ebp-8h] BYREF
  int v11; // [esp+14h] [ebp-4h] BYREF

  sub_5424E0((_DWORD *)a2, &v8, &v9, &v10, &v11);
  if ( a3 )
    goto LABEL_4;
  v4 = *(_DWORD **)(a2 + 416);
  if ( v4 )
  {
    sub_543250(v4, v8, v9, (_DWORD *)this[1354], v8, v9, v10, v11, 0, 0);
LABEL_4:
    result = (*(int (__stdcall **)(int, _DWORD, _DWORD, int, _DWORD, int, _DWORD))(*(_DWORD *)this[1088] + 144))(
               this[1088],
               0,
               0,
               2,
               0,
               1065353216,
               0);
    *this = result;
    return result;
  }
  v6 = (int *)this[1088];
  v7 = *v6;
  if ( (*(_BYTE *)(a2 + 128) & 2) != 0 )
    result = (*(int (__stdcall **)(int *, _DWORD, _DWORD, int, _DWORD, int, _DWORD))(v7 + 144))(
               v6,
               0,
               0,
               3,
               *(_DWORD *)(a2 + 124),
               1065353216,
               0);
  else
    result = (*(int (__stdcall **)(int *, _DWORD, _DWORD, int, _DWORD, int, _DWORD))(v7 + 144))(
               v6,
               0,
               0,
               2,
               0,
               1065353216,
               0);
  *this = result;
  return result;
}
