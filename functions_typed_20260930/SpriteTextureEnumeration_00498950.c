int __thiscall sub_498950(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // esi
  _DWORD *v5; // edi
  int v6; // eax

  result = a2;
  if ( a2 )
  {
    v4 = 0;
    v5 = this + 1407;
    do
    {
      if ( !(unsigned __int8)FloatThresholdCheck(v5) )
        break;
      v6 = StringPointerDereference(v5);
      result = sub_588410(a2, v6);
      if ( !result )
        return result;
      ++v4;
      v5 += 3;
    }
    while ( v4 < 4 );
    if ( v4 == 3 )
    {
      StringFieldSetter(byte_5EA438, 0);
      sub_495B60((int)this);
    }
    return StringFieldSetter(a2, this[54]);
  }
  return result;
}

