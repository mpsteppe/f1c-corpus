int __thiscall sub_5F27D0(void *this, int a2, _DWORD *a3, _DWORD *a4, int a5)
{
  int v5; // edx
  int v6; // edx
  _DWORD v8[8]; // [esp+0h] [ebp-20h] BYREF

  v8[0] = *a3;
  v5 = a3[1];
  v8[2] = a3[2];
  v8[1] = v5;
  v8[3] = *a4;
  v6 = a4[1];
  v8[5] = a4[2];
  v8[4] = v6;
  return (*(int (__thiscall **)(void *, int, _DWORD *, int, int))(*(_DWORD *)this + 488))(this, a2, v8, a5, 1);
}
