int __thiscall sub_5B9F20(int *this)
{
  int *v2; // esi
  int v3; // eax
  int result; // eax
  int v5; // edi
  int v6; // eax
  int v7; // edx
  bool v8; // zf

  sub_5BBD90();
  v2 = this + 18;
  sub_5BDA20();
  v3 = *v2;
  if ( !*v2 )
    return sub_5BCA40(v2);
  if ( v3 <= 1 || v3 > 3 )
    return 0;
  if ( !sub_5BDC00(v2[296]) )
    return 0;
  v5 = v2[30];
  v6 = recv(v2[296], (char *)(v5 + v2[29]), 4096 - v5, 0);
  if ( v6 == -1 || !v6 )
  {
    sub_5BCA10(v2);
    return 3;
  }
  else
  {
    v7 = v6 + v2[30];
    v8 = *v2 == 2;
    v2[30] = v7;
    if ( v8 || v2[366] > 0 )
      sub_5BE770(v7 - v5);
    if ( *v2 != 3 || (result = sub_5BCC00(v2)) == 0 )
    {
      if ( *v2 != 2 || v2[30] <= 0 )
        return 0;
      return sub_5BD3F0(v2);
    }
  }
  return result;
}
