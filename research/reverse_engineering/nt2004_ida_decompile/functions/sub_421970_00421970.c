int __thiscall sub_421970(int this)
{
  int v2; // ecx
  int v3; // edx
  int result; // eax
  double v5; // st7
  int v6; // edx
  int v7; // ecx
  int v8; // ecx
  double v9; // st7

  v2 = *(_DWORD *)(this + 80);
  v3 = *(_DWORD *)(v2 + 16584);
  result = *(_DWORD *)(this + 4);
  if ( result != v3 )
  {
    if ( !result && v3 == 1 )
    {
      if ( *(_DWORD *)(*(_DWORD *)(this + 23432) + 328) )
        *(_DWORD *)(this + 24192) = 7;
      else
        *(_DWORD *)(this + 24192) = 8;
      v5 = sub_42B090(*(_DWORD *)(this + 24192), 0);
      v6 = *(_DWORD *)(this + 24192);
      *(float *)(this + 24184) = *(float *)(this + 23700) - v5;
      *(_DWORD *)(this + 24020) = 13;
      sub_42C150(v6, 1000593162, COERCE_FLOAT(1));
      *(_DWORD *)(this + 23724) = 0;
    }
    v2 = *(_DWORD *)(this + 80);
    result = *(_DWORD *)(v2 + 16584);
    *(_DWORD *)(this + 4) = result;
  }
  if ( *(_DWORD *)(v2 + 16584) == 1 )
  {
    if ( *(int *)(this + 24024) <= 3 )
    {
      result = sub_42B430(this);
      if ( !(_BYTE)result )
        return result;
      goto LABEL_27;
    }
    result = *(_DWORD *)(this + 23432);
    if ( result )
    {
      if ( !*(_DWORD *)(v2 + 25300) && !(unsigned __int8)sub_4EED40(v2) )
        sub_42B5C0(this);
      *(_DWORD *)(this + 24028) = 1140457472;
      *(_DWORD *)(this + 23868) = 1232348144;
      sub_427F60(500);
      result = sub_42A1F0(this);
      if ( (_BYTE)result )
      {
        v7 = *(_DWORD *)(this + 80);
        if ( !*(_DWORD *)(v7 + 25300) )
        {
          if ( !(unsigned __int8)sub_4EED40(v7) )
            nullsub_6((void *)this);
          sub_427CB0(this);
        }
        sub_422260(this);
        sub_42CC80(this);
        v8 = *(_DWORD *)(this + 80);
        *(_DWORD *)(this + 8) = 0;
        if ( !*(_DWORD *)(v8 + 25300) )
          sub_4252A0(this);
        sub_425DE0(this);
        sub_423380(this);
        sub_424C60(this);
        if ( *(float *)(this + 23868) < (double)*(float *)(this + 24720) )
          *(_DWORD *)(this + 24720) = *(_DWORD *)(this + 23868);
        sub_423790(this);
        result = *(_DWORD *)(this + 80);
        if ( !*(_DWORD *)(result + 25300) )
          result = sub_42B680(this);
LABEL_27:
        v9 = *(float *)(this + 23732);
        *(_DWORD *)(this + 24620) = 0;
        *(float *)(this + 17764) = v9;
        *(float *)(this + 17768) = *(float *)(this + 23748);
        *(float *)(this + 17760) = *(float *)(this + 23740);
      }
    }
  }
  return result;
}
