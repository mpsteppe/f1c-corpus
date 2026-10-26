void __stdcall sub_41B080(_DWORD *a1)
{
  double v1; // st7
  int v2; // ecx
  int v3; // [esp+8h] [ebp+4h]

  if ( dword_7688A0
    && flt_7678BC != 0.0
    && byte_6292D8
    && sub_4633A0(&unk_764D70) != 1
    && (*(_DWORD *)dword_7689CC == 4
     || *(_DWORD *)dword_7689CC == 3
     || *(_DWORD *)dword_7689CC == 2
     || *(_DWORD *)dword_7689CC == 5)
    && a1[5223] == 1
    && !a1[5225]
    && (unsigned __int8)sub_4EED40(a1) )
  {
    v3 = a1[5221];
    if ( v3 == 1 )
    {
      sub_4193B0(1, 999999, 0, 0);
    }
    else if ( v3 == 2 && (int)NumOfElements > 2 )
    {
      sub_4193B0(64, 999999, 0, 0);
    }
    else if ( v3 == 3 && (int)NumOfElements > 3 )
    {
      sub_4193B0(128, 999999, 0, 0);
    }
    else if ( v3 > 5 || (int)NumOfElements < 10 )
    {
      if ( v3 > 10 || (int)NumOfElements < 20 )
      {
        v1 = (double)v3 / (double)(int)NumOfElements;
        if ( v1 > 0.5 )
        {
          v2 = 16;
          if ( v1 > 0.69999999 )
            v2 = 32;
          sub_4193B0(v2, 999999, 0, 0);
        }
        else
        {
          sub_4193B0(8, 999999, 0, 0);
        }
      }
      else
      {
        sub_4193B0(4, 999999, 0, 0);
      }
    }
    else
    {
      sub_4193B0(2, 999999, 0, 0);
    }
  }
}
