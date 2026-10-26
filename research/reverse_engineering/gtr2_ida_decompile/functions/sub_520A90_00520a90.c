char __thiscall sub_520A90(char *this, int a2)
{
  char *v4; // edi
  int v5; // ebx

  (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 24))(a2, this, 64);
  (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 24))(a2, this + 64, 8);
  (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 24))(a2, this + 72, 64);
  (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 24))(a2, this + 136, 64);
  (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 24))(a2, this + 200, 4);
  (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 24))(a2, this + 204, 4);
  (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 24))(a2, this + 208, 4);
  (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 24))(a2, this + 212, 4);
  (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 24))(a2, this + 216, 4);
  (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 24))(a2, this + 220, 4);
  (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 24))(a2, this + 224, 4);
  (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 24))(a2, this + 228, 4);
  (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 24))(a2, this + 232, 4);
  v4 = this + 236;
  v5 = 3;
  do
  {
    (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 24))(a2, v4, 4);
    v4 += 4;
    --v5;
  }
  while ( v5 );
  return 1;
}
