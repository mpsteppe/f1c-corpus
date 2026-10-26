int __thiscall sub_603980(_DWORD **this, int *a2, int a3, int a4)
{
  int v5; // esi
  int v6; // eax
  char v8; // [esp+0h] [ebp-Ch]

  v5 = sub_5E7120(a2, a3);
  if ( v5
    && (v6 = sub_5E7120(a2, a4)) != 0
    && (*(int (__stdcall **)(_DWORD *, int, _DWORD, int, _DWORD))(*this[2387] + 120))(this[2387], v5, 0, v6, 0) )
  {
    sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, "HW error during surface refresh.", v8);
    return -1;
  }
  else
  {
    *a2 |= 0x100u;
    return 0;
  }
}
