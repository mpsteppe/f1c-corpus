int __thiscall sub_6982E4(int *this, int a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // edi
  int v5; // eax
  int v6; // esi
  int result; // eax

  v3 = (_DWORD *)sub_65B229(20);
  if ( v3 )
    v4 = sub_67ED1B(v3, 0, this[5], (int)"UsageType");
  else
    v4 = 0;
  if ( !v4 )
    goto LABEL_7;
  this[5] = (int)v4;
  if ( !a2 )
    return 0;
  v5 = sub_67ECC3(a2);
  v6 = v5;
  v4[2] = v5;
  if ( !v5 )
  {
LABEL_7:
    sub_694C92(this, 0);
    return -2147024882;
  }
  result = sub_696C04(this, v5, *(_DWORD **)(v5 + 24));
  if ( result >= 0 )
  {
    *(_BYTE *)(v6 + 17) &= 0xF1u;
    return 0;
  }
  return result;
}
