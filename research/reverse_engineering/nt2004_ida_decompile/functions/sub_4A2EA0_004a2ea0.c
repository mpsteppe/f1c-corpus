char __thiscall sub_4A2EA0(_DWORD *this, int a2, int a3)
{
  char result; // al
  int v4; // edi
  _DWORD *v6; // ecx
  _DWORD *v7; // eax
  int v8; // eax
  _DWORD *v9; // eax

  result = 0;
  v4 = 0;
  if ( a3 > 0 )
  {
    while ( *(_WORD *)(a2 + 2 * v4) != 203 )
    {
      if ( *(_WORD *)(a2 + 2 * v4) == 205 )
      {
        v6 = this;
        if ( *((_BYTE *)this + 284) )
        {
          v7 = (_DWORD *)(*(int (__thiscall **)(_DWORD *))(*this + 172))(this);
          if ( v7 )
          {
            ++*v7;
            (*(void (__thiscall **)(_DWORD *))(*this + 156))(this);
          }
          goto LABEL_13;
        }
        v8 = this[67] + 1;
LABEL_12:
        this[67] = v8;
        sub_49EA70(v6);
LABEL_13:
        result = 1;
      }
      if ( ++v4 >= a3 )
        return result;
    }
    v6 = this;
    if ( *((_BYTE *)this + 284) )
    {
      v9 = (_DWORD *)(*(int (__thiscall **)(_DWORD *))(*this + 172))(this);
      if ( v9 )
      {
        --*v9;
        (*(void (__thiscall **)(_DWORD *))(*this + 156))(this);
      }
      goto LABEL_13;
    }
    v8 = this[67] - 1;
    goto LABEL_12;
  }
  return result;
}
