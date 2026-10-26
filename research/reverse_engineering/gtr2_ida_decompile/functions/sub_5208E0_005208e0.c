char __thiscall sub_5208E0(void *this, int *a2)
{
  int v2; // edx
  int v4; // edx
  int v5; // edx
  unsigned __int8 v7; // [esp+21h] [ebp-1h] BYREF

  v2 = *a2;
  v7 = *(_BYTE *)this | (*((_BYTE *)this + 204) == 0 ? 0 : 0x80);
  (*(void (__thiscall **)(int *, unsigned __int8 *, int))(v2 + 24))(a2, &v7, 1);
  v4 = *a2;
  v7 = strlen((const char *)this + 1);
  (*(void (__thiscall **)(int *, unsigned __int8 *, int))(v4 + 24))(a2, &v7, 1);
  (*(void (__thiscall **)(int *, int, _DWORD))(*a2 + 24))(a2, (int)this + 1, v7);
  v5 = *a2;
  v7 = strlen((const char *)this + 33);
  (*(void (__thiscall **)(int *, unsigned __int8 *, int))(v5 + 24))(a2, &v7, 1);
  (*(void (__thiscall **)(int *, int, _DWORD))(*a2 + 24))(a2, (int)this + 33, v7);
  (*(void (__thiscall **)(int *, int, int))(*a2 + 24))(a2, (int)this + 65, 64);
  (*(void (__thiscall **)(int *, int, int))(*a2 + 24))(a2, (int)this + 129, 64);
  (*(void (__thiscall **)(int *, int, int))(*a2 + 24))(a2, (int)this + 196, 4);
  (*(void (__thiscall **)(int *, int, int))(*a2 + 24))(a2, (int)this + 200, 4);
  return 1;
}
