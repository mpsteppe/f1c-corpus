_DWORD *__thiscall sub_4E5E20(_DWORD *this, char *String2)
{
  _DWORD *v3; // esi
  int v4; // ebx
  _DWORD *v5; // eax
  _DWORD *v6; // eax

  v3 = (_DWORD *)sub_4E5DB0(this, String2);
  if ( !v3 )
  {
    sub_4E8D60(String2);
    v4 = dword_7D6B58 + 400 * dword_7D6B54;
    if ( v4 )
    {
      v5 = operator new(0x18u);
      v3 = v5 ? sub_4E34D0(v5) : 0;
      sub_578600(v4 + 260);
      sub_578600(v4 + 4);
      if ( v3 )
      {
        v6 = operator new(0xCu);
        if ( v6 )
        {
          *v6 = v3;
          v6[1] = 0;
          *((_BYTE *)v6 + 8) = 1;
        }
        else
        {
          v6 = 0;
        }
        if ( !this[4] )
        {
          this[4] = v6;
          this[6] = v6;
          this[5] = v6;
          ++this[7];
          return v3;
        }
        *(_DWORD *)(this[5] + 4) = v6;
        this[5] = v6;
        ++this[7];
      }
    }
  }
  return v3;
}
