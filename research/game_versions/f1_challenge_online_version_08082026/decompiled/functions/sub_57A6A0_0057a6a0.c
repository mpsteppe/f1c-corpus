int __thiscall sub_57A6A0(_DWORD *this, int a2, int a3, int a4, char a5, int a6, int a7, char a8)
{
  int v8; // esi

  v8 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*this + 88))(*this);
  if ( !v8 )
    return 10;
  if ( a4 )
    (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(v8 + 72) + 32))(*(_DWORD *)(v8 + 72), a4);
  else
    *(_BYTE *)(*(_DWORD *)(v8 + 72) + 4) = 1;
  sub_586800(1, 0, a5, a6, a7);
  sub_586A00(a2, a3);
  if ( a8 )
    sub_585380(v8);
  else
    sub_585270(v8);
  return 0;
}
