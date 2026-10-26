int __thiscall sub_409CE0(int this)
{
  int result; // eax
  int v3; // edi
  int v4; // eax
  int v5; // eax
  float v6; // [esp+0h] [ebp-14h]
  float v7; // [esp+4h] [ebp-10h]

  result = sub_5971C0(aRearview);
  *(_DWORD *)(this + 44) = result;
  if ( result )
  {
    if ( sub_5971C0(aMainview) )
      sub_593F10(sub_409E60, 0);
    sub_593F30(dword_7E8CDC);
    sub_593AF0(1);
    sub_593B30(flt_768318, flt_76833C, flt_768360, flt_768384, 0);
    v7 = flt_767AE4 * 0.01745433;
    v6 = flt_767AC0 * 0.01745433;
    sub_593820(v6, v7, 0);
    sub_593F10(sub_409E80, 0);
    sub_594050(0.5);
    sub_594020(dword_767B08);
    sub_593430(0);
    result = sub_42DBC0(&unk_62BF64);
    if ( (_BYTE)result )
      v3 = *(_DWORD *)(dword_75AACC + 4412);
    else
      v3 = 0;
    if ( v3 )
    {
      v4 = sub_59EFD0(v3);
      if ( v4 > 1 )
      {
        v5 = sub_59EFF0(v4 - 1);
        *(_DWORD *)(this + 48) = v5;
        if ( v5 )
        {
          if ( sub_59CB20(v5) != 4 )
            *(_DWORD *)(this + 48) = 0;
        }
      }
      result = sub_598170(dword_7DA9B8);
      if ( result )
      {
        result = sub_599D20(aMirrorBmp);
        if ( result )
        {
          result = *(_DWORD *)(result + 16);
          if ( (*(_DWORD *)(result + 56) & 0x40000) != 0 )
          {
            *(_DWORD *)(this + 68) = result;
            result = sub_593F30(result);
            *(_BYTE *)(this + 72) = 0;
          }
        }
      }
    }
    else
    {
      *(_DWORD *)(this + 44) = 0;
    }
  }
  return result;
}
