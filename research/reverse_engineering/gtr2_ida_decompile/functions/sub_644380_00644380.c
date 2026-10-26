unsigned int __thiscall sub_644380(void *this, const void *a2, unsigned int a3)
{
  int v4; // eax
  int v5; // ecx
  int v6; // edi
  unsigned int v7; // esi
  char *v8; // eax
  unsigned int v9; // ecx
  int v11; // [esp+0h] [ebp-10h]

  v4 = *((_DWORD *)this + 1);
  v5 = *((_DWORD *)this + 2);
  if ( v5 + a3 > v4 + *((_DWORD *)this + 3) && *((_BYTE *)this + 24) )
  {
    v6 = v5 - v4;
    v7 = a3 + v5 + *((_DWORD *)this + 5) - v4;
    sub_4F14D0(v11);
    v8 = (char *)sub_5A8CF0(*((void **)this + 1), v7 + *((_DWORD *)this + 3), 0, 16, 0);
    v9 = v7 + *((_DWORD *)this + 3);
    *((_DWORD *)this + 1) = v8;
    *((_DWORD *)this + 3) = v9;
    *((_DWORD *)this + 2) = &v8[v6];
  }
  qmemcpy(*((void **)this + 2), a2, a3);
  (*(void (__thiscall **)(void *, unsigned int))(*(_DWORD *)this + 140))(this, a3);
  *((_DWORD *)this + 4) = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 128))(this);
  return a3;
}
