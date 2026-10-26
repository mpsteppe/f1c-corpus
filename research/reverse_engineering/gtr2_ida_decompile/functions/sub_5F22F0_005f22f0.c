int __thiscall sub_5F22F0(void *this, int a2, int a3, _DWORD *a4, _DWORD *a5, int a6)
{
  int v6; // edx
  int v7; // edx
  _DWORD v9[8]; // [esp+0h] [ebp-20h] BYREF

  v9[0] = *a4;
  v6 = a4[1];
  v9[2] = a4[2];
  v9[1] = v6;
  v9[3] = *a5;
  v7 = a5[1];
  v9[5] = a5[2];
  v9[4] = v7;
  return (*(int (__thiscall **)(void *, int, int, _DWORD *, int, int))(*(_DWORD *)this + 496))(this, a2, a3, v9, a6, 1);
}
