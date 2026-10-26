char __thiscall sub_4C2E00(int *this, float *a2)
{
  int v3; // edi
  int v4; // eax
  int v5; // ecx
  bool v6; // al
  int v7; // ebx
  int v8; // edi
  _DWORD *v9; // ebp
  int v10; // ecx

  if ( dword_7D7540
    && (unsigned __int8)sub_4EED40(*this)
    && (unsigned __int8)sub_4DEB10(*this + 20836)
    && *(_DWORD *)(*this + 16584) == 1 )
  {
    sub_4C2C10(this);
  }
  v3 = this[207];
  if ( v3 && v3 != 4 || (LOBYTE(v4) = dword_75AB98, !dword_75AB98) )
  {
    v5 = *this;
    v6 = !*(_BYTE *)(*this + 2296)
      || !*(_BYTE *)(v5 + 2600)
      || !*(_BYTE *)(v5 + 2904)
      || !*(_BYTE *)(v5 + 3208)
      || *(float *)(v5 + 19808) < 0.0;
    if ( dword_75CBB0 == 7 && !v6 || *(_DWORD *)(*this + 16584) == 1 )
    {
      switch ( v3 )
      {
        case 0:
          if ( (unsigned __int8)sub_4EED40(v5) )
          {
            if ( *(_DWORD *)(*this + 20852) )
            {
              v7 = *(_DWORD *)(*this + 20848) + 1;
              v8 = 0;
              if ( this[198] > 0 )
              {
                v9 = this + 199;
                do
                {
                  if ( *v9 == v7 )
                    sub_4C1790((float *)this, 1);
                  ++v8;
                  v9 += 2;
                }
                while ( v8 < this[198] );
              }
            }
          }
          break;
        case 1:
          if ( *(float *)&a2 - *((float *)this + 208) > 150.0 )
            sub_4C1790((float *)this, 0);
          break;
        case 2:
          if ( sub_4C1CF0((float *)this) )
          {
            *((_BYTE *)this + 836) = 0;
            sub_4C1790((float *)this, 3);
            if ( *(_DWORD *)(dword_75AAD0[dword_75AAC0] + 25248) == this[1] )
              sub_502040(2);
          }
          break;
        case 3:
          if ( *((_BYTE *)this + 836) )
            sub_4C2790((float *)this, *(float *)&a2);
          else
            sub_4C2000((float **)this, a2);
          break;
        default:
          sub_51F3D0(1, 2);
          break;
      }
    }
    else if ( v3 == 2 && sub_4C1CF0((float *)this) && !*(_DWORD *)(*this + 16584) )
    {
      dword_766180 = 1;
    }
    if ( *((_BYTE *)this + 824) )
    {
      v4 = sub_514EE0(*this + 84);
      if ( !v4 )
        return v4;
      v10 = *(_DWORD *)(*this + 23608);
      if ( v10 && *(_DWORD *)(v4 + 328) != *(_DWORD *)(v10 + 100) )
        sub_4C1BA0(this);
    }
    LOBYTE(v4) = *((_BYTE *)this + 864);
    if ( (_BYTE)v4 && this[207] != 3 )
      *((_BYTE *)this + 864) = 0;
  }
  return v4;
}
