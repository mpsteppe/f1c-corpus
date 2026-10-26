_BYTE *__fastcall sub_564390(int a1, int a2)
{
  _BYTE *result; // eax
  int i; // esi
  char *v5; // edi
  int v6; // eax
  int v7; // ecx
  _DWORD v8[2]; // [esp+8h] [ebp-8h] BYREF

  result = sub_564220((_BYTE *)(a2 + 1), 92);
  for ( i = (int)result; result; i = (int)result )
  {
    v5 = sub_564220(0, 92);
    if ( !v5 )
      v5 = byte_5EA438;
    if ( sub_564410(i) )
    {
      v8[0] = sub_564270(a1, i);
      v6 = sub_564270(a1, (int)v5);
      v7 = *(_DWORD *)(a1 + 12);
      v8[1] = v6;
      sub_564780(v7, v8);
    }
    result = sub_564220(0, 92);
  }
  return result;
}
