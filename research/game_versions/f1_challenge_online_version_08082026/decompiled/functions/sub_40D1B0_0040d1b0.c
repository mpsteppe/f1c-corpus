char __thiscall sub_40D1B0(int this, int a2, char a3)
{
  char result; // al
  _DWORD *v5; // ecx
  int v6; // eax
  _DWORD *v7; // ecx
  int v8; // ecx

  result = 0;
  if ( a2 )
  {
    if ( sub_40A910(*(_DWORD **)(this + 24), a2, a3) )
    {
      sub_40CDD0((_DWORD *)this, *(_DWORD *)(this + 24));
    }
    else if ( sub_40B450(*(_DWORD **)(this + 28), a2, a3) )
    {
      sub_40CDD0((_DWORD *)this, *(_DWORD *)(this + 28));
    }
    else
    {
      if ( !sub_40BCD0(*(_DWORD **)(this + 32), a2, a3) )
        return 0;
      sub_40CDD0((_DWORD *)this, *(_DWORD *)(this + 32));
    }
    *(_BYTE *)(this + 44) = 1;
    v6 = sub_40CD60(v5);
    sub_40CDE0(v7, v6, 0);
    if ( a3 )
    {
      v8 = *(_DWORD *)(this + 8);
      if ( v8 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 16))(v8);
    }
    return 1;
  }
  return result;
}
