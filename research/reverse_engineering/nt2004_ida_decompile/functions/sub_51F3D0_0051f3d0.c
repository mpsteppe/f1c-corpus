char __thiscall sub_51F3D0(_DWORD *this, char a2, int a3)
{
  int v4; // eax
  int v5; // edi
  int v6; // eax
  int v7; // edi

  LOBYTE(v4) = sub_4EED40((_DWORD *)*this);
  if ( (_BYTE)v4 )
  {
    LOBYTE(v4) = a2;
    if ( a2 )
    {
      if ( a3 != 8 )
      {
        v4 = this[4364];
        if ( (v4 & a3) == 0 )
        {
          if ( a3 == 4 )
          {
            v5 = dword_75CBB0;
            LOBYTE(v4) = sub_4DEB10((_DWORD *)(*this + 20836));
            if ( v5 == 7 && ((_BYTE)v4 || dword_75CBB4 <= 4) )
            {
              LOBYTE(v4) = byte_75E9CD;
              if ( byte_75E9CD )
              {
                v6 = this[4364];
                if ( v6 )
                {
                  v4 = v6 | 4;
                  this[4364] = v4;
                }
                else
                {
                  LOBYTE(v4) = dword_75AACC;
                  v7 = dword_75AACC + 84;
                  if ( dword_75AACC != -84 )
                  {
                    sub_51BC20((float *)(dword_75AACC + 84), (_DWORD *)1, 1);
                    if ( dword_75CBB4 == 3 && *(float *)(v7 + 18736) * 9.5492964 <= 0.0 )
                      sub_51C0E0(v7, 1);
                    v4 = this[4364] + 4;
                    this[4364] = v4;
                  }
                }
              }
            }
          }
          else if ( byte_75E9CC )
          {
            if ( v4 )
            {
              v4 |= a3;
              this[4364] = v4;
            }
            else
            {
              if ( dword_75AACC != -84 )
                sub_51BC20((float *)(dword_75AACC + 84), (_DWORD *)1, 1);
              v4 = a3 + this[4364];
              this[4364] = v4;
            }
          }
        }
      }
    }
    else if ( *(_DWORD *)(*this + 16584) == 1 )
    {
      if ( a3 == 8 )
      {
        this[4364] = 0;
        if ( sub_42DBA0() )
          sub_51BC20((float *)(dword_75AACC + 84), 0, 1);
      }
      v4 = this[4364];
      if ( (v4 & a3) != 0 )
      {
        v4 -= a3;
        this[4364] = v4;
        if ( !v4 )
        {
          LOBYTE(v4) = sub_42DBA0();
          if ( (_BYTE)v4 )
            LOBYTE(v4) = sub_51BC20((float *)(dword_75AACC + 84), 0, 1);
        }
      }
    }
  }
  return v4;
}
