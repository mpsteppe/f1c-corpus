char __thiscall sub_42B430(int this)
{
  int v2; // ecx
  int v4; // eax

  v2 = *(_DWORD *)(this + 80);
  if ( *(_DWORD *)(v2 + 25300) )
  {
    *(_BYTE *)(this + 23872) = 0;
    return 0;
  }
  else if ( *(_DWORD *)(this + 16584) == 1 )
  {
    v4 = *(_DWORD *)(this + 24024);
    if ( v4 == 3 )
    {
      return 0;
    }
    else if ( *(_DWORD *)(v2 + 20892) == 2 )
    {
      *(_DWORD *)(this + 24024) = 3;
      sub_51F0F0(this + 84);
      sub_4EEC20(0);
      if ( !(unsigned __int8)sub_4EED40(*(_DWORD *)(this + 80)) )
        sub_4EEC50(0);
      sub_4EECE0(0);
      return 0;
    }
    else
    {
      *(_DWORD *)(this + 23740) = 0;
      if ( v4 == 1 && *(_DWORD *)(this + 17416) == 4 )
        *(_DWORD *)(this + 24024) = 5;
      if ( dword_75CBB4 != *(_DWORD *)(this + 23816) )
      {
        if ( dword_75CBB4 == 5 && *(_DWORD *)(this + 24024) != 1 )
        {
          switch ( dword_75CBB0 )
          {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 6:
              *(_DWORD *)(this + 24024) = 10;
              break;
            case 5:
              if ( dword_7D74E8 == *(_DWORD *)(this + 68) && dword_75CBB0 == 5 && !*(_DWORD *)(this + 20848) )
                sub_42C000(this);
              break;
            case 7:
              sub_427FC0((_DWORD *)this);
              *(_DWORD *)(this + 24024) = 17;
              break;
            default:
              break;
          }
        }
        *(_DWORD *)(this + 23816) = dword_75CBB4;
      }
      if ( *(_DWORD *)(this + 23816) == 3 )
      {
        *(_DWORD *)(this + 24024) = 17;
        *(float *)(this + 24028) = flt_7D74E0 + 2.0;
        sub_427FC0((_DWORD *)this);
      }
      *(_DWORD *)(this + 23748) = 1065353216;
      *(_DWORD *)(this + 23732) = 0;
      return 1;
    }
  }
  else
  {
    return 0;
  }
}
