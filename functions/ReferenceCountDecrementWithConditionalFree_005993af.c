void __thiscall sub_5993AF(_DWORD *this, char a2)
{
  int v3; // eax
  _BYTE *v4; // ecx
  char v5; // al

  if ( a2 )
  {
    v3 = this[1];
    if ( v3 )
    {
      v4 = (_BYTE *)(v3 - 1);
      v5 = *(_BYTE *)(v3 - 1);
      if ( !v5 || v5 == -1 )
        FreeWrapper_7bcf(v4);
      else
        *v4 = v5 - 1;
    }
  }
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
}
