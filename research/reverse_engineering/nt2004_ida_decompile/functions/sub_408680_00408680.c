_DWORD *__thiscall sub_408680(_DWORD *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // edi
  _DWORD *v4; // eax

  if ( !this[34] )
    return 0;
  v2 = operator new(0x68u);
  if ( !v2 )
    return 0;
  v3 = sub_406DE0(v2, (int)this);
  if ( !v3 )
    return 0;
  v4 = operator new(0xCu);
  if ( v4 )
  {
    *v4 = v3;
    v4[1] = 0;
    *((_BYTE *)v4 + 8) = 0;
  }
  else
  {
    v4 = 0;
  }
  if ( this[6] )
  {
    *(_DWORD *)(this[7] + 4) = v4;
  }
  else
  {
    this[6] = v4;
    this[8] = v4;
  }
  this[7] = v4;
  ++this[9];
  return v3;
}
