char __thiscall sub_46FA10(void *this, int a2, int a3)
{
  char v3; // bl
  int v4; // edi
  void *v6; // ecx
  _DWORD *v7; // eax
  int v8; // eax
  _DWORD *v9; // eax

  v3 = 0;
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
          v7 = (_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)this + 172))(this);
          if ( v7 )
          {
            ++*v7;
            (*(void (__thiscall **)(void *))(*(_DWORD *)this + 156))(this);
          }
          goto LABEL_13;
        }
        v8 = *((_DWORD *)this + 67) + 1;
LABEL_12:
        *((_DWORD *)this + 67) = v8;
        sub_49EA70(v6);
LABEL_13:
        v3 = 1;
      }
      if ( ++v4 >= a3 )
        goto LABEL_15;
    }
    v6 = this;
    if ( *((_BYTE *)this + 284) )
    {
      v9 = (_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)this + 172))(this);
      if ( v9 )
      {
        --*v9;
        (*(void (__thiscall **)(void *))(*(_DWORD *)this + 156))(this);
      }
      goto LABEL_13;
    }
    v8 = *((_DWORD *)this + 67) - 1;
    goto LABEL_12;
  }
LABEL_15:
  sub_434120(&byte_75CBC8, *((_DWORD *)this + 77), *((float *)this + 76));
  return v3;
}
