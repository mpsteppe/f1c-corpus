int __thiscall sub_4E0300(_DWORD *this, int a2, int a3, int a4, float a5)
{
  int result; // eax
  int i; // edi
  int v8; // ecx
  unsigned __int8 v10; // c0
  unsigned __int8 v11; // c2

  result = this[7];
  for ( i = 0; i < result; ++i )
  {
    v8 = *(_DWORD *)(this[8] + 4 * i);
    if ( !(v10 | v11) && *(_DWORD *)(v8 + 4) != a2 )
    {
      *(_DWORD *)(v8 + 4) = a2;
      sub_5A0F50(*(_DWORD *)(v8 + 36), 1);
    }
    result = this[7];
  }
  return result;
}
