LPVOID *__thiscall sub_4ADAF0(_DWORD *this, char *String2, int a3, int a4)
{
  LPVOID *result; // eax
  int v6; // esi
  void *v7; // eax
  LPVOID *v8; // edi
  int i; // eax

  if ( !String2 )
    return 0;
  result = (LPVOID *)sub_4ADBB0(String2);
  if ( result )
    return result;
  v6 = this[83];
  v7 = operator new(0x2Cu);
  if ( v7 )
    v8 = (LPVOID *)sub_4B0680(v7);
  else
    v8 = 0;
  if ( !(unsigned __int8)sub_4B0960(String2, a3, a4) )
  {
    if ( v8 )
    {
      sub_4B0930(1);
      if ( *v8 )
        sub_5BE8AE(*v8);
      sub_5BE8AE(v8);
    }
    return 0;
  }
  if ( v6 )
  {
    for ( i = *(_DWORD *)(v6 + 40); i; i = *(_DWORD *)(i + 40) )
      v6 = i;
    *(_DWORD *)(v6 + 40) = v8;
    ++this[84];
    return v8;
  }
  else
  {
    ++this[84];
    this[83] = v8;
    return v8;
  }
}
