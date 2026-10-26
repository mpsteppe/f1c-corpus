char __thiscall sub_413CB0(int this, int a2, int a3)
{
  char v3; // bl
  int v5; // eax
  int v6; // eax
  _DWORD *v7; // ecx
  int v8; // esi

  v3 = 0;
  if ( !a2 )
    return v3;
  if ( sub_412870(*(_DWORD **)(this + 32), a2, a3) )
  {
    v5 = *(_DWORD *)(this + 32);
LABEL_10:
    *(_DWORD *)(this + 8) = v5;
    goto LABEL_11;
  }
  if ( sub_40D8F0(*(_DWORD **)(this + 36), a2, a3) )
  {
    *(_DWORD *)(this + 8) = *(_DWORD *)(this + 36);
  }
  else
  {
    if ( !sub_40DB60(*(_DWORD **)(this + 40), a2, a3) )
    {
      if ( !sub_412870(*(_DWORD **)(this + 44), a2, a3) )
        return v3;
      v5 = *(_DWORD *)(this + 44);
      goto LABEL_10;
    }
    *(_DWORD *)(this + 8) = *(_DWORD *)(this + 40);
  }
LABEL_11:
  v3 = 1;
  *(_BYTE *)(this + 56) = 1;
  v6 = sub_410B50((_DWORD *)this);
  sub_412EB0(v7, v6, 0);
  if ( (_BYTE)a3 )
  {
    v8 = *(_DWORD *)(this + 8);
    if ( v8 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 16))(v8);
  }
  return v3;
}
