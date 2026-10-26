_DWORD *__thiscall sub_57A420(_DWORD *this, _DWORD *a2, _BYTE *a3)
{
  int v4; // eax

  *a3 = 0;
  if ( *a2 > 1u )
  {
    *this = 0;
    *a3 = 1;
  }
  else
  {
    if ( sub_587C03(3064) )
      v4 = sub_57BA10(a2, a3);
    else
      v4 = 0;
    *this = v4;
    if ( *a3 )
    {
      if ( v4 )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 68))(v4, 1);
      *this = 0;
    }
  }
  return this;
}
