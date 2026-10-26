int __thiscall sub_57FB80(int this, int a2)
{
  unsigned __int8 v4; // c0
  unsigned __int8 v5; // c3
  int result; // eax
  int v7; // edi
  int v8; // ecx
  int v9; // [esp+4h] [ebp-4h]

  result = *(_DWORD *)(this + 15912);
  if ( v4 | v5 )
  {
    *(_DWORD *)(this + 15928) = *(_DWORD *)(this + 15920);
  }
  else
  {
    ++result;
    *(_DWORD *)(this + 15928) = *(_DWORD *)(this + 15924);
  }
  *(_DWORD *)(this + 16260) = *(_DWORD *)(this + 15928);
  *(_DWORD *)(this + 16512) = *(_DWORD *)(this + 15928);
  *(_DWORD *)(this + 16764) = *(_DWORD *)(this + 15928);
  *(_DWORD *)(this + 17016) = *(_DWORD *)(this + 15928);
  v9 = *(_DWORD *)(this + 16132);
  if ( result <= 0 )
  {
    *(_DWORD *)(this + 15932) = a2;
  }
  else
  {
    v7 = result;
    do
    {
      *(_DWORD *)(this + 16132) = v9;
      sub_578FE0(this);
      sub_575690((float *)this);
      sub_574F40(v8);
      sub_5751B0((float *)this);
      sub_579170(this);
      --v7;
    }
    while ( v7 );
    result = a2;
    *(_DWORD *)(this + 15932) = a2;
  }
  return result;
}
