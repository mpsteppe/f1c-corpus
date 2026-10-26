char __thiscall sub_5209D0(_BYTE *this, int a2)
{
  int v2; // esi
  char v4; // al

  v2 = a2;
  (*(void (__thiscall **)(int, int *, int))(*(_DWORD *)a2 + 28))(a2, &a2, 1);
  v4 = (unsigned __int8)a2 >> 7;
  *this = a2 & 0x7F;
  this[204] = v4;
  (*(void (__thiscall **)(int, int *, int))(*(_DWORD *)v2 + 28))(v2, &a2, 1);
  (*(void (__thiscall **)(int, _BYTE *, _DWORD))(*(_DWORD *)v2 + 28))(v2, this + 1, (unsigned __int8)a2);
  this[(unsigned __int8)a2 + 1] = 0;
  (*(void (__thiscall **)(int, int *, int))(*(_DWORD *)v2 + 28))(v2, &a2, 1);
  (*(void (__thiscall **)(int, _BYTE *, _DWORD))(*(_DWORD *)v2 + 28))(v2, this + 33, (unsigned __int8)a2);
  this[(unsigned __int8)a2 + 33] = 0;
  (*(void (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)v2 + 28))(v2, this + 65, 64);
  (*(void (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)v2 + 28))(v2, this + 129, 64);
  (*(void (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)v2 + 28))(v2, this + 196, 4);
  (*(void (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)v2 + 28))(v2, this + 200, 4);
  return 1;
}
