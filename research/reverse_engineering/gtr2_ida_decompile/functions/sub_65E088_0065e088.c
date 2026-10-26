int __thiscall sub_65E088(unsigned int *this)
{
  _BYTE *v2; // eax
  char v3; // dl
  int v4; // eax
  unsigned int v5; // edi
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  char v8; // dl
  _BYTE *v9; // eax
  int v11; // [esp+4h] [ebp-4h]

  v11 = 0;
  if ( *this < this[1] )
  {
    while ( 1 )
    {
      v2 = (_BYTE *)*this;
      v3 = *(_BYTE *)*this;
      if ( v3 == 10 )
      {
        v4 = (int)(v2 + 1);
        ++this[7];
        v11 = 1;
LABEL_35:
        *this = v4;
        goto LABEL_36;
      }
      if ( v3 == 32 || v3 >= 9 && v3 <= 13 )
      {
        v4 = (int)(v2 + 1);
        goto LABEL_35;
      }
      if ( v3 != 47 )
        break;
      if ( (unsigned int)(v2 + 1) < this[1] && v2[1] == 47 )
        goto LABEL_10;
      v5 = this[1];
      if ( (unsigned int)(v2 + 1) >= v5 || v2[1] != 42 )
        break;
      v6 = v2 + 2;
      *this = (unsigned int)v6;
      if ( (unsigned int)v6 < v5 )
      {
        do
        {
          v7 = (_BYTE *)*this;
          v8 = *(_BYTE *)*this;
          if ( v8 == 42 && (unsigned int)(v7 + 1) < v5 && v7[1] == 47 )
            break;
          if ( v8 == 10 )
            ++this[7];
          v9 = v7 + 1;
          *this = (unsigned int)v9;
        }
        while ( (unsigned int)v9 < this[1] );
      }
      if ( *this < v5 )
      {
        v4 = *this + 2;
        goto LABEL_35;
      }
      sub_65DD1F((_DWORD *)this[12], (int)(this + 2), 1001, "comment continues past end of file");
LABEL_36:
      if ( *this >= this[1] )
        return v11;
    }
    if ( (this[10] & 2) == 0 || v3 != 59 )
    {
      if ( v3 != 92 )
        return v11;
      if ( (unsigned int)(v2 + 1) < this[1] && v2[1] == 10 )
      {
        v4 = (int)(v2 + 2);
      }
      else
      {
        if ( (unsigned int)(v2 + 2) >= this[1] || v2[1] != 13 || v2[2] != 10 )
          return v11;
        v4 = (int)(v2 + 3);
      }
      ++this[7];
      goto LABEL_35;
    }
LABEL_10:
    sub_65D86A(this);
    goto LABEL_36;
  }
  return v11;
}
