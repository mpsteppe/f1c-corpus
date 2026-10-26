int __thiscall sub_4C28D0(_DWORD *this, int a2)
{
  int v3; // edi
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  int v6; // eax

  if ( !sub_4C2860(this, a2) )
  {
    sub_4C5690(a2);
    v3 = dword_8AC490 + 396 * dword_8AC48C;
    if ( v3 )
    {
      v4 = (_DWORD *)sub_587C03(24);
      v5 = v4 ? sub_4C03A0(v4) : 0;
      sub_566650(v3 + 260);
      sub_566650(v3 + 4);
      if ( v5 )
      {
        v6 = sub_587C03(12);
        if ( v6 )
        {
          *(_DWORD *)v6 = v5;
          *(_DWORD *)(v6 + 4) = 0;
          *(_BYTE *)(v6 + 8) = 1;
        }
        else
        {
          v6 = 0;
        }
        if ( this[4] )
        {
          *(_DWORD *)(this[5] + 4) = v6;
        }
        else
        {
          this[4] = v6;
          this[6] = v6;
        }
        this[5] = v6;
        ++this[7];
      }
    }
  }
  return sub_4C2860(this, a2);
}
