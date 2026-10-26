int __thiscall sub_42BD90(int this, _DWORD *a2, float a3, float a4, float a5, int a6)
{
  int result; // eax
  double v8; // st7
  int v9; // ebp
  int v10; // edi
  int v11; // eax
  int v12; // [esp+4h] [ebp-4h]

  result = 20;
  v12 = 20;
  if ( *(_DWORD *)(this + 23432) )
  {
    if ( a4 < -0.1 && !dword_7D7540 )
    {
      v8 = a3 - 4.0;
      if ( v8 < 0.0 )
        v8 = 0.0;
      if ( -1.0 / a4 * v8 < 2.0 )
      {
        if ( sub_42D720(a6) - 1.0 >= a5 || 3.0 - *(float *)(a6 + 124) >= a5 )
        {
          if ( sub_42D720(a6) > a5 && *(float *)(a6 + 128) - 4.0 > a5 )
            v12 = 9;
        }
        else
        {
          v12 = 8;
        }
      }
    }
    if ( *(float *)(this + 23776) < 0.69999999
      && *(float *)(this + 23852) - 1.0 > *(float *)(this + 23784)
      && (*(_DWORD *)(this + 24244) || a2[6061] != 1) )
    {
      if ( sub_42D720(a6) - 1.0 >= a5 || 3.0 - *(float *)(a6 + 124) >= a5 )
      {
        if ( sub_42D720(a6) > a5 && *(float *)(a6 + 128) - 4.0 > a5 )
          v12 = 9;
      }
      else
      {
        v12 = 8;
      }
    }
    if ( !(unsigned __int8)sub_4DEB10(this + 20836) )
      return v12;
    if ( (int)sub_4F8370(a2[20]) < 0 )
      return v12;
    if ( (int)sub_4F8370(*(_DWORD *)(this + 80)) < 0 )
      return v12;
    v9 = sub_4F8370(a2[20]);
    if ( v9 >= sub_4F8370(*(_DWORD *)(this + 80)) )
      return v12;
    v10 = a2[17];
    v11 = sub_4F8370(a2[20]);
    if ( v10 == sub_4FA870(v11) )
    {
      return v12;
    }
    else if ( sub_42D720(a6) <= a5 || *(float *)(a6 + 128) - 3.0 <= a5 )
    {
      return 8;
    }
    else
    {
      return 9;
    }
  }
  return result;
}
