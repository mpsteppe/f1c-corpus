int __thiscall sub_421590(int this, int a2, int a3)
{
  int result; // eax
  int v5; // edx
  int v6; // ecx
  int v7; // eax
  int v8; // eax

  result = a2;
  switch ( a2 )
  {
    case 17:
      result = sub_4EED40(*(_DWORD *)(this + 80));
      if ( !(_BYTE)result )
      {
        *(float *)(this + 24132) = *(float *)(this + 23852) + 0.75;
        return sub_4271B0(0);
      }
      break;
    case 4:
      result = *(_DWORD *)(this + 23756);
      if ( !result )
      {
        result = sub_4EED40(*(_DWORD *)(this + 80));
        if ( (_BYTE)result && !*(_DWORD *)(this + 23752) )
        {
          result = sub_403FD0(&flt_628F60, (float *)(this + 17604), 1);
          *(_DWORD *)(this + 23436) = result;
          *(_DWORD *)(this + 23432) = result;
        }
        *(_DWORD *)(this + 23752) = 1;
      }
      if ( *(_DWORD *)(this + 24024) )
      {
        *(_DWORD *)(this + 24244) = *(_DWORD *)(this + 23612);
        sub_427F60(18);
        v5 = *(_DWORD *)(this + 80);
        *(_DWORD *)(this + 24024) = 8;
        if ( *(_DWORD *)(v5 + 25300) )
          result = sub_4BBDC0(0);
        else
          result = sub_4BF840(this, 1, 1);
        if ( *(_DWORD *)(this + 23432) )
          return sub_42C150(dword_629108, 1000593162, COERCE_FLOAT(1));
      }
      break;
    case 5:
      v6 = *(_DWORD *)(this + 24024);
      if ( v6 && !*(_DWORD *)(*(_DWORD *)(this + 80) + 25300) )
      {
        *(_DWORD *)(this + 23936) = 0x40000000;
        *(_DWORD *)(this + 23944) = 1065353216;
        if ( dword_7D7928 == 3 )
        {
          *(_DWORD *)(this + 23936) = 1077936128;
          *(_DWORD *)(this + 23944) = 0x40000000;
        }
        else if ( dword_7D7928 == 2 )
        {
          *(_DWORD *)(this + 23936) = 0x40000000;
          *(_DWORD *)(this + 23944) = 1069547520;
        }
        if ( v6 != 14 && v6 != 17 )
        {
          if ( dword_7D7540 <= 1 )
          {
            if ( *(_DWORD *)(this + 23432) )
            {
              if ( *(float *)(*(_DWORD *)(this + 23608) + 24) <= 0.0 )
                sub_42C150(7, 1000593162, COERCE_FLOAT(1));
              else
                sub_42C150(8, 1000593162, COERCE_FLOAT(1));
            }
            *(_DWORD *)(this + 24024) = 5;
          }
          else
          {
            *(_DWORD *)(this + 24024) = 18;
          }
        }
        *(_BYTE *)(this + 24236) = 0;
        if ( dword_75CBB4 == 3 )
          sub_427F60((__int64)flt_7D74E0);
        else
          sub_427F60(500);
        result = sub_4BF840(this, 0, 0);
        *(_DWORD *)(this + 23724) = 0;
        *(_DWORD *)(this + 23756) = 0;
        *(_DWORD *)(this + 23752) = 0;
      }
      break;
    case 1:
      result = *(_DWORD *)(this + 24024);
      *(float *)(this + 64) = *(float *)(this + 23852) + 2.0;
      if ( result == 6 )
        *(_DWORD *)(this + 24024) = 5;
      break;
    case 15:
      if ( dword_75CBB4 == 8 )
      {
        sub_4EE160(0.0);
        *(_DWORD *)(this + 17416) = 0;
      }
      else if ( *(_DWORD *)(this + 24024) != 3 )
      {
        *(_DWORD *)(this + 24024) = 10;
      }
      *(_DWORD *)(this + 24232) = 0;
      result = sub_427F60(18);
      *(_DWORD *)(this + 24244) = *(_DWORD *)(this + 23612);
      break;
    case 16:
      result = *(_DWORD *)(this + 20844);
      if ( result == 9 )
      {
        *(_DWORD *)(this + 24028) = 1140457472;
        return sub_427F60(500);
      }
      else if ( dword_75CBB4 == 5 && (dword_7D7540 != 7 || *(_DWORD *)(this + 20884) == 1) )
      {
        v7 = *(_DWORD *)(this + 24024);
        if ( v7 == 18 )
        {
          *(_DWORD *)(this + 24024) = 5;
          sub_427F60(500);
        }
        else if ( v7 != 5 )
        {
          *(_DWORD *)(this + 20844) = 5;
          *(_DWORD *)(this + 24024) = 6;
        }
        result = *(_DWORD *)(this + 24244);
        *(_DWORD *)(this + 24232) = 3;
        *(_DWORD *)(this + 23816) = dword_75CBB4;
        *(_DWORD *)(this + 24028) = 1140457472;
        *(_DWORD *)(this + 23708) = 0;
        if ( !result )
          return sub_427F60(500);
      }
      else if ( result == 10 )
      {
        v8 = *(_DWORD *)(this + 24024);
        *(_DWORD *)(this + 23708) = 0;
        if ( v8 != 8 && v8 != 1 )
          *(_DWORD *)(this + 24024) = 18;
        result = dword_75CBB4;
        *(_DWORD *)(this + 23816) = dword_75CBB4;
        *(float *)(this + 24028) = flt_7D74E0;
      }
      else if ( result == 11 )
      {
        *(_DWORD *)(this + 23816) = dword_75CBB4;
      }
      break;
    default:
      if ( !a2 && *(_DWORD *)(this + 20892) == 2 )
        *(_DWORD *)(this + 24024) = 0;
      break;
  }
  return result;
}
