// f1c  0x00411b50  size=151
int __stdcall sub_411B50(int a1, int a2, int a3, int a4)
{
  int v4; // edi
  int result; // eax
  _DWORD *v6; // ecx

  v4 = -1;
  result = 1;
  if ( a1 == 9875 )
  {
    if ( a4 == 397 )
    {
      v4 = 45;
    }
    else
    {
      if ( a4 != 426 )
        return result;
      v4 = 46;
    }
    goto LABEL_18;
  }
  if ( a1 == 9876 )
  {
    if ( a4 == 1 )
    {
      v4 = 42;
    }
    else
    {
      if ( a4 != 2 )
        return result;
      v4 = 43;
    }
    goto LABEL_18;
  }
  if ( !a2 )
  {
    v6 = &unk_5BEE08;
    goto LABEL_15;
  }
  if ( a2 == 1 )
  {
    v6 = &unk_5BF4C0;
LABEL_15:
    v4 = v6[a1];
  }
  if ( a1 >= 0 && v4 >= 0 )
  {
LABEL_18:
    sub_566650(&byte_5EA438);
    *(_DWORD *)(a3 + 8) = a1;
    *(_DWORD *)(a3 + 12) = v4;
    return 0;
  }
  return result;
}
