int __thiscall sub_5BD390(_DWORD *this, double a2, int a3, const void *a4)
{
  int v4; // ebx
  int v6; // eax
  int result; // eax
  int i; // edi
  int v9; // ecx

  v4 = a3;
  v6 = this[133];
  if ( v6 )
    (*(void (__thiscall **)(int, _DWORD, _DWORD, int))(*(_DWORD *)v6 + 24))(v6, LODWORD(a2), HIDWORD(a2), a3);
  if ( (_BYTE)v4 )
  {
    sub_5BC2F0(this, a2);
    sub_5BD0D0((int)this, a4);
    sub_5BC340(this, a2);
    sub_5BC1F0(this, &a2);
  }
  result = this[108];
  for ( i = 0; i < result; ++i )
  {
    v9 = *(_DWORD *)(this[110] + 4 * i);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, int, _DWORD))(*(_DWORD *)v9 + 36))(v9, LODWORD(a2), HIDWORD(a2), v4, 0);
    result = this[108];
  }
  return result;
}
