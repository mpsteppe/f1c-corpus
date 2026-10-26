void __fastcall sub_565140(_DWORD *a1, int a2, int a3)
{
  int i; // edi
  int v6; // eax

  for ( i = 0; i < a3; ++a1[325] )
  {
    v6 = a1[325];
    if ( !v6 || (unsigned int)(v6 - (_DWORD)a1 - 1236) >= 0x3F )
    {
      a1[325] = a1 + 309;
      sub_564F10(a1, a1 + 309, 16);
    }
    *(_BYTE *)(i + a2) ^= *(_BYTE *)a1[325];
    ++i;
  }
}
